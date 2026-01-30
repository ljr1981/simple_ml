# LANDSCAPE: simple_ml

## Existing Solutions

### Solution 1: scikit-learn (Python)

| Aspect | Assessment |
|--------|------------|
| Type | LIBRARY (comprehensive ML) |
| Platform | Python 3.8+ |
| URL | https://scikit-learn.org/stable/ |
| Maturity | MATURE (since 2007) |
| License | BSD 3-Clause |
| Primary Use | Traditional ML: classification, regression, clustering |

**Strengths:**
- Most comprehensive classical ML library
- Excellent documentation and community
- Best-in-class data preprocessing pipeline
- Simple, intuitive API
- Excellent performance on small-medium datasets
- De facto standard for tabular data

**Weaknesses:**
- No formal verification or contracts
- Limited to CPU (no GPU acceleration)
- Not designed for large-scale distributed training
- Limited neural network support (uses external libraries)

**Relevance:** 85% - This is the benchmark for classical ML in enterprise

### Solution 2: TensorFlow (Python)

| Aspect | Assessment |
|--------|------------|
| Type | FRAMEWORK (deep learning + traditional ML) |
| Platform | Python, C++, JavaScript |
| URL | https://www.tensorflow.org/ |
| Maturity | MATURE (since 2015, Google-backed) |
| License | Apache 2.0 |
| Primary Use | Deep learning, large-scale training, production deployment |

**Strengths:**
- GPU/TPU acceleration for large datasets
- Production-grade deployment (TensorFlow Serving, Lite, JS)
- Supports neural networks, deep learning
- Excellent scalability
- Mobile and embedded deployment options

**Weaknesses:**
- Steep learning curve (high-level Keras API vs low-level)
- Overkill for classical ML tasks
- Complex for simple problems
- No formal verification

**Relevance:** 60% - Overkill for MVP; relevant for Phase 2 neural network scaling

### Solution 3: PyTorch (Python)

| Aspect | Assessment |
|--------|------------|
| Type | FRAMEWORK (deep learning + traditional ML) |
| Platform | Python, C++ |
| URL | https://pytorch.org/ |
| Maturity | MATURE (since 2016, Facebook AI Research) |
| License | BSD |
| Primary Use | Research, deep learning, dynamic computation graphs |

**Strengths:**
- Pythonic, easy-to-understand API
- Excellent for research and prototyping
- GPU acceleration
- Dynamic computation graphs (more flexible)
- Growing production adoption

**Weaknesses:**
- Less mature deployment infrastructure than TensorFlow
- Primarily focused on deep learning
- No formal verification
- More research-oriented than production-ready

**Relevance:** 55% - Research-friendly but not focused on classical ML or verification

### Solution 4: Algae (Eiffel)

| Aspect | Assessment |
|--------|------------|
| Type | LIBRARY (matrices and linear algebra) |
| Platform | Eiffel |
| URL | (historical library, limited current documentation) |
| Maturity | DORMANT/HISTORICAL |
| License | Unknown (likely proprietary or abandoned) |
| Primary Use | 2D matrix operations in Eiffel |

**Strengths:**
- Native Eiffel implementation
- Some linear algebra support
- Design by Contract possible

**Weaknesses:**
- No active maintenance
- No ML algorithms
- Limited feature set
- Poor documentation
- Not suitable as foundation for simple_ml

**Relevance:** 5% - Historical reference only; superseded by simple_linalg

### Solution 5: EiffelMath (Eiffel)

| Aspect | Assessment |
|--------|------------|
| Type | LIBRARY (numerical computation) |
| Platform | Eiffel |
| URL | (historical library, mentioned in academic context) |
| Maturity | DORMANT |
| License | Unknown |
| Primary Use | Object-oriented numerical computation |

**Strengths:**
- Designed for numerical computation in Eiffel
- Some scientific computing support
- Design by Contract potential

