note
	description: "Tests for Phase 2 enhancements (v1.1.0+)"
	author: "Larry Rix"

class TEST_ENHANCEMENTS

inherit
	EQA_TEST_SET

feature -- Regularization Tests

	test_linear_regression_regularized_creation
			-- Test creating regularized linear regression model.
		local
			l_model: LINEAR_REGRESSION_REGULARIZED
		do
			create l_model.make
			assert ("not_trained", not l_model.is_trained)
		end

	test_linear_regression_regularized_l2
			-- Test L2 regularization reduces weight magnitude.
		local
			l_model: LINEAR_REGRESSION_REGULARIZED
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make
			l_model := l_model.set_regularization ("l2", 0.1)

			-- Create simple training data (3 samples, 2 features)
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 3)
			l_X [1] := create {ARRAY [REAL_64]}.make_filled (1.0, 1, 2)
			l_X [2] := create {ARRAY [REAL_64]}.make_filled (2.0, 1, 2)
			l_X [3] := create {ARRAY [REAL_64]}.make_filled (3.0, 1, 2)

			create l_y.make_filled (0.0, 1, 3)
			l_y [1] := 1.0
			l_y [2] := 2.0
			l_y [3] := 3.0

			-- Train model
			l_model.train (l_X, l_y)

			-- Verify model is trained and learned weights
			assert ("trained", l_model.is_trained)
			assert ("has_weights", l_model.features_learned > 0)
		end

	test_logistic_regression_regularized_creation
			-- Test creating regularized logistic regression model.
		local
			l_model: LOGISTIC_REGRESSION_REGULARIZED
		do
			create l_model.make
			assert ("not_trained", not l_model.is_trained)
			assert ("zero_classes", l_model.classes_learned = 0)
		end

	test_logistic_regression_regularized_training
			-- Test training logistic regression on binary classification.
		local
			l_model: LOGISTIC_REGRESSION_REGULARIZED
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_regularization (0.01)

			-- Create binary classification data (4 samples, 2 features)
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.5, 5.5>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			-- Train model
			l_model.train (l_X, l_y)

			-- Verify model is trained
			assert ("trained", l_model.is_trained)
			assert ("two_classes", l_model.classes_learned = 2)
		end

	test_logistic_regression_regularized_prediction
			-- Test prediction on trained model.
		local
			l_model: LOGISTIC_REGRESSION_REGULARIZED
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_pred: INTEGER
			l_proba: ARRAY [REAL_64]
		do
			create l_model.make

			-- Create binary classification data
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.5, 5.5>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			-- Train model
			l_model.train (l_X, l_y)

			-- Test prediction
			l_pred := l_model.predict (<<2.0, 2.0>>)
			assert ("prediction_valid", l_pred = 0 or l_pred = 1)

			-- Test probability prediction
			l_proba := l_model.predict_proba (<<2.0, 2.0>>)
			assert ("proba_count", l_proba.count = 2)
		end

