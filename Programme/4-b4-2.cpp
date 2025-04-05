/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：cls
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：输出设备句柄
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？答 : 发生碰撞 */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：menu
  功    能：显示菜单并获取用户选择
  输入参数：无
  返 回 值：int - 用户的选择（0-4）
  说    明：通过简易菜单进行选择
***************************************************************************/
int menu()
{
	cls(GetStdHandle(STD_OUTPUT_HANDLE));
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界停止）" << endl;
	cout << "4.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界回绕）" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "0.退出" << endl;
	cout << "请选择[0-4] ";

	// 直接读取按键，不需要回车确认
	int choice;
	while (true) {
		choice = _getch();
		choice = choice - '0';
		if (choice >= 0 && choice <= 4) {
			return choice;
		}
	}
}

/***************************************************************************
  函数名称：get_new_x_from_ijkl
  功    能：根据IJKL按键获取新的X坐标
  输入参数：int X - 当前光标X坐标
			int key - 按键值
			bool wrap - 是否边界回绕
  返 回 值：int - 新的X坐标
  说    明：处理X坐标变化，根据按键和边界设置确定新位置
***************************************************************************/
int get_new_x_from_ijkl(int X, int key, bool wrap)
{
	int new_X = X;

	if (key == 'J' || key == 'j') { // 左
		if (X > 1)
			new_X = X - 1;
		else if (wrap)
			new_X = MAX_X;
	}
	else if (key == 'L' || key == 'l') { // 右
		if (X < MAX_X)
			new_X = X + 1;
		else if (wrap)
			new_X = 1;
	}

	return new_X;
}

/***************************************************************************
  函数名称：get_new_y_from_ijkl
  功    能：根据IJKL按键获取新的Y坐标
  输入参数：int Y - 当前光标Y坐标
			int key - 按键值
			bool wrap - 是否边界回绕
  返 回 值：int - 新的Y坐标
  说    明：处理Y坐标变化，根据按键和边界设置确定新位置
***************************************************************************/
int get_new_y_from_ijkl(int Y, int key, bool wrap)
{
	int new_Y = Y;

	if (key == 'I' || key == 'i') { // 上
		if (Y > 1)
			new_Y = Y - 1;
		else if (wrap)
			new_Y = MAX_Y;
	}
	else if (key == 'K' || key == 'k') { // 下
		if (Y < MAX_Y)
			new_Y = Y + 1;
		else if (wrap)
			new_Y = 1;
	}

	return new_Y;
}

/***************************************************************************
  函数名称：get_new_x_from_arrow
  功    能：根据箭头按键获取新的X坐标
  输入参数：int X - 当前光标X坐标
			int key - 按键值
			bool wrap - 是否边界回绕
  返 回 值：int - 新的X坐标
  说    明：处理X坐标变化，根据箭头键和边界设置确定新位置
***************************************************************************/
int get_new_x_from_arrow(int X, int key, bool wrap)
{
	int new_X = X;

	if (key == 75) { // 左箭头
		if (X > 1)
			new_X = X - 1;
		else if (wrap)
			new_X = MAX_X;
	}
	else if (key == 77) { // 右箭头
		if (X < MAX_X)
			new_X = X + 1;
		else if (wrap)
			new_X = 1;
	}

	return new_X;
}

/***************************************************************************
  函数名称：get_new_y_from_arrow
  功    能：根据箭头按键获取新的Y坐标
  输入参数：int Y - 当前光标Y坐标
			int key - 按键值
			bool wrap - 是否边界回绕
  返 回 值：int - 新的Y坐标
  说    明：处理Y坐标变化，根据箭头键和边界设置确定新位置
***************************************************************************/
int get_new_y_from_arrow(int Y, int key, bool wrap)
{
	int new_Y = Y;

	if (key == 72) { // 上箭头
		if (Y > 1)
			new_Y = Y - 1;
		else if (wrap)
			new_Y = MAX_Y;
	}
	else if (key == 80) { // 下箭头
		if (Y < MAX_Y)
			new_Y = Y + 1;
		else if (wrap)
			new_Y = 1;
	}

	return new_Y;
}

