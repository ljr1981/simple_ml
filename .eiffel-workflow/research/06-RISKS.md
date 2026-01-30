# RISKS: simple_ml

## Risk Register

| ID | Risk | Likelihood | Impact | Mitigation | Contingency |
|----|------|-----------|--------|-----------|------------|
| RISK-001 | CPU-only performance insufficient (mitigated by Phase 1.5 GPU) | MEDIUM→LOW | HIGH→MEDIUM | Phase 1.5 GPU acceleration via CUDA; CPU path acceptable for verification | Accept as verification library; defer GPU to Phase 2+ |
| RISK-001b | GPU integration introduces bugs or breaks CPU path | MEDIUM | MEDIUM | Phase 1.5 comprehensive testing (CPU vs GPU equivalence); dual code path testing | Remove GPU layer; revert to CPU-only |
| RISK-002 | Simple_linalg matrix operations not numerically stable enough | LOW | HIGH | Validate algorithms against reference implementations | Phase 2 switches to simpler algorithms |
| RISK-003 | Gradient descent from simple_optimization doesn't converge for NN | MEDIUM | HIGH | Phase 5 comprehensive testing; may need custom convergence logic | Implement Newton-Raphson for smaller models |
| RISK-004 | Contract postconditions impossible to satisfy (overspecified) | MEDIUM | MEDIUM | Phase 1 adversarial review catches impossible contracts | Phase 2 revises contracts based on experience |
| RISK-005 | Eiffel ecosystem (simple_*) has bugs discovered during ML work | LOW | MEDIUM | Phase 5 includes integration tests; report issues to library maintainers | Fork and maintain needed components |
| RISK-006 | Users expect scikit-learn performance/feature parity | MEDIUM | MEDIUM | Clear positioning: simple_ml is for verification, not performance | Extensive documentation of trade-offs |
| RISK-007 | Market adoption is minimal (niche for verified ML) | MEDIUM | LOW | Start with academic adoption; build case studies | Pivot to educational tool |
| RISK-008 | Regulatory bodies don't recognize contract-based verification | MEDIUM | MEDIUM | Collaborate with formal verification researchers; publish | Develop SMT verification framework in Phase 2 |
| RISK-009 | Neural network training diverges frequently | MEDIUM | MEDIUM | Extensive Phase 6 adversarial testing; add regularization | Simplify NN to single hidden layer for MVP |
| RISK-010 | Phase 1-3 scope creep (algorithms not in MVP still needed) | MEDIUM | MEDIUM | Strict scope: 6 algorithms only; rest to Phase 2 | Cut lowest-priority algorithms |

## Technical Risks

### RISK-001: CPU-Only Performance Insufficient (MITIGATED by Phase 1.5 GPU)

**Description:**
Eiffel code is interpreted/compiled by EiffelStudio, not as optimized as Python+NumPy+TensorFlow (C backends). Training on 100K samples × 1K features might take minutes where scikit-learn takes seconds. **MITIGATION: Phase 1.5 GPU acceleration via CUDA/cuBLAS/cuDNN for users with NVIDIA hardware.**

**Likelihood (MVP CPU):** MEDIUM → **LOW (with Phase 1.5 GPU option)**

**Impact:** HIGH → **MEDIUM (with Phase 1.5 GPU option)**
- Reason: CPU path acceptable for verification/education; GPU path for production performance

**Current Indicators:**
- EiffelStudio JIT compilation helps, but no SIMD
- Simple_linalg uses Eiffel arrays, not BLAS (scikit-learn uses BLAS)
- Python has 30 years of numerical optimization; Eiffel doesn't
- NVIDIA CUDA is mature (5070 Ti: 5-20x speedup for matrix ops)

**Mitigation Strategy (Phase 1-3 + Phase 1.5):**
1. **Phase 1-3 (MVP):** CPU-only training (clear expectation-setting)
2. **Phase 1.5 (GPU):** Optional CUDA acceleration via cuBLAS/cuDNN
   - Target: NVIDIA GPUs (5070 Ti, 4090, professional A100, H100)
   - Performance: 5-20x speedup for matrix-heavy algorithms (linear/logistic/NN)
   - Implementation: C/C++ CUDA bindings with Eiffel wrapper contracts