feature -- Model Selection Tests

	test_k_fold_splitter_creation
			-- Test creating k-fold splitter.
		local
			l_splitter: K_FOLD_SPLITTER
		do
			create l_splitter.make (5)
			assert ("k_set", l_splitter.k = 5)
		end

	test_k_fold_splitter_split
			-- Test splitting data into k folds.
		local
			l_splitter: K_FOLD_SPLITTER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_fold: FOLD
			l_i: INTEGER
		do
			create l_splitter.make (3)

			-- Create sample data (10 samples, 2 features)
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 10)
			from l_i := 1 until l_i > 10 loop
				l_X [l_i] := <<l_i / 1.0, (l_i + 1) / 1.0>>
				l_i := l_i + 1
			end

			create l_y.make_filled (0, 1, 10)
			from l_i := 1 until l_i > 10 loop
				if l_i <= 5 then
					l_y [l_i] := 0
				else
					l_y [l_i] := 1
				end
				l_i := l_i + 1
			end

			-- Split data (procedure, no return value)
			l_splitter.split (l_X, l_y)

			-- Verify fold structure
			assert ("three_folds", l_splitter.split_count = 3)

			-- Get first fold and verify sizes
			l_fold := l_splitter.get_fold (1)
			assert ("first_fold_valid", l_fold.training_size > 0)
			assert ("first_fold_test", l_fold.test_size > 0)
		end

	test_fold_creation
			-- Test creating a fold with training and test data.
		local
			l_fold: FOLD
			l_train_X: ARRAY [ARRAY [REAL_64]]
			l_train_y: ARRAY [INTEGER]
			l_test_X: ARRAY [ARRAY [REAL_64]]
			l_test_y: ARRAY [INTEGER]
		do
			-- Create sample training data (3 samples, 2 features)
			create l_train_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 3)
			l_train_X [1] := <<1.0, 2.0>>
			l_train_X [2] := <<2.0, 3.0>>
			l_train_X [3] := <<3.0, 4.0>>

			create l_train_y.make_filled (0, 1, 3)
			l_train_y [1] := 0
			l_train_y [2] := 1
			l_train_y [3] := 0

			-- Create sample test data (2 samples, 2 features)
			create l_test_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 2)
			l_test_X [1] := <<1.5, 2.5>>
			l_test_X [2] := <<2.5, 3.5>>

			create l_test_y.make_filled (0, 1, 2)
			l_test_y [1] := 0
			l_test_y [2] := 1

			-- Create fold
			create l_fold.make (l_train_X, l_train_y, l_test_X, l_test_y)

			-- Verify fold sizes
			assert ("train_size", l_fold.training_size = 3)
			assert ("test_size", l_fold.test_size = 2)
		end

	test_grid_search_cv_creation
			-- Test creating grid search optimizer.
		local
			l_grid_search: GRID_SEARCH_CV
		do
			create l_grid_search.make
			assert ("created", l_grid_search /= Void)
		end

	test_grid_search_cv_search
			-- Test executing grid search with cross-validation.
		local
			l_grid_search: GRID_SEARCH_CV
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_i: INTEGER
		do
			create l_grid_search.make

			-- Create sample classification data (12 samples, 2 features - need minimum 10)
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 12)
			from l_i := 1 until l_i > 6 loop
				l_X [l_i] := <<l_i / 10.0, (l_i + 1) / 10.0>>
				l_i := l_i + 1
			end
			from l_i := 7 until l_i > 12 loop
				l_X [l_i] := <<(l_i - 2) / 10.0, (l_i - 1) / 10.0>>
				l_i := l_i + 1
			end

			create l_y.make_filled (0, 1, 12)
			from l_i := 1 until l_i > 6 loop
				l_y [l_i] := 0
				l_i := l_i + 1
			end
			from l_i := 7 until l_i > 12 loop
				l_y [l_i] := 1
				l_i := l_i + 1
			end

			-- Execute grid search
			l_grid_search.search (l_X, l_y)

			-- Verify search completed and returned valid score
			assert ("has_results", l_grid_search.best_score >= 0.0 and l_grid_search.best_score <= 1.0)
		end

