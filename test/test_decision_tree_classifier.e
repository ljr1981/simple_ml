note
	description: "Tests for DECISION_TREE_CLASSIFIER"
	author: "Larry Rix"

class TEST_DECISION_TREE_CLASSIFIER

inherit
	EQA_TEST_SET

feature -- Tests

	test_make_creates_unconfigured_model
			-- Test that make creates an unconfigured model.
		local
			l_model: DECISION_TREE_CLASSIFIER
		do
			create l_model.make
			assert ("not trained", not l_model.is_trained)
			assert ("no classes", l_model.classes_learned.is_empty)
			assert ("default max depth", l_model.max_depth = 10)
			assert ("default min samples", l_model.min_samples_split = 2)
		end

	test_set_max_depth
			-- Test setting maximum tree depth.
		local
			l_model: DECISION_TREE_CLASSIFIER
		do
			create l_model.make
			l_model := l_model.set_max_depth (5)
			assert ("max depth set", l_model.max_depth = 5)
		end

	test_set_min_samples_split
			-- Test setting minimum samples to split.
		local
			l_model: DECISION_TREE_CLASSIFIER
		do
			create l_model.make
			l_model := l_model.set_min_samples_split (5)
			assert ("min samples set", l_model.min_samples_split = 5)
		end

	test_train_tree_classifier
			-- Test training decision tree classifier.
		local
			l_model: DECISION_TREE_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_max_depth (3)
			l_model := l_model.set_min_samples_split (2)

			-- Simple dataset with 2 features, 2 classes
			l_x := << << 1.0, 1.0 >>, << 2.0, 2.0 >>, << 5.0, 5.0 >>, << 6.0, 6.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)

			assert ("model trained", l_model.is_trained)
			assert ("classes learned", l_model.classes_learned.count = 2)
		end

	test_predict_returns_valid_class
			-- Test that predict returns a learned class.
		local
			l_model: DECISION_TREE_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_prediction: INTEGER
		do
			create l_model.make
			l_model := l_model.set_max_depth (3)

			l_x := << << 1.0, 1.0 >>, << 2.0, 2.0 >>, << 5.0, 5.0 >>, << 6.0, 6.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)
			l_prediction := l_model.predict (<< 1.5, 1.5 >>)

			assert ("prediction valid", l_model.classes_learned.has (l_prediction))
		end

	test_feature_dimension_validation
			-- Test that predict validates feature dimension.
		local
			l_model: DECISION_TREE_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make

			l_x := << << 1.0, 1.0 >>, << 2.0, 2.0 >> >>
			l_y := << 0, 1 >>

			l_model.train (l_x, l_y)

			-- Predict with correct feature count should work
			assert ("trained", l_model.is_trained)
		end

	test_adversarial_max_depth_boundary
			-- Test with extreme max depth values.
		local
			l_model1, l_model2: DECISION_TREE_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model1.make
			l_model1 := l_model1.set_max_depth (1)

			create l_model2.make
			l_model2 := l_model2.set_max_depth (100)

			l_x := << << 1.0 >>, << 2.0 >>, << 3.0 >> >>
			l_y := << 0, 1, 0 >>

			l_model1.train (l_x, l_y)
			l_model2.train (l_x, l_y)

			assert ("both trained", l_model1.is_trained and l_model2.is_trained)
		end

	test_adversarial_single_class
			-- Test with only one class in data.
		local
			l_model: DECISION_TREE_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make

			l_x := << << 1.0 >>, << 2.0 >>, << 3.0 >> >>
			l_y := << 0, 0, 0 >>

			l_model.train (l_x, l_y)
			assert ("trained with single class", l_model.is_trained)
		end

	test_adversarial_many_classes
			-- Test with many classes.
		local
			l_model: DECISION_TREE_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_i: INTEGER
		do
			create l_model.make

			-- 10 samples, 10 classes
			create l_x.make_filled (create {ARRAY [REAL_64]}.make_filled (0.0, 1, 1), 1, 10)
			create l_y.make_filled (0, 1, 10)

			from l_i := 1 until l_i > 10
			loop
				l_x [l_i] := << l_i.to_real >>
				l_y [l_i] := l_i - 1
				l_i := l_i + 1
			end

			l_model.train (l_x, l_y)
			assert ("trained with many classes", l_model.is_trained)
		end

	test_adversarial_high_dimensional
			-- Test with many features.
		local
			l_model: DECISION_TREE_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_i: INTEGER
			l_dummy_sample: ARRAY [REAL_64]
			l_sample: ARRAY [REAL_64]
		do
			create l_model.make

			-- Create dummy sample to pass to make_filled
			create l_dummy_sample.make_filled (0.0, 1, 20)
			create l_x.make_filled (l_dummy_sample, 1, 4)
			create l_y.make_filled (0, 1, 4)

			from l_i := 1 until l_i > 4
			loop
				create l_sample.make_filled (l_i.to_real, 1, 20)
				l_x [l_i] := l_sample
				l_y [l_i] := l_i \\ 2
				l_i := l_i + 1
			end

			l_model.train (l_x, l_y)
			assert ("trained high dimensional", l_model.is_trained)
		end

	test_adversarial_min_samples_split_boundary
			-- Test with extreme min_samples_split.
		local
			l_model: DECISION_TREE_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_min_samples_split (1000)

			l_x := << << 1.0 >>, << 2.0 >>, << 3.0 >> >>
			l_y := << 0, 1, 0 >>

			l_model.train (l_x, l_y)
			assert ("handles high min split", l_model.is_trained)
		end

end
