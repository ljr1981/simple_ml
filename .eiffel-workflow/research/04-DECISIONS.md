# DECISIONS: simple_ml

## Decision Log

### D-001: Native Implementation vs Wrapping Existing Library

**Question:** Should we build simple_ml from scratch with Eiffel idioms or wrap an existing library like scikit-learn?

**Options:**
1. **Native Build (CHOSEN)**: Write all algorithms in Eiffel with full Design by Contract
   - Pros: Eiffel-idiomatic, 100% Design by Contract, algorithms transparent, full control
   - Cons: More effort, must ensure correctness ourselves, performance trade-off vs optimized C

2. **Wrap scikit-learn/TensorFlow**: Binding layer to Python libraries
   - Pros: Leverage proven algorithms, mature implementations, good performance
   - Cons: Loses Design by Contract (python code unverified), not Eiffel-idiomatic, complex binding layer

3. **Port scikit-learn to Eiffel**: Translate Python to Eiffel line-by-line
   - Pros: Proven algorithms, familiar API
   - Cons: Enormous effort (100K+ lines), doesn't add new value, tedious mechanical work

**Decision:** **Native Build** - Create simple_ml with full Design by Contract

**Rationale:**
- Simple_* ecosystem is all native Eiffel for control and verification
- Design by Contract is the core value proposition vs other ML libraries
- Algorithms are well-understood; implementation is engineering, not research
- Building from scratch allows Eiffel-idiomatic design (e.g., builder pattern for config)
- Positions Eiffel uniquely in formal-verified ML space

**Implications:**
- Requires careful algorithm implementation (need numerical stability expertise)
- Must validate algorithms against reference implementations (scikit-learn, R)
- Performance will be CPU-bound (no GPU in MVP)
- Educational value is high (transparent algorithms)

**Reversible:** No - committed to this approach for Phase 1+

---

### D-002: MVP Algorithm Selection

**Question:** Which algorithms should we prioritize in MVP (Phases 1-3) vs Phase 2+?

**Options:**
1. **Minimal (5 algorithms)**: Linear, Logistic, DecisionTree, RandomForest, SVM
   - Pros: Focused scope, achievable in Phase 1-3
   - Cons: Doesn't cover clustering, dimensionality reduction

2. **Comprehensive (10+ algorithms)**: Add clustering, PCA, basic NN
   - Pros: Broader capability
   - Cons: Scope creep, harder to verify contracts

3. **Neural-Network-First**: Start with basic MLP, add classics later
   - Pros: Trendy, appeals to modern ML community
   - Cons: More complex, algorithms are harder to verify, misses traditional ML focus

**Decision:** **Minimal (5 algorithms) + basic Neural Network = 6 core**

| Algorithm | MVP Phase | Rationale |
|-----------|-----------|-----------|
| Linear Regression | Phase 1 (MVP) | Simplest; foundation for others |
| Logistic Regression | Phase 1 (MVP) | Natural extension; widely used |
| Decision Tree | Phase 1 (MVP) | Foundation for Random Forest |
| Random Forest | Phase 1 (MVP) | Ensemble; shows combination patterns |
| Support Vector Machine | Phase 1 (MVP) | Classic; covers margin-based methods |
| Neural Network (basic MLP) | Phase 1 (MVP) | Covers deep learning; backpropagation important |
| Clustering (k-means) | Phase 2 | Unsupervised; deferred |
| Dimensionality Reduction (PCA) | Phase 2 | Secondary; deferred |
| Time Series (ARIMA) | Phase 2 | Specialized domain |

**Rationale:**
- 5-6 algorithms covers supervised learning (the highest-demand domain)
- Builds on gradient descent (already in simple_optimization)
- Can be done in 3 phases with rigorous verification
- Covers both classical and deep learning paradigms
- Directly uses simple_optimization, simple_linalg, simple_statistics

**Implications:**
- Scope is manageable; keeps verification bar high
- Unsupervised learning deferred to Phase 2 (bigger design effort)
- Time series is specialized; separate library option (simple_timeseries)

