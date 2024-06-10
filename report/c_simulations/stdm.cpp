#include "definitions.h"

void std_multiplication(DTYPE matrix[size][size], DTYPE *y, DTYPE *x) {
	for (int i = 0; i < size; i++) {
		DTYPE ytmp = 0;
		for (int j = 0; j < size; j++)
			ytmp += matrix[i][j] * x[j];
		y[i] = ytmp;
	}
}
