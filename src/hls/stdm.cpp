#include "definitions.h"

void std_multiplication(
		int matrix[size][size],
		int *mulRes,
		int *vector
) {
	for(int i=0; i<size; ++i) {
		float ytmp = 0;
		for(int j=0; j<size; ++j) {
			ytmp += matrix[i][j] * vector[j];
		}
		*mulRes = ytmp;
	}
}
