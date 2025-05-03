/* 2452098 计算机 赵崇治 */
#include<cmath>
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	cout << "请输入x的值[-10 ~ +65]\n";
	int x;
	double n = 1.0;
	double exp = 1.0;
	double factor = 1.0;
	cin >> x;

	while (x < -10 || x > 65) {
		cout << "输入非法，请重新输入\n";
		cout << "请输入x的值[-10 ~ +65]\n";
		cin >> x;
	}

	while (fabs(factor) >= 1e-6) {
		factor *= x / n;
		n++;
		exp += factor;
	}
	exp -= factor;

	cout << "e^" << x << "=" << setprecision(10) << exp << endl;
	return 0;
}