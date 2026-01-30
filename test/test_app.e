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

			run_linear_regression_tests
			run_logistic_regression_tests
			run_decision_tree_tests
			run_random_forest_tests
			run_svm_tests
			run_neural_network_tests

			print ("%N========================%N")
			print ("Results: " + passed.out + " passed, " + failed.out + " failed%N")

			if failed > 0 then
				print ("TESTS FAILED%N")
			else
				print ("ALL TESTS PASSED%N")
			end
		end

feature {NONE} -- Test Runners

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

end
