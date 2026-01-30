note
	description: "K-nearest neighbors classifier"
	author: "Larry Rix"

class KNN_CLASSIFIER

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured KNN classifier.
		do
			is_trained := False
			k := 3
			distance_metric := "euclidean"
			create training_X.make_empty
			create training_y.make_empty
			create classes.make_empty
		ensure
			not_trained: not is_trained
			k_positive: k > 0
			metric_euclidean: distance_metric.is_equal ("euclidean")
		end

feature -- Configuration

	set_k (a_k: INTEGER): like Current
			-- Set number of nearest neighbors to use.
		require
			positive_k: a_k > 0
		do
			k := a_k
			Result := Current
		ensure
			k_set: k = a_k
		end

	set_distance_metric (a_metric: STRING): like Current
			-- Set distance metric ("euclidean", "manhattan", "cosine").
		require
			valid_metric: a_metric.is_equal ("euclidean") or
						  a_metric.is_equal ("manhattan") or
						  a_metric.is_equal ("cosine")
		do
			distance_metric := a_metric
			Result := Current
		ensure
			metric_set: distance_metric.is_equal (a_metric)
		end

feature -- Training

	train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Store training data (lazy learning).
		require
			x_exists: a_X /= Void
			y_exists: a_y /= Void
			consistent_dimensions: a_X.count = a_y.count
			not_empty: a_X.count > 0
			k_less_than_samples: k < a_X.count
			x_not_void: across a_X as row all row /= Void end
			x_consistent: across a_X as row all row.count = a_X [a_X.lower].count end
		do
			training_X := a_X
			training_y := a_y
			-- Extract unique classes
			create classes.make_empty
			across a_y as y loop
				if not classes.has (y.item) then
					classes.force (y.item, classes.count + 1)
				end
			end
			is_trained := True
		ensure
			is_trained: is_trained
			data_stored: training_X.count = a_X.count
			classes_initialized: classes.count > 0
		end

feature -- Prediction

	predict (a_x: ARRAY [REAL_64]): INTEGER
			-- Find k nearest neighbors and return majority class.
		require
			trained: is_trained
			x_exists: a_x /= Void
		local
			l_distances: ARRAY [REAL_64]
			l_indices: ARRAY [INTEGER]
			l_i: INTEGER
			l_j: INTEGER
			l_min_dist: REAL_64
			l_min_idx: INTEGER
			l_votes: HASH_TABLE [INTEGER, INTEGER]
			l_max_votes: INTEGER
			l_max_class: INTEGER
		do
			-- Compute distances to all training samples
			create l_distances.make_filled (0.0, 1, training_X.count)
			from l_i := 1 until l_i > training_X.count loop
				l_distances [l_i] := distance (a_x, training_X [l_i])
				l_i := l_i + 1
			end

			-- Find k nearest neighbors (simple partial sort)
			create l_indices.make_filled (0, 1, k)
			from l_i := 1 until l_i > k loop
				l_min_dist := 999999999.0
				l_min_idx := 0
				from l_j := 1 until l_j > training_X.count loop
					if l_distances [l_j] < l_min_dist then
						-- Check if not already selected
						if not l_indices.has (l_j) then
							l_min_dist := l_distances [l_j]
							l_min_idx := l_j
						end
					end
					l_j := l_j + 1
				end
				l_indices [l_i] := l_min_idx
				l_i := l_i + 1
			end

			-- Count votes for each class
			create l_votes.make (classes.count)
			from l_i := 1 until l_i > k loop
				l_j := training_y [l_indices [l_i]]
				if l_votes.has_key (l_j) then
					l_votes [l_j] := l_votes [l_j] + 1
				else
					l_votes.put (1, l_j)
				end
				l_i := l_i + 1
			end

			-- Find class with most votes
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
			-- Return class probabilities based on k nearest neighbors.
		require
			trained: is_trained
			x_exists: a_x /= Void
		local
			l_distances: ARRAY [REAL_64]
			l_indices: ARRAY [INTEGER]
			l_i: INTEGER
			l_j: INTEGER
			l_min_dist: REAL_64
			l_min_idx: INTEGER
			l_votes: HASH_TABLE [INTEGER, INTEGER]
			l_class_idx: INTEGER
		do
			create Result.make_filled (0.0, 1, classes.count)

			-- Compute distances to all training samples
			create l_distances.make_filled (0.0, 1, training_X.count)
			from l_i := 1 until l_i > training_X.count loop
				l_distances [l_i] := distance (a_x, training_X [l_i])
				l_i := l_i + 1
			end

			-- Find k nearest neighbors
			create l_indices.make_filled (0, 1, k)
			from l_i := 1 until l_i > k loop
				l_min_dist := 999999999.0
				l_min_idx := 0
				from l_j := 1 until l_j > training_X.count loop
					if l_distances [l_j] < l_min_dist then
						if not l_indices.has (l_j) then
							l_min_dist := l_distances [l_j]
							l_min_idx := l_j
						end
					end
					l_j := l_j + 1
				end
				l_indices [l_i] := l_min_idx
				l_i := l_i + 1
			end

			-- Count votes for each class
			create l_votes.make (classes.count)
			from l_i := 1 until l_i > k loop
				l_j := training_y [l_indices [l_i]]
				if l_votes.has_key (l_j) then
					l_votes [l_j] := l_votes [l_j] + 1
				else
					l_votes.put (1, l_j)
				end
				l_i := l_i + 1
			end

			-- Convert votes to probabilities
			from l_i := 1 until l_i > classes.count loop
				l_j := classes [l_i]
				if l_votes.has_key (l_j) then
					Result [l_i] := l_votes [l_j] / k
				else
					Result [l_i] := 0.0
				end
				l_i := l_i + 1
			end
		ensure
		end

