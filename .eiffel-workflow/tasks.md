# Phase 3: Enhancement Task Decomposition

**Project:** simple_ml v1.1.0+ Enhancements  
**Date:** 2026-01-30  
**Status:** Tasks Decomposed and Ready for Implementation

---

## ENHANCEMENT 1: REGULARIZATION (Tasks 1.1-1.3)

### Task 1.1: LINEAR_REGRESSION_REGULARIZED - Configuration
- Implement: make, set_learning_rate, set_max_iterations, set_regularization, set_l1_ratio
- Acceptance: Model initializes unconfigured, all setters return `like Current` 
- Dependencies: None

### Task 1.2: LINEAR_REGRESSION_REGULARIZED - Training
- Implement: train (gradient descent + regularization loss), predict, weights_magnitude_unregularized
- Loss = MSE + lambda * regularization_penalty (L1, L2, or ElasticNet)
- Acceptance: Weights updated, regularization reduces magnitude when lambda > 0
- Dependencies: Task 1.1

### Task 1.3: LOGISTIC_REGRESSION_REGULARIZED - Multiclass Classification  
- Implement: make, configuration methods, train (cross-entropy + L2), predict, predict_proba
- Probability = softmax(X @ W + b), Loss = cross_entropy + lambda * L2_penalty
- Acceptance: Multiclass predictions work, probabilities sum to 1.0
- Dependencies: None (parallel to 1.1-1.2)

---

## ENHANCEMENT 2: MODEL SELECTION (Tasks 2.1-2.3)

### Task 2.1: FOLD - Data Holder
- Implement: make, training_X/Y, test_X/Y, training_size, test_size
- Acceptance: Immutable, dimensions validated
- Dependencies: None

### Task 2.2: K_FOLD_SPLITTER - Cross-Validation Splitter
- Implement: make, set_k, set_random_seed, split(a_X, a_y), get_fold, split_count
- Algorithm: Shuffle, divide into k parts, create FOLD for each (test=part_i, train=others)
- Acceptance: Each sample used exactly once per fold, reproducible with same seed
- Dependencies: Task 2.1

### Task 2.3: GRID_SEARCH_CV - Hyperparameter Optimization
- Implement: make, set_estimator, set_param_grid, fit(a_X, a_y), best_params, best_score, best_estimator
- Algorithm: For each param combo → train on train folds → score on test fold → record mean
- Acceptance: All combinations tried, best params selected, best estimator trained
- Dependencies: Task 2.2 (uses K_FOLD_SPLITTER)

---

## ENHANCEMENT 3: KERNEL METHODS (Tasks 3.1-3.2)

### Task 3.1: SVM_RBF - Radial Basis Function Kernel
- Implement: make, set_gamma, set_c_param, train, predict, decision_function, rbf_kernel
- Kernel = exp(-gamma * ||x-y||²), Decision = sum(alpha_i * y_i * K(x,x_i)) + bias
- Acceptance: Kernel values in [0,1], predictions valid, decision function finite
- Dependencies: None

### Task 3.2: SVM_POLYNOMIAL - Polynomial Kernel  
- Implement: make, set_gamma, set_degree, set_coef0, train, predict, decision_function, polynomial_kernel
- Kernel = (gamma * x·y + coef0)^degree
- Acceptance: Kernel computed correctly, decision function finite
- Dependencies: None (parallel to 3.1)

---

## ENHANCEMENT 4: NEW ALGORITHMS (Tasks 4.1-4.3)

### Task 4.1: KNN_CLASSIFIER - k-Nearest Neighbors
- Implement: make, set_k, set_distance_metric, train (lazy: store data), predict, predict_proba, distance
- Metrics: Euclidean, Manhattan, Cosine
- Acceptance: k neighbors found, majority vote works, probabilities sum to 1.0
- Dependencies: None

### Task 4.2: NAIVE_BAYES_CLASSIFIER - Gaussian Probabilistic Classifier
- Implement: make, train (class priors + feature distributions), predict, predict_proba, gaussian_pdf
- Algorithm: P(class|x) ∝ P(class) * ∏ gaussian_pdf(x_i | class)
- Acceptance: Class priors correct, feature distributions learned, predictions valid
- Dependencies: None

### Task 4.3: GRADIENT_BOOSTING_CLASSIFIER - Sequential Ensemble
- Implement: make, set_n_estimators, set_learning_rate, set_max_depth, train, predict, predict_proba
- Algorithm: Initialize with priors, iterate: fit tree to residuals, update pred += learning_rate * tree_pred
- Acceptance: All estimators trained, learning rate applied, predictions improve
- Dependencies: DECISION_TREE_CLASSIFIER (exists in v1.0.0)

---

## IMPLEMENTATION STRATEGY

**Phase A - Parallel (No Dependencies):**
Tasks 1.1, 1.3, 3.1, 3.2, 4.1, 4.2 can start immediately

**Phase B - Sequential:**  
Task 2.1 → 2.2 → 2.3 (each depends on previous)  
Task 1.1 → 1.2 (1.2 depends on 1.1)  
Task 4.3 (needs DECISION_TREE_CLASSIFIER from v1.0.0)

**Recommended Order:** Phase A (6 tasks) in parallel, then sequential tasks

---

## QUALITY GATES

All implementations must satisfy Phase 1 contracts (frozen - no changes):
- ✅ All preconditions validated
- ✅ All postconditions verified  
- ✅ All invariants maintained
- ✅ Fluent API (set_* return `like Current`)
- ✅ Void-safe and SCOOP-compatible

Next: Phase 4 (Implementation) - Write feature bodies satisfying contracts

