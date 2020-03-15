library("Rcpp")
sourceCpp("fastProxSl1.cpp")

library("SLOPE")
library("microbenchmark")


run_experiment <- function(sequence_length,iterations){
    time_fpsl1 = 0
    time_psl1 = 0
    for (i in 1:iterations){
        y = c(runif(sequence_length,min=-100000,max=100000))
        y = sort(y,decreasing=TRUE)
        lambda = create_lambda(1,sequence_length)
        t <- proc.time()
        FastProxSL1(y,lambda)
        time_fpsl1 <- time_fpsl1 + (proc.time()-t)
        t <- proc.time()
        prox_sorted_L1(y,lambda)
        time_psl1 <- time_psl1 + (proc.time()-t)
    }
    print(paste("Average execution time for sequence length=",sequence_length,"and",iterations, "iterations"))
    print("FastProxSL1 :")
    print(time_fpsl1)
    print("Prox_Sorted_L1 : ")
    print(time_psl1)
}

l <- c(100,1000,10000,100000,1000000,10000000)
for (val in l){
    run_experiment(val,100)
}


# print("y = 1000")
# y = c(runif(1000,min=-100000,max=100000))
# y = sort(y,decreasing=TRUE)
# lambda = create_lambda(1,1000)
# microbenchmark(FastProxSL1(y,lambda),prox_sorted_L1(y,lambda))

# print("y = 10000")
# y = c(runif(10000,min=-100000,max=100000))
# y = sort(y,decreasing=TRUE)
# lambda = create_lambda(1,10000)
# microbenchmark(FastProxSL1(y,lambda),prox_sorted_L1(y,lambda))

# print("y = 100000")
# y = c(runif(100000,min=-100000,max=100000))
# y = sort(y,decreasing=TRUE)
# lambda = create_lambda(1,100000)
# # print("Size of y = ",val)
# microbenchmark(FastProxSL1(y,lambda),prox_sorted_L1(y,lambda))

# print("y = 1000000")
# y = c(runif(1000000,min=-100000,max=100000))
# y = sort(y,decreasing=TRUE)
# lambda = create_lambda(1,1000000)
# microbenchmark(FastProxSL1(y,lambda),prox_sorted_L1(y,lambda))

# proc.time() - ptm