# Implementation Tasks: simple_ml

**Phase:** 3 - Task Decomposition
**Date:** 2026-01-30
**Status:** Ready for Phase 4 Implementation

---

## Architecture & Dependencies

All 6 algorithm classes follow identical pattern:
- Facade classes with full DBC (Design by Contract)
- Fluent configuration API (set_* methods return `like Current`)
- State machine: unconfigured → trained → predictions
- Integration with simple_linalg, simple_statistics, simple_optimization

**Critical Path:** Linear Regression (foundation) → Logistic Regression → Decision Tree → Random Forest

---

## Task 1: LINEAR_REGRESSION_MODEL - Initialization

**Files:** src/linear_regression_model.e
**Features:** make
**Effort:** 0.5 hours

### Acceptance Criteria
- [ ] Initializes is_trained := False
- [ ] Creates empty weights array
- [ ] Sets default learning_rate (0.01)
- [ ] Sets default max_iterations (100)
- [ ] Postcondition: not_trained verified
- [ ] Invariants satisfied after make

### Implementation Notes
- Initialize weights with `create weights.make_empty`
- Default hyperparameters should match postconditions
- No complex logic - simple state initialization

### Dependencies
None

---

## Task 2: LINEAR_REGRESSION_MODEL - Configuration

**Files:** src/linear_regression_model.e
**Features:** set_learning_rate, set_max_iterations
**Effort:** 0.5 hours

### Acceptance Criteria
- [ ] set_learning_rate: stores parameter and returns Current
- [ ] set_max_iterations: stores parameter and returns Current
- [ ] Both use fluent API (Result := Current)
- [ ] Postconditions verified (rate_set, max_set)
- [ ] Can chain calls: `.set_learning_rate(0.1).set_max_iterations(200)`

### Implementation Notes
- Preconditions enforce positive values (already specified)
- Simple assignment + return Current
- No state modification except target attribute

### Dependencies
None

---

## Task 3: LINEAR_REGRESSION_MODEL - Training

**Files:** src/linear_regression_model.e
**Features:** train
**Effort:** 3 hours

### Acceptance Criteria
- [ ] Accepts a_x (features), a_y (targets)
- [ ] Preconditions: arrays valid, dimensions match, learning_rate > 0
- [ ] Initializes weights array to zero vectors (same dimension as features)
- [ ] Implements gradient descent loop (up to max_iterations)
  - [ ] Computes predictions: y_pred = X @ weights
  - [ ] Computes gradients: grad = X^T @ (y_pred - y) / m
  - [ ] Updates weights: weights -= learning_rate * grad
- [ ] Sets is_trained := true after loop
- [ ] Postconditions verified:
  - [ ] is_trained = true
  - [ ] weights.count == feature_dimension
  - [ ] Result property computes predictions
- [ ] Does NOT modify input arrays (implied immutability)

### Implementation Notes
- Use simple_linalg for matrix operations
- Gradient descent: iterate from 1 to max_iterations
- Vector operations:
  - y_pred[i] = sum(weights[j] * X[i][j] for all j)
  - error[i] = y_pred[i] - y[i]
  - grad[j] = sum(error[i] * X[i][j] for all i) / m
- Early stopping optional (not required by contract)
- From approach.md section 1

### Dependencies
- Task 2 (configuration must be set)
- simple_linalg (matrix operations)

---

## Task 4: LINEAR_REGRESSION_MODEL - Prediction

**Files:** src/linear_regression_model.e
**Features:** predict
**Effort:** 1 hour

### Acceptance Criteria
- [ ] Requires: is_trained = true
- [ ] Requires: a_x.count = weights.count (feature dimension matches)
- [ ] Computes: result = x @ weights (dot product)
- [ ] Postcondition: result_exists (True - any value allowed)
- [ ] Returns single REAL_64 prediction value

### Implementation Notes
- Simple dot product: sum(x[i] * weights[i] for all i)
- From approach.md section 1
- No probability computation (unlike logistic regression)

### Dependencies
- Task 3 (training must have completed)

