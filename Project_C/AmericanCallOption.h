#pragma once
#include "AmericanOption.h"

class AmericanCallOption : public AmericanOption
{
private:

public:
	AmericanCallOption(double, double); // decalaration Contructor 
	double payoff(double) override; //computing the payoff of the option 
};

