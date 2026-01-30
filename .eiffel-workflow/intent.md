# Intent: simple_ml

## What

**simple_ml** is a formally-verified machine learning library for Eiffel that provides contract-verified supervised learning algorithms (linear regression, logistic regression, decision trees, random forests, support vector machines, and basic neural networks) with complete Design by Contract verification, algorithmic transparency, and auditability for regulated domains.

The library emphasizes correctness and verification over raw performance, making it suitable for healthcare, finance, autonomous systems, and academic use cases where formal assurance matters more than speed.

## Why

**Problem:** Enterprise and academic applications need machine learning capabilities they can formally verify and audit. Existing ML libraries (scikit-learn, TensorFlow, PyTorch) are black boxes without formal verification. Regulatory domains (healthcare, finance, autonomous vehicles) cannot deploy unverifiable decision-making systems.

**Opportunity:** Formal verification of ML is an emerging field (WFVML 2024, Post-AI-FM-26). No production library currently combines Design by Contract with machine learning algorithms. This is a genuine gap in the ecosystem.

**Strategic Value:**
- Positions Eiffel as the leader in formally-verified ML
- simple_ml is the capstone library that ties together simple_optimization, simple_linalg, simple_statistics (ecosystem synergy)
- First-mover advantage in contract-verified ML market
- Fills gap for regulated industries that need auditable AI systems

## Users

| User Type | Use Case | Needs |
|-----------|----------|-------|
| **Enterprise Data Scientists** | Building models for regulated domains | Formal correctness guarantees, audit trails, certifiable decision logic |
| **FinTech/HealthTech Developers** | Healthcare/finance ML systems | Regulatory compliance (EU AI Act, FDA), formal verification, certification trails |
| **Autonomous Systems Engineers** | Safety-critical decision logic | Provably correct ML predictions, formal assurance, auditability |
| **Academic Researchers** | Formal methods + ML research | Teaching tool, verification framework, contract-based ML exploration |
| **Eiffel Community** | Production ML capability | Native Eiffel ML library with Design by Contract, ecosystem integration |

## Acceptance Criteria

- [ ] **6 core supervised learning algorithms implemented:** Linear Regression, Logistic Regression, Decision Tree, Random Forest, Support Vector Machine (linear), Neural Network (basic MLP)
- [ ] **100% Design by Contract coverage:** Every public class and feature has require/ensure/invariant clauses
- [ ] **Complete evaluation framework:** Accuracy, Precision, Recall, F1-score, Confusion Matrix, ROC-AUC, MSE, R² metrics
- [ ] **Data preprocessing pipeline:** Feature scaling (min-max, standardization), train-test split, k-fold cross-validation
- [ ] **Integration with simple_* ecosystem:** Uses simple_optimization (gradient descent), simple_linalg (matrices), simple_statistics (distributions), simple_mml (contracts)
- [ ] **100% test pass rate:** Phase 5-6 comprehensive testing with adversarial/edge case coverage
- [ ] **Validation against reference implementations:** All algorithms match scikit-learn/R within IEEE 754 epsilon
- [ ] **Numerical stability:** No NaN/Inf crashes; explicit IEEE 754 compliance in contracts
- [ ] **Production release:** v1.0.0 with professional documentation site, zero compilation warnings
- [ ] **Regulatory-ready:** Formal verification hooks; contracts amenable to SMT/model checking for FDA/EU AI Act compliance

## Out of Scope

**Phase 1-3 (MVP):**
- GPU acceleration (CPU-only; Phase 2 evaluates)
- Distributed/parallel training (single-threaded MVP; Phase 2 evaluates)
- Clustering algorithms (k-means, hierarchical; defer to Phase 2)
- Dimensionality reduction (PCA, t-SNE; defer to Phase 2)
- Time series methods (ARIMA, Prophet; defer to Phase 2 or separate simple_timeseries)
- Neural network advanced architectures (convolutional, recurrent; MVP is simple MLP only)
- AutoML/hyperparameter optimization beyond grid search (Phase 2+)
- Causal inference (statistical specialty; separate library)
- Natural language processing (NLP-specific domain; separate simple_nlp)
- Ensemble stacking/blending (Phase 2+)
- Large-scale distributed datasets (>100MB; MVP targets in-memory)

**Explicitly Out of Scope (Never):**
- Wrapping external ML libraries (TensorFlow, scikit-learn) without Design by Contract
- GPU/CUDA acceleration without formal verification framework
- Black-box algorithms or hidden optimization tricks