---

## Task 5: LOGISTIC_REGRESSION_MODEL - Initialization & Configuration

**Files:** src/logistic_regression_model.e
**Features:** make, set_learning_rate, set_max_iterations
**Effort:** 1 hour

### Acceptance Criteria
- [ ] Similar to Linear Regression initialization
- [ ] Creates empty weights AND classes arrays (unlike Linear)
- [ ] Stores bias attribute (initialized to 0.0)
- [ ] Configuration methods follow same pattern as Linear

### Implementation Notes
- Extra: `create classes.make_empty` (track learned class labels)
- bias is separate from weights (important for logistic regression)

### Dependencies
None

---

## Task 6: LOGISTIC_REGRESSION_MODEL - Training

**Files:** src/logistic_regression_model.e
**Features:** train
**Effort:** 4 hours

### Acceptance Criteria
- [ ] Accepts a_x (features), a_y (INTEGER class labels)
- [ ] Extracts unique classes from a_y and stores in classes array
- [ ] Initializes weights to zero (length = feature_dimension)
- [ ] Initializes bias to 0.0
- [ ] Implements gradient descent with sigmoid activation:
  - [ ] Compute logits: z = X @ weights + bias
  - [ ] Compute probabilities: y_pred = sigmoid(z) = 1 / (1 + exp(-z))
  - [ ] Compute gradients:
    - [ ] grad_w = X^T @ (y_pred - y_binary) / m
    - [ ] grad_b = mean(y_pred - y_binary)
  - [ ] Update: weights -= lr * grad_w, bias -= lr * grad_b
- [ ] Sets is_trained := true
- [ ] Postconditions:
  - [ ] is_trained = true
  - [ ] weights.count = feature_dimension
  - [ ] classes_learned not empty
  - [ ] Input arrays unchanged

### Implementation Notes
- Classes array: stores unique class labels in order seen
- sigmoid(z) = 1 / (1 + exp(-z))
- For binary classification: y_binary = (a_y == primary_class ? 1.0 : 0.0)
- For multi-class: could use one-vs-rest or softmax (contract allows flexibility)
- From approach.md section 2

### Dependencies
- Task 5 (configuration)
- simple_statistics (exponential function for sigmoid)

---

## Task 7: LOGISTIC_REGRESSION_MODEL - Prediction

**Files:** src/logistic_regression_model.e
**Features:** predict, predict_proba
**Effort:** 2 hours

### Acceptance Criteria
- [ ] predict(a_x): returns class label from classes array
  - [ ] Precondition: is_trained, a_x.count = weights.count
  - [ ] Postcondition: result in classes_learned
- [ ] predict_proba(a_x): returns probability [0, 1]
  - [ ] Computes: logits = x @ weights + bias
  - [ ] Applies sigmoid: prob = 1 / (1 + exp(-logits))
  - [ ] Postcondition: 0.0 <= result <= 1.0
  - [ ] For binary: prob is probability of positive class

### Implementation Notes
- predict: threshold at 0.5, return classes[0] or classes[1]
- predict_proba: return sigmoid(logits) directly

### Dependencies
- Task 6 (training must complete)

---

## Task 8: DECISION_TREE_CLASSIFIER - Initialization & Configuration

**Files:** src/decision_tree_classifier.e
**Features:** make, set_max_depth, set_min_samples_split, feature_count attribute
**Effort:** 1 hour

### Acceptance Criteria
- [ ] Initializes max_depth, min_samples_split with defaults
- [ ] Creates empty classes array
- [ ] Adds feature_count attribute (initialized to 0)
- [ ] Configuration methods return Current (fluent API)

### Implementation Notes
- feature_count stores training feature dimension for validation
- Will be set during train(), used in predict()

### Dependencies
None

---

## Task 9: DECISION_TREE_CLASSIFIER - Training

**Files:** src/decision_tree_classifier.e
**Features:** train
**Effort:** 5 hours (most complex - recursive tree building)

