/* 2452098 计算机 赵崇治 */
#include<iostream>
#include<cmath>
using namespace std;

int max(int n, int a, int b)
{
	return (a > b ? a : b);
}

int max(int n, int a, int b, int c)
{
	if (a > b && a > c) {
		return a;
	}
	else if (b > a && b > c) {
		return b;
	}
	else {
		return c;
	}
}

int max(int n, int a, int b, int c, int d)
{
	if (a > b && a > c && a > d) {
		return a;
	}
	else if (b > a && b > c && b > d) {
		return b;
	}
	else if (c > a && c > b && c > d) {
		return c;
	}
	else {
		return d;
	}
}

int main()
{
	int n, a, b, c = INT_MIN, d = INT_MIN;

	while (1) {
		cout << "请输入个数num及num个正整数：\n";
		cin >> n;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (n < 1 || n>4) {
			cout << "个数输入错误\n";
			return 0;
		}
		else if (n == 2) {
			cin >> a >> b;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				if (a > 0 && b > 0) {
					break;
				}
			}
		}
		else if (n == 3) {
			cin >> a >> b >> c;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				if (a > 0 && b > 0 && c > 0) {
					break;
				}
			}
		}
		else if (n == 4) {
			cin >> a >> b >> c >> d;
			if (cin.good() == 0) {
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				if (a > 0 && b > 0 && c > 0 && d > 0) {
					break;
				}
			}
		}
	}

	cout << "max=" << max(n, a, b, c, d) << endl;

	return 0;
}
