note
	description: "Tests for LOGISTIC_REGRESSION_MODEL"
	author: "Larry Rix"

class TEST_LOGISTIC_REGRESSION_MODEL

inherit
	EQA_TEST_SET

feature -- Tests

	test_make_creates_unconfigured_model
			-- Test that make creates an unconfigured model.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
		do
			create l_model.make
			assert ("not trained", not l_model.is_trained)
			assert ("no classes", l_model.classes_learned.is_empty)
		end

	test_set_learning_rate_valid
			-- Test that set_learning_rate accepts positive value.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.01)
			assert ("learning rate set", l_model.learning_rate = 0.01)
		end

	test_set_max_iterations_valid
			-- Test that set_max_iterations accepts positive value.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
		do
			create l_model.make
			l_model := l_model.set_max_iterations (100)
			assert ("max iterations set", l_model.max_iterations = 100)
		end

	test_train_binary_classification
			-- Test binary classification training.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.01)
			l_model := l_model.set_max_iterations (100)

			-- Binary classification: feature -> class 0 or 1
			l_x := << << 0.5 >>, << 1.5 >>, << 2.5 >>, << 3.5 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)

			assert ("model trained", l_model.is_trained)
			assert ("classes learned", l_model.classes_learned.count = 2)
		end

	test_predict_returns_valid_class
			-- Test that predict returns a learned class.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_prediction: INTEGER
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.01)
			l_model := l_model.set_max_iterations (100)

			l_x := << << 0.5 >>, << 1.5 >>, << 2.5 >>, << 3.5 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)
			l_prediction := l_model.predict (<< 1.0 >>)

			assert ("prediction valid", l_model.classes_learned.has (l_prediction))
		end

	test_predict_proba_in_range
			-- Test that predict_proba returns values in [0,1].
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_prob: REAL_64
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.01)
			l_model := l_model.set_max_iterations (50)

			l_x := << << 0.0 >>, << 1.0 >>, << 2.0 >> >>
			l_y := << 0, 0, 1 >>

			l_model.train (l_x, l_y)
			l_prob := l_model.predict_proba (<< 1.0 >>)

			assert ("probability in range", l_prob >= 0.0 and l_prob <= 1.0)
		end

	test_train_multiclass
			-- Test training with multiple classes.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.01)
			l_model := l_model.set_max_iterations (100)

			-- Multiclass: 3 classes
			l_x := << << 0.0 >>, << 1.0 >>, << 2.0 >>, << 3.0 >>, << 4.0 >>, << 5.0 >> >>
			l_y := << 0, 0, 1, 1, 2, 2 >>

			l_model.train (l_x, l_y)

			assert ("model trained", l_model.is_trained)
			assert ("classes learned", l_model.classes_learned.count = 3)
		end

	test_adversarial_very_small_learning_rate
			-- Test with very small learning rate.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.0000001)

			l_x := << << 0.0 >>, << 1.0 >>, << 2.0 >>, << 3.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)
			assert ("trained with tiny lr", l_model.is_trained)
		end

	test_adversarial_large_learning_rate
			-- Test with very large learning rate.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_learning_rate (100.0)

			l_x := << << 0.0 >>, << 1.0 >>, << 2.0 >>, << 3.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)
			assert ("trained with huge lr", l_model.is_trained)
		end

	test_adversarial_single_sample
			-- Test with single training sample.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make

			l_x := << << 1.0 >> >>
			l_y := << 0 >>

			l_model.train (l_x, l_y)
			assert ("trained with single sample", l_model.is_trained)
		end

	test_adversarial_imbalanced_classes
			-- Test with highly imbalanced class distribution.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_i: INTEGER
		do
			create l_model.make

			-- 99 samples of class 0, 1 sample of class 1
			create l_x.make_filled (create {ARRAY [REAL_64]}.make_filled (0.0, 1, 1), 1, 100)
			create l_y.make_filled (0, 1, 100)

			from l_i := 1 until l_i > 99
			loop
				l_x [l_i] := << 0.0 >>
				l_y [l_i] := 0
				l_i := l_i + 1
			end
			l_x [100] := << 5.0 >>
			l_y [100] := 1

			l_model.train (l_x, l_y)
			assert ("handles imbalanced data", l_model.is_trained)
		end

	test_adversarial_many_classes
			-- Test with many classes.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_i: INTEGER
		do
			create l_model.make

			-- 20 samples, 10 classes (2 per class)
			create l_x.make_filled (create {ARRAY [REAL_64]}.make_filled (0.0, 1, 1), 1, 20)
			create l_y.make_filled (0, 1, 20)

			from l_i := 1 until l_i > 20
			loop
				l_x [l_i] := << l_i.to_real >>
				l_y [l_i] := (l_i - 1) \\ 2
				l_i := l_i + 1
			end

			l_model.train (l_x, l_y)
			assert ("handles many classes", l_model.is_trained)
		end

	test_adversarial_large_feature_values
			-- Test with very large feature values.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_learning_rate (0.0001)

			l_x := << << 1000000.0 >>, << 2000000.0 >>, << 3000000.0 >>, << 4000000.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)
			assert ("handles large values", l_model.is_trained)
		end

	test_adversarial_many_iterations
			-- Test with many iterations.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_max_iterations (5000)

			l_x := << << 0.0 >>, << 1.0 >>, << 2.0 >>, << 3.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)
			assert ("trained with many iterations", l_model.is_trained)
		end

	test_adversarial_sigmoid_boundary_values
			-- Test sigmoid computation with boundary values.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_prob_zero, l_prob_large: REAL_64
		do
			create l_model.make

			l_x := << << -10.0 >>, << 10.0 >>, << 0.0 >> >>
			l_y := << 0, 1, 0 >>

			l_model.train (l_x, l_y)

			-- Test probability at extreme values
			l_prob_zero := l_model.predict_proba (<< 0.0 >>)
			l_prob_large := l_model.predict_proba (<< 10.0 >>)

			assert ("prob at zero", l_prob_zero >= 0.0 and l_prob_zero <= 1.0)
			assert ("prob at large", l_prob_large >= 0.0 and l_prob_large <= 1.0)
		end

	test_adversarial_repeated_training
			-- Test training twice.
		local
			l_model: LOGISTIC_REGRESSION_MODEL
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make

			l_x := << << 0.0 >>, << 1.0 >> >>
			l_y := << 0, 1 >>
			l_model.train (l_x, l_y)

			-- Train again
			l_x := << << 2.0 >>, << 3.0 >> >>
			l_y := << 0, 1 >>
			l_model.train (l_x, l_y)

			assert ("retraining allowed", l_model.is_trained)
		end

end
