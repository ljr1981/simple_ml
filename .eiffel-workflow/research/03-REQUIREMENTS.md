# REQUIREMENTS: simple_ml

## Functional Requirements

| ID | Requirement | Priority | Acceptance Criteria |
|----|-------------|----------|---------------------|
| FR-001 | Implement Linear Regression (OLS) | MUST | Can train on labeled dataset, predict on new samples, has MSE/R² metrics |
| FR-002 | Implement Logistic Regression (binary classification) | MUST | Can train on binary dataset, predict probabilities, compute confusion matrix |
| FR-003 | Implement Decision Tree classifier | MUST | Builds tree via information gain, predicts classes, handles missing values gracefully |
| FR-004 | Implement Random Forest (ensemble of trees) | MUST | Trains N trees with random feature subsets, aggregates predictions, computes feature importance |
| FR-005 | Implement Support Vector Machine (SVM) with linear kernel | MUST | Finds maximum-margin hyperplane, handles linearly separable data, produces decision function |
| FR-006 | Implement basic Neural Network (MLPClassifier, MLPRegressor) | MUST | Multi-layer perceptron with backpropagation, configurable hidden layers, sigmoid/ReLU activations |
| FR-007 | Model evaluation metrics framework | MUST | Accuracy, Precision, Recall, F1-score, Confusion Matrix, ROC-AUC, MSE, R² |
| FR-008 | Data preprocessing pipeline | MUST | Feature scaling (min-max, standard), train-test split, cross-validation (k-fold) |
| FR-009 | Gradient-based optimization integration | MUST | Use simple_optimization.GRADIENT_DESCENT_SOLVER for training |
| FR-010 | Linear algebra operations | MUST | Use simple_linalg for matrix ops (transpose, multiply, inverse, decomposition) |
| FR-011 | Statistical distributions | MUST | Use simple_statistics for Gaussian, Bernoulli distributions in probabilistic methods |
| FR-012 | Configuration builder pattern | SHOULD | Chainable setters for hyperparameters (e.g., model.set_learning_rate(0.01).set_max_iterations(1000)) |
| FR-013 | Model serialization | SHOULD | Save/load trained models to/from files (simple format, not binary blobs) |
| FR-014 | Feature importance visualization hooks | SHOULD | Methods to extract feature importance for visualization by external tools |
| FR-015 | Hyperparameter tuning (grid search) | SHOULD | Grid search over parameter space, cross-validation to find best params |
| FR-016 | Clustering algorithms (Phase 2) | DEFERRED | K-means, hierarchical clustering, DBSCAN |
| FR-017 | Dimensionality reduction (Phase 2) | DEFERRED | PCA, t-SNE basics |
| FR-018 | Time series support (Phase 2) | DEFERRED | ARIMA, Prophet basics, seasonal decomposition |

## Non-Functional Requirements

| ID | Requirement | Category | Measure | Target |
|----|-------------|----------|---------|--------|
| NFR-001 | Correctness via Design by Contract | CORRECTNESS | % contracts implemented | 100% on public features |
| NFR-002 | Numerical stability | CORRECTNESS | IEEE 754 compliance | Handles NaN, Inf gracefully |
| NFR-003 | Training time for datasets | PERFORMANCE | Time for 10K samples, 100 features | < 5 seconds (gradient descent) |
| NFR-004 | Memory usage | PERFORMANCE | In-memory dataset size | Support up to 100MB (RAM-based) |
| NFR-005 | Prediction latency | PERFORMANCE | Single prediction time | < 100 microseconds for basic models |
| NFR-006 | Void-safety | RELIABILITY | Void checks | All contracts void-safe (void_safety="all") |
| NFR-007 | SCOOP compatibility | RELIABILITY | Concurrency support | Concurrent prediction allowed; training single-threaded initially |
| NFR-008 | Code clarity | MAINTAINABILITY | Algorithm transparency | Algorithms visible in code, not black boxes |
| NFR-009 | Documentation | MAINTAINABILITY | Doc coverage | Every public feature has require/ensure/invariant + comments |
| NFR-010 | Test coverage | RELIABILITY | Test pass rate | 100% pass rate for all phases |
| NFR-011 | Compilation warnings | RELIABILITY | Warning count | Zero warnings (ZERO POLICY) |
| NFR-012 | Educational value | USABILITY | Algorithm clarity | Easy to understand how algorithms work |
| NFR-013 | Integration with simple_* | COMPATIBILITY | Dependency usage | Use simple_optimization, simple_linalg, simple_statistics, simple_mml for contracts |
| NFR-014 | Eiffel idioms compliance | QUALITY | Code style | UPPER_SNAKE_CASE classes, lower_snake_case features, l_ for locals, a_ for args |

## Constraints

| ID | Constraint | Type | Immutable? |
|----|------------|------|------------|
| C-001 | Must use Design by Contract (require/ensure/invariant) throughout | TECHNICAL | YES |
| C-002 | Must be SCOOP-compatible and void-safe | TECHNICAL | YES |
| C-003 | Must prefer simple_* over ISE/Gobo where available | ECOSYSTEM | YES |
| C-004 | No external ML libraries (TensorFlow, scikit-learn bindings) in implementation | TECHNICAL | YES |
| C-005 | All code must compile with zero warnings | TECHNICAL | YES |
| C-006 | MIT License (same as simple_* ecosystem) | LEGAL | YES |
| C-007 | CPU-based training (no GPU acceleration in MVP) | PERFORMANCE | MUTABLE (Phase 2 evaluation) |
| C-008 | Single-threaded training (SCOOP for prediction only, initially) | TECHNICAL | MUTABLE (Phase 2 evaluation) |
| C-009 | In-memory datasets (no streaming or distributed storage in MVP) | TECHNICAL | MUTABLE (Phase 2 evaluation) |
| C-010 | Eiffel 25.02+ (current EiffelStudio version) | TECHNICAL | YES |

