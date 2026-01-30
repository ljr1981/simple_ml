note
	description: "Tests for RANDOM_FOREST_CLASSIFIER"
	author: "Larry Rix"

class TEST_RANDOM_FOREST_CLASSIFIER

inherit
	EQA_TEST_SET

feature -- Tests

	test_make_creates_unconfigured_model
			-- Test that make creates an unconfigured model.
		local
			l_model: RANDOM_FOREST_CLASSIFIER
		do
			create l_model.make
			assert ("not trained", not l_model.is_trained)
			assert ("no classes", l_model.classes_learned.is_empty)
			assert ("default num trees", l_model.num_trees = 100)
			assert ("default max depth", l_model.max_depth = 10)
		end

	test_set_num_trees
			-- Test setting number of trees.
		local
			l_model: RANDOM_FOREST_CLASSIFIER
		do
			create l_model.make
			l_model := l_model.set_num_trees (50)
			assert ("num trees set", l_model.num_trees = 50)
		end

	test_set_max_depth
			-- Test setting maximum tree depth.
		local
			l_model: RANDOM_FOREST_CLASSIFIER
		do
			create l_model.make
			l_model := l_model.set_max_depth (8)
			assert ("max depth set", l_model.max_depth = 8)
		end

	test_train_ensemble
			-- Test training random forest ensemble.
		local
			l_model: RANDOM_FOREST_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_num_trees (10)
			l_model := l_model.set_max_depth (3)

			l_x := << << 1.0, 1.0 >>, << 2.0, 2.0 >>, << 5.0, 5.0 >>, << 6.0, 6.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)

			assert ("model trained", l_model.is_trained)
			assert ("classes learned", l_model.classes_learned.count = 2)
		end

	test_predict_returns_valid_class
			-- Test that predict returns a learned class.
		local
			l_model: RANDOM_FOREST_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_prediction: INTEGER
		do
			create l_model.make
			l_model := l_model.set_num_trees (5)

			l_x := << << 1.0, 1.0 >>, << 2.0, 2.0 >>, << 5.0, 5.0 >>, << 6.0, 6.0 >> >>
			l_y := << 0, 0, 1, 1 >>

			l_model.train (l_x, l_y)
			l_prediction := l_model.predict (<< 1.5, 1.5 >>)

			assert ("prediction valid", l_model.classes_learned.has (l_prediction))
		end

	test_predict_proba_valid_distribution
			-- Test that predict_proba returns valid probability distribution.
		local
			l_model: RANDOM_FOREST_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_probs: ARRAY [REAL_64]
			l_sum: REAL_64
			l_i: INTEGER
		do
			create l_model.make
			l_model := l_model.set_num_trees (5)

			l_x := << << 1.0 >>, << 2.0 >>, << 3.0 >> >>
			l_y := << 0, 1, 0 >>

			l_model.train (l_x, l_y)
			l_probs := l_model.predict_proba (<< 1.5 >>)

			-- Check that we have probabilities for each class
			assert ("probs returned", l_probs.count = l_model.classes_learned.count)

			-- Check that each probability is in [0, 1]
			from l_i := l_probs.lower
			until l_i > l_probs.upper
			loop
				assert ("probability in range", l_probs [l_i] >= 0.0 and l_probs [l_i] <= 1.0)
				l_sum := l_sum + l_probs [l_i]
				l_i := l_i + 1
			end

			-- For uniform distribution (simplified RF), sum should be 1.0
			assert ("probabilities sum to 1", (l_sum - 1.0).abs < 0.001)
		end

	test_adversarial_single_tree
			-- Test with single tree (degenerate ensemble).
		local
			l_model: RANDOM_FOREST_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_num_trees (1)

			l_x := << << 1.0 >>, << 2.0 >>, << 3.0 >> >>
			l_y := << 0, 1, 0 >>

			l_model.train (l_x, l_y)
			assert ("single tree trained", l_model.is_trained)
		end

	test_adversarial_many_trees
			-- Test with many trees in ensemble.
		local
			l_model: RANDOM_FOREST_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_num_trees (1000)

			l_x := << << 1.0 >>, << 2.0 >> >>
			l_y := << 0, 1 >>

			l_model.train (l_x, l_y)
			assert ("many trees trained", l_model.is_trained)
		end

	test_adversarial_single_class
			-- Test with single class.
		local
			l_model: RANDOM_FOREST_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make

			l_x := << << 1.0 >>, << 2.0 >> >>
			l_y := << 0, 0 >>

			l_model.train (l_x, l_y)
			assert ("single class trained", l_model.is_trained)
		end

	test_adversarial_many_classes
			-- Test with many classes.
		local
			l_model: RANDOM_FOREST_CLASSIFIER
			l_x: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_i: INTEGER
		do
			create l_model.make

			create l_x.make_filled (create {ARRAY [REAL_64]}.make_filled (0.0, 1, 1), 1, 15)
			create l_y.make_filled (0, 1, 15)

			from l_i := 1 until l_i > 15
			loop
				l_x [l_i] := << l_i.to_real >>
				l_y [l_i] := l_i \\ 5
				l_i := l_i + 1
			end

			l_model.train (l_x, l_y)
			assert ("many classes trained", l_model.is_trained)
		end

end
