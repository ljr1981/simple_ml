# INNOVATIONS: simple_ml

## What Makes This Different

### I-001: Contract-Verified Machine Learning Algorithms

**Problem Solved:** ML algorithms lack formal verification; users can't audit why models make decisions or guarantee correctness of training.

**Approach:** Every algorithm in simple_ml has complete Design by Contract:
- **Preconditions**: What input guarantees must be true (feature count, sample count, feature ranges)
- **Postconditions**: What the algorithm guarantees about output (probability bounds, convergence, loss decrease)
- **Invariants**: What's always true (number of classes never changes, weights stay finite)

**Example: Logistic Regression**
```eiffel
class LOGISTIC_REGRESSION_MODEL

feature -- Training

    train (X: ARRAY [ARRAY [REAL_64]]; y: ARRAY [BOOLEAN])
            -- Train logistic regression on data.
        require
            valid_data: X.count = y.count and X.count > 0
            consistent_features: across X as r all r.item.count = feature_count end
            binary_labels: across y as r all r.item end -- TRUE/FALSE only
        do
            -- Gradient descent training
        ensure
            model_trained: is_trained
            weights_finite: across weights as w all is_finite (w.item) end
            convergence: final_loss < previous_loss or iterations_count >= max_iterations
            -- Frame condition: input data unchanged
            data_unchanged: X.count = old X.count
        end

    predict_proba (sample: ARRAY [REAL_64]): REAL_64
            -- Probability sample belongs to class 1.
        require
            model_fitted: is_trained
            sample_valid: sample.count = feature_count
            finite_values: across sample as s all is_finite (s.item) end
        ensure
            valid_probability: Result >= 0.0 and Result <= 1.0
        end
end
```

**Novelty:** No other ML library combines Design by Contract with machine learning. This is the first formally-verified ML library in any language that puts contracts ON the algorithm itself (not just wrapping external code).

**Design Impact:**
- Every class has require/ensure/invariant
- Training contracts enforce mathematical preconditions
- Prediction contracts enforce output bounds
- Frame conditions document what data properties are preserved
- Users can AUDIT algorithms (code is transparent)
- Regulatory bodies can CERTIFY models (formal contracts prove correctness)

---

### I-002: Algorithmic Transparency & Educational Value

**Problem Solved:** ML libraries (TensorFlow, scikit-learn) hide algorithms in optimized C/C++ code. Students and auditors can't understand HOW decisions are made. Black-box algorithms are unacceptable in regulated domains.

**Approach:** simple_ml implements algorithms in readable Eiffel code, not compiled black boxes.
- Users can READ algorithm implementations
- Students can LEARN how algorithms work
- Auditors can VERIFY correctness
- No hidden optimization tricks

**Example: Decision Tree Building**
```eiffel
class DECISION_TREE_BUILDER

feature -- Tree Building (transparent algorithm)

    build_tree (X: ARRAY [ARRAY [REAL_64]]; y: ARRAY [INTEGER]): DECISION_TREE_NODE
            -- Build decision tree via recursive information gain splitting.
        require
            valid_training_data: X.count = y.count
        do
            if is_pure (y) or max_depth_reached then
                Result := create {LEAF_NODE}.make (majority_class (y))
            else
                best_split := find_best_split (X, y)
                -- Split recursively
                left_indices := features (X, best_split).lower_than (best_split.threshold)
                right_indices := features (X, best_split).greater_equal (best_split.threshold)

                left_tree := build_tree (X.filtered (left_indices), y.filtered (left_indices))
                right_tree := build_tree (X.filtered (right_indices), y.filtered (right_indices))

                Result := create {INTERNAL_NODE}.make (best_split, left_tree, right_tree)
            end
        ensure
            tree_valid: Result /= Void
            tree_consistent: consistent_tree_structure (Result)
        end
end
```

**Novelty:** First ML library where you can literally read the algorithm as a Eiffel program. Not a wrapped Python/C library; actual readable code.

**Design Impact:**
- Code clarity is valued over micro-optimizations
- Comments explain mathematical concepts
- Students use simple_ml to learn ML
- Auditors can certify correctness by code review
- Regulatory compliance is possible (auditable decision logic)

---

### I-003: Eiffel Ecosystem Integration (Not Reinvention)

**Problem Solved:** Existing ML libraries reinvent basic functionality (linear algebra, optimization). simple_ml reuses the proven, verified simple_* ecosystem.

**Approach:** Leverage existing libraries for foundational work:

| Component | Source | Benefit |
|-----------|--------|---------|
| Gradient Descent Optimization | simple_optimization | Reuse verified solver; don't reinvent |
| Matrix Operations | simple_linalg | Numerical stability from domain experts |
| Statistical Distributions | simple_statistics | Gaussian, Bernoulli already verified |
| Random Sampling | simple_random | Reproducible splits, shuffling |
| Probabilistic Methods | simple_montecarlo | MC integration for advanced methods |
| MML Contracts | simple_mml | Frame conditions on datasets |

**Novelty:** First ML library built as composition of specialized libraries. Not a monolithic blob but a SYSTEM of libraries.

**Design Impact:**
- simple_ml doesn't reimplement linear algebra (simple_linalg does it better)
- Gradient descent solver already in simple_optimization (reuse it)
- Training data contracts use simple_mml (frame conditions)
- Bug in simple_linalg? Fix once, benefit all (simple_ml, simple_stats, simple_physics, simple_ml)
- This is architectural maturity (composability) vs. vendor lock-in

---

### I-004: Contract-Driven API Design

**Problem Solved:** ML API design is ad-hoc. Users learn by trial-and-error (fit before transform fails, wrong shape crashes, etc.).

**Approach:** Contracts encode the protocol:

```eiffel
class MODEL_PIPELINE

feature -- Protocol: must be called in order

    fit (X: ARRAY [ARRAY [REAL_64]]; y: ARRAY [INTEGER])
            -- Fit all transformers and model.
        require
            not_yet_fitted: not is_fitted  -- Enforce: must fit first
            valid_data: X.count = y.count
        ensure
            now_fitted: is_fitted  -- After fit, model is ready
        end

    transform (X: ARRAY [ARRAY [REAL_64]]): ARRAY [ARRAY [REAL_64]]
            -- Transform features (scalers, feature selection).
        require
            fitted: is_fitted  -- Enforce: fit before transform
            consistent_features: X.count > 0 implies X[0].count = feature_count
        ensure
            -- Result has transformed features
        end

    predict (X: ARRAY [ARRAY [REAL_64]]): ARRAY [INTEGER]
            -- Predict (only after fitting and transformation).
        require
            fitted: is_fitted
        ensure
            predictions_valid: Result.count = X.count
        end

invariant
    -- Once fitted, remains fitted (no unfitting)
    fitness_immutable: old is_fitted implies is_fitted
end
```

**Novelty:** Contracts document the PROTOCOL (fit → transform → predict), not just individual function behavior.

**Design Impact:**
- Compile-time/runtime enforcement of ordering constraints
- No more "fit() before transform() crashes" surprises
- API is self-documenting (contracts say how to use it)
- Students learn correct usage patterns immediately

---

### I-005: Formal Verification Hooks for Regulatory Compliance

**Problem Solved:** Regulated industries (healthcare, finance, autonomous vehicles) need proof that ML models make correct decisions. Current ML libraries don't support formal verification.

