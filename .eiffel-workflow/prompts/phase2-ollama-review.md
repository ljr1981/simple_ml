# Eiffel Contract Review Request (Ollama)

**Project:** simple_ml (Machine Learning Library with Design by Contract)
**Date:** 2026-01-29
**Task:** Adversarial contract review to identify design issues before implementation

You are reviewing Eiffel contracts for a formally-verified ML library. The goal is to find obvious problems, ambiguities, and missing specifications that would cause issues during Phase 4 (Implementation).

## Review Checklist

Find and report:
- [ ] Preconditions that are too weak (e.g., just `True`)
- [ ] Postconditions that don't actually constrain behavior
- [ ] Missing preconditions for obvious invalid inputs
- [ ] Missing postconditions on queries (functions)
- [ ] Postconditions that reference uninitialized attributes
- [ ] Invariants that would be violated by the contract
- [ ] Missing invariants (things that should always be true)
- [ ] Missing MML model queries for collection attributes
- [ ] Missing frame conditions (what did NOT change)
- [ ] Specification ambiguities (vague language like "reasonable", "proper", "valid")
- [ ] Edge cases not handled (empty arrays, zero counts, single items)
- [ ] Impossible postconditions (can never be satisfied)
- [ ] Type mismatches or logical errors
- [ ] Inconsistencies between related contracts
- [ ] Features marked as stubs that need full implementation

## Contracts to Review

### LINEAR_REGRESSION_MODEL

```eiffel
note
	description: "Linear regression supervised learning model"
	author: "Larry Rix"

class LINEAR_REGRESSION_MODEL

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured model.
		do
			is_trained := False
			learning_rate := 0.01
			max_iterations := 100
			create weights.make_empty
		ensure
			not_trained: not is_trained
		end

feature -- Model Queries (MML)

	features_learned: MML_SET [INTEGER]
			-- Mathematical model of learned feature indices.
		do
			create Result
			if is_trained then
				across 1 |..| weights.count as ic loop
					Result := Result & ic.item
				end
			end
		end

feature -- Configuration

	set_learning_rate (a_rate: REAL_64): like Current
			-- Set learning rate for gradient descent.
		require
			positive_rate: a_rate > 0.0
		do
			learning_rate := a_rate
			Result := Current
		ensure
			rate_set: learning_rate = a_rate
		end

	set_max_iterations (a_max: INTEGER): like Current
			-- Set maximum iterations for training.
		require
			positive_max: a_max > 0
		do
			max_iterations := a_max
			Result := Current
		ensure
			max_set: max_iterations = a_max
		end

feature -- Training

	train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [REAL_64])
			-- Train model on features `a_x' and target `a_y'.
		require
			x_valid: a_x /= Void and a_x.count > 0
			y_valid: a_y /= Void and a_y.count > 0
			same_length: a_x.count = a_y.count
			x_not_empty: a_x [a_x.lower].count > 0
			learning_rate_set: learning_rate > 0.0
			max_iterations_set: max_iterations > 0
		do
			-- Implementation in Phase 4
		ensure
			is_trained: is_trained
			weights_initialized: weights /= Void and weights.count = a_x [a_x.lower].count
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): REAL_64
			-- Predict target value for features `a_x'.
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count = weights.count
		do
			-- Implementation in Phase 4
		ensure
			-- Result is finite number (IEEE 754 compliant)
		end

	is_trained: BOOLEAN
			-- Has model been trained?

	weights: ARRAY [REAL_64]
			-- Learned weight vector.

	learning_rate: REAL_64
			-- Learning rate for gradient descent.

	max_iterations: INTEGER
			-- Maximum training iterations.

invariant
	weights_valid: is_trained implies weights /= Void and weights.count > 0
	learning_rate_positive: learning_rate > 0.0
	max_iterations_positive: max_iterations > 0

end
```

### LOGISTIC_REGRESSION_MODEL

