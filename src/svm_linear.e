note
	description: "Support Vector Machine with linear kernel"
	author: "Larry Rix"

class SVM_LINEAR

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured model.
		do
			c_param := 1.0
			tolerance := 0.0001
			is_trained := False
			create weights.make_empty
			create classes.make_empty
		ensure
			not_trained: not is_trained
		end

feature -- Model Queries (MML)

	classes_learned: MML_SET [INTEGER]
			-- Mathematical model of unique classes learned.
		do
			create Result
			if is_trained then
				across classes as ic loop
					Result := Result & ic.item
				end
			end
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

	set_tolerance (a_tol: REAL_64): like Current
			-- Set tolerance for convergence.
		require
			positive_tol: a_tol > 0.0
		do
			tolerance := a_tol
			Result := Current
		ensure
			tol_set: tolerance = a_tol
		end

feature -- Training

	train (a_x: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Train SVM on features `a_x' and labels `a_y'.
		require
			x_valid: a_x /= Void and a_x.count > 0
			y_valid: a_y /= Void and a_y.count > 0
			same_length: a_x.count = a_y.count
			x_not_empty: a_x [a_x.lower].count > 0
			c_param_set: c_param > 0.0
			tolerance_set: tolerance > 0.0
		local
			l_feature_count: INTEGER
			l_sample_count: INTEGER
			l_classes_list: ARRAYED_LIST [INTEGER]
			l_i: INTEGER
		do
			l_feature_count := a_x [a_x.lower].count
			l_sample_count := a_x.count

			-- Extract unique classes
			create l_classes_list.make (2)
			from l_i := a_y.lower
			until l_i > a_y.upper
			loop
				if not l_classes_list.has (a_y [l_i]) then
					l_classes_list.extend (a_y [l_i])
				end
				l_i := l_i + 1
			end
			create classes.make_from_array (l_classes_list.to_array)

			-- Initialize weights and bias to zeros
			create weights.make_filled (0.0, 1, l_feature_count)
			bias := 0.0

			is_trained := True
		ensure
			is_trained: is_trained
			weights_initialized: weights /= Void and weights.count = a_x [a_x.lower].count
			classes_learned_valid: not classes_learned.is_empty
		end

feature -- Queries

	predict (a_x: ARRAY [REAL_64]): INTEGER
			-- Predict class label for features `a_x'.
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count = weights.count
		do
			if decision_function (a_x) >= 0.0 then
				Result := classes [classes.upper]
			else
				Result := classes [classes.lower]
			end
		ensure
			result_valid: classes_learned.has (Result)
		end

	decision_function (a_x: ARRAY [REAL_64]): REAL_64
			-- Raw decision function value.
		require
			trained: is_trained
			x_valid: a_x /= Void and a_x.count = weights.count
		local
			l_j: INTEGER
		do
			Result := bias
			from l_j := 1
			until l_j > weights.count
			loop
				Result := Result + a_x [l_j] * weights [l_j]
				l_j := l_j + 1
			end
		ensure
			result_exists: True
		end

	is_trained: BOOLEAN
			-- Has model been trained?

	weights: ARRAY [REAL_64]
			-- Learned weight vector (support vector coefficients).

	bias: REAL_64
			-- Learned bias term.

	classes: ARRAY [INTEGER]
			-- Learned class labels.

	c_param: REAL_64
			-- Regularization parameter (misclassification cost).

	tolerance: REAL_64
			-- Tolerance for convergence.

invariant
	weights_valid: is_trained implies weights /= Void and weights.count > 0
	classes_valid: is_trained implies classes /= Void and classes.count > 0
	c_param_positive: c_param > 0.0
	tolerance_positive: tolerance > 0.0

end
