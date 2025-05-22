#include "AmericanPutOption.h"
#include "VanillaOption.h"

//definition of the contructor 
AmericanPutOption::AmericanPutOption(double expi, double strike) : AmericanOption(expi, strike) { }


//Computing the payoff of a put option max(S_O-K,0)
double AmericanPutOption::payoff(double z) {
	double strike = AmericanOption::GetStrike();
	if (z >= strike) {
		return z - strike;
	}
	else {
		return 0;
	}
}
