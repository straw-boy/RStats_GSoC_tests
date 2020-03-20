// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// FastProxSL1
arma::vec FastProxSL1(arma::vec y, arma::vec lambda);
RcppExport SEXP _SlopeSolver_FastProxSL1(SEXP ySEXP, SEXP lambdaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::vec >::type lambda(lambdaSEXP);
    rcpp_result_gen = Rcpp::wrap(FastProxSL1(y, lambda));
    return rcpp_result_gen;
END_RCPP
}
// solveSlope
arma::vec solveSlope(arma::mat x, arma::vec y, arma::vec lambda);
RcppExport SEXP _SlopeSolver_solveSlope(SEXP xSEXP, SEXP ySEXP, SEXP lambdaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type x(xSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type y(ySEXP);
    Rcpp::traits::input_parameter< arma::vec >::type lambda(lambdaSEXP);
    rcpp_result_gen = Rcpp::wrap(solveSlope(x, y, lambda));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_SlopeSolver_FastProxSL1", (DL_FUNC) &_SlopeSolver_FastProxSL1, 2},
    {"_SlopeSolver_solveSlope", (DL_FUNC) &_SlopeSolver_solveSlope, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_SlopeSolver(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
