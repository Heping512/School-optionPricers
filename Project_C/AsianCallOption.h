#pragma once
#include <vector>
#include "AsianOption.h"

class AsianCallOption : public AsianOption {
public:
	AsianCallOption(std::vector<double>, double); //Constructor AsianCallOption(std::vector<double> times, double _strike)
	double payoff(double) override; //Overridden payoff function from AsianOption
private:
	double _strike; //Strike
};
