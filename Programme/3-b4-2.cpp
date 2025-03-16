/* 2452098 计算机 赵崇治 */
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
	int a, b, angle;
	float s;
	const double pi = 3.14159;
	cout << "请输入三角形的两边及其夹角(角度)\n";
	cin >> a >> b >> angle;
	
	s = float(1.0f / 2 * a * b * sin(angle * pi / 180.0));

	cout << "三角形面积为 : " << setiosflags(ios::fixed) << setprecision(3)<< s << endl;
	return 0;
}