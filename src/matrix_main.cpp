// matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include "matrix.h"

int main()
{
	flaber::Matrix<int, 0> matrix;

	for (int i = 0; i < 10; ++i)
		matrix[i][i] = i; // rvalue qualified assigned operator

	for (int i = 0; i < 10; ++i) {
		auto matrElem = matrix[i][9 - i];
		matrElem = 9 - i; // lvalue qualified assigned operator
	}

	for (int i = 1; i < 9; ++i)
	{
		for (int j = 1; j < 9; ++j)
			std::cout << matrix[i][j] << " ";
		
		std::cout << std::endl;
	}

	std::cout << matrix.size() << std::endl;

	for (auto c : matrix)
	{
		int x, y, v;
		std::tie(x, y, v) = c;
		std::cout << "[" << x << "," << y << "] = " << v << std::endl;
	}
}