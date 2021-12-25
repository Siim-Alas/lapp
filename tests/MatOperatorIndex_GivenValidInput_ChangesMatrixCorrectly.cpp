
#include <iostream>
#include "../src/mat.h"

int main()
{
	const size_t M = 3, N = 5;
	double elements[M * N] =
	{
		-1,  2,  3, -4,  5,
		 6, -7,  8,  9, 10,
		11, 12, 13, 14, 15
	};
	lapp::mat<double> matrix(M, N);
	memcpy(matrix.elements, elements, M * N * sizeof(double));

	double correct_elements[M * N] =
	{
		-1,  2,  3,  -4,  5,
		 6, -7,  8,   9, 10,
		11, 12, 13, -14, 15
	};
	lapp::mat<double> correct_matrix(M, N);
	memcpy(correct_matrix.elements, correct_elements, M * N * sizeof(double));

	matrix[2][3] = -14;

	if (matrix == correct_matrix)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

