#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int kind, price, sum = 0;;
	
	scanf("%d %d", &kind,&price);
	int* arr= malloc(sizeof(int)*kind);
	
	for (int i = kind-1; i >= 0; i--)
		scanf("%d", &arr[i]);
	for (int i = 0; i < kind; i++) {
		if (price == 0)
			break;
		if (arr[i] > price)
			continue;
		sum += price / arr[i];
		price %= arr[i];
	}
	printf("%d", sum);
	free(arr);

	return 0;
}