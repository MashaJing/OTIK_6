#pragma once
#include <algorithm>
#include <cassert>


class SoloveiStrassen
{
	private:
	int Jacobi(int a, int b);
	int Euclidean(int a, int b);
	

	public:
	SoloveiStrassen() {};

	bool Is_simple(int a);

};

bool odd(int b);
int mod(int a, int b);

