note
	description: "Test application runner for simple_ml"
	author: "Larry Rix"

class TEST_APP

create
	make

feature {NONE} -- Initialization

	make
			-- Run the tests.
		do
			print ("Running simple_ml tests...%N%N")
			passed := 0
			failed := 0

			run_scoop_consumer_test
			run_linear_regression_tests
			run_logistic_regression_tests
			run_decision_tree_tests
			run_random_forest_tests
			run_svm_tests
			run_neural_network_tests
			run_enhancements_tests

			print ("%N========================%N")
			print ("Results: " + passed.out + " passed, " + failed.out + " failed%N")

			if failed > 0 then
				print ("TESTS FAILED%N")
			else
				print ("ALL TESTS PASSED%N")
			end
		end

feature {NONE} -- Test Runners

	run_scoop_consumer_test
			-- Test SCOOP compatibility.
		local
			l_test: TEST_SCOOP_CONSUMER
		do
			print ("SCOOP Consumer Integration Tests:%N")
			create l_test.make
			print ("  PASS: SCOOP consumer integration test%N")
			passed := passed + 1
			print ("%N")
		end

	run_linear_regression_tests
		local
			l_tests: TEST_LINEAR_REGRESSION_MODEL
		do
			print ("Linear Regression Tests:%N")
			create l_tests
			run_test (agent l_tests.test_make_creates_unconfigured_model, "test_make_creates_unconfigured_model")
			run_test (agent l_tests.test_set_learning_rate_valid, "test_set_learning_rate_valid")
			run_test (agent l_tests.test_set_max_iterations_valid, "test_set_max_iterations_valid")
			run_test (agent l_tests.test_train_with_simple_data, "test_train_with_simple_data")
			run_test (agent l_tests.test_predict_after_training, "test_predict_after_training")
			run_test (agent l_tests.test_train_with_multiple_features, "test_train_with_multiple_features")
			run_test (agent l_tests.test_learning_rate_effect, "test_learning_rate_effect")
			run_test (agent l_tests.test_adversarial_very_small_learning_rate, "test_adversarial_very_small_learning_rate")
			run_test (agent l_tests.test_adversarial_large_learning_rate, "test_adversarial_large_learning_rate")
			run_test (agent l_tests.test_adversarial_single_sample, "test_adversarial_single_sample")
			run_test (agent l_tests.test_adversarial_large_feature_values, "test_adversarial_large_feature_values")
			run_test (agent l_tests.test_adversarial_small_feature_values, "test_adversarial_small_feature_values")
			run_test (agent l_tests.test_adversarial_many_iterations, "test_adversarial_many_iterations")
			run_test (agent l_tests.test_adversarial_high_dimensional, "test_adversarial_high_dimensional")
			run_test (agent l_tests.test_adversarial_many_samples, "test_adversarial_many_samples")
			run_test (agent l_tests.test_adversarial_repeated_training, "test_adversarial_repeated_training")
			run_test (agent l_tests.test_precondition_predict_requires_training, "test_precondition_predict_requires_training")
			print ("%N")
		end

	run_logistic_regression_tests
		local
			l_tests: TEST_LOGISTIC_REGRESSION_MODEL
		do
			print ("Logistic Regression Tests:%N")
			create l_tests
			run_test (agent l_tests.test_make_creates_unconfigured_model, "test_make_creates_unconfigured_model")
			run_test (agent l_tests.test_set_learning_rate_valid, "test_set_learning_rate_valid")
			run_test (agent l_tests.test_set_max_iterations_valid, "test_set_max_iterations_valid")
			run_test (agent l_tests.test_train_binary_classification, "test_train_binary_classification")
			run_test (agent l_tests.test_predict_returns_valid_class, "test_predict_returns_valid_class")
			run_test (agent l_tests.test_predict_proba_in_range, "test_predict_proba_in_range")
			run_test (agent l_tests.test_train_multiclass, "test_train_multiclass")
			run_test (agent l_tests.test_adversarial_very_small_learning_rate, "test_adversarial_very_small_learning_rate")
			run_test (agent l_tests.test_adversarial_large_learning_rate, "test_adversarial_large_learning_rate")
			run_test (agent l_tests.test_adversarial_single_sample, "test_adversarial_single_sample")
			run_test (agent l_tests.test_adversarial_imbalanced_classes, "test_adversarial_imbalanced_classes")
			run_test (agent l_tests.test_adversarial_many_classes, "test_adversarial_many_classes")
			run_test (agent l_tests.test_adversarial_large_feature_values, "test_adversarial_large_feature_values")
			run_test (agent l_tests.test_adversarial_many_iterations, "test_adversarial_many_iterations")
			run_test (agent l_tests.test_adversarial_sigmoid_boundary_values, "test_adversarial_sigmoid_boundary_values")
			run_test (agent l_tests.test_adversarial_repeated_training, "test_adversarial_repeated_training")
			print ("%N")
		end

	run_decision_tree_tests
		local
			l_tests: TEST_DECISION_TREE_CLASSIFIER
		do
			print ("Decision Tree Tests:%N")
			create l_tests
			run_test (agent l_tests.test_make_creates_unconfigured_model, "test_make_creates_unconfigured_model")
			run_test (agent l_tests.test_set_max_depth, "test_set_max_depth")
			run_test (agent l_tests.test_set_min_samples_split, "test_set_min_samples_split")
			run_test (agent l_tests.test_train_tree_classifier, "test_train_tree_classifier")
			run_test (agent l_tests.test_predict_returns_valid_class, "test_predict_returns_valid_class")
			run_test (agent l_tests.test_feature_dimension_validation, "test_feature_dimension_validation")
			run_test (agent l_tests.test_adversarial_max_depth_boundary, "test_adversarial_max_depth_boundary")
			run_test (agent l_tests.test_adversarial_single_class, "test_adversarial_single_class")
			run_test (agent l_tests.test_adversarial_many_classes, "test_adversarial_many_classes")
			run_test (agent l_tests.test_adversarial_high_dimensional, "test_adversarial_high_dimensional")
			run_test (agent l_tests.test_adversarial_min_samples_split_boundary, "test_adversarial_min_samples_split_boundary")
			print ("%N")
		end

	run_random_forest_tests
		local
			l_tests: TEST_RANDOM_FOREST_CLASSIFIER
		do
			print ("Random Forest Tests:%N")
			create l_tests
			run_test (agent l_tests.test_make_creates_unconfigured_model, "test_make_creates_unconfigured_model")
			run_test (agent l_tests.test_set_num_trees, "test_set_num_trees")
			run_test (agent l_tests.test_set_max_depth, "test_set_max_depth")
			run_test (agent l_tests.test_train_ensemble, "test_train_ensemble")
			run_test (agent l_tests.test_predict_returns_valid_class, "test_predict_returns_valid_class")
			run_test (agent l_tests.test_predict_proba_valid_distribution, "test_predict_proba_valid_distribution")
			run_test (agent l_tests.test_adversarial_single_tree, "test_adversarial_single_tree")
			run_test (agent l_tests.test_adversarial_many_trees, "test_adversarial_many_trees")
			run_test (agent l_tests.test_adversarial_single_class, "test_adversarial_single_class")
			run_test (agent l_tests.test_adversarial_many_classes, "test_adversarial_many_classes")
			print ("%N")
		end

	run_svm_tests
		local
			l_tests: TEST_SVM_LINEAR
		do
			print ("SVM Linear Tests:%N")
			create l_tests
			run_test (agent l_tests.test_make_creates_unconfigured_model, "test_make_creates_unconfigured_model")
			run_test (agent l_tests.test_set_c_param, "test_set_c_param")
			run_test (agent l_tests.test_set_tolerance, "test_set_tolerance")
			run_test (agent l_tests.test_train_svm, "test_train_svm")
			run_test (agent l_tests.test_predict_returns_valid_class, "test_predict_returns_valid_class")
			run_test (agent l_tests.test_decision_function, "test_decision_function")
			run_test (agent l_tests.test_adversarial_c_param_boundary, "test_adversarial_c_param_boundary")
			run_test (agent l_tests.test_adversarial_tolerance_boundary, "test_adversarial_tolerance_boundary")
			run_test (agent l_tests.test_adversarial_single_sample, "test_adversarial_single_sample")
			run_test (agent l_tests.test_adversarial_high_dimensional, "test_adversarial_high_dimensional")
			run_test (agent l_tests.test_adversarial_decision_function_extremes, "test_adversarial_decision_function_extremes")
			print ("%N")
		end

	run_neural_network_tests
		local
			l_tests: TEST_NEURAL_NETWORK_CLASSIFIER
		do
			print ("Neural Network Tests:%N")
			create l_tests
			run_test (agent l_tests.test_make_creates_unconfigured_model, "test_make_creates_unconfigured_model")
			run_test (agent l_tests.test_set_learning_rate, "test_set_learning_rate")
			run_test (agent l_tests.test_set_max_iterations, "test_set_max_iterations")
			run_test (agent l_tests.test_set_hidden_layers, "test_set_hidden_layers")
			run_test (agent l_tests.test_train_neural_network, "test_train_neural_network")
			run_test (agent l_tests.test_predict_returns_valid_class, "test_predict_returns_valid_class")
			run_test (agent l_tests.test_predict_proba_returns_distribution, "test_predict_proba_returns_distribution")
			run_test (agent l_tests.test_loss_non_negative, "test_loss_non_negative")
			run_test (agent l_tests.test_adversarial_deep_network, "test_adversarial_deep_network")
			run_test (agent l_tests.test_adversarial_wide_network, "test_adversarial_wide_network")
			run_test (agent l_tests.test_adversarial_single_hidden_neuron, "test_adversarial_single_hidden_neuron")
			run_test (agent l_tests.test_adversarial_many_iterations, "test_adversarial_many_iterations")
			run_test (agent l_tests.test_adversarial_high_dimensional_input, "test_adversarial_high_dimensional_input")
			run_test (agent l_tests.test_adversarial_many_classes, "test_adversarial_many_classes")
			run_test (agent l_tests.test_adversarial_single_class, "test_adversarial_single_class")
			print ("%N")
		end

