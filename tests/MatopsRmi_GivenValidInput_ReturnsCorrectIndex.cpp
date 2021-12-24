
#include "../src/matops.h"

int main()
{
	size_t i = 1, j = 2, cols = 3;
	size_t correct_result = i * cols + j;

	if (lapp::matops::rmi(i, j, cols) == correct_result)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

