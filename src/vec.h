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

		const vec<N, T> operator+(const vec<N, T> &other) const
		{
			vec<N, T> result;
			vecops::add<N, T>(elements, other.elements, result.elements);
			return result;
		}

		const vec<N, T> operator-(const vec<N, T> &other) const
		{
			vec<N, T> result;
			vecops::subtract<N, T>(elements, other.elements, result.elements);
			return result;
		}

		const vec<N, T> operator*(const T factor) const
		{
			vec<N, T> result;
			vecops::scale<N, T>(factor, elements, result.elements);
			return result;
		}

		const vec<N, T> operator/(const T factor) const
		{
			vec<N, T> result;
			vecops::scale_by_reciprocal<N, T>(factor, elements, result.elements);
			return result;
		}

		void operator+=(const vec<N, T> &other)
		{
			vecops::add<N, T>(elements, other.elements, elements);
		}

		void operator-=(const vec<N, T> &other)
		{
			vecops::subtract<N, T>(elements, other.elements, elements);
		}

		void operator*=(const T factor)
		{
			vecops::scale<N, T>(factor, elements, elements);
		}

		void operator/=(const T factor)
		{
			vecops::scale_by_reciprocal<N, T>(factor, elements, elements);
		}
	};

	template<size_t N, typename T>
	const vec<N, T> operator*(const T factor, const vec<N, T> &v)
	{
		return v * factor;
	}
}