**Reversible:** Yes - Phase 2 can add clustering/PCA without breaking existing APIs

---

### D-003: Gradient Descent vs Analytical Solutions

**Question:** For linear/logistic regression, use gradient descent or closed-form (normal equation)?

**Options:**
1. **Gradient Descent (CHOSEN)**: Use simple_optimization.GRADIENT_DESCENT_SOLVER for all
   - Pros: Unified approach, scalable to neural networks, reuses simple_optimization
   - Cons: Requires hyperparameter tuning (learning rate), slower convergence than normal equation

2. **Analytical (Normal Equation)**: Linear regression via (X^T X)^(-1) X^T y
   - Pros: Direct solution, no hyperparameter tuning, mathematically elegant
   - Cons: Requires matrix inversion (numerically unstable), doesn't scale to non-linear

3. **Hybrid**: Use normal equation for linear, gradient descent for logistic/neural
   - Pros: Best of both
   - Cons: Two implementations, maintenance overhead

**Decision:** **Gradient Descent (unified approach)**

**Rationale:**
- Leverages simple_optimization (already verified)
- Single algorithm scales from linear to neural networks
- Teaches users convergence, learning rates, stopping criteria
- Extends naturally to mini-batch, stochastic variants

**Implications:**
- Linear regression postconditions must verify convergence (via loss function decrease)
- Must document learning rate selection guidance
- Training may be slower than analytical; worth it for unification

**Reversible:** Partially - could add normal equation as optimization in Phase 2

---

### D-004: Contract Design for Probabilistic Outputs

**Question:** How to write contracts for algorithms that produce probabilistic outputs (e.g., logistic regression)?

**Options:**
1. **Deterministic Contracts (CHOSEN)**: Guarantee that probabilities sum to 1, are in [0,1]
   - Pros: Verifiable, formal
   - Cons: Doesn't guarantee output quality/accuracy

2. **No Probabilistic Contracts**: Just document expected behavior
   - Pros: Simpler
   - Cons: Loses verification advantage

3. **Statistical Contracts**: Probability assertions (e.g., mean squared error < threshold)
   - Pros: Meaningful
   - Cons: Hard to verify on one prediction; need aggregate assertions

**Decision:** **Deterministic Contracts + aggregate test verification**

```eiffel
predict_proba (a_sample: ARRAY [REAL_64]): ARRAY [REAL_64]
    require
        valid_sample: a_sample.count = feature_count
    ensure
        valid_probabilities: across Result as r all r.item >= 0.0 and r.item <= 1.0 end
        sums_to_one: across Result as r all abs (sum_probabilities (Result) - 1.0) < 0.0001 end
        correct_length: Result.count = class_count
    end
```

**Rationale:**
- Contracts verify structural correctness (probabilities are valid)
- Phase 5 tests verify accuracy (must achieve >80% on test set)
- Separates concerns: contract = structure, tests = quality

**Implications:**
- Every probabilistic output has sum-to-1 invariant
- Model quality verified in tests, not contracts
- Users can trust output structure even if accuracy varies

**Reversible:** Yes - can add statistical contracts in Phase 2

---

### D-005: Configuration Pattern: Builder vs Named Parameters

**Question:** How should users configure hyperparameters?

**Options:**
1. **Builder Pattern with Chaining (CHOSEN)**: `model.set_learning_rate(0.01).set_max_iterations(1000)`
   - Pros: Fluent, discoverable, modern Eiffel style, reuses simple_optimization pattern
   - Cons: More typing

2. **Constructor Parameters**: `create model.make (learning_rate=0.01, max_iterations=1000)`
   - Pros: Simple, clear
   - Cons: Many parameters = long signatures; Eiffel doesn't have named parameters

3. **Configuration Object**: `create config.make; config.set_learning_rate(0.01); create model.make(config)`
   - Pros: Organized
   - Cons: Extra layer of indirection

**Decision:** **Builder Pattern with chaining**

