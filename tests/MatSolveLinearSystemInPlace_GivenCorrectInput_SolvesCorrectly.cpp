
#include <cstring>
#include "../src/mat.h"

int main()
{
	const size_t M = 3;
	double A[M * (M + 1)] =
	{
		 2,  1, -1,   8,
		-3, -1,  2, -11,
		-2,  1,  2,  -3
	};
	lapp::mat<double> equation_matrix(M, M + 1);
	memcpy(equation_matrix.elements, A, M * (M + 1) * sizeof(double));


	double result[M]; 
	double correct_result[M] = { 2, 3, -1 };
	double tolerance = 1.0e-6;

	equation_matrix.solve_linear_system_in_place(result);

	if ((std::abs(result[0] - correct_result[0]) < tolerance) &&
		(std::abs(result[1] - correct_result[1]) < tolerance) &&
		(std::abs(result[2] - correct_result[2]) < tolerance))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