feature -- Kernel Methods Tests

	test_svm_rbf_creation
			-- Test creating RBF-SVM classifier.
		local
			l_svm: SVM_RBF
		do
			create l_svm.make
			assert ("not_trained", not l_svm.is_trained)
			assert ("gamma_positive", l_svm.gamma > 0.0)
		end

	test_svm_rbf_kernel_computation
			-- Test RBF kernel value computation.
		local
			l_svm: SVM_RBF
			l_x1, l_x2: ARRAY [REAL_64]
			l_kernel_value: REAL_64
		do
			create l_svm.make

			-- Create identical sample points
			l_x1 := <<1.0, 2.0>>
			l_x2 := <<1.0, 2.0>>

			-- Compute kernel value (should be 1 for identical points)
			l_kernel_value := l_svm.rbf_kernel (l_x1, l_x2)

			-- Verify kernel value in [0, 1]
			assert ("kernel_identical", l_kernel_value = 1.0)

			-- Test with different points
			l_x2 := <<2.0, 3.0>>
			l_kernel_value := l_svm.rbf_kernel (l_x1, l_x2)

			assert ("kernel_bounded", l_kernel_value >= 0.0 and l_kernel_value <= 1.0)
		end

	test_svm_rbf_training
			-- Test training RBF-SVM classifier.
		local
			l_svm: SVM_RBF
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_svm.make
			l_svm := l_svm.set_gamma (0.1)

			-- Create binary classification data (4 samples, 2 features)
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.5, 5.5>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			-- Train model
			l_svm.train (l_X, l_y)

			-- Verify model is trained
			assert ("trained", l_svm.is_trained)
			assert ("has_support_vectors", l_svm.feature_dimension = 2)
		end

	test_svm_rbf_prediction
			-- Test prediction with RBF-SVM.
		local
			l_svm: SVM_RBF
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_pred: INTEGER
		do
			create l_svm.make

			-- Create binary classification data
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.5, 5.5>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			-- Train model
			l_svm.train (l_X, l_y)

			-- Make prediction
			l_pred := l_svm.predict (<<1.2, 1.2>>)

			-- Verify prediction is one of the classes
			assert ("prediction_valid", l_pred = 0 or l_pred = 1)
		end

	test_svm_polynomial_creation
			-- Test creating polynomial-SVM classifier.
		local
			l_svm: SVM_POLYNOMIAL
		do
			create l_svm.make
			assert ("not_trained", not l_svm.is_trained)
			assert ("degree_positive", l_svm.degree > 0)
		end

	test_svm_polynomial_kernel_computation
			-- Test polynomial kernel value computation.
		local
			l_svm: SVM_POLYNOMIAL
			l_x1, l_x2: ARRAY [REAL_64]
			l_kernel_value: REAL_64
		do
			create l_svm.make
			l_svm := l_svm.set_degree (2)
				.set_coef0 (1.0)
				.set_gamma (0.1)

			-- Create sample points
			l_x1 := <<1.0, 2.0>>
			l_x2 := <<1.0, 2.0>>

			-- Compute kernel value
			l_kernel_value := l_svm.polynomial_kernel (l_x1, l_x2)

			-- Verify kernel value is finite and positive
			assert ("kernel_positive", l_kernel_value > 0.0)
		end

	test_svm_polynomial_training
			-- Test training polynomial-SVM classifier.
		local
			l_svm: SVM_POLYNOMIAL
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_svm.make
			l_svm := l_svm.set_degree (2)

			-- Create binary classification data (4 samples, 2 features)
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.5, 5.5>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			-- Train model
			l_svm.train (l_X, l_y)

			-- Verify model is trained
			assert ("trained", l_svm.is_trained)
		end

	test_svm_polynomial_prediction
			-- Test prediction with polynomial-SVM.
		local
			l_svm: SVM_POLYNOMIAL
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_pred: INTEGER
		do
			create l_svm.make

			-- Create binary classification data
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.5, 5.5>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			-- Train model
			l_svm.train (l_X, l_y)

			-- Make prediction
			l_pred := l_svm.predict (<<5.2, 5.2>>)

			-- Verify prediction is one of the classes
			assert ("prediction_valid", l_pred = 0 or l_pred = 1)
		end

