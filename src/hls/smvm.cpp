#include "definitions.h"

/**
 * Sparse Matrix Vector Multiplication Design (CRS format).
 * @param rowPtr[rows+1] Indexes First Elements
 * @param columnIndex[nnz] Indexes Non Zero Elements
 * @param values[nnz] Input Values
 * @param y[size] Multiplication Result
 * @param x[size] Input Vector
 */
void smvm(int rowPtr[rows+1], int columnIndex[nnz], DTYPE values[nnz], DTYPE y[size], DTYPE x[size]) {
	loop1: for (int i=0; i<rows; i++) {
		//#pragma HLS pipeline
		//#pragma HLS unroll factor=2
		DTYPE ytmp = 0;
		loop2: for (int k=rowPtr[i]; k<rowPtr[i+1]; k++) {

			//#pragma HLS pipeline

			//#pragma HLS unroll factor=2

			//#pragma HLS loop_tripcount min=0 max=4 avg=2
			//#pragma HLS loop_tripcount min=0 max=8 avg=4

			//#pragma HLS array_partition variable=columnIndex cyclic factor=2
			//#pragma HLS array_partition variable=values cyclic factor=2
			//#pragma HLS array_partition variable=x cyclic factor=2

			ytmp += values[k] * x[columnIndex[k]];
		}
		y[i] = ytmp;
	}
}