```eiffel
model := create {LINEAR_REGRESSION_MODEL}.make
    .set_learning_rate (0.01)
    .set_max_iterations (1000)
    .set_regularization (0.0001)
```

**Rationale:**
- Matches simple_optimization pattern (already established)
- Fluent interface is modern Eiffel style
- Chainable methods return `like Current` - documented pattern
- Contract validation happens in each setter

**Implications:**
- Every hyperparameter is a setter returning `like Current`
- Default values set in `make`; overridden by setters
- Configuration immutable after training begins

**Reversible:** Yes - can add static factory methods in Phase 2

---

### D-006: Error Handling: Exceptions vs Postconditions

**Question:** When training fails (e.g., divergence), use exceptions or return error flag?

**Options:**
1. **Postconditions Only (CHOSEN)**: Convergence guaranteed if preconditions met; postcondition states convergence achieved
   - Pros: Eiffel-idiomatic, contracts encode assumptions
   - Cons: Can't distinguish convergence vs timeout gracefully

2. **Exceptions**: Throw on divergence/timeout
   - Pros: Clear failure signal, doesn't hide problems
   - Cons: Not Eiffel idiomatic; complicated error handling

3. **Return Status**: Function returns (is_converged: BOOLEAN, model_ref: MODEL)
   - Pros: Explicit failure
   - Cons: Two-phase protocol, error-prone

**Decision:** **Postconditions + optional status field**

```eiffel
train (X: ARRAY [ARRAY [REAL_64]]; y: ARRAY [REAL_64])
    require
        data_valid: X.count = y.count and X.count > 0
    ensure
        model_trained: is_trained
        convergence_achieved: convergence_loss < tolerance or iterations_completed >= max_iterations
        -- Frame condition: training data unchanged
        original_X_unchanged: X.count = old X.count
    end

feature -- Status (optional)
    is_converged: BOOLEAN
        -- Did training converge within tolerance?
    final_loss: REAL_64
        -- Loss value after training
    iterations_used: INTEGER
        -- Number of iterations actually taken
```

**Rationale:**
- Contracts state conditions; if violated, precondition violation (not error)
- Optional status fields let users check convergence details
- Postcondition guarantees training completed (even if not converged to tolerance)

**Implications:**
- No exceptions for normal ML failure modes (divergence = trained but not converged)
- Users must check `final_loss` and `is_converged` if results matter
- Trains to max_iterations if tolerance not reached (defensive)

**Reversible:** No - core architectural choice

---

### D-007: Model Serialization Format

**Question:** How should users save/load trained models?

**Options:**
1. **Simple Text Format (CHOSEN)**: JSON-like format with coefficients, hyperparameters
   - Pros: Auditable, human-readable, language-agnostic
   - Cons: Precision loss, large files

2. **Binary Format**: Custom binary with IEEE 754 doubles
   - Pros: Compact, preserves precision
   - Cons: Not auditable, endianness issues

3. **No Serialization in MVP**: Defer to Phase 2
   - Pros: Reduces scope
   - Cons: Hard to use trained models in production

**Decision:** **Simple text format (JSON-based) for MVP**

```json
{
  "model_type": "LINEAR_REGRESSION_MODEL",
  "version": "1.0.0",
  "feature_count": 10,
  "coefficients": [0.123, -0.456, ...],
  "intercept": 0.789,
  "training_stats": {
    "mean_loss": 0.0123,
    "final_loss": 0.0098,
    "iterations": 500,
    "converged": true
  }
}
```

**Rationale:**
- Auditable (reviewers can inspect coefficients)
- Simple to implement (no binary serialization complexity)
- Aligns with contract-verification goal (transparent models)
- JSON widely supported

**Implications:**
- Must implement JSON write/read; consider simple_json library
- Precision ~15 decimal places (IEEE 754)
- Phase 2 can add binary format for efficiency

**Reversible:** Yes - can add binary format in Phase 2

---

### D-008: GPU Acceleration Timeline (UPDATED)

