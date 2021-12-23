
#include "../src/vec.h"

int main()
{
	const size_t N = 5;
	double a = 1.5;
	lapp::vec<N, double> b = {{ 6, 7, 8, 9, 10 }};
	lapp::vec<N, double> correct_result = {{ 1.5*6, 1.5*7, 1.5*8, 1.5*9, 1.5*10 }};

	lapp::vec<N, double> result1 = a * b;
	lapp::vec<N, double> result2 = b * a;

	if ((result1 == correct_result) && (result2 == correct_result))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

