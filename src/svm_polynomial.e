note
	description: "Support Vector Machine with polynomial kernel"
	author: "Larry Rix"

class SVM_POLYNOMIAL

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured polynomial-SVM model.
		do
			is_trained := False
			c_param := 1.0
			degree := 3
			coef0 := 1.0
			gamma := 0.01
			tolerance := 0.001
			create support_vectors.make_empty
			create support_vector_coefficients.make_empty
			create classes.make_empty
			bias := 0.0
		ensure
			not_trained: not is_trained
			c_param_positive: c_param > 0.0
			degree_positive: degree > 0
			coef0_non_negative: coef0 >= 0.0
		end

feature -- Configuration

	set_c_param (a_c: REAL_64): like Current
		require
			positive_c: a_c > 0.0
		do
			c_param := a_c
			Result := Current
		ensure
			c_set: c_param = a_c
		end

	set_degree (a_degree: INTEGER): like Current
			-- Set polynomial degree.
		require
			positive_degree: a_degree > 0
		do
			degree := a_degree
			Result := Current
		ensure
			degree_set: degree = a_degree
		end

	set_coef0 (a_coef: REAL_64): like Current
			-- Set independent coefficient.
		require
			non_negative_coef: a_coef >= 0.0
		do
			coef0 := a_coef
			Result := Current
		ensure
			coef_set: coef0 = a_coef
		end

	set_gamma (a_gamma: REAL_64): like Current
		require
			positive_gamma: a_gamma > 0.0
		do
			gamma := a_gamma
			Result := Current
		ensure
			gamma_set: gamma = a_gamma
		end

feature -- Training

	train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Train polynomial-SVM using kernel trick.
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
			create l_unique_classes.make_filled (0, 1, a_y.count)
			l_class_count := 0
			from l_i := a_y.lower until l_i > a_y.upper loop
				if l_class_count = 0 or not l_unique_classes.has (a_y [l_i]) then
					l_class_count := l_class_count + 1
					l_unique_classes [l_class_count] := a_y [l_i]
				end
				l_i := l_i + 1
			end

			-- Store classes
			create classes.make_filled (0, 1, l_class_count)
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
			-- Predict class for feature vector.
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
			-- Compute decision function.
		require
			trained: is_trained
			x_exists: a_x /= Void
		local
			l_i: INTEGER
		do
			Result := bias
			from l_i := 1 until l_i > support_vectors.count loop
				Result := Result + support_vector_coefficients [l_i] * polynomial_kernel (a_x, support_vectors [l_i])
				l_i := l_i + 1
			end
		ensure
		end

feature -- Kernel Operations

	polynomial_kernel (a_x1, a_x2: ARRAY [REAL_64]): REAL_64
			-- Compute polynomial kernel: (gamma * x1·x2 + coef0)^degree.
		require
			x1_exists: a_x1 /= Void
			x2_exists: a_x2 /= Void
			same_dimension: a_x1.count = a_x2.count
		local
			l_dot_product: REAL_64
			l_i: INTEGER
			l_kernel_val: REAL_64
			l_d: INTEGER
		do
			-- Compute dot product x1 · x2
			l_dot_product := 0.0
			from l_i := 1 until l_i > a_x1.count loop
				l_dot_product := l_dot_product + a_x1 [l_i] * a_x2 [l_i]
				l_i := l_i + 1
			end

			-- Polynomial kernel: (gamma * dot + coef0)^degree
			l_kernel_val := gamma * l_dot_product + coef0
			Result := 1.0

			from l_d := 1 until l_d > degree loop
				Result := Result * l_kernel_val
				l_d := l_d + 1
			end
		ensure
		end

feature -- Status

	is_trained: BOOLEAN

	feature_dimension: INTEGER
		do
			if is_trained and support_vectors.count > 0 then
				Result := support_vectors [support_vectors.lower].count
			else
				Result := 0
			end
		end

feature -- Configuration

	gamma: REAL_64
	degree: INTEGER
	coef0: REAL_64

feature {NONE} -- Implementation

	c_param: REAL_64
	tolerance: REAL_64
	support_vectors: ARRAY [ARRAY [REAL_64]]
	support_vector_coefficients: ARRAY [REAL_64]
	classes: ARRAY [INTEGER]
	bias: REAL_64

invariant
	c_param_positive: c_param > 0.0
	degree_positive: degree > 0
	coef0_non_negative: coef0 >= 0.0
	gamma_positive: gamma > 0.0
	tolerance_positive: tolerance > 0.0

end
