// [[Rcpp::depends("RcppArmadillo")]]
#include <RcppArmadillo.h>
#include "fastProxSl1.h"

using namespace Rcpp;
using namespace arma;

// [[Rcpp::export]]
arma::vec solveSlope(arma::mat x, arma::vec y, arma::vec lambda) {

    arma::uword p = x.n_cols;

    arma::uword max_passes=100000;

 
    arma::vec beta(p);
    beta.fill(0.0);
    arma::vec z = beta, w = beta;

    mat I(p,p);
    I.eye();

    double rho = 10;

    arma::mat temp = x.t()*x + rho*I, temp2 = x.t()*y;
    temp = inv(temp);

    for(uword i=0;i<max_passes;i++){

        beta = temp*(temp2+rho*(z-w));
        
        z = beta+w;
        vec z_sign = sign(z);
        z = abs(z);
        uvec z_order = sort_index(z,"descend");
        z = (z(z_order)).eval();

        z = FastProxSL1(z,(1/rho)*lambda);
        
        z(z_order) = z;
        z %= z_sign;


        w = w + beta - z;
    }
    
    return beta;

}

