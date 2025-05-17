/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	static const char others[] = "!@#$%^&*-_=+,.?";
	static const char nums[] = "0123456789";
	static const char lowers[] = "abcdefghijklmnopqrstuvwxyz";
	static const char uppers[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)\n";
	int len, upper_num, lower_num, num_num, other_num;
	cin >> len >> upper_num >> lower_num >> num_num >> other_num;
	if (cin.fail())
	{
		cout << "输入非法\n";
		return 0;
	}
	else if (len < 12 || len > 16)
	{
		cout << "密码长度[" << len << "]不正确\n";
		return 0;
	}
	else if (upper_num < 2)
	{
		cout << "大写字母个数[" << upper_num << "]不正确\n";
		return 0;
	}
	else if (lower_num < 2)
	{
		cout << "小写字母个数[" << lower_num << "]不正确\n";
		return 0;
	}
	else if (num_num < 2)
	{
		cout << "数字个数[" << num_num << "]不正确\n";
		return 0;
	}
	else if (other_num < 2)
	{
		cout << "其它符号个数[" << other_num << "]不正确\n";
		return 0;
	}
	else if (upper_num + lower_num + num_num + other_num > len)
	{
		cout << "所有字符类型之和[" << upper_num << "+" << lower_num << "+" << num_num << "+" << other_num << "]大于总密码长度[" << len << "]\n";
		return 0;
	}
	else
	{
		srand((unsigned int)time(0));
		cout << len << " " << upper_num << " " << lower_num << " " << num_num << " " << other_num << "\n";
		if (upper_num + lower_num + num_num + other_num < len)
		{
			int gap = len - (upper_num + lower_num + num_num + other_num);
			for (int j = 0; j < gap; j++) {
				int x = rand() % 4;
				if (x == 0)
					upper_num++;
				if (x == 1)
					lower_num++;
				if (x == 2)
					num_num++;
				if (x == 3)
					other_num++;
			}
		}
		for (int i = 0; i < 10; i++)
		{
			int upper = upper_num;
			int lower = lower_num;
			int num = num_num;
			int other = other_num;
			for (int i = 0;;)
			{
				if (i == len)
					break;
				int x = rand() % 4;
				if (x == 0 && upper > 0)
				{
					cout << uppers[rand() % 26];
					upper--;
					i++;
				}
				else if (x == 1 && lower > 0)
				{
					cout << lowers[rand() % 26];
					lower--;
					i++;
				}
				else if (x == 2 && num > 0)
				{
					cout << nums[rand() % 10];
					num--;
					i++;
				}
				else if (x == 3 && other > 0)
				{
					cout << others[rand() % 15];
					other--;
					i++;
				}
			}
			cout << endl;
		}
	}
	return 0;
}