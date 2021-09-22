
#pragma once

#include <cstddef>

namespace lapp::vecops
{
	/*
	 * Adds a to b component wise for N components.
	 *
	 * Parameters:
	 * 	N, the number of elements to add;
	 * 	T, the type of elements in a, b, and result;
	 * 	a, a pointer to the start of one array;
	 * 	b, a pointer to the start of the other array;
	 * 	result, a pointer to the start of the array where the result is saved.
	 *
	 * Returns:
	 * 	void
	 */
	template <size_t N, typename T>
	void add(const T* a, const T* b, T* result)
	{
		for (int i = 0; i < N; i++)
		{
			result[i] = a[i] + b[i];
		}
	}

	/*
	 * Computes the dot product of a and b for N components.
	 *
	 * Parameters:
	 * 	N, the number of elements to multiply and sum;
	 * 	T, the type of elements in a and b;
	 * 	a, a pointer to the start of one array;
	 * 	b, a pointer to the start of the other array;
	 *
	 * Returns:
	 * 	the dot product of the two arrays.
	 */
	template <size_t N, typename T>
	T dot(const T* a, const T* b)
	{
		T dot_prod = 0;
		for (int i = 0; i < N; i++)
		{
			dot_prod += a[i] * b[i];
		}
		return dot_prod;
	}

	/*
	 * Scales the first N components of b by a factor of a.
	 *
	 * Parameters:
	 * 	N, the number of elements to scale;
	 * 	T, the type of elements in b;
	 * 	a, the factor by which the components of b are to be scaled;
	 * 	b, a pointer to the start of the array to be scaled;
	 * 	result, a pointer to the start of the array where the result is saved.
	 *
	 * Returns:
	 * 	void
	 */
	template <size_t N, typename T>
	void scale(const T a, const T* b, T* result)
	{
		for (int i = 0; i < N; i++)
		{
			result[i] = a * b[i];
		}
	}
	/*
	 * Subtracts b from a component wise for N components.
	 *
	 * Parameters:
	 * 	N, the number of elements to subtract;
	 * 	T, the type of elements in a, b, and result;
	 * 	a, a pointer to the start of the array from which so subtract b;
	 * 	b, a pointer to the start of the array to subtract from a;
	 * 	result, a pointer to the start of the array where the result is saved.
	 *
	 * Returns:
	 * 	void
	 */
	template <size_t N, typename T>
	void subtract(const T* a, const T* b, T* result)
	{
		for (int i = 0; i < N; i++)
		{
			result[i] = a[i] - b[i];
		}
	}
}

