#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
double drand(double low, double high)
{
	return ((double)rand() * (high - low)) / (double)RAND_MAX + low;
}

extern void Compute(double* X, double* Y, double* Z, double* A, long long int i);

int main() {
	long long int i;
	printf("Input Number of digits per vector: ");
	scanf_s("%lld", &i);

	double* X = malloc(sizeof(double) * i);
	double* Y = malloc(sizeof(double) * i);
	double* Z = malloc(sizeof(double) * i);
	double* Z1 = malloc(sizeof(double) * i);

	long long int j;
	int k;
	double A;
	clock_t start, end;
	// sanity check
	A = drand(-1000000.0, 1000000.0);
	srand(time(0));

	for (j = 0; j < 5; j++) {
		X[j] = drand(-1000000.0, 1000000.0);
	}

	for (j = 0; j < 5; j++) {
		Y[j] = drand(-1000000.0, 1000000.0);
	}

	//assembly solution
	Compute(X, Y, Z, &A, i);
	//C solution
	for (j = 0; j < i; j++) {
		Z1[j] = X[j] * A + Y[j];
	}
	printf("\nSANITY CHECK\nA:\n%lf", A);
	printf("\nVector Y:\n");
	for (j = 0; j < 5; j++) {
		printf("%lf ", X[j]);
	}
	printf("\nVector X:\n");
	for (j = 0; j < 5; j++) {
		printf("%lf ", Y[j]);
	}
	printf("\nVector Z Assembly:\n");
	for (j = 0; j < 5; j++) {
		printf("%lf ", Z[j]);
	}
	printf("\nVector Z C:\n");
	for (j = 0; j < 5; j++) {
		printf("%lf ", Z1[j]);
	}
	printf("\n\nTIME COMPARISON:");


	//time comparison
	for (k = 0; k < 30; k++) {
		A = drand(-1000000.0, 1000000.0);
		srand(time(0));

		for (j = 0; j < i; j++) {
			X[j] = drand(-1000000.0, 1000000.0);
		}

		for (j = 0; j < i; j++) {
			Y[j] = drand(-1000000.0, 1000000.0);
		}
		printf("\nrun %d,", k);
		start = clock();
		//assembly solution
		Compute(X, Y, Z, &A, i);
		end = clock();
		printf("%lf,", (double)(end - start) / CLOCKS_PER_SEC);

		//C solution
		start = clock();
		for (j = 0; j < i; j++) {
			Z1[j] = X[j] * A + Y[j];
		}
		end = clock();
		printf("%lf", (double)(end - start) / CLOCKS_PER_SEC);
		for (j = 0; j < i; j++) {
			if (Z1[j] != Z[j]) {
				printf("ERROR MISMATCH VALUE AT INDEX %d", j);
				return 0;
			}
		}
	}
	return 0;
}