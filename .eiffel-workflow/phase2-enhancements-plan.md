# Phase 2 Feature Enhancements Plan

**Project:** simple_ml
**Current Version:** v1.0.0 (6 algorithms, 80 tests, production-ready)
**Enhancement Scope:** v1.1.0+ (planned expansions)
**Date:** 2026-01-30

---

## Overview

Based on Phase 2 adversarial review insights and identified gaps, simple_ml v1.1.0+ should add:

1. **Advanced Kernel Methods** - RBF and polynomial kernels for SVM
2. **Regularization Framework** - L1/L2 regularization for linear models
3. **Model Selection Tools** - Cross-validation and hyperparameter tuning
4. **Additional Algorithms** - KNN, Naive Bayes, Gradient Boosting

---

## Enhancement 1: Advanced Kernel Methods for SVM

### Current State (v1.0.0)
- ✅ SVM_LINEAR with linear kernel only
- ✅ Decision function working correctly
- ✅ Regularization via C parameter

### Enhancement: SVM_RBF and SVM_POLYNOMIAL

#### New Classes

**SVM_RBF**
```eiffel
class SVM_RBF
-- Support Vector Machine with RBF (Radial Basis Function) kernel

feature -- Configuration
  set_gamma (a_gamma: REAL_64): like Current
    -- RBF kernel parameter (inverse of feature variance)
    require
      positive_gamma: a_gamma > 0.0
    ensure
      gamma_set: gamma = a_gamma
    end

  set_c_param (a_c: REAL_64): like Current
    -- Regularization parameter
    require
      positive_c: a_c > 0.0
    ensure
      c_set: c_param = a_c
    end

feature -- Core Operations
  train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
    -- Train RBF-kernel SVM using kernel trick
    require
      x_valid: a_X /= Void and a_X.count > 0
      y_valid: a_y /= Void and a_y.count = a_X.count
      dimension_consistency: across a_X as row all
        row.item /= Void and row.item.count = feature_dim
      end
    do
      -- Train using kernel trick: K(x,y) = exp(-gamma * ||x-y||²)
      -- Store support vectors and their coefficients
    ensure
      is_trained: is_trained
      support_vectors_initialized: support_vectors.count > 0
      decision_function_valid: across test_data as x all
        decision_function(x.item).is_finite
      end
    end

  predict (a_x: ARRAY [REAL_64]): INTEGER
    require
      trained: is_trained
      correct_dimensions: a_x.count = feature_dim
    do
      -- Compute kernel trick decision: sum of (alpha_i * y_i * K(x, x_i)) + bias
    ensure
      result_valid: classes_learned.has (Result)
    end

feature -- Kernel Operations
  rbf_kernel (a_x1, a_x2: ARRAY [REAL_64]): REAL_64
    -- Compute RBF kernel: exp(-gamma * ||x1-x2||²)
    require
      same_dimension: a_x1.count = a_x2.count
    ensure
      result_in_range: Result >= 0.0 and Result <= 1.0
    end

feature {NONE} -- Implementation
  support_vectors: ARRAY [ARRAY [REAL_64]]
  support_vector_coefficients: ARRAY [REAL_64]
  gamma: REAL_64 := 0.01
end
```

**SVM_POLYNOMIAL**
```eiffel
class SVM_POLYNOMIAL
-- Support Vector Machine with polynomial kernel

feature -- Configuration
  set_degree (a_degree: INTEGER): like Current
    require
      positive_degree: a_degree > 0
    ensure
      degree_set: degree = a_degree
    end

  set_coef0 (a_coef: REAL_64): like Current
    require
      non_negative_coef: a_coef >= 0.0
    ensure
      coef_set: coef0 = a_coef
    end

feature -- Core Operations
  polynomial_kernel (a_x1, a_x2: ARRAY [REAL_64]): REAL_64
    -- Compute polynomial kernel: (gamma * x1·x2 + coef0)^degree
    require
      same_dimension: a_x1.count = a_x2.count
    ensure
      result_finite: Result.is_finite
    end

feature {NONE} -- Implementation
  degree: INTEGER := 3
  coef0: REAL_64 := 1.0
end
```