```eiffel
class LOGISTIC_REGRESSION_MODEL

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured model.
		do
			is_trained := False
			learning_rate := 0.01
			max_iterations := 100
			create weights.make_empty
			create classes.make_empty
		ensure
			not_trained: not is_trained
		end

feature -- Model Queries (MML)

	classes_learned: MML_SET [INTEGER]
			-- Mathematical model of unique classes learned.
		do
			create Result
			if is_trained then
				across classes as ic loop
					Result := Result & ic.item
				end
			end
		end

feature -- Configuration

	set_learning_rate (a_rate: REAL_64): like Current
		require
			positive_rate: a_rate > 0.0
		do
			learning_rate := a_rate
			Result := Current
		ensure
			rate_set: learning_rate = a_rate
		end

	set_max_iterations (a_max: INTEGER): like Current
		require
			positive_max: a_max > 0
		do
			max_iterations := a_max
			Result := Current
		ensure
			max_set: max_iterations = a_max
		end

feature -- Training

	train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
		require
			x_valid: a_x /= Void and a_x.count > 0
			y_valid: a_y /= Void and a_y.count > 0
			same_length: a_x.count = a_y.count
			x_not_empty: a_x [a_x.lower].count > 0
			learning_rate_set: learning_rate > 0.0
			max_iterations_set: max_iterations > 0
		do
			-- Implementation in Phase 4
		ensure
			is_trained: is_trained
			weights_initialized: weights /= Void and weights.count = a_x [a_x.lower].count
			classes_learned_valid: not classes_learned.is_empty
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): INTEGER
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count = weights.count
		do
			-- Implementation in Phase 4
		ensure
			result_valid: classes_learned.has (Result)
		end

	predict_proba (a_x: ARRAY [REAL_64]): REAL_64
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count = weights.count
		do
			-- Implementation in Phase 4
		ensure
			result_in_range: Result >= 0.0 and Result <= 1.0
		end

	is_trained: BOOLEAN
	weights: ARRAY [REAL_64]
	bias: REAL_64
	classes: ARRAY [INTEGER]
	learning_rate: REAL_64
	max_iterations: INTEGER

invariant
	weights_valid: is_trained implies weights /= Void and weights.count > 0
	classes_valid: is_trained implies classes /= Void and classes.count > 0
	learning_rate_positive: learning_rate > 0.0
	max_iterations_positive: max_iterations > 0

end
```

### DECISION_TREE_CLASSIFIER

```eiffel
class DECISION_TREE_CLASSIFIER

create
	make

feature {NONE} -- Initialization

	make
		do
			max_depth := 10
			min_samples_split := 2
			is_trained := False
			create classes.make_empty
		ensure
			not_trained: not is_trained
		end

feature -- Model Queries (MML)

	classes_learned: MML_SET [INTEGER]
		do
			create Result
			if is_trained then
				across classes as ic loop
					Result := Result & ic.item
				end
			end
		end

feature -- Configuration

	set_max_depth (a_depth: INTEGER): like Current
		require
			positive_depth: a_depth > 0
		do
			max_depth := a_depth
			Result := Current
		ensure
			depth_set: max_depth = a_depth
		end

	set_min_samples_split (a_min: INTEGER): like Current
		require
			positive_min: a_min > 0
		do
			min_samples_split := a_min
			Result := Current
		ensure
			min_set: min_samples_split = a_min
		end

feature -- Training

	train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
		require
			x_valid: a_x /= Void and a_x.count > 0
			y_valid: a_y /= Void and a_y.count > 0
			same_length: a_x.count = a_y.count
			x_not_empty: a_x [a_x.lower].count > 0
			max_depth_set: max_depth > 0
			min_samples_set: min_samples_split > 0
		do
			-- Implementation in Phase 4
		ensure
			is_trained: is_trained
			classes_learned_valid: not classes_learned.is_empty
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): INTEGER
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count > 0
		do
			-- Implementation in Phase 4
		ensure
			result_valid: classes_learned.has (Result)
		end

	is_trained: BOOLEAN
	classes: ARRAY [INTEGER]
	max_depth: INTEGER
	min_samples_split: INTEGER

invariant
	classes_valid: is_trained implies classes /= Void and classes.count > 0
	max_depth_positive: max_depth > 0
	min_samples_positive: min_samples_split > 0

end
```

### RANDOM_FOREST_CLASSIFIER