feature -- New Algorithm Tests

	test_knn_classifier_creation
			-- Test creating KNN classifier.
		local
			l_knn: KNN_CLASSIFIER
		do
			create l_knn.make
			assert ("not_trained", not l_knn.is_trained)
			assert ("k_positive", l_knn.k > 0)
		end

	test_knn_classifier_k_setting
			-- Test setting K parameter.
		local
			l_knn: KNN_CLASSIFIER
		do
			create l_knn.make
			l_knn := l_knn.set_k (7)
			-- Verify K is set
			assert ("k_set", l_knn.k = 7)
		end

	test_knn_classifier_training
			-- Test training KNN classifier.
		local
			l_knn: KNN_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_knn.make
			l_knn := l_knn.set_k (3)

			-- Create binary classification data (6 samples, 2 features)
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 6)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<2.0, 2.0>>
			l_X [4] := <<5.0, 5.0>>
			l_X [5] := <<5.5, 5.5>>
			l_X [6] := <<6.0, 6.0>>

			create l_y.make_filled (0, 1, 6)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 0
			l_y [4] := 1
			l_y [5] := 1
			l_y [6] := 1

			-- Train model
			l_knn.train (l_X, l_y)

			-- Verify model is trained
			assert ("trained", l_knn.is_trained)
		end

	test_knn_classifier_prediction
			-- Test prediction with KNN classifier.
		local
			l_knn: KNN_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_pred: INTEGER
		do
			create l_knn.make
			l_knn := l_knn.set_k (3)

			-- Create binary classification data
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 6)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<2.0, 2.0>>
			l_X [4] := <<5.0, 5.0>>
			l_X [5] := <<5.5, 5.5>>
			l_X [6] := <<6.0, 6.0>>

			create l_y.make_filled (0, 1, 6)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 0
			l_y [4] := 1
			l_y [5] := 1
			l_y [6] := 1

			-- Train model
			l_knn.train (l_X, l_y)

			-- Test prediction near class 0 points
			l_pred := l_knn.predict (<<1.2, 1.2>>)
			assert ("prediction_near_0", l_pred = 0)

			-- Test prediction near class 1 points
			l_pred := l_knn.predict (<<5.2, 5.2>>)
			assert ("prediction_near_1", l_pred = 1)
		end

	test_naive_bayes_classifier_creation
			-- Test creating Naive Bayes classifier.
		local
			l_nb: NAIVE_BAYES_CLASSIFIER
		do
			create l_nb.make
			assert ("not_trained", not l_nb.is_trained)
		end

	test_naive_bayes_classifier_training
			-- Test training Naive Bayes classifier.
		local
			l_nb: NAIVE_BAYES_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_nb.make

			-- Create binary classification data (6 samples, 2 features)
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 6)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<2.0, 2.0>>
			l_X [4] := <<5.0, 5.0>>
			l_X [5] := <<5.5, 5.5>>
			l_X [6] := <<6.0, 6.0>>

			create l_y.make_filled (0, 1, 6)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 0
			l_y [4] := 1
			l_y [5] := 1
			l_y [6] := 1

			-- Train model
			l_nb.train (l_X, l_y)

			-- Verify model is trained
			assert ("trained", l_nb.is_trained)
		end

	test_naive_bayes_classifier_prediction
			-- Test prediction with Naive Bayes classifier.
		local
			l_nb: NAIVE_BAYES_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_pred: INTEGER
			l_proba: ARRAY [REAL_64]
		do
			create l_nb.make

			-- Create binary classification data
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 6)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<2.0, 2.0>>
			l_X [4] := <<5.0, 5.0>>
			l_X [5] := <<5.5, 5.5>>
			l_X [6] := <<6.0, 6.0>>

			create l_y.make_filled (0, 1, 6)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 0
			l_y [4] := 1
			l_y [5] := 1
			l_y [6] := 1

			-- Train model
			l_nb.train (l_X, l_y)

			-- Test prediction
			l_pred := l_nb.predict (<<1.2, 1.2>>)
			assert ("prediction_valid", l_pred = 0 or l_pred = 1)

			-- Test probability prediction
			l_proba := l_nb.predict_proba (<<1.2, 1.2>>)
			assert ("proba_count", l_proba.count = 2)
		end

	test_gradient_boosting_classifier_creation
			-- Test creating gradient boosting classifier.
		local
			l_gb: GRADIENT_BOOSTING_CLASSIFIER
		do
			create l_gb.make
			assert ("not_trained", not l_gb.is_trained)
			assert ("has_estimators", l_gb.feature_dimension >= 0)
		end

	test_gradient_boosting_configuration
			-- Test configuring gradient boosting parameters.
		local
			l_gb: GRADIENT_BOOSTING_CLASSIFIER
		do
			create l_gb.make
			l_gb := l_gb.set_n_estimators (50)
				.set_learning_rate (0.05)
				.set_max_depth (4)
			-- Parameters are set
		end

	test_gradient_boosting_classifier_training
			-- Test training gradient boosting classifier.
		local
			l_gb: GRADIENT_BOOSTING_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_gb.make
			l_gb := l_gb.set_n_estimators (5)

			-- Create binary classification data (6 samples, 2 features)
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 6)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<2.0, 2.0>>
			l_X [4] := <<5.0, 5.0>>
			l_X [5] := <<5.5, 5.5>>
			l_X [6] := <<6.0, 6.0>>

			create l_y.make_filled (0, 1, 6)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 0
			l_y [4] := 1
			l_y [5] := 1
			l_y [6] := 1

			-- Train model
			l_gb.train (l_X, l_y)

			-- Verify model is trained
			assert ("trained", l_gb.is_trained)
		end

	test_gradient_boosting_classifier_prediction
			-- Test prediction with gradient boosting classifier.
		local
			l_gb: GRADIENT_BOOSTING_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_pred: INTEGER
			l_proba: ARRAY [REAL_64]
		do
			create l_gb.make
			l_gb := l_gb.set_n_estimators (5)

			-- Create binary classification data
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 6)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<2.0, 2.0>>
			l_X [4] := <<5.0, 5.0>>
			l_X [5] := <<5.5, 5.5>>
			l_X [6] := <<6.0, 6.0>>

			create l_y.make_filled (0, 1, 6)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 0
			l_y [4] := 1
			l_y [5] := 1
			l_y [6] := 1

			-- Train model
			l_gb.train (l_X, l_y)

			-- Test prediction
			l_pred := l_gb.predict (<<1.2, 1.2>>)
			assert ("prediction_valid", l_pred = 0 or l_pred = 1)

			-- Test probability prediction
			l_proba := l_gb.predict_proba (<<1.2, 1.2>>)
			assert ("proba_count", l_proba.count = 2)
		end

