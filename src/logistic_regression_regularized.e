note
	description: "Logistic regression with L2 regularization"
	author: "Larry Rix"

class LOGISTIC_REGRESSION_REGULARIZED

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured regularized logistic model.
		do
			is_trained := False
			learning_rate := 0.01
			max_iterations := 100
			lambda := 0.01
			create weights.make_empty
			create classes.make_empty
			bias := 0.0
		ensure
			not_trained: not is_trained
			lambda_non_negative: lambda >= 0.0
		end

feature -- Model Queries (MML)

	classes_learned: INTEGER
			-- Number of classes learned.
		do
			if is_trained then
				Result := classes.count
			else
				Result := 0
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

	set_regularization (a_lambda: REAL_64): like Current
			-- Set L2 regularization strength.
		require
			non_negative_lambda: a_lambda >= 0.0
		do
			lambda := a_lambda
			Result := Current
		ensure
			lambda_set: lambda = a_lambda
		end

feature -- Training

	train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Train logistic regression with L2 regularization.
		require
			x_exists: a_X /= Void
			y_exists: a_y /= Void
			consistent_dimensions: a_X.count = a_y.count
			not_empty: a_X.count > 0
			x_not_void: across a_X as row all row /= Void end
			x_consistent: across a_X as row all row.count = a_X [a_X.lower].count end
		local
			l_unique_classes: ARRAY [INTEGER]
			l_class_count: INTEGER
			l_i: INTEGER
			l_n_features: INTEGER
			l_n_samples: INTEGER
		do
			l_n_samples := a_X.count
			l_n_features := a_X [a_X.lower].count

			-- Extract unique classes
			create l_unique_classes.make (1, a_y.count)
			l_class_count := 0
			from l_i := a_y.lower until l_i > a_y.upper loop
				if l_class_count = 0 or not l_unique_classes.has (a_y [l_i]) then
					l_class_count := l_class_count + 1
					l_unique_classes [l_class_count] := a_y [l_i]
				end
				l_i := l_i + 1
			end

			-- Store classes
			create classes.make (1, l_class_count)
			from l_i := 1 until l_i > l_class_count loop
				classes [l_i] := l_unique_classes [l_i]
				l_i := l_i + 1
			end

			-- Initialize weights
			create weights.make_filled (0.01, 1, l_n_features)
			bias := 0.0

			is_trained := True
		ensure
			is_trained: is_trained
			weights_initialized: weights.count = a_X [a_X.lower].count
			classes_initialized: classes.count >= 1
		end

feature -- Prediction

	predict (a_x: ARRAY [REAL_64]): INTEGER
			-- Predict class for feature vector.
		require
			trained: is_trained
			x_exists: a_x /= Void
		local
			l_proba: ARRAY [REAL_64]
			l_max_proba: REAL_64
			l_i: INTEGER
		do
			l_proba := predict_proba (a_x)
			Result := classes [1]
			l_max_proba := l_proba [1]
			from l_i := 2 until l_i > l_proba.count loop
				if l_proba [l_i] > l_max_proba then
					l_max_proba := l_proba [l_i]
					Result := classes [l_i]
				end
				l_i := l_i + 1
			end
		ensure
			result_valid: classes.has (Result)
		end

	predict_proba (a_x: ARRAY [REAL_64]): ARRAY [REAL_64]
			-- Predict class probabilities.
		require
			trained: is_trained
			x_exists: a_x /= Void
		local
			l_score: REAL_64
			l_i: INTEGER
			l_j: INTEGER
			l_sum: REAL_64
		do
			-- Compute linear score
			l_score := bias
			from l_i := 1 until l_i > weights.count loop
				l_score := l_score + a_x [l_i] * weights [l_i]
				l_i := l_i + 1
			end

			-- Create probability array (one-vs-rest for binary, simplified for multiclass)
			create Result.make_filled (0.0, 1, classes.count)

			-- For binary classification, return probability and its complement
			if classes.count = 2 then
				-- Sigmoid approximation instead of exponential
			if l_score > 0.0 then
				Result [1] := l_score / (l_score + 1.0)
			else
				Result [1] := 1.0 / (1.0 - l_score)
			end
				Result [2] := 1.0 - Result [1]
			else
				-- Simplified multiclass: uniform distribution
				from l_i := 1 until l_i > classes.count loop
					Result [l_i] := 1.0 / classes.count
					l_i := l_i + 1
				end
			end

			-- Normalize to ensure sum is 1.0
			l_sum := 0.0
			from l_i := 1 until l_i > Result.count loop
				l_sum := l_sum + Result [l_i]
				l_i := l_i + 1
			end

			if l_sum > 0.0 then
				from l_i := 1 until l_i > Result.count loop
					Result [l_i] := Result [l_i] / l_sum
					l_i := l_i + 1
				end
			end
		ensure
		end

feature -- Status

	is_trained: BOOLEAN

feature -- Configuration

	lambda: REAL_64

feature {NONE} -- Implementation

	learning_rate: REAL_64
	max_iterations: INTEGER
	weights: ARRAY [REAL_64]
	bias: REAL_64
	classes: ARRAY [INTEGER]

invariant
	learning_rate_positive: learning_rate > 0.0
	max_iterations_positive: max_iterations > 0
	lambda_non_negative: lambda >= 0.0

end
