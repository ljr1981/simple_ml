note
	description: "Unit tests for ACTIVATION_FUNCTIONS class"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class TEST_ACTIVATION_FUNCTIONS

inherit
	EQA_TEST_SET

feature -- Tests

	test_sigmoid_zero
			-- Test sigmoid(0) = 0.5
		local
			l_act: ACTIVATION_FUNCTIONS
		do
			create l_act.make
			assert ("sigmoid(0) = 0.5", (l_act.sigmoid (0.0) - 0.5).abs < 0.0001)
		end

	test_sigmoid_large_positive
			-- Test sigmoid(10) ≈ 1.0
		local
			l_act: ACTIVATION_FUNCTIONS
		do
			create l_act.make
			assert ("sigmoid(10) ≈ 1", (l_act.sigmoid (10.0) - 1.0).abs < 0.001)
		end

	test_sigmoid_large_negative
			-- Test sigmoid(-10) ≈ 0.0
		local
			l_act: ACTIVATION_FUNCTIONS
		do
			create l_act.make
			assert ("sigmoid(-10) ≈ 0", l_act.sigmoid (-10.0).abs < 0.001)
		end

	test_sigmoid_derivative_zero
			-- Test sigmoid'(0) = 0.25
		local
			l_act: ACTIVATION_FUNCTIONS
		do
			create l_act.make
			assert ("sigmoid'(0) = 0.25", (l_act.sigmoid_derivative (0.0) - 0.25).abs < 0.0001)
		end

	test_relu_positive
			-- Test relu(5) = 5
		local
			l_act: ACTIVATION_FUNCTIONS
		do
			create l_act.make
			assert ("relu(5) = 5", l_act.relu (5.0) = 5.0)
		end

	test_relu_negative
			-- Test relu(-5) = 0
		local
			l_act: ACTIVATION_FUNCTIONS
		do
			create l_act.make
			assert ("relu(-5) = 0", l_act.relu (-5.0) = 0.0)
		end

	test_rbf_kernel_zero_distance
			-- Test rbf_kernel(0, gamma) = 1
		local
			l_act: ACTIVATION_FUNCTIONS
		do
			create l_act.make
			assert ("rbf(0, gamma) = 1", (l_act.rbf_kernel (0.0, 1.0) - 1.0).abs < 0.0001)
		end

	test_gaussian_pdf_at_mean
			-- Test gaussian PDF at mean returns correct normalization factor
		local
			l_act: ACTIVATION_FUNCTIONS
			l_result: REAL_64
			l_expected: REAL_64
		do
			create l_act.make
			l_result := l_act.gaussian_pdf (5.0, 5.0, 1.0)
			-- At mean with variance 1, should be 1/sqrt(2π) ≈ 0.3989
			l_expected := 0.3989422804
			assert ("gaussian at mean", (l_result - l_expected).abs < 0.001)
		end

	test_tanh_zero
			-- Test tanh(0) = 0
		local
			l_act: ACTIVATION_FUNCTIONS
		do
			create l_act.make
			assert ("tanh(0) = 0", l_act.tanh (0.0).abs < 0.0001)
		end

end