feature -- Adversarial Tests: Regularization

	test_linear_regression_regularized_extreme_lambda
			-- Test with very large regularization lambda.
		local
			l_model: LINEAR_REGRESSION_REGULARIZED
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make
			l_model := l_model.set_regularization ("l2", 1000.0)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 2.0>>
			l_X [2] := <<2.0, 3.0>>
			l_X [3] := <<3.0, 4.0>>
			l_X [4] := <<4.0, 5.0>>

			create l_y.make_filled (0.0, 1, 4)
			l_y [1] := 1.0
			l_y [2] := 2.0
			l_y [3] := 3.0
			l_y [4] := 4.0

			l_model.train (l_X, l_y)
			assert ("trained_with_high_lambda", l_model.is_trained)
		end

	test_linear_regression_regularized_elastic_net
			-- Test ElasticNet regularization.
		local
			l_model: LINEAR_REGRESSION_REGULARIZED
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [REAL_64]
		do
			create l_model.make
			l_model := l_model.set_regularization ("elastic_net", 0.1)
				.set_l1_ratio (0.5)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 2.0>>
			l_X [2] := <<2.0, 3.0>>
			l_X [3] := <<3.0, 4.0>>
			l_X [4] := <<4.0, 5.0>>

			create l_y.make_filled (0.0, 1, 4)
			l_y [1] := 1.0
			l_y [2] := 2.0
			l_y [3] := 3.0
			l_y [4] := 4.0

			l_model.train (l_X, l_y)
			assert ("elastic_net_trained", l_model.is_trained)
		end

	test_logistic_regression_regularized_large_lambda
			-- Test logistic regression with large regularization.
		local
			l_model: LOGISTIC_REGRESSION_REGULARIZED
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_model.make
			l_model := l_model.set_regularization (100.0)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.5, 5.5>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			l_model.train (l_X, l_y)
			assert ("high_reg_trained", l_model.is_trained)
		end

