#include "AsianPutOption.h"

AsianPutOption::AsianPutOption(std::vector<double> timesVector, double strike) :
	AsianOption(timesVector), _strike(strike) {}

double AsianPutOption::payoff(double assetsSum) {
	double res = 0;
	res = _strike - assetsSum;
	if (res <= 0) {
		res = 0;
	}
	return res;
}

