#include "CallOption.h"



CallOption::CallOption(double expi, double strike) :
	VanillaOption(expi, strike) {
}

OptionType CallOption::GetOptionType() {
	return OptionType::Call;
}

double CallOption::payoff(double z) {
	double strike = VanillaOption::GetStrike();
	if (z <= strike) {
		return strike - z;
	}
	else {
		return 0;
	}
}