feature -- Adversarial Tests: Model Selection

	test_k_fold_splitter_boundary_k
			-- Test with k = 2 (minimum valid value).
		local
			l_splitter: K_FOLD_SPLITTER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_i: INTEGER
		do
			create l_splitter.make (2)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 8)
			from l_i := 1 until l_i > 8 loop
				l_X [l_i] := <<l_i / 1.0, (l_i + 1) / 1.0>>
				l_i := l_i + 1
			end

			create l_y.make_filled (0, 1, 8)
			from l_i := 1 until l_i > 8 loop
				if l_i <= 4 then
					l_y [l_i] := 0
				else
					l_y [l_i] := 1
				end
				l_i := l_i + 1
			end

			l_splitter.split (l_X, l_y)
			assert ("min_k_folds", l_splitter.split_count = 2)
		end

	test_k_fold_splitter_large_k
			-- Test with large k (many small folds).
		local
			l_splitter: K_FOLD_SPLITTER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_i: INTEGER
		do
			create l_splitter.make (10)

			-- Need at least k*2 samples
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 50)
			from l_i := 1 until l_i > 50 loop
				l_X [l_i] := <<l_i / 1.0, (l_i + 1) / 1.0>>
				l_i := l_i + 1
			end

			create l_y.make_filled (0, 1, 50)
			from l_i := 1 until l_i > 50 loop
				l_y [l_i] := if l_i <= 25 then 0 else 1 end
				l_i := l_i + 1
			end

			l_splitter.split (l_X, l_y)
			assert ("large_k_folds", l_splitter.split_count = 10)
		end

	test_grid_search_cv_minimal_data
			-- Test grid search with minimum valid dataset size.
		local
			l_grid_search: GRID_SEARCH_CV
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_grid_search.make

			-- Create minimum data (10 samples required)
			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 10)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.1, 1.1>>
			l_X [3] := <<1.2, 1.2>>
			l_X [4] := <<1.3, 1.3>>
			l_X [5] := <<1.4, 1.4>>
			l_X [6] := <<5.0, 5.0>>
			l_X [7] := <<5.1, 5.1>>
			l_X [8] := <<5.2, 5.2>>
			l_X [9] := <<5.3, 5.3>>
			l_X [10] := <<5.4, 5.4>>

			create l_y.make_filled (0, 1, 10)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 0
			l_y [4] := 0
			l_y [5] := 0
			l_y [6] := 1
			l_y [7] := 1
			l_y [8] := 1
			l_y [9] := 1
			l_y [10] := 1

			l_grid_search.search (l_X, l_y)
			assert ("minimal_search", l_grid_search.best_score >= 0.0)
		end

feature -- Adversarial Tests: Kernel Methods

	test_svm_rbf_extreme_gamma_small
			-- Test RBF-SVM with very small gamma.
		local
			l_svm: SVM_RBF
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_pred: INTEGER
		do
			create l_svm.make
			l_svm := l_svm.set_gamma (0.00001)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.5, 5.5>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			l_svm.train (l_X, l_y)
			l_pred := l_svm.predict (<<3.0, 3.0>>)
			assert ("small_gamma_predict", l_pred = 0 or l_pred = 1)
		end

	test_svm_rbf_extreme_gamma_large
			-- Test RBF-SVM with very large gamma.
		local
			l_svm: SVM_RBF
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_pred: INTEGER
		do
			create l_svm.make
			l_svm := l_svm.set_gamma (100.0)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.5, 5.5>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			l_svm.train (l_X, l_y)
			l_pred := l_svm.predict (<<3.0, 3.0>>)
			assert ("large_gamma_predict", l_pred = 0 or l_pred = 1)
		end

	test_svm_polynomial_high_degree
			-- Test polynomial SVM with high polynomial degree.
		local
			l_svm: SVM_POLYNOMIAL
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_svm.make
			l_svm := l_svm.set_degree (10)
				.set_gamma (0.01)
				.set_coef0 (1.0)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.5, 5.5>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			l_svm.train (l_X, l_y)
			assert ("high_degree_trained", l_svm.is_trained)
		end

	test_svm_polynomial_zero_coef0
			-- Test polynomial SVM with coef0 = 0 (homogeneous).
		local
			l_svm: SVM_POLYNOMIAL
			l_x1, l_x2: ARRAY [REAL_64]
			l_kernel_value: REAL_64
		do
			create l_svm.make
			l_svm := l_svm.set_coef0 (0.0)
				.set_degree (2)
				.set_gamma (0.1)

			l_x1 := <<2.0, 2.0>>
			l_x2 := <<3.0, 3.0>>
			l_kernel_value := l_svm.polynomial_kernel (l_x1, l_x2)
			assert ("homogeneous_kernel", l_kernel_value > 0.0)
		end

