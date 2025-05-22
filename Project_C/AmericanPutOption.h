#pragma once
#include "AmericanOption.h"

class AmericanPutOption : public AmericanOption
{
private:

public:
	AmericanPutOption(double, double); //declaration of the contructor 
	double payoff(double) override; //Computing the payoff of the option
};
