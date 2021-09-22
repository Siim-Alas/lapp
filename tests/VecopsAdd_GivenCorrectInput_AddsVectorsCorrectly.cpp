
#include <cstring>
#include "../src/vecops.h"

int main()
{
	const size_t N = 5;
	double a[N] = { 1, 2, 3, 4, 5 };
	double b[N] = { 6, 7, 8, 9, 10 };
	double result[N];
	double correct_result[N] = { 1 + 6, 2 + 7, 3 + 8, 4 + 9, 5 + 10 };

	lapp::vecops::add<N, double>(a, b, result);

	return memcmp(result, correct_result, N);
}

