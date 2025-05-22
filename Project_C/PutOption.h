#pragma once
#include "VanillaOption.h"
class PutOption : public VanillaOption
{
public:
	PutOption() = delete; //Deletes the default constructor
	PutOption(double, double); //Constructor PutOption(double _expiry, double _strike)
	OptionType GetOptionType() override; //Overridden getter for the option type
	double payoff(double) override; //h(z)
};

