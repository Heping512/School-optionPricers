#include "Option.h"

//Default constructor
Option::Option() :_expiry(0.0) {}

//Constructor to initialize _expiry
Option::Option(double expi) : _expiry(expi) {}

// Getter of the expiry
double Option::GetExpiry() {
	return _expiry;
}

//payoffPath
double Option::payoffPath(std::vector<double> vect) {
	return Option::payoff(vect.back());
}

//isVanillaOption
bool Option::isVanillaOption() {
	return false;
}

//isDigitalOption
bool Option::isDigitalOption() {
	return false;
}

//isAsianOption
bool Option::isAsianOption() {
	return false;
}

//isAmericanOption 
bool Option::isAmericanOption() {
	return false;
}
