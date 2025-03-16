/* 2452098 计算机 赵崇治 */
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
    double oldNum;
    int sy, y, qw, bw, sw, w, q, b, s, g, j, f;
    cout << "请输入[0-100亿)之间的数字:\n";
    cin >> oldNum;

    double num = (floor(oldNum));
    double partialNum = round((oldNum - num) * 100);

    sy = int(num / 1e9);
    num -= sy * 1e9;
    y = int(num / 1e8);
    num -= y * 1e8;
    qw = int(num / 1e7);
    num -= qw * 1e7;
    bw = int(num / 1e6);
    num -= bw * 1e6;
    sw = int(num / 1e5);
    num -= sw * 1e5;
    w = int(num / 1e4);
    num -= w * 1e4;
    q = int(num / 1e3);
    num -= q * 1e3;
    b = int(num / 100);
    num -= b * 100;
    s = int(num / 10);
    num -= s * 10;
    g = int(num);
    j = int(partialNum / 10);
    f = int(partialNum - j * 10);


    cout << setw(6) << setiosflags(ios::left) << "十亿位" << " : " << sy << endl;
    cout << setw(6) << setiosflags(ios::left) << "亿位" << " : " << y << endl;
    cout << setw(6) << setiosflags(ios::left) << "千万位" << " : " << qw << endl;
    cout << setw(6) << setiosflags(ios::left) << "百万位" << " : " << bw << endl;
    cout << setw(6) << setiosflags(ios::left) << "十万位" << " : " << sw << endl;
    cout << setw(6) << setiosflags(ios::left) << "万位" << " : " << w << endl;
    cout << setw(6) << setiosflags(ios::left) << "千位" << " : " << q << endl;
    cout << setw(6) << setiosflags(ios::left) << "百位" << " : " << b << endl;
    cout << setw(6) << setiosflags(ios::left) << "十位" << " : " << s << endl;
    cout << setw(6) << setiosflags(ios::left) << "圆" << " : " << g << endl;
    cout << setw(6) << setiosflags(ios::left) << "角" << " : " << j << endl;
    cout << setw(6) << setiosflags(ios::left) << "分" << " : " << f << endl;

    return 0;
}