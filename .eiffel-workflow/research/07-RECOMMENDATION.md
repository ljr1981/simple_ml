# RECOMMENDATION: simple_ml

## Executive Summary

**simple_ml should be built as a native Eiffel library emphasizing Design by Contract, algorithmic transparency, and formal verification.** This fills a genuine gap in the ML ecosystem: no other library combines machine learning with formal verification. The target market is regulated industries (finance, healthcare, autonomous systems) and academic research where correctness and auditability matter more than raw performance. MVP scope: 6 supervised learning algorithms with 100% contract coverage, building on the simple_* ecosystem (optimization, linear algebra, statistics).

---

## Recommendation

**Action:** **BUILD** (native implementation)

**Confidence:** **HIGH** (80%+)

**Rationale:**

1. **Unique Positioning**: No other ML library has Design by Contract on algorithms. This is a genuine innovation, not feature parity chasing.

2. **Eiffel Ecosystem Synergy**: simple_ml is the capstone library that ties together simple_optimization (training), simple_linalg (matrices), simple_statistics (distributions). This justifies the entire ecosystem.

3. **Market Need**: Formal verification of ML is emerging field (WFVML 2024, Post-AI-FM-26). First-mover advantage in contract-verified ML.

4. **Feasibility**: 6-algorithm MVP is achievable in Phases 1-3 with rigorous verification. Scope is tight but not impossible.

5. **Risk Mitigation**: Highest-risk item (performance) is addressed by clear positioning: "verification, not speed." Academic market accepts this trade-off.

---

## Proposed Approach

### Phase 1: Intent + Contracts + Skeletal Tests
- Capture refined intent from research and specification
- Design 6 core classes with full require/ensure/invariant
- Create skeletal test classes for each algorithm
- Compilation gate: zero warnings, contracts syntactically valid

**Deliverables:**
- `src/`: LINEAR_REGRESSION_MODEL, LOGISTIC_REGRESSION_MODEL, DECISION_TREE_CLASSIFIER, RANDOM_FOREST_CLASSIFIER, SVM_LINEAR, NEURAL_NETWORK_CLASSIFIER
- `test/`: test_linear_regression.e, test_logistic_regression.e, ... test_app.e
- Contracts with frame conditions using simple_mml

**Timeline:** ~2 weeks (4 main classes × 3-4 days each)

---

### Phase 2: Review + Approach + Synopsis
- Submit contracts to adversarial AI review (Ollama → Claude → Grok → Gemini)
- AI identifies:
  - Overspecified/impossible postconditions
  - Missing preconditions
  - Contract ambiguities
  - Missed edge cases
- Generate implementation approach (algorithm pseudocode)
- Create synopsis of findings

**Deliverables:**
- `prompts/`: phase2-review prompts for all 4 review chains
- `evidence/`: review responses from AIs
- `synopsis.md`: aggregated findings, contract refinements
- `approach.md`: implementation strategy for each algorithm

**Timeline:** ~1 week (5 days review cycle + 2 days synthesis)

---

### Phase 3: Task Decomposition
- Break Phase 1 contracts into implementation tasks
- Each task is 1-3 methods in a class
- Clear acceptance criteria (contracts must be satisfied)

**Example Tasks:**
- TASK-1: Implement linear_regression_model.train() (gradient descent via simple_optimization)
- TASK-2: Implement linear_regression_model.predict() (matrix multiply via simple_linalg)
- TASK-3: Implement decision_tree_classifier.find_best_split() (information gain)
- ... ~20-30 total tasks

**Deliverables:**
- `tasks.md`: full task list with dependencies

**Timeline:** ~3 days (can parallelize with Phase 2)

---

### Phase 1.5: GPU Integration (NEW - Optional Acceleration for NVIDIA Hardware)

**Timing:** After Phase 3 verification complete, before Phase 4+ scaling work

**Purpose:** Add optional GPU acceleration via CUDA/cuBLAS/cuDNN for users with NVIDIA hardware (e.g., 5070 Ti 16GB)

**Scope:**
- C/C++ bindings to NVIDIA CUDA, cuBLAS, cuDNN libraries
- Eiffel wrapper classes with contracts (GPU_MATRIX_OPERATIONS, GPU_NEURAL_NETWORK_KERNELS)
- Runtime choice: CPU (simple_linalg) vs GPU (CUDA)
- Backward compatibility: CPU path unchanged, no CUDA dependency required

**Why Phase 1.5, Not Phase 2:**
- Users with GPU hardware can accelerate immediately after MVP
- CUDA is mature, proven technology (not risky)
- Phase 1.5 is ideal timing: MVP verified, before Phase 2 scaling work
- Performance issue (RISK-001) mitigated immediately