### Acceptance Criteria
- [ ] Extracts unique classes from a_y
- [ ] Stores feature_count = a_x[lower].count for predict() validation
- [ ] Recursively builds tree with max_depth constraint:
  - [ ] Base cases:
    - [ ] All samples same class → leaf node
    - [ ] Depth reached max_depth → leaf node
    - [ ] Fewer than min_samples_split samples → leaf node
  - [ ] Recursive case:
    - [ ] Try each feature: split samples into two groups
    - [ ] Choose split maximizing information gain
    - [ ] Recurse on left/right with depth+1
- [ ] Stores learned classes in classes array
- [ ] Sets is_trained := true
- [ ] Postconditions:
  - [ ] is_trained = true
  - [ ] classes_learned not empty
  - [ ] feature_count set

### Implementation Notes
- Information gain = entropy(parent) - weighted_avg(entropy(children))
- Entropy(p) = -sum(p_i * log2(p_i)) for each class proportion
- From approach.md section 3

### Dependencies
- Task 8 (configuration)
- simple_statistics (entropy calculation)
- simple_optimization (optional: feature selection heuristic)

---

## Task 10: DECISION_TREE_CLASSIFIER - Prediction

**Files:** src/decision_tree_classifier.e
**Features:** predict
**Effort:** 2 hours

### Acceptance Criteria
- [ ] Requires: is_trained, a_x.count = feature_count (NEW: dimension check)
- [ ] Traverses learned tree from root using feature values
- [ ] Returns class label from leaf node reached
- [ ] Postcondition: result in classes_learned

### Implementation Notes
- Tree structure from training must be stored (implicit in implementation)
- Traverse: at each node, check feature[split_feature] and go left/right
- Return class stored in leaf node

### Dependencies
- Task 9 (tree must be trained)

---

## Task 11: RANDOM_FOREST_CLASSIFIER - Initialization & Configuration

**Files:** src/random_forest_classifier.e
**Features:** make, set_num_trees, set_max_depth
**Effort:** 0.5 hours

### Acceptance Criteria
- [ ] Initializes num_trees (default 100), max_depth
- [ ] Creates empty classes array
- [ ] Configuration methods follow pattern

### Implementation Notes
- Will store array of DECISION_TREE_CLASSIFIER internally

### Dependencies
None

---

## Task 12: RANDOM_FOREST_CLASSIFIER - Training

**Files:** src/random_forest_classifier.e
**Features:** train
**Effort:** 3 hours

### Acceptance Criteria
- [ ] Extracts classes from a_y
- [ ] For each of num_trees:
  - [ ] Bootstrap sample a_x and a_y (sample with replacement)
  - [ ] Create new DECISION_TREE_CLASSIFIER with max_depth
  - [ ] Train tree on bootstrap sample
  - [ ] Store trained tree
- [ ] Sets is_trained := true
- [ ] Postconditions:
  - [ ] is_trained = true
  - [ ] classes_learned not empty

### Implementation Notes
- Bootstrap: random sampling with replacement
- Each tree trained on ~63% of data (statistical property)
- Use simple_randomizer for random index selection

### Dependencies
- Task 11 (configuration)
- Task 10 (DECISION_TREE must be trainable)
- simple_randomizer (bootstrap sampling)

---

## Task 13: RANDOM_FOREST_CLASSIFIER - Prediction

**Files:** src/random_forest_classifier.e
**Features:** predict, predict_proba
**Effort:** 2 hours

### Acceptance Criteria
- [ ] predict(a_x): majority voting across all trees
  - [ ] Call predict() on each trained tree
  - [ ] Count votes for each class
  - [ ] Return class with most votes
  - [ ] Postcondition: result in classes_learned
- [ ] predict_proba(a_x): average probabilities across trees
  - [ ] For each tree: count how many samples in leaf vote for each class
  - [ ] Average across all trees
  - [ ] Return probabilities [0, 1] summing to 1.0
  - [ ] Postcondition:
    - [ ] Result.count = classes_learned.count
    - [ ] Each probability in [0, 1]

