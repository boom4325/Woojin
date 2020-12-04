#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int price, change,cnt=0;

	scanf("%d", &price);
	change = 1000 - price;
	while (1) {
		if (change == 0)
			break;
		if (change >= 500) {
			change -= 500;
			cnt++;
			continue;
		}
		if (change >= 100) {
			change -= 100;
			cnt++;
			continue;
		}
		if (change >= 50) {
			change -= 50;
			cnt++;
			continue;
		}
		if (change >= 10) {
			change -= 10;
			cnt++;
			continue;
		}
		if (change >= 5) {
			change -= 5;
			cnt++;
			continue;
		}
		if (change >= 1) {
			change -= 1;
			cnt++;
			continue;
		}
	}
	printf("%d", cnt);

	return 0;
}