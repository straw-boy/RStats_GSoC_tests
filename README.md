# RStats_GSoC_tests
## Easy
Regularization plots for SLOPE and LASSO are slope.pdf and lasso.pdf in the repository.

Similarity: For smaller sigma, the estimated parameter values are similar.

Difference: As we increase sigma, LASSO is more "aggressive" in shrinking all features. SLOPE avoids that and shrinks parameters according to their estimate magnitudes. This can be observed for sigma=6 where LASSO shrinks all but 2 features to 0 but SLOPE has 5-6 non-zero features.

Question : Why does LASSO drop some coefficients but SLOPE retains them?

Answer : Constraint region for LASSO is a uniform polygon. Optimum solutions occur at the corners which lie on the axes. So LASSO sets the feature values to 0. But in SLOPE, constraint region, albeit a polygon, is not uniform. This gives rise to a greater possibility of finding a solution which is not a corner point for many features. 
## Medium
```fastProxSl1.cpp``` contains my implementation for FastProxSL1 algorithm in armadillo.

medium.r's "run_experiment" function first generates y randomly, lambda using library function of SLOPE package and then runs both FastProxSL1 and Prox_Sorted_L1 algorithms and prints the execution time of given number of iterations. Execution time of FastProxSL1 is faster by 5-6 times but for sequence length 1000000, it suddenly becomes slower than Prox_Sorted_L1 ( though it is of same order). Currently, I am not able to account for this behaviour. My output on running ```medium.r``` is as follows:
```
[1] "Average execution time for sequence length= 100 and 100 iterations"
[1] "FastProxSL1 :"
   user  system elapsed 
  0.002   0.000   0.002 
[1] "Prox_Sorted_L1 : "
   user  system elapsed 
  0.004   0.000   0.006 
[1] "Average execution time for sequence length= 1000 and 100 iterations"
[1] "FastProxSL1 :"
   user  system elapsed 
  0.002   0.002   0.004 
[1] "Prox_Sorted_L1 : "
   user  system elapsed 
  0.013   0.004   0.022 
[1] "Average execution time for sequence length= 10000 and 100 iterations"
[1] "FastProxSL1 :"
   user  system elapsed 
  0.010   0.003   0.014 
[1] "Prox_Sorted_L1 : "
   user  system elapsed 
  0.089   0.005   0.092 
[1] "Average execution time for sequence length= 1e+05 and 100 iterations"
[1] "FastProxSL1 :"
   user  system elapsed 
  0.114   0.002   0.116 
[1] "Prox_Sorted_L1 : "
   user  system elapsed 
  0.837   0.018   0.856 
[1] "Average execution time for sequence length= 1e+06 and 100 iterations"
[1] "FastProxSL1 :"
   user  system elapsed 
 12.569   0.296  12.868 
[1] "Prox_Sorted_L1 : "
   user  system elapsed 
 11.709   0.604  12.316 
```