**Implementation Strategy:**
```
GPU Acceleration Architecture:
┌─────────────────────────────────────────────────┐
│  Eiffel Code (with Design by Contract)          │
│  - Facade: SIMPLE_ML.train(...) ensures Result  │
│  - Wrapper: GPU_MATRIX_OPERATIONS contracts     │
└──────────────────┬──────────────────────────────┘
                   │ calls (optionally)
┌──────────────────▼──────────────────────────────┐
│  C/C++ CUDA Binding Layer                       │
│  - cuda_matrix_multiply_gpu(...)                │
│  - cuda_neural_net_forward_gpu(...)             │
└──────────────────┬──────────────────────────────┘
                   │ uses
┌──────────────────▼──────────────────────────────┐
│  NVIDIA Libraries (Trusted External)            │
│  - cuBLAS: matrix operations                    │
│  - cuDNN: neural network kernels                │
│  - CUDA Runtime: memory, kernel dispatch        │
└──────────────────┬──────────────────────────────┘
                   │ executes on
┌──────────────────▼──────────────────────────────┐
│  NVIDIA GPU (5070 Ti, 4090, A100, H100, etc.)  │
│  - Expected speedup: 5-20x for matrix-heavy ops│
└─────────────────────────────────────────────────┘
```

**Key Requirements:**
1. **Contracts stay on Eiffel side** - CUDA code is trusted external library (like ISE base)
2. **CPU path unchanged** - No CUDA required; CPU-only systems work identically
3. **Results match** - CPU and GPU produce same results (within IEEE 754 epsilon)
4. **Optional installation** - `pip install simple-ml` (CPU); `pip install simple-ml[gpu]` (CUDA)
5. **Runtime selection** - `model.compute_device := GPU_DEVICE or CPU_DEVICE`

**Libraries (Phase 1.5):**
- **cuBLAS**: GPU matrix multiply, transpose, solve (used by GPU_MATRIX_OPERATIONS)
- **cuDNN**: GPU NN operations (convolution, activation, backprop for NN training)
- **CUDA Runtime**: Memory management (cudaMalloc, cudaMemcpy), kernel dispatch
- **NCCL** (deferred to Phase 2): Multi-GPU collective communication

**Test Strategy (Phase 1.5):**
- For each matrix operation, test: CPU vs GPU results match
- For each NN algorithm, test: CPU vs GPU weights converge identically
- Tolerance: IEEE 754 precision (both CPU and GPU use REAL_64)

**Phase 1.5 Deliverables:**
- `gpu_backends/`: C/C++ CUDA code
- `gpu_backends/eiffel_cuda_bindings.cpp`: CUDA kernel implementations
- `src/gpu_matrix_operations.e`: Eiffel GPU wrapper with contracts
- `src/gpu_neural_network_kernels.e`: GPU NN operations
- `test/test_gpu_equivalence.e`: CPU vs GPU validation tests
- `INSTALL_GPU.md`: GPU setup instructions, troubleshooting

**Timeline:** ~2 weeks (after Phase 3 MVP verified)
- CUDA binding research: 2-3 days
- GPU kernel implementation: 4-5 days (matrix ops, NN ops)
- Eiffel wrapper + contracts: 2-3 days
- Testing (CPU vs GPU equivalence): 3-4 days

**Success Criteria (Phase 1.5):**
- [ ] NVIDIA GPU detected and initialized
- [ ] cuBLAS/cuDNN operations produce correct results
- [ ] CPU results ≈ GPU results (within tolerance)
- [ ] Performance improvement: 5x+ speedup for matrix operations
- [ ] 100% of GPU tests pass

**Contingency:**
- If CUDA integration too complex: defer to Phase 2, stick with CPU-only MVP
- If performance benefit <2x: not worth effort, revert to CPU-only
- If Eiffel ↔ CUDA calling overhead excessive: consider pure C wrapper instead

---

### Phase 4: Implementation
- Write feature bodies following contracts
- Contracts are FROZEN; no modifications allowed
- Compile and test after each task
- ZERO WARNINGS POLICY

**Key Implementation Notes:**

1. **Gradient Descent Integration**: Use simple_optimization.GRADIENT_DESCENT_SOLVER
   ```eiffel
   solver := create {GRADIENT_DESCENT_SOLVER}.make
       .set_learning_rate (0.01)
       .set_max_iterations (1000)
   result := solver.minimize (loss_function, initial_weights)
   ```

