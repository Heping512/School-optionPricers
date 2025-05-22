#include "AsianCallOption.h"
#include "AsianOption.h"
#include <vector>

AsianCallOption::AsianCallOption(std::vector<double> timesVector, double strike) :
	AsianOption(timesVector), _strike(strike) {}

double AsianCallOption::payoff(double assetsSum) {
	double res = 0;
	res = assetsSum - _strike;
	if (res <= 0) {
		res = 0;
	}
	return res;
}