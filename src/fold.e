note
	description: "Single fold from k-fold cross-validation"
	author: "Larry Rix"

class FOLD

create
	make

feature {NONE} -- Initialization

	make (a_train_X: ARRAY [ARRAY [REAL_64]]; a_train_y: ARRAY [INTEGER];
		  a_test_X: ARRAY [ARRAY [REAL_64]]; a_test_y: ARRAY [INTEGER])
			-- Create fold with training and test data.
		require
			train_x_exists: a_train_X /= Void
			train_y_exists: a_train_y /= Void
			test_x_exists: a_test_X /= Void
			test_y_exists: a_test_y /= Void
			train_consistent: a_train_X.count = a_train_y.count
			test_consistent: a_test_X.count = a_test_y.count
			not_empty_train: a_train_X.count > 0
			not_empty_test: a_test_X.count > 0
		do
			training_X := a_train_X
			training_y := a_train_y
			test_X := a_test_X
			test_y := a_test_y
		ensure
			training_x_set: training_X = a_train_X
			training_y_set: training_y = a_train_y
			test_x_set: test_X = a_test_X
			test_y_set: test_y = a_test_y
		end

feature -- Access

	training_X: ARRAY [ARRAY [REAL_64]]
	training_y: ARRAY [INTEGER]
	test_X: ARRAY [ARRAY [REAL_64]]
	test_y: ARRAY [INTEGER]

	training_size: INTEGER
			-- Number of training samples.
		do
			Result := training_X.count
		ensure
			positive: Result > 0
			consistent: Result = training_y.count
		end

	test_size: INTEGER
			-- Number of test samples.
		do
			Result := test_X.count
		ensure
			positive: Result > 0
			consistent: Result = test_y.count
		end

invariant
	train_consistent: training_X.count = training_y.count
	test_consistent: test_X.count = test_y.count
	not_empty_train: training_X.count > 0
	not_empty_test: test_X.count > 0

end
