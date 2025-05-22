#include "AsianOption.h"
#include <vector>

//Constructor
AsianOption::AsianOption(std::vector<double> timesVector) : times(timesVector) {};

//Getter
std::vector<double> AsianOption::getTimeSteps() {
	return times;
}

double AsianOption::payoffPath(std::vector<double> assets) {
	double sum = 0;
	for (int i = 0; i < getTimeSteps().size(); i++) {
		sum = sum + assets[i];
	}
	return Option::payoff((1 / getTimeSteps().size()) * sum);
}

bool AsianOption::isAsianOption() {
	return true;
}

