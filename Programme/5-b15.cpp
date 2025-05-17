/* 2452098 计算机 赵崇治 */
#include<iostream>
using namespace std;
int main()
{
	char str[3][128];
	int cnt[5] = { 0 };
	
	cout << "请输入第一行\n";
    cin.getline(str[0], 128, '\n');

	cout << "请输入第二行\n";
	cin.getline(str[1], 128, '\n');

	cout << "请输入第三行\n";
	cin.getline(str[2], 128, '\n');

	for (int row = 0; row < 3; row++) {
		for (int t = 0; t < 128; t++) {
			if (str[row][t] >= 'A' && str[row][t] <= 'Z') {
				cnt[0]++;
			}
			else if (str[row][t] >= 'a' && str[row][t] <= 'z') {
				cnt[1]++;
			}
			else if (str[row][t] >= '0' && str[row][t] <= '9') {
				cnt[2]++;
			}
			else if (str[row][t] == ' ') {
				cnt[3]++;
			}
			else if(str[row][t] == '\0') {
				break;
			}
			else	
				cnt[4]++;
		}
	}
	cout << "大写 : " << cnt[0] << endl;
	cout << "小写 : " << cnt[1] << endl;
	cout << "数字 : " << cnt[2] << endl;
	cout << "空格 : " << cnt[3] << endl;
	cout << "其它 : " << cnt[4] << endl;

	return 0;
}