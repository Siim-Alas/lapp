#pragma once

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
			return lapp::vecops::dot<T>(elements, other.elements, N);
		}

		const T sqr_len() const
		{
			return lapp::vecops::dot<T>(elements, elements, N);
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
			vecops::add<T>(elements, other.elements, result.elements, N);
			return result;
		}

		const vec<N, T> operator-(const vec<N, T> &other) const
		{
			vec<N, T> result;
			vecops::subtract<T>(elements, other.elements, result.elements, N);
			return result;
		}

		const vec<N, T> operator*(const T factor) const
		{
			vec<N, T> result;
			vecops::scale<T>(factor, elements, result.elements, N);
			return result;
		}

		const vec<N, T> operator/(const T factor) const
		{
			vec<N, T> result;
			vecops::scale_by_reciprocal<T>(factor, elements, result.elements, N);
			return result;
		}

		void operator+=(const vec<N, T> &other)
		{
			vecops::add<T>(elements, other.elements, elements, N);
		}

		void operator-=(const vec<N, T> &other)
		{
			vecops::subtract<T>(elements, other.elements, elements, N);
		}

		void operator*=(const T factor)
		{
			vecops::scale<T>(factor, elements, elements, N);
		}

		void operator/=(const T factor)
		{
			vecops::scale_by_reciprocal<T>(factor, elements, elements, N);
		}
	};

	template<size_t N, typename T>
	const vec<N, T> operator*(const T factor, const vec<N, T> &v)
	{
		return v * factor;
	}
}

