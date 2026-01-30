# Adversarial Test Suggestions

**Project:** simple_ml (Machine Learning Library)

## Adversarial Testing Focus Areas

Review the contracts below and suggest adversarial tests for:

1. **Boundary Values**
   - Very small learning rates (1e-10, 1e-6)
   - Very large learning rates (1.0, 100.0)
   - Zero iterations attempt (already blocked by precondition)
   - Single sample training (edge case)
   - Single feature (edge case)

2. **Data Dimension Mismatches**
   - Train with 2 features, predict with 1 feature
   - Train with 1 feature, predict with 2 features
   - Feature count validation

3. **State Transition Violations**
   - Call predict() before training
   - Call train() twice sequentially
   - Modify learning rate after training

4. **Numerical Stability**
   - Very large feature values (1e10)
   - Very small feature values (1e-10)
   - Mixed scale features
   - NaN/Infinity handling

5. **Class/Label Edge Cases**
   - Single class only (degenerate case)
   - Many classes (10+)
   - Repeated identical samples
   - Imbalanced classes (99:1 ratio)

6. **Capacity and Performance**
   - Large datasets (1000+ samples)
   - High dimensional data (100+ features)
   - Many iterations (10000)
   - Memory-intensive training

---

## Key Invariants to Test

All classes have these invariants that should be maintained under adversarial conditions:
- `learning_rate > 0.0` (always positive)
- `max_iterations > 0` (always positive)
- `is_trained` flag correctly reflects training state
- `weights/classes` only populated after training
- Postconditions maintained under stress

## Suggested Test Names

- `test_boundary_very_small_learning_rate`
- `test_boundary_very_large_learning_rate`
- `test_boundary_single_sample`
- `test_boundary_single_feature`
- `test_mismatch_predict_after_dimension_change`
- `test_precondition_predict_untrained`
- `test_stability_large_feature_values`
- `test_stability_small_feature_values`
- `test_stress_many_samples`
- `test_stress_high_dimensional`
- `test_stress_many_iterations`
- `test_edge_case_single_class`
- `test_edge_case_imbalanced_data`
- `test_repeated_training`

---

## Contracts Under Review

### LINEAR_REGRESSION_MODEL
```eiffel
train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [REAL_64])
    require
        x_valid: a_x /= Void and a_x.count > 0
        y_valid: a_y /= Void and a_y.count > 0
        same_length: a_x.count = a_y.count
        x_not_empty: a_x [a_x.lower].count > 0
        learning_rate_set: learning_rate > 0.0
        max_iterations_set: max_iterations > 0
    ensure
        is_trained: is_trained
        weights_initialized: weights /= Void and weights.count = a_x [a_x.lower].count

predict (a_x: ARRAY [REAL_64]): REAL_64
    require
        trained: is_trained
        x_valid: a_x /= Void and a_x.count = weights.count
```

### LOGISTIC_REGRESSION_MODEL
```eiffel
train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
    require
        same_length: a_x.count = a_y.count
        x_not_empty: a_x [a_x.lower].count > 0
    ensure
        is_trained: is_trained
        classes_learned_valid: not classes_learned.is_empty

predict (a_x: ARRAY [REAL_64]): INTEGER
    require
        trained: is_trained
    ensure
        result_valid: classes_learned.has (Result)

predict_proba (a_x: ARRAY [REAL_64]): REAL_64
    ensure
        result_in_range: Result >= 0.0 and Result <= 1.0
```

---

## Attack Vectors

1. **Precondition Bypassing:** Can we violate preconditions? (No - they're enforced)
2. **Postcondition Violations:** Do postconditions hold under stress? (To be tested)
3. **Invariant Violations:** Can we break invariants? (To be tested)
4. **State Machine Attacks:** Unexpected state transitions? (To be tested)
5. **Numerical Instability:** Do algorithms handle extreme values? (To be tested)