#### Design Decisions
1. **Kernel Trick:** Use kernel matrices instead of explicit feature transformation
2. **Support Vectors:** Store only necessary vectors for prediction
3. **Decision Bounds:** RBF kernels naturally bounded in (0, 1)
4. **Contract Additions:** Explicit kernel value ranges in postconditions

#### Testing Strategy
- ✅ Kernel computation correctness
- ✅ Support vector selection
- ✅ Decision function bounds (RBF naturally [0,1])
- ✅ Comparison with SVM_LINEAR on linear data
- ✅ Stress test: high-dimensional RBF

#### Dependencies
- simple_linalg: Kernel matrix computation
- simple_statistics: Numerical stability in exponentials

---

## Enhancement 2: Regularization Framework

### Current State (v1.0.0)
- ✅ SVM_LINEAR has C parameter (implicit L2)
- ❌ No explicit L1/L2 for linear models
- ❌ No regularization for logistic regression

### Enhancement: Regularized Linear & Logistic Regression

#### New Classes/Features

**LINEAR_REGRESSION_REGULARIZED**
```eiffel
class LINEAR_REGRESSION_REGULARIZED
-- Linear regression with L1 (Lasso) and L2 (Ridge) regularization

feature -- Configuration
  set_regularization (a_type: STRING; a_lambda: REAL_64): like Current
    -- Set regularization type and strength
    require
      valid_type: a_type.is_equal("l1") or a_type.is_equal("l2") or a_type.is_equal("elastic_net")
      positive_lambda: a_lambda >= 0.0  -- 0 = no regularization
    ensure
      regularization_set: regularization_type.is_equal(a_type)
      lambda_set: lambda = a_lambda
    end

  set_l1_ratio (a_ratio: REAL_64): like Current
    -- Elastic net: balance between L1 and L2
    require
      valid_ratio: a_ratio >= 0.0 and a_ratio <= 1.0
    ensure
      ratio_set: l1_ratio = a_ratio
    end

feature -- Training
  train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [REAL_64])
    -- Train with regularization term in loss function
    require
      ... -- same as LINEAR_REGRESSION_MODEL
    do
      -- Loss = MSE + lambda * penalty(weights)
      -- penalty(L1) = sum(|w|)
      -- penalty(L2) = sum(w²)
      -- penalty(ElasticNet) = l1_ratio * sum(|w|) + (1-l1_ratio) * sum(w²)
    ensure
      ... -- same as LINEAR_REGRESSION_MODEL
      regularization_effect: (
        lambda > 0 implies
        weights_magnitude <= weights_magnitude_without_regularization
      )
    end

feature {NONE} -- Implementation
  regularization_type: STRING := "l2"  -- "l1", "l2", "elastic_net"
  lambda: REAL_64 := 0.01
  l1_ratio: REAL_64 := 0.5  -- For elastic net
end
```

**LOGISTIC_REGRESSION_REGULARIZED**
```eiffel
class LOGISTIC_REGRESSION_REGULARIZED
-- Logistic regression with regularization

feature -- Configuration
  set_regularization (a_lambda: REAL_64): like Current
    require
      non_negative_lambda: a_lambda >= 0.0
    ensure
      lambda_set: lambda = a_lambda
    end

feature -- Training
  train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
    -- Log loss + lambda * L2 penalty on weights
    do
      -- Loss = -sum(y*log(p) + (1-y)*log(1-p)) + lambda * sum(w²)
    ensure
      ...
      regularization_prevents_overfitting: (
        lambda > 0 implies
        weights_magnitude < weights_magnitude_unregularized
      )
    end

feature {NONE} -- Implementation
  lambda: REAL_64 := 0.01
end
```

#### Design Decisions
1. **Loss Function:** Add regularization term to training objective
2. **Elastic Net:** Support L1 + L2 combination
3. **Lambda Parameter:** Controls regularization strength (0 = none)
4. **Contract Impact:** Postconditions show regularization prevents overfitting

