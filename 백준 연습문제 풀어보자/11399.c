#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define Swap(a,b){int temp; temp = a; a = b; b= temp;}

int main()
{
	int person,sum = 0;
	int* arr;
	scanf("%d", &person);
	arr = (int*)malloc(sizeof(int) * person);
	for (int i = 0; i < person; i++) 
		scanf("%d",&arr[i]);

	for(int i =0; i<person-1; i++)
		for (int j = i + 1; j < person; j++) 
			if (arr[i] > arr[j]) 
				Swap(arr[i], arr[j]);
	
	for (int i = 0; i < person; i++) {
		for (int j = 0; j < i+1; j++)
			sum += arr[j];
	}

	printf("%d", sum);

	free(arr);

	return 0;
}