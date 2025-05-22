#pragma once
#include "Option.h"
#include "OptionType.h"

class VanillaOption : public Option
{
private:
	double _strike; //Strike
public:
	VanillaOption(double, double); //Constructor VanillaOption(double _expiry,double  _strike)
	virtual OptionType GetOptionType() = 0; //Option type getter
	double GetStrike(); //Strike getter
	bool isVanillaOption() override; //Overridden isVanillaOption() from Option
};

