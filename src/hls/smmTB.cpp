#include "definitions.h"
#include <iostream>
using namespace std;


void std_multiplication(float matrix[SIZE][SIZE], float *x, float *y);
void smm_unoptimized(int indexesFirstEl[ROWS+1], int indexesNonZeroEl[NNZ], float values[NNZ], float x[SIZE], float y[SIZE]);


int main() {

	int fail = 0;
	float matrix[SIZE][SIZE] = {
			{3, 4, 0, 0},
			{0, 5, 9, 0},
			{2, 0, 3, 1},
			{0, 4, 0, 6}
	};
	float x[SIZE] = {1, 2, 3, 4};
	float ysw[SIZE];
	float values[] = {3, 4, 5, 9, 2, 3, 1, 4, 6};
	int indexesNonZeroEl[] = {0, 1, 1, 2, 0, 2, 3, 1, 3};
	int indexesFirstEl[] = {0, 2, 4, 7, 9};
	float y[SIZE];

	std_multiplication(matrix, x, ysw);
	smm_unoptimized(indexesFirstEl, indexesNonZeroEl, values, x, y);

	for(int i=0; i<SIZE; ++i) {
		if(ysw[i] != y[i])
			fail = 1;
		if(fail == 1)
			cout << "i=" << i << " failed." << endl;
		else
			cout << "i=" << i << " passed." << endl;
	}

	return fail;
}
