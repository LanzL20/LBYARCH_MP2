#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// Utility function to generate random double number between low and high.
double drand(double low, double high)
{
	return ((double)rand() * (high - low)) / (double)RAND_MAX + low;
}
// Assembly function to compute Z = X * A + Y.
extern void Compute(double* X, double* Y, double* Z, double* A, long long int i);

int main() {
	// Initialize variables needed for the program.
	long long int i;
	printf("Length of Each Vector: ");
	scanf_s("%lld", &i);

	double* X = malloc(sizeof(double) * i);
	double* Y = malloc(sizeof(double) * i);
	double* Z = malloc(sizeof(double) * i);
	double* Z1 = malloc(sizeof(double) * i);

	long long int j;
	int k;
	double A;
	clock_t start, end;

	// Sanity Check
	printf("\n-------------------------------------\n");
	A = drand(-1000000.0, 1000000.0);
	srand(time(0));

	for (j = 0; j < 5; j++) {
		X[j] = drand(-1000000.0, 1000000.0);
	}

	for (j = 0; j < 5; j++) {
		Y[j] = drand(-1000000.0, 1000000.0);
	}

	// Sanity Check: Assembly Solution
	Compute(X, Y, Z, &A, i);
	// Sanity Check: C Solution
	for (j = 0; j < i; j++) {
		Z1[j] = X[j] * A + Y[j];
	}

	// Compare the results of the assembly and C solutions.
	printf("\nSANITY CHECK: Assembly vs C\n\nA: %lf", A);
	printf("\nVector Y: [");
	for (j = 0; j < 5; j++) {
		printf("%lf", X[j]);
		if(j != 4) printf(", ");
	}
	printf("]\nVector X: [");
	for (j = 0; j < 5; j++) {
		printf("%lf", Y[j]);
		if (j != 4) printf(", ");
	}
	printf("]\nVector Z ASM: [");
	for (j = 0; j < 5; j++) {
		printf("%lf", Z[j]);
		if (j != 4) printf(", ");
	}
	printf("]\nVector Z C:   [");
	for (j = 0; j < 5; j++) {
		printf("%lf", Z1[j]);
		if (j != 4) printf(", ");
	}
	printf("]");


	// Time Comparison
	printf("\n\n-------------------------------------");
	printf("\n\nTIME COMPARISON: Assembly vs C (In Seconds)\n");

	// Run the program 30 times and compare the time taken by the assembly and C solutions.
	for (k = 0; k < 30; k++) {
		A = drand(-1000000.0, 1000000.0);
		srand(time(0));

		for (j = 0; j < i; j++) {
			X[j] = drand(-1000000.0, 1000000.0);
		}

		for (j = 0; j < i; j++) {
			Y[j] = drand(-1000000.0, 1000000.0);
		}
		printf("\nRun %02d: ", k + 1);

		// Time Comparison: Assembly Solution
		start = clock();
		Compute(X, Y, Z, &A, i);
		end = clock();
		printf("%lf, ", (double)(end - start) / CLOCKS_PER_SEC);

		// Time Comparison: C Solution
		start = clock();
		for (j = 0; j < i; j++) {
			Z1[j] = X[j] * A + Y[j];
		}
		end = clock();
		printf("%lf", (double)(end - start) / CLOCKS_PER_SEC);

		// Check if the results of the assembly and C solutions match.
		for (j = 0; j < i; j++) {
			if (Z1[j] != Z[j]) {
				printf("\nERROR MISMATCH VALUE AT INDEX %d", j);
				return 0;
			}
		}
	}
	return 0;
}