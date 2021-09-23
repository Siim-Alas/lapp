
#include <cstring>
#include "../src/matops.h"

int main()
{
	const size_t M = 3;
	const size_t N = 4;
	double A[M][N] =
	{
		{  2,  1, -1,   8 },
		{ -3, -1,  2, -11 },
		{ -2,  1,  2,  -3 }
	};
	double correct_result[M][N] =
	{
		{ 2,   1,  -1, 8 },
		{ 0, 0.5, 0.5, 1 },
		{ 0,   0,  -1, 1 }
	};

	lapp::matops::transform_in_place_to_unreduced_row_echelon_form<M, N, double>(A);

	return memcmp(A, correct_result, sizeof(double) * M * N);
}

