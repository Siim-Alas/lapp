#pragma once

#include <cstddef>	// size_t

namespace lapp::vecops
{
	/*
	 * Adds a to b component wise for n components.
	 *
	 * Parameters:
	 * 	- T, the type of elements in a, b, and result;
	 * 	- a, a pointer to the start of one array;
	 * 	- b, a pointer to the start of the other array;
	 * 	- result, a pointer to the start of the array where the result is saved;
	 * 	- N, the number of elements to add.
	 *
	 * Returns:
	 * 	void
	 */
	template <typename T>
	void add(const T *a, const T *b, T *result, size_t n)
	{
		for (int i = 0; i < n; i++)
		{
			result[i] = a[i] + b[i];
		}
	}

	/*
	 * Computes the dot product of a and b for n components.
	 *
	 * Parameters:
	 * 	- T, the type of elements in a and b;
	 * 	- a, a pointer to the start of one array;
	 * 	- b, a pointer to the start of the other array;
	 * 	- n, the number of elements to multiply and sum.
	 *
	 * Returns:
	 * 	the dot product of the two arrays.
	 */
	template <typename T>
	T dot(const T *a, const T *b, size_t n)
	{
		T dot_prod = 0;
		for (int i = 0; i < n; i++)
		{
			dot_prod += a[i] * b[i];
		}
		return dot_prod;
	}

	/*
	 * Scales the first n components of b by a factor of a.
	 *
	 * Parameters:
	 * 	- T, the type of elements in b;
	 * 	- a, the factor by which the components of b are to be scaled;
	 * 	- b, a pointer to the start of the array to be scaled;
	 * 	- result, a pointer to the start of the array where the result is saved;
	 * 	- n, the number of elements to scale.
	 *
	 * Returns:
	 * 	void
	 */
	template <typename T>
	void scale(const T a, const T *b, T *result, size_t n)
	{
		for (int i = 0; i < n; i++)
		{
			result[i] = a * b[i];
		}
	}

	/*
	 * Scales the first n components of b by a factor of 1 / a.
	 *
	 * Parameters:
	 * 	- T, the type of elements in b;
	 * 	- a, the factor by the reciprocal of which the components of b are to be
	 * 	scaled;
	 * 	- b, a pointer to the start of the array to be scaled;
	 * 	- result, a pointer to the start of the array where the result is saved;
	 * 	- n, the number of elements to scale.
	 *
	 * Returns:
	 * 	void
	 */
	template <typename T>
	void scale_by_reciprocal(const T a, const T *b, T *result, size_t n)
	{
		for (int i = 0; i < n; i++)
		{
			result[i] = b[i] / a;
		}
	}

	/*
	 * Subtracts b from a component-wise for n components.
	 *
	 * Parameters:
	 * 	- T, the type of elements in a, b, and result;
	 * 	- a, a pointer to the start of the array from which so subtract b;
	 * 	- b, a pointer to the start of the array to subtract from a;
	 * 	- result, a pointer to the start of the array where the result is saved;
	 * 	- n, the number of elements to subtract.
	 *
	 * Returns:
	 * 	void
	 */
	template <typename T>
	void subtract(const T *a, const T *b, T *result, size_t n)
	{
		for (int i = 0; i < n; i++)
		{
			result[i] = a[i] - b[i];
		}
	}
}

