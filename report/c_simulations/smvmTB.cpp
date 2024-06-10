#include "definitions.h"
#include <iostream>
using namespace std;

void std_multiplication(DTYPE matrix[size][size], DTYPE *y, DTYPE *x);
void smvm(int rowPtr[rows+1], int columnIndex[nnz], DTYPE values[nnz], DTYPE y[size], DTYPE x[size]);


int main() {
	int fail = 0;

	DTYPE matrix[size][size] = {
		{3,4,0,0},
		{0,5,9,0},
		{2,0,3,1},
		{0,4,0,6}
	};
	DTYPE x[size] = {1, 1, 1, 1};
	DTYPE values[] = {3, 4, 5, 9, 2, 3, 1, 4, 6};
	int columnIndex[] = {0, 1, 1, 2, 0, 2, 3, 1, 3};
	int rowPtr[] = {0,2,4,7,9};
	
	/*
	DTYPE matrix[size][size] = {
		{3, 4, 0, 0, 0, 0, 0, 0},
		{0, 5, 9, 0, 0, 0, 0, 0},
		{2, 0, 3, 1, 0, 0, 0, 0},
		{0, 4, 0, 6, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};
	DTYPE x[size] = {1, 1, 1, 1, 1, 1, 1, 1};
	DTYPE values[] = {3, 4, 5, 9, 2, 3, 1, 4, 6};
	int columnIndex[] = {0, 1, 1, 2, 0, 2, 3, 1, 3};
	int rowPtr[] = {0, 2, 4, 7, 9, 9, 9, 9, 9};
	*/
	/*
	DTYPE matrix[size][size] = {
		{3, 4, 0, 0, 0, 0, 0, 0},
		{0, 5, 9, 0, 0, 0, 0, 0},
		{2, 0, 3, 1, 0, 0, 0, 0},
		{0, 4, 0, 6, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0, 0}
	};
	DTYPE x[size] = {1, 1, 1, 1, 1, 1, 1, 1};
	DTYPE values[] = {3, 4, 5, 9, 2, 3, 1, 4, 6, 1, 1, 1, 1, 1, 1, 1};
	int columnIndex[] = {0, 1, 1, 2, 0, 2, 3, 1, 3, 0, 0, 1, 0, 1, 0, 1};
	int rowPtr[] = {0, 2, 4, 7, 9, 10, 12, 14, 16};
	*/
	
	DTYPE ystd[size];
	std_multiplication(matrix, ystd, x);
	DTYPE y[size];
	smvm(rowPtr, columnIndex, values, y, x);
	cout << endl;
	for(int i=0; i<size; ++i) {
		cout << "ystd=" << ystd[i] << ", ";
		cout << "y=" << y[i] << endl;
		if(ystd[i] != y[i] )
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}
	cout << endl;
	
	return fail;
}
