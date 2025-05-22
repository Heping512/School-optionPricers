#pragma once
#include "Option.h"
class BlackScholesMCPricer
{
private:
	long generated_paths; //Total number of paths created
	Option* option; //Option to be priced
	double price; //Price
	double S0; //Initial price
	double r; //Interest rate
	double sigma; //Volatility
public:
	BlackScholesMCPricer(Option*, double, double, double); //Constructor of arguments (Option* option, double initial_price, double interest rate, double volatility)
	long getNbPaths(); //Number of generated paths getter
	double generate(int); //Generator of int n additional paths
	double operator()(); //Returns the current estimate and throws an exception if not defined
	std::vector<double> confidenceInterval(); //Computes the confidence interval at 95% of the estimate 
};

