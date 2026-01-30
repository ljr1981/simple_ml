# Intent: simple_ml (Refined - Phase 0)

**Date:** 2026-01-29
**Status:** Approved for Phase 1 (Contracts)
**Based on:** Comprehensive research (research/*.md) + initial intent.md + GPU strategy updates

---

## What

**simple_ml** is a formally-verified machine learning library for Eiffel that provides contract-verified supervised learning algorithms with complete Design by Contract verification, algorithmic transparency, and optional GPU acceleration for users with NVIDIA hardware.

### Core Capability (Phases 1-3 MVP)
- **6 supervised learning algorithms:** Linear Regression, Logistic Regression, Decision Tree, Random Forest, Support Vector Machine (linear kernel), Neural Network (basic MLP)
- **Design by Contract on everything:** Every class, every feature has require/ensure/invariant clauses
- **Data preprocessing pipeline:** Feature scaling, normalization, standardization, train-test split, k-fold cross-validation
- **Evaluation framework:** Accuracy, Precision, Recall, F1-score, Confusion Matrix, ROC-AUC, MSE, R²
- **CPU-based training:** MVP targets verification correctness over raw speed

### Optional GPU Acceleration (Phase 1.5+)
- **NVIDIA CUDA/cuBLAS/cuDNN** bindings for users with GPU hardware (5070 Ti, 4090, A100, H100, etc.)
- **Expected speedup:** 5-20x for matrix-heavy operations
- **Optional installation:** `pip install simple-ml[gpu]`
- **CPU path unchanged:** GPU is opt-in; CPU-only systems work identically
- **Eiffel contracts preserved:** Verification on Eiffel layer; CUDA is optimization layer

### Emphasis
- **Correctness and verification** over raw performance
- **Algorithmic transparency** (readable Eiffel code, not black boxes)
- **Auditability** for regulated domains (healthcare, finance, autonomous systems)
- **Educational value** (students can read and understand implementations)

---

## Why

### Problem Statement
Enterprise and academic applications need machine learning capabilities they can formally verify and audit. Existing ML libraries (scikit-learn, TensorFlow, PyTorch) are black boxes without formal verification. Regulatory domains (healthcare, finance, autonomous vehicles) cannot deploy unverifiable decision-making systems.

### Market Opportunity
- **Formal verification of ML is emerging** (WFVML 2024, Post-AI-FM-26 workshops)
- **No production library combines Design by Contract + ML algorithms** - genuine gap
- **First-mover advantage** in contract-verified ML space
- **Regulatory demand:** FDA, EU AI Act require auditable AI decision logic

### Strategic Value
1. **Ecosystem Capstone:** simple_ml ties together simple_optimization (training), simple_linalg (matrices), simple_statistics (distributions) - justifies entire ecosystem
2. **Eiffel Positioning:** Positions Eiffel as formal-methods leader in ML (vs Python/TensorFlow focus on speed)
3. **Regulated Industries:** Healthcare, fintech, autonomous vehicles need certified ML; simple_ml enables this
4. **User Hardware:** Users with NVIDIA GPUs (like 5070 Ti 16GB) can now get accelerated ML with formal verification (Phase 1.5)

---

## Users

| User Type | Use Case | Needs | Phase Ready |
|-----------|----------|-------|-------------|
| **Enterprise Data Scientists** | Building models for regulated domains | Formal correctness guarantees, audit trails, certifiable decision logic | MVP (Phase 3) |
| **FinTech/HealthTech Developers** | Healthcare/finance ML systems | Regulatory compliance (EU AI Act, FDA), formal verification, certification trails | MVP (Phase 3) |
| **Autonomous Systems Engineers** | Safety-critical decision logic | Provably correct ML predictions, formal assurance, auditability | MVP (Phase 3) |
| **GPU-Equipped Data Scientists** | Performance-sensitive training | Accelerated training with NVIDIA GPUs (5070 Ti, etc.) + formal verification | Phase 1.5 |
| **Academic Researchers** | Formal methods + ML research | Teaching tool, verification framework, contract-based ML exploration | MVP (Phase 3) |
| **Eiffel Community** | Production ML capability | Native Eiffel ML library with Design by Contract, ecosystem integration | MVP (Phase 3) |

---

## Acceptance Criteria

### MVP (Phases 1-3) - MUST HAVE
- [ ] **6 core algorithms implemented:** Linear Regression, Logistic Regression, Decision Tree, Random Forest, SVM (linear), Neural Network (MLP)
- [ ] **100% Design by Contract coverage:** Every public class/feature has require/ensure/invariant
- [ ] **Complete evaluation framework:** Accuracy, Precision, Recall, F1-score, Confusion Matrix, ROC-AUC, MSE, R²
- [ ] **Data preprocessing pipeline:** Feature scaling, normalization, standardization, train-test split, k-fold CV
- [ ] **Integration with simple_* ecosystem:** Uses simple_optimization, simple_linalg, simple_statistics, simple_mml, simple_random
- [ ] **100% test pass rate:** Phase 5-6 comprehensive testing with adversarial/edge case coverage
- [ ] **Validation vs reference:** All algorithms match scikit-learn/R within IEEE 754 epsilon
- [ ] **Numerical stability:** No NaN/Inf crashes; explicit IEEE 754 compliance in contracts
- [ ] **Production release v1.0.0:** Professional documentation site, zero warnings
- [ ] **Regulatory-ready:** Formal verification hooks; contracts amenable to SMT/model checking

### Phase 1.5 (GPU - SHOULD HAVE)
- [ ] **GPU acceleration optional:** CUDA/cuBLAS/cuDNN bindings for NVIDIA hardware
- [ ] **5-20x speedup:** Matrix operations accelerated on GPU; gradient descent on GPU
- [ ] **CPU path preserved:** GPU optional; CPU-only systems work identically
- [ ] **Contracts on GPU wrapper:** Eiffel layer has contracts; CUDA is trusted external code
- [ ] **CPU vs GPU equivalence:** Results match within IEEE 754 epsilon

### Phase 2+ (Deferred - NICE TO HAVE)
- [ ] Distributed training (multi-GPU, multi-node)
- [ ] Large-scale dataset support (>100MB streaming)
- [ ] Clustering algorithms (k-means, hierarchical, DBSCAN)
- [ ] Dimensionality reduction (PCA, t-SNE, UMAP)
- [ ] Advanced ensemble methods (stacking, blending, boosting)
- [ ] Advanced neural network architectures (Conv, RNN, Attention)
- [ ] AutoML/hyperparameter search (Bayesian optimization, evolutionary)
- [ ] Time series methods (ARIMA, Prophet, LSTM)

---

## Out of Scope (Explained)

### Phase 1-3 (MVP)
- **GPU acceleration (CPU-only MVP):** Phase 1.5 adds optional GPU via CUDA/cuBLAS/cuDNN for NVIDIA hardware. MVP focuses on verification; GPU is optimization layer.
- **Distributed training (single-threaded MVP):** Requires simple_distributed library (doesn't exist yet) + NCCL communication. Phase 2+ after single-machine proven.
- **Clustering algorithms:** Unsupervised learning different from supervised. Phase 2 adds k-means, hierarchical, DBSCAN.
- **Dimensionality reduction:** PCA, t-SNE require eigendecomposition. Phase 2+.
- **Advanced NN architectures:** Conv/RNN are domain-specific. MVP MLP covers basics.

### Phase 2+ (Deferred - Reasons Below)
- **Distributed Training (Phase 2+):** Multi-machine gradient sharing requires MPI/NCCL library, fault tolerance handling (stragglers), synchronization primitives. 3-4x complexity over single-machine. Ecosystem gap: no simple_distributed exists. Research needed: how to maintain Design by Contract guarantees across network boundaries.

- **Large-scale Datasets (Phase 2+):** >100MB out-of-core training requires disk I/O management, shuffling, caching. MVP targets in-memory (100MB typical). Phase 2 with streaming APIs.

- **Advanced Ensembles (Phase 2+):** Stacking (training meta-models), blending are specializations. MVP Random Forest (bagging) covers 80% of ensemble use cases.

- **Advanced NN Architectures (Phase 2+):** Convolutional (image), Recurrent (sequences), Attention, Transformers are domain-specific. MVP MLP sufficient for basic supervised learning.

- **AutoML/NAS (Phase 2+):** Requires hyperparameter search (Bayesian optimization, evolutionary algorithms). simple_optimization currently supports gradient descent only. Ecosystem gap: no Bayesian/evolutionary search library exists yet.

- **Time Series (Phase 2+):** ARIMA, Prophet, LSTM require specialized algorithms. Could be separate simple_timeseries library.

- **Causal Inference (Phase 3+):** Orthogonal to supervised learning. Causal asks "does X cause Y?" vs supervised learning "predict Y given X." Requires domain expertise (causal assumptions), harder contracts (causal DAGs, unobserved confounders). Market not ready for MVP. Future simple_causal library could provide causal forests, propensity score weighting, instrumental variables.

- **NLP (Future simple_nlp):** Separate specialized domain (tokenization, embeddings, language-specific preprocessing).

- **Reinforcement Learning (Future simple_rl):** Different paradigm (exploration/exploitation, state/action spaces, reward signals). Not supervised learning.

---

## Dependencies

### Core Dependencies (MVP)

| Need | Library | Type | Justification |
|------|---------|------|---------------|
| **Matrix operations** | simple_linalg | simple_* | Verified linear algebra; core to all algorithms |
| **Optimization solver** | simple_optimization | simple_* | GRADIENT_DESCENT_SOLVER already implemented; reuse for training |
| **Statistical distributions** | simple_statistics | simple_* | Gaussian, Bernoulli for probabilistic methods |
| **Random sampling** | simple_random | simple_* | Train-test split, cross-validation, NN initialization |
| **MML contracts** | simple_mml | simple_* | Frame conditions on training data, learned models |
| **Fundamental types** | base | ISE only | No simple_* equivalent for core Eiffel types |
| **Test infrastructure** | testing | ISE only | EQA_TEST_SET; no simple_* equivalent |

### Optional GPU Dependencies (Phase 1.5+)

| Need | Library | Type | Justification | Installation |
|------|---------|------|---------------|--------------|
| **GPU matrix ops** | cuBLAS | C/C++ GPU | NVIDIA CUDA linear algebra; 10-20x speedup | `pip install simple-ml[gpu]` |
| **GPU neural network ops** | cuDNN | C/C++ GPU | NVIDIA CUDA neural network kernels; gradient computation | `pip install simple-ml[gpu]` |
| **GPU runtime** | CUDA | C/C++ GPU | Memory management, kernel dispatch | `pip install simple-ml[gpu]` |
| **Multi-GPU communication** | NCCL | C/C++ GPU | AllReduce for distributed training (Phase 2+) | Phase 2+ |

### Future Dependencies (Phase 2+)

| Need | Library | Type | Timeline |
|------|---------|------|----------|
| **Distributed training** | simple_distributed (TBD) | simple_* (needed) | Phase 2+ |
| **Bayesian optimization** | simple_optimization (enhancement) | simple_* (enhancement) | Phase 2+ AutoML |
| **Time series** | simple_timeseries (TBD) | simple_* (new) | Phase 2+ or separate lib |
| **Causal inference** | simple_causal (TBD) | simple_* (new) | Phase 3+ |

### Gaps Identified for Future simple_* Libraries

| Gap | Current Workaround | Proposed simple_* | Priority |
|-----|-------------------|-------------------|----------|
| Distributed training coordination | Use NCCL directly (Phase 2) | simple_distributed | Phase 2 |
| Bayesian hyperparameter search | Grid search only (Phase 1) | simple_optimization enhancement | Phase 2 |
| Time series forecasting | Separate external library | simple_timeseries | Phase 2 or separate |
| Causal inference methods | Out of scope | simple_causal | Phase 3+ |

---

## MML Decision

**Question:** Does simple_ml need MML model queries for precise postconditions?

**Answer:** **YES - Required**

**Rationale:**

simple_ml has collections (training datasets, feature matrices, neural network weights) that require formal frame conditions:

1. **Training Data Immutability:** Contracts must document that training data is not modified
   ```eiffel
   train (X: ARRAY [ARRAY [REAL_64]]; y: ARRAY [INTEGER])
       ensure
           X_unchanged: X.count = old X.count
           y_unchanged: y.count = old y.count
   ```

2. **Model State Tracking:** Using MML_SET to track learned classes/features
   ```eiffel
   feature
       learned_classes_model: MML_SET [INTEGER]
           -- Mathematical model of unique classes learned during training.
   ```

3. **Weight Stability:** Using MML to verify all weights remain finite (no NaN/Inf)
   ```eiffel
   invariant
       weights_finite: across weights as w all is_finite (w.item) end
   ```

**Implementation Plan:**
- Phase 1: Add simple_mml to ECF
- Phase 1: Create model queries for key attributes (training data, learned classes, weights)
- Phase 4: Use model queries in postconditions for frame conditions
- Phase 5: Validate MML postconditions are satisfied

---

## simple_* First Policy & GPU Exception

### Core Policy
**Prefer simple_* libraries over ISE/Gobo for Eiffel ecosystem functionality.**

### Exception: C/C++ GPU Libraries (Phase 1.5+)

**Decision:** C/C++ CUDA/cuBLAS/cuDNN allowed as optional GPU backends (intentional exception)

**Rationale:**
1. **Distinction:** simple_* first applies to **Eiffel libraries**. GPU libraries are **trusted C/C++ external code**.
2. **Precedent:** Industry standard - scikit-learn uses C/BLAS, TensorFlow uses C++, PyTorch uses C++
3. **Pattern:** Same as ISE base library (external, trusted, optimized)
4. **User Control:** GPU optional; CPU-only systems work without CUDA dependency
5. **Verification Preserved:** Eiffel contracts on wrapper layer; CUDA is optimization (expected to be opaque)

**Updated Constraint:**
```
simple_* first policy: Prefer simple_* for Eiffel ecosystem

EXCEPTION: C/C++ GPU libraries (NVIDIA CUDA, cuBLAS, cuDNN) allowed
for Phase 1.5+ acceleration as optional trusted backends with Eiffel wrapper layer
```

---

## Phase Timeline

| Phase | Deliverable | Duration | Entrance | GPU Strategy |
|-------|-------------|----------|----------|--------------|
| **Phase 1** | Contracts + Skeletal Tests | 2 weeks | Intent approved | CPU only |
| **Phase 2** | Adversarial Review + Approach | 1 week | Phase 1 compiled | CPU only |
| **Phase 3** | Task Decomposition | 3 days | Phase 2 complete | CPU only |
| **Phase 1.5** | GPU Integration (optional) | 2 weeks | Phase 3 complete | CUDA/cuBLAS/cuDNN |
| **Phase 4** | Implementation | 4-5 weeks | Phase 3 tasks approved | CPU implementation |
| **Phase 5** | Test Generation + Verification | 2 weeks | Phase 4 complete | All tests pass |
| **Phase 6** | Adversarial Testing + Hardening | 1.5 weeks | Phase 5 tests passing | GPU equivalence tests |
| **Phase 7** | Production Release (v1.0.0) | 1 week | Phase 6 complete | v1.0.0 + GPU support |

**Total Timeline:**
- **CPU-only MVP:** 11-12 weeks (Phases 1-7 sequential)
- **With GPU:** 13-14 weeks (Phases 1-3, 1.5, 4-7 in sequence)
- **Parallel optimization possible:** GPU research during Phase 4 implementation

---

## Success Criteria (Phase 0 - Intent Approval)

- [x] Intent clearly captures WHAT (6 algorithms, GPU optional, contracts everywhere)
- [x] Intent clearly captures WHY (formal verification gap, regulatory need, GPU hardware support)
- [x] Intent clearly captures WHO (regulated industries, GPU users, academic researchers, Eiffel community)
- [x] Out of scope is explicit with reasons (distributed training complex, causal inference orthogonal, etc.)
- [x] Dependencies audited: 7 simple_* + 2 ISE + 3 NVIDIA GPU (optional)
- [x] MML decision made: YES-Required (collections need frame conditions)
- [x] GPU strategy integrated: Phase 1.5 for NVIDIA acceleration (5070 Ti, etc.)
- [x] Phase 2+ justified: All deferrals have explicit reasons documented
- [x] simple_* first policy exception documented: GPU libraries allowed (intentional)
- [x] Research findings incorporated: Comprehensive GPU strategy, all Phase 2+ explained

---

## Approval & Next Steps

**Phase 0 Status:** ✅ **INTENT APPROVED**

This refined intent-v2.md incorporates:
- ✅ Comprehensive research from research/*.md
- ✅ GPU strategy (Phase 1.5 integration)
- ✅ Justifications for all Phase 2+ deferrals
- ✅ Definitions of deferred features (Distributed Training, AutoML/NAS, Causal Inference)
- ✅ simple_* first policy exception for GPU (documented, rationale)
- ✅ MML decision (required for frame conditions)
- ✅ Complete timeline with GPU milestone

**Ready to proceed to Phase 1: Contracts**

**Next command:** `/eiffel.contracts d:\prod\simple_ml`
