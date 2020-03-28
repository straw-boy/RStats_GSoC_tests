// [[Rcpp::depends("RcppArmadillo")]]
#include <RcppArmadillo.h>
#include "fastProxSl1.h"

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
arma::vec solveSlope(arma::mat x, arma::vec y, arma::vec lambda) {

    arma::uword p = x.n_cols;

    arma::uword max_passes=1000000;

 
    arma::vec beta(p);
    beta.fill(10.0);
    arma::vec z = beta, w = beta;

    mat I(p,p);
    I.eye();

    double rho = 1.5;

    arma::mat temp = x.t()*x + rho*I, temp2 = x.t()*y;
    temp = inv(temp);

    for(int i=0;i<max_passes;i++){
        beta = temp*(temp2+rho*(z-w));
        z = FastProxSL1(beta+w,rho*lambda);
        w = w + beta - z;
    }
    
    return beta;

}
