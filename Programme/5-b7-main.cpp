/* 2452098 计算机 赵崇治 */
//2h40min 
#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include"5-b7.h"
using namespace std;

static int isShow = 0;
static int speed = 0;
int ptrA = 0;
int ptrB = 0;
int ptrC = 0;
int a[11];
int b[11];
int c[11];
int steps = 0;

/***************************************************************************
  函数名称：wait
  功    能：等待的输出间隔
  输入参数：无
  返 回 值：无
  说    明：倒头就睡，那很有生活了
***************************************************************************/
void wait() {
	switch (speed)
	{
		case(1):
			Sleep(1000);
			break;
		case(2):
			Sleep(500);
			break;
		case(3):
			Sleep(200);
			break;
		case(4):
			Sleep(50);
			break;
		case(5):
			break;
		default:
			int ch;
			while (true) {
				ch = _getch();
				if (ch == 13)
					break;
			}
	}
}

/***************************************************************************
  函数名称：showch
  功    能：显示字符
  输入参数：坐标以及字符
  返 回 值：无
  说    明：以光标移动方式
***************************************************************************/
void showch(const int X, const int Y, const char ch)
{
	cct_gotoxy(X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：outputGraph
  功    能：输出当前三个柱子上的图形
  输入参数：无
  返 回 值：无
  说    明：格式化方式显示，注意输出10是2个字符，一不小心容易翻车
***************************************************************************/
void outputGraph() {
	for (int i = 10; i <= 34; i++) {
		showch(i, 25, '=');
	}
	int xa = 12;
	int xb = 22;
	int xc = 32;
	showch(xa, 26, 'A');
	showch(xb, 26, 'B');
	showch(xc, 26, 'C');
	for (int h = 24, i = 0; i < 10; i++) {
		char num = a[i] + '0';
		if (a[i]) {
			if (a[i] == 10) {
				cct_gotoxy(xa-1, h);
				cout << "10";
			}
			else 
				showch(xa, h, num);
			h--;
		}
		else {
			showch(xa - 1, h, ' ');
			showch(xa, h, ' ');
			break;
		}
	}
	for (int h = 24, i = 0; i < 10; i++) {
		char num = b[i] + '0';
		if (b[i]) {
			if (b[i] == 10) {
				cct_gotoxy(xb - 1, h);
				cout << "10";
			}
			else
				showch(xb, h, num);
			h--;
		}
		else {
			showch(xb - 1, h, ' ');
			showch(xb, h, ' ');
			break;
		}
	}
	for (int h = 24, i = 0; i < 10; i++) {
		char num = c[i] + '0';
		if (c[i]) {
			if (c[i] == 10) {
				cct_gotoxy(xc - 1, h);
				cout << "10";
			}
			else
				showch(xc, h, num);
			h--;
		}
		else {
			showch(xc - 1, h, ' ');
			showch(xc, h, ' ');
			break;
		}
	}
}

/***************************************************************************
  函数名称：outputStatus
  功    能：输出当前三个柱子上盘子的分布状态
  输入参数：无
  返 回 值：无
  说    明：以格式化方式显示A、B、C三根柱子上的盘子分布情况
***************************************************************************/
void outputStatus() {
	cct_gotoxy(42, 30);
	cout << " A:";
	for (int i = 0; i < 10; i++) {
		if (a[i]) {
			cout << right << setw(2) << a[i];
		}
		else cout << "  ";
	}

	cout << " B:";
	for (int i = 0; i < 10; i++) {
		if (b[i]) {
			cout << right << setw(2) << b[i];
		}
		else cout << "  ";
	}

	cout << " C:";
	for (int i = 0; i < 10; i++) {
		if (c[i]) {
			cout << right << setw(2) << c[i];
		}
		else cout << "  ";
	}
	cout << endl;
}

/***************************************************************************
	  函数名称：init
	  功    能：初始化汉诺塔，根据指定起始柱放置盘子
	  输入参数：int n - 汉诺塔的层数
			  char from - 起始柱（'A'、'B'或'C'）
	  返 回 值：无
	  说    明：根据起始柱参数，将n个盘子按从大到小顺序放置在对应柱子上
	***************************************************************************/
void init(int n, char from) {
	cct_gotoxy(10, 30);
	cout << "初始:               ";
	for (int i = 0; i < n; i++) {
		if (from == 'A') {
			a[i] = n - i;
			ptrA = n;
		}
		else if (from == 'B') {
			b[i] = n - i;
			ptrB = n;
		}
		else {
			c[i] = n - i;
			ptrC = n;
		}
	}
	if (isShow)
		outputStatus();
}

/***************************************************************************
  函数名称：move
  功    能：移动一个盘子从一个柱子到另一个柱子
  输入参数：char from - 起始柱（'A'、'B'或'C'）
		  char to - 目标柱（'A'、'B'或'C'）
  返 回 值：无
  说    明：执行单次盘子移动操作，更新内部数组状态
***************************************************************************/
void move(char from, char to) {
	int val;
	switch (from) {
	case('A'):
		val = a[ptrA - 1];
		a[--ptrA] = 0;
		if (to == 'B')
			b[ptrB++] = val;
		else
			c[ptrC++] = val;
		break;
	case('B'):
		val = b[ptrB - 1];
		b[--ptrB] = 0;
		if (to == 'A')
			a[ptrA++] = val;
		else
			c[ptrC++] = val;
		break;
	case('C'):
		val = c[ptrC - 1];
		c[--ptrC] = 0;
		if (to == 'A')
			a[ptrA++] = val;
		else
			b[ptrB++] = val;
		break;
	}
}

/***************************************************************************
  函数名称：hanoi
  功    能：实现汉诺塔的递归移动算法
  输入参数：int n - 要移动的盘子数量
		  char src - 源柱（起始柱）
		  char tmp - 中间柱（辅助柱）
		  char dst - 目标柱
  返 回 值：无
  说    明：使用递归方式实现汉诺塔问题的求解，并显示每一步的移动过程
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst) {
	if (n == 1) {
		steps++;
		outputGraph();
		wait();
		cct_gotoxy(16, 30);
		cout << "第" << right << setw(4) << steps << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
		move(src, dst);
		if (isShow) {
			outputStatus();
			cct_gotoxy(10, 30);
			for (int i = 0; i <= 5; i++) {
				showch(10 + i, 30, ' ');
			}
			wait();
		}
		return;
	}

	hanoi(n - 1, src, dst, tmp);

	steps++;
	outputGraph();
	wait();
	cct_gotoxy(16, 30);
	cout << "第" << right << setw(4) << steps << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
	move(src, dst);
	if (isShow) {
		outputStatus();
		wait();
	}

	hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
	  函数名称：play
	  功    能：封装汉诺塔程序的主控制函数
	  输入参数：无
	  返 回 值：无
	  说    明：处理用户输入，获取汉诺塔层数、起始柱和目标柱，然后执行汉诺塔算法
***************************************************************************/
void play() {
	int n;
	char from, to, tmp;

	while (true) {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> n;

		if (cin.fail() || n > 10 || n < 1) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else {
			cin.ignore(2147483647, '\n');
			break;
		}
	}

	while (true) {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> from;

		if (cin.fail() || from > 'c' || (from < 'A' && from > 'C') || (from < 'a' && from > 'C')) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else {
			if (from >= 'a')
				from -= 32;
			cin.ignore(2147483647, '\n');
			break;
		}
	}

	while (true) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> to;

		if (cin.fail() || to > 'c' || (to < 'A' && to > 'C') || (to < 'a' && to > 'C')) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else {
			if (to >= 'a')
				to -= 32;
			if (from == to) {
				cout << "目标柱(" << from << ")不能与起始柱(" << to << ")相同" << endl;
				cin.ignore(2147483647, '\n');
				continue;
			}
			cin.ignore(2147483647, '\n');
			break;
		}
	}

	tmp = 'A' + 'B' + 'C' - to - from;
	
	cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)\n";
	cin >> speed;

	cout << "请输入是否显示内部数组值(0-不显示 1-显示)\n";
	cin >> isShow;

	cct_cls();
	cout << "从 " << from << " 移动到 " << to << "，共 " << n << " 层，延时设置为 " << speed <<"，";
	if (isShow)
		cout << "显示内部数组值\n";
	else
		cout << "不显示内部数组值\n";
	//system("pause");
	init(n, from);
	wait();
	hanoi(n, from, tmp, to);
	outputGraph();
	cct_gotoxy(0, 3);
	cout << "从 " << from << " 移动到 " << to << "，共 " << n << " 层，延时设置为 " << speed << "，";
	cct_gotoxy(0, 4);
}
//main函数入口
int main()
{
	play();
	system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
	return 0;
}
