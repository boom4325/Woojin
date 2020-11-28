#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<double> scores(10);
	int i = 0,j =0;
	while(1)
	{
		cout << "점수를 입력하세요: ";
		cin >> scores[i];
		if (scores[i] >= 0.0 && scores[i] <= 10.0) {
			i++;
		}
		else cout << "점수가 크거나 작습니다" << endl;
		if (i == 10)
			break;
	}
	double highest = scores[0], lowest = scores[0];
	for (i = 1; i < scores.size(); i++) {
		if (scores[i] > highest)
			highest = scores[i];
		if (scores[i] < lowest)
			lowest = scores[i];
	}	
	double sum = 0,ave=0;
	cout << "최저,최고를 제외한 점수 : ";
	for (i = 0; i < scores.size(); i++)
		if (scores[i] != highest && scores[i] != lowest) {
			cout << scores[i] << " ";
			sum += scores[i];
			j++;
		}
	cout << endl;
	ave = sum / j;
	cout << "평균 : " << ave << endl << "합 : " << sum << endl;
	
	
	return 0;
}