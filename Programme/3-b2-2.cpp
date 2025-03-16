/* 2452098 计算机 */
#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int num, w, q, b, s, g;
    cout << "请输入一个[1..30000]间的整数:\n";
    cin >> num;
    g = num % 10;
    num /= 10;
    s = num % 10;
    num /= 10;
    b= num % 10;
    num /= 10;
    q = num % 10;
    num /= 10;
    w = num;

    cout << setw(3) << setiosflags(ios::left) << "万位" << " : " << w << endl;
    cout << setw(3) << setiosflags(ios::left) << "千位" << " : " << q << endl;
    cout << setw(3) << setiosflags(ios::left) << "百位" << " : " << b << endl;
    cout << setw(3) << setiosflags(ios::left) << "十位" << " : " << s << endl;
    cout << setw(3) << setiosflags(ios::left) << "个位" << " : " << g << endl;

    return 0;
}
