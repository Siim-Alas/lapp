
#include <cstring>
#include "../src/matops.h"

int main()
{
	const size_t M = 3;
	double A[M][M + 1] =
	{
		{  2,  1, -1,   8 },
		{ -3, -1,  2, -11 },
		{ -2,  1,  2,  -3 }
	};
	double result[M]; 
	double correct_result[M] = { 2, 3, -1 };
	double tolerance = 1.0e-6;

	lapp::matops::solve_linear_system_in_place_with_gaussian_elimination<double>(&(A[0][0]), result, M);

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