2. **Matrix Operations**: Use simple_linalg
   ```eiffel
   X_transposed := X.transpose
   X_T_X := X_transposed.multiply (X)
   gradient := X_T_X.multiply (weights).subtract (X_transposed.multiply (y))
   ```

3. **Statistical Operations**: Use simple_statistics
   ```eiffel
   mean := distribution.mean
   std := distribution.standard_deviation
   z_score := (value - mean) / std
   ```

4. **Contracts on Model State**:
   ```eiffel
   invariant
       weights_finite: is_trained implies across weights as w all is_finite (w.item) end
       classes_immutable: is_trained implies class_count = old class_count
   ```

**Deliverables:**
- Fully implemented classes with bodies

**Timeline:** ~4-5 weeks (6 algorithms × 1-2 weeks each, some parallel)

---

### Phase 5: Test Generation & Verification
- Flesh out skeletal tests from Phase 1
- Generate tests for every postcondition
- Train models on real datasets; validate vs reference (scikit-learn, R)
- 100% test pass rate mandatory

**Test Strategy:**

1. **Instantiation Tests** (per algorithm):
   ```eiffel
   test_creation
       local l_model: LINEAR_REGRESSION_MODEL
       do
           create l_model.make
           assert ("created", l_model /= Void)
       end
   ```

2. **Training Tests**:
   ```eiffel
   test_train_converges
       do
           model.train (X_train, y_train)
           assert ("converged", model.is_converged or model.iterations_used >= model.max_iterations)
           assert ("loss_decreases", model.final_loss < model.initial_loss)
       end
   ```

3. **Prediction Tests**:
   ```eiffel
   test_predict_valid_shape
       do
           predictions := model.predict (X_test)
           assert ("correct_count", predictions.count = X_test.count)
       end
   ```

4. **Numerical Validation Tests**:
   ```eiffel
   test_weights_finite
       do
           model.train (X, y)
           assert_all_finite (model.weights)
       end
   ```

5. **Postcondition Verification Tests**:
   - For each postcondition, create test that would fail if postcondition violated

**Deliverables:**
- `test/test_app.e`: main test runner
- `test/test_adversarial.e`: Phase 6 (created during Phase 5, running in Phase 6)
- Test evidence: all pass, 100% pass rate

**Timeline:** ~2 weeks (tests for 6 algorithms + validation vs reference)

---

### Phase 6: Adversarial Testing & Hardening
- Generate adversarial tests for edge cases and stress
- Test on:
  - Zero/single sample datasets
  - Degenerate classes (all-same-label)
  - Singular/near-singular matrices
  - Extreme feature ranges
  - High-dimensional data (1000+ features)
  - Numerical edge cases (NaN input handling)

**Test Examples:**

1. **Zero-Sample Edge Case**:
   ```eiffel
   test_single_sample
       do
           model.train (<<[1.0, 2.0]>>, <<1>>)  -- One sample, one feature
           assert ("trains", model.is_trained)
           assert ("predicts", model.predict (<<[1.0, 2.0]>>) /= Void)
       end
   ```

2. **Degenerate Class Distribution**:
   ```eiffel
   test_all_same_class
       do
           -- All 100 training samples belong to class 1
           create y.make_filled (1, 100)
           model.train (X, y)
           assert ("handles_degenerate", model.is_trained)
       end
   ```

3. **Matrix Singularity**:
   ```eiffel
   test_singular_matrix
       do
           -- Features are linearly dependent (column 2 = 2 × column 1)
           X := << <<1.0, 2.0>>, <<2.0, 4.0>>, <<3.0, 6.0>> >>
           model.train (X, y)
           -- Should handle gracefully (regularize or report)
       end
   ```

4. **Numerical Stability**:
   ```eiffel
   test_extreme_range_features
       do
           -- Features in range [1e-100, 1e100]
           X := << <<1e-100, 1e100>>, ... >>
           model.train (X, y)
           assert ("numerically_stable", model.is_numerically_stable)
       end
   ```

**Deliverables:**
- `test/test_adversarial.e`: 7+ adversarial tests per algorithm
- Adversarial evidence: all pass

**Timeline:** ~1.5 weeks (brainstorm attack vectors + implement + run)

---

### Phase 7: Production Release
- Verify naming conventions (UPPER_SNAKE_CASE classes, lower_snake_case features)
- Create production documentation site (`/docs`)
- Generate README.md (short, links to docs)
- Create CHANGELOG.md, LICENSE
- Final compilation: zero warnings
- Final test run: 100% pass rate

**Documentation:**