## Use Cases

### UC-001: Train Linear Regression Model
**Actor:** Data Scientist
**Precondition:** Labeled dataset available with numerical features and continuous target
**Main Flow:**
1. Load dataset from CSV (using external tool, not in scope)
2. Create LINEAR_REGRESSION_MODEL
3. Call train(X_train, y_train) with gradient descent from simple_optimization
4. Call predict(X_test) on new samples
5. Evaluate with MSE, R² metrics
**Postcondition:** Model trained, predictions available with accuracy metrics

### UC-002: Train Random Forest Classifier
**Actor:** Analyst
**Precondition:** Labeled classification dataset, 1000+ samples recommended
**Main Flow:**
1. Create RANDOM_FOREST_CLASSIFIER with num_trees=100, max_features="sqrt"
2. Call train(X_train, y_train) - builds 100 decision trees with random subsets
3. Call predict_proba(X_test) - returns probability for each class
4. Evaluate with accuracy, precision, recall, F1-score
5. Call feature_importance() - see which features matter most
**Postcondition:** Predictions made; feature importance known

### UC-003: Hyperparameter Tuning with Grid Search
**Actor:** ML Engineer
**Precondition:** Base model, parameter grid defined
**Main Flow:**
1. Create MODEL instance
2. Create GRID_SEARCH with parameter_grid = {learning_rate: [0.001, 0.01, 0.1], max_iterations: [100, 500, 1000]}
3. Call grid_search.fit(X_train, y_train, model, cv=5) - tests all combinations with 5-fold CV
4. Returns best parameters and cross-validation scores
**Postcondition:** Best hyperparameters identified

### UC-004: Cross-Validation for Model Selection
**Actor:** Research Scientist
**Precondition:** Dataset, candidate models
**Main Flow:**
1. Create CROSS_VALIDATOR with k=5 folds
2. For each model:
   a. Call cross_validator.evaluate(model, X, y)
   b. Get fold scores: [0.92, 0.89, 0.91, 0.88, 0.90]
   c. Compute mean = 0.90, std = 0.013
3. Select model with highest mean cross-validation score
**Postcondition:** Best model selected based on generalization performance

### UC-005: Feature Scaling for Neural Network
**Actor:** Practitioner
**Precondition:** Raw dataset with mixed feature scales
**Main Flow:**
1. Create STANDARD_SCALER
2. Call scaler.fit(X_train) - computes mean and std
3. Call X_train_scaled = scaler.transform(X_train)
4. Call X_test_scaled = scaler.transform(X_test) - uses training stats
5. Train neural network on scaled data
**Postcondition:** Features normalized to zero mean, unit variance

### UC-006: Regulatory Audit Trail for ML Model
**Actor:** Compliance Officer
**Precondition:** Trained ML model used in decision-making
**Main Flow:**
1. Model has complete contract-verified implementation
2. For any prediction, reviewer can:
   a. Understand exactly what algorithm was used
   b. See preconditions checked before prediction
   c. See postconditions guarantees
   d. Trace all hyperparameters
   e. Review training data statistics
3. Formal correctness documented for audits
**Postcondition:** ML model decision fully auditable and traceable

## Derived Requirements from Research

### From Landscape Analysis
- **FR-007** extends scikit-learn's metric comprehensiveness
- **NFR-001** addresses gap in formal verification (not in scikit-learn, TensorFlow, PyTorch)
- **C-003** enforces simple_* first policy (novel in ML ecosystem)

### From Formal Verification Research (WFVML, Post-AI-FM-26)
- Every algorithm will have preconditions specifying valid input ranges
- Every algorithm will have postconditions specifying output properties
- Model training will have frame conditions (what dataset properties are preserved)
- **NEW** FR-019 (implicit): Formal verification hooks for external verification tools

### From Contract-Based Programming Research
- Contracts document valid API usage (preconditions on feature order)
- API contracts catch errors early (e.g., fit() must be called before predict())

## Success Metrics (for Phase 5 Verification)

1. **Algorithm Correctness**: All algorithms match reference implementations within IEEE 754 epsilon
2. **Contract Completeness**: 100% of public features have require/ensure/invariant
3. **Test Coverage**: Every contract postcondition verified by at least one test
4. **Numerical Stability**: No crashes on edge cases (zero features, single sample, all-same-class)
5. **Performance Baseline**: Training completes in reasonable time (< 5 sec for typical enterprise dataset)
6. **Usability**: Code is understandable; algorithms not hidden in optimized black boxes
7. **Integration**: All simple_* dependencies work correctly; no circular dependencies

## Open Questions for Phases 1-2 Resolution

1. Should we implement regularization (L1/L2) in linear/logistic regression for MVP?
2. How to represent missing values in datasets? (NA, NaN, separate flag?)
3. Should neural network implementation support batching or single-sample training?
4. What's the minimal decision tree depth/width for practical use?
5. Should SVM support non-linear kernels (RBF, poly) in MVP or defer to Phase 2?
6. How to handle imbalanced datasets? (class weights, resampling?)
7. Should we include anomaly detection algorithms?
8. What's the API for feature selection?

These will be refined during Phase 1 (Contracts) and Phase 2 (Review).
