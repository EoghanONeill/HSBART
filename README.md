
# HSBART

<!-- badges: start -->
<!-- badges: end -->

This package is an attemptted implementation of Bayesian Additive Regression Trees (Chipman et al. 2010) with Hierarchical Shrinkage (Agrawal 2022). This package accounts for the Hierarchical Shrinkage aspect of models within MCMC (drawing parameters, calculating marginal likelihoods etc.), rather than applying shrinkage post-hoc as in Agrawal et al. (2022).

Agarwal, A., Tan, Y. S., Ronen, O., Singh, C., & Yu, B. (2022). Hierarchical Shrinkage: improving the accuracy and interpretability of tree-based methods. arXiv preprint arXiv:2202.00858.

[Agarwal, A., Tan, Y. S., Ronen, O., Singh, C., & Yu, B. (2022). _Hierarchical Shrinkage: improving the accuracy and interpretability of tree-based methods_ .](https://arxiv.org/abs/2202.00858)

[Chipman, H. A., George, E. I., & McCulloch, R. E. (2010). _BART: Bayesian additive regression trees_ . The Annals of Applied Statistics, 4(1), 266-298.](https://projecteuclid.org/journals/annals-of-applied-statistics/volume-4/issue-1/BART-Bayesian-additive-regression-trees/10.1214/09-AOAS285.full)

## Installation

You can install the development version of HSBART like so:

``` r
library(devtools)
install_github("EoghanONeill/HSBART")

```

## Example

This is a basic example which shows you how to solve a common problem:

``` r
library(HSBART)
## basic example code

library(mvtnorm)
library(stats)
library(MCMCpack)
library(truncnorm)

library(profvis)

# Simulate a Friedman data set
friedman_data = function(n, num_cov, sd_error){
  x = matrix(runif(n*num_cov),n,num_cov)
  y = 10*sin(pi*x[,1]*x[,2]) + 20*(x[,3]-.5)^2+10*x[,4]+5*x[,5] + rnorm(n, sd=sd_error)
  return(list(y = y,
              x = x))
}
# Training data
data = friedman_data(100, 10, 1)
y = data$y
x = data$x

# Test data
data_test = friedman_data(100, 10, 1)
y.test = data_test$y
x.test = data_test$x

# Run MOTR-BART
set.seed(55)
# profvis({
  fit.motr.bart.h = hs_bart(x, y, ntrees = 10, nburn = 10, npost = 10)
# })
# save(fit.motr.bart, file = "smotr_result.Rdata")

test_results = test_function(x.test, fit.motr.bart.h)

cor(y.test, rowMeans(test_results$predictions))



```

