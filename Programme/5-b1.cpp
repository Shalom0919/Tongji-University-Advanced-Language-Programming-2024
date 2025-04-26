/* 245N98 计算机 赵崇治 */
#include<iostream>
using namespace std;
#define N 20

int main()
{
	int a[N + 1] = { 0 };
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (a[i] <= 0) {
			break;
		}
	}
	cin.ignore(2147483647, '\n');
	if (a[0] <= 0) {
		cout << "无有效输入\n";
		return 0;
	}

	cout << "原数组为：\n";
	for (int i = 0; i < N; i++) {
		if (a[i] > 0)
			cout << a[i] << " ";
	}
	cout << endl;

	cout << "请输入要插入的正整数\n";
	cin >> a[20];

	/*int left = 0;
	int right = N;
	int mid = 0;
	while (left <= right) {
		mid = (left + right) / 2;
		if (a[mid] > num) {
			if (mid == 0)
			{
				right = 0;
				break;
			}
			else
				right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	int ans[N + 1] = { 0 };
	ans[right] = num;
	for (int i = 0; i < right; i++) {
		ans[i] = a[i];
	}
	for (int i = right; i < N; i++) {
		ans[i + 1] = a[i];
	}卧槽了末尾有0用不了装逼失败*/

	int i, j, k, t;
	for (i = 0; i <= N; ++i) {
		k = i;
		for (j = i + 1; j <= N; j++) {
			if (a[j] < a[k]) {
				k = j;
			}
		}
		t = a[k];
		a[k] = a[i];
		a[i] = t;
	}

	cout << "插入后的数组为：\n";
	for (int i = 0; i <= N; i++) {
		if (a[i] > 0)
			cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}