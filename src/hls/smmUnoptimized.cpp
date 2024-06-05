#include "definitions.h"


void smm_unoptimized(int indexesFirstEl[ROWS+1], int indexesNonZeroEl[NNZ], float values[NNZ], float x[SIZE], float y[SIZE]) {

	loop1 : for(int i=0; i<ROWS; ++i) {
		float ytmp = 0;
		loop2 : for(int k=indexesFirstEl[i]; k<indexesFirstEl[i+1]; ++k) {
			ytmp += values[k] * x[indexesNonZeroEl[k]];
		}
		y[i] = ytmp;
	}

}