```eiffel
class RANDOM_FOREST_CLASSIFIER

create
	make

feature {NONE} -- Initialization

	make
		do
			num_trees := 100
			max_depth := 10
			is_trained := False
			create classes.make_empty
		ensure
			not_trained: not is_trained
		end

feature -- Model Queries (MML)

	classes_learned: MML_SET [INTEGER]
		do
			create Result
			if is_trained then
				across classes as ic loop
					Result := Result & ic.item
				end
			end
		end

feature -- Configuration

	set_num_trees (a_num: INTEGER): like Current
		require
			positive_num: a_num > 0
		do
			num_trees := a_num
			Result := Current
		ensure
			num_set: num_trees = a_num
		end

	set_max_depth (a_depth: INTEGER): like Current
		require
			positive_depth: a_depth > 0
		do
			max_depth := a_depth
			Result := Current
		ensure
			depth_set: max_depth = a_depth
		end

feature -- Training

	train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
		require
			x_valid: a_x /= Void and a_x.count > 0
			y_valid: a_y /= Void and a_y.count > 0
			same_length: a_x.count = a_y.count
			x_not_empty: a_x [a_x.lower].count > 0
			num_trees_set: num_trees > 0
			max_depth_set: max_depth > 0
		do
			-- Implementation in Phase 4
		ensure
			is_trained: is_trained
			classes_learned_valid: not classes_learned.is_empty
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): INTEGER
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count > 0
		do
			-- Implementation in Phase 4
		ensure
			result_valid: classes_learned.has (Result)
		end

	predict_proba (a_x: ARRAY [REAL_64]): ARRAY [REAL_64]
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count > 0
		do
			create Result.make_empty
			-- Implementation in Phase 4
		ensure
			result_non_void: Result /= Void
		end

	is_trained: BOOLEAN
	classes: ARRAY [INTEGER]
	num_trees: INTEGER
	max_depth: INTEGER

invariant
	classes_valid: is_trained implies classes /= Void and classes.count > 0
	num_trees_positive: num_trees > 0
	max_depth_positive: max_depth > 0

end
```

### SVM_LINEAR

```eiffel
class SVM_LINEAR

create
	make

feature {NONE} -- Initialization

	make
		do
			c_param := 1.0
			tolerance := 0.0001
			is_trained := False
			create weights.make_empty
			create classes.make_empty
		ensure
			not_trained: not is_trained
		end

feature -- Model Queries (MML)

	classes_learned: MML_SET [INTEGER]
		do
			create Result
			if is_trained then
				across classes as ic loop
					Result := Result & ic.item
				end
			end
		end

feature -- Configuration

	set_c_param (a_c: REAL_64): like Current
		require
			positive_c: a_c > 0.0
		do
			c_param := a_c
			Result := Current
		ensure
			c_set: c_param = a_c
		end

	set_tolerance (a_tol: REAL_64): like Current
		require
			positive_tol: a_tol > 0.0
		do
			tolerance := a_tol
			Result := Current
		ensure
			tol_set: tolerance = a_tol
		end

feature -- Training

	train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
		require
			x_valid: a_x /= Void and a_x.count > 0
			y_valid: a_y /= Void and a_y.count > 0
			same_length: a_x.count = a_y.count
			x_not_empty: a_x [a_x.lower].count > 0
			c_param_set: c_param > 0.0
			tolerance_set: tolerance > 0.0
		do
			-- Implementation in Phase 4
		ensure
			is_trained: is_trained
			weights_initialized: weights /= Void and weights.count = a_x [a_x.lower].count
			classes_learned_valid: not classes_learned.is_empty
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): INTEGER
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count = weights.count
		do
			-- Implementation in Phase 4
		ensure
			result_valid: classes_learned.has (Result)
		end

	decision_function (a_x: ARRAY [REAL_64]): REAL_64
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count = weights.count
		do
			-- Implementation in Phase 4
		ensure
			-- Result is finite number
		end

	is_trained: BOOLEAN
	weights: ARRAY [REAL_64]
	bias: REAL_64
	classes: ARRAY [INTEGER]
	c_param: REAL_64
	tolerance: REAL_64

invariant
	weights_valid: is_trained implies weights /= Void and weights.count > 0
	classes_valid: is_trained implies classes /= Void and classes.count > 0
	c_param_positive: c_param > 0.0
	tolerance_positive: tolerance > 0.0

end
```

### NEURAL_NETWORK_CLASSIFIER

