#include "CRRPricer.h"
#include <vector>
#include <algorithm>

//Constructor 
CRRPricer::CRRPricer(Option* _op, int depth, double asset_price, double up, double down, double interest_rate) : _option(_op), N(depth), S_0(asset_price), U(up), D(down), R(interest_rate) {
	//We are checking the arbitrage condition 
	bool arbitrage = true;
	if ((U > R) && (R > D)) {
		arbitrage = false;
		std::cout << "Arbitrage conditions not respected : " << arbitrage << std::endl;
	}
	//This CRRPricer can only cumpute European option so we are putting condition on the constructor
	if (_op->isAsianOption() || _op->isAmericanOption()) {
		throw std::invalid_argument("Not a European Option... Can't use this CRR pricer constructor."); //Throws an invalid argument exception if the option is an asian, american or digital option
	}
	//However the overloaded CRRPricer can compute American and Digital Option, so we are urging them to use the overloaded one
	if (_op->isAmericanOption()) {
		throw  std::invalid_argument("Please use the constructorCRRPricer(Option* option, int depth, double asset_price, double compounded_interest_rate, double volatility) ");
	}
}

//The overloaded constructor 
CRRPricer::CRRPricer(Option* _op, int depth, double asset_price, double r, double volatility) : _option(_op), N(depth), S_0(asset_price), Interest_rate(r), Vol(volatility) {
	//The CRRPricer can not compute the price of an AnsianOption 
	if (_op->isAsianOption()) {
		throw std::invalid_argument("Asian Option... Can't use the CRR pricer."); //Throws an invalid argument exception if the option is an asian option 
	}
	else //If it's not then we are initializing U, R, D with the formula for a binomial model
	{
		double h = double(_option->GetExpiry()) / double(depth);
		double A = (R + ((double(Vol) * double(Vol)) / double(2)));
		double BU = (h + Vol * sqrt(h));
		double BD = (h - Vol * sqrt(h));
		U = exp(A * BU) - 1;
		D = exp(A * BD) - 1;
		R = exp(Interest_rate * h) - 1;
	}
}

void CRRPricer::compute() {
	double q = double(R - D) / double(U - D);
	//std::cout << R << std::endl;
	CRRPricer::_tree.setDepth(N);
	for (int j = 0; j <= CRRPricer::_tree._depth; j++) {
		double Sn = S_0 * pow((1 + U), j) * pow((1 + D), CRRPricer::_tree._depth - j);
		//std::cout << _option->payoff(Sn) << std::endl;
		CRRPricer::_tree.setNode(CRRPricer::_tree._depth, j, _option->payoff(Sn));

	}
	for (int n = CRRPricer::_tree._depth - 1; n >= 0; n--) {
		if (_option->isAmericanOption() == true) {
			//std::cout << "AM" << std::endl;
			for (int i = n; i >= 0; i--) {
				double value = q * CRRPricer::_tree.getNode(n + 1, i + 1) + (1 - q) * CRRPricer::_tree.getNode(n + 1, i);
				double Hn = value / (1 + R);
				double value_2 = get(n, i);
				if (value <= value_2) {
					Hn = value_2;
				}
				CRRPricer::_tree.setNode(n, i, Hn);
			}
		}
		else {
			for (int i = n; i >= 0; i--) {
				double value = q * CRRPricer::_tree.getNode(n + 1, i + 1) + (1 - q) * CRRPricer::_tree.getNode(n + 1, i);
				double Hn = value / (1 + R);
				//std::cout << "debut get" << std::endl;
				//std::cout << CRRPricer::_tree.getNode(n + 1, i + 1) << " et " << CRRPricer::_tree.getNode(n + 1, i) << std::endl;
				CRRPricer::_tree.setNode(n, i, Hn);
			}
		}
	}
}


double CRRPricer::get(int n, int i) {
	return CRRPricer::_tree.getNode(n, i);
}

//Getting the node (n,i) of the CRRPricer 
//But returning a boolean, for tree which are construct with boolean 
//However this only works with American Option 
bool CRRPricer::getExercice(int n, int i) {
	bool res = false;
	if (_option->isAmericanOption() == true)
	{
		double payoff_continu = 0;
		double payoff_intrinsic = 0;
		double q = (R - D) / (U - D);
		compute();
		payoff_continu = q * CRRPricer::_tree.getNode(n + 1, i + 1) + (1 - q) * CRRPricer::_tree.getNode(n + 1, i);
		payoff_intrinsic = get(n, i);
		if (payoff_continu <= payoff_intrinsic) {
			res = true;
		}
	}
	else
	{
		std::cout << "Can only be used with american option" << std::endl;
	}
	return res;

}



double CRRPricer::operator()(bool closed_form = false) {
	compute();
	double res = 0;
	double q = (R - D) / (U - D);
	//std::cout << CRRPricer::_tree._depth;
	N = CRRPricer::_tree._depth - 1;
	if (closed_form == true) {
		double cst = 1 / pow((1 + R), N);
		double sum = 0;
		double combi_stock = 1;
		double combi = 0;
		for (int i = 0; i <= N; i++) {
			if (i == 0) {
				combi = 1;
			}
			else {
				combi = combi_stock * (double(N - (i - 1)) / double(i));
				//std::cout <<"value : "<< (N - (i - 1)) << std::endl;
				combi_stock = combi;
			}
			//std::cout << N << " and "<< i << std::endl << combi_stock << std::endl <<combi << std::endl;
			double bino = pow(q, i) * pow(1 - q, N - i) * get(N, i);
			sum = sum + combi * bino;
		}
		res = sum * cst;
	}
	return res;
}


double CRRPricer::operator()() {
	compute();
	double res = 0;
	double q = (R - D) / (U - D);
	N = CRRPricer::_tree._depth;
	res = get(0, 0);
	return res;
}