**Weaknesses:**
- No active development
- No ML-specific features
- Poor documentation
- Not suitable for modern ML

**Relevance:** 10% - Historical context; shows Eiffel used for numerical work

### Solution 6: Wrapping TensorFlow in Eiffel

| Aspect | Assessment |
|--------|------------|
| Type | WRAPPER (Eiffel bindings to TensorFlow C API) |
| Platform | Eiffel + TensorFlow C API |
| URL | Tutorial available via WrapC tool |
| Maturity | EXPERIMENTAL |
| License | TensorFlow (Apache 2.0) + Eiffel wrapper (varies) |
| Primary Use | Using TensorFlow from Eiffel code |

**Strengths:**
- Access to TensorFlow's ML capabilities
- GPU acceleration available
- Leverages TensorFlow's maturity

**Weaknesses:**
- Loses Design by Contract benefits
- TensorFlow's API not Eiffel-idiomatic
- Complex C API bindings
- No simple_* ecosystem integration
- Not pure Eiffel

**Relevance:** 30% - Feasible but not aligned with simple_* philosophy

## Eiffel Ecosystem Check

### ISE Libraries
- **EiffelStudio Base**: Used for fundamental types (vectors, lists, queues)
- **EiffelStudio EiffelMath**: Historical, dormant, not suitable
- **EiffelStudio Testing**: Used for test infrastructure in simple_*

### simple_* Libraries (Direct Dependencies)
- **simple_linalg**: Matrix operations, linear algebra - PRIMARY DEPENDENCY
- **simple_optimization**: Gradient descent, optimization - PRIMARY DEPENDENCY
- **simple_statistics**: Distributions, statistical operations - PRIMARY DEPENDENCY
- **simple_montecarlo**: Probabilistic simulation - SECONDARY DEPENDENCY
- **simple_random**: Random number generation - SECONDARY DEPENDENCY
- **simple_calculus**: Numerical differentiation - POSSIBLE DEPENDENCY
- **simple_mml**: Mathematical contracts (MML_SET, MML_SEQUENCE) - REQUIRED for contracts
- **simple_testing**: Test infrastructure - REQUIRED for Phase 5

### Gobo Libraries
- **Gobo Data Structures**: Not needed; simple_* has collections
- **Gobo String Processing**: Not core ML need
- **Gobo Math**: Obsolete; simple_linalg preferred

### Gap Analysis

**Not available in Eiffel/simple_* ecosystem:**
- Formal verification tools for trained models (unlike research in WFVML)
- GPU acceleration framework
- Distributed training infrastructure
- ONNX model interchange
- Automated hyperparameter tuning (AutoML)
- Time series specialized algorithms (Prophet, ARIMA)
- NLP preprocessing and embeddings

## Comparison Matrix

| Feature | scikit-learn | TensorFlow | PyTorch | simple_ml (Proposed) |
|---------|-------------|-----------|---------|----------------------|
| Classical ML | ✓ BEST | ✓ | ✓ Limited | ✓ MVP Focus |
| Deep Learning | ✗ | ✓ BEST | ✓ BEST | ✓ Basic only |
| Formal Verification | ✗ | ✗ | ✗ | ✓ DBC throughout |
| Data Preprocessing | ✓ BEST | ✓ | ✓ | ✓ Foundation |
| GPU Acceleration | ✗ | ✓ BEST | ✓ BEST | ✗ CPU only (MVP) |
| Eiffel Native | ✗ | ✗ | ✗ | ✓ BEST |
| Design by Contract | ✗ | ✗ | ✗ | ✓ 100% |
| Educational Value | ✓ BEST | Medium | Medium | ✓ BEST (transparent) |
| Deployment Ease | ✓ | ✓ BEST | ✓ | ✓ Eiffel integration |
| Learning Curve | ✓ BEST (gentle) | Steep | Gentle | ✓ Transparent DBC |
| Model Interpretability | ✓ BEST | Limited | Limited | ✓ BEST (algorithms visible) |

