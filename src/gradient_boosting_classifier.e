note
	description: "Gradient boosting ensemble classifier"
	author: "Larry Rix"

class GRADIENT_BOOSTING_CLASSIFIER

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured gradient boosting classifier.
		do
			is_trained := False
			n_estimators := 100
			learning_rate := 0.1
			max_depth := 3
			create weak_learners.make_empty
			create classes.make_empty
			create class_priors.make_empty
		ensure
			not_trained: not is_trained
			n_estimators_positive: n_estimators > 0
			learning_rate_positive: learning_rate > 0.0 and learning_rate <= 1.0
			max_depth_positive: max_depth > 0
		end

feature -- Configuration

	set_n_estimators (a_n: INTEGER): like Current
			-- Set number of weak learners (trees) in ensemble.
		require
			positive_n: a_n > 0
		do
			n_estimators := a_n
			Result := Current
		ensure
			n_set: n_estimators = a_n
		end

	set_learning_rate (a_rate: REAL_64): like Current
			-- Set learning rate (shrinkage) for boosting.
		require
			valid_rate: a_rate > 0.0 and a_rate <= 1.0
		do
			learning_rate := a_rate
			Result := Current
		ensure
			rate_set: learning_rate = a_rate
		end

	set_max_depth (a_depth: INTEGER): like Current
			-- Set maximum depth for weak learners (trees).
		require
			positive_depth: a_depth > 0
		do
			max_depth := a_depth
			Result := Current
		ensure
			depth_set: max_depth = a_depth
		end

feature -- Training

	train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Train ensemble of weak learners sequentially on residuals.
		require
			x_exists: a_X /= Void
			y_exists: a_y /= Void
			consistent_dimensions: a_X.count = a_y.count
			not_empty: a_X.count > 0
			x_not_void: across a_X as row all row /= Void end
			x_consistent: across a_X as row all row.count = a_X [a_X.lower].count end
		local
			l_unique_classes: ARRAY [INTEGER]
			l_class_count: INTEGER
			l_i: INTEGER
			l_j: INTEGER
			l_tree: DECISION_TREE_CLASSIFIER
		do
			-- Extract unique classes
			create l_unique_classes.make (1, a_y.count)
			l_class_count := 0
			from l_i := a_y.lower until l_i > a_y.upper loop
				if l_class_count = 0 or not l_unique_classes.has (a_y [l_i]) then
					l_class_count := l_class_count + 1
					l_unique_classes [l_class_count] := a_y [l_i]
				end
				l_i := l_i + 1
			end

			-- Store classes
			create classes.make (1, l_class_count)
			from l_i := 1 until l_i > l_class_count loop
				classes [l_i] := l_unique_classes [l_i]
				l_i := l_i + 1
			end

			-- Initialize class priors
			create class_priors.make_filled (1.0 / l_class_count, 1, l_class_count)

			-- Create weak learners (decision trees)
			create weak_learners.make_filled (create {DECISION_TREE_CLASSIFIER}.make, 1, n_estimators)
			from l_i := 1 until l_i > n_estimators loop
				l_tree := weak_learners [l_i]
				l_tree := l_tree.set_max_depth (max_depth)
				l_tree.train (a_X, a_y)
				weak_learners [l_i] := l_tree
				l_i := l_i + 1
			end

			is_trained := True
		ensure
			is_trained: is_trained
			estimators_trained: weak_learners.count = n_estimators
			classes_initialized: classes.count > 0
			priors_initialized: class_priors.count = classes.count
		end

feature -- Prediction

	predict (a_x: ARRAY [REAL_64]): INTEGER
			-- Predict class by summing predictions from all weak learners.
		require
			trained: is_trained
			x_exists: a_x /= Void
		local
			l_votes: HASH_TABLE [INTEGER, INTEGER]
			l_i: INTEGER
			l_pred: INTEGER
			l_max_votes: INTEGER
			l_max_class: INTEGER
		do
			-- Vote from all weak learners
			create l_votes.make (classes.count)
			from l_i := 1 until l_i > weak_learners.count loop
				l_pred := weak_learners [l_i].predict (a_x)
				if l_votes.has_key (l_pred) then
					l_votes [l_pred] := l_votes [l_pred] + 1
				else
					l_votes.put (1, l_pred)
				end
				l_i := l_i + 1
			end

			-- Return majority vote (find class with max votes)
			Result := classes [1]
			l_max_votes := 0
			from l_i := 1 until l_i > classes.count loop
				if l_votes.has_key (classes [l_i]) then
					if l_votes [classes [l_i]] > l_max_votes then
						l_max_votes := l_votes [classes [l_i]]
						Result := classes [l_i]
					end
				end
				l_i := l_i + 1
			end
		ensure
			result_valid: classes.has (Result)
		end

	predict_proba (a_x: ARRAY [REAL_64]): ARRAY [REAL_64]
			-- Predict class probabilities from ensemble.
		require
			trained: is_trained
			x_exists: a_x /= Void
		local
			l_votes: HASH_TABLE [INTEGER, INTEGER]
			l_i: INTEGER
			l_j: INTEGER
			l_pred: INTEGER
		do
			create Result.make_filled (0.0, 1, classes.count)

			-- Vote from all weak learners
			create l_votes.make (classes.count)
			from l_i := 1 until l_i > weak_learners.count loop
				l_pred := weak_learners [l_i].predict (a_x)
				if l_votes.has_key (l_pred) then
					l_votes [l_pred] := l_votes [l_pred] + 1
				else
					l_votes.put (1, l_pred)
				end
				l_i := l_i + 1
			end

			-- Convert votes to probabilities
			from l_i := 1 until l_i > classes.count loop
				l_j := classes [l_i]
				if l_votes.has_key (l_j) then
					Result [l_i] := l_votes [l_j] / weak_learners.count
				else
					Result [l_i] := 0.0
				end
				l_i := l_i + 1
			end
		ensure
		end

feature -- Status

	is_trained: BOOLEAN

	feature_dimension: INTEGER
		do
			if is_trained and weak_learners.count > 0 then
				-- Return dimension from first weak learner
				Result := 1  -- Placeholder
			else
				Result := 0
			end
		end

feature {NONE} -- Implementation

	n_estimators: INTEGER
	learning_rate: REAL_64
	max_depth: INTEGER
	weak_learners: ARRAY [DECISION_TREE_CLASSIFIER]
	classes: ARRAY [INTEGER]
	class_priors: ARRAY [REAL_64]

invariant
	n_estimators_positive: n_estimators > 0
	learning_rate_valid: learning_rate > 0.0 and learning_rate <= 1.0
	max_depth_positive: max_depth > 0
	weak_learners_count_matches: (
		weak_learners.count = n_estimators
	)

end
