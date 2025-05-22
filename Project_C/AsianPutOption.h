#pragma once
#include "AsianOption.h"
#include <vector>

class AsianPutOption : public AsianOption {
public:
	AsianPutOption(std::vector<double>, double); //Constructor AsianCallOption(std::vector<double> times, double _strike)
	double payoff(double) override; //Overridden payoff function from AsianOption
private:
	double _strike; //Strike
};