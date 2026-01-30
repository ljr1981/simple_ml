# Intent Review Request: simple_ml

**Instructions:** You are an expert software architect reviewing the intent document for a new Eiffel machine learning library called **simple_ml**. Your goal is to identify vague language, missing requirements, hidden assumptions, and surface critical questions that need clarification BEFORE contract design begins.

---

## Review Criteria

Look for:

1. **Vague language:** Words like "suitable", "appropriate", "comprehensive", "efficient" without concrete definitions
2. **Missing edge cases:** What happens with empty datasets? Single-class problems? Numerical extremes?
3. **Untestable criteria:** Are acceptance criteria specific and measurable?
4. **Hidden dependencies:** What assumptions exist about user knowledge, data format, runtime environment?
5. **Scope ambiguity:** Is the boundary between MVP and Phase 2 clear? Could creep happen?
6. **Contract feasibility:** Can all proposed Design by Contract guarantees actually be verified in practice?
7. **Market assumptions:** Is the regulatory domain assumption validated, or speculative?
8. **Risk mitigation:** Are the 10 identified risks adequately addressed before Phase 1?

---

## Output Format

For each significant issue found, provide:

```
ISSUE: [Brief title]

LOCATION: [Section in intent.md]

CURRENT TEXT: "[Quote the vague/problematic phrase]"

PROBLEM: [Why this is vague, unclear, or risky]

ALTERNATIVES:
  A) [Concrete option 1 with specifics]
  B) [Concrete option 2 with specifics]
  C) [Concrete option 3 with specifics]

RECOMMENDATION: [Which option is best, and why]

IMPACT IF NOT FIXED: [What breaks in Phase 1 if this isn't clarified now]
```

---

## Intent Document to Review

```
# Intent: simple_ml

## What

**simple_ml** is a formally-verified machine learning library for Eiffel that provides
contract-verified supervised learning algorithms (linear regression, logistic regression,
decision trees, random forests, support vector machines, and basic neural networks) with
complete Design by Contract verification, algorithmic transparency, and auditability for
regulated domains.

The library emphasizes correctness and verification over raw performance, making it
suitable for healthcare, finance, autonomous systems, and academic use cases where formal
assurance matters more than speed.

## Why

**Problem:** Enterprise and academic applications need machine learning capabilities they
can formally verify and audit. Existing ML libraries (scikit-learn, TensorFlow, PyTorch)
are black boxes without formal verification. Regulatory domains (healthcare, finance,
autonomous vehicles) cannot deploy unverifiable decision-making systems.

**Opportunity:** Formal verification of ML is an emerging field (WFVML 2024, Post-AI-FM-26).
No production library currently combines Design by Contract with machine learning algorithms.
This is a genuine gap in the ecosystem.

**Strategic Value:**
- Positions Eiffel as the leader in formally-verified ML
- simple_ml is the capstone library that ties together simple_optimization, simple_linalg,
  simple_statistics (ecosystem synergy)
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

- [ ] **6 core supervised learning algorithms implemented:** Linear Regression, Logistic Regression,
      Decision Tree, Random Forest, Support Vector Machine (linear), Neural Network (basic MLP)
- [ ] **100% Design by Contract coverage:** Every public class and feature has require/ensure/invariant clauses
- [ ] **Complete evaluation framework:** Accuracy, Precision, Recall, F1-score, Confusion Matrix, ROC-AUC, MSE, R² metrics
- [ ] **Data preprocessing pipeline:** Feature scaling (min-max, standardization), train-test split, k-fold cross-validation
- [ ] **Integration with simple_* ecosystem:** Uses simple_optimization (gradient descent), simple_linalg (matrices),
      simple_statistics (distributions), simple_mml (contracts)
- [ ] **100% test pass rate:** Phase 5-6 comprehensive testing with adversarial/edge case coverage
- [ ] **Validation against reference implementations:** All algorithms match scikit-learn/R within IEEE 754 epsilon
- [ ] **Numerical stability:** No NaN/Inf crashes; explicit IEEE 754 compliance in contracts
- [ ] **Production release:** v1.0.0 with professional documentation site, zero compilation warnings
- [ ] **Regulatory-ready:** Formal verification hooks; contracts amenable to SMT/model checking for FDA/EU AI Act compliance

## Out of Scope (Phase 1-3 MVP)

- GPU acceleration (CPU-only; Phase 2 evaluates)
- Distributed/parallel training (single-threaded MVP; Phase 2 evaluates)
- Clustering algorithms (k-means, hierarchical; defer to Phase 2)
- Dimensionality reduction (PCA, t-SNE; defer to Phase 2)
- Time series methods (ARIMA, Prophet; defer to Phase 2 or separate simple_timeseries)
- Neural network advanced architectures (convolutional, recurrent; MVP is simple MLP only)
- AutoML/hyperparameter optimization beyond grid search (Phase 2+)

## Dependencies

7 simple_* libraries (linalg, optimization, statistics, random, montecarlo, calculus, mml)
2 ISE libraries (base, testing)
0 Gobo libraries
0 gaps identified

## MML Decision

**YES - Required**

simple_ml has collections (training datasets, feature matrices, neural network weights) that
require formal frame conditions via MML_SET, MML_SEQUENCE model queries.

## Phase Timeline

Total: ~12 weeks from Phase 1 to v1.0.0 production release
```

