#include "AmericanOption.h"

//Definition constructor 
AmericanOption::AmericanOption(double expi, double strike) :
	Option(expi), _strike(strike) {
}

//setting the boolean at true because it's an american option 
bool AmericanOption::isAmericanOption() {
	return true;
}

//getting the strike of the option 
double AmericanOption::GetStrike() {
	return _strike;
}