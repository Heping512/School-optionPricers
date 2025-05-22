#pragma once
#include"DigitalOption.h"

class DigitalPutOption : public DigitalOption
{
public:
	DigitalPutOption() = delete; //Delete the default constructor
	DigitalPutOption(double, double); //Constructor 
	OptionType GetOptionType() override; //Overridden GetOptionType() from DigitalOption
	double payoff(double) override; //Overridden payoff() from DigitalOption

};