### Implementation Notes
- Voting: find max count, break ties consistently
- predict_proba more complex: requires tracking leaf node samples

### Dependencies
- Task 12 (training must complete)

---

## Task 14: SVM_LINEAR - Initialization & Configuration

**Files:** src/svm_linear.e
**Features:** make, set_c_param, set_tolerance
**Effort:** 0.5 hours

### Acceptance Criteria
- [ ] Initializes c_param (default 1.0), tolerance (default 0.0001)
- [ ] Creates empty weights and classes arrays
- [ ] Initializes bias to 0.0
- [ ] Configuration methods follow pattern

### Implementation Notes
- c_param: regularization strength (higher = less regularization)
- tolerance: convergence threshold for optimization

### Dependencies
None

---

## Task 15: SVM_LINEAR - Training

**Files:** src/svm_linear.e
**Features:** train
**Effort:** 4 hours

### Acceptance Criteria
- [ ] Extracts classes from a_y
- [ ] For binary classification (2 classes):
  - [ ] Convert to ±1 labels (class[0] → -1, class[1] → +1)
  - [ ] Initialize weights to zeros (length = features)
  - [ ] Initialize bias to 0.0
  - [ ] Optimize via subgradient descent:
    - [ ] For each iteration:
      - [ ] For each sample i:
        - [ ] Compute margin: margin = y[i] * (x[i] @ w + b)
        - [ ] If margin < 1:
          - [ ] Subgradient includes (-y[i] * x[i], -y[i])
        - [ ] Update: w -= learning_rate * (c_param * subgrad_w + lambda * w)
        - [ ] Update: b -= learning_rate * (c_param * subgrad_b)
      - [ ] Check convergence (tolerance)
- [ ] Sets is_trained := true
- [ ] Postconditions:
  - [ ] is_trained = true
  - [ ] weights.count = feature_dimension
  - [ ] classes_learned not empty

### Implementation Notes
- Hinge loss: max(0, 1 - margin)
- L2 regularization: 0.5 * lambda * ||w||^2 (use lambda = 1/c_param)
- From approach.md section 5

### Dependencies
- Task 14 (configuration)
- simple_optimization (subgradient descent framework)

---

## Task 16: SVM_LINEAR - Prediction

**Files:** src/svm_linear.e
**Features:** predict, decision_function
**Effort:** 1 hour

### Acceptance Criteria
- [ ] decision_function(a_x): raw SVM score
  - [ ] Computes: f = x @ weights + bias
  - [ ] Postcondition: result_exists (any value)
- [ ] predict(a_x): class label
  - [ ] If decision_function >= 0: return classes[1]
  - [ ] If decision_function < 0: return classes[0]
  - [ ] Postcondition: result in classes_learned

### Implementation Notes
- decision_function is the discriminant function
- Sign determines class

### Dependencies
- Task 15 (training)

---

## Task 17: NEURAL_NETWORK_CLASSIFIER - Initialization & Configuration

**Files:** src/neural_network_classifier.e
**Features:** make, set_hidden_layers, set_learning_rate, set_max_iterations
**Effort:** 1 hour

### Acceptance Criteria
- [ ] Initializes learning_rate, max_iterations
- [ ] Creates empty hidden_layer_sizes, weights, classes
- [ ] set_hidden_layers: validates all sizes > 0, stores copy
- [ ] Configuration methods return Current (fluent)

### Implementation Notes
- hidden_layer_sizes: ARRAY[INTEGER] specifying neuron counts per layer
- Example: [64, 32] = input → 64 neurons → 32 neurons → output

### Dependencies
None

---

## Task 18: NEURAL_NETWORK_CLASSIFIER - Training

**Files:** src/neural_network_classifier.e
**Features:** train
**Effort:** 6 hours (most complex - backpropagation)

### Acceptance Criteria
- [ ] Requires: hidden_layer_sizes set and non-empty (precondition enforced)
- [ ] Extracts classes from a_y
- [ ] Initializes network:
  - [ ] Layer architecture: [feature_dim] → [hidden[0]] → ... → [hidden[N]] → [num_classes]
  - [ ] Initialize all weight matrices to small random values
  - [ ] Initialize all biases to zeros