#### Testing Strategy
- ✅ L1 sparsity: Some weights should be exactly zero
- ✅ L2 smoothing: Weights should be smaller with regularization
- ✅ Elastic net: Balance between sparsity and smoothing
- ✅ Cross-comparison: Same data with different lambda values
- ✅ Boundary test: lambda = 0 should match unregularized version

#### Dependencies
- simple_linalg: L-norm calculations
- simple_statistics: Loss function computation

---

## Enhancement 3: Model Selection Tools

### Current State (v1.0.0)
- ❌ No cross-validation support
- ❌ No grid search or random search
- ❌ Manual train/test split required

### Enhancement: Cross-Validation Framework

#### New Classes

**K_FOLD_SPLITTER**
```eiffel
class K_FOLD_SPLITTER
-- K-fold cross-validation data splitting

feature -- Configuration
  set_k (a_k: INTEGER): like Current
    require
      valid_k: a_k >= 2 and a_k <= dataset_size / 2
    ensure
      k_set: k = a_k
    end

feature -- Splitting
  split (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
    -- Generate k train/test splits
    require
      consistent_size: a_X.count = a_y.count
    do
      -- Create k folds, each fold gets different test set
    ensure
      fold_count: folds.count = k
      across folds as f all
        f.item.training_size + f.item.test_size = a_X.count
      end
    end

feature -- Access
  get_fold (a_index: INTEGER): FOLD
    require
      valid_index: a_index >= 1 and a_index <= k
    ensure
      result_valid: Result.training_size > 0 and Result.test_size > 0
    end

feature {NONE} -- Implementation
  k: INTEGER := 5
  folds: ARRAY [FOLD]
end

class FOLD
-- Single fold from k-fold split
feature
  training_X: ARRAY [ARRAY [REAL_64]]
  training_y: ARRAY [INTEGER]
  test_X: ARRAY [ARRAY [REAL_64]]
  test_y: ARRAY [INTEGER]

  training_size: INTEGER do Result := training_X.count end
  test_size: INTEGER do Result := test_X.count end
end
```

**GRID_SEARCH_CV**
```eiffel
class GRID_SEARCH_CV
-- Hyperparameter grid search with cross-validation

feature -- Configuration
  set_param_grid (a_grid: HASH_TABLE [ARRAY [REAL_64], STRING]): like Current
    -- Set parameters to search
    require
      grid_not_empty: a_grid.count > 0
    ensure
      grid_set: param_grid = a_grid
    end

  set_cv_folds (a_k: INTEGER): like Current
    require
      valid_k: a_k >= 2
    ensure
      cv_set: cv_folds = a_k
    end

feature -- Execution
  search (a_model_class: TYPE; a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
    -- Exhaustive grid search over parameters
    require
      valid_data: a_X.count = a_y.count and a_X.count > a_k * 2
    do
      -- For each parameter combination:
      --   For each CV fold:
      --     Train on fold, evaluate on holdout
      --   Average scores across folds
      -- Rank combinations by score
    ensure
      results_available: results.count = total_combinations
      best_params_identified: best_params /= Void
      best_score_computed: best_score >= 0.0 and best_score <= 1.0
    end

feature -- Results
  best_params: HASH_TABLE [REAL_64, STRING]
    -- Best hyperparameters found
  best_score: REAL_64
    -- Cross-validation score of best model
  get_results: ARRAY [TUPLE [params: HASH_TABLE [REAL_64, STRING]; score: REAL_64]]
    -- All results, ranked by score
end
```

#### Design Decisions
1. **K-Fold:** Non-overlapping folds, each sample used once per fold
2. **Stratified Option:** For classification, maintain class distribution
3. **Grid Search:** Exhaustive search over parameter combinations
4. **Scoring:** F1 for classification, R² for regression
5. **Contract:** Result validity guaranteed by cross-validation structure

#### Testing Strategy
- ✅ Fold creation: Each sample appears exactly once as test
- ✅ Grid search: All combinations evaluated
- ✅ Best params: Return parameters with highest score
- ✅ Reproducibility: Same seed → same splits
- ✅ Edge case: Single-parameter search

