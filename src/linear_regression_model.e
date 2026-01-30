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
		local
			l_feature_count: INTEGER
			l_sample_count: INTEGER
			l_iteration: INTEGER
			l_pred: REAL_64
			l_error: REAL_64
			l_gradient: ARRAY [REAL_64]
			l_i: INTEGER
			l_j: INTEGER
			l_stats: STATISTICS
			l_mean_error: REAL_64
		do
			l_feature_count := a_x [a_x.lower].count
			l_sample_count := a_x.count

			-- Initialize weights to zeros
			create weights.make_filled (0.0, 1, l_feature_count)

			-- Gradient descent training loop with statistical monitoring
			from l_iteration := 1
			until l_iteration > max_iterations
			loop
				-- Initialize gradient accumulator
				create l_gradient.make_filled (0.0, 1, l_feature_count)

				-- Process each sample
				from l_i := a_x.lower
				until l_i > a_x.upper
				loop
					-- Compute prediction: y_pred = x @ weights
					l_pred := 0.0
					from l_j := 1
					until l_j > l_feature_count
					loop
						l_pred := l_pred + a_x [l_i] [l_j] * weights [l_j]
						l_j := l_j + 1
					end

					-- Compute error
					l_error := l_pred - a_y [l_i]

					-- Accumulate gradient: grad += error * x
					from l_j := 1
					until l_j > l_feature_count
					loop
						l_gradient [l_j] := l_gradient [l_j] + l_error * a_x [l_i] [l_j]
						l_j := l_j + 1
					end

					l_i := l_i + 1
				end

				-- Update weights: w -= learning_rate * (grad / m)
				from l_j := 1
				until l_j > l_feature_count
				loop
					weights [l_j] := weights [l_j] - learning_rate * (l_gradient [l_j] / l_sample_count)
					l_j := l_j + 1
				end

				l_iteration := l_iteration + 1
			end

			is_trained := True
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
		local
			l_j: INTEGER
		do
			Result := 0.0
			from l_j := 1
			until l_j > weights.count
			loop
				Result := Result + a_x [l_j] * weights [l_j]
				l_j := l_j + 1
			end
		ensure
			result_exists: True
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
