#include "DigitalOption.h"

DigitalOption::DigitalOption(double expi, double strike) :
	Option(expi), strike(strike) {
}

double DigitalOption::GetStrike() {
	return strike;
}

bool DigitalOption::isDigitalOption() {
	return true;
}
