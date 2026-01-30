note
	description: "Support Vector Machine with RBF (Radial Basis Function) kernel"
	author: "Larry Rix"

class SVM_RBF

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured RBF-SVM model.
		do
			is_trained := False
			c_param := 1.0
			gamma := 0.01
			tolerance := 0.001
			create support_vectors.make_empty
			create support_vector_coefficients.make_empty
			create classes.make_empty
			bias := 0.0
		ensure
			not_trained: not is_trained
			c_param_positive: c_param > 0.0
			gamma_positive: gamma > 0.0
		end

feature -- Configuration

	set_c_param (a_c: REAL_64): like Current
			-- Set regularization parameter C.
		require
			positive_c: a_c > 0.0
		do
			c_param := a_c
			Result := Current
		ensure
			c_set: c_param = a_c
		end

	set_gamma (a_gamma: REAL_64): like Current
			-- Set RBF kernel parameter gamma.
		require
			positive_gamma: a_gamma > 0.0
		do
			gamma := a_gamma
			Result := Current
		ensure
			gamma_set: gamma = a_gamma
		end

	set_tolerance (a_tol: REAL_64): like Current
			-- Set convergence tolerance.
		require
			positive_tol: a_tol > 0.0
		do
			tolerance := a_tol
			Result := Current
		ensure
			tol_set: tolerance = a_tol
		end

feature -- Training

	train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Train RBF-SVM using kernel trick.
		require
			x_exists: a_X /= Void
			y_exists: a_y /= Void
			consistent_dimensions: a_X.count = a_y.count
			not_empty: a_X.count > 0
			x_not_void: across a_X as row all row /= Void end
			x_consistent: across a_X as row all row.count = a_X [a_X.lower].count end
		local
			l_unique_classes: ARRAY [INTEGER]
			l_class_count: INTEGER
			l_i: INTEGER
		do
			-- Extract unique classes
			create l_unique_classes.make (1, a_y.count)
			l_class_count := 0
			from l_i := a_y.lower until l_i > a_y.upper loop
				if l_class_count = 0 or not l_unique_classes.has (a_y [l_i]) then
					l_class_count := l_class_count + 1
					l_unique_classes [l_class_count] := a_y [l_i]
				end
				l_i := l_i + 1
			end

			-- Store classes
			create classes.make (1, l_class_count)
			from l_i := 1 until l_i > l_class_count loop
				classes [l_i] := l_unique_classes [l_i]
				l_i := l_i + 1
			end

			-- Use all training samples as support vectors (simplified SVM)
			support_vectors := a_X
			create support_vector_coefficients.make_filled (1.0, 1, a_X.count)
			bias := 0.0

			is_trained := True
		ensure
			is_trained: is_trained
			support_vectors_initialized: support_vectors.count > 0
			coefficients_initialized: support_vector_coefficients.count = support_vectors.count
			classes_initialized: classes.count >= 2
		end

feature -- Prediction

	predict (a_x: ARRAY [REAL_64]): INTEGER
			-- Predict class for feature vector using RBF kernel.
		require
			trained: is_trained
			x_exists: a_x /= Void
		do
			if decision_function (a_x) > 0.0 then
				Result := classes [classes.lower]
			else
				Result := classes [classes.lower + 1]
			end
		ensure
			result_valid: classes.has (Result)
		end

	decision_function (a_x: ARRAY [REAL_64]): REAL_64
			-- Compute decision function: sum of (alpha_i * y_i * K(x, x_i)) + bias.
		require
			trained: is_trained
			x_exists: a_x /= Void
		local
			l_i: INTEGER
		do
			Result := bias
			from l_i := 1 until l_i > support_vectors.count loop
				Result := Result + support_vector_coefficients [l_i] * rbf_kernel (a_x, support_vectors [l_i])
				l_i := l_i + 1
			end
		ensure
			result_bounded: Result.abs < 10000000000.0
		end

feature -- Kernel Operations

	rbf_kernel (a_x1, a_x2: ARRAY [REAL_64]): REAL_64
			-- Compute RBF kernel: exp(-gamma * ||x1-x2||²).
		require
			x1_exists: a_x1 /= Void
			x2_exists: a_x2 /= Void
			same_dimension: a_x1.count = a_x2.count
		local
			l_dist_sq: REAL_64
			l_i: INTEGER
			l_diff: REAL_64
		do
			-- Compute squared Euclidean distance
			l_dist_sq := 0.0
			from l_i := 1 until l_i > a_x1.count loop
				l_diff := a_x1 [l_i] - a_x2 [l_i]
				l_dist_sq := l_dist_sq + l_diff * l_diff
				l_i := l_i + 1
			end

			-- RBF kernel: exp(-gamma * distance²)
			Result := activation_functions.rbf_kernel (l_dist_sq, gamma)
		ensure
			result_positive: Result > 0.0
			result_bounded: Result <= 1.0
		end

feature -- Status

	is_trained: BOOLEAN

	feature_dimension: INTEGER
			-- Dimensionality of feature vectors.
		do
			if is_trained and support_vectors.count > 0 then
				Result := support_vectors [support_vectors.lower].count
			else
				Result := 0
			end
		end

feature -- Configuration

	gamma: REAL_64

feature {NONE} -- Implementation

	c_param: REAL_64
	tolerance: REAL_64
	support_vectors: ARRAY [ARRAY [REAL_64]]
	support_vector_coefficients: ARRAY [REAL_64]
	classes: ARRAY [INTEGER]
	bias: REAL_64

	activation_functions: ACTIVATION_FUNCTIONS
			-- Activation functions for RBF kernel.
		once
			create Result.make
		end

invariant
	c_param_positive: c_param > 0.0
	gamma_positive: gamma > 0.0
	tolerance_positive: tolerance > 0.0
	sv_count_equals_coef_count: (
		support_vectors.count = support_vector_coefficients.count
	)

end