## Dependencies (REQUIRED - simple_* First Policy)

**RULE:** Prefer simple_* libraries over ISE/Gobo where available.

### Dependencies Identified

| Need | Library | Justification | Preferred |
|------|---------|---------------|-----------|
| Matrix operations, linear algebra | simple_linalg | Verified linear algebra; core to all algorithms | YES (simple_*) |
| Optimization, gradient descent | simple_optimization | GRADIENT_DESCENT_SOLVER already implemented; reuse for training | YES (simple_*) |
| Statistical distributions, probability | simple_statistics | Gaussian, Bernoulli for probabilistic methods | YES (simple_*) |
| Random sampling, shuffling | simple_random | Random train-test split, cross-validation, NN initialization | YES (simple_*) |
| Probabilistic methods, Monte Carlo | simple_montecarlo | MC integration for advanced methods (Phase 2) | YES (simple_*) |
| Numerical differentiation | simple_calculus | Possible gradient computation alternative (Phase 2) | YES (simple_*) |
| MML model queries, frame conditions | simple_mml | Postcondition verification using MML_SET, MML_SEQUENCE | YES (simple_*) |
| Fundamental types (arrays, lists, etc.) | base | ISE library; fundamental Eiffel types | ISE only (no simple_* equivalent) |
| Test infrastructure | testing | EQA_TEST_SET for test framework | ISE only (no simple_* equivalent) |

**Summary:**
- 7 simple_* dependencies (all ecosystem integration)
- 2 ISE dependencies (base, testing - no alternatives exist)
- 0 Gobo dependencies
- 0 ISE/Gobo libraries blocked by simple_* equivalents

**No gaps identified.** Simple_* ecosystem is sufficient for ML library implementation.

## MML Decision (REQUIRED)

**Question:** Does simple_ml need MML model queries for precise postconditions?

**Answer:** **YES - Required**

**Rationale:**

simple_ml has collections (training datasets, feature matrices, neural network weight matrices) that require formal frame conditions:

1. **Training Data Immutability:** Contracts must document that training data is not modified by algorithms
   ```eiffel
   train (X: ARRAY [ARRAY [REAL_64]]; y: ARRAY [INTEGER])
       ensure
           -- Frame condition: training data unchanged
           X_count_unchanged: X.count = old X.count
           y_count_unchanged: y.count = old y.count
   ```

2. **Model State Tracking:** Using MML_SET to track learned classes/features
   ```eiffel
   feature -- Model Queries

       learned_classes_model: MML_SET [INTEGER]
           -- Mathematical model of unique classes learned during training.
           do
               create Result.make_empty
               across unique_classes as uc loop
                   Result := Result & @uc.item
               end
           end
   ```

3. **Weight Stability:** Using MML to verify all weights remain finite
   ```eiffel
   feature -- Invariant

       weights_finite: across weights as w all is_finite (w.item) end
   ```

**Implementation Plan:**
- Phase 1: Add simple_mml to ECF configuration
- Phase 1: Create model queries for key attributes (training data, learned classes, weights)
- Phase 4: Use model queries in postconditions for frame conditions
- Phase 5: Validate that MML postconditions are satisfied by implementation

---

## Ecosystem Integration Summary

**simple_ml positioning in ecosystem:**

```
simple_ml (NEW)
    ├── uses: simple_optimization (gradient descent solver)
    ├── uses: simple_linalg (matrix operations)
    ├── uses: simple_statistics (distributions)
    ├── uses: simple_random (sampling)
    ├── uses: simple_montecarlo (probabilistic methods, Phase 2)
    ├── uses: simple_calculus (derivatives, Phase 2)
    └── uses: simple_mml (contract verification)

This creates SYNERGY:
- simple_optimization is for mathematical optimization
- simple_ml is for machine learning optimization
- They share the same solver, proving ecosystem maturity
```

**This is the capstone library** that demonstrates the simple_* ecosystem is complete and composable.

---

## Project Structure (Phase 1+)

