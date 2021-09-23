
#include <cstring>
#include "../src/matops.h"

#include <iostream>

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
		{ 0, 1/2, 1/2, 1 },
		{ 0,   0,  -1, 1 }
	};

	lapp::matops::transform_in_place_to_unreduced_row_echelon_form<M, N, double>(A);

	std::cout << A[0][0] << ", " << A[0][1] << ", " << A[0][2] << ", " << A[0][3] << std::endl;
	std::cout << A[1][0] << ", " << A[1][1] << ", " << A[1][2] << ", " << A[1][3] << std::endl;
	std::cout << A[2][0] << ", " << A[2][1] << ", " << A[2][2] << ", " << A[2][3] << std::endl;

	return memcmp(A, correct_result, sizeof(double) * M * N);
}

