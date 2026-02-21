#include <stdio.h>
#define N 200

int main() {
	int i, j, k;
	double A[N][N], B[N][N], C[N][N];


	// Initialize matrices
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			A[i][j] = i + j;
			B[i][j] = i - j;
			C[i][j] = 0;
		}


	// Multiply matrices
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];

	printf("Done\n");
	return 0;
}


