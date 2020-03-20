library("Rcpp")
sourceCpp("fastProxSl1.cpp")

library("SLOPE")

run_experiment <- function(sequence_length,iterations){
    time_fpsl1 = 0
    time_psl1 = 0
    for (i in 1:iterations){
        y = c(runif(sequence_length,min=0,max=100000))
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

l <- c(100,1000,10000,100000,1000000)
for (val in l){
    run_experiment(val,100)
}
