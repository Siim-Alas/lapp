#pragma once

#include <cstring>	// memcmp

#include "matops.h"

namespace lapp
{
	template <typename T>
	struct mat
	{
		size_t M, N;
		T *elements;

		mat(size_t arg_M, size_t arg_N) : M(arg_M), N(arg_N)
		{
			elements = new T[M * N];
		}
		~mat()
		{
			delete[] elements;
		}

		const T* operator[](size_t i) const
		{
			// No need for * sizeof(T), since it is done automatically when
			// adding integers to pointers
			return elements + i * N;
		}

		T* operator[](size_t i)
		{
			return elements + i * N;
		}

		const bool operator==(const mat<T> &other) const
		{
			return (M == other.M) && (N == other.N) &&
				(memcmp(elements, other.elements, M * N * sizeof(T)) == 0);
		}

		const bool operator!=(const mat<T> &other) const
		{
			return (M != other.M) || (N != other.N) ||
				(memcmp(elements, other.elements, M * N * sizeof(T)) != 0);
		}

		void solve_linear_system_in_place(T *results)
		{
			// This assumes that N = M + 1
			matops::solve_linear_system_in_place_with_gaussian_elimination(
				elements, results, M);
		}
	};
}

