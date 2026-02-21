#include <stdio.h>
#include <stdlib.h>
#define SIZE 50000000 // 50 million doubles (~400MB)


int main() {
	double *arr = malloc(SIZE * sizeof(double));
	if (!arr) {
		printf("Memory allocation failed\n");
		return 1;
	}

	for (int i = 0; i < SIZE; i++)
		arr[i] = i * 0.5;

	double sum = 0;
	for (int i = 0; i < SIZE; i++)
		sum += arr[i];

	printf("Sum = %f\n", sum);
	free(arr);
	return 0;
}

