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
		for (int j = 0; j < N; j++)
		{
			T temp = A[a][j];
			A[a][j] = A[b][j];
			A[b][j] = temp;
		}
	}

	/*
	 * Transform a matrix to unreduced row echelon form (the leftmost element in each row may not equal 1). The
	 * transformation is done in place, meaning that the original matrix is replaced with its row echelon form.
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
			int i_max = argmax_abs_in_col<M, N, T>(A, j, i);
			if (i_max == -1)
			{
				j++;
				continue;
			}

			swap_rows<M, N, T>(A, i, i_max);

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

	/*
	 * Solves a system of linear equations with Gaussian elimination. The system is solved in place, meaning that the
	 * original matrix is replaced with its row echelon form.
	 *
	 * Parameters:
	 * 	M, the number of equations;
	 * 	A, a pointer to the start of the M by M + 1 matrix containing the augmented matrix associated with the system;
	 * 	results, a pointer to the start of the vector to which the results are saved;
	 *
	 * Returns:
	 * 	void
	 */
	template <size_t M, typename T>
	void solve_linear_system_in_place_with_gaussian_elimination(T A[M][M + 1], T results[M])
	{
		transform_in_place_to_unreduced_row_echelon_form<M, M + 1, T>(A);

		for (int i = M - 1; i >= 0; i--)
		{
			T sum = 0;
			for (int j = i + 1; j < M; j++)
			{
				sum += A[i][j] * results[j];
			}

			results[i] = (A[i][M] - sum) / A[i][i];
		}
	}
}

