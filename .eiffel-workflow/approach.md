# Implementation Approach: simple_ml

**Date:** 2026-01-29
**Phase:** 2 (Adversarial Review → Approach Sketch)
**Status:** Ready for Review

---

## Architecture Overview

### Layer Model

```
User Code (Eiffel)
    ↓ calls
Facade Classes (e.g., LINEAR_REGRESSION_MODEL)
    ├ with full Design by Contract
    ├ Configuration via builder pattern
    ├ Training via simple_optimization
    ├ Matrix ops via simple_linalg
    └ Statistics via simple_statistics
```

### 6 Core Algorithm Classes

Each algorithm follows identical pattern:

**PUBLIC INTERFACE:**
- `make` → Create unconfigured model
- `set_*()` → Configure hyperparameters (fluent API, return `like Current`)
- `train(a_x, a_y)` → Train model, transition `is_trained := true`
- `predict(a_x)` → Make predictions (requires `trained`)
- Optional: `predict_proba()`, `loss()`, `feature_importance()`

**INTERNAL STATE:**
- Configuration attributes (learning_rate, max_iterations, etc.)
- Model attributes (weights, classes, bias)
- Status flag (is_trained)
- MML model queries for tracking learned classes

**CONTRACTS:**
- Preconditions: Validate input arrays, check configuration
- Postconditions: Verify state transitions, model initialization
- Invariants: Guard learned state consistency

---

## Algorithm-Specific Implementation Plans

### 1. LINEAR_REGRESSION_MODEL

**Training Algorithm:**
1. Initialize weights to zeros (or small random values)
2. For each iteration (max_iterations):
   a. Compute predictions: y_pred = X @ weights
   b. Compute gradients: grad = X^T @ (y_pred - y) / m
   c. Update weights: weights -= learning_rate * grad
   d. Check convergence (optional early stopping)

**Prediction:**
- y_pred = x @ weights

**Dependencies:**
- simple_linalg: Matrix multiplication (@ operator)
- simple_optimization: Gradient descent loop (or custom)

**Contracts to Satisfy:**
- Precondition: `x_valid`, `y_valid`, `same_length`, learning_rate > 0
- Postcondition: `is_trained`, `weights.count == feature_dim`
- Invariant: `weights_valid` when trained

---

### 2. LOGISTIC_REGRESSION_MODEL

**Training Algorithm:**
1. Initialize weights and bias to zeros
2. For each iteration:
   a. Compute logits: z = X @ weights + bias
   b. Compute probabilities: y_pred = sigmoid(z)
   c. Compute gradients:
      - grad_w = X^T @ (y_pred - y) / m
      - grad_b = mean(y_pred - y)
   d. Update: weights -= lr * grad_w; bias -= lr * grad_b

**Prediction:**
- logits = x @ weights + bias
- prob = sigmoid(logits)
- class = argmax([1-prob, prob])

**Auxiliary Methods:**
- `sigmoid(z) = 1 / (1 + exp(-z))`
- `predict_proba()` → sigmoid(logits)

**Dependencies:**
- simple_linalg: Matrix ops
- simple_statistics: Sigmoid approximation (or custom)

**Contracts to Satisfy:**
- Precondition: y values are integers (class labels)
- Postcondition: `bias.is_finite`, `classes_learned.count > 0`

---

### 3. DECISION_TREE_CLASSIFIER

**Training Algorithm:**
1. Build tree recursively from root node
2. At each node:
   a. Try all features and thresholds
   b. For each split, compute information gain (entropy reduction)
   c. Choose split with max gain
   d. If gain < threshold OR depth >= max_depth OR samples < min_split: make leaf
   e. Recursively build left/right subtrees

**Prediction:**
- Traverse tree from root based on feature values
- Return class at leaf node

**Feature Importance:**
- Sum information gain contributed by each feature

**Dependencies:**
- simple_statistics: Entropy calculation
- simple_random: Optional sample selection

**Contracts to Satisfy:**
- Precondition: `max_depth > 0`, `min_samples_split > 0`
- Postcondition: `classes_learned` contains all unique y values
- Invariant: `max_depth` and `min_samples_split` positive

---

### 4. RANDOM_FOREST_CLASSIFIER

