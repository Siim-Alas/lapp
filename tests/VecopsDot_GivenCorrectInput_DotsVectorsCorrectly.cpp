
#include <cstring>
#include "../src/vecops.h"

int main()
{
	const size_t N = 5;
	double a[N] = { 1, 2, 3, 4, 5 };
	double b[N] = { 6, 7, 8, 9, 10 };
	double correct_result = 1*6 + 2*7 + 3*8 + 4*9 + 5*10;

	double result = lapp::vecops::dot<N, double>(a, b);

	return result - correct_result;
}

