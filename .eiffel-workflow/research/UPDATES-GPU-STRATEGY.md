# Research Documentation Updates: GPU Strategy & Phase 2+ Justifications

**Date:** 2026-01-29
**Updated Files:** 01-SCOPE.md, 04-DECISIONS.md, 06-RISKS.md, 07-RECOMMENDATION.md
**Status:** All research documents updated with comprehensive GPU strategy and Phase 2+ justifications

---

## Summary of Changes

### 1. GPU Support Strategy (MAJOR UPDATE)

#### Changed From:
- GPU/CUDA Phase 2 (deferred after full implementation)
- Performance (RISK-001) unmitigated for MVP

#### Changed To:
- **Phase 1.5: GPU Integration (NEW)**
- Timing: After Phase 3 MVP verification, before Phase 4+ scaling
- NVIDIA CUDA/cuBLAS/cuDNN C/C++ bindings
- Optional backend (CPU path unchanged)
- Expected speedup: 5-20x for matrix-heavy algorithms
- Targets: NVIDIA 5070 Ti, 4090, A100, H100, etc.

#### Rationale:
- Users with NVIDIA GPUs (like 5070 Ti 16GB) need acceleration NOW
- CUDA is mature, proven technology (not risky)
- Phase 1.5 ideal timing: MVP contracts verified first, then performance layer
- Exception to simple_* first policy: C/C++ GPU libraries allowed as optional trusted backends
- Architecture: Eiffel contracts on CPU side; CUDA is optimization layer

#### Key Design Principle:
```
Eiffel Layer (with contracts) → GPU Wrapper → CUDA/cuBLAS/cuDNN → NVIDIA GPU

- Verification contracts on Eiffel layer (Design by Contract maintained)
- CUDA code is trusted external library (like ISE base library)
- CPU path works identically without CUDA
- Results: CPU ≈ GPU within IEEE 754 epsilon
```

---

### 2. All Phase 2+ Decisions Justified (COMPREHENSIVE UPDATE)

#### Updated in 01-SCOPE.md

Each deferred feature now has detailed justification:

| Feature | Phase | Justification | When Needed |
|---------|-------|---------------|-------------|
| **GPU Acceleration** | 1.5+ | NVIDIA hardware acceleration optional; users need MVP first | After MVP verified |
| **Distributed Training** | 2+ | Multi-machine gradient sharing complex; requires simple_distributed lib | After single-machine proven |
| **Large Datasets** | 2+ | >100MB out-of-core adds I/O complexity; MVP fits in RAM | After MVP baseline |
| **Advanced Ensembles** | 2+ | Stacking/blending are specializations; bagging (RF) covers 80% | Future releases |
| **Advanced NN** | 2+ | Conv/RNN are domain-specific; MLP covers basics | Image/sequence data needed |
| **AutoML/NAS** | 2+ | Requires Bayesian/evolutionary search (no simple_optimization support) | After MVP stable |
| **Causal Inference** | 3+ | Orthogonal to supervised learning; requires domain expertise | When causal questions arise |
| **NLP** | Future | Different domain; separate simple_nlp library needed | NLP-specific use case |

#### Definitions Added

**Distributed Training Definition:**
Training a single model across multiple computers/GPUs where each machine:
1. Loads different data batch
2. Computes gradients locally
3. Synchronizes gradients via AllReduce (NCCL)
4. Updates model weights with aggregated gradient
5. Repeats for next batch

Why Phase 2+: Adds 3-4x complexity (MPI/NCCL communication, fault tolerance, stragglers, synchronization). Requires simple_distributed library that doesn't exist. Risk: breaking Design by Contract guarantees across network boundaries.

**AutoML/NAS Definitions:**
- **AutoML (Automated Machine Learning):** Systems that automatically choose algorithm type, hyperparameters, architectures without human input. Examples: Auto-sklearn, TPOT, H2O AutoML.
- **NAS (Neural Architecture Search):** Algorithms that design optimal neural network topologies automatically. Examples: DARTS, NASNet, EfficientNet discovery.

Why Phase 2+: Requires meta-learning, search algorithms (Bayesian optimization, evolutionary), ensemble selection. Current simple_optimization supports gradient descent only; no Bayesian/evolutionary support exists.

**Causal Inference Justification (Detailed):**

Why out of MVP scope (important distinction):
1. **Orthogonal goal:** Supervised ML predicts Y given X. Causal asks "does X cause Y?" Different objective.
2. **Domain knowledge required:** Causal assumptions (unconfoundedness, no hidden confounders, no feedback loops) need domain expertise about the problem. Can't learn from data alone.
3. **Market mismatch:** Most ML practitioners want predictions, not causal explanations (yet). Focus on core supervised learning first.
4. **Contract complexity:** Causal contracts must encode assumptions about causal DAGs, unobserved confounders - harder to specify formally.
5. **Eiffel ecosystem gap:** No simple_causal library. Would require foundational research on representing causal assumptions in contracts.

