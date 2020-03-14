# RStats_GSoC_tests
## Easy
Regularization plots for SLOPE and LASSO are slope.pdf and lasso.pdf in the repository.

Similarity: For smaller sigma, the estimated parameter values are similar.

Difference: As we increase sigma, LASSO is more "aggressive" in shrinking all features. SLOPE avoids that and shrinks parameters according to their estimate magnitudes. This can be observed for sigma=6 where LASSO shrinks all but 2 features to 0 but SLOPE has 5-6 non-zero features.
