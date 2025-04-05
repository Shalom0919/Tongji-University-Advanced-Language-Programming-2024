/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：打印字母
	 输入参数：
	 返 回 值：
	 说    明：用于行内打印
   ***************************************************************************/
void showch1(int len) 
{
	if (len == 1) {
		return;
	}
	cout << char('A' + len / 2);
	return showch1(len - 2);
}

void showch2(int l, int len) 
{
	cout << char('A' + l / 2);
	if (l > len-2) {
		return;
	}
	return showch2(l + 2, len);

}

   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/
void print_tower(int globalLen, int len, int mode)
{
	/* 允许按需定义最多一个静态局部变量（也可以不定义） */
	if (mode == 1) {
		if (len == 1) {
			cout << setfill(' ') << setw(1 + (globalLen - len) / 2) << 'A' << endl;
			return;
		}
		else {
			print_tower(globalLen, len - 2, mode);
			cout << setfill(' ') << setw(1 + (globalLen - len) / 2);
			showch1(len);
			showch2(0, len);
			cout << endl;
			return;
		}
	}
	else{
		if (len == 1) {
			cout << setfill(' ') << setw(1 + (globalLen - len) / 2) << 'A' << endl;
			return;
		}
		else {
			cout << setfill(' ') << setw(1 + (globalLen - len) / 2);
			showch1(len);
			showch2(0, len);
			cout << endl;
			print_tower(globalLen, len - 2, mode);
			return;
		}
	}
	/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw(int(2 * (end_ch - 'A') + 1)) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw(int(2 * (end_ch - 'A') + 1)) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(int(2 * (end_ch - 'A') + 1), int(2 * (end_ch - 'A') + 1), 1); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setfill('=') << setw(int(2 * (end_ch - 'A') + 1)) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw(int(2 * (end_ch - 'A') + 1)) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(int(2 * (end_ch - 'A') + 1), int(2 * (end_ch - 'A') + 1), 2); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setfill('=') << setw(int(2 * (end_ch - 'A') + 1)) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setfill('=') << setw(int(2 * (end_ch - 'A') + 1)) << '=' << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(int(2 * (end_ch - 'A') + 1), int(2 * (end_ch - 'A') + 1), 1);   //打印 A~结束字符的正三角 
	print_tower(int(2 * (end_ch - 'A') + 1), int(2 * (end_ch - 'A') - 1), 2);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}