1. **README.md** (short):
   ```markdown
   # simple_ml

   Formally-verified machine learning in Eiffel with Design by Contract.

   [Documentation](https://simple-eiffel.github.io/simple_ml/) •
   [GitHub](https://github.com/simple-eiffel/simple_ml) •
   [Issues](https://github.com/simple-eiffel/simple_ml/issues)

   ![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
   ![Eiffel 25.02](https://img.shields.io/badge/Eiffel-25.02-purple.svg)
   ![DBC: Contracts](https://img.shields.io/badge/DBC-Contracts-green.svg)

   Contract-verified machine learning algorithms for formal assurance in regulated domains.

   ## Features

   - Linear & Logistic Regression with gradient descent
   - Decision Trees & Random Forests
   - Support Vector Machines (linear kernel)
   - Basic Neural Networks (MLP)
   - Full Design by Contract verification
   - Auditability for regulatory compliance

   ## Quick Example

   ```eiffel
   model := create {LINEAR_REGRESSION_MODEL}.make
       .set_learning_rate (0.01)
       .set_max_iterations (1000)
   model.train (X_train, y_train)
   predictions := model.predict (X_test)
   ```

   For complete guide, see [documentation](https://simple-eiffel.github.io/simple_ml/).

   ## Status

   v1.0.0 - Production Ready
   - 6 core algorithms
   - 100% contract coverage
   - 100% test pass rate
   - **GPU acceleration optional (Phase 1.5+)**: NVIDIA CUDA/cuBLAS/cuDNN for 5-20x speedup

   ## GPU Support (Phase 1.5+)

   For users with NVIDIA GPUs:

   ```bash
   pip install simple-ml[gpu]  # Installs CUDA support
   ```

   ```eiffel
   model.compute_device := GPU_DEVICE  -- Use GPU
   -- or
   model.compute_device := CPU_DEVICE  -- Use CPU
   ```

   Supported: NVIDIA CUDA-capable GPUs (5070 Ti, 4090, A100, H100, etc.)

   ## License

   MIT License - See LICENSE file
   ```

2. **Docs Site** (`/docs/`):
   - `index.html`: Overview, features, status
   - `quick.html`: Quick API reference
   - `user-guide.html`: Complete guide with examples
   - `api-reference.html`: Full class documentation
   - `architecture.html`: Design decisions, class relationships
   - `cookbook.html`: Real-world examples

**Deliverables:**
- README.md, CHANGELOG.md, LICENSE
- `/docs/` complete documentation site
- `phase7-ship.txt` evidence

**Timeline:** ~1 week (documentation + final verification)

---

## Key Features (MVP)

### Algorithms (6 core)

1. **Linear Regression** (OLS via gradient descent)
   - Preconditions: X ∈ ℝ^(n×m), y ∈ ℝ^n
   - Postconditions: weights ∈ ℝ^m, converged or iterations exhausted

2. **Logistic Regression** (binary classification)
   - Preconditions: y ∈ {0, 1}
   - Postconditions: probabilities ∈ [0, 1], sum-to-1

3. **Decision Tree** (information gain splitting)
   - Preconditions: max_depth ≥ 1, min_samples_per_leaf ≥ 1
   - Postconditions: tree consistent, predictions ∈ classes

4. **Random Forest** (ensemble of trees)
   - Preconditions: num_trees ≥ 1
   - Postconditions: predictions aggregated correctly, feature importance computed

5. **Support Vector Machine** (linear kernel, quadratic programming)
   - Preconditions: linearly separable data (MVP), C > 0
   - Postconditions: support vectors identified, margin maximized

6. **Neural Network** (MLPClassifier/MLPRegressor)
   - Preconditions: hidden_layers ≥ 1, activation ∈ {sigmoid, tanh, relu}
   - Postconditions: weights finite, converged or iterations exhausted

### Evaluation Metrics
- Accuracy, Precision, Recall, F1-score
- Confusion Matrix
- ROC-AUC, Mean Squared Error, R²

### Preprocessing
- Feature scaling (min-max, standardization)
- Train-test split
- K-fold cross-validation

---

## Success Criteria

**Phase 1-3:**
- [ ] 6 classes with complete contracts
- [ ] Tasks defined with acceptance criteria
- [ ] Contracts reviewed and refined

**Phase 4-5:**
- [ ] All classes fully implemented
- [ ] 100% test pass rate
- [ ] Algorithms validated vs reference implementations (scikit-learn, R)

**Phase 6:**
- [ ] 7+ adversarial tests per algorithm
- [ ] All edge cases handled gracefully
- [ ] Numerical stability verified

