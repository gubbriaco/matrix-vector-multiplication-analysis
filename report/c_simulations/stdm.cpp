#include "definitions.h"

void std_multiplication(DTYPE matrix[size][size], DTYPE *mulRes, DTYPE *vector) {
	for (int i=0; i<size; i++) {
		DTYPE ytmp = 0;
		for (int j=0; j<size; j++)
		ytmp += matrix[i][j] * vector[j];
		mulRes[i] = ytmp;
	}
}