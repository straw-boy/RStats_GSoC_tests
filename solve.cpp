#include <RcppArmadillo.h>
#include <Rcpp.h>
#include "fastProxSl1.h"

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
arma::vec solveSlope(arma::mat x, arma::vec y, arma::vec lambda) {

    arma::u_word p = x.n_cols;

    arma::uword passes = 0, max_passes=1e+6;

    // Initial b_0
    arma::vec beta = zeros<vec>(p);
    arma::vec beta_prev = beta;


    // Pseudo Code referred from http://www.seas.ucla.edu/~vandenbe/236C/lectures/fista.pdf
    while (passes < max_passes){
        arma::uword k = passes+1;
        arma::vec temp = beta + (beta-beta_prev)*(k-2)/(k-1);
        temp = temp - 0.5*x.t()*(x*temp-y);
        beta_prev = beta;
        beta = FastProxSL1(temp);
        passes++;
    }
    return beta;
}
