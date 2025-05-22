#include "VanillaOption.h"


VanillaOption::VanillaOption(double expi, double strike) :
	Option(expi), _strike(strike) {
}

double VanillaOption::GetStrike() {
	return _strike;
}

bool VanillaOption::isVanillaOption() {
	return true;
}
