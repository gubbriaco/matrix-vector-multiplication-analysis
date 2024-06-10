#include "definitions.h"

void smvm(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]) {
	loop1: for (int i=0; i<rows; i++) {
		DTYPE ytmp = 0;
		loop2: for (int k=iFirstEl[i]; k<iFirstEl[i+1]; k++) {
			#pragma HLS loop_tripcount min=0 max=4 avg=2
			ytmp += values[k] * vector[iNonZeroEl[k]];
		}
		mulRes[i] = ytmp;
	}
}