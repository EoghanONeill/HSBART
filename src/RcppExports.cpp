// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// phi_app_hs
arma::mat phi_app_hs(arma::mat treemat, arma::vec node_indices, arma::mat internalmat, arma::mat xmat);
RcppExport SEXP _HSBART_phi_app_hs(SEXP treematSEXP, SEXP node_indicesSEXP, SEXP internalmatSEXP, SEXP xmatSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type treemat(treematSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type node_indices(node_indicesSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type internalmat(internalmatSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type xmat(xmatSEXP);
    rcpp_result_gen = Rcpp::wrap(phi_app_hs(treemat, node_indices, internalmat, xmat));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_HSBART_phi_app_hs", (DL_FUNC) &_HSBART_phi_app_hs, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_HSBART(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