#### Dependencies
- simple_randomizer: Random shuffling for fold creation
- simple_statistics: Scoring metrics (accuracy, F1, R²)

---

## Enhancement 4: Additional Algorithms

### New Algorithms to Implement (v1.1.0+)

#### 4A: K-Nearest Neighbors (KNN)

**KNN_CLASSIFIER**
```eiffel
class KNN_CLASSIFIER
-- K-nearest neighbors classification

feature -- Configuration
  set_k (a_k: INTEGER): like Current
    require
      positive_k: a_k > 0
      k_less_than_samples: a_k < training_size
    ensure
      k_set: k = a_k
    end

  set_metric (a_metric: STRING): like Current
    require
      valid_metric: a_metric.is_equal("euclidean") or
                    a_metric.is_equal("manhattan") or
                    a_metric.is_equal("cosine")
    ensure
      metric_set: metric = a_metric
    end

feature -- Training
  train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
    -- Store training data (lazy learning)
    require
      ...
    ensure
      is_trained: is_trained
      data_stored: training_X.count = a_X.count
    end

feature -- Prediction
  predict (a_x: ARRAY [REAL_64]): INTEGER
    -- Find k nearest neighbors, majority vote
    require
      trained: is_trained
      correct_dimensions: a_x.count = feature_dim
    ensure
      result_valid: classes_learned.has (Result)
    end

  predict_proba (a_x: ARRAY [REAL_64]): ARRAY [REAL_64]
    -- Class probabilities based on k nearest neighbors
    ensure
      sums_to_one: sum_of_probabilities ≈ 1.0
    end

feature {NONE} -- Implementation
  k: INTEGER := 3
  metric: STRING := "euclidean"
  training_X: ARRAY [ARRAY [REAL_64]]
  training_y: ARRAY [INTEGER]

  distance (a_x1, a_x2: ARRAY [REAL_64]): REAL_64
    -- Compute distance based on metric
  end
end
```

#### 4B: Naive Bayes

**NAIVE_BAYES_CLASSIFIER**
```eiffel
class NAIVE_BAYES_CLASSIFIER
-- Naive Bayes probabilistic classifier

feature -- Training
  train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
    -- Learn class priors and feature distributions
    require
      ...
    ensure
      is_trained: is_trained
      priors_learned: class_priors.count = classes_learned.count
      feature_distributions_initialized: feature_means.count > 0
    end

feature -- Prediction
  predict (a_x: ARRAY [REAL_64]): INTEGER
    -- Compute P(class|features) using Bayes rule
    require
      trained: is_trained
      correct_dimensions: a_x.count = feature_dim
    ensure
      result_valid: classes_learned.has (Result)
    end

  predict_proba (a_x: ARRAY [REAL_64]): ARRAY [REAL_64]
    -- Probability distribution over classes
    ensure
      valid_distribution: (
        Result.count = classes_learned.count and
        sums_to_one
      )
    end

feature {NONE} -- Implementation
  class_priors: ARRAY [REAL_64]      -- P(class)
  feature_means: ARRAY [ARRAY [REAL_64]]      -- μ per class per feature
  feature_variances: ARRAY [ARRAY [REAL_64]]  -- σ² per class per feature
end
```

#### 4C: Gradient Boosting Classifier

