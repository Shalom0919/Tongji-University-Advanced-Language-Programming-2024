/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <cstring>
using namespace std;

bool reverse(char* str) {
	int n = strlen(str);
	if (n <= 2) {
		return true;
	}
	char* st = str;
	char* end = str + n - 2;
	while (*st == *end) {
		st++;
		end--;
	}
	if (st > end) {
		return true;
	}
	return false;
}

int main()
{
	char str[80];
	cout << "请输入一个长度小于80的字符串（回文串）\n";
	fgets(str, 80, stdin);

	if (reverse(str)) {
		cout << "yes\n";
	}
	else {
		cout << "no\n";
	}

	return 0;
}