```
d:\prod\simple_ml\
├── .eiffel-workflow/
│   ├── intent-v2.md (this document, refined)
│   ├── research/ (from pre-phase)
│   │   ├── 01-SCOPE.md
│   │   ├── 02-LANDSCAPE.md
│   │   ├── 03-REQUIREMENTS.md
│   │   ├── 04-DECISIONS.md
│   │   ├── 05-INNOVATIONS.md
│   │   ├── 06-RISKS.md
│   │   ├── 07-RECOMMENDATION.md
│   │   └── REFERENCES.md
│   ├── prompts/ (Phase 2+)
│   └── evidence/ (Phase 1-7)
├── src/ (Phase 1: contracts; Phase 4: implementation)
│   ├── simple_ml.e (facade)
│   ├── linear_regression_model.e
│   ├── logistic_regression_model.e
│   ├── decision_tree_classifier.e
│   ├── random_forest_classifier.e
│   ├── svm_linear.e
│   ├── neural_network_classifier.e
│   └── (evaluation, preprocessing, utilities)
├── test/ (Phase 1: skeletal; Phase 5: complete)
│   ├── test_app.e
│   ├── test_linear_regression.e
│   ├── test_logistic_regression.e
│   ├── ... (per algorithm)
│   └── test_adversarial.e (Phase 6)
├── docs/ (Phase 7)
│   ├── index.html
│   ├── quick.html
│   ├── user-guide.html
│   ├── api-reference.html
│   ├── architecture.html
│   ├── cookbook.html
│   ├── css/style.css
│   └── images/
├── simple_ml.ecf (configuration)
├── README.md (Phase 7)
├── CHANGELOG.md (Phase 7)
└── LICENSE (Phase 7)
```

---

## Phase Timeline Overview

| Phase | Deliverable | Timeline | Entrance Criteria |
|-------|-------------|----------|-------------------|
| **Phase 0** | Intent + Research | ✅ COMPLETE | Research approved |
| **Phase 1** | Contracts + Skeletal Tests | 2 weeks | Intent approved |
| **Phase 2** | Adversarial Review + Approach | 1 week | Phase 1 compiled, zero warnings |
| **Phase 3** | Task Decomposition | 3 days | Phase 2 review complete |
| **Phase 4** | Implementation | 4-5 weeks | Phase 3 tasks approved |
| **Phase 5** | Test Generation + Verification | 2 weeks | Phase 4 implementation complete |
| **Phase 6** | Adversarial Testing + Hardening | 1.5 weeks | Phase 5 tests passing (100%) |
| **Phase 7** | Production Release (v1.0.0) | 1 week | Phase 6 hardening complete, zero warnings |

**Total Timeline:** ~12 weeks from Phase 1 to production release

---

## Success Criteria (Phase 0 Completion)

- [ ] Intent clearly captures WHAT (6 algorithms), WHY (formal verification gap), and WHO (regulated industries, academia)
- [ ] Out of scope is explicit (Phase 2+ features listed)
- [ ] Dependencies audited: 7 simple_* + 2 ISE (no gaps)
- [ ] MML decision made: YES-Required (collections need frame conditions)
- [ ] Research findings (07-RECOMMENDATION.md) recommend BUILD with HIGH confidence
- [ ] Ready to proceed to Phase 1 (Contracts)

---

## Notes for Phase 1 (Contracts)

**Key design principles to keep in mind:**

1. **Contracts are everything:** Every public feature will have require/ensure/invariant. This is the core value.

2. **Algorithms are transparent:** Code is readable Eiffel, not hidden C/C++ optimizations.

3. **simple_* first:** Use simple_optimization for gradient descent (not reimplementing), simple_linalg for matrices (not reimplementing).

4. **Numerical stability:** Explicit contracts on IEEE 754 compliance, no silent NaN/Inf.

5. **Regulatory ready:** Frame conditions document what data properties are preserved; SMT tools can verify postconditions.

6. **Builder pattern:** Configuration via chainable setters (matches simple_optimization style).

7. **One postcondition rule:** What changed? How? What didn't change (frame condition)?

---

## Questions for AI Review (Phase 0 - Part 2)

The following questions will be asked to external AI (Ollama/Grok/Gemini/Claude) to validate this intent:

1. **Scope clarity:** Are the 6 algorithms sufficient for MVP, or are critical algorithms missing?
2. **Contract feasibility:** Are the Design by Contract requirements realistic and achievable?
3. **Market positioning:** Is "formal verification for regulated domains" a compelling differentiator, or too niche?
4. **Dependency validation:** Are all 7 simple_* libraries actually suitable, or are there hidden gaps?
5. **MML necessity:** Is MML really required, or could simpler frame conditions work?
6. **Risk assessment:** Which of the 10 identified risks is most critical to address?
7. **Timeline realism:** Are the Phases 1-7 timelines achievable, or too optimistic?
8. **Success criteria:** Are the acceptance criteria measurable and specific enough?

These will be addressed in Phase 0 - Part 2 (AI review).