3. **Phase 5:** Benchmark CPU vs GPU; document performance trade-offs
4. **Phase 2+:** Distributed GPU training (multi-GPU, multi-node)
5. **Marketing:** Position as "Contract-verified ML; optional GPU acceleration"

**GPU Mitigation Details:**
- Users with CPU only: simple_ml works identically, no CUDA dependency
- Users with NVIDIA GPU: `pip install simple-ml[gpu]` enables acceleration
- Contracts verified on Eiffel layer; CUDA is trusted external library
- Results: CPU and GPU must match within IEEE 754 epsilon

**Contingency (if Phase 1.5 GPU fails):**
- If GPU integration is too complex: revert to CPU-only, accept as verification library
- Or: Defer GPU to Phase 2 after MVP proves stable

**Preventive Action (Phase 1-3):**
- Profile simple_linalg matrix operations early
- Set performance targets in Phase 5 (acceptable slowdown ratio for CPU: <5 seconds for typical 1K sample dataset)
- Phase 1.5 research: Can EiffelStudio call CUDA via C bindings? What's the overhead?

---

### RISK-002: Simple_linalg Numerical Stability Issues

**Description:**
simple_linalg may use algorithms (Gaussian elimination without pivoting, naive SVD) that aren't numerically stable. If LU decomposition produces NaN for near-singular matrices, all ML algorithms depending on it fail.

**Likelihood:** LOW - simple_linalg has been tested on simple_statistics, simple_ode, simple_physics

**Impact:** HIGH - Propagates to all ML algorithms; hard to debug

**Current Indicators:**
- simple_linalg passes Phase 6 testing (adversarial + stress tests)
- Used successfully in simple_ode and simple_physics
- But ML uses linear algebra differently (many small solutions vs large decompositions)

**Mitigation:**
1. Phase 5 tests train linear regression; validate weights vs reference (R, Python)
2. Phase 6 adversarial tests: near-singular matrices, rank-deficient cases
3. Monitor floating-point precision; log condition numbers
4. If issues found: coordinate with simple_linalg maintainers for fixes

**Contingency:**
- Phase 2: Implement custom stable matrix algorithms for ML if needed
- Use simpler regularization to avoid singularity

**Preventive Action (Phase 1):**
- Document which simple_linalg operations simple_ml uses (matrix multiply, solve, transpose, inverse, decomposition)
- Phase 2 creates integration test suite: test simple_linalg with ML-specific patterns

---

### RISK-003: Gradient Descent from simple_optimization May Not Converge for Neural Networks

**Description:**
simple_optimization.GRADIENT_DESCENT_SOLVER was built for simpler optimization problems (from simple_optimization). Neural networks have non-convex loss surfaces with local minima, plateaus, saddle points. Gradient descent may get stuck.

**Likelihood:** MEDIUM - Neural network training is harder than linear/logistic regression

**Impact:** HIGH - Core feature (FR-006) fails; NN training unusable

**Current Indicators:**
- Simple_optimization test suite passes (Phases 5-6)
- But tests are for convex optimization (linear, logistic regression)
- NN training not tested yet

**Mitigation:**
1. Phase 5 starts with linear/logistic regression (convex) before NN
2. Phase 6 adversarial testing for NN: try 10 random seeds, measure convergence rate
3. Implement momentum, adaptive learning rates (phase 2 improvements)
4. Add early stopping to escape plateaus
5. Document NN limitations in MVP (e.g., single hidden layer, small networks)

**Contingency:**
- If NN training fails: Remove NN from MVP; move to Phase 2 as research feature
- Phase 2 implements SGD with momentum, Adam optimizer
- Or: Use simple simpler activation (tanh instead of ReLU) to improve landscape

**Preventive Action (Phase 1):**
- Phase 5 tests NN training on small datasets (e.g., iris: 150 samples, 4 features)
- Phase 6 runs 100+ training runs with random initialization to measure success rate
- If <80% success on small datasets: flag for Phase 2 improvement

---

### RISK-004: Contract Postconditions Are Overspecified (Impossible to Satisfy)

**Description:**
During Phase 1, we might write contracts that are mathematically sound but impossible to achieve in practice. Example: "convergence_loss < 1e-10" for a model that can only achieve 1e-5. Then training violates postcondition.

