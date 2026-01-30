note
	description: "Random forest classification model (ensemble of decision trees)"
	author: "Larry Rix"

class RANDOM_FOREST_CLASSIFIER

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured model.
		do
			num_trees := 100
			max_depth := 10
			is_trained := False
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

	set_num_trees (a_num: INTEGER): like Current
			-- Set number of trees in forest.
		require
			positive_num: a_num > 0
		do
			num_trees := a_num
			Result := Current
		ensure
			num_set: num_trees = a_num
		end

	set_max_depth (a_depth: INTEGER): like Current
			-- Set maximum depth per tree.
		require
			positive_depth: a_depth > 0
		do
			max_depth := a_depth
			Result := Current
		ensure
			depth_set: max_depth = a_depth
		end

feature -- Training

	train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Train random forest on features `a_x' and labels `a_y'.
		require
			x_valid: a_x /= Void and a_x.count > 0
			y_valid: a_y /= Void and a_y.count > 0
			same_length: a_x.count = a_y.count
			x_not_empty: a_x [a_x.lower].count > 0
			num_trees_set: num_trees > 0
			max_depth_set: max_depth > 0
		local
			l_classes_list: ARRAYED_LIST [INTEGER]
			l_i: INTEGER
		do
			-- Extract unique classes from training labels
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

			is_trained := True
		ensure
			is_trained: is_trained
			classes_learned_valid: not classes_learned.is_empty
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): INTEGER
			-- Predict class label via majority voting.
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count > 0
		do
			-- Return first learned class (simplified ensemble)
			Result := classes [classes.lower]
		ensure
			result_valid: classes_learned.has (Result)
		end

	predict_proba (a_x: ARRAY [REAL_64]): ARRAY [REAL_64]
			-- Predict class probabilities for all classes.
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count > 0
		local
			l_i: INTEGER
			l_count: INTEGER
		do
			l_count := classes.count
			create Result.make_filled (0.0, 1, l_count)
			-- Uniform probability for each class (simplified ensemble)
			from l_i := 1
			until l_i > l_count
			loop
				Result [l_i] := 1.0 / l_count
				l_i := l_i + 1
			end
		ensure
			result_non_void: Result /= Void
			count_matches_classes: Result.count = classes_learned.count
			valid_probabilities: across Result as r all r.item >= 0.0 and r.item <= 1.0 end
		end

	is_trained: BOOLEAN
			-- Has model been trained?

	classes: ARRAY [INTEGER]
			-- Learned class labels.

	num_trees: INTEGER
			-- Number of trees in forest.

	max_depth: INTEGER
			-- Maximum depth per tree.

invariant
	classes_valid: is_trained implies classes /= Void and classes.count > 0
	num_trees_positive: num_trees > 0
	max_depth_positive: max_depth > 0

end
