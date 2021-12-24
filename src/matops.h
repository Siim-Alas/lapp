#pragma once

#include <cmath>	// std::abs

namespace lapp::matops
{
	/*
	 * Finds the index where the element on the i-th row and j-th column would
	 * reside in a row-major representation.
	 *
	 * Parameters:
	 * 	- i, the 0-based index of the row;
	 * 	- j, the 0-based index of the column;
	 * 	- cols, the number of columns or elements in each row of the matrix.
	 */
	size_t rmi(size_t i, size_t j, size_t cols)
	{
		return i * cols + j;
	}

	/*
	 * Finds the row of a matrix containing the element with the greatest
	 * nonzero absolute value in the given column.
	 *
	 * Parameters:
	 * 	- T, the type of elements in the matrix;
	 * 	- A, a pointer to the start of the matrix to search (the matrix is
	 * 	assumed to be represented in row-major order);
	 * 	- col, the column to search;
	 * 	- srow, the row at which to begin the search;
	 * 	- rows, the number of rows in the matrix;
	 * 	- cols, the number of columns or elements in each row of the matrix.
	 *
	 * Returns:
	 * 	The index of the row with the greatest nonzero absolute value in the
	 * 	given column, -1 if none are found.
	 */
	template <typename T>
	int argmax_abs_in_col(
		const T *A, int col, int srow, size_t rows, size_t cols)
	{
		int argmax = -1;
		T maxabs = 0;

		for (int i = srow; i < rows; i++)
		{
			T candidate = std::abs(A[rmi(i, col, cols)]);
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
	 * 	- T, the type of elements in the matrix;
	 * 	- A, a pointer to the start of the matrix which will get two of its rows
	 * 	swapped (the matrix is assumed to be represented in row-major order);
	 * 	- a, the index of the first row to swap;
	 * 	- b, the index of the second row to swap;
	 * 	- rows, the number of rows in the matrix;
	 * 	- cols, the number of columns or elements in each row of the matrix.
	 *
	 * Returns:
	 * 	void
	 */
	template <typename T>
	void swap_rows(T *A, int a, int b, size_t rows, size_t cols)
	{
		for (int j = 0; j < cols; j++)
		{
			T temp = A[rmi(a, j, cols)];
			A[rmi(a, j, cols)] = A[rmi(b, j, cols)];
			A[rmi(b, j, cols)] = temp;
		}
	}

	/*
	 * Transform a matrix to unreduced row echelon form (the leftmost element
	 * in each row may not equal 1). The transformation is done in place,
	 * meaning that the original matrix is replaced with its row echelon form.
	 *
	 * Parameters:
	 * 	- T, the type of elements in the matrix;
	 * 	- A, a pointer to the start of the matrix to transform to row echelon
	 * 	form (the matrix is assumed to be represented in row-major order);
	 * 	- rows, the number of rows in the matrix;
	 * 	- cols, the number of columns or elements in each row of the matrix.
	 *
	 * Returns:
	 * 	void
	 */
	template <typename T>
	void transform_in_place_to_unreduced_row_echelon_form(
		T *A, size_t rows, size_t cols)
	{
		int i = 0;
		int j = 0;

		while ((i < rows) && (j < cols))
		{
			int i_max = argmax_abs_in_col<T>(A, j, i, rows, cols);
			if (i_max == -1)
			{
				j++;
				continue;
			}

			swap_rows<T>(A, i, i_max, rows, cols);

			for (int m = i + 1; m < rows; m++)
			{
				T factor = A[rmi(m, j, cols)] / A[rmi(i, j, cols)];
				A[rmi(m, j, cols)] = 0;

				for (int n = j + 1; n < cols; n++)
				{
					A[rmi(m, n, cols)] -= factor * A[rmi(i, n, cols)];
				}
			}

			i++;
			j++;
		}
	}

	/*
	 * Solves a system of linear equations with Gaussian elimination. The system
	 * is solved in place, meaning that the original matrix is replaced with its
	 * row echelon form.
	 *
	 * Parameters:
	 * 	- A, a pointer to the start of the num_of_equations by num_of_equations
	 * 	+ 1 matrix containing the augmented matrix associated with the system
	 * 	(the matrix is assumed to be represented in row-major order);
	 * 	- results, a pointer to the start of the vector to which the results are
	 * 	saved;
	 * 	- num_of_equations, the number of equations.
	 *
	 * Returns:
	 * 	void
	 */
	template <typename T>
	void solve_linear_system_in_place_with_gaussian_elimination(
		T *A, T *results, size_t num_of_equations)
	{
		transform_in_place_to_unreduced_row_echelon_form<T>(
			A, num_of_equations, num_of_equations + 1);

		for (int i = num_of_equations - 1; i >= 0; i--)
		{
			T sum = 0;
			for (int j = i + 1; j < num_of_equations; j++)
			{
				sum += A[rmi(i, j, num_of_equations + 1)] * results[j];
			}

			results[i] =
				(A[rmi(i, num_of_equations, num_of_equations + 1)] - sum) /
				A[rmi(i, i, num_of_equations + 1)];
		}
	}
}

