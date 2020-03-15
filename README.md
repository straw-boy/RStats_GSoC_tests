# RStats_GSoC_tests
## Easy
Regularization plots for SLOPE and LASSO are slope.pdf and lasso.pdf in the repository.

Similarity: For smaller sigma, the estimated parameter values are similar.

Difference: As we increase sigma, LASSO is more "aggressive" in shrinking all features. SLOPE avoids that and shrinks parameters according to their estimate magnitudes. This can be observed for sigma=6 where LASSO shrinks all but 2 features to 0 but SLOPE has 5-6 non-zero features.

## Medium
fastProxSl1.cpp contains my implementation for FastProxSL1 algorithm in armadillo.

medium.r's "run_experiment" function first generates y randomly, lambda using library function of SLOPE package and then runs both FastProxSL1 and Prox_Sorted_L1 algorithms and prints the execution time of given number of iterations. Execution time of FastProxSL1 is faster by 5-6 times but for sequence length 1000000, it suddenly becomes slower than Prox_Sorted_L1 ( though it is of same order). Currently, I am not able to account for this behaviour.