---

## Specific Questions for Reviewer

Please address the following critical questions:

### 1. Scope & Scale

**Q1a:** "6 core supervised learning algorithms" - Is this truly sufficient for MVP? Which are most critical?
- Are Linear Regression and Logistic Regression essential (foundation)?
- Are Decision Tree + Random Forest essential (interpretability)?
- Are SVM essential, or could be deferred with 5 core?
- Is Neural Network essential, or risky/complex for MVP?

**Q1b:** What defines "basic MLP" neural network?
- How many hidden layers? (1? 2? configurable?)
- What activation functions? (sigmoid, tanh, ReLU, or all three?)
- What's the maximum network size before performance becomes unacceptable?
- Is backpropagation from scratch feasible in Eiffel, or should Phase 2 implement better optimizers?

**Q1c:** Datasets up to ~100MB in-memory - is this realistic?
- What's the actual test scenario? (1000 samples × 1000 features = 8MB)
- Have you considered sparse matrices? (Many ML datasets are sparse)
- Should Phase 2 address larger datasets, or is 100MB the hard limit?

### 2. Contract Feasibility

**Q2a:** "100% Design by Contract coverage" - what does this actually mean?
- Does EVERY method need contracts, or just public APIs?
- What about helper methods in DecisionTreeNode (internal tree structure)?
- What about iteration/recursion? (Tree building is recursive - how to contract?)

**Q2b:** "Validation against reference implementations within IEEE 754 epsilon" - how tight is epsilon?
- IEEE 754 epsilon for REAL_64: ~2.22e-16
- But numerical algorithms accumulate error over iterations
- Should acceptance be ±0.0001 (0.01%), ±0.001 (0.1%), or exact?
- How will you verify this automatically in Phase 5?

