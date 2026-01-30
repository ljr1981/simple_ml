# Changelog

All notable changes to simple_ml will be documented in this file.

## [1.1.0] - 2026-01-30

### Added

#### Regularization (Phase 4 Enhancements)
- `LINEAR_REGRESSION_REGULARIZED` - Linear regression with L1, L2, ElasticNet regularization
- `LOGISTIC_REGRESSION_REGULARIZED` - Logistic regression with L2 regularization
- Configurable regularization strength (lambda) and L1 ratio for ElasticNet

#### Kernel Methods (Phase 4 Enhancements)
- `SVM_RBF` - Support Vector Machine with Radial Basis Function kernel
- `SVM_POLYNOMIAL` - Support Vector Machine with polynomial kernel
- Configurable gamma, degree, and independent coefficient (coef0) parameters

#### Model Selection (Phase 4 Enhancements)
- `K_FOLD_SPLITTER` - K-fold cross-validation data splitter
- `FOLD` - Individual fold with training and test sets
- `GRID_SEARCH_CV` - Grid search with cross-validation for hyperparameter tuning

#### New Algorithms (Phase 4 Enhancements)
- `KNN_CLASSIFIER` - K-Nearest Neighbors classifier with multiple distance metrics
- `NAIVE_BAYES_CLASSIFIER` - Gaussian Naive Bayes probabilistic classifier
- `GRADIENT_BOOSTING_CLASSIFIER` - Ensemble of weak learners with boosting

#### Testing (Phase 5-6)
- 20 functional tests for enhancement classes (Phase 5)
- 15 adversarial/stress tests for hardening (Phase 6)
  - Boundary value tests (extreme parameters: λ=1000, γ=0.00001, degree=10)
  - Stress tests (large datasets, many estimators)
  - Edge case tests (k=1, identical features, zero coef0)
- SCOOP consumer integration test
- Total: 125 tests (100% pass rate)

### Changed
- Version bumped from 1.0.0 to 1.1.0
- Enhanced test suite: 89 tests → 125 tests

### Technical
- All enhancements fully Design by Contract compliant
- SCOOP concurrent compatibility verified
- Zero compilation warnings in finalized mode
- All postconditions verified by comprehensive test suite

## [1.0.0] - 2026-01-20

### Added
- **Linear Regression Model** - Supervised learning for continuous value prediction
  - Gradient descent optimization with configurable learning rate and iterations
  - Feature weight learning and prediction

- **Logistic Regression Model** - Binary and multiclass classification
  - Sigmoid activation with linear approximation for numerical stability
  - Probability prediction support

- **Decision Tree Classifier** - Tree-based classification
  - Configurable maximum depth and minimum samples per split
  - Hierarchical feature-based decision rules

- **Random Forest Classifier** - Ensemble learning
  - Multiple decision trees with majority voting
  - Configurable number of trees and tree depth
  - Probability distribution output

- **SVM Linear** - Support Vector Machine with linear kernel
  - Configurable regularization parameter (C) and convergence tolerance
  - Decision function output for raw classification scores

- **Neural Network Classifier** - Multi-layer perceptron
  - Configurable hidden layer architecture
  - Gradient descent training with configurable learning rate
  - Probability distribution output

### Technical
- **Design by Contract** throughout all classes
  - 74 contract clauses (preconditions, postconditions, invariants)
  - All postconditions verified by comprehensive test suite
  - Mathematical Model Library (MML) queries for precise specifications

- **Void-Safe Implementation** - void_safety="all" enforced
  - No null pointer references
  - Safe collection handling

- **SCOOP Compatibility** - Full support for concurrent algorithms
  - Concurrency support="scoop" enabled
  - Ready for parallel training on multi-core systems

- **Zero External Dependencies** - Only requires ISE base library
  - No external math libraries needed
  - Custom numerical stability techniques (e.g., sigmoid approximation)

- **Comprehensive Testing**
  - 40 functional tests covering all postconditions
  - 40 adversarial tests for boundary values, stress, and edge cases
  - 100% test pass rate (80/80 tests)
  - Adversarial test coverage:
    - Learning rates from 1e-6 to 100.0
    - Feature counts from 1 to 100+
    - Sample counts from 1 to 100+
    - Class counts from 1 to 10+
    - Iterations from 1 to 10000+

### Documentation
- **Professional Documentation Site** at https://simple-eiffel.github.io/simple_ml/
  - Overview page with feature summary
  - Quick API reference for immediate usage
  - Comprehensive user guide with examples
  - Complete API reference for all classes
  - Architecture and design documentation
  - Cookbook with 10 real-world code recipes
  - Responsive CSS styling for all devices

- **README** - Short gateway to documentation site
- **CHANGELOG** - This file documenting all changes
- **LICENSE** - MIT open source license

## Installation

To use simple_ml in your project, add this to your ECF file:

```xml
<library name="simple_ml" location="$SIMPLE_EIFFEL/simple_ml/simple_ml.ecf"/>
```

## Status

✅ **Production Ready** — Full quality assurance with Design by Contract verification
- All features implemented
- All contracts enforced
- All tests passing
- All documentation complete
- Ready for production use

## Support

- **GitHub:** https://github.com/simple-eiffel/simple_ml
- **Issues:** https://github.com/simple-eiffel/simple_ml/issues
- **Documentation:** https://simple-eiffel.github.io/simple_ml/

## License

MIT License - See LICENSE file for details
