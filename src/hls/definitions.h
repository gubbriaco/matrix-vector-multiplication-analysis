#ifndef DEFINITIONS_H

/**
 * Square Matrix Size.
 */
const static int size = 4;

/**
 * Number of Non-Zero Elements.
 */
const static int noZeroEl = 9;

/**
 * Number of Rows.
 */
const static int rows = 4;

/**
 * Standard Matrix Multiplication Design.
 * @param matrix[size][size] Input matrix
 * @param vector Input Vector
 * @param resMul Multiplication Result
 */
void std_multiplication(
		int matrix[size][size],
		int *mulRes,
		int *vector
);

/**
 * Sparse Matrix Multiplication Unoptimized Design.
 * @param iFirstEl[rows+1] Indexes First Elements
 * @param iNonZeroEl[noZeroEl] Indexes Non Zero Elements
 * @param values[noZeroEl] Input Values
 * @param vector[size] Input Vector
 * @param mulRes[size] Multiplication Result
 */
void smvm_unoptimized(
		int iFirstEl[rows+1],
		int iNonZeroEl[noZeroEl],
		int values[noZeroEl],
		int mulRes[size],
		int vector[size]
);


#endif