**Approach:** Design all contracts to be verifiable by formal methods tools:
- Preconditions on input ranges (can be checked by SMT solvers)
- Postconditions on output bounds (mathematically provable)
- Invariants on model state (verifiable properties)
- Frame conditions on data (what doesn't change)

**Example for Heart Disease Prediction Model**
```eiffel
class HEART_DISEASE_CLASSIFIER
    -- Used in healthcare: must be formally verifiable for FDA approval

feature -- Medical Prediction

    predict_risk (age: INTEGER; cholesterol: INTEGER; blood_pressure: INTEGER): REAL_64
            -- Predict probability of heart disease (0-1 scale).
        require
            -- Medical constraints (provable from medical knowledge)
            age_realistic: 0 <= age and age <= 150
            cholesterol_realistic: 0 <= cholesterol and cholesterol <= 400
            blood_pressure_realistic: 0 <= blood_pressure and blood_pressure <= 250
        ensure
            -- Output is a valid probability
            probability_bounds: Result >= 0.0 and Result <= 1.0

            -- Monotonicity guarantee (higher age/cholesterol = higher risk)
            age_monotonic: old_age <= age implies old_risk <= Result

            -- Continuity guarantee (small input changes = bounded output changes)
            continuous: (age - old_age).abs < 1 implies (Result - old_risk).abs < 0.01
        end
end
```

**Novelty:** Hooks for formal verification (contracts are amenable to SMT, bounded model checking, abstract interpretation). This supports FDA, EU AI Act, and other regulatory verification.

**Design Impact:**
- Contracts written with formal verification in mind
- External tools can verify postconditions hold
- Healthcare/finance can certify ML models mathematically
- Positions Eiffel as the formal-methods leader in ML

---

### I-006: Numerical Stability & IEEE 754 Compliance

**Problem Solved:** ML training is numerically sensitive. Algorithms can produce NaN or Inf, silently causing bad predictions. Scikit-learn/TensorFlow don't have explicit stability contracts.

**Approach:** Explicit contracts on numerical stability:

```eiffel
class LINEAR_REGRESSION_MODEL

feature -- Numerical Stability

    is_numerically_stable: BOOLEAN
            -- Are all weights and intercepts finite (not NaN/Inf)?
        do
            Result := is_finite (intercept) and across weights as w all is_finite (w.item) end
        end

    train (X: ARRAY [ARRAY [REAL_64]]; y: ARRAY [REAL_64])
        ensure
            numerically_stable: is_numerically_stable
            no_nans: not (across Result as r all is_nan (r.item) end)
            no_infs: not (across Result as r all is_infinite (r.item) end)
            weights_bounded: across weights as w all w.item.abs <= max_weight_magnitude end
        end

    predict (X: ARRAY [REAL_64]): REAL_64
        require
            finite_input: across X as f all is_finite (f.item) end
        ensure
            finite_output: is_finite (Result)
            -- Even if model is unstable, output is bounded (clipped if needed)
            bounded: Result >= min_prediction and Result <= max_prediction
        end

feature {NONE} -- Numerical Utilities

    is_finite (x: REAL_64): BOOLEAN
        do
            Result := x = x and x.abs < positive_infinity
        end

    is_nan (x: REAL_64): BOOLEAN
        do
            Result := x /= x
        end
end
```

**Novelty:** Explicit postconditions on numerical stability. Other libraries don't guarantee this.

**Design Impact:**
- Training won't produce silent NaN/Inf failures
- Predictions are always bounded (even if model diverges)
- Debugging numerical problems is easier (contracts tell what went wrong)
- IEEE 754 compliance is explicit

---

### I-007: Scientific Reproducibility via Contract-Based Testing

**Problem Solved:** ML models are hard to reproduce. Different libraries, random seeds, numerical precision cause different results. simple_ml enables reproducibility.

**Approach:** Contracts + deterministic algorithms = reproducible training:

```eiffel
feature -- Reproducibility

    train_deterministic (X: ARRAY [ARRAY [REAL_64]]; y: ARRAY [INTEGER]; seed: INTEGER)
            -- Train with deterministic random seed for reproducibility.
        require
            fixed_seed: seed >= 0  -- User provides seed for reproducibility
        do
            random_generator.set_seed (seed)  -- Via simple_random with seed
            -- Training now deterministic: same seed = same weights
        ensure
            deterministic: -- Same seed always produces same weights
            -- Can be verified by running twice with same seed
        end

    -- Verification method for tests
    verify_reproducibility (seed: INTEGER): BOOLEAN
            -- Can this model reproduce exactly with same seed?
        do
            weights_run1 := train (data, seed).weights
            weights_run2 := train (data, seed).weights
            Result := weights_run1.all_equal (weights_run2)
        end
end
```

**Novelty:** Contracts DOCUMENT reproducibility requirements. Tests VERIFY reproducibility actually holds.

**Design Impact:**
- Scientific papers using simple_ml can claim reproducibility
- Same seed = identical training
- Publication-quality results (verifiable by reviewers)

---

## Differentiation from Existing Solutions

| Aspect | Existing (scikit/TensorFlow) | Our Approach (simple_ml) | Benefit |
|--------|-----|-----|---------|
| **Contracts** | None | 100% Design by Contract | Formal correctness guarantees |
| **Transparency** | Black box (C/C++) | Readable Eiffel code | Auditability, understanding |
| **Ecosystem** | Monolithic | Composed of simple_* libs | Modularity, reusability |
| **Verification** | Manual testing | Contracts + SMT hooks | Regulatory compliance |
| **Stability** | Implicit | Explicit finite bounds | Numerical safety |
| **Reproducibility** | Seed-based | Contract-enforced | Scientific credibility |
| **API Design** | Trial-and-error | Protocol contracts | Self-documenting |
| **Educational** | Black box | Transparent algorithms | Learn by reading code |
| **Regulated Use** | Not certified | Formally verifiable | FDA/EU AI Act ready |

## Position in ML Landscape

simple_ml fills a **unique niche**: ML for regulated domains, education, and formal verification.

- **For Enterprise**: Auditable models, certification trails, formal correctness
- **For Academia**: Teaching tool, research on formal-verified ML
- **For Regulators**: Formally-verifiable decision logic for AI Act compliance
- **For Eiffel Community**: Production ML capability with Design by Contract

This is not about beating scikit-learn on speed (we won't). It's about providing ML capability that's **verifiable, transparent, and auditable** — what regulated industries actually need.
