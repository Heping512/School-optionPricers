#pragma once
#include "Option.h"


class AmericanOption : public Option
{
private:
	double _strike;
public:
	AmericanOption(double, double); //declaration of the constructor of an american otion 
	bool isAmericanOption() override; //Setting the boolean at true 
	double GetStrike(); //getting the strike of the option
};
