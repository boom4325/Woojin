#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

double factorial(int n) {
	if (n <= 1)
		return 1;
	return n * factorial(n - 1);
}

double combination(int n, int m) {
	return factorial(m) / (factorial(n) * factorial(m - n));
}

int main() 
{
	int n,m,T;
	
	scanf("%d", &T);
	double* arr = malloc(sizeof(double) * T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &n, &m);
		arr[i] = combination(n, m);
	}
	for (int i = 0; i < T; i++) {
		printf("%.0lf\n", arr[i]);
	}

	return 0;
}
