#include "BlackScholesMCPricer.h"
#include "MT.h"
#include "AsianOption.h"
#include <vector>
#include <math.h>

BlackScholesMCPricer::BlackScholesMCPricer(Option* option, double initial_price, double interest_rate, double volatility) :
	option((Option*)option), S0(initial_price), r(interest_rate), sigma(volatility) {
	generated_paths = 0;
	//Doesn't count from beginning of program but from construction of pricer
	MT::getInstance(); //initializes the generator
}

/*
BlackScholesMCPricer::BlackScholesMCPricer(DigitalOption* option2, double initial_price, double interest_rate, double volatility):
	option(option2), S0(initial_price), r(interest_rate), sigma(volatility)
{
	MT::getInstance();
	generated_paths = 0;
}
*/


long BlackScholesMCPricer::getNbPaths() {
	return generated_paths;
}

double BlackScholesMCPricer::generate(int nb_paths) {
	generated_paths += nb_paths;
	std::vector<double> Zk(nb_paths);
	std::vector<double> Sk(nb_paths);
	std::vector<double> Times(nb_paths);
	if (nb_paths == 0) {
		throw std::invalid_argument("0 added paths");
	}
	if (option->isAsianOption()) {
		Times = ((AsianOption*)option)->getTimeSteps(); // Type casting
	}
	else {
		Times[0] = option->GetExpiry();
	}
	double res = 0;
	for (int k = 0; k < nb_paths; k++) {
		// Generation of a new path
		for (int i = 0; i < Times.size(); i++) {
			Zk[i] = MT::rand_norm();
			if (i != 0) {
				Sk[i] = Sk[i - 1] * std::exp((r - (sigma * sigma) / 2) * ((Times[i] - Times[i - 1]) + sigma * std::sqrt(Times[i] - Times[i - 1]) * Zk[i]));

			}
			else {
				Sk[i] = S0 * std::exp((r - (sigma * sigma) / 2) * (Times[0] + sigma * std::sqrt(Times[0]) * Zk[0]));
			}
		}
		// Adding the path to the computation of the price
		res += option->payoffPath(Sk);
	}
	res = res * (std::exp(-r * option->GetExpiry()));
	price = ((generated_paths - nb_paths) * price + res) / generated_paths;
	return price;
}

double BlackScholesMCPricer::operator()() {
	if (generated_paths == 0) {
		throw std::invalid_argument("Undefined estimate"); // Throws an exception if the pricer is not defined
	}
	else {
		return price;
	}
}

//CDF of N(0,1) (cf BlackScholesPricer.cpp)
double normalDistribution(double x) {
	return 0.5 * (2 - std::erfc(x / std::sqrt(2.0)));
}

//Confidence interval at 95%
std::vector<double> BlackScholesMCPricer::confidenceInterval() {
	std::vector<double> IC(2);
	double z = normalDistribution(0.975);
	double mu = price;
	double sigma_estim = sigma / std::sqrt(generated_paths);
	double lower_bound = mu - z * sigma_estim;
	double upper_bound = mu + z * sigma_estim;
	IC[0] = lower_bound;
	IC[1] = upper_bound;
	std::cout << std::endl << "Confidence interval at 95% : [" << lower_bound << ";" << upper_bound << "]" << std::endl;
	return IC;
}

