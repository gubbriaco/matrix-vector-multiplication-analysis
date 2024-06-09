#ifndef DEFINITIONS_H


/**
* Square Matrix Size. Possible values for different implementations: 4, 8, 16.
*/
const static int size = 4;

/**
* Number of Non-Zero Elements. Possible values for different implementations: 9, 13, 16.
*/
const static int noZeroEl  = 9;

/**
* Number of Rows. Possible values for different implementations: 4, 8, 16.
*/
const static int rows = 16;

/**
* Data Type.
*/
typedef int DTYPE;

/**
* Standard Matrix Multiplication Design.
* @param matrix[size][size] Input matrix
* @param resMul Multiplication Result
* @param vector Input Vector
*/
void std_multiplication(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);

/**
* Sparse Matrix Multiplication Design.
* @param iFirstEl[rows+1] Indexes First Elements
* @param iNonZeroEl[noZeroEl] Indexes Non Zero Elements
* @param values[noZeroEl] Input Values
* @param mulRes[size] Multiplication Result
* @param vector[size] Input Vector
*/
void smvm(DTYPE matrix[size][size], DTYPE *mulRes, DTYPE *vector);


#endif