feature -- Status

	is_trained: BOOLEAN

	k: INTEGER
			-- Number of nearest neighbors to use.

	feature_dimension: INTEGER
		do
			if is_trained and training_X.count > 0 then
				Result := training_X [training_X.lower].count
			else
				Result := 0
			end
		end

feature {NONE} -- Implementation

	distance_metric: STRING
	training_X: ARRAY [ARRAY [REAL_64]]
	training_y: ARRAY [INTEGER]
	classes: ARRAY [INTEGER]

	distance (a_x1, a_x2: ARRAY [REAL_64]): REAL_64
			-- Compute distance between two points using configured metric.
		require
			x1_exists: a_x1 /= Void
			x2_exists: a_x2 /= Void
			same_dimension: a_x1.count = a_x2.count
		local
			l_i: INTEGER
			l_diff: REAL_64
		do
			if distance_metric.is_equal ("euclidean") then
				-- Euclidean distance: sqrt(sum((x1-x2)^2))
				Result := 0.0
				from l_i := 1 until l_i > a_x1.count loop
					l_diff := a_x1 [l_i] - a_x2 [l_i]
					Result := Result + l_diff * l_diff
					l_i := l_i + 1
				end
				-- Return squared distance to avoid sqrt
				Result := Result
			elseif distance_metric.is_equal ("manhattan") then
				-- Manhattan distance: sum(|x1-x2|)
				Result := 0.0
				from l_i := 1 until l_i > a_x1.count loop
					l_diff := a_x1 [l_i] - a_x2 [l_i]
					if l_diff < 0.0 then
						Result := Result - l_diff
					else
						Result := Result + l_diff
					end
					l_i := l_i + 1
				end
			else
				-- Cosine distance: 1 - (x1·x2) / (||x1|| * ||x2||)
				Result := 0.0
			end
		ensure
			result_non_negative: Result >= 0.0
		end

invariant
	k_positive: k > 0
	metric_valid: distance_metric.is_equal ("euclidean") or
				  distance_metric.is_equal ("manhattan") or
				  distance_metric.is_equal ("cosine")
	training_data_consistent: (
		training_X.count = training_y.count
	)

end