**GRADIENT_BOOSTING_CLASSIFIER**
```eiffel
class GRADIENT_BOOSTING_CLASSIFIER
-- Ensemble method building sequential classifiers

feature -- Configuration
  set_n_estimators (a_n: INTEGER): like Current
    require
      positive_n: a_n > 0
    ensure
      n_set: n_estimators = a_n
    end

  set_learning_rate (a_rate: REAL_64): like Current
    require
      positive_rate: a_rate > 0.0 and a_rate <= 1.0
    ensure
      rate_set: learning_rate = a_rate
    end

  set_max_depth (a_depth: INTEGER): like Current
    require
      positive_depth: a_depth > 0
    ensure
      depth_set: max_depth = a_depth
    end

feature -- Training
  train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
    -- Train sequence of classifiers, each on residuals
    require
      ...
    do
      -- 1. Initialize with constant prediction (class prior)
      -- 2. For each iteration:
      --    a. Compute pseudo-residuals (y - prediction)
      --    b. Fit weak learner (decision tree) to residuals
      --    c. Update predictions: pred += learning_rate * tree_pred
    ensure
      is_trained: is_trained
      estimators_trained: weak_learners.count = n_estimators
    end

feature -- Prediction
  predict (a_x: ARRAY [REAL_64]): INTEGER
    -- Sum predictions from all weak learners
    require
      trained: is_trained
      correct_dimensions: a_x.count = feature_dim
    ensure
      result_valid: classes_learned.has (Result)
    end

feature {NONE} -- Implementation
  n_estimators: INTEGER := 100
  learning_rate: REAL_64 := 0.1
  max_depth: INTEGER := 3
  weak_learners: ARRAY [DECISION_TREE_CLASSIFIER]
end
```

#### Design Decisions for All New Algorithms
1. **Consistent API:** All follow same pattern as existing algorithms
2. **Contract Completeness:** Full pre/post/invariants
3. **MML Queries:** Model state verification
4. **Testing:** Functional + adversarial tests
5. **Dependencies:** Use simple_* ecosystem

#### Testing for New Algorithms
- ✅ Correctness vs reference implementations
- ✅ Edge cases: empty classes, high dimensions
- ✅ Numerical stability
- ✅ Contract satisfaction
- ✅ Comparison with SVM/tree methods

#### Dependencies
- simple_linalg: Distance computations (KNN)
- simple_statistics: Probability distributions (Naive Bayes, Boosting)
- simple_randomizer: Bootstrap sampling (if needed)
- simple_mml: Contract specification

---

## Implementation Roadmap

### Phase Timeline (Estimated)

| Phase | Deliverable | Timeline | Description |
|-------|-------------|----------|-------------|
| 1.0.0 | Current Version | ✅ Complete | 6 algorithms, 80 tests |
| 1.1.0 | Kernel Methods | Q2 2026 | SVM_RBF, SVM_POLYNOMIAL |
| 1.2.0 | Regularization | Q3 2026 | L1/L2 for linear models |
| 1.3.0 | Model Selection | Q3 2026 | K-Fold, Grid Search |
| 1.4.0 | New Algorithms | Q4 2026 | KNN, Naive Bayes, Gradient Boosting |

### Total Enhancement Scope
- **New Classes:** 9 (2 SVM + 2 Regularized + 3 Selection + 3 Algorithms)
- **Estimated Tests:** 60+ new tests
- **Documentation:** 6 new cookbook recipes
- **Target Release:** v2.0.0 (complete ML library)

---

## Quality Gates for Enhancements

All enhancements must meet:

### Code Quality
- ✅ Zero compilation warnings
- ✅ All contracts verified
- ✅ Full test coverage
- ✅ Design by Contract enforced

### Testing
- ✅ Functional tests for each new class
- ✅ Adversarial tests for edge cases
- ✅ Integration tests with existing algorithms
- ✅ 100% test pass rate

### Documentation
- ✅ API documentation
- ✅ User guide section
- ✅ Cookbook recipe
- ✅ Architecture documentation

### Performance
- ✅ No regression in existing algorithms
- ✅ Reasonable training time
- ✅ Memory efficiency

---

## Getting Started

### Priority Order for Implementation
1. **Regularization** (easiest - extends existing classes)
2. **Kernel Methods** (extends SVM_LINEAR)
3. **Model Selection** (independent utilities)
4. **New Algorithms** (most complex)

### Recommended Team
- 1 lead engineer (overall architecture)
- 2 implementation engineers (algorithms)
- 1 test engineer (adversarial testing)
- 1 documentation engineer (user guide)

---

## Conclusion

These enhancements will transform simple_ml from a foundation library (6 essential algorithms) into a comprehensive ML toolkit (9 new features, 3 new algorithms). All enhancements maintain the Design by Contract promise and production quality standards set by v1.0.0.

**Target:** v2.0.0 (2026-Q4) - Complete, professional-grade machine learning library for Eiffel.