## Patterns Identified

| Pattern | Seen In | Adopt? |
|---------|---------|--------|
| Builder pattern for model configuration | scikit-learn (pipeline), TensorFlow, PyTorch | YES - use for chainable setters |
| Transformer API (fit/transform) | scikit-learn pipeline | YES - preprocessing pipeline |
| Lazy evaluation of matrices | NumPy (foundational to scikit-learn) | MAYBE - if simple_linalg supports |
| Separation of training and prediction | All ML libraries | YES - two-phase model lifecycle |
| Cross-validation patterns | scikit-learn | YES - evaluation framework |
| Ensemble voting patterns | scikit-learn | MAYBE Phase 2 |
| Callback patterns for monitoring | TensorFlow, PyTorch | MAYBE Phase 2 |
| Contract-based error checking | Formal verification research (WFVML) | YES - core to simple_ml |

## Build vs Buy vs Adapt

| Option | Effort | Risk | Fit |
|--------|--------|------|-----|
| **BUILD** (native simple_ml) | HIGH (substantial) | MEDIUM (algorithm complexity) | 95% (perfect Eiffel fit) |
| **WRAP TensorFlow** | MEDIUM (binding layer) | HIGH (loses DBC benefits) | 20% (not idiomatic) |
| **PORT scikit-learn** | VERY HIGH (100K+ LOC) | LOW (algorithms proven) | 50% (not Eiffel design) |
| **ADAPT Algae/EiffelMath** | MEDIUM (legacy code) | HIGH (dormant, poor structure) | 30% (outdated) |

**Recommendation:** **BUILD** - Create native simple_ml with full Design by Contract

## Market Positioning

**Unique positioning for simple_ml:**
- Only ML library with formal verification built-in
- Algorithms transparent and auditable (not black boxes)
- Design by Contract ensures correctness guarantees
- Educational tool for teaching ML + verification combined
- Natural fit in regulated domains (healthcare, finance, autonomous systems)
- Eiffel community gains production-grade ML capability

## Challenges vs Opportunities

| Aspect | Challenge | Opportunity |
|--------|-----------|-------------|
| Performance | Eiffel slower than C/C++ | Positioned for correctness, not speed; find niche in verification-focused domains |
| Adoption | Eiffel niche language | First-mover advantage: only formal-verified ML library |
| GPU Support | Eiffel not GPU-optimized | MVP targets CPU; Phase 2 explores acceleration |
| Scalability | Datasets up to ~100MB in memory | Good for enterprise decision-making; not for big data pipelines |
| Ecosystem | small_* is new | Building synergy: optimization + linalg + stats + ML together |

## References to Formal Verification Research

Research shows formal verification of ML models is emerging (WFVML 2024, Post-AI-FM-26), but no production libraries implement it. This is a genuine gap that simple_ml can fill.

Key research areas:
- Verification of neural network robustness (arxiv.org/abs/2104.02466)
- ML for formal verification (arxiv.org/abs/1806.03600)
- Contracts for ML APIs (emerging research on what contracts help catch errors)

## Ecosystem Synergy Opportunity

simple_ml can leverage:
- **simple_optimization**: Gradient descent, Nelder-Mead already implemented
- **simple_linalg**: Matrix operations, linear transformations
- **simple_statistics**: Statistical distributions, probability
- **simple_montecarlo**: Probabilistic methods, uncertainty quantification
- **simple_random**: Random sampling, shuffling

This is a STRENGTH vs Python ecosystem fragmentation.

## Conclusion

**Gap filled by simple_ml:** No other library combines Design by Contract with machine learning. This is a genuine innovation in the ML space.

**Target market:** Enterprises and researchers who value correctness, auditability, and formal verification over raw speed. Much like how Eiffel positioned itself in safety-critical domains (aviation, medical devices).
