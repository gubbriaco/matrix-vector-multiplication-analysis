#include "definitions.h"

/**
 * Standard Matrix Multiplication Design.
 * @param matrix[size][size] Input matrix
 * @param resMul Multiplication Result
 * @param vector Input Vector
 */
void std_multiplication(DTYPE matrix[size][size], DTYPE *mulRes, DTYPE *vector) {
	for (int i = 0; i < size; i++) {
		DTYPE ytmp = 0;
		for (int j = 0; j < size; j++)
			ytmp += matrix[i][j] * vector[j];
		mulRes[i] = ytmp;
	}
}
