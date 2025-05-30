/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	unsigned int n = 0;
	char str[34] = "";
	char* p = str;
	cout << "请输入一个0/1组成的字符串，长度不超过32\n";
	//cin.getline(str, '\n');
	fgets(str, 34, stdin);
	int len = strlen(str);
	int k = 0;
	while (*p != '\0') {
		k++;
		unsigned int tmp = 1;
		if (*p == '1') {
			for (int i = 1; i < len - k; i++) {
				tmp *= (unsigned int)2;
			}
			n = n + tmp;
		}
		p++;
	}
	cout << n << endl;
	return 0;	
}