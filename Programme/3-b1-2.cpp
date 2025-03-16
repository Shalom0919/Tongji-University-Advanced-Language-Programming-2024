/* 2452098 计算机 赵崇治 */
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    double r, h, c, sCircle, sSphere, vSphere, vColumn;
    const double pi = 3.14159;
    cout << "请输入半径和高度" << endl;
    cin >> r >> h;

    c = 2 * pi * r;
    sCircle = pi * r * r;
    sSphere = 4 * pi * r * r;
    vSphere = pi * r * r * r * 4 / 3;
    vColumn = pi * r * r * h;

    cout << setw(10) << setiosflags(ios::left) << setiosflags(ios::fixed) << setprecision(2) << "圆周长" << " : " << c << endl;
    cout << setw(10) << setiosflags(ios::left) << "圆面积" << " : " << sCircle << endl;
    cout << setw(10) << setiosflags(ios::left) << "圆球表面积" << " : " << sSphere << endl;
    cout << setw(10) << setiosflags(ios::left) << "圆球体积" << " : " << vSphere << endl;
    cout << setw(10) << setiosflags(ios::left) << "圆柱体积" << " : " << vColumn << endl;

    return 0;
}
