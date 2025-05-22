#pragma once
#include"VanillaOption.h"

class CallOption : public VanillaOption
{
public:
	CallOption() = delete; //Deleting the default constructor
	CallOption(double, double); //Constructor using the VanillaOption one
	OptionType GetOptionType() override; //Overridden getter for the option type from VanillaOption
	double payoff(double) override; //h(z), overridden payoff() from VanillaOption
};

