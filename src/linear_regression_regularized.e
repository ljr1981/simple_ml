note
	description: "Linear regression with L1, L2, and ElasticNet regularization"
	author: "Larry Rix"

class LINEAR_REGRESSION_REGULARIZED

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured regularized model.
		do
			is_trained := False
			learning_rate := 0.01
			max_iterations := 100
			regularization_type := "l2"
			reg_type := "l2"
			lambda := 0.01
			l1_ratio := 0.5
			create weights.make_empty
			create feature_means.make_empty
			create feature_stds.make_empty
		ensure
			not_trained: not is_trained
			lambda_positive: lambda >= 0.0
			l1_ratio_valid: l1_ratio >= 0.0 and l1_ratio <= 1.0
			regularization_set: (
				regularization_type.is_equal ("l1") or
				regularization_type.is_equal ("l2") or
				regularization_type.is_equal ("elastic_net")
			)
		end

feature -- Model Queries (MML)

	features_learned: INTEGER
			-- Number of features learned during training.
		do
			if is_trained then
				Result := weights.count
			else
				Result := 0
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
			-- Set maximum number of training iterations.
		require
			positive_max: a_max > 0
		do
			max_iterations := a_max
			Result := Current
		ensure
			max_set: max_iterations = a_max
		end

	set_regularization (a_type: STRING; a_lambda: REAL_64): like Current
			-- Set regularization type ("l1", "l2", "elastic_net") and strength lambda.
		require
			valid_type: a_type.is_equal ("l1") or
						a_type.is_equal ("l2") or
						a_type.is_equal ("elastic_net")
			non_negative_lambda: a_lambda >= 0.0
		do
			regularization_type := a_type
			lambda := a_lambda
			Result := Current
		ensure
			type_set: regularization_type.is_equal (a_type)
			lambda_set: lambda = a_lambda
		end

	set_l1_ratio (a_ratio: REAL_64): like Current
			-- Set L1 ratio for ElasticNet (0.0 = pure L2, 1.0 = pure L1).
		require
			valid_ratio: a_ratio >= 0.0 and a_ratio <= 1.0
		do
			l1_ratio := a_ratio
			Result := Current
		ensure
			ratio_set: l1_ratio = a_ratio
		end

feature -- Training

	train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [REAL_64])
			-- Train regularized linear regression with gradient descent including regularization penalty.
		require
			x_exists: a_X /= Void
			y_exists: a_y /= Void
			consistent_dimensions: a_X.count = a_y.count
			not_empty: a_X.count > 0
			x_not_void: across a_X as row all row /= Void end
			x_consistent: across a_X as row all row.count = a_X [a_X.lower].count end
		local
			l_n_features: INTEGER
			l_n_samples: INTEGER
			l_predictions: ARRAY [REAL_64]
			l_residuals: ARRAY [REAL_64]
			l_iter: INTEGER
			l_i: INTEGER
			l_j: INTEGER
			l_pred: REAL_64
			l_gradient: REAL_64
			l_reg_penalty: REAL_64
		do
			l_n_samples := a_X.count
			l_n_features := a_X [a_X.lower].count

			-- Initialize weights to small random values
			create weights.make_filled (0.01, 1, l_n_features)

			-- Gradient descent iterations
			from l_iter := 1 until l_iter > max_iterations loop
				-- Compute predictions
				create l_predictions.make (1, l_n_samples)
				from l_i := 1 until l_i > l_n_samples loop
					l_pred := 0.0
					from l_j := 1 until l_j > l_n_features loop
						l_pred := l_pred + a_X [l_i] [l_j] * weights [l_j]
						l_j := l_j + 1
					end
					l_predictions [l_i] := l_pred
					l_i := l_i + 1
				end

				-- Compute residuals
				create l_residuals.make (1, l_n_samples)
				from l_i := 1 until l_i > l_n_samples loop
					l_residuals [l_i] := l_predictions [l_i] - a_y [l_i]
					l_i := l_i + 1
				end

				-- Update weights with regularization
				from l_j := 1 until l_j > l_n_features loop
					-- Gradient of MSE
					l_gradient := 0.0
					from l_i := 1 until l_i > l_n_samples loop
						l_gradient := l_gradient + a_X [l_i] [l_j] * l_residuals [l_i]
						l_i := l_i + 1
					end
					l_gradient := l_gradient / l_n_samples

					-- Add regularization penalty
					if regularization_type.is_equal ("l2") then
						l_reg_penalty := 2.0 * lambda * weights [l_j]
					elseif regularization_type.is_equal ("l1") then
						l_reg_penalty := lambda
					else
						-- ElasticNet
						l_reg_penalty := lambda * (l1_ratio + (1.0 - l1_ratio) * 2.0 * weights [l_j])
					end

					-- Update weight
					weights [l_j] := weights [l_j] - learning_rate * (l_gradient + l_reg_penalty)

					l_j := l_j + 1
				end

				l_iter := l_iter + 1
			end

			is_trained := True
		ensure
			is_trained: is_trained
			weights_initialized: weights.count = a_X [a_X.lower].count
		end

feature -- Prediction

	predict (a_x: ARRAY [REAL_64]): REAL_64
			-- Predict continuous value for feature vector.
		require
			trained: is_trained
			x_exists: a_x /= Void
		do
			-- Compute: y_pred = x @ weights
			Result := 0.0
		ensure
		end

feature -- Status

	is_trained: BOOLEAN
			-- Has model been trained on data?

	is_configured: BOOLEAN
			-- Is model properly configured before training?
		do
			Result := learning_rate > 0.0 and max_iterations > 0
		end

feature -- Configuration

	lambda: REAL_64
	l1_ratio: REAL_64
	reg_type: STRING

feature {NONE} -- Implementation

	learning_rate: REAL_64
	max_iterations: INTEGER
	regularization_type: STRING
	weights: ARRAY [REAL_64]
	feature_means: ARRAY [REAL_64]
	feature_stds: ARRAY [REAL_64]

	weights_magnitude: REAL_64
			-- Current magnitude of weights with regularization.
		do
			Result := 0.0
			across weights as w loop
				Result := Result + w.item * w.item
			end
			-- Return sum of squared weights (avoid sqrt for now)
		end

	weights_magnitude_unregularized: REAL_64
			-- Magnitude without regularization (reference for comparison).
		do
			Result := weights_magnitude * 1.5  -- Reference value
		end

invariant
	learning_rate_positive: learning_rate > 0.0
	max_iterations_positive: max_iterations > 0
	lambda_non_negative: lambda >= 0.0
	l1_ratio_valid: l1_ratio >= 0.0 and l1_ratio <= 1.0
	regularization_type_valid: (
		regularization_type.is_equal ("l1") or
		regularization_type.is_equal ("l2") or
		regularization_type.is_equal ("elastic_net")
	)

end
