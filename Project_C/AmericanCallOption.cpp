#include "AmericanCallOption.h"
#include "VanillaOption.h"

//Definition of the contructor 
AmericanCallOption::AmericanCallOption(double expi, double strike) : AmericanOption(expi, strike) { }

//Computing the payoff of a call option max(K-S_O,0)
double AmericanCallOption::payoff(double z) {
	double strike = AmericanOption::GetStrike();
	if (z <= strike) {
		return strike - z;
	}
	else {
		return 0;
	}
}

