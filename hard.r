library("devtools")
library("owl")
library("SLOPE")
library("Rcpp")
sourceCpp("/home/akarsh/owl/owl_imp.cpp")

setwd("/home/akarsh/RStats_GSoC_tests/SlopeSolver")
load_all()

ld = 0.001*create_lambda(1,dim(bodyfat$x)[2])
x = data.matrix(bodyfat$x)


beta = solveSlope(x,bodyfat$y,ld)
print(beta)
fit <- owl(bodyfat$x, bodyfat$y,lambda=ld,sigma=1)
print(fit$coefficients) 


