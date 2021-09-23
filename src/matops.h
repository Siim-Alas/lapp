#pragma once

#include <cmath>	// std::abs
#include <cstddef>	// size_t

namespace lapp::matops
{
	/*
	 * Finds the row of a matrix containing the element with the greatest nonzero absolute value in the given column.
	 *
	 * Parameters:
	 * 	M, the number of rows in the matrix;
	 * 	N, the number of columns or elements in each row of the matrix;
	 * 	A, a pointer to the start of the matrix to search;
	 * 	col, the column to search;
	 * 	srow, the row at which to begin the search.
	 *
	 * Returns:
	 * 	The index of the row with the greatest nonzero absolute value in the given column, -1 if none are found.
	 */
	template <size_t M, size_t N, typename T>
	int argmax_abs_in_col(const T A[M][N], const int col, const int srow)
	{
		int argmax = -1;
		T maxabs = 0;

		for (int i = srow; i < M; i++)
		{
			T candidate = std::abs(A[i][col]);
			if (candidate > maxabs)
			{
				maxabs = candidate;
				argmax = i;
			}
		}

		return argmax;
	}

	/*
	 * Swaps two rows of a matrix.
	 *
	 * Parameters:
	 * 	M, the number of rows in the matrix;
	 * 	N, the number of columns or elements in each row of the matrix;
	 * 	A, a pointer to the start of the matrix which will get two of its rows swapped;
	 * 	a, the index of the first row to swap;
	 * 	b, the index of the second row to swap.
	 *
	 * Returns:
	 * 	void
	 */
	template <size_t M, size_t N, typename T>
	void swap_rows(T A[M][N], const int a, const int b)
	{
		const size_t bytes_to_swap = sizeof(T) * N;
		T swap[N];
		memcpy(swap, &A[a][0], bytes_to_swap);
		memcpy(&A[a][0], &A[b][0], bytes_to_swap);
		memcpy(&A[b][0], swap, bytes_to_swap);
	}

	/*
	 * Transform a matrix to unreduced row echelon form (the leftmost element in each row may not equal 1).
	 *
	 * Parameters:
	 * 	M, the number of rows in the matrix;
	 * 	N, the number of columns or elements in each row of the matrix;
	 * 	A, a pointer to the start of the matrix to transform to row echelon form.
	 *
	 * Returns:
	 * 	void
	 */
	template <size_t M, size_t N, typename T>
	void transform_in_place_to_unreduced_row_echelon_form(T A[M][N])
	{
		int i = 0;
		int j = 0;

		while ((i < M) && (j < N))
		{
			/*
			int imax = argmax_abs_in_col<M, N, T>(A, j, i);
			if (imax == -1)
			{
				j++;
				continue;
			}
			swap_rows<M, N, T>(A, i, imax);
			*/

			for (int m = i + 1; m < M; m++)
			{
				T factor = A[m][j] / A[i][j];
				A[m][j] = 0;

				for (int n = j + 1; n < N; n++)
				{
					A[m][n] -= factor * A[i][n];
				}
			}

			i++;
			j++;
		}
	}
}

