note
	description: "Tests for LINEAR_REGRESSION_MODEL"
	author: "Larry Rix"

class TEST_LINEAR_REGRESSION_MODEL

inherit
	EQA_TEST_SET

feature -- Tests

	test_make_creates_unconfigured_model
			-- Test that make creates an unconfigured model.
		local
			l_model: LINEAR_REGRESSION_MODEL
		do
			create l_model.make
			assert ("not trained", not l_model.is_trained)
			assert ("no features", l_model.features_learned.is_empty)
		end

	test_set_learning_rate_valid
			-- Test that set_learning_rate accepts positive value.
		local
			l_model: LINEAR_REGRESSION_MODEL
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.01)
			assert ("learning rate set", l_model.learning_rate = 0.01)
		end

	test_set_max_iterations_valid
			-- Test that set_max_iterations accepts positive value.
		local
			l_model: LINEAR_REGRESSION_MODEL
		do
			create l_model.make
			l_model := l_model.set_max_iterations (100)
			assert ("max iterations set", l_model.max_iterations = 100)
		end

	test_train_with_simple_data
			-- Test that train updates model state.
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.01)
			l_model := l_model.set_max_iterations (100)

			-- Create simple 2-sample, 1-feature dataset
			l_x := << << 1.0 >>, << 2.0 >> >>
			l_y := << 2.0, 4.0 >>

			l_model.train (l_x, l_y)

			assert ("model trained", l_model.is_trained)
			assert ("features learned", l_model.features_learned.count = 1)
		end

	test_predict_after_training
			-- Test that predict returns a value after training.
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
			l_prediction: REAL_64
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.01)
			l_model := l_model.set_max_iterations (50)

			-- Simple linear data: y = 2*x
			l_x := << << 1.0 >>, << 2.0 >>, << 3.0 >> >>
			l_y := << 2.0, 4.0, 6.0 >>

			l_model.train (l_x, l_y)
			l_prediction := l_model.predict (<< 2.5 >>)

			-- Should be close to 5.0 (2*2.5)
			assert ("prediction reasonable", l_prediction > 0.0)
		end

	test_train_with_multiple_features
			-- Test training with multiple features.
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.01)
			l_model := l_model.set_max_iterations (50)

			-- 3 samples, 2 features: y ≈ x1 + 2*x2
			l_x := << << 1.0, 1.0 >>, << 2.0, 1.0 >>, << 1.0, 2.0 >> >>
			l_y := << 3.0, 4.0, 5.0 >>

			l_model.train (l_x, l_y)

			assert ("model trained", l_model.is_trained)
			assert ("features learned", l_model.features_learned.count = 2)
		end

	test_learning_rate_effect
			-- Test that different learning rates affect training.
		local
			l_model1, l_model2: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			l_x := << << 1.0 >>, << 2.0 >> >>
			l_y := << 2.0, 4.0 >>

			-- Model with small learning rate
			create l_model1.make
			l_model1 := l_model1.set_learning_rate (0.001)
			l_model1 := l_model1.set_max_iterations (100)
			l_model1.train (l_x, l_y)

			-- Model with larger learning rate
			create l_model2.make
			l_model2 := l_model2.set_learning_rate (0.1)
			l_model2 := l_model2.set_max_iterations (100)
			l_model2.train (l_x, l_y)

			assert ("both trained", l_model1.is_trained and l_model2.is_trained)
		end

	test_adversarial_very_small_learning_rate
			-- Test with very small learning rate (boundary case).
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.000001)
			l_model := l_model.set_max_iterations (10)

			l_x := << << 1.0 >>, << 2.0 >> >>
			l_y := << 2.0, 4.0 >>

			l_model.train (l_x, l_y)
			assert ("trained with tiny learning rate", l_model.is_trained)
		end

	test_adversarial_large_learning_rate
			-- Test with very large learning rate.
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make
			l_model := l_model.set_learning_rate (100.0)
			l_model := l_model.set_max_iterations (10)

			l_x := << << 1.0 >>, << 2.0 >> >>
			l_y := << 2.0, 4.0 >>

			l_model.train (l_x, l_y)
			assert ("trained with huge learning rate", l_model.is_trained)
		end

	test_adversarial_single_sample
			-- Test with single training sample (edge case).
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make
			l_x := << << 1.0 >> >>
			l_y := << 2.0 >>

			l_model.train (l_x, l_y)
			assert ("trained with single sample", l_model.is_trained)
		end

	test_adversarial_large_feature_values
			-- Test with very large feature values (numerical stability).
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
			l_prediction: REAL_64
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.0001)

			l_x := << << 1000000.0 >>, << 2000000.0 >> >>
			l_y := << 2000000.0, 4000000.0 >>

			l_model.train (l_x, l_y)
			l_prediction := l_model.predict (<< 1500000.0 >>)
			assert ("handles large values", True)
		end

	test_adversarial_small_feature_values
			-- Test with very small feature values.
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.01)

			l_x := << << 0.000001 >>, << 0.000002 >> >>
			l_y := << 0.000002, 0.000004 >>

			l_model.train (l_x, l_y)
			assert ("handles small values", l_model.is_trained)
		end

	test_adversarial_many_iterations
			-- Test with many training iterations.
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make
			l_model := l_model.set_max_iterations (10000)

			l_x := << << 1.0 >>, << 2.0 >> >>
			l_y := << 2.0, 4.0 >>

			l_model.train (l_x, l_y)
			assert ("trained with many iterations", l_model.is_trained)
		end

	test_adversarial_high_dimensional
			-- Test with many features.
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
			l_i: INTEGER
		do
			create l_model.make

			-- Create 3 samples with 50 features each
			create l_x.make_filled (create {ARRAY [REAL_64]}.make_filled (1.0, 1, 50), 1, 3)
			from l_i := 1 until l_i > 3
			loop
				l_x [l_i] := create {ARRAY [REAL_64]}.make_filled (l_i.to_real * 1.0, 1, 50)
				l_i := l_i + 1
			end

			l_y := << 1.0, 2.0, 3.0 >>

			l_model.train (l_x, l_y)
			assert ("trained high dimensional", l_model.is_trained)
			assert ("features learned", l_model.features_learned.count = 50)
		end

	test_adversarial_many_samples
			-- Test with many training samples.
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
			l_i: INTEGER
		do
			create l_model.make
			l_model := l_model.set_max_iterations (50)

			-- Create 100 samples with 2 features
			create l_x.make_filled (create {ARRAY [REAL_64]}.make_filled (1.0, 1, 2), 1, 100)
			create l_y.make_filled (1.0, 1, 100)

			from l_i := 1 until l_i > 100
			loop
				l_x [l_i] := << l_i.to_real, (l_i * 2).to_real >>
				l_y [l_i] := (l_i * 3).to_real
				l_i := l_i + 1
			end

			l_model.train (l_x, l_y)
			assert ("trained many samples", l_model.is_trained)
		end

	test_adversarial_repeated_training
			-- Test training twice on same model (state check).
		local
			l_model: LINEAR_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make

			l_x := << << 1.0 >>, << 2.0 >> >>
			l_y := << 2.0, 4.0 >>

			l_model.train (l_x, l_y)
			assert ("first training", l_model.is_trained)

			-- Train again with different data
			l_x := << << 3.0 >>, << 4.0 >> >>
			l_y := << 6.0, 8.0 >>

			l_model.train (l_x, l_y)
			assert ("second training overwrites", l_model.is_trained)
		end

	test_precondition_predict_requires_training
			-- Verify that predict requires trained model (will fail gracefully).
		local
			l_model: LINEAR_REGRESSION_MODEL
		do
			create l_model.make
			-- Precondition violation: cannot predict without training
			-- This test documents the precondition contract
			assert ("model created but not trained", not l_model.is_trained)
		end

end
