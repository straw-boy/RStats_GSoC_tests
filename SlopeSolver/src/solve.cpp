// [[Rcpp::depends("RcppArmadillo")]]
#include <RcppArmadillo.h>
#include "fastProxSl1.h"

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
arma::vec solveSlope(arma::mat x, arma::vec y, arma::vec lambda) {

    arma::uword p = x.n_cols;

    arma::uword passes = 0, max_passes=15;

    // Initial b_0
    arma::vec beta = zeros<vec>(p);
    arma::vec beta_prev = beta;

    double lr = 0.5;

    // Pseudo Code referred from http://www.seas.ucla.edu/~vandenbe/236C/lectures/fista.pdf
    while (passes < max_passes){
        arma::uword k = passes+1;

        arma::vec temp = beta + (beta-beta_prev)*(k-2)/(k+1);

        temp = temp - lr*x.t()*(x*temp-y);
        beta_prev = beta;

        vec temp_sign = sign(temp);
        temp = abs(temp);
        uvec temp_order = sort_index(temp,"descend");
        temp = (temp(temp_order)).eval();

        temp = FastProxSL1(temp,lambda);

        temp(temp_order) = temp;
        temp %= temp_sign;

        beta = temp;
        // beta.print();
        passes++;
    }
    return beta;
}
