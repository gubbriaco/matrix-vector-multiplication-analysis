#ifndef DEFINITIONS_H

/**
 * Square Matrix Size.
 */
const static int SIZE = 4;

/**
 * Number of Non-Zero Elements.
 */
const static int NNZ = 9;

/**
 * Number of Rows.
 */
const static int ROWS = 4;

/**
 * Standard Matrix Multiplication Design.
 */
void std_multiplication(float matrix[SIZE][SIZE], float *x, float *y);

/**
 * Sparse Matrix Multiplication Unoptimized Design.
 */
void smm_unoptimized(int indexesFirstEl[ROWS+1], int indexesNonZeroEl[NNZ], float values[NNZ], float x[SIZE], float y[SIZE]);

#endif