**Likelihood:** MEDIUM - First time writing ML contracts; easy to be optimistic

**Impact:** MEDIUM - Breaks Phase 5 testing; requires contract revision

**Current Indicators:**
- Contracts written in Phase 1 before implementation
- No implementation experience to validate bounds
- Requirements document specifies <1e-10 convergence tolerance

**Mitigation:**
1. Phase 1: Write contracts with wide tolerances (e.g., convergence_loss < old_loss)
2. Phase 2 (Review): Adversarial review specifically checks postcondition feasibility
3. Phase 5: Tests reveal if postconditions are too tight
4. Phase 6: Loosen postconditions based on empirical testing
5. Final contracts: Conservative, achievable, verifiable

**Contingency:**
- If Phase 5 fails: Rewrite contracts to match achievable performance
- No architecture change needed; just loosen tolerance
- Phase 7: Document lessons learned for next library

**Preventive Action (Phase 1):**
- Phase 1 contracts: Use ranges with buffer (e.g., "loss_decreased_by_at_least_50%" not "loss < epsilon")
- Phase 5: First iteration tightens based on empirical data
- Don't commit to tight tolerances until Phase 6 validates

---

## Ecosystem Risks

### RISK-005: Eiffel Ecosystem (simple_* Libraries) Has Bugs

**Description:**
simple_linalg, simple_optimization, simple_statistics were Phase 7 released. If bugs exist (unlikely but possible), they propagate to simple_ml during integration testing.

**Likelihood:** LOW - All simple_* libs completed Phase 6-7 (comprehensive testing, hardening, release)

**Impact:** MEDIUM - Integration tests fail; need to fix upstream

**Current Indicators:**
- simple_physics: 62/62 tests passing
- simple_ode: 13/13 tests passing
- simple_optimization: 10/10 tests passing
- All Phase 6+ complete, Phase 7 released
- But: first time these libraries used together in ML context

**Mitigation:**
1. Phase 5 includes integration tests: each simple_ml algorithm trains on sample data
2. Results compared vs reference (R, Python) to validate correctness
3. If bug suspected: create minimal reproduction case, report to library maintainers
4. Phase 5 tests both simple_ml AND upstream libraries simultaneously

**Contingency:**
- If upstream bug found: Coordinate fix with maintainer (quick turnaround)
- Temporary: Workaround in simple_ml code
- Fork if maintainer unresponsive (unlikely given team)

**Preventive Action (Phase 1):**
- Document exact versions of simple_* dependencies in Phase 1
- Phase 5 tests specify which simple_* bugs are known/accepted
- Phase 5 integration tests are THE verification that ecosystem works together

---

### RISK-006: User Expectations: Simple_ml Won't Match scikit-learn Feature Parity

**Description:**
Users expect scikit-learn: 50+ algorithms, GPU acceleration, production-grade performance. simple_ml MVP has 6 algorithms, CPU-only, verification-focused. Users abandon disappointed.

**Likelihood:** MEDIUM - Eiffel niche audience, but scikit-learn is gold standard

**Impact:** MEDIUM - Low adoption; seen as insufficient

**Current Indicators:**
- Landscape analysis shows scikit-learn dominates
- Market expectation is "complete ML library"
- simple_ml explicitly defers clustering, PCA, time series to Phase 2

**Mitigation:**
1. Clear positioning in README: "simple_ml is for formal verification, not features"
2. Phase 7 documentation: Compare vs scikit-learn (trade-offs honest)
3. Target academic/regulated market first (verification matters to them)
4. Provide roadmap: "Phase 2 adds clustering, Phase 3 adds time series"
5. MVP focuses on breadth of contracts, not breadth of algorithms

**Contingency:**
- If adoption low: Accelerate Phase 2 to add more algorithms
- Or: Shift positioning to "educational ML library" (attracts students, academia)
- Or: Develop scikit-learn compatibility layer (wrap simple_ml as scikit-like API)

**Preventive Action (Phase 1):**
- Phase 7 (Release) includes comparison table: simple_ml vs scikit-learn features/contracts
- Clear statement: "simple_ml prioritizes correctness and auditability over feature count"
- Announce Phase 2 roadmap upfront

---

## Resource Risks

### RISK-007: Market Adoption Minimal (Niche for Formal-Verified ML)

**Description:**
The world of ML is speed/scale focused (Kaggle competitions, big data). Formal verification appeals to tiny niche (academia, fintech auditors). simple_ml might launch to zero users.

**Likelihood:** MEDIUM - Eiffel ecosystem is niche; ML verification is niche; intersection very small

**Impact:** LOW - Doesn't break technical correctness, but project feels unsuccessful

**Current Indicators:**
- Eiffel ~2% of programming language market
- ML verification research is emerging but small field
- Intersection: few hundred people globally?

**Mitigation:**
1. Target academic first: publish paper on formal-verified ML
2. Collaborate with researchers (WFVML, Post-AI-FM workshops)
3. Partner with fintech/healthtech (regulated industries) for case studies
4. Create free educational materials (teaching ML + verification)
5. Open-source ensures visibility

**Contingency:**
- If adoption remains low: Pivot to educational tool
- Position as "ML for learning, not production"
- Or: Build case studies in regulated domains to show value

**Preventive Action (Phase 1):**
- Phase 7 includes marketing plan: academic conferences, fintech outreach
- Create teaching materials (course, tutorials)
- Document regulatory value clearly

---

## Regulatory Risks

### RISK-008: Regulatory Bodies (FDA, EU AI Act) Don't Recognize Contract-Based Verification

**Description:**
We claim simple_ml contracts help with regulatory compliance, but regulators (FDA, EU AI Act boards) may not accept Design by Contract as "formal verification." They want SMT/model checking.

**Likelihood:** MEDIUM - Formal verification landscape is evolving; contracts are not SMT-proven

**Impact:** MEDIUM - Regulatory positioning weakened; reduces market advantage

**Current Indicators:**
- WFVML and Post-AI-FM are new workshops (2024+)
- EU AI Act doesn't mention Eiffel or Design by Contract specifically
- Regulators more familiar with: model checking, symbolic execution, SAT/SMT

**Mitigation:**
1. Contracts as FIRST STEP toward formal verification (not sufficient alone)
2. Phase 2: Develop integration with SMT solvers (export postconditions as SMT formulas)
3. Collaborate with formal verification researchers to bridge contract → SMT
4. Document: "Contracts necessary but not sufficient; use with formal verification tools"
5. Position as: "Eiffel Design by Contract + formal methods"

**Contingency:**
- If regulators don't accept contracts alone: Develop SMT verification layer
- Or: Create case studies showing contracts catch bugs earlier
- Or: Pivot to academic positioning (contracts as research tool)

**Preventive Action (Phase 1):**
- Phase 5-6: Identify which postconditions are SMT-verifiable
- Phase 2 research: Can PostCondition → SMT formula be automated?
- Partner with formal methods researchers early

---

## Summary: Risk Mitigation Strategy

| Phase | Focus | Risk Reduction |
|-------|-------|-----------------|
| **Phase 1** | Write achievable contracts; validate simple_* APIs | RISK-004 (overspecified contracts) |
| **Phase 2** | Review reveals contract issues early | RISK-004 |
| **Phase 5** | Comprehensive testing; validate vs reference implementations | RISK-002, RISK-003 (convergence, stability) |
| **Phase 6** | Adversarial testing; edge cases; stress tests | RISK-001 (performance bottlenecks found) |
| **Phase 7** | Documentation, positioning, marketing | RISK-006, RISK-007 (expectation management) |

## Open Questions

1. **What's an acceptable performance slowdown vs scikit-learn?** (for RISK-001)
   - Option A: 5-10x slower is acceptable (educational market)
   - Option B: Must match 2x slowdown (enterprise market)

2. **Should we commit to SMT verification integration, or contracts alone?** (for RISK-008)
   - Option A: Contracts as first step; Phase 2 plans SMT
   - Option B: Design from start to be SMT-compatible

3. **If NN training fails in Phase 5, do we remove NN or pivot to Phase 2?** (for RISK-003)
   - Need clear success criteria: "NN converges on 80% of training runs"

4. **Who is target market: academia, finance, or both?** (for RISK-007)
   - Affects marketing, feature prioritization, documentation

These will be finalized during Phase 2 (Review) by adversarial AI analysis.