**Question:** When should we add GPU support? Users have NVIDIA GPUs (e.g., 5070 Ti 16GB) and need acceleration.

**Options:**
1. **MVP (Phase 1-3): CPU only, Phase 1.5: GPU via C/C++ bindings (CHOSEN)**
   - Pros: MVP verified first (contracts on CPU), then GPU acceleration optional (Phase 1.5)
   - Pros: NVIDIA CUDA/cuBLAS/cuDNN are mature, trusted libraries
   - Pros: Users with GPU hardware can opt-in; CPU-only still works identically
   - Cons: Two code paths to maintain (CPU vs GPU), need testing for equivalence

2. **Phase 1: design GPU-aware from start**
   - Pros: Single code path, unified from start
   - Cons: Complexity in Phase 1 contracts, CUDA/Eiffel interaction untested

3. **Never: stick to CPU**
   - Pros: Simplicity, maintains algorithmic transparency
   - Cons: Performance limits adoption for users with NVIDIA hardware

4. **Phase 2 or later: GPU support**
   - Pros: Defers complexity
   - Cons: Users with GPU hardware frustrated waiting; opportunity cost

**Decision:** **UPDATED: Phase 1-3 MVP (CPU), Phase 1.5 GPU (C/C++ bindings)**

**Rationale:**
- MVP Phase 1-3: CPU implementation first, full Design by Contract verification
- Phase 1.5: Optional GPU acceleration via C/C++ CUDA/cuBLAS/cuDNN bindings
- Timing: After MVP is verified but before Phase 2 scaling work
- Users with NVIDIA 5070 Ti and similar hardware get 5-20x acceleration
- CPU-only path unchanged (no CUDA required to install)
- Contracts verified on Eiffel layer; CUDA is trusted external library
- Simple_* first policy exception: C/C++ GPU libraries allowed as optional backends

**Architecture:**
```
Phase 1-3: Eiffel algorithms + simple_* ecosystem (CPU)
Phase 1.5: Add C/C++ CUDA binding layer (optional GPU)
Phase 2+: Distributed GPU training (multi-GPU, multi-node)
```

**GPU Libraries (Phase 1.5):**
- **cuBLAS**: GPU matrix multiply, transpose, solve (for simple_linalg fallback)
- **cuDNN**: GPU neural network ops (convolution, activation, backprop)
- **CUDA Runtime**: Memory management, kernel dispatch
- **NCCL** (Phase 2): Multi-GPU communication

**Implications:**
- Phase 1 contracts stay on CPU; CUDA code is optimization layer
- Results must match: CPU(Eiffel) ≈ GPU(CUDA) within numerical precision
- Test suite must verify CPU vs GPU equivalence
- Installation: `pip install simple-ml` works without CUDA; CUDA acceleration optional via `pip install simple-ml[gpu]`
- Users choose: `model.compute_device = CPU_DEVICE or GPU_DEVICE`

**Reversible:** Yes - can remove GPU in Phase 2 if performance tests show minimal benefit

---

### D-008b: simple_* First Policy Exception (GPU Libraries)

**Question:** Does C/C++ GPU library exception violate simple_* first policy?

**Decision:** **YES, intentional exception** - C/C++ CUDA/cuBLAS/cuDNN are allowed as optional backends

**Rationale:**
- simple_* first policy is for Eiffel ecosystem libraries
- C/C++ GPU libraries are **trusted external code** (NVIDIA, proven, industry-standard)
- Same pattern as ISE base library (external, trusted, optimized)
- GPU is **optional** (CPU-only path unchanged)
- Eiffel contracts on wrapper layer (verification still present)
- Precedent: scikit-learn uses C/Fortran BLAS; TensorFlow uses C++; PyTorch uses C++ - normal practice

**Updated Constraint:**
- simple_* first policy: Prefer simple_* for algorithms and Eiffel functionality
- **Exception:** C/C++ CUDA/cuBLAS/cuDNN allowed for Phase 1.5+ GPU acceleration as optional, trusted backends

---

### D-009: Hyperparameter Tuning: Grid Search vs Bayesian

