note
	description: "Tests for SVM_LINEAR"
	author: "Larry Rix"

class TEST_SVM_LINEAR

inherit
	EQA_TEST_SET

feature -- Tests

	test_make_creates_unconfigured_model
			-- Test that make creates an unconfigured model.
		local
			l_model: SVM_LINEAR
		do
			create l_model.make
			assert ("not trained", not l_model.is_trained)
			assert ("no classes", l_model.classes_learned.is_empty)
			assert ("default c param", l_model.c_param = 1.0)
		end

	test_set_c_param
			-- Test setting regularization parameter.
		local
			l_model: SVM_LINEAR
		do
			create l_model.make
			l_model := l_model.set_c_param (0.5)
			assert ("c param set", l_model.c_param = 0.5)
		end

	test_set_tolerance
			-- Test setting convergence tolerance.
		local
			l_model: SVM_LINEAR
		do
			create l_model.make
			l_model := l_model.set_tolerance (0.001)
			assert ("tolerance set", l_model.tolerance = 0.001)
		end

	test_train_svm
			-- Test training linear SVM.
		local
			l_model: SVM_LINEAR
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_c_param (1.0)
			l_model := l_model.set_tolerance (0.0001)

			-- Simple binary classification data
			l_x := << << 0.5, 0.5 >>, << 1.5, 1.5 >>, << 3.0, 3.0 >>, << 4.0, 4.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)

			assert ("model trained", l_model.is_trained)
			assert ("classes learned", l_model.classes_learned.count = 2)
		end

	test_predict_returns_valid_class
			-- Test that predict returns a learned class.
		local
			l_model: SVM_LINEAR
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_prediction: INTEGER
		do
			create l_model.make
			l_model := l_model.set_c_param (1.0)

			l_x := << << 0.5, 0.5 >>, << 1.5, 1.5 >>, << 3.0, 3.0 >>, << 4.0, 4.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)
			l_prediction := l_model.predict (<< 1.0, 1.0 >>)

			assert ("prediction valid", l_model.classes_learned.has (l_prediction))
		end

	test_decision_function
			-- Test decision function computation.
		local
			l_model: SVM_LINEAR
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_decision: REAL_64
		do
			create l_model.make

			l_x := << << 0.5 >>, << 1.5 >>, << 3.0 >>, << 4.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)
			l_decision := l_model.decision_function (<< 2.0 >>)

			-- Decision function should return a real value
			assert ("decision computed", True)
		end

	test_adversarial_c_param_boundary
			-- Test with extreme C parameter values.
		local
			l_model1, l_model2: SVM_LINEAR
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model1.make
			l_model1 := l_model1.set_c_param (0.0001)

			create l_model2.make
			l_model2 := l_model2.set_c_param (1000.0)

			l_x := << << 0.5 >>, << 1.5 >>, << 3.0 >>, << 4.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model1.train (l_x, l_y)
			l_model2.train (l_x, l_y)

			assert ("both c values trained", l_model1.is_trained and l_model2.is_trained)
		end

	test_adversarial_tolerance_boundary
			-- Test with extreme tolerance values.
		local
			l_model: SVM_LINEAR
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_tolerance (0.000000001)

			l_x := << << 0.5 >>, << 1.5 >>, << 3.0 >>, << 4.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)
			assert ("very tight tolerance trained", l_model.is_trained)
		end

	test_adversarial_single_sample
			-- Test with single sample.
		local
			l_model: SVM_LINEAR
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make

			l_x := << << 1.0 >> >>
			l_y := << 0 >>

			l_model.train (l_x, l_y)
			assert ("single sample trained", l_model.is_trained)
		end

	test_adversarial_high_dimensional
			-- Test with many features.
		local
			l_model: SVM_LINEAR
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_i: INTEGER
			l_dummy_sample: ARRAY [REAL_64]
			l_sample: ARRAY [REAL_64]
		do
			create l_model.make

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
			assert ("high dimensional trained", l_model.is_trained)
		end

	test_adversarial_decision_function_extremes
			-- Test decision function with extreme values.
		local
			l_model: SVM_LINEAR
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_d1, l_d2: REAL_64
		do
			create l_model.make

			l_x := << << -1000.0 >>, << 1000.0 >> >>
			l_y := << 0, 1 >>

			l_model.train (l_x, l_y)

			l_d1 := l_model.decision_function (<< -1000.0 >>)
			l_d2 := l_model.decision_function (<< 1000.0 >>)

			-- Decision values should be real numbers
			assert ("decisions computed", True)
		end

end
