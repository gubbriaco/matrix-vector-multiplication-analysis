#include "definitions.h"

void std_multiplication(float matrix[SIZE][SIZE], float *x, float *y) {
	for(int i=0; i<SIZE; ++i) {
		float ytmp = 0;
		for(int j=0; j<SIZE; ++j) {
			ytmp += matrix[i][j] * x[j];
		}
		*y = ytmp;
	}
}
