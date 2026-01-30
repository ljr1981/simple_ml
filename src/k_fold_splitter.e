note
	description: "K-fold cross-validation data splitter"
	author: "Larry Rix"

class K_FOLD_SPLITTER

create
	make

feature {NONE} -- Initialization

	make (a_k: INTEGER)
			-- Create k-fold splitter with k folds.
		require
			valid_k: a_k >= 2
		do
			k := a_k
			random_seed := 42
			create folds.make_empty
		ensure
			k_set: k = a_k
			folds_empty: folds.count = 0
		end

feature -- Configuration

	set_k (a_k: INTEGER): like Current
		require
			valid_k: a_k >= 2
		do
			k := a_k
			Result := Current
		ensure
			k_set: k = a_k
		end

	set_random_seed (a_seed: INTEGER): like Current
			-- Set seed for reproducible shuffling.
		do
			random_seed := a_seed
			Result := Current
		ensure
			seed_set: random_seed = a_seed
		end

feature -- Splitting

	split (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Generate k train/test folds from data.
		require
			x_exists: a_X /= Void
			y_exists: a_y /= Void
			consistent_size: a_X.count = a_y.count
			sufficient_samples: a_X.count >= k * 2
			x_not_void: across a_X as row all row /= Void end
		local
			l_indices: ARRAY [INTEGER]
			l_fold_size: INTEGER
			l_i: INTEGER
			l_j: INTEGER
			l_fold_start: INTEGER
			l_fold_end: INTEGER
			l_train_x: ARRAY [ARRAY [REAL_64]]
			l_train_y: ARRAY [INTEGER]
			l_test_x: ARRAY [ARRAY [REAL_64]]
			l_test_y: ARRAY [INTEGER]
			l_train_idx: INTEGER
			l_test_idx: INTEGER
		do
			-- Create indices array [0, 1, 2, ..., n-1]
			create l_indices.make_filled (0, 0, a_X.count - 1)
			from l_i := 0 until l_i >= a_X.count loop
				l_indices [l_i] := l_i
				l_i := l_i + 1
			end

			-- Simple shuffle using seed (deterministic)
			l_i := 0
			from until l_i >= a_X.count loop
				l_j := (l_i + random_seed) \\ a_X.count
				-- Swap indices[l_i] and indices[l_j]
				if l_i /= l_j then
					l_indices [l_i] := l_indices [l_i] + l_indices [l_j]
					l_indices [l_j] := l_indices [l_i] - l_indices [l_j]
					l_indices [l_i] := l_indices [l_i] - l_indices [l_j]
				end
				l_i := l_i + 1
			end

			-- Calculate fold size (roughly equal distribution)
			l_fold_size := a_X.count // k

			-- Create k folds
			create folds.make (1, k)
			from l_i := 1 until l_i > k loop
				-- Calculate test fold boundaries
				l_fold_start := (l_i - 1) * l_fold_size
				if l_i = k then
					l_fold_end := a_X.count - 1
				else
					l_fold_end := l_i * l_fold_size - 1
				end

				-- Create training and test arrays for this fold
				create l_train_x.make (1, a_X.count - (l_fold_end - l_fold_start + 1))
				create l_train_y.make (1, l_train_x.count)
				create l_test_x.make (1, l_fold_end - l_fold_start + 1)
				create l_test_y.make (1, l_test_x.count)

				-- Populate test set
				l_test_idx := 1
				from l_j := l_fold_start until l_j > l_fold_end loop
					l_test_x [l_test_idx] := a_X [l_indices [l_j] + 1]
					l_test_y [l_test_idx] := a_y [l_indices [l_j] + 1]
					l_test_idx := l_test_idx + 1
					l_j := l_j + 1
				end

				-- Populate training set (all except test fold)
				l_train_idx := 1
				from l_j := 0 until l_j >= a_X.count loop
					if l_j < l_fold_start or l_j > l_fold_end then
						l_train_x [l_train_idx] := a_X [l_indices [l_j] + 1]
						l_train_y [l_train_idx] := a_y [l_indices [l_j] + 1]
						l_train_idx := l_train_idx + 1
					end
					l_j := l_j + 1
				end

				-- Create FOLD for this split
				folds [l_i] := create {FOLD}.make (l_train_x, l_train_y, l_test_x, l_test_y)
				l_i := l_i + 1
			end
		ensure
			folds_created: folds.count = k
			across folds as f all
				f.training_size + f.test_size = a_X.count
			end
			across folds as f all
				f.training_size > 0 and f.test_size > 0
			end
		end

feature -- Access

	get_fold (a_index: INTEGER): FOLD
			-- Get fold at index (1-based).
		require
			valid_index: a_index >= 1 and a_index <= k
		do
			-- Implementation in Phase 4
			Result := folds [a_index]
		ensure
			result_exists: Result /= Void
		end

	split_count: INTEGER
			-- Number of folds available.
		do
			Result := folds.count
		end

feature -- Status Queries

	k: INTEGER
			-- Number of folds to create.

feature {NONE} -- Implementation

	random_seed: INTEGER
	folds: ARRAY [FOLD]

invariant
	k_positive: k >= 2

end
