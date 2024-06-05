#include "definitions.h"
#include <iostream>
using namespace std;


void std_multiplication(DTYPE matrix[size][size], DTYPE *mulRes, DTYPE *vector);
void smvm_unoptimized(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl ], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);


int main() {

	int fail = 0;
	DTYPE matrix[size][size] = {
			{3,4,0,0},
			{0,5,9,0},
			{2,0,3,1},
			{0,4,0,6}
	};
	DTYPE vector[size] = {1,1,1,1};
	DTYPE mulResSW[size];
	DTYPE values[] = {3,4,5,9,2,3,1,4,6};
	int iNonZeroEl[] = {0,1,1,2,0,2,3,1,3};
	int iFirstEl[] = {0,2,4,7,9};
	DTYPE mulRes[size];

	smvm_unoptimized(iFirstEl, iNonZeroEl, values, mulRes, vector);
	std_multiplication(matrix, mulResSW, vector);

	cout << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i])
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl << endl;
		else
			cout << "i=" << i << " passed." << endl << endl;
	}

	return 0;
	//return fail;

}