**Training Algorithm:**
1. Create `num_trees` decision trees
2. For each tree i:
   a. Bootstrap sample from training data (sample with replacement)
   b. At each node, consider only random subset of features
   c. Build tree with max_depth
3. Store all trees

**Prediction:**
- For each tree, get prediction
- Return majority vote among trees
- For `predict_proba()`: count votes per class, normalize

**Dependencies:**
- DECISION_TREE_CLASSIFIER: Reuse tree building logic
- simple_randomizer: Random sampling for bootstrap

**Contracts to Satisfy:**
- Precondition: `num_trees > 0`
- Postcondition: All trees trained, classes tracked
- Invariant: `num_trees > 0`

---

### 5. SVM_LINEAR

**Training Algorithm:**
1. Use simplified gradient-based approach (vs full SMO):
   a. Initialize weights and bias to zeros
   b. For each iteration:
      - For each sample, compute hinge loss: max(0, 1 - y * (w·x + b))
      - Compute gradient for misclassified samples
      - Update: w -= lr * grad; b -= lr * grad_b
      - Add L2 regularization: w -= lr * c_param * w
   c. Stop when loss converges or max iterations reached

**Prediction:**
- decision = x @ weights + bias
- class = sign(decision)

**Auxiliary Methods:**
- `decision_function()` → raw score before sign

**Dependencies:**
- simple_linalg: Dot product, vector operations
- simple_statistics: For numerical stability checks

**Contracts to Satisfy:**
- Precondition: `c_param > 0`, `tolerance > 0`
- Postcondition: `decision_function()` returns finite values

---

### 6. NEURAL_NETWORK_CLASSIFIER

**Training Algorithm (Backpropagation with Stochastic Gradient Descent):**

Architecture: Input → Hidden Layers (configurable sizes) → Output

1. Initialize weights randomly (small values), biases to zero
2. For each epoch (max_iterations):
   a. **Forward pass:**
      - For each hidden layer: h = ReLU(W @ prev_layer + b)
      - For output layer: logits = W @ h_final + b
      - Softmax for multiclass: y_pred = softmax(logits)

   b. **Compute loss:**
      - Cross-entropy for classification
      - Accumulate for epoch

   c. **Backward pass:**
      - Compute gradients using chain rule (backpropagation)
      - Update all weights and biases: w -= lr * grad_w; b -= lr * grad_b

3. Early stopping option: Stop if loss plateaus

**Prediction:**
- Forward pass without backprop
- Return argmax of output layer for class
- For `predict_proba()`: return softmax(output)

**Auxiliary Methods:**
- `loss()` → current cross-entropy loss

**Dependencies:**
- simple_linalg: Matrix ops for forward/backward
- simple_optimization: Optional: reuse gradient descent structure

**Contracts to Satisfy:**
- Precondition: `hidden_layer_sizes.count > 0`, all sizes > 0
- Postcondition: `weights.count > 0`, all weights finite
- Invariant: `hidden_layers_valid`

---

## Shared Implementation Patterns

### 1. MML Model Queries

All classes implement:
```eiffel
classes_learned: MML_SET [INTEGER]
    -- Mathematical model of learned classes
```

Implementation pattern:
```eiffel
do
    create Result
    if is_trained then
        across classes as ic loop
            Result := Result & ic.item
        end
    end
end
```

### 2. Builder Pattern (Fluent API)

Configuration methods return `like Current`:
```eiffel
set_learning_rate (a_rate: REAL_64): like Current
    do
        learning_rate := a_rate
        Result := Current
    ensure
        rate_set: learning_rate = a_rate
    end
```

Enables chaining:
```eiffel
model.set_learning_rate(0.01).set_max_iterations(100).set_...
```

### 3. Training Data Immutability

Postconditions verify input arrays unchanged:
```eiffel
ensure
    x_unchanged: across a_x as ic all ic.item.count = old a_x [ic.item_lower].count end
```

Protects against accidental data modification.

### 4. State Transitions

All models follow state machine:
```
CREATED (is_trained := false)
    ↓ train()
TRAINED (is_trained := true)
    ↓ predict()
PREDICTION
```

Preconditions enforce valid states.

---

## Integration Points

### With simple_linalg
- Matrix multiplication for forward passes
- Transpose operations
- Dot products for predictions

### With simple_optimization
- Potential reuse of GRADIENT_DESCENT_SOLVER
- Or: Implement custom gradient descent in Phase 4

