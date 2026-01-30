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

✅ **Production Ready** — v1.0.0
- 80 tests passing (40 functional + 40 adversarial), 100% pass rate
- Six core algorithms: linear regression, logistic regression, decision trees, random forests, SVM, neural networks
- Design by Contract throughout with 74 contract clauses

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

- **Design by Contract** - Every algorithm fully specified with require/ensure/invariant
- **Six Core Algorithms** - Linear/Logistic regression, Decision trees, Random forests, SVM, Neural networks
- **Void-Safe & SCOOP** - Void-safe implementation (void_safety="all") with SCOOP concurrency support
- **Production Quality** - 80 tests with 100% pass rate including adversarial hardening
- **Zero Dependencies** - Only requires Eiffel base library (ISE)

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
