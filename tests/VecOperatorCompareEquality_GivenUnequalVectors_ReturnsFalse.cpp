
#include "../src/vec.h"

int main()
{
	const size_t N = 5;
	lapp::vec<N, double> a = {{ 1, 2, 3, 4, 5 }};
	lapp::vec<N, double> b = {{ 0, 2, 3, 4, 5 }};

	if (!(a == b))
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

