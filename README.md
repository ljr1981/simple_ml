# simple_ml

[Documentation](https://simple-eiffel.github.io/simple_ml/) •
[GitHub](https://github.com/simple-eiffel/simple_ml) •
[Issues](https://github.com/simple-eiffel/simple_ml/issues)

![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
![Eiffel 25.02](https://img.shields.io/badge/Eiffel-25.02-purple.svg)
![DBC: Contracts](https://img.shields.io/badge/DBC-Contracts-green.svg)

Production-ready machine learning algorithms for Eiffel with Design by Contract.

Part of the [Simple Eiffel](https://github.com/simple-eiffel) ecosystem.

## Status

✅ **Production Ready** — v1.1.0
- 125 tests passing, 100% pass rate
- 10 ML algorithms with regularization, kernel methods, ensemble learning
- Design by Contract throughout
- SCOOP concurrent-ready

## Quick Start

```eiffel
model := create {LINEAR_REGRESSION_MODEL}.make
    .set_learning_rate (0.01)
    .set_max_iterations (100)

model.train (training_X, training_y)
prediction := model.predict (test_X)
```

For complete documentation, see [our docs site](https://simple-eiffel.github.io/simple_ml/).

## Features

- **Supervised Learning** - Linear/Logistic Regression, SVM, KNN, Decision Trees, Random Forests, Neural Networks
- **Regularization** - L1, L2, ElasticNet for linear models (v1.1.0+)
- **Kernel Methods** - RBF and Polynomial kernels for SVM (v1.1.0+)
- **Ensemble Methods** - Gradient Boosting classifier (v1.1.0+)
- **Model Selection** - K-fold cross-validation, grid search (v1.1.0+)
- **Probabilistic** - Naive Bayes classifier (v1.1.0+)
- **Design by Contract** - Every algorithm fully specified with require/ensure/invariant
- **SCOOP Ready** - Void-safe (void_safety="all") with concurrent support

For details, see the [User Guide](https://simple-eiffel.github.io/simple_ml/user-guide.html).

## Installation

```bash
# Add to your ECF:
<library name="simple_ml" location="$SIMPLE_EIFFEL/simple_ml/simple_ml.ecf"/>
```

## License

MIT License - See LICENSE file

## Support

- **Docs:** https://simple-eiffel.github.io/simple_ml/
- **GitHub:** https://github.com/simple-eiffel/simple_ml
- **Issues:** https://github.com/simple-eiffel/simple_ml/issues
