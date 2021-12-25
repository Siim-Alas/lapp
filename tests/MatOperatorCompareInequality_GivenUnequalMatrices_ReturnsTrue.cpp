
#include "../src/mat.h"

int main()
{
	const size_t M = 3, N = 5;
	double elements1[M * N] =
	{
		-1,  2,  3, -4,  5,
		 6, -7,  8,  9, 10,
		11, 12, 13, 14, 15
	};
	lapp::mat<double> mat1(M, N);
	memcpy(mat1.elements, elements1, M * N * sizeof(double));

	double elements2[M * N] =
	{
		 0,  2,  3, -4,  5,
		 6, -7,  8,  9, 10,
		11, 12, 13, 14, 15
	};
	lapp::mat<double> mat2(M, N);
	memcpy(mat2.elements, elements2, M * N * sizeof(double));

	if (mat1 != mat2)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

