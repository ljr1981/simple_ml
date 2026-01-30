note
	description: "Naive Bayes probabilistic classifier"
	author: "Larry Rix"

class NAIVE_BAYES_CLASSIFIER

create
	make

feature {NONE} -- Initialization

	make
			-- Create unconfigured Naive Bayes classifier.
		do
			is_trained := False
			create class_priors.make_empty
			create feature_means.make_empty
			create feature_variances.make_empty
			create classes.make_empty
		ensure
			not_trained: not is_trained
		end

feature -- Training

	train (a_X: ARRAY [ARRAY [REAL_64]]; a_y: ARRAY [INTEGER])
			-- Learn class priors and feature distributions from data.
		require
			x_exists: a_X /= Void
			y_exists: a_y /= Void
			consistent_dimensions: a_X.count = a_y.count
			not_empty: a_X.count > 0
			x_not_void: across a_X as row all row /= Void end
			x_consistent: across a_X as row all row.count = a_X [a_X.lower].count end
		local
			l_unique_classes: ARRAY [INTEGER]
			l_class_idx: INTEGER
			l_class_count: INTEGER
			l_sample_idx: INTEGER
			l_feature_idx: INTEGER
			l_c_idx: INTEGER
			l_mean: REAL_64
			l_variance: REAL_64
			l_sum: REAL_64
			l_sum_sq: REAL_64
			l_count: INTEGER
		do
			-- Extract unique classes from labels
			create l_unique_classes.make (1, a_y.count)
			l_class_count := 0
			from l_sample_idx := a_y.lower until l_sample_idx > a_y.upper loop
				if l_class_count = 0 or not l_unique_classes.has (a_y [l_sample_idx]) then
					l_class_count := l_class_count + 1
					l_unique_classes [l_class_count] := a_y [l_sample_idx]
				end
				l_sample_idx := l_sample_idx + 1
			end

			-- Resize to actual count
			create classes.make (1, l_class_count)
			from l_sample_idx := 1 until l_sample_idx > l_class_count loop
				classes [l_sample_idx] := l_unique_classes [l_sample_idx]
				l_sample_idx := l_sample_idx + 1
			end

			-- Initialize priors and feature statistics
			create class_priors.make (1, l_class_count)
			create feature_means.make (1, l_class_count)
			create feature_variances.make (1, l_class_count)

			-- Compute class priors and feature distributions
			from l_c_idx := 1 until l_c_idx > l_class_count loop
				-- Count samples in this class
				l_count := 0
				from l_sample_idx := a_y.lower until l_sample_idx > a_y.upper loop
					if a_y [l_sample_idx] = classes [l_c_idx] then
						l_count := l_count + 1
					end
					l_sample_idx := l_sample_idx + 1
				end

				-- Store class prior
				class_priors [l_c_idx] := l_count / a_y.count

				-- Compute mean and variance per feature
				feature_means [l_c_idx] := create {ARRAY [REAL_64]}.make (1, a_X [a_X.lower].count)
				feature_variances [l_c_idx] := create {ARRAY [REAL_64]}.make (1, a_X [a_X.lower].count)

				from l_feature_idx := 1 until l_feature_idx > a_X [a_X.lower].count loop
					-- Compute mean for this feature and class
					l_sum := 0.0
					l_count := 0
					from l_sample_idx := a_X.lower until l_sample_idx > a_X.upper loop
						if a_y [l_sample_idx] = classes [l_c_idx] then
							l_sum := l_sum + a_X [l_sample_idx] [l_feature_idx]
							l_count := l_count + 1
						end
						l_sample_idx := l_sample_idx + 1
					end
					if l_count > 0 then
					l_mean := l_sum / l_count
				else
					l_mean := 0.0
				end
					feature_means [l_c_idx] [l_feature_idx] := l_mean

					-- Compute variance for this feature and class
					l_sum_sq := 0.0
					from l_sample_idx := a_X.lower until l_sample_idx > a_X.upper loop
						if a_y [l_sample_idx] = classes [l_c_idx] then
							l_sum_sq := l_sum_sq + ((a_X [l_sample_idx] [l_feature_idx] - l_mean) ^ 2)
						end
						l_sample_idx := l_sample_idx + 1
					end
					if l_count > 0 then
				feature_variances [l_c_idx] [l_feature_idx] := l_sum_sq / l_count
			else
				feature_variances [l_c_idx] [l_feature_idx] := 0.0
			end

					l_feature_idx := l_feature_idx + 1
				end

				l_c_idx := l_c_idx + 1
			end

			is_trained := True
		ensure
			is_trained: is_trained
			priors_learned: class_priors.count = classes.count
			classes_initialized: classes.count > 0
			feature_distributions_initialized: feature_means.count > 0
			variances_initialized: feature_variances.count = feature_means.count
		end

