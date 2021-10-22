
#include <cstring>
#include "../src/vec.h"

int main()
{
	const size_t N = 5;
	lapp::vec<N, double> a = { 1, 2, 3, 4, 5 };
	lapp::vec<N, double> b = { 6, 7, 8, 9, 10 };
	double correct_result = 1*6 + 2*7 + 3*8 + 4*9 + 5*10;

	double result = a.dot(b);

	return result - correct_result;
}

