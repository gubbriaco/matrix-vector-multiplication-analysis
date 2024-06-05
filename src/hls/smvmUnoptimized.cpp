#include "definitions.h"


void smvm_unoptimized(
		int iFirstEl[rows+1],
		int iNonZeroEl[noZeroEl],
		int values[noZeroEl],
		int mulRes[size],
		int vector[size]
) {

	loop1 : for(int i=0; i<rows; ++i) {
		int ytmp = 0;
		loop2 : for(int k=iFirstEl[i]; k<iFirstEl[i+1]; ++k) {
			ytmp += values[k] * vector[iNonZeroEl[k]];
		}
		mulRes[i] = ytmp;
	}

}
