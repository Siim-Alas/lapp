
#include <cstring>
#include "../src/matops.h"

int main()
{
	const size_t M = 5;
	const size_t N = 10;
	double A[M][N] =
	{
		{ 0,   2,   3,   4,   5,   6,   7,   8,   9,  10 },
		{ 0, -12, -13, -14, -15, -16, -17, -18, -19, -20 },
		{ 0,  22,  23,  24,  25,  26,  27,  28,  29,  30 },
		{ 0, -32, -33, -34, -35, -36, -37, -38, -39, -40 },
		{ 0,  42,  43,  44,  45,  46,  47,  48,  49,  50 },
	};
	int col = 0;
	int srow = 0;
	double correct_result = -1;

	double result = lapp::matops::argmax_abs_in_col<M, N, double>(A, col, srow);

	return result - correct_result;
}