- [ ] Implements backpropagation training:
  - [ ] For each iteration (up to max_iterations):
    - [ ] Forward pass: compute activations through all layers (ReLU for hidden, softmax for output)
    - [ ] Backward pass: compute gradients (chain rule)
    - [ ] Update weights/biases using gradient descent
    - [ ] Optionally track loss for convergence detection
- [ ] Sets is_trained := true
- [ ] Postconditions:
  - [ ] is_trained = true
  - [ ] weights.count > 0 (contains all weight parameters)
  - [ ] classes_learned not empty

### Implementation Notes
- Activation function: ReLU(x) = max(0, x) for hidden layers
- Output: softmax for multi-class (p_i = exp(z_i) / sum(exp(z)))
- Loss: cross-entropy for classification
- From approach.md section 6

### Dependencies
- Task 17 (configuration, hidden_layers must be set)
- simple_statistics (exponential for softmax)
- simple_randomizer (weight initialization)

---

## Task 19: NEURAL_NETWORK_CLASSIFIER - Prediction

**Files:** src/neural_network_classifier.e
**Features:** predict, predict_proba, loss
**Effort:** 2.5 hours

### Acceptance Criteria
- [ ] predict(a_x): forward pass and return argmax class
  - [ ] Propagate x through network
  - [ ] Apply softmax to output layer
  - [ ] Return class with highest probability
- [ ] predict_proba(a_x): return softmax output
  - [ ] Forward pass
  - [ ] Return probability vector
  - [ ] Postcondition: Result.count = classes_learned.count, each in [0,1]
- [ ] loss(a_x): optional - returns training loss (requires training data context)
  - [ ] Postcondition: result >= 0.0

### Implementation Notes
- Forward pass logic mirrors train() forward pass
- softmax(z)[i] = exp(z[i]) / sum(exp(z[j]))

### Dependencies
- Task 18 (network must be trained)

---

## Task 20: MML Model Query - Consistency Across Classes

**Files:** All 6 classes
**Features:** features_learned, classes_learned (where applicable)
**Effort:** 1 hour

### Acceptance Criteria
- [ ] LINEAR_REGRESSION_MODEL.features_learned: returns MML_SET of indices 1..weights.count
- [ ] All 5 classifiers implement classes_learned: MML_SET of class labels learned
- [ ] MML queries use guard: `if is_trained then ... else create empty set`
- [ ] Queries are deterministic (same input → same output)

### Implementation Notes
- MML queries are model functions - they don't modify state
- Used in contracts for frame conditions and state verification

### Dependencies
None (parallel with other tasks)

---

## Summary

**Total Tasks:** 20
**Estimated Implementation Effort:** ~30 hours
**Critical Path:** Task 1 → 3 → 4 (Linear Regression foundation)
**Parallelizable:** All configuration tasks (2, 5, 8, 11, 14, 17) can start immediately

### Task Dependencies Graph

```
Task 1 (LR init) → Task 2 (LR config) → Task 3 (LR train) → Task 4 (LR predict)
                                                          ↓
Task 5 (Logistic init) → Task 6 (Logistic train) → Task 7 (Logistic predict)
                                                      ↓
Task 8 (DT init) → Task 9 (DT train) → Task 10 (DT predict)
                                           ↓
Task 11 (RF init) → Task 12 (RF train) → Task 13 (RF predict)

Task 14 (SVM init) → Task 15 (SVM train) → Task 16 (SVM predict)

Task 17 (NN init) → Task 18 (NN train) → Task 19 (NN predict)

All → Task 20 (MML queries - parallel)
```

---

## Ready for Phase 4?

**Approval Requested:**
✓ All 6 algorithm classes covered
✓ All public features specified
✓ Dependencies clearly marked
✓ Contracts reference included
✓ Implementation notes detailed

**Proceed to Phase 4 (Implementation)?** → User approval required
