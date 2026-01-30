note
	description: "Real mathematical activation functions for neural networks and ML models"
	author: "Larry Rix"
	date: "$Date$"
	revision: "$Revision$"

class ACTIVATION_FUNCTIONS

inherit
	ANY

create
	make

feature {NONE} -- Initialization

	make
			-- Initialize activation functions.
		do
			create l_math.make
		end

feature -- Sigmoid family

	sigmoid (z: REAL_64): REAL_64
			-- Sigmoid: σ(z) = 1/(1 + exp(-z))
			-- Clips to prevent overflow in exp calculation.
		require
			not_nan: not z.is_nan
		local
			l_exp_neg_z: REAL_64
		do
			-- Clip to prevent overflow
			if z > 500.0 then
				Result := 1.0
			elseif z < -500.0 then
				Result := 0.0
			else
				l_exp_neg_z := l_math.exp (-z)
				Result := 1.0 / (1.0 + l_exp_neg_z)
			end
		ensure
			in_range: Result > 0.0 and Result < 1.0
		end

	sigmoid_derivative (z: REAL_64): REAL_64
			-- Sigmoid derivative: σ'(z) = σ(z) * (1 - σ(z))
		local
			l_sig: REAL_64
		do
			l_sig := sigmoid (z)
			Result := l_sig * (1.0 - l_sig)
		ensure
			non_negative: Result >= 0.0
		end

feature -- Hyperbolic tangent

	tanh (z: REAL_64): REAL_64
			-- tanh(z) = (exp(z) - exp(-z))/(exp(z) + exp(-z))
			-- Clips to prevent overflow.
		require
			not_nan: not z.is_nan
		local
			l_exp_pos, l_exp_neg: REAL_64
		do
			if z > 20.0 then
				Result := 1.0
			elseif z < -20.0 then
				Result := -1.0
			else
				l_exp_pos := l_math.exp (z)
				l_exp_neg := l_math.exp (-z)
				Result := (l_exp_pos - l_exp_neg) / (l_exp_pos + l_exp_neg)
			end
		ensure
			in_range: Result > -1.0 and Result < 1.0
		end

	tanh_derivative (z: REAL_64): REAL_64
			-- tanh derivative: tanh'(z) = 1 - tanh²(z)
		local
			l_tanh: REAL_64
		do
			l_tanh := tanh (z)
			Result := 1.0 - l_tanh * l_tanh
		ensure
			non_negative: Result >= 0.0
		end

feature -- ReLU family

	relu (z: REAL_64): REAL_64
			-- ReLU (Rectified Linear Unit): max(0, z)
		do
			if z > 0.0 then
				Result := z
			else
				Result := 0.0
			end
		ensure
			non_negative: Result >= 0.0
			zero_or_same: (z <= 0.0 and Result = 0.0) or (z > 0.0 and Result = z)
		end

	relu_derivative (z: REAL_64): REAL_64
			-- ReLU derivative: 1 if z > 0, else 0
		do
			if z > 0.0 then
				Result := 1.0
			else
				Result := 0.0
			end
		ensure
			binary: Result = 0.0 or Result = 1.0
		end

feature -- Probability distributions

	gaussian_pdf (x, mean, variance: REAL_64): REAL_64
			-- Gaussian (normal) probability density function.
			-- N(x|μ,σ²) = (1/sqrt(2πσ²)) * exp(-(x-μ)²/(2σ²))
		require
			variance_positive: variance > 0.0
		local
			l_diff, l_exponent, l_normalization: REAL_64
		do
			l_diff := x - mean
			l_exponent := -(l_diff * l_diff) / (2.0 * variance)
			l_normalization := 1.0 / l_math.sqrt (2.0 * l_math.pi * variance)
			Result := l_normalization * l_math.exp (l_exponent)
		ensure
			positive: Result > 0.0
		end

feature -- Kernel functions

	rbf_kernel (distance_squared, gamma: REAL_64): REAL_64
			-- RBF (Radial Basis Function) kernel: K(x,y) = exp(-gamma * ||x-y||²)
		require
			distance_non_negative: distance_squared >= 0.0
			gamma_positive: gamma > 0.0
		local
			l_exponent: REAL_64
		do
			l_exponent := -gamma * distance_squared
			-- Clip to prevent underflow
			if l_exponent < -500.0 then
				Result := 0.0
			else
				Result := l_math.exp (l_exponent)
			end
		ensure
			in_range: Result > 0.0 and Result <= 1.0
		end

feature {NONE} -- Implementation

	l_math: SIMPLE_MATH
			-- Shared math library instance

invariant
	math_not_void: l_math /= Void

end
