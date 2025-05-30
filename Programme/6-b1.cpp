/* 2452098 计算机 赵崇治 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	//bool is_num;
	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串\n";
	p = str;
	pnum = a;
	pa = a;

	while ((*p = cin.get()) != '\n') {
		if (pnum - a == 10)
			break;
		if ((*p < '0' || *p>'9')) {
			if (*(p - 1) < '0' || *(p - 1) > '9') {
				;
			}
			else {
				pnum++;
				pa++;
			}
		}
		else {
			*pa = 10 * *pa + *p - '0';
		}
		p++;
	}
	if (*(p - 1) >= '0' && *(p - 1) <= '9') {
		pa++;
		pnum++;
	}
	pa = a;
	cout << "共有"<<(pnum-a)<<"个整数\n";
	while (pa < pnum) {
		cout << *pa++ << " ";
	}
	cout << endl;

	return 0;
}