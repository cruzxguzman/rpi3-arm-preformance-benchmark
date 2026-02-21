#include <stdio.h>
#include <pthread.h>
#define N 200
#define NUM_THREADS 4
double A[N][N], B[N][N], C[N][N];

void *multiply(void *arg) {
	int t = *(int *)arg;
	int i, j, k;
	int start = t * (N / NUM_THREADS);
	int end = start + (N / NUM_THREADS);

	for (i = start; i < end; i++)
		for (j = 0; j < N; j++)
			for (k = 0; k < N; k++)
				C[i][j] += A[i][k] * B[k][j];
	return NULL;
}


int main() {
	int i, j, t;
	pthread_t threads[NUM_THREADS];
	int thread_id[NUM_THREADS];


	// Initialize matrices
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			A[i][j] = i + j;
			B[i][j] = i - j;
			C[i][j] = 0;
		}


	// Create threads
	for (t = 0; t < NUM_THREADS; t++) {
		thread_id[t] = t;
		pthread_create(&threads[t], NULL, multiply, &thread_id[t]);
	}


	// Join threads
	for (t = 0; t < NUM_THREADS; t++)
		pthread_join(threads[t], NULL);

	printf("Done\n");
	return 0;
}
