#include "DigitalCallOption.h"
#include "DigitalOption.h"
#include "Option.h"

DigitalCallOption::DigitalCallOption(double expi, double strike) :
	DigitalOption(expi, strike) {

}

OptionType DigitalCallOption::GetOptionType() {
	return OptionType::Call;
}

double DigitalCallOption::payoff(double z) {
	double strike = DigitalOption::GetStrike();
	if (z >= strike) {
		return 1;
	}
	else {
		return 0;
	}
}

