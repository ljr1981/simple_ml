# Eiffel Contract Review Request (Claude)

**Project:** simple_ml (Machine Learning Library with Design by Contract)
**Date:** 2026-01-29
**Step:** 2 of 4 in Progressive AI Review Chain
**Task:** Claude-specific adversarial contract review focusing on MML correctness

You are reviewing Eiffel contracts for a formally-verified ML library. This is the SECOND review in a chain - Ollama has already reviewed. Focus on:
1. MML model query correctness
2. Frame conditions and immutability
3. Cross-feature consistency
4. Any additional issues Ollama missed

## Claude-Specific Review Checklist

- [ ] MML_SET model queries correctly represent mathematical sets
- [ ] Frame conditions use `|=|` operator for model equality
- [ ] Postconditions using `old` expressions are syntactically correct
- [ ] Model queries are deterministic/pure (no side effects)
- [ ] MML model queries match actual data structures (e.g., classes array)
- [ ] Learned state tracking is consistent across related classes
- [ ] Configuration postconditions properly chain method returns
- [ ] Invariants are consistent with MML model queries
- [ ] No circular or redundant specifications

## Contracts to Review

[Same as phase2-ollama-review.md - all 6 algorithm classes with full contracts]

## Implementation Approach

[See approach.md]

## Ollama's Review (First Pass)

```
### 1. **LINEAR_REGRESSION_MODEL**
- **ISSUE**: Prediction value completely unconstrained.
- **LOCATION**: LINEAR_REGRESSION_MODEL.predict()
- **SEVERITY**: CRITICAL
- **SUGGESTION**: Add a postcondition to ensure the predicted value falls within a reasonable range.
- **DETAILS**: The predict() method should not allow arbitrary values as predictions, which can lead to confusion or misuse of the model's output.

### 2. **LOGISTIC_REGRESSION_MODEL**
- **ISSUE**: Could receive monolithic training data but postcondition impossible.
- **LOCATION**: LOGISTIC_REGRESSION_MODEL.train()
- **SEVERITY**: CRITICAL
- **SUGGESTION**: Modify the precondition to ensure that at least two classes are present in the training data or adjust the postcondition accordingly.
- **DETAILS**: The requirement for `classes_learned.count > 0` is impossible if only a single class is provided, leading to logical inconsistencies.

### 3. **DECISION_TREE_CLASSIFIER**
- **ISSUE**: Could accept wrong-sized feature arrays.
- **LOCATION**: DECISION_TREE_CLASSIFIER.predict()
- **SEVERITY**: CRITICAL
- **SUGGESTION**: Add a precondition to ensure that the dimension of the feature array matches the number of features expected by the trained model.
- **DETAILS**: Incorrect feature dimensions can lead to unpredictable and incorrect predictions, which is critical for reliable ML models.

### 4. **RANDOM_FOREST_CLASSIFIER**
- **ISSUE**: Should specify Result.count = classes.count, each in [0,1].
- **LOCATION**: RANDOM_FOREST_CLASSIFIER.predict_proba()
- **SEVERITY**: CRITICAL
- **SUGGESTION**: Update the postcondition to ensure that the result array contains probabilities for all classes and sums up to 1.
- **DETAILS**: The probabilities returned by predict_proba() should be valid probability distributions, ensuring that they sum up to 1 and each value is between 0 and 1.

### 5. **SVM_LINEAR**
- **ISSUE**: Extreme values, missing result constraint.
- **LOCATION**: SVM_LINEAR.decision_function()
- **SEVERITY**: CRITICAL
- **SUGGESTION**: Add postconditions to ensure that the decision function results do not have extreme values and meet any necessary constraints.
- **DETAILS**: Missing constraints on the result of the decision function can lead to confusion about the model's output, potentially causing issues in further processing.

### 6. **NEURAL_NETWORK_CLASSIFIER**
- **ISSUE**: Can't verify network properly trained.
- **LOCATION**: NEURAL_NETWORK_CLASSIFIER.weights
- **SEVERITY**: CRITICAL
- **SUGGESTION**: Specify a more precise condition for the weights, such as `Result.count = total_expected_weights`.
- **DETAILS**: The requirement that `weights.count > 0` is too vague. Properly specifying the total number of weights helps ensure that the network has been properly initialized and trained.
```

## Your Additional Findings

Report additional issues not found by Ollama using same format:

```
**ISSUE**: [Clear description]
**LOCATION**: [ClassName.feature]
**SEVERITY**: [CRITICAL / HIGH / MEDIUM / LOW]
**SUGGESTION**: [How to fix]
**DETAILS**: [Why this matters]
```

## MML Deep Dive Questions

Specifically analyze:

1. **classes_learned Query Consistency**
   - All 5 classification classes implement `classes_learned: MML_SET [INTEGER]`
   - Does the implementation correctly filter learned classes?
   - Is the guard `if is_trained then` sufficient?

2. **Frame Conditions**
   - Linear Regression mentions frame conditions but doesn't implement them
   - Should postconditions explicitly use `old` and `|=|`?
   - What should NOT change during training?

3. **Configuration Method Chaining**
   - All set_* methods return `like Current`
   - Is the contract `Result := Current` sufficient for proving chaining works?
   - What about nested calls like `.set_a().set_b().set_c()`?

4. **Training Data Immutability**
   - Postconditions on `train()` should verify input arrays unchanged
   - Are current postconditions sufficient to express this?
   - Should use MML frame conditions for `a_x` and `a_y`?

5. **State Machine Contracts**
   - Preconditions enforce state (e.g., `trained: is_trained`)
   - Are postconditions sufficient to guarantee state transitions?
   - What about invalid state transitions?

## Output Format

Report findings as structured issues with:
- ISSUE (clear description)
- LOCATION (ClassName.feature)
- SEVERITY (CRITICAL/HIGH/MEDIUM/LOW)
- SUGGESTION (specific fix)
- DETAILS (context and reasoning)

Include any issues from Ollama that you think are important for implementation.