Examples of causal methods (Phase 3+):
- Causal forests (adaptive random forests with honest splitting)
- Propensity score weighting (match observational units by similarity)
- Instrumental variables (use Z to identify causal effect of X on Y)
- Difference-in-differences (before/after policy intervention)

Future: separate **simple_causal library** (Phase 4+) could provide these with formal contracts.

---

### 3. simple_* First Policy Exception (IMPORTANT)

#### Updated Constraint (in 01-SCOPE.md):

**Original:**
```
simple_* first policy: no external ML libraries (scikit-learn, etc.) in implementation
```

**Updated:**
```
simple_* first policy: no external ML libraries (scikit-learn, etc.) in implementation

EXCEPTION: C/C++ GPU libraries (NVIDIA CUDA, cuBLAS, cuDNN) allowed for Phase 1.5+
acceleration as optional trusted backends with Eiffel wrapper layer
```

#### Rationale for Exception:
- **simple_* first applies to:** Eiffel ecosystem libraries (algorithms, data structures, utilities)
- **Exception applies to:** Trusted external C/C++ libraries (GPU acceleration, proven industry-standard)
- **Precedent:** scikit-learn uses C/BLAS, TensorFlow uses C++, PyTorch uses C++ - normal practice
- **Pattern consistency:** Same as ISE base library (external, trusted, optimized)
- **User control:** GPU is optional; CPU-only path unchanged, no CUDA dependency required

---

### 4. GPU Integration Details (Phase 1.5)

#### Architecture:
```
User Code (Eiffel)
    ↓ calls
Eiffel Facade (simple_ml.train(...))
    ├ with contracts (require/ensure/invariant)
    ↓ optionally delegates to
GPU Wrapper Layer (gpu_matrix_operations.e)
    ├ with contracts (input validation, output bounds)
    ↓ calls (via bindings)
C/C++ CUDA Code (cuda_kernels.cpp)
    ├ No contracts (trusted external)
    ↓ uses
NVIDIA Libraries (cuBLAS, cuDNN)
    ↓ executes on
NVIDIA GPU (5070 Ti, 4090, A100, H100)
```

#### Libraries (Phase 1.5 GPU):
- **cuBLAS**: Optimized matrix operations (multiply, transpose, solve) on GPU
- **cuDNN**: Neural network kernels (convolution, activation, backprop) on GPU
- **CUDA Runtime**: Memory management (cudaMalloc, cudaMemcpy), kernel dispatch
- **NCCL** (Phase 2): Multi-GPU collective communication (AllReduce, broadcast)

#### Installation:
```bash
pip install simple-ml              # CPU only
pip install simple-ml[gpu]         # With CUDA support
```

#### Runtime Usage:
```eiffel
model := create {LINEAR_REGRESSION_MODEL}.make
model.compute_device := GPU_DEVICE  -- or CPU_DEVICE
model.train (X_train, y_train)
```

#### Testing (Phase 1.5):
- For every matrix op: assert CPU result ≈ GPU result (within IEEE 754 epsilon)
- For every NN algorithm: assert CPU weights ≈ GPU weights after convergence
- Tolerance: Both use REAL_64, so epsilon ~2.22e-16 × value

---

### 5. Phase 1.5 Inserted in Timeline

#### Updated Timeline (01-SCOPE.md + 07-RECOMMENDATION.md):

**Before:**
```
Phase 1 (2 wks) → Phase 2 (1 wk) → Phase 3 (3 days) → Phase 4 (4-5 wks) → ...
Total: ~11-12 weeks
```

**After:**
```
Phase 1 (2 wks) → Phase 2 (1 wk) → Phase 3 (3 days)
    ↓
    Phase 1.5 GPU (2 wks) [optional, parallel research possible]
    ↓
Phase 4 (4-5 wks) → Phase 5 (2 wks) → Phase 6 (1.5 wks) → Phase 7 (1 wk)
Total: ~13-14 weeks (with GPU); ~11-12 weeks (CPU-only)
```

**Timeline Details:**
- Phase 1.5 starts after Phase 3 is complete
- Can run in parallel with Phase 4 CPU implementation if resources available
- GPU integration independent of main algorithm implementation
- Success criteria separate from Phase 4-7

---

### 6. Risk Mitigation Update (06-RISKS.md)

#### RISK-001: Performance (UPDATED)

**Before:**
```
Likelihood: MEDIUM
Impact: HIGH
Mitigation: MVP targets CPU; Phase 2 evaluates GPU
Contingency: Accept as educational library
```

**After:**
```
Likelihood: MEDIUM → LOW (with GPU option)
Impact: HIGH → MEDIUM (with GPU option)
Mitigation: Phase 1.5 GPU acceleration via CUDA; CPU path remains acceptable
Contingency: If GPU integration fails, revert to CPU-only; defer GPU to Phase 2+
```

#### New Risk (01-RISK-001b): GPU Integration Bugs

