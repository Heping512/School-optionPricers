#pragma once
#include <iostream>
#include <vector>

template <class T>
class BinaryTree {

public:
	//déclaration contructeur
	BinaryTree();
	void setDepth(int);
	void setNode(int, int, T);
	double getNode(int, int);
	int _depth;
	void display();

private:

	std::vector<std::vector<T>> _tree;
	std::vector<std::vector<T>> _tree_stock;
};
