#include "definitions.h"

void smvm(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]) {
	loop1: for (int i=0; i<rows; i++) {
		//#pragma HLS pipeline
		//#pragma HLS unroll factor=2
		DTYPE ytmp = 0;
		loop2: for (int k=iFirstEl[i]; k<iFirstEl[i+1]; k++) {
			//#pragma HLS pipeline
			//#pragma HLS unroll factor=2
			//#pragma HLS loop_tripcount min=0 max=4 avg=2
			//#pragma HLS loop_tripcount min=0 max=8 avg=4
			//#pragma HLS loop_tripcount min=0 max=16 avg=8
			//#pragma HLS array_partition variable=iNonZeroEl block factor=16
			//#pragma HLS array_partition variable=values block factor=16
			//#pragma HLS array_partition variable=vector block factor=16
			ytmp += values[k] * vector[iNonZeroEl[k]];
		}
		mulRes[i] = ytmp;
	}
}