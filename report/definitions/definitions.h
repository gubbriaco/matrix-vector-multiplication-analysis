#ifndef DEFINITIONS_H


/**
 * Square Matrix Size.
 */
const static int size = 4;

/**
 * Number of Non-Zero Elements.
 */
const static int nnz = 9;

/**
 * Number of Rows.
 */
const static int rows = 4;

/**
 * Data Type.
 */
typedef int DTYPE;

/**
 * Matrix Vector Standard Multiplication Design.
 * @param matrix[size][size] Input matrix
 * @param y Multiplication Result
 * @param x Input Vector
 */
void std_multiplication(DTYPE matrix[size][size], DTYPE *y, DTYPE *x);

/**
 * Sparse Matrix Vector Multiplication Design (CRS format).
 * @param rowPtr[rows+1] Indexes First Elements
 * @param columnIndex[nnz] Indexes Non Zero Elements
 * @param values[nnz] Input Values
 * @param y[size] Multiplication Result
 * @param x[size] Input Vector
 */
void smvm(int rowPtr[rows+1], int columnIndex[nnz], DTYPE values[nnz], DTYPE y[size], DTYPE x[size]);


#endif
