#include "definitions.h"

/**
 * Sparse Matrix Multiplication Loop 2 Pipeline and Unrolling Factor=8 Design.
 * @param iFirstEl[rows+1] Indexes First Elements
 * @param iNonZeroEl[noZeroEl] Indexes Non Zero Elements
 * @param values[noZeroEl] Input Values
 * @param mulRes[size] Multiplication Result
 * @param vector[size] Input Vector
 */
void smvm_loop2PU8(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]) {
	loop1: for (int i=0; i<rows; i++) {
		DTYPE ytmp = 0;
		loop2: for (int k=iFirstEl[i]; k<iFirstEl[i+1]; k++) {
			#pragma HLS pipeline
			#pragma HLS unroll factor=8
			ytmp += values[k] * vector[iNonZeroEl[k]];
		}
		mulRes[i] = ytmp;
	}
}