### With simple_statistics
- Entropy calculation (decision trees)
- Sigmoid approximation (logistic regression)
- Numerical stability checks

### With simple_randomizer
- Random sampling for train/test splits (future)
- Bootstrap sampling (random forest)
- Weight initialization (neural network)

### With simple_mml
- MML_SET model queries for learned classes
- Frame conditions in postconditions

---

## Testing Strategy (Phase 5)

### Unit Tests (Per Algorithm)
1. Creation: `make` creates unconfigured model
2. Configuration: Setting hyperparameters works
3. Training: Model trains on small dataset, `is_trained` becomes true
4. Prediction: Trained model can predict
5. Fluent API: Method chaining works

### Integration Tests
1. Cross-library: Test simple_linalg integration
2. Data pipeline: Full train/predict cycle
3. Reference validation: Compare outputs vs scikit-learn/R (within epsilon)

### Edge Case Tests
1. Single-sample datasets
2. All same-class data
3. Extreme hyperparameter values
4. Maximum array sizes

---

## Numerical Stability Considerations

### Gradient Descent (Linear/Logistic/SVM)
- Use learning rate decay if needed
- Clip gradients to prevent overflow
- Normalize features for better convergence (future)

### Neural Network
- Initialize weights with small random values (Xavier/He initialization - Phase 2+)
- Use momentum to smooth updates (future)
- Monitor for NaN/Inf in loss and weights

### Decision Trees
- Handle division by zero in entropy calculation
- Prevent infinite recursion with depth limit

---

## Performance Expectations

### CPU-Only MVP (Phase 1-3)
- Linear Regression: 100 samples × 10 features → <1 second
- Logistic Regression: 100 samples × 10 features → <1 second
- Decision Tree: 100 samples × 10 features → <0.5 seconds
- Random Forest (100 trees): 100 samples × 10 features → <5 seconds
- SVM: 100 samples × 10 features → <2 seconds
- Neural Network (1 hidden layer, 32 units): 100 samples × 10 features → <5 seconds

### GPU Acceleration (Phase 1.5)
- Expected: 5-20x speedup via cuBLAS and cuDNN
- Targets: 5070 Ti, 4090, A100, H100

---

## Known Limitations (MVP)

1. **Single-threaded**: No parallelization within algorithms
2. **In-memory**: Cannot train on datasets > available RAM
3. **Simple optimizers**: No momentum, Adam, or advanced schedulers
4. **Basic NN**: Single output type (classification), no Conv/RNN
5. **No hyperparameter tuning**: Grid search only (future)
6. **No feature engineering**: Raw numeric features only

---

## Success Criteria

By end of Phase 4 (Implementation), all 6 algorithms must:

✓ Compile with zero warnings
✓ Satisfy all contracts (pre/post/invariant)
✓ Train on sample datasets
✓ Make predictions matching contracts
✓ Handle edge cases without crashing
✓ Produce results within epsilon of reference implementations

By end of Phase 6 (Hardening):
✓ All 18+ tests pass
✓ Adversarial tests stress-tested
✓ CPU ≈ GPU results (within IEEE 754 epsilon, Phase 1.5)
✓ Documentation complete
✓ Ready for v1.0.0 release

---

## Implementation Order (Phase 4)

**Priority 1 (Foundation):**
1. LINEAR_REGRESSION_MODEL
2. LOGISTIC_REGRESSION_MODEL

**Priority 2 (Decision Trees):**
3. DECISION_TREE_CLASSIFIER
4. RANDOM_FOREST_CLASSIFIER (depends on Decision Tree)

**Priority 3 (Advanced):**
5. SVM_LINEAR
6. NEURAL_NETWORK_CLASSIFIER

This order allows testing of simpler algorithms before tackling complex ensemble and neural network implementations.

---

## Key Design Decisions

1. **Fluent API**: Configuration methods return `like Current` for chaining
2. **MML Queries**: All classes expose learned state via MML_SET
3. **Immutability**: Input arrays remain unchanged (verified in contracts)
4. **State Machine**: Trained/untrained states enforced via preconditions
5. **CPU-First**: MVP focuses on verification; Phase 1.5 adds GPU
6. **Simplicity**: Linear/logistic regression before advanced techniques

---
