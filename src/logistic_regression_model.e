note
	description: "Logistic regression binary classification model"
	author: "Larry Rix"

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

	train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Train model on features `a_x' and class labels `a_y'.
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
			l_classes_list: ARRAYED_LIST [INTEGER]
			l_iteration: INTEGER
			l_i: INTEGER
			l_j: INTEGER
			l_logit: REAL_64
			l_prob: REAL_64
			l_error: REAL_64
			l_gradient: ARRAY [REAL_64]
			l_grad_bias: REAL_64
		do
			l_feature_count := a_x [a_x.lower].count
			l_sample_count := a_x.count

			-- Extract unique classes
			create l_classes_list.make (2)
			from l_i := a_y.lower
			until l_i > a_y.upper
			loop
				if not l_classes_list.has (a_y [l_i]) then
					l_classes_list.extend (a_y [l_i])
				end
				l_i := l_i + 1
			end
			create classes.make_from_array (l_classes_list.to_array)

			-- Initialize weights and bias to zeros
			create weights.make_filled (0.0, 1, l_feature_count)
			bias := 0.0

			-- Gradient descent training loop
			from l_iteration := 1
			until l_iteration > max_iterations
			loop
				-- Initialize gradient accumulator
				create l_gradient.make_filled (0.0, 1, l_feature_count)
				l_grad_bias := 0.0

				-- Process each sample
				from l_i := a_y.lower
				until l_i > a_y.upper
				loop
					-- Compute logits: z = x @ weights + bias
					l_logit := bias
					from l_j := 1
					until l_j > l_feature_count
					loop
						l_logit := l_logit + a_x [l_i] [l_j] * weights [l_j]
						l_j := l_j + 1
					end

					-- Compute sigmoid using linear approximation
					if l_logit > 5.0 then
						l_prob := 1.0
					elseif l_logit < -5.0 then
						l_prob := 0.0
					else
						-- Linear approximation near 0: sigmoid(z) ≈ 0.5 + 0.125*z
						l_prob := 0.5 + (0.125 * l_logit)
					end

					-- Binary error (assume first class is 0, second is 1)
					if a_y [l_i] = classes [classes.lower] then
						l_error := l_prob - 0.0
					else
						l_error := l_prob - 1.0
					end

					-- Accumulate gradients
					from l_j := 1
					until l_j > l_feature_count
					loop
						l_gradient [l_j] := l_gradient [l_j] + l_error * a_x [l_i] [l_j]
						l_j := l_j + 1
					end
					l_grad_bias := l_grad_bias + l_error

					l_i := l_i + 1
				end

				-- Update weights: w -= learning_rate * (grad / m)
				from l_j := 1
				until l_j > l_feature_count
				loop
					weights [l_j] := weights [l_j] - learning_rate * (l_gradient [l_j] / l_sample_count)
					l_j := l_j + 1
				end

				-- Update bias
				bias := bias - learning_rate * (l_grad_bias / l_sample_count)

				l_iteration := l_iteration + 1
			end

			is_trained := True
		ensure
			is_trained: is_trained
			weights_initialized: weights /= Void and weights.count = a_x [a_x.lower].count
			classes_learned_valid: not classes_learned.is_empty
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): INTEGER
			-- Predict class label for features `a_x'.
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count = weights.count
		local
			l_prob: REAL_64
		do
			l_prob := predict_proba (a_x)
			if l_prob < 0.5 then
				Result := classes [classes.lower]
			else
				Result := classes [classes.upper]
			end
		ensure
			result_valid: classes_learned.has (Result)
		end

	predict_proba (a_x: ARRAY [REAL_64]): REAL_64
			-- Predict probability for positive class.
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count = weights.count
		local
			l_logit: REAL_64
			l_j: INTEGER
		do
			-- Compute logits: z = x @ weights + bias
			l_logit := bias
			from l_j := 1
			until l_j > weights.count
			loop
				l_logit := l_logit + a_x [l_j] * weights [l_j]
				l_j := l_j + 1
			end

			-- Compute sigmoid using linear approximation
			if l_logit > 5.0 then
				Result := 1.0
			elseif l_logit < -5.0 then
				Result := 0.0
			else
				-- Linear approximation near 0: sigmoid(z) ≈ 0.5 + 0.125*z
				Result := 0.5 + (0.125 * l_logit)
			end
		ensure
			result_in_range: Result >= 0.0 and Result <= 1.0
		end

	is_trained: BOOLEAN
			-- Has model been trained?

	weights: ARRAY [REAL_64]
			-- Learned weight vector.

	bias: REAL_64
			-- Learned bias term.

	classes: ARRAY [INTEGER]
			-- Learned class labels.

	learning_rate: REAL_64
			-- Learning rate for gradient descent.

	max_iterations: INTEGER
			-- Maximum training iterations.

invariant
	weights_valid: is_trained implies weights /= Void and weights.count > 0
	classes_valid: is_trained implies classes /= Void and classes.count > 0
	learning_rate_positive: learning_rate > 0.0
	max_iterations_positive: max_iterations > 0

end
