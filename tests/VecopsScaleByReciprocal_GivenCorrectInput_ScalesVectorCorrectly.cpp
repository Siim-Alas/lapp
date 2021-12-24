
#include <cstring>
#include "../src/vecops.h"

int main()
{
	const size_t N = 5;
	double a = 1.5;
	double b[N] = { 6, 7, 8, 9, 10 };
	double result[N];
	double correct_result[N] = { 6/1.5, 7/1.5, 8/1.5, 9/1.5, 10/1.5 };

	lapp::vecops::scale_by_reciprocal<double>(a, b, result, N);

	return memcmp(result, correct_result, N);
}

