/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "hanoi.h"
#include "hanoi_const_value.h"
#include "cmd_console_tools.h"
#include "cmd_hdc_tools.h"
using namespace std;
/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
static int isShow = 0;
static int speed = 0;
static int steps = 0;
int stk[3][12];
int ptr[3];

void wait()
{
	if (speed != 0)
		Sleep(speed);
	else {
		int ch;
		while (true) {
			ch = _getch();
			if (ch == 13)
				break;
		}
	}
}

void showch(const int X, const int Y, const char ch)
{
	cct_gotoxy(X, Y);
	putchar(ch);
}

void outputGraph(const int op)
{
	int xa = 0;
	int underMenu = 0;
	if (op == 4) {
		xa = MenuItem4_Start_X + Underpan_A_X_OFFSET;
		underMenu = MenuItem4_Start_Y + Underpan_A_Y_OFFSET;
	}
	else if (op == 8) {
		xa = MenuItem8_Start_X + Underpan_A_X_OFFSET;
		underMenu = MenuItem8_Start_Y + Underpan_A_Y_OFFSET;
	}
	else if (op == 9) {
		xa = MenuItem9_Start_X + Underpan_A_X_OFFSET;
		underMenu = MenuItem9_Start_Y + Underpan_A_Y_OFFSET;
	}
	const int xb = xa + Underpan_Distance;
	const int xc = xb + Underpan_Distance;

	showch(xa, underMenu, 'A');
	showch(xb, underMenu, 'B');
	showch(xc, underMenu, 'C');
	for (int i = xa - 2; i <= xa + 2 + 2 * (Underpan_Distance); i++) {
		showch(i, underMenu - 1, '=');
	}
	for (int h = underMenu - 2, i = 0; i < 10; i++) {
		char num = stk[0][i] + '0';
		if (stk[0][i]) {
			if (stk[0][i] == 10) {
				cct_gotoxy(xa - 1, h);
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
	for (int h = underMenu - 2, i = 0; i < 10; i++) {
		char num = stk[1][i] + '0';
		if (stk[1][i]) {
			if (stk[1][i] == 10) {
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
	for (int h = underMenu - 2, i = 0; i < 10; i++) {
		char num = stk[2][i] + '0';
		if (stk[2][i]) {
			if (stk[2][i] == 10) {
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

void outputStatus(int op)
{
	cout << " A:";
	for (int i = 0; i < 10; i++)
		if (stk[0][i])
			cout << right << setw(2) << stk[0][i];
		else
			cout << "  ";

	cout << " B:";
	for (int i = 0; i < 10; i++)
		if (stk[1][i])
			cout << right << setw(2) << stk[1][i];
		else
			cout << "  ";

	cout << " C:";
	for (int i = 0; i < 10; i++)
		if (stk[2][i])
			cout << right << setw(2) << stk[2][i];
		else
			cout << "  ";
	cout << endl;
}

void animate(int n, char src, char dst, int op, int from_top, int to_top)
{
	const int dist = dst - src;
	int srcX[3];
	for (int i = 0; i < 3; i++)
		srcX[i] = HDC_Start_X + (23 * i + 11) * HDC_Base_Width + HDC_Underpan_Distance * i;
	int width = (2 * n + 1) * HDC_Base_Width;
	int color = HDC_COLOR[n];
	if (steps < 7)
		wait();
	for (int y = HDC_Start_Y - (from_top + 1) * HDC_Base_High - HDC_Step_Y; y >= HDC_Top_Y; y -= HDC_Step_Y) {
		if (y < HDC_Start_Y - from_top * HDC_Base_High) {
			hdc_rectangle(srcX[src - 'A'] - width / 2 + HDC_Base_Width / 2,
				y + HDC_Base_High,
				width, HDC_Step_Y,
				HDC_COLOR[0]);
			if (y + HDC_Base_High >= HDC_Start_Y - 12 * HDC_Base_High) {
				hdc_rectangle(srcX[src - 'A'],
					y + HDC_Base_High,
					HDC_Base_Width, HDC_Step_Y,
					HDC_COLOR[11]); // 如果清除区域与柱子重叠，重绘柱子部分
			}
		}
		hdc_rectangle(srcX[src - 'A'] - width / 2 + HDC_Base_Width / 2,
			y,
			width, HDC_Base_High,
			color);
		if (steps < 7)
			wait();
	}
	if (dist > 0)
		for (int x = srcX[src - 'A']; x <= srcX[dst - 'A']; x += HDC_Step_X) {
			if (x > srcX[src - 'A']) {
				hdc_rectangle(x - HDC_Step_X - width / 2 + HDC_Base_Width / 2,
					HDC_Top_Y,
					HDC_Step_X, HDC_Base_High,
					HDC_COLOR[0]);
			}
			hdc_rectangle(x - width / 2 + HDC_Base_Width / 2,
				HDC_Top_Y,
				width, HDC_Base_High,
				color);
			if (steps < 7)
				wait();
		}
	else if (dist < 0)
		for (int x = srcX[src - 'A']; x >= srcX[dst - 'A']; x -= HDC_Step_X) {
			if (x < srcX[src - 'A']) {
				hdc_rectangle(x + width / 2 + HDC_Base_Width / 2,
					HDC_Top_Y,
					HDC_Step_X, HDC_Base_High,
					HDC_COLOR[0]);
			}
			hdc_rectangle(x - width / 2 + HDC_Base_Width / 2,
				HDC_Top_Y,
				width, HDC_Base_High,
				color);
			if (steps < 7)
				wait();
		}
	for (int y = HDC_Top_Y; y <= HDC_Start_Y - (to_top + 1) * HDC_Base_High; y += HDC_Step_Y) {
		if (y > HDC_Top_Y) {
			hdc_rectangle(srcX[dst - 'A'] - width / 2 + HDC_Base_Width / 2,
				y - HDC_Step_Y,
				width, HDC_Step_Y,
				HDC_COLOR[0]);
			if (y - HDC_Step_Y >= HDC_Start_Y - 12 * HDC_Base_High) {
				hdc_rectangle(srcX[dst - 'A'],
					y - HDC_Step_Y,
					HDC_Base_Width, HDC_Step_Y,
					HDC_COLOR[11]); // 如果清除区域与柱子重叠，重绘柱子部分
			}
		}
		hdc_rectangle(srcX[dst - 'A'] - width / 2 + HDC_Base_Width / 2,
			y,
			width, HDC_Base_High,
			color);
		if (steps < 7)
			wait();
	}
}

void init(int op, int n, char src)
{
	if (op == 4) {
		cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
		cout << "初始: ";
	}
	else if (op == 9) {
		cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y);
		cout << "初始: ";
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <= 10; j++) {
			stk[i][j] = 0;
			ptr[i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		if (src == 'A') {
			stk[0][i] = n - i;
			ptr[0] = n;
		}
		else if (src == 'B') {
			stk[1][i] = n - i;
			ptr[1] = n;
		}
		else {
			stk[2][i] = n - i;
			ptr[2] = n;
		}
	}
	if (op == 4)
		outputStatus(4);
}

void initPrint(int op, int steps, int n, char src, char dst)
{
	cct_cls();
	hdc_cls();
	if (op == 8) {
		cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y);
		cout << "初始:  ";
		outputStatus(8);
		outputGraph(8);
		cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y + 3);
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << "层，延时设置为 " << speed << "（前7步，后面自动变为0ms）";
	}
	else if (op == 9) {
		cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 3);
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
	}
	else {
		cct_gotoxy(0, 36);
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层";
	}
	Sleep(HDC_Init_Delay);
	drawCol();
	int col_index = src - 'A';
	for (int i = 1; i <= n; i++) {
		int width = (2 * (n - i + 1) + 1) * HDC_Base_Width;
		int x = HDC_Start_X + 23 * HDC_Base_Width * col_index + HDC_Underpan_Distance * col_index + (23 * HDC_Base_Width - width) / 2;
		int y = HDC_Start_Y - i * HDC_Base_High;
		hdc_rectangle(x, y, width, HDC_Base_High, HDC_COLOR[n - i + 1]);
		Sleep(HDC_Init_Delay);
	}
}

void Output_4(int n, char src, char dst, int order)
{
	outputGraph(4);
	cct_gotoxy(MenuItem4_Start_X, MenuItem4_Start_Y);
	cout << "第" << right << setw(4) << steps << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
	Move(src, dst);
	outputStatus(4);
	wait();
}

void Move(char src, char dst)
{
	int k = src - 'A';
	int t = dst - 'A';
	int val = stk[k][ptr[k] - 1];
	stk[k][--ptr[k]] = 0;
	stk[t][ptr[t]++] = val;
}

void solve(int n, char src, char dst, int op, int order)
{
	if (op == 1) {
		cout << n << "# " << src << "---->" << dst << endl;
	}
	else if (op == 2) {
		cout << "第" << setw(4) << steps << " 步: " << setw(2) << n << "# " << src << "-->" << dst << endl;
	}
	else if (op == 3) {
		cout << "第" << right << setw(4) << steps << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
		Move(src, dst);
		outputStatus(3);
	}
	else if (op == 4) {
		if (order == 1)
			Output_4(n, src, dst, 1);
		else if (order == 2)
			Output_4(n, src, dst, 2);
	}
	else if (op == 7) {
		if (order == 1) {
			if (n == 1) {
				int from = src - 'A';
				int to = dst - 'A';
				animate(n, src, dst, 7, ptr[from] - 1, ptr[to]);
			}
			Move(src, dst);
		}
		else if (order == 2) {
			Move(src, dst);
		}
	}
	else if (op == 8) {
		if (order == 1) {
			Move(src, dst);
			outputGraph(8);
			cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y);
			cout << "第" << right << setw(4) << steps << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
			outputStatus(8);
			if (n == 1) {
				int from = src - 'A';
				int to = dst - 'A';
				animate(n, src, dst, 8, ptr[from], ptr[to] - 1);
			}
			wait();
		}
		else if (order == 2) {
			Move(src, dst);
			outputGraph(8);
			cct_gotoxy(MenuItem8_Start_X, MenuItem8_Start_Y);
			cout << "第" << right << setw(4) << steps << " 步(" << setw(2) << n << "#: " << src << "-->" << dst << ") ";
			outputStatus(8);
			int from = src - 'A';
			int to = dst - 'A';
			animate(n, src, dst, 8, ptr[from], ptr[to] - 1);
			wait();
		}
	}
}

void drawCol()
{
	const int   win_width = 1400, win_high = 900;	//设定屏幕宽度
	const int   win_bgcolor = HDC_COLOR[0], win_fgcolor = HDC_COLOR[0];
	hdc_init(win_bgcolor, win_fgcolor, win_width, win_high);		//用(背景色，前景色，宽度，高度）初始化窗口
	for (int i = 0; i < 3; i++) {
		hdc_rectangle(HDC_Start_X + 23 * HDC_Base_Width * i + HDC_Underpan_Distance * i,
			HDC_Start_Y,
			23 * HDC_Base_Width, HDC_Base_High, HDC_COLOR[11]);
		Sleep(HDC_Init_Delay);
	}
	for (int i = 0; i < 3; i++) {
		hdc_rectangle(HDC_Start_X + (23 * i + 11) * HDC_Base_Width + HDC_Underpan_Distance * i,
			HDC_Start_Y - 12 * HDC_Base_High,
			HDC_Base_Width, 12 * HDC_Base_High, HDC_COLOR[11]);
		Sleep(HDC_Init_Delay);
	}
}

void manageError(int* n, char* src, char* tmp, char* dst, int op)
{
	while (true) {
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> *n;

		if (cin.fail() || *n > 10 || *n < 1) {
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
		cin >> *src;

		if (cin.fail() || *src > 'c' || (*src < 'A' && *src > 'C') || (*src < 'a' && *src > 'C')) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else {
			if (*src >= 'a')
				*src -= 32;
			cin.ignore(2147483647, '\n');
			break;
		}
	}

	while (true) {
		cout << "请输入目标柱(A-C)" << endl;
		cin >> *dst;

		if (cin.fail() || *dst > 'c' || (*dst < 'A' && *dst > 'C') || (*dst < 'a' && *dst > 'C')) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else {
			if (*dst >= 'a')
				*dst -= 32;
			if (src == dst) {
				cout << "目标柱(" << *src << ")不能与起始柱(" << *dst << ")相同" << endl;
				cin.ignore(2147483647, '\n');
				continue;
			}
			cin.ignore(2147483647, '\n');
			break;
		}
	}

	*tmp = 'A' + 'B' + 'C' - *dst - *src;
}

void hanoi(int n, char src, char tmp, char dst, int op)
{
	if (n == 1) {
		steps++;
		return solve(n, src, dst, op, 1);
	}
	hanoi(n - 1, src, dst, tmp, op);
	steps++;
	solve(n, src, dst, op, 2);
	if (op != 7)
		hanoi(n - 1, tmp, src, dst, op);
}

void input(int op)
{
	if (op == 1) {
		solve_123(1);
	}
	else if (op == 2) {
		solve_123(2);
	}
	else if (op == 3) {
		solve_123(3);
	}
	else if (op == 4) {
		solve_4(4);
	}
	else if (op == 5) {
		hdc_cls();
		cct_cls();
		drawCol();
		cct_gotoxy(0, 30);
	}
	else if (op == 6) {
		solve_6(6);
		cct_gotoxy(0, 30);
	}
	else if (op == 7) {
		solve_7(7);
		cct_gotoxy(0, 30);
	}
	else if (op == 8) {
		solve_8(8);
	}
	else if (op == 9) {
		solve_9(9);
	}
}

void solve_123(int op)
{
	int n;
	char src;
	char tmp;
	char dst;
	manageError(&n, &src, &tmp, &dst, op);
	init(op, n, src);
	hanoi(n, src, tmp, dst, op);
}

void solve_4(int op)
{
	int n;
	char src;
	char tmp;
	char dst;
	manageError(&n, &src, &tmp, &dst, op);
	while (true) {
		cout << "请输入移动速度(0-200：0-按回车单步演示 1-200:延时1-200ms)\n";
		cin >> speed;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else {
			if (speed <= 200 && speed >= 0)
				break;
		}
	}
	isShow = 1;
	cct_cls();
	cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << speed << "(ms)";
	init(4, n, src);
	hanoi(n, src, tmp, dst, op);
	outputGraph(4);
	cct_gotoxy(0, MenuItem4_Start_Y + 2);
}

void solve_6(int op)
{
	int n;
	char src;
	char tmp;
	char dst;
	manageError(&n, &src, &tmp, &dst, op);
	initPrint(op, steps, n, src, dst);
}

void solve_7(int op)
{
	int n;
	char src;
	char tmp;
	char dst;
	manageError(&n, &src, &tmp, &dst, op);
	while (true) {
		cout << "请输入移动速度(0-1：0-按回车单步演示 1:延时1ms)";
		cin >> speed;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else {
			if (speed == 0 || speed == 1)
				break;
		}
	}
	initPrint(op, steps, n, src, dst);
	init(7, n, src);
	hanoi(n, src, tmp, dst, 7);
}

void solve_8(int op)
{
	int n;
	char src;
	char tmp;
	char dst;
	manageError(&n, &src, &tmp, &dst, op);
	while (true) {
		cout << "请输入移动速度(0-1：0-按回车单步演示 1:延时1ms)";
		cin >> speed;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else {
			if (speed == 0 || speed == 1)
				break;
		}
	}
	cct_cls();
	hdc_cls();
	init(8, n, src);
	initPrint(8, steps, n, src, dst);
	hanoi(n, src, tmp, dst, 8);
}

void solve_9(int op)
{
	int n;
	char src;
	char tmp;
	char dst;
	manageError(&n, &src, &tmp, &dst, op);
	while (true) {
		cout << "请输入移动速度(0-1：0-按回车单步演示 1:延时1ms)\n";
		cin >> speed;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		else {
			if (speed == 0 || speed == 1)
				break;
		}
	}
	cct_cls();
	hdc_cls();
	init(9, n, src);
	initPrint(9, steps, n, src, dst);
	outputGraph(9);
	int step = 0;
	while (true) {
		char from, to;
		if (ptr[dst - 'A'] == n) {
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 5);
			cout << "我嘞个豆，这你都能通关，不赖！";
			break;
		}
		cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 2);
		cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出)：                         ";

		cct_gotoxy(MenuItem9_Start_X + 59, MenuItem9_Start_Y + 2);
		int ch;
		while (true) {
			ch = _getch();
			if (ch >= 'a' && ch <= 'c' || ch >= 'A' && ch <= 'C' || ch == 'q' || ch == 'Q') {
				from = ch;
				cout << from;
				break;
			}
		}
		while (true) {
			ch = _getch();
			if (ch >= 'a' && ch <= 'c' || ch >= 'A' && ch <= 'C') {
				to = ch;
				cout << to;
				break;
			}
			if (ch == 13)
				break;
		}
		if (ch == 13) {
			if (from == 'q' || from == 'Q') {
				cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 5);
				cout << "游戏结束！ ";
				break;
			}
			else
				continue;
		}
		else if (from == 'q' || from == 'Q')
			continue;
		if (from >= 'a' && from <= 'c')
			from -= 32;
		if (to >= 'a' && to <= 'c')
			to -= 32;
		if (from < 'A' || from > 'C' || to < 'A' || to > 'C') {
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 4);
			cout << "输入错误，柱号必须是A、B、C之一！      ";
			Sleep(2000);
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 4);
			cout << "                                                       ";
			continue;
		}
		if (from == to) {
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 4);
			cout << "源柱和目标柱不能相同！   ";
			Sleep(2000);
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 4);
			cout << "                                    ";
			continue;
		}
		if (ptr[from - 'A'] == 0) {
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 4);
			cout << "源柱为空，无法移动！      ";
			Sleep(2000);
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 4);
			cout << "                                    ";
			continue;
		}
		if (ptr[to - 'A'] > 0 && stk[from - 'A'][ptr[from - 'A'] - 1] > stk[to - 'A'][ptr[to - 'A'] - 1]) {
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 4);
			cout << "不能大盘压小盘，请重输！";
			Sleep(2000);
			cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y + 4);
			cout << "                                    ";
			continue;
		}
		step++;
		int disk_num = 0;
		cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y);
		cout << "第" << right << setw(4) << step << " 步(" << setw(2) << stk[from - 'A'][ptr[from - 'A'] - 1] << "#: " << from << "-->" << to << ") ";
		disk_num = stk[from - 'A'][ptr[from - 'A'] - 1];
		Move(from, to);
		outputGraph(9);
		cct_gotoxy(MenuItem9_Start_X, MenuItem9_Start_Y);
		outputStatus(9);
		animate(disk_num, from, to, 9, ptr[from - 'A'], ptr[to - 'A'] - 1);
		wait();
	}
}