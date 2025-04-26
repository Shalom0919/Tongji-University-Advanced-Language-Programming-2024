/* 2452098 ¼ÆËã»ú ÕÔ³çÖÎ */
#include<iostream>
using namespace std;
int main()
{
	int times[102] = { 0 };
	int n = 0;
	for (int i = 1; i <= 100;i++){
		for (int j = 1; i * j <= 100; j++) {
			times[i * j]++;
		}
	}

	int k = 0;
	for (int i = 1; i <= 100; i++) {
		if (times[i] % 2) {
			if (k) {
				cout << " " << i;
			}
			else {
				cout << i;
				k++;
			}
		}
	}
	cout << endl;

	return 0;
}