#pragma once
#include"DigitalOption.h"

class DigitalCallOption : public DigitalOption
{
public:
	DigitalCallOption() = delete; //Delete the default constructor
	DigitalCallOption(double, double); //Constructor 
	OptionType GetOptionType() override; //Overridden GetOptionType() from DigitalOption
	double payoff(double) override; //Overridden payoff() from DigitalOption
};