**Q2c:** Postcondition for training that diverges (NN doesn't converge):
- Current: "converged or iterations_exhausted"
- But what if loss is still HIGH after iterations_exhausted?
- Should postcondition guarantee minimum quality, or just guarantee termination?

### 3. simple_* Ecosystem Coupling

**Q3a:** Dependency on simple_optimization.GRADIENT_DESCENT_SOLVER:
- Have you verified it works for non-convex problems (NN training)?
- What if simple_optimization has bugs? Dependency chain risk?
- Should simple_ml implement fallback gradient descent, or trust upstream?

**Q3b:** Dependency on simple_linalg for all matrix operations:
- Have you benchmarked simple_linalg performance?
- Are there algorithms that would fail due to numerical instability in simple_linalg?
- SVM requires solving quadratic programming (QP) - does simple_optimization support QP, or just unconstrained optimization?

**Q3c:** simple_mml for contracts:
- MML_SET, MML_SEQUENCE are new/specialized - are they mature enough for Phase 1?
- Could simpler frame conditions work without MML?
- What if MML postconditions can't be written or verified?

### 4. Regulatory & Market Risk

**Q4a:** "Regulatory-ready with formal verification hooks":
- Who specifically validated this? FDA? EU AI Act boards?
- Or is this aspirational positioning?
- Will contracts alone satisfy regulators, or do you need SMT/model checking in Phase 2?

**Q4b:** Market for formal-verified ML:
- Is there actual customer demand, or is this theoretical?
- Would FinTech/HealthTech pay for slow, verified ML?
- Or will they use faster scikit-learn + manual auditing?

**Q4c:** Educational market:
- Are universities ready to adopt Eiffel ML library?
- Or is this a niche even within academia?

### 5. Risk Mitigation

**Q5a:** RISK-003 (NN training divergence):
- MVP success criterion: NN converges successfully - what % of time?
- If <80% success rate on toy datasets, should NN be deferred to Phase 2?
- Is there a fallback (e.g., switch to logistic regression if NN fails)?

**Q5b:** RISK-001 (performance too slow):
- Have you accepted that 10x slowdown vs scikit-learn is OK?
- What if benchmarks show 100x slowdown? Is library still useful?
- Phase 2 decision: GPU acceleration or accept CPU-only forever?

**Q5c:** RISK-004 (overspecified contracts):
- How will you detect if contracts are impossible during Phase 5?
- Proposed process: loosen tolerances? Weaken postconditions?
- Won't this undermine the "formal verification" positioning?

### 6. Phase 1 Contracts (Critical Path)

**Q6a:** What are the contract signatures for the facade class (SIMPLE_ML)?
```eiffel
class SIMPLE_ML
    feature
        create_linear_regression: LINEAR_REGRESSION_MODEL
            require
                -- What preconditions?
            ensure
                -- What postconditions? Just "not void"?
        ...
end
```

**Q6b:** How to contract DATA LOADING?
- Intent says "uses simple_random for sampling"
- But actual data input is user-provided (CSV, JSON, arrays)
- Who validates input data format/quality?
- Should simple_ml include CSV parser, or leave to users?

**Q6c:** How to contract CONVERGENCE?
- Linear regression: converges via closed-form OR gradient descent
- Logistic regression: gradient descent may oscillate
- NN: non-convex landscape, may have local minima
- One postcondition for all, or specialized per algorithm?

### 7. Timeline Reality Check

**Q7a:** Phase 1 (2 weeks, 6 algorithms):
- 6 class skeletons × 3 days each = 18 days = 2.5 weeks
- But also: 6 test skeleton classes, ECF setup, compilation gate
- Is 2 weeks realistic, or should it be 3?

**Q7b:** Phase 4 (4-5 weeks, implementation):
- Linear regression with gradient descent: 1 week (learning curve)
- Logistic regression: 3-4 days (similar to linear)
- Decision tree (information gain splitting): 1 week (complex algorithm)
- Random forest (ensemble, bootstrap): 3-4 days
- SVM (quadratic programming): 1-2 weeks (hardest, might fail)
- NN (backpropagation): 1.5 weeks (complex, might diverge in Phase 5)
- Total: 6-7 weeks (longer than estimate)

**Q7c:** Phase 5 (2 weeks, testing):
- Skeletal tests → full tests: 2-3 days per algorithm (5-6 days total)
- Validation vs reference (scikit-learn): 1 week
- Edge case debugging: 3-4 days
- Total: 2-3 weeks (longer than estimate)

### 8. Success Criteria Clarity

**Q8a:** "Validation within IEEE 754 epsilon" - how will you automate this?
- Write test comparing simple_ml vs scikit-learn outputs?
- Tolerance: exact match, ±1e-10, ±1e-6?
- What if SVM produces different support vectors than scikit-learn (both correct)?

**Q8b:** "100% test pass rate" - for what test set?
- Only adversarial/unit tests in Phase 6?
- Also real-world datasets (iris, MNIST)?
- What if iris misclassifies 1 sample - test fails?

**Q8c:** "Formal verification hooks for SMT" - what does this mean concretely?
- Postconditions exportable to SMT-LIB format?
- Or just "postconditions could theoretically be verified"?

---

## Final Summary Questions

1. **MUST FIX before Phase 1:** Which 1-2 items above are blockers for contract design?

2. **NICE TO CLARIFY before Phase 1:** Which 3-4 items would improve Phase 1 contracts?

3. **CAN DEFER to Phase 2:** Which items can be addressed later without impacting MVP?

4. **RECOMMENDATION:** Given the research and this intent, is the BUILD recommendation still HIGH confidence, or should it be MEDIUM due to ambiguities found?

---

## Reviewer Instructions

Please provide structured feedback using the format shown above. Focus on clarifying INTENT, not redesigning the library.

Thank you for your careful review.