```eiffel
class NEURAL_NETWORK_CLASSIFIER

create
	make

feature {NONE} -- Initialization

	make
		do
			learning_rate := 0.01
			max_iterations := 200
			is_trained := False
			create hidden_layer_sizes.make_empty
			create weights.make_empty
			create classes.make_empty
		ensure
			not_trained: not is_trained
		end

feature -- Model Queries (MML)

	classes_learned: MML_SET [INTEGER]
		do
			create Result
			if is_trained then
				across classes as ic loop
					Result := Result & ic.item
				end
			end
		end

feature -- Configuration

	set_hidden_layers (a_sizes: ARRAY [INTEGER]): like Current
		require
			sizes_valid: a_sizes /= Void and a_sizes.count > 0
			all_positive: across a_sizes as sz all sz.item > 0 end
		do
			hidden_layer_sizes := a_sizes.twin
			Result := Current
		ensure
			layers_set: hidden_layer_sizes.count = a_sizes.count
		end

	set_learning_rate (a_rate: REAL_64): like Current
		require
			positive_rate: a_rate > 0.0
		do
			learning_rate := a_rate
			Result := Current
		ensure
			rate_set: learning_rate = a_rate
		end

	set_max_iterations (a_max: INTEGER): like Current
		require
			positive_max: a_max > 0
		do
			max_iterations := a_max
			Result := Current
		ensure
			max_set: max_iterations = a_max
		end

feature -- Training

	train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
		require
			x_valid: a_x /= Void and a_x.count > 0
			y_valid: a_y /= Void and a_y.count > 0
			same_length: a_x.count = a_y.count
			x_not_empty: a_x [a_x.lower].count > 0
			hidden_layers_set: hidden_layer_sizes /= Void and hidden_layer_sizes.count > 0
			learning_rate_set: learning_rate > 0.0
			max_iterations_set: max_iterations > 0
		do
			-- Implementation in Phase 4
		ensure
			is_trained: is_trained
			weights_initialized: weights /= Void and weights.count > 0
			classes_learned_valid: not classes_learned.is_empty
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): INTEGER
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count > 0
		do
			-- Implementation in Phase 4
		ensure
			result_valid: classes_learned.has (Result)
		end

	predict_proba (a_x: ARRAY [REAL_64]): ARRAY [REAL_64]
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count > 0
		do
			create Result.make_empty
			-- Implementation in Phase 4
		ensure
			result_non_void: Result /= Void
		end

	loss: REAL_64
		require
			trained: is_trained
		do
			-- Implementation in Phase 4
		ensure
			result_non_negative: Result >= 0.0
		end

	is_trained: BOOLEAN
	weights: ARRAY [REAL_64]
	classes: ARRAY [INTEGER]
	hidden_layer_sizes: ARRAY [INTEGER]
	learning_rate: REAL_64
	max_iterations: INTEGER

invariant
	weights_valid: is_trained implies weights /= Void and weights.count > 0
	classes_valid: is_trained implies classes /= Void and classes.count > 0
	hidden_layers_valid: hidden_layer_sizes /= Void
	learning_rate_positive: learning_rate > 0.0
	max_iterations_positive: max_iterations > 0

end
```

## Implementation Approach

[See approach.md for full implementation strategy]

Key points:
- Linear/Logistic: Gradient descent-based
- Decision Trees: Recursive splitting with information gain
- Random Forest: Ensemble of decision trees with bootstrap sampling
- SVM: Hinge loss with L2 regularization
- Neural Network: Backpropagation with configurable hidden layers

All classes follow:
1. Builder pattern (fluent API with `like Current` returns)
2. State machine (unconfigured → trained → predictions)
3. MML model queries for learned classes
4. Full contract coverage (require/ensure/invariant on all public features)

## Output Format

Report each issue found as:

```
**ISSUE**: [Clear, concise description]
**LOCATION**: [ClassName.feature_name]
**SEVERITY**: [CRITICAL / HIGH / MEDIUM / LOW]
**SUGGESTION**: [How to fix or improve]
**DETAILS**: [Why this is a problem, examples if needed]
```

## Examples of Good Issues to Find

1. Too-weak precondition:
   - `x_valid: a_x /= Void` doesn't check if it's empty
   - Should also have `a_x.count > 0`

2. Missing postcondition:
   - `set_learning_rate()` only checks the rate was set
   - Should also verify `Result = Current` for fluent API

3. Inconsistent invariants:
   - Linear Regression checks `weights_valid` but Logistic Regression checks `classes_valid`
   - Should both be consistent across all classes

4. Missing specification:
   - `predict_proba()` postcondition doesn't specify range bounds
   - Should be `Result >= 0.0 and Result <= 1.0`

5. Edge cases:
   - What if `a_y` contains only one unique class? (monolithic data)
   - What if learning_rate is extremely small (< epsilon)?

Please review thoroughly and report all issues found.

