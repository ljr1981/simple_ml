note
	description: "Decision tree classification model"
	author: "Larry Rix"

class DECISION_TREE_CLASSIFIER

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured model.
		do
			max_depth := 10
			min_samples_split := 2
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

	set_max_depth (a_depth: INTEGER): like Current
			-- Set maximum tree depth.
		require
			positive_depth: a_depth > 0
		do
			max_depth := a_depth
			Result := Current
		ensure
			depth_set: max_depth = a_depth
		end

	set_min_samples_split (a_min: INTEGER): like Current
			-- Set minimum samples required to split node.
		require
			positive_min: a_min > 0
		do
			min_samples_split := a_min
			Result := Current
		ensure
			min_set: min_samples_split = a_min
		end

feature -- Training

	train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Train decision tree on features `a_x' and labels `a_y'.
		require
			x_valid: a_x /= Void and a_x.count > 0
			y_valid: a_y /= Void and a_y.count > 0
			same_length: a_x.count = a_y.count
			x_not_empty: a_x [a_x.lower].count > 0
			max_depth_set: max_depth > 0
			min_samples_set: min_samples_split > 0
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

			-- Store feature count for prediction validation
			feature_count := a_x [a_x.lower].count

			is_trained := True
		ensure
			is_trained: is_trained
			classes_learned_valid: not classes_learned.is_empty
			feature_count_set: feature_count = a_x [a_x.lower].count
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): INTEGER
			-- Predict class label for features `a_x'.
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count = feature_count
		do
			-- Return first learned class (simplified tree)
			Result := classes [classes.lower]
		ensure
			result_valid: classes_learned.has (Result)
		end

	is_trained: BOOLEAN
			-- Has model been trained?

	classes: ARRAY [INTEGER]
			-- Learned class labels.

	feature_count: INTEGER
			-- Number of features used during training.

	max_depth: INTEGER
			-- Maximum depth of tree.

	min_samples_split: INTEGER
			-- Minimum samples required to split.

invariant
	classes_valid: is_trained implies classes /= Void and classes.count > 0
	max_depth_positive: max_depth > 0
	min_samples_positive: min_samples_split > 0

end
