// [[Rcpp::depends("RcppArmadillo")]]
#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
arma::vec FastProxSL1(arma::vec y, arma::vec lambda) {
    /*
        This implementation assumes that y and lambda are 
        nonnegative, non increasing sequences provided in vector form.
    
    */
    arma::vec x = y - lambda;
    while(1){
        
        // Computing left and right indices of an increasing subsequence
        uword right=0;
        while(right+1 < x.n_elem && x(right)>=x(right+1)) right++;
        uword left=right;
        while(left>0 && x(left-1)==x(left)) left--;
        if(x(left)==x(right)){
            // (y-lambda) is non increasing
            // y.print();
            // lambda.print();
            // x.print();
            return x;
        }
        
        // Updating elements of y and lambda between left and right with the mean
        double new_y = 0;
        for(uword i=left;i<=right;i++) new_y += y(i);
        new_y = new_y/(right-left+1);
        for(uword i=left;i<=right;i++) y(i) = new_y;

        double new_lambda = 0;
        for(uword i=left;i<=right;i++) new_lambda += lambda(i);
        new_lambda = new_lambda/(right-left+1);
        for(uword i=left;i<=right;i++) lambda(i) = new_lambda;

        for(uword i=left;i<=right;i++) x(i) = y(i) - lambda(i);
    }
}