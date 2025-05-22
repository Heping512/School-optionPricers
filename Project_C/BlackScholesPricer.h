#pragma once
#include "VanillaOption.h"
#include "DigitalOption.h"
#include "PutOption.h"
#include "CallOption.h"
#include "OptionType.h"
#include <cmath>

class BlackScholesPricer
{
public:
	BlackScholesPricer(VanillaOption*, double, double, double);
	BlackScholesPricer(DigitalOption*, double, double, double);
	double operator()();
	double delta();
private:
	VanillaOption* vanilla_option;
	DigitalOption* digital_option;
	double S; //Underlying price
	double r; //Interest rate
	double sigma; //Volatility
	double optionPrice; //Price of the option
	double computePriceCall(double);
	double computePricePut(double);
	double computeDelta(double, double);
};