feature {NONE} -- Implementation

	passed: INTEGER
	failed: INTEGER

	run_test (a_test: PROCEDURE; a_name: STRING)
		local
			l_retried: BOOLEAN
		do
			if not l_retried then
				a_test.call (Void)
				print ("  PASS: " + a_name + "%N")
				passed := passed + 1
			end
		rescue
			print ("  FAIL: " + a_name + "%N")
			failed := failed + 1
			l_retried := True
			retry
		end

	run_enhancements_tests
			-- Run tests for Phase 2 enhancements.
		local
			l_tests: TEST_ENHANCEMENTS
		do
			print ("Enhancement Tests:%N")
			create l_tests

			-- Regularization tests
			run_test (agent l_tests.test_linear_regression_regularized_creation, "test_linear_regression_regularized_creation")
			run_test (agent l_tests.test_linear_regression_regularized_l2, "test_linear_regression_regularized_l2")
			run_test (agent l_tests.test_logistic_regression_regularized_creation, "test_logistic_regression_regularized_creation")
			run_test (agent l_tests.test_logistic_regression_regularized_training, "test_logistic_regression_regularized_training")
			run_test (agent l_tests.test_logistic_regression_regularized_prediction, "test_logistic_regression_regularized_prediction")

			-- Model selection tests
			run_test (agent l_tests.test_k_fold_splitter_creation, "test_k_fold_splitter_creation")
			run_test (agent l_tests.test_k_fold_splitter_split, "test_k_fold_splitter_split")
			run_test (agent l_tests.test_fold_creation, "test_fold_creation")
			run_test (agent l_tests.test_grid_search_cv_creation, "test_grid_search_cv_creation")
			run_test (agent l_tests.test_grid_search_cv_search, "test_grid_search_cv_search")

			-- Kernel methods tests
			run_test (agent l_tests.test_svm_rbf_creation, "test_svm_rbf_creation")
			run_test (agent l_tests.test_svm_rbf_kernel_computation, "test_svm_rbf_kernel_computation")
			run_test (agent l_tests.test_svm_rbf_training, "test_svm_rbf_training")
			run_test (agent l_tests.test_svm_rbf_prediction, "test_svm_rbf_prediction")
			run_test (agent l_tests.test_svm_polynomial_creation, "test_svm_polynomial_creation")
			run_test (agent l_tests.test_svm_polynomial_kernel_computation, "test_svm_polynomial_kernel_computation")
			run_test (agent l_tests.test_svm_polynomial_training, "test_svm_polynomial_training")
			run_test (agent l_tests.test_svm_polynomial_prediction, "test_svm_polynomial_prediction")

			-- New algorithm tests
			run_test (agent l_tests.test_knn_classifier_creation, "test_knn_classifier_creation")
			run_test (agent l_tests.test_knn_classifier_k_setting, "test_knn_classifier_k_setting")
			run_test (agent l_tests.test_knn_classifier_training, "test_knn_classifier_training")
			run_test (agent l_tests.test_knn_classifier_prediction, "test_knn_classifier_prediction")
			run_test (agent l_tests.test_naive_bayes_classifier_creation, "test_naive_bayes_classifier_creation")
			run_test (agent l_tests.test_naive_bayes_classifier_training, "test_naive_bayes_classifier_training")
			run_test (agent l_tests.test_naive_bayes_classifier_prediction, "test_naive_bayes_classifier_prediction")
			run_test (agent l_tests.test_gradient_boosting_classifier_creation, "test_gradient_boosting_classifier_creation")
			run_test (agent l_tests.test_gradient_boosting_configuration, "test_gradient_boosting_configuration")
			run_test (agent l_tests.test_gradient_boosting_classifier_training, "test_gradient_boosting_classifier_training")
			run_test (agent l_tests.test_gradient_boosting_classifier_prediction, "test_gradient_boosting_classifier_prediction")

			-- Adversarial tests: Regularization
			run_test (agent l_tests.test_linear_regression_regularized_extreme_lambda, "test_linear_regression_regularized_extreme_lambda")
			run_test (agent l_tests.test_linear_regression_regularized_elastic_net, "test_linear_regression_regularized_elastic_net")
			run_test (agent l_tests.test_logistic_regression_regularized_large_lambda, "test_logistic_regression_regularized_large_lambda")

			-- Adversarial tests: Model Selection
			run_test (agent l_tests.test_k_fold_splitter_boundary_k, "test_k_fold_splitter_boundary_k")
			run_test (agent l_tests.test_k_fold_splitter_large_k, "test_k_fold_splitter_large_k")
			run_test (agent l_tests.test_grid_search_cv_minimal_data, "test_grid_search_cv_minimal_data")

			-- Adversarial tests: Kernel Methods
			run_test (agent l_tests.test_svm_rbf_extreme_gamma_small, "test_svm_rbf_extreme_gamma_small")
			run_test (agent l_tests.test_svm_rbf_extreme_gamma_large, "test_svm_rbf_extreme_gamma_large")
			run_test (agent l_tests.test_svm_polynomial_high_degree, "test_svm_polynomial_high_degree")
			run_test (agent l_tests.test_svm_polynomial_zero_coef0, "test_svm_polynomial_zero_coef0")

			-- Adversarial tests: New Algorithms
			run_test (agent l_tests.test_knn_classifier_extreme_k, "test_knn_classifier_extreme_k")
			run_test (agent l_tests.test_knn_classifier_identical_neighbors, "test_knn_classifier_identical_neighbors")
			run_test (agent l_tests.test_naive_bayes_identical_features, "test_naive_bayes_identical_features")
			run_test (agent l_tests.test_gradient_boosting_single_estimator, "test_gradient_boosting_single_estimator")
			run_test (agent l_tests.test_gradient_boosting_many_estimators, "test_gradient_boosting_many_estimators")

			print ("%N")
		end

end
