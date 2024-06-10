#include "definitions.h"

void smvm(int rowPtr[rows+1], int columnIndex[nnz], DTYPE values[nnz], DTYPE y[size], DTYPE x[size]) {
	loop1: for (int i=0; i<rows; i++) {
		DTYPE ytmp = 0;
		loop2: for (int k=rowPtr[i]; k<rowPtr[i+1]; k++) {
			ytmp += values[k] * x[columnIndex[k]];
		}
		y[i] = ytmp;
	}
}
