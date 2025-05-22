#include <iostream>
#include <vector>
#include "BinaryTree.h"
#include <string>
#include <string.h>

//Contructeur défintion 

template <class T>
BinaryTree<T>::BinaryTree() { }


template <class T>
void BinaryTree<T>::setDepth(int n) {
	if (_depth == 0) {
		_depth = n;
		_tree.resize(_depth + 1);
		for (int i = 0; i <= _depth; i++)
		{
			std::vector<T> branch(i + 1);
			_tree[i] = branch;
		}
	}
	else if (n > _depth)
	{
		_tree_stock.resize(n + 1);
		for (int i = 0; i <= _depth; i++)
		{
			_tree_stock[i] = _tree[i];
		}
		for (int i = _depth; i <= n; i++) {
			std::vector<T> branch(i + 1);
			_tree_stock[i] = branch;
		}
		_tree.resize(_depth + 1);
		_tree = _tree_stock;
		_tree_stock.clear();
		_depth = n;

	}
	else if (n < _depth) {
		_tree_stock.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			_tree_stock[i] = _tree[i];
		}
		_tree.resize(n + 1);
		_tree = _tree_stock;
		_depth = n;
	}

}

//template <class T>
//void BinaryTree<T>::setDepth(int n) {
//	_depth = n;
//	_tree.resize(_depth + 1);
//	for (int i = 0; i <= _depth; i++)
//	{
//		std::vector<T> branch(i + 1);
//		_tree[i] = branch;
//	}
//}

/*
template <class T>
void BinaryTree<T>::setNode(int n, int i, T object) {

	_tree[n][i] = double(S_0 * pow((1 + up), i) * pow((1 + down), n - i));
	std::cout << _tree[n][i] << std::endl;
	std::cout << "Node set at (" << n << ";" << i << ")" << std::endl;
}*/


template <class T>
void BinaryTree<T>::setNode(int n, int i, T value) {

	//std::cout << value << std::endl;
	_tree[n][i] = value;
}

template <class T>
double BinaryTree<T>::getNode(int n, int i) {
	return  _tree[n][i];
}

template <class T>
void BinaryTree<T>::display() {
	int n = 0;
	for (int i = 0; i <= (_depth - 1) * 2; i++) {
		int k = 0;
		bool gauche = true;
		for (int j = 0; j <= 4 * (_depth - 1) + 1; j++) {
			if (j < 2 * (_depth - 1) - i || j > 2 * (_depth - 1) + i) {
				std::cout << " ";
			}
			else
			{
				if (i % 2 == 0) {
					if (int(getNode(n, k)) >= 100) {
						std::cout << " " << int(getNode(n, k));
					}
					else if ((int(getNode(n, k)) < 100) && (int(getNode(n, k)) >= 10)) {
						std::cout << " " << int(getNode(n, k));
						std::cout << " ";
					}
					else {
						std::cout << "  " << int(getNode(n, k));
						std::cout << " ";
					}

					j = j + 3;
					k++;
				}
				else {

					if (gauche == true) {
						std::cout << " /";
						std::cout << " ";
						gauche = false;
					}
					else {
						std::cout << "";
						std::cout << "\\";
						gauche = true;
					}
					j = j + 1;
				}

			}
		}
		std::cout << std::endl;
		if (i % 2 == 0) {
			n++;
		}
	}
}