**Question:** What hyperparameter optimization method should simple_ml provide?

**Options:**
1. **Grid Search (CHOSEN for MVP)**: Exhaustive search over parameter grid
   - Pros: Simple, deterministic, finds global optimum in grid
   - Cons: Exponential in parameter count; slow for large spaces

2. **Random Search**: Sample random parameters
   - Pros: Better than grid for high dimensions
   - Cons: Non-deterministic, can miss optima

3. **Bayesian Optimization**: Use Gaussian Process to guide search
   - Pros: Sample-efficient, adaptive
   - Cons: Complex to implement, harder to verify contracts

4. **Manual**: Just document guidance for users
   - Pros: Simplest
   - Cons: Less helpful

**Decision:** **Grid Search for MVP, Random Search + Bayesian for Phase 2**

**Rationale:**
- Grid search is simplest to verify and document
- Deterministic = reproducible = matches contract-verification goal
- Feasible for typical enterprise hyperparameter counts (2-3 params)
- Phase 2 can add fancier methods

**Implications:**
- Grid search may be slow for 5+ parameters
- Users document parameter ranges manually
- Phase 2 should add RANDOM_SEARCH and BAYESIAN_OPTIMIZER

**Reversible:** Yes - Phase 2 adds methods without breaking grid search

---

### D-010: Simple_* Ecosystem Dependencies

**Question:** Which simple_* libraries should simple_ml depend on?

**Options:**
1. **Minimal Dependencies**: Only simple_linalg (for matrices)
   - Pros: Low coupling, simple to maintain
   - Cons: Might duplicate functionality

2. **Comprehensive (CHOSEN)**: simple_linalg, simple_optimization, simple_statistics, simple_mml, simple_montecarlo
   - Pros: Reuses verified code, leverages ecosystem strength
   - Cons: More dependencies to manage

3. **No Dependencies**: Reimplement everything
   - Pros: Self-contained
   - Cons: Loses ecosystem benefits, duplicates code

**Decision:** **Comprehensive dependency approach**

| Dependency | Usage | Why |
|------------|-------|-----|
| simple_linalg | Matrix operations, linear transformations | Verified linear algebra |
| simple_optimization | Gradient descent training | Reuse solver from simple_optimization |
| simple_statistics | Distributions, probability | Gaussian for NN initialization |
| simple_mml | MML contracts (MML_SET, MML_SEQUENCE) | Frame conditions on training data |
| simple_montecarlo | Probabilistic methods (future) | Phase 2 ensemble methods |
| simple_random | Random sampling, shuffling | Train-test split, cross-validation |

**Rationale:**
- Eiffel ecosystem is built on composition
- Reusing verified components increases reliability
- Matches simple_* philosophy of modular libraries
- Clear separation of concerns

**Implications:**
- simple_ml is HIGH in dependency graph
- Bug in simple_linalg could affect simple_ml (need to test integration)
- Phase 5 includes integration tests with dependencies

**Reversible:** Partially - can add/remove dependencies in Phase 2

---

## Summary of Key Decisions

| Decision | Chosen | Key Implication |
|----------|--------|-----------------|
| D-001 | Native Build | Full Design by Contract, Eiffel-idiomatic |
| D-002 | 6 core algorithms (MVP) | Manageable scope for verification |
| D-003 | Unified Gradient Descent | Scalable from linear to neural networks |
| D-004 | Deterministic Contracts | Verify structure; test quality separately |
| D-005 | Builder Pattern | Fluent configuration, modern Eiffel style |
| D-006 | Postconditions + status fields | Eiffel-idiomatic error handling |
| D-007 | JSON serialization | Auditable, transparent models |
| D-008 | CPU-only MVP | Focus on verification; Phase 2 evaluates GPU |
| D-009 | Grid Search | Simple, deterministic, reproducible |
| D-010 | Comprehensive simple_* deps | Leverage ecosystem strength |

These decisions establish the foundation for Phases 1-3. Phases 4-7 will implement and verify.
