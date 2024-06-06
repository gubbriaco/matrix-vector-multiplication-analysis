#include "definitions.h"
#include <iostream>
using namespace std;


void std_multiplication(DTYPE matrix[size][size], DTYPE *mulRes, DTYPE *vector);
void smvm_unoptimized(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl ], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);
void smvm_loop2P(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);
void smvm_loop1P(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);
void smvm_loop1U2(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);
void smvm_loop2PU2(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);
void smvm_loop2PU2C2iNonZeroEl(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);
void smvm_loop2PU2C2values(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);
void smvm_loop2PU2C2vector(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);
void smvm_loop2PU2C2all3(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);
void smvm_loop2PU4(int iFirstEl[rows+1], int iNonZeroEl[noZeroEl], DTYPE values[noZeroEl], DTYPE mulRes[size], DTYPE vector[size]);

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

	std_multiplication(matrix, mulResSW, vector);

	DTYPE mulRes[size];

	smvm_unoptimized(iFirstEl, iNonZeroEl, values, mulRes, vector);
	cout << endl;
	cout << "*** Unoptimized Design ***" << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	smvm_loop2P(iFirstEl, iNonZeroEl, values, mulRes, vector);
	cout << endl;
	cout << "*** Loop 2 Pipeline Design ***" << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	smvm_loop1P(iFirstEl, iNonZeroEl, values, mulRes, vector);
	cout << endl;
	cout << "*** Loop 1 Pipeline Design ***" << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	smvm_loop1U2(iFirstEl, iNonZeroEl, values, mulRes, vector);
	cout << endl;
	cout << "*** Loop 1 Unrolling Factor=2 Design ***" << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	smvm_loop2PU2(iFirstEl, iNonZeroEl, values, mulRes, vector);
	cout << endl;
	cout << "*** Loop 1 Unrolling Factor=2 Design ***" << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	smvm_loop2PU2C2iNonZeroEl(iFirstEl, iNonZeroEl, values, mulRes, vector);
	cout << endl;
	cout << "*** Loop 2 Pipeline, Unrolling Factor=2 and Partitioning Cyclic=2 (iNonZeroEl) Design ***" << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	smvm_loop2PU2C2values(iFirstEl, iNonZeroEl, values, mulRes, vector);
	cout << endl;
	cout << "*** Loop 2 Pipeline, Unrolling Factor=2 and Partitioning Cyclic=2 (values) Design ***" << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	smvm_loop2PU2C2vector(iFirstEl, iNonZeroEl, values, mulRes, vector);
	cout << endl;
	cout << "*** Loop 2 Pipeline, Unrolling Factor=2 and Partitioning Cyclic=2 (vector) Design ***" << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	smvm_loop2PU2C2all3(iFirstEl, iNonZeroEl, values, mulRes, vector);
	cout << endl;
	cout << "*** Loop 2 Pipeline, Unrolling Factor=2 and Partitioning Cyclic=2 (All 3) Design ***" << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	smvm_loop2PU4(iFirstEl, iNonZeroEl, values, mulRes, vector);
	cout << endl;
	cout << "*** Loop 2 Pipeline and Unrolling Factor=4 Design ***" << endl;
	for(int i=0; i<size; ++i) {
		cout << "mulResSW=" << mulResSW[i] << ", ";
		cout << "mulRes=" << mulRes[i] << endl;
		if(mulResSW[i] != mulRes[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	cout << endl;
	return 0;
	//return fail;

}
