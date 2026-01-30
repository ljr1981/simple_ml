note
	description: "SCOOP consumer integration test for simple_ml"
	author: "Larry Rix"

class TEST_SCOOP_CONSUMER

create
	make

feature -- SCOOP Integration

	make
			-- Test that simple_ml works in SCOOP context.
		local
			l_lr: LINEAR_REGRESSION_MODEL
			l_logistic: LOGISTIC_REGRESSION_MODEL
			l_svm_lin: SVM_LINEAR
			l_knn: KNN_CLASSIFIER
			l_nb: NAIVE_BAYES_CLASSIFIER
		do
			-- Verify enhancement classes work in SCOOP context
			test_linear_regression_regularized
			test_logistic_regression_regularized
			test_svm_rbf
			test_svm_polynomial
			test_knn_classifier
			test_naive_bayes_classifier
			test_gradient_boosting_classifier
			test_k_fold_splitter
			test_grid_search_cv

			print ("SCOOP compatibility test completed successfully%N")
		end

feature {NONE} -- SCOOP Component Tests

	test_linear_regression_regularized
			-- Test LINEAR_REGRESSION_REGULARIZED in SCOOP context.
		local
			l_model: LINEAR_REGRESSION_REGULARIZED
		do
			create l_model.make
			l_model := l_model.set_regularization ("l2", 0.1)
			-- Model should be usable without issues
		end

	test_logistic_regression_regularized
			-- Test LOGISTIC_REGRESSION_REGULARIZED in SCOOP context.
		local
			l_model: LOGISTIC_REGRESSION_REGULARIZED
		do
			create l_model.make
			l_model := l_model.set_regularization (0.01)
			-- Model should be usable without issues
		end

	test_svm_rbf
			-- Test SVM_RBF in SCOOP context.
		local
			l_svm: SVM_RBF
		do
			create l_svm.make
			l_svm := l_svm.set_gamma (0.1)
			-- SVM should be usable without issues
		end

	test_svm_polynomial
			-- Test SVM_POLYNOMIAL in SCOOP context.
		local
			l_svm: SVM_POLYNOMIAL
		do
			create l_svm.make
			l_svm := l_svm.set_degree (2)
				.set_gamma (0.1)
				.set_coef0 (1.0)
			-- SVM should be usable without issues
		end

	test_knn_classifier
			-- Test KNN_CLASSIFIER in SCOOP context.
		local
			l_knn: KNN_CLASSIFIER
		do
			create l_knn.make
			l_knn := l_knn.set_k (3)
			-- KNN should be usable without issues
		end

	test_naive_bayes_classifier
			-- Test NAIVE_BAYES_CLASSIFIER in SCOOP context.
		local
			l_nb: NAIVE_BAYES_CLASSIFIER
		do
			create l_nb.make
			-- Naive Bayes should be usable without issues
		end

	test_gradient_boosting_classifier
			-- Test GRADIENT_BOOSTING_CLASSIFIER in SCOOP context.
		local
			l_gb: GRADIENT_BOOSTING_CLASSIFIER
		do
			create l_gb.make
			l_gb := l_gb.set_n_estimators (10)
				.set_learning_rate (0.1)
				.set_max_depth (3)
			-- Gradient boosting should be usable without issues
		end

	test_k_fold_splitter
			-- Test K_FOLD_SPLITTER in SCOOP context.
		local
			l_splitter: K_FOLD_SPLITTER
		do
			create l_splitter.make (5)
			l_splitter := l_splitter.set_random_seed (42)
			-- K-fold splitter should be usable without issues
		end

	test_grid_search_cv
			-- Test GRID_SEARCH_CV in SCOOP context.
		local
			l_grid_search: GRID_SEARCH_CV
		do
			create l_grid_search.make
			l_grid_search := l_grid_search.set_cv_folds (5)
			-- Grid search should be usable without issues
		end

end
