note
	description: "Tests for NEURAL_NETWORK_CLASSIFIER"
	author: "Larry Rix"

class TEST_NEURAL_NETWORK_CLASSIFIER

inherit
	EQA_TEST_SET

feature -- Tests

	test_make_creates_unconfigured_model
			-- Test that make creates an unconfigured model.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
		do
			create l_model.make
			assert ("not trained", not l_model.is_trained)
			assert ("no classes", l_model.classes_learned.is_empty)
			assert ("default learning rate", l_model.learning_rate = 0.01)
			assert ("default max iterations", l_model.max_iterations = 200)
		end

	test_set_learning_rate
			-- Test setting learning rate.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.001)
			assert ("learning rate set", l_model.learning_rate = 0.001)
		end

	test_set_max_iterations
			-- Test setting maximum iterations.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
		do
			create l_model.make
			l_model := l_model.set_max_iterations (500)
			assert ("max iterations set", l_model.max_iterations = 500)
		end

	test_set_hidden_layers
			-- Test setting hidden layer sizes.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_sizes: ARRAY [INTEGER]
		do
			create l_model.make
			l_sizes := << 64, 32 >>
			l_model := l_model.set_hidden_layers (l_sizes)
			assert ("hidden layers set", l_model.hidden_layer_sizes.count = 2)
		end

	test_train_neural_network
			-- Test training neural network.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_sizes: ARRAY [INTEGER]
		do
			create l_model.make
			l_sizes := << 8, 4 >>
			l_model := l_model.set_hidden_layers (l_sizes)
			l_model := l_model.set_learning_rate (0.01)
			l_model := l_model.set_max_iterations (100)

			-- Simple dataset for NN training
			l_x := << << 0.0, 0.0 >>, << 1.0, 1.0 >>, << 1.0, 0.0 >>, << 0.0, 1.0 >> >>
			l_y := << 0, 1, 1, 1 >>

			l_model.train (l_x, l_y)

			assert ("model trained", l_model.is_trained)
			assert ("classes learned", l_model.classes_learned.count = 2)
		end

	test_predict_returns_valid_class
			-- Test that predict returns a learned class.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_prediction: INTEGER
			l_sizes: ARRAY [INTEGER]
		do
			create l_model.make
			l_sizes := << 4 >>
			l_model := l_model.set_hidden_layers (l_sizes)
			l_model := l_model.set_learning_rate (0.01)

			l_x := << << 0.0 >>, << 1.0 >>, << 2.0 >> >>
			l_y := << 0, 1, 1 >>

			l_model.train (l_x, l_y)
			l_prediction := l_model.predict (<< 0.5 >>)

			assert ("prediction valid", l_model.classes_learned.has (l_prediction))
		end

	test_predict_proba_returns_distribution
			-- Test that predict_proba returns valid probability distribution.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_probs: ARRAY [REAL_64]
			l_sizes: ARRAY [INTEGER]
			l_i: INTEGER
		do
			create l_model.make
			l_sizes := << 4 >>
			l_model := l_model.set_hidden_layers (l_sizes)

			l_x := << << 0.0 >>, << 1.0 >>, << 2.0 >> >>
			l_y := << 0, 1, 0 >>

			l_model.train (l_x, l_y)
			l_probs := l_model.predict_proba (<< 1.5 >>)

			assert ("probs returned", l_probs.count = l_model.classes_learned.count)

			-- Check each probability is in [0, 1]
			from l_i := l_probs.lower
			until l_i > l_probs.upper
			loop
				assert ("prob in range", l_probs [l_i] >= 0.0 and l_probs [l_i] <= 1.0)
				l_i := l_i + 1
			end
		end

	test_loss_non_negative
			-- Test that loss function returns non-negative value.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_loss: REAL_64
			l_sizes: ARRAY [INTEGER]
		do
			create l_model.make
			l_sizes := << 4 >>
			l_model := l_model.set_hidden_layers (l_sizes)

			l_x := << << 0.0 >>, << 1.0 >> >>
			l_y := << 0, 1 >>

			l_model.train (l_x, l_y)
			l_loss := l_model.loss

			assert ("loss non-negative", l_loss >= 0.0)
		end

	test_adversarial_deep_network
			-- Test with many hidden layers.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_sizes: ARRAY [INTEGER]
		do
			create l_model.make
			l_sizes := << 32, 16, 8, 4 >>
			l_model := l_model.set_hidden_layers (l_sizes)

			l_x := << << 0.0 >>, << 1.0 >>, << 2.0 >> >>
			l_y := << 0, 1, 0 >>

			l_model.train (l_x, l_y)
			assert ("deep network trained", l_model.is_trained)
		end

	test_adversarial_wide_network
			-- Test with very wide hidden layer.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_sizes: ARRAY [INTEGER]
		do
			create l_model.make
			l_sizes := << 256 >>
			l_model := l_model.set_hidden_layers (l_sizes)

			l_x := << << 0.0 >>, << 1.0 >> >>
			l_y := << 0, 1 >>

			l_model.train (l_x, l_y)
			assert ("wide network trained", l_model.is_trained)
		end

	test_adversarial_single_hidden_neuron
			-- Test with minimal hidden layer.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_sizes: ARRAY [INTEGER]
		do
			create l_model.make
			l_sizes := << 1 >>
			l_model := l_model.set_hidden_layers (l_sizes)

			l_x := << << 0.0 >>, << 1.0 >> >>
			l_y := << 0, 1 >>

			l_model.train (l_x, l_y)
			assert ("minimal network trained", l_model.is_trained)
		end

	test_adversarial_many_iterations
			-- Test with many training epochs.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_sizes: ARRAY [INTEGER]
		do
			create l_model.make
			l_sizes := << 8 >>
			l_model := l_model.set_hidden_layers (l_sizes)
			l_model := l_model.set_max_iterations (10000)

			l_x := << << 0.0 >>, << 1.0 >> >>
			l_y := << 0, 1 >>

			l_model.train (l_x, l_y)
			assert ("many iterations trained", l_model.is_trained)
		end

	test_adversarial_high_dimensional_input
			-- Test with many input features.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_sizes: ARRAY [INTEGER]
			l_i: INTEGER
			l_dummy_sample: ARRAY [REAL_64]
			l_sample: ARRAY [REAL_64]
		do
			create l_model.make
			l_sizes := << 16 >>
			l_model := l_model.set_hidden_layers (l_sizes)

			-- Create dummy sample to pass to make_filled
			create l_dummy_sample.make_filled (0.0, 1, 50)
			create l_x.make_filled (l_dummy_sample, 1, 4)
			create l_y.make_filled (0, 1, 4)

			from l_i := 1 until l_i > 4
			loop
				create l_sample.make_filled (l_i.to_real, 1, 50)
				l_x [l_i] := l_sample
				l_y [l_i] := l_i \\ 2
				l_i := l_i + 1
			end

			l_model.train (l_x, l_y)
			assert ("high dimensional input trained", l_model.is_trained)
		end

	test_adversarial_many_classes
			-- Test with many output classes.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_sizes: ARRAY [INTEGER]
			l_i: INTEGER
		do
			create l_model.make
			l_sizes := << 16 >>
			l_model := l_model.set_hidden_layers (l_sizes)

			create l_x.make_filled (create {ARRAY [REAL_64]}.make_filled (1.0, 1, 2), 1, 10)
			create l_y.make_filled (0, 1, 10)

			from l_i := 1 until l_i > 10
			loop
				l_x [l_i] := << l_i.to_real, (l_i * 2).to_real >>
				l_y [l_i] := l_i \\ 5
				l_i := l_i + 1
			end

			l_model.train (l_x, l_y)
			assert ("many classes trained", l_model.is_trained)
		end

	test_adversarial_single_class
			-- Test with single class only.
		local
			l_model: NEURAL_NETWORK_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_sizes: ARRAY [INTEGER]
		do
			create l_model.make
			l_sizes := << 4 >>
			l_model := l_model.set_hidden_layers (l_sizes)

			l_x := << << 0.0 >>, << 1.0 >> >>
			l_y := << 0, 0 >>

			l_model.train (l_x, l_y)
			assert ("single class trained", l_model.is_trained)
		end

end
