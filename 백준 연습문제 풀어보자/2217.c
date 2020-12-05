#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000
#define Swap(a,b){int temp; temp = a; a = b; b= temp;}

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot);
		do
			high--;
		while (list[high] > pivot);
		if (low < high) Swap(list[low], list[high]);
	} while (low < high);
	Swap(list[left], list[high]);
	return high;
}

void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main() 
{
	int cnt,sum1=0,sum2=0;
	scanf("%d", &cnt);
	int* weight = malloc(sizeof(int) * cnt);
	for (int i = 0; i < cnt; i++)
		scanf("%d", &weight[i]);

	quick_sort(weight, 0, cnt - 1);

	for (int i = 0; i < cnt; i++) {
		sum2 = weight[i] * (cnt - i);
		if (sum2 > sum1) {
			sum1 = sum2;
		}
	}

	printf("%d", sum1);
	free(weight);
	return 0;
}