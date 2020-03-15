library(owl)

x <- abalone$x
y <- abalone$y

l = rep(0.01,9)


fit <- owl(x, y,family="poisson", lambda="bh")
pdf("slope.pdf")
plot(fit,main="Regularization path for SLOPE")

fit <- owl(x, y,family="poisson", lambda=l)
pdf("lasso.pdf")
plot(fit,main="Regularization path for LASSO")