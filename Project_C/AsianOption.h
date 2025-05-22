#pragma once
#include <vector>
#include "Option.h"

class AsianOption : public Option
{
public:
	AsianOption(std::vector<double>); // Constructor AsianOption(std::vector<double> times)
	std::vector<double> getTimeSteps(); //Getter method of the time steps vector
	double payoffPath(std::vector<double>) override; //Overridden method of payoffPath from Option, Returns h(St1,...,Stm)
	bool isAsianOption() override; //Overridden isAsianOption() from Option
private:
	std::vector<double> times; //Vector of the times of the path
};

