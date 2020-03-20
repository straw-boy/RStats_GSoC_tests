library("devtools")
library("owl")
library("SLOPE")
library("Rcpp")
sourceCpp("/home/akarsh/owl/owl_imp.cpp")

setwd("/home/akarsh/RStats_GSoC_tests/SlopeSolver")
load_all()

lambda = create_lambda(1,dim(bodyfat$x)[2])

x = data.matrix(bodyfat$x)

beta1 = solveSlope(x,bodyfat$y,0*lambda)
print(beta1)
beta2 = solveSlope(x,bodyfat$y,100*lambda)
print(beta2)

# fit <- owl(bodyfat$x, bodyfat$y)
# print(fit$coefficients)

