
#include <cstring>
#include "../src/matops.h"

int main()
{
	const size_t M = 5;
	const size_t N = 10;
	double A[M][N] =
	{
		{   1,   2,   3,   4,   5,   6,   7,   8,   9,  10 },
		{ -11, -12, -13, -14, -15, -16, -17, -18, -19, -20 },
		{  21,  22,  23,  24,  25,  26,  27,  28,  29,  30 },
		{ -31, -32, -33, -34, -35, -36, -37, -38, -39, -40 },
		{  41,  42,  43,   0,  45,  46,  47,  48,  49,  50 },
	};
	int col = 3;
	int srow = 0;
	double correct_result = 3;

	double result = lapp::matops::argmax_abs_in_col<double>(&(A[0][0]), col, srow, M, N);

	return result - correct_result;
}

