#include "definitions.h"

void smvm(int rowPtr[rows+1], int columnIndex[nnz], DTYPE values[nnz], DTYPE y[size], DTYPE x[size]) {
	loop1: for (int i=0; i<rows; i++) {
		DTYPE ytmp = 0;
		loop2: for (int k=rowPtr[i]; k<rowPtr[i+1]; k++) {
			#pragma HLS loop_tripcount min=0 max=4 avg=2
			#pragma HLS pipeline
			#pragma HLS unroll factor=2
			#pragma HLS array_partition variable=columnIndex cyclic factor=2
			#pragma HLS array_partition variable=values cyclic factor=2
			#pragma HLS array_partition variable=x cyclic factor=2
			ytmp += values[k] * x[columnIndex[k]];
		}
		y[i] = ytmp;
	}
}