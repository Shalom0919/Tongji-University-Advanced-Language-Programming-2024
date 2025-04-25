/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <iomanip>
using namespace std;
static int steps;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：打印n层汉诺塔的移动顺序
	 输入参数：int n：层数
			   char src：起始柱
			   char tmp：中间柱
			   char dst：目标柱
	 返 回 值：
	 说    明：1、函数名、形参、返回类型均不准动
			   2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 1) {
		steps++;
		cout << setw(5) << steps << ": " << setw(2) << n << "# " << src << "-->" << dst << endl;
		return;
	}

	hanoi(n - 1, src, dst, tmp);
	steps++;
	cout << setw(5) << steps << ": " << setw(2) << n << "# " << src << "-->" << dst << endl;
	hanoi(n - 1, tmp, src, dst);
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
			2、处理输入错误时，允许使用循环
			3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
	int n;
	char from, tmp, to;
	bool valid = false;
	while (!valid) {
		cout << "请输入汉诺塔的层数(1-16)\n";
		if (cin >> n) {
			if (n >= 1 && n <= 16) {
				valid = true;
			}
		}
		if (!valid) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	cin.clear();
	cin.ignore(65536, '\n');

	cout << "请输入起始柱(A-C)\n";
	while (cin >> from) {
		if (from - 'A' >= 0 && from - 'A' <= 2) {
			break;
		}
		else if (from - 'a' >= 0 && from - 'a' <= 2) {
			from = char(from - 32);
			break;
		}
		else {
			cout << "请输入起始柱(A-C)\n";
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	cin.clear();
	cin.ignore(65536, '\n');

	cout << "请输入目标柱(A-C)\n";
	while (cin >> to) {
		if (to - 'A' >= 0 && to != from && to - 'A' <= 2) {
			break;
		}
		else if (to - 'a' >= 0 && to - 'a' <= 2) {
			to = char(to - 32);
			if (to != from) {
				break;
			}
			else {
				cout << "目标柱(" << to << ")不能与起始柱(" << from << ")相同\n";
			}
		}
		else {
			if (to == from) {
				cout << "目标柱(" << to << ")不能与起始柱(" << from << ")相同\n";
			}
			cout << "请输入目标柱(A-C)\n";
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}

	tmp = 'A' + 'B' + 'C' - to - from;

	cout << "移动步骤为:\n";
	hanoi(n, from, tmp, to);

	return 0;
}