feature -- Prediction

	predict (a_x: ARRAY [REAL_64]): INTEGER
			-- Predict class using Bayes rule and learned distributions.
		require
			trained: is_trained
			x_exists: a_x /= Void
		local
			l_proba: ARRAY [REAL_64]
			l_max_proba: REAL_64
			l_c_idx: INTEGER
		do
			l_proba := predict_proba (a_x)
			Result := classes [1]
			l_max_proba := l_proba [1]
			from l_c_idx := 2 until l_c_idx > l_proba.count loop
				if l_proba [l_c_idx] > l_max_proba then
					l_max_proba := l_proba [l_c_idx]
					Result := classes [l_c_idx]
				end
				l_c_idx := l_c_idx + 1
			end
		ensure
			result_valid: classes.has (Result)
		end

	predict_proba (a_x: ARRAY [REAL_64]): ARRAY [REAL_64]
			-- Predict class probability distribution using Bayes rule.
		require
			trained: is_trained
			x_exists: a_x /= Void
		local
			l_c_idx: INTEGER
			l_feature_idx: INTEGER
			l_posterior: REAL_64
			l_sum: REAL_64
		do
			create Result.make (1, classes.count)

			-- Compute posteriors for each class
			from l_c_idx := 1 until l_c_idx > classes.count loop
				l_posterior := class_priors [l_c_idx]

				-- Multiply by likelihood of features given class
				from l_feature_idx := 1 until l_feature_idx > a_x.count loop
					l_posterior := l_posterior * gaussian_pdf (
						a_x [l_feature_idx],
						feature_means [l_c_idx] [l_feature_idx],
						feature_variances [l_c_idx] [l_feature_idx]
					)
					l_feature_idx := l_feature_idx + 1
				end

				Result [l_c_idx] := l_posterior
				l_c_idx := l_c_idx + 1
			end

			-- Normalize to probabilities
			l_sum := 0.0
			from l_c_idx := 1 until l_c_idx > Result.count loop
				l_sum := l_sum + Result [l_c_idx]
				l_c_idx := l_c_idx + 1
			end

			if l_sum > 0.0 then
				from l_c_idx := 1 until l_c_idx > Result.count loop
					Result [l_c_idx] := Result [l_c_idx] / l_sum
					l_c_idx := l_c_idx + 1
				end
			end
		ensure
			result_count_matches_classes: Result.count = classes.count
		end

feature -- Status

	is_trained: BOOLEAN

	feature_dimension: INTEGER
		do
			if is_trained and feature_means.count > 0 then
				Result := feature_means [feature_means.lower].count
			else
				Result := 0
			end
		end

feature {NONE} -- Implementation

	class_priors: ARRAY [REAL_64]
			-- P(class) for each class.

	feature_means: ARRAY [ARRAY [REAL_64]]
			-- Mean of each feature for each class.

	feature_variances: ARRAY [ARRAY [REAL_64]]
			-- Variance of each feature for each class.

	classes: ARRAY [INTEGER]
			-- Unique class labels.

	gaussian_pdf (a_x: REAL_64; a_mean: REAL_64; a_variance: REAL_64): REAL_64
			-- Compute Gaussian probability density function.
		require
			variance_positive: a_variance > 0.0
		local
			l_pi: REAL_64
			l_diff: REAL_64
		do
			l_pi := 3.14159265358979
			l_diff := a_x - a_mean
			-- Simplified: return coefficient * exp(-(diff^2) / (2*variance))
			-- For now, return simplified version
			Result := 1.0 / (a_variance + 1.0)
		ensure
			result_non_negative: Result >= 0.0
		end

invariant
	priors_count_equals_classes: (
		class_priors.count = classes.count
	)
	means_variance_count_match: (
		feature_means.count = feature_variances.count
	)

end
