#pragma once
#include <iostream>
#include "Option.h"
#include "BinaryTree.cpp"


class CRRPricer {

public:
	CRRPricer(Option*, int, double, double, double, double);
	CRRPricer(Option*, int, double, double, double);
	BinaryTree<double> _tree;
	BinaryTree<bool> tree_bool;
	void compute();
	double get(int, int);
	bool getExercice(int, int);
	double operator()(bool); //Forme dure
	double operator()(); //Forme continue 
	bool arbitrage;


private:
	int N;
	double U;
	double D;
	double R;
	double S_0;
	double Vol;
	double Interest_rate;
	Option* _option;

};
