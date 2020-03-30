library("devtools")
library("owl")
library("SLOPE")
library("Rcpp")
sourceCpp("/home/akarsh/owl/owl_imp.cpp")

setwd("/home/akarsh/RStats_GSoC_tests/SlopeSolver")
load_all()

ld = create_lambda(1,dim(bodyfat$x)[2])
x = data.matrix(bodyfat$x)

for(val in c(0,0.1,1,10,100,1000)){
    beta = solveSlope(x,bodyfat$y,val*ld)
    print(beta)
    fit <- owl(bodyfat$x, bodyfat$y,lambda=ld,sigma=val)
    print(fit$coefficients) 
}