/***************************************************************************
  函数名称：move_and_return_new_x
  功    能：移动光标并返回新的X坐标
  输入参数：HANDLE hout - 输出设备句柄
			int X - 当前X坐标
			int Y - 当前Y坐标
			int new_X - 新的X坐标
			int new_Y - 新的Y坐标
  返 回 值：int - 移动后的X坐标
  说    明：移动光标到新位置并返回更新后的X坐标
***************************************************************************/
int move_and_return_new_x(const HANDLE hout, int X, int Y, int new_X, int new_Y)
{
	gotoxy(hout, new_X, new_Y);
	return new_X;
}

/***************************************************************************
  函数名称：move_and_return_new_y
  功    能：移动光标并返回新的Y坐标
  输入参数：HANDLE hout - 输出设备句柄
			int X - 当前X坐标
			int Y - 当前Y坐标
			int new_X - 新的X坐标
			int new_Y - 新的Y坐标
  返 回 值：int - 移动后的Y坐标
  说    明：移动光标到新位置并返回更新后的Y坐标
***************************************************************************/
int move_and_return_new_y(const HANDLE hout, int X, int Y, int new_X, int new_Y)
{
	gotoxy(hout, new_X, new_Y);
	return new_Y;
}

/***************************************************************************
  函数名称：play_game
  功    能：根据选择的模式进行游戏
  输入参数：HANDLE hout - 输出设备句柄
			int mode - 游戏模式（1-4）
  返 回 值：无
  说    明：根据不同模式控制光标移动
***************************************************************************/
void play_game(const HANDLE hout, int mode)
{
	cls(hout);
	init_border(hout);

	// 初始位置为边框中心
	int X = MAX_X / 2;
	int Y = MAX_Y / 2;
	gotoxy(hout, X, Y);

	bool wrap = (mode == 2 || mode == 4); // 模式2和4支持边界回绕
	bool use_arrow = (mode == 3 || mode == 4); // 模式3和4使用箭头键
	bool use_ijkl = (mode == 1 || mode == 2); // 模式1和2使用IJKL键

	int key;
	int new_X, new_Y;

	while (true) {
		key = _getch(); // 读取按键

		// 检查是否为方向键的第一个字节
		if (key == 224) {
			key = _getch(); // 读取方向键的第二个字节

			// 只有在使用箭头键的模式下才处理箭头键
			if (use_arrow) {
				new_X = get_new_x_from_arrow(X, key, wrap);
				new_Y = get_new_y_from_arrow(Y, key, wrap);
				X = move_and_return_new_x(hout, X, Y, new_X, new_Y);
				Y = move_and_return_new_y(hout, X, Y, new_X, new_Y);
			}
		}
		else if (key == 'Q' || key == 'q') {
			break; // 按Q键退出
		}
		else if (use_ijkl && (key == 'I' || key == 'i' || key == 'J' || key == 'j' ||
			key == 'K' || key == 'k' || key == 'L' || key == 'l')) {
			// 在使用IJKL模式下处理IJKL按键
			new_X = get_new_x_from_ijkl(X, key, wrap);
			new_Y = get_new_y_from_ijkl(Y, key, wrap);
			X = move_and_return_new_x(hout, X, Y, new_X, new_Y);
			Y = move_and_return_new_y(hout, X, Y, new_X, new_Y);
		}
		else if (key == 32) { // 空格键的ASCII码是32
			// 在当前光标位置显示空格，实现消除字母的效果
			showch(hout, X, Y, ' ');
			// 重新将光标移动到当前位置，确保光标不会移动
			gotoxy(hout, X, Y);
		}
	}

	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键返回菜单.";

	// 等待用户按下回车键
	int ch;
	while (true) {
		ch = _getch();
		if (ch == 13) // 回车键的ASCII码是13
			break;
		// 其他键无反应
	}
}

/***************************************************************************
  函数名称：main
  功    能：主函数
  输入参数：无
  返 回 值：int - 程序退出码
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	int choice;
	do {
		choice = menu();
		if (choice >= 1 && choice <= 4)
			play_game(hout, choice);
	} while (choice != 0);

	return 0;
}