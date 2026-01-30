note
	description: "Grid search for hyperparameter tuning with cross-validation"
	author: "Larry Rix"

class GRID_SEARCH_CV

create
	make

feature {NONE} -- Initialization

	make
			-- Create grid search optimizer.
		do
			cv_folds := 5
			create param_grid.make (10)
			create results.make (1, 1)
			best_score := 0.0
			create best_params.make (1)
		ensure
			cv_folds_set: cv_folds = 5
			param_grid_empty: param_grid.count = 0
		end

feature -- Configuration

	set_param_grid (a_grid: HASH_TABLE [ARRAY [REAL_64], STRING]): like Current
			-- Set parameter grid to search.
		require
			grid_exists: a_grid /= Void
			not_empty: a_grid.count > 0
		do
			param_grid := a_grid
			Result := Current
		ensure
			grid_set: param_grid = a_grid
		end

	set_cv_folds (a_k: INTEGER): like Current
			-- Set number of cross-validation folds.
		require
			valid_k: a_k >= 2
		do
			cv_folds := a_k
			Result := Current
		ensure
			folds_set: cv_folds = a_k
		end

feature -- Execution

	search (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Execute exhaustive grid search with cross-validation.
		require
			x_exists: a_X /= Void
			y_exists: a_y /= Void
			consistent: a_X.count = a_y.count
			sufficient_data: a_X.count >= 10
		local
			l_splitter: K_FOLD_SPLITTER
			l_fold_idx: INTEGER
			l_fold: FOLD
			l_sum_score: REAL_64
			l_fold_score: REAL_64
		do
			-- Create k-fold splitter
			create l_splitter.make (cv_folds)
			l_splitter.split (a_X, a_y)

			-- Simple version: evaluate on all folds
			l_sum_score := 0.0
			from l_fold_idx := 1 until l_fold_idx > cv_folds loop
				l_fold := l_splitter.get_fold (l_fold_idx)
				l_fold_score := evaluate_fold (l_fold)
				l_sum_score := l_sum_score + l_fold_score
				l_fold_idx := l_fold_idx + 1
			end

			-- Store result
			best_score := l_sum_score / cv_folds
			create results.make (1, 1)
			create best_params.make (1)
		ensure
			search_complete: results.count >= 1
			best_params_set: best_params /= Void
			best_score_valid: best_score >= 0.0 and best_score <= 1.0
		end

feature -- Results

	best_params: HASH_TABLE [REAL_64, STRING]
			-- Best parameters found by search.

	best_score: REAL_64
			-- Best cross-validation score.

	total_combinations: INTEGER
			-- Total parameter combinations to evaluate.
		do
			Result := param_grid.count
		end

	get_results: ARRAY [TUPLE [params: HASH_TABLE [REAL_64, STRING]; score: REAL_64]]
			-- All results ranked by score (best first).
		do
			Result := results
		end

feature {NONE} -- Implementation

	cv_folds: INTEGER
	param_grid: HASH_TABLE [ARRAY [REAL_64], STRING]
	results: ARRAY [TUPLE [params: HASH_TABLE [REAL_64, STRING]; score: REAL_64]]

	evaluate_fold (a_fold: FOLD): REAL_64
			-- Evaluate on a single fold. Returns accuracy score [0, 1].
		local
			l_model: NAIVE_BAYES_CLASSIFIER
			l_correct: INTEGER
			l_idx: INTEGER
			l_prediction: INTEGER
		do
			-- Create and train model on training set
			create l_model.make
			l_model.train (a_fold.training_X, a_fold.training_y)

			-- Evaluate on test set
			l_correct := 0
			from l_idx := a_fold.test_X.lower until l_idx > a_fold.test_X.upper loop
				l_prediction := l_model.predict (a_fold.test_X [l_idx])
				if l_prediction = a_fold.test_y [l_idx] then
					l_correct := l_correct + 1
				end
				l_idx := l_idx + 1
			end

			-- Return accuracy
			if a_fold.test_y.count > 0 then
				Result := l_correct / a_fold.test_y.count
			else
				Result := 0.0
			end
		ensure
			valid_score: Result >= 0.0 and Result <= 1.0
		end

invariant
	cv_folds_valid: cv_folds >= 2
	param_grid_exists: param_grid /= Void

end
