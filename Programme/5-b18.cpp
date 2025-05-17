/* 2452098 计算机 赵崇治 */
#include <iostream>
using namespace std;

int main()
{
	cin.ignore(65536, '\n');
	int len, upper_num, lower_num, num_num, other_num;
	cin >> len >> upper_num >> lower_num >> num_num >> other_num;
	if (cin.fail()) {
		cout << "错误\n";
		return 0;
	}
	cin.ignore(65536, '\n');
	static const char others[] = "!@#$%^&*-_=+,.?";
	int flag = 1;
	for (int i = 0; i < 10; i++)
	{
		int upper = 0;
		int lower = 0;
		int num = 0;
		int other = 0;
		char x[17] = { "" };
		cin.getline(x, 17, '\n');
		for (int j = 0; j < 17; j++) {
			if (x[j] == '\0')
				break;
			if (x[j] >= 'A' && x[j] <= 'Z')
				upper++;
			else if (x[j] >= 'a' && x[j] <= 'z')
				lower++;
			else if (x[j] >= '0' && x[j] <= '9')
				num++;
			else {
				bool is_other = false;
				for (int k = 0; others[k] != '\0'; k++) {
					if (x[j] == others[k]) {
						is_other = true;
						break;
					}
				}
				if (is_other) {
					other++;
				}
				else {
					flag = 0;
					break;
				}
			}
				
		}
		if (upper < upper_num || lower < lower_num || num < num_num || other < other_num) {
			flag = 0;
			break;
		}
	}
	if (flag == 0)
		cout << "错误\n";
	else
		cout << "正确\n";
	return 0;
}