#pragma once
#include <vector>

class Option
{
private:
	double _expiry;
public:
	virtual double payoff(double) = 0; //h(z), the payoff
	virtual double payoffPath(std::vector<double>); //h(S_t1,...,S_tm), the payoff of the path (S_t1,...,S_tm)
	//To test the type of the option:
	virtual bool isVanillaOption();
	virtual bool isDigitalOption();
	virtual bool isAsianOption();
	virtual bool isAmericanOption();
	Option(); // Default constructor
	Option(double); //Constructor Option(double _expiry)
	double GetExpiry(); //Getter for _expiry
};


