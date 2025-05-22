#include "PutOption.h"
#include "VanillaOption.h"
#include "Option.h"



PutOption::PutOption(double expi, double strike) :
	VanillaOption(expi, strike) {
}

OptionType PutOption::GetOptionType() {
	return OptionType::Put;
}

double PutOption::payoff(double z) {
	double strike = VanillaOption::GetStrike();
	if (z >= strike) {
		return z - strike;
	}
	else {
		return 0;
	}
}
