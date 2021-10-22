#pragma once

#include <cstddef>	// size_t
#include <cstring>	// memcmp

#include "vecops.h"

namespace lapp
{
	template <size_t N, typename T>
	struct vec
	{
		T elements[N];

		const T dot(const vec<N, T> &other) const
		{
			return lapp::vecops::dot<N, T>(elements, other.elements);
		}

		const T sqr_len() const
		{
			return lapp::vecops::dot<N, T>(elements, elements);
		}

		const bool operator==(const vec<N, T> &other) const
		{
			return memcmp(elements, other.elements, sizeof(T) * N) == 0;
		}

		const bool operator!=(const vec<N, T> &other) const
		{
			return memcmp(elements, other.elements, sizeof(T) * N) != 0;
		}

		void operator+=(const vec<N, T> &other)
		{
			lapp::vecops::add<N, T>(elements, other.elements, elements);
		}

		void operator-=(const vec<N, T> &other)
		{
			lapp::vecops::subtract<N, T>(elements, other.elements, elements);
		}
	};
}