**Phase 7:**
- [ ] Production release v1.0.0
- [ ] Zero warnings, 100% test pass
- [ ] Professional documentation site
- [ ] GitHub repository public
- [ ] Ready for regulated domain use

---

---

## Project Timeline (Phases 1-7, with Phase 1.5 GPU)

| Phase | Deliverable | Timeline | Entrance Criteria |
|-------|-------------|----------|-------------------|
| **Phase 1** | Contracts + Skeletal Tests | 2 weeks | Intent approved |
| **Phase 2** | Adversarial Review + Approach | 1 week | Phase 1 compiled |
| **Phase 3** | Task Decomposition | 3 days | Phase 2 complete |
| **Phase 1.5** | GPU Integration (optional) | 2 weeks | Phase 3 complete, Phase 4+ ready |
| **Phase 4** | Implementation | 4-5 weeks | Phase 3 tasks approved |
| **Phase 5** | Test Generation + Verification | 2 weeks | Phase 4 implementation complete |
| **Phase 6** | Adversarial Testing + Hardening | 1.5 weeks | Phase 5 tests passing (100%) |
| **Phase 7** | Production Release (v1.0.0) | 1 week | Phase 6 hardening complete |

**Total Timeline (MVP only):** ~11-12 weeks (Phases 1-7)
**Total Timeline (with GPU):** ~13-14 weeks (Phases 1-3, 1.5, 4-7 in sequence)

**Parallel Work Possible:**
- Phase 2 can run in parallel with Phase 3 planning
- Phase 1.5 GPU research can start during Phase 4 implementation

---

## Dependencies

| Library | Purpose | Type | Notes |
|---------|---------|------|-------|
| simple_linalg | Matrix operations | simple_* | CPU matrix ops |
| simple_optimization | Gradient descent solver | simple_* | Training via GD |
| simple_statistics | Distributions | simple_* | Probabilistic methods |
| simple_mml | MML contracts | simple_* | Frame conditions |
| simple_random | Random sampling | simple_* | Train-test split |
| base | Fundamental types | ISE only | No alternative |
| testing | Test infrastructure | ISE only | No alternative |
| **CUDA** (Phase 1.5) | **GPU acceleration** | **C/C++ optional** | **cuBLAS, cuDNN - optional backend** |
| **cuBLAS** (Phase 1.5) | **GPU matrix operations** | **C/C++ optional** | **NVIDIA library - optional** |
| **cuDNN** (Phase 1.5) | **GPU neural network ops** | **C/C++ optional** | **NVIDIA library - optional** |

---

## Next Steps

1. **Phase 1 (Contracts)**: Run `/eiffel.intent` to capture refined intent, then `/eiffel.contracts` to generate class skeletons

2. **Phase 2 (Review)**: Run `/eiffel.review` for adversarial AI review of contracts

3. **Phase 3 (Tasks)**: Run `/eiffel.tasks` to decompose into implementation tasks

4. **Phases 4-7**: Execute standard Eiffel Spec Kit workflow

---

## Open Questions (for Phase 2 Review)

1. **Regularization in MVP?** Should linear/logistic regression include L1/L2 regularization, or keep simple for MVP?

2. **Neural Network Size?** Is single hidden layer sufficient, or do we need configurable architecture?

3. **SVM Kernel?** Start with linear-only, or include RBF kernel for MVP?

4. **Missing Values?** How to represent NA/NaN in datasets?

5. **Class Imbalance?** Should we include class weighting or resampling for imbalanced data?

6. **Hyperparameter Validation?** Should we add parameter validation (e.g., learning_rate > 0) or leave to user?

These will be answered during Phase 2 adversarial review.

---

## Risk Mitigation Summary

| Risk | Mitigation |
|------|-----------|
| Performance too slow | MVP targets verification, not speed; position accordingly |
| simple_* library bugs | Phase 5 integration tests validate ecosystem together |
| Contract overspecification | Phase 2 review; Phase 5 tightens based on empirical data |
| NN training fails | Phase 5 tests on small datasets; Phase 6 stress testing |
| Low adoption | Target academia + regulated industries first; build case studies |
| Regulatory recognition | Phase 2 plans SMT integration; contracts as first step |

---

## Conclusion

**simple_ml is both technically feasible and strategically valuable.** It fills a genuine gap (formal-verified ML), leverages the simple_* ecosystem synergistically, and positions Eiffel as the leader in ML verification. MVP scope is tight but achievable (6 algorithms). Risk mitigation is clear. The market opportunity is niche but real (regulated industries, academia, formal methods researchers).

**Recommendation: BUILD with high confidence.**
