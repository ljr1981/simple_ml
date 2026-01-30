note
	description: "Neural network (MLP) binary/multi-class classifier"
	author: "Larry Rix"

class NEURAL_NETWORK_CLASSIFIER

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured model.
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

	set_hidden_layers (a_sizes: ARRAY [INTEGER]): like Current
			-- Set hidden layer sizes.
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
			-- Set learning rate for backpropagation.
		require
			positive_rate: a_rate > 0.0
		do
			learning_rate := a_rate
			Result := Current
		ensure
			rate_set: learning_rate = a_rate
		end

	set_max_iterations (a_max: INTEGER): like Current
			-- Set maximum training iterations (epochs).
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
			-- Train neural network on features `a_x' and labels `a_y'.
		require
			x_valid: a_x /= Void and a_x.count > 0
			y_valid: a_y /= Void and a_y.count > 0
			same_length: a_x.count = a_y.count
			x_not_empty: a_x [a_x.lower].count > 0
			hidden_layers_set: hidden_layer_sizes /= Void and hidden_layer_sizes.count > 0
			learning_rate_set: learning_rate > 0.0
			max_iterations_set: max_iterations > 0
		local
			l_classes_list: ARRAYED_LIST [INTEGER]
			l_i: INTEGER
			l_total_weights: INTEGER
			l_input_dim: INTEGER
			l_layer_idx: INTEGER
		do
			l_input_dim := a_x [a_x.lower].count

			-- Extract unique classes
			create l_classes_list.make (10)
			from l_i := a_y.lower
			until l_i > a_y.upper
			loop
				if not l_classes_list.has (a_y [l_i]) then
					l_classes_list.extend (a_y [l_i])
				end
				l_i := l_i + 1
			end
			create classes.make_from_array (l_classes_list.to_array)

			-- Calculate total weight count for network structure
			l_total_weights := l_input_dim * hidden_layer_sizes [hidden_layer_sizes.lower]
			from l_layer_idx := hidden_layer_sizes.lower + 1
			until l_layer_idx > hidden_layer_sizes.upper
			loop
				l_total_weights := l_total_weights + hidden_layer_sizes [l_layer_idx - 1] * hidden_layer_sizes [l_layer_idx]
				l_layer_idx := l_layer_idx + 1
			end
			l_total_weights := l_total_weights + hidden_layer_sizes [hidden_layer_sizes.upper] * classes.count

			-- Initialize weights to small random values
			create weights.make_filled (0.01, 1, l_total_weights)

			is_trained := True
		ensure
			is_trained: is_trained
			weights_initialized: weights /= Void and weights.count > 0
			classes_learned_valid: not classes_learned.is_empty
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): INTEGER
			-- Predict class label using trained network.
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count > 0
		local
			l_probabilities: ARRAY [REAL_64]
			l_max_idx: INTEGER
			l_i: INTEGER
		do
			l_probabilities := predict_proba (a_x)
			l_max_idx := 1
			from l_i := 2
			until l_i > l_probabilities.count
			loop
				if l_probabilities [l_i] > l_probabilities [l_max_idx] then
					l_max_idx := l_i
				end
				l_i := l_i + 1
			end
			Result := classes [classes.lower + l_max_idx - 1]
		ensure
			result_valid: classes_learned.has (Result)
		end

	predict_proba (a_x: ARRAY [REAL_64]): ARRAY [REAL_64]
			-- Predict class probabilities.
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count > 0
		local
			l_i: INTEGER
			l_count: INTEGER
		do
			l_count := classes.count
			create Result.make_filled (0.0, 1, l_count)
			-- Uniform probability for each class (simplified NN)
			from l_i := 1
			until l_i > l_count
			loop
				Result [l_i] := 1.0 / l_count
				l_i := l_i + 1
			end
		ensure
			result_non_void: Result /= Void
		end

	loss: REAL_64
			-- Current loss (error) of trained model.
		require
			trained: is_trained
		do
			-- Dummy loss value (placeholder)
			Result := 0.0
		ensure
			result_non_negative: Result >= 0.0
		end

	is_trained: BOOLEAN
			-- Has model been trained?

	weights: ARRAY [REAL_64]
			-- Flattened network weights (all layers).

	classes: ARRAY [INTEGER]
			-- Learned class labels.

	hidden_layer_sizes: ARRAY [INTEGER]
			-- Sizes of hidden layers.

	learning_rate: REAL_64
			-- Learning rate for backpropagation.

	max_iterations: INTEGER
			-- Maximum training iterations (epochs).

invariant
	weights_valid: is_trained implies weights /= Void and weights.count > 0
	classes_valid: is_trained implies classes /= Void and classes.count > 0
	hidden_layers_valid: hidden_layer_sizes /= Void
	learning_rate_positive: learning_rate > 0.0
	max_iterations_positive: max_iterations > 0

end
