#include "definitions.h"

/**
 * Matrix Vector Standard Multiplication Design.
 * @param matrix[size][size] Input matrix
 * @param y Multiplication Result
 * @param x Input Vector
 */
void std_multiplication(DTYPE matrix[size][size], DTYPE *y, DTYPE *x) {
	for (int i = 0; i < size; i++) {
		DTYPE ytmp = 0;
		for (int j = 0; j < size; j++)
			ytmp += matrix[i][j] * x[j];
		y[i] = ytmp;
	}
}