```
Risk: GPU integration introduces bugs or breaks CPU path
Likelihood: MEDIUM
Impact: MEDIUM
Mitigation: Phase 1.5 comprehensive testing (CPU vs GPU equivalence); dual code path testing
Contingency: Remove GPU layer; revert to CPU-only
```

---

### 7. Decision Updates (04-DECISIONS.md)

#### D-008: GPU Acceleration Timeline (REVISED)

**Before Decision:**
```
Phase 1: CPU only
Phase 2: Evaluate GPU
```

**After Decision:**
```
Phase 1-3: CPU MVP (contracts verified)
Phase 1.5: GPU Integration (optional acceleration layer)
Phase 2+: Distributed GPU training
```

**Rationale:**
- Users with NVIDIA hardware (5070 Ti) can't wait until Phase 2
- CUDA is mature, proven technology
- Phase 1.5 ideal timing: after MVP verified, before scaling work
- GPU research question: "Can EiffelStudio call CUDA safely?"

#### D-008b: NEW - simple_* First Policy Exception

**Decision:**
```
C/C++ CUDA/cuBLAS/cuDNN allowed as optional GPU backends (Phase 1.5+)
This is intentional exception to simple_* first policy.
```

**Rationale:**
- simple_* first applies to Eiffel ecosystem (algorithms, libraries)
- C/C++ GPU libraries are trusted external code (same pattern as ISE base)
- GPU is optional (CPU path unchanged)
- Precedent: all ML frameworks use C/C++ backends for performance

---

### 8. Research Questions Updated (01-SCOPE.md)

Added to Research Questions section:
```
11. GPU Strategy (Phase 1.5): Can Eiffel safely call CUDA via C/C++ bindings?
    What's the performance/complexity trade-off?

12. How to test GPU vs CPU equivalence? What tolerance is acceptable for
    numerical differences?
```

---

## Files Updated

1. **01-SCOPE.md**
   - Added detailed GPU Strategy section
   - Updated Out of Scope with justifications for each Phase 2+ feature
   - Added definitions: Distributed Training, AutoML, NAS, Causal Inference
   - Updated Constraints with GPU exception to simple_* first policy
   - Added GPU research questions

2. **04-DECISIONS.md**
   - Updated D-008 (GPU Acceleration) to Phase 1.5 strategy
   - Added D-008b (GPU Exception to simple_* first policy)
   - Updated rationale, implications, reversibility

3. **06-RISKS.md**
   - Updated RISK-001 (Performance) with GPU mitigation
   - Added RISK-001b (GPU integration bugs)
   - Detailed Phase 1.5 GPU mitigation strategy

4. **07-RECOMMENDATION.md**
   - Added Phase 1.5 GPU Integration section (comprehensive)
   - Updated README template with GPU support info
   - Updated Dependencies table to include CUDA libraries
   - Added Phase timeline table with Phase 1.5
   - Updated total timeline: 11-12 weeks (CPU) vs 13-14 weeks (GPU)

---

## Key Takeaways

### GPU Strategy (User's NVIDIA 5070 Ti)
✅ **Phase 1.5 GPU acceleration** (after MVP verified)
✅ **Optional, not mandatory** (CPU-only path works identically)
✅ **Expected speedup:** 5-20x for matrix operations
✅ **Maturity:** CUDA is proven technology, not risky
✅ **Architecture:** Eiffel contracts preserved; CUDA is optimization layer

### Phase 2+ Justifications
✅ **All deferred features justified** with specific reasons
✅ **Distributed Training:** Multi-machine complexity + ecosystem gap (no simple_distributed)
✅ **AutoML/NAS:** Requires search algorithms not in simple_optimization yet
✅ **Causal Inference:** Orthogonal goal; requires domain expertise; market not ready
✅ **Advanced NN Architectures:** Domain-specific (Conv, RNN); MLP covers MVP

### simple_* First Policy
✅ **Exception created for GPU** (intentional, documented, justified)
✅ **Applies to:** C/C++ trusted external libraries only
✅ **Pattern:** Same as ISE base library, scikit-learn practices
✅ **Control:** GPU optional; CPU path unchanged

### Timeline Impact
⏱️ **MVP (CPU only):** 11-12 weeks (Phases 1-7)
⏱️ **With GPU:** 13-14 weeks (Phases 1-3, 1.5, 4-7)
⏱️ **Parallel work possible:** GPU research during Phase 4 implementation

---

## Next Action

Research documents are now complete with:
- ✅ Comprehensive GPU strategy for Phase 1.5
- ✅ Detailed justifications for all Phase 2+ deferrals
- ✅ Definitions of deferred features (Distributed Training, AutoML/NAS, Causal Inference)
- ✅ simple_* first policy exception for GPU (documented, rationale)
- ✅ Updated timeline, risks, decisions, recommendations

**Ready to proceed to Phase 0:** Intent Capture with updated understanding.
