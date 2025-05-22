#include "BlackScholesPricer.h"

#pragma region Normal distribution function

/*
* Note: erf(z/sqrt(2))=P(-z<X<z)
* erfc=1-erf
* Z~N(0,1)
* =>P(X<z)=(1/2)(1+erf(z/sqrt(2)))=(1/2)(2-erfc(z/sqrt(2)))
*/

//Computing the cumulated distribution function using the error function
double normalDistribution(double x) {
	return 0.5 * (2 - std::erfc(x / std::sqrt(2.0)));
}

#pragma endregion

//Constructors
BlackScholesPricer::BlackScholesPricer(VanillaOption* option, double asset_price, double interest_rate, double volatility) :
	vanilla_option(option), S(asset_price), r(interest_rate), sigma(volatility)
{}
BlackScholesPricer::BlackScholesPricer(DigitalOption* option, double asset_price, double interest_rate, double volatility) :
	digital_option(option), S(asset_price), r(interest_rate), sigma(volatility)
{}

#pragma region Computing the option price

//For a call
double BlackScholesPricer::computePriceCall(double maturity) {
	double C = 0;
	if (vanilla_option == NULL)
	{
		double d1 = std::log(S / digital_option->GetStrike()) + (r + sigma * sigma / 2) * maturity;
		d1 /= (sigma * std::sqrt(maturity));
		double d2 = d1 - sigma * std::sqrt(maturity);
		C = normalDistribution(d1) * S - normalDistribution(d2) * digital_option->GetStrike() * std::exp(-r * maturity);
	}
	else
	{
		double d1 = std::log(S / vanilla_option->GetStrike()) + (r + sigma * sigma / 2) * maturity;
		d1 /= (sigma * std::sqrt(maturity));
		double d2 = d1 - sigma * std::sqrt(maturity);
		C = normalDistribution(d1) * S - normalDistribution(d2) * vanilla_option->GetStrike() * std::exp(-r * maturity);

	}
	return C;
}

//For a put
double BlackScholesPricer::computePricePut(double deadline) {
	double P = 0;
	if (vanilla_option == NULL)
	{
		double d1 = std::log(S / digital_option->GetStrike()) + (r + std::pow(sigma, 2) / 2) * deadline;
		d1 /= (sigma * std::pow(deadline, 0.5));
		double d2 = d1 - sigma * std::pow(deadline, 0.5);
		P = -normalDistribution(-d1) * S + normalDistribution(-d2) * digital_option->GetStrike() * std::exp(-r * deadline);
	}
	else {
		double d1 = std::log(S / vanilla_option->GetStrike()) + (r + std::pow(sigma, 2) / 2) * deadline;
		d1 /= (sigma * std::pow(deadline, 0.5));
		double d2 = d1 - sigma * std::pow(deadline, 0.5);
		P = -normalDistribution(-d1) * S + normalDistribution(-d2) * vanilla_option->GetStrike() * std::exp(-r * deadline);
	}
	return P;
}

#pragma endregion

#pragma region Computing the delta

double BlackScholesPricer::delta() {
	double price = operator()(); //PAS SUR
	double d1 = std::log(S / vanilla_option->GetStrike()) + (r + std::pow(sigma, 2) / 2) * (vanilla_option->GetExpiry());
	//return std::exp(-price * (vanilla_option->GetExpiry())) * normalDistribution(d1);
	if (vanilla_option->GetOptionType() == OptionType::Put) {
		return normalDistribution(d1) - 1;
	}
	else {
		return normalDistribution(d1);
	}
}

#pragma endregion

double BlackScholesPricer::operator()() {

	if (vanilla_option == NULL)
	{
		if (digital_option->GetOptionType() == OptionType::Call)
		{
			optionPrice = computePriceCall(digital_option->GetExpiry());

		}
		else
		{
			optionPrice = computePricePut(digital_option->GetExpiry());
		}
	}
	else {
		if (vanilla_option->GetOptionType() == OptionType::Call)
		{
			optionPrice = computePriceCall(vanilla_option->GetExpiry());

		}
		else
		{
			optionPrice = computePricePut(vanilla_option->GetExpiry());
		}
	}
	return optionPrice;
}