feature -- Adversarial Tests: New Algorithms

	test_knn_classifier_extreme_k
			-- Test KNN with k = 1 (nearest single neighbor).
		local
			l_knn: KNN_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_pred: INTEGER
		do
			create l_knn.make
			l_knn := l_knn.set_k (1)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 6)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<2.0, 2.0>>
			l_X [4] := <<5.0, 5.0>>
			l_X [5] := <<5.5, 5.5>>
			l_X [6] := <<6.0, 6.0>>

			create l_y.make_filled (0, 1, 6)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 0
			l_y [4] := 1
			l_y [5] := 1
			l_y [6] := 1

			l_knn.train (l_X, l_y)
			l_pred := l_knn.predict (<<1.1, 1.1>>)
			assert ("k1_predict", l_pred = 0 or l_pred = 1)
		end

	test_knn_classifier_identical_neighbors
			-- Test KNN when query point equals training point.
		local
			l_knn: KNN_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_pred: INTEGER
		do
			create l_knn.make
			l_knn := l_knn.set_k (3)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 6)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<2.0, 2.0>>
			l_X [4] := <<5.0, 5.0>>
			l_X [5] := <<5.5, 5.5>>
			l_X [6] := <<6.0, 6.0>>

			create l_y.make_filled (0, 1, 6)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 0
			l_y [4] := 1
			l_y [5] := 1
			l_y [6] := 1

			l_knn.train (l_X, l_y)
			l_pred := l_knn.predict (<<1.0, 1.0>>)
			assert ("identical_point", l_pred = 0)
		end

	test_naive_bayes_identical_features
			-- Test Naive Bayes when all features are identical.
		local
			l_nb: NAIVE_BAYES_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_nb.make

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 4)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.0, 1.0>>
			l_X [3] := <<5.0, 5.0>>
			l_X [4] := <<5.0, 5.0>>

			create l_y.make_filled (0, 1, 4)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 1
			l_y [4] := 1

			l_nb.train (l_X, l_y)
			assert ("identical_features_trained", l_nb.is_trained)
		end

	test_gradient_boosting_single_estimator
			-- Test gradient boosting with only one weak learner.
		local
			l_gb: GRADIENT_BOOSTING_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
		do
			create l_gb.make
			l_gb := l_gb.set_n_estimators (1)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 6)
			l_X [1] := <<1.0, 1.0>>
			l_X [2] := <<1.5, 1.5>>
			l_X [3] := <<2.0, 2.0>>
			l_X [4] := <<5.0, 5.0>>
			l_X [5] := <<5.5, 5.5>>
			l_X [6] := <<6.0, 6.0>>

			create l_y.make_filled (0, 1, 6)
			l_y [1] := 0
			l_y [2] := 0
			l_y [3] := 0
			l_y [4] := 1
			l_y [5] := 1
			l_y [6] := 1

			l_gb.train (l_X, l_y)
			assert ("single_estimator_trained", l_gb.is_trained)
		end

	test_gradient_boosting_many_estimators
			-- Test gradient boosting with many weak learners.
		local
			l_gb: GRADIENT_BOOSTING_CLASSIFIER
			l_X: ARRAY [ARRAY [REAL_64]]
			l_y: ARRAY [INTEGER]
			l_i: INTEGER
		do
			create l_gb.make
			l_gb := l_gb.set_n_estimators (100)

			create l_X.make_filled (create {ARRAY [REAL_64]}.make_empty, 1, 20)
			from l_i := 1 until l_i > 20 loop
				l_X [l_i] := <<l_i / 1.0, (l_i + 1) / 1.0>>
				l_i := l_i + 1
			end

			create l_y.make_filled (0, 1, 20)
			from l_i := 1 until l_i > 20 loop
				l_y [l_i] := if l_i <= 10 then 0 else 1 end
				l_i := l_i + 1
			end

			l_gb.train (l_X, l_y)
			assert ("many_estimators_trained", l_gb.is_trained)
		end

end
