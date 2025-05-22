#pragma once
#include "Option.h"
#include "OptionType.h"

class DigitalOption : public Option
{
private:
	double strike; //Strike
public:
	DigitalOption(double, double); //Constructor 
	virtual OptionType GetOptionType() = 0;
	double GetStrike(); //Strike getter
	bool isDigitalOption() override; //Overridden isDigitalOption() from Option
};

