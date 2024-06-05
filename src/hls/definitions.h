#ifndef DEFINITIONS_H


/**
 * Square Matrix Size.
 */
const static int size = 4;

/**
 * Number of Non-Zero Elements.
 */
const static int noZeroEl  = 9;

/**
 * Number of Rows.
 */
const static int rows = 4;

/**
 * Data Type.
 */
typedef int DTYPE;

/**
 * Sparse Matrix Multiplication Unoptimized Design.
 * @param iFirstEl[rows+1] Indexes First Elements
 * @param iNonZeroEl[noZeroEl] Indexes Non Zero Elements
 * @param values[noZeroEl] Input Values
 * @param mulRes[size] Multiplication Result
 * @param vector[size] Input Vector
 */
void std_multiplication(DTYPE matrix[size][size], DTYPE *mulRes, DTYPE *vector);

/**
 * Standard Matrix Multiplication Design.
 * @param matrix[size][size] Input matrix
 * @param resMul Multiplication Result
 * @param vector Input Vector
 */
void smvm_unoptimized(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);

/**
 * Sparse Matrix Multiplication Loop 2 Pipeline Design.
 * @param iFirstEl[rows+1] Indexes First Elements
 * @param iNonZeroEl[noZeroEl] Indexes Non Zero Elements
 * @param values[noZeroEl] Input Values
 * @param mulRes[size] Multiplication Result
 * @param vector[size] Input Vector
 */
void smvm_loop2P(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);

/**
 * Sparse Matrix Multiplication Loop 1 Pipeline Design.
 * @param iFirstEl[rows+1] Indexes First Elements
 * @param iNonZeroEl[noZeroEl] Indexes Non Zero Elements
 * @param values[noZeroEl] Input Values
 * @param mulRes[size] Multiplication Result
 * @param vector[size] Input Vector
 */
void smvm_loop1P(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);

/**
 * Sparse Matrix Multiplication Loop 1 Unrolling Factor=2 Design.
 * @param iFirstEl[rows+1] Indexes First Elements
 * @param iNonZeroEl[noZeroEl] Indexes Non Zero Elements
 * @param values[noZeroEl] Input Values
 * @param mulRes[size] Multiplication Result
 * @param vector[size] Input Vector
 */
void smvm_loop1U2(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);

/**
 * Sparse Matrix Multiplication Loop 2 Pipeline and Unrolling Factor=2 Design.
 * @param iFirstEl[rows+1] Indexes First Elements
 * @param iNonZeroEl[noZeroEl] Indexes Non Zero Elements
 * @param values[noZeroEl] Input Values
 * @param mulRes[size] Multiplication Result
 * @param vector[size] Input Vector
 */
void smvm_loop2PU2(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);

#endif
