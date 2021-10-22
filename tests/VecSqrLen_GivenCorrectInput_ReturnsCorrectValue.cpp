
#include <cstring>
#include "../src/vec.h"

int main()
{
	const size_t N = 5;
	lapp::vec<N, double> a = { 1, 2, 3, 4, 5 };
	double correct_result = 1*1 + 2*2 + 3*3 + 4*4 + 5*5;

	double result = a.sqr_len();

	return result - correct_result;
}

