#include "DigitalPutOption.h"
#include "DigitalOption.h"
#include "Option.h"



DigitalPutOption::DigitalPutOption(double expi, double strike) :
	DigitalOption(expi, strike) {
}

OptionType DigitalPutOption::GetOptionType() {
	return OptionType::Put;
}

double DigitalPutOption::payoff(double z) {
	double strike = DigitalOption::GetStrike();
	if (z <= strike) {
		return 1;
	}
	else {
		return 0;
	}
}



