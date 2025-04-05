/* 2452098 计算机 赵崇治 */
#include<iostream>
#include<iomanip>
using namespace std;

int zeller(int year, int month, int day) //4-b2复用
{
	if (month == 1 || month == 2) {
		month += 12;
		year--;
	}
	int century = year / 100;
	year = year % 100;
	int week = (day + 26 * (month + 1) / 10 + year + year / 4 + century / 4 + 5 * century) % 7;
	return (week + 7 - 1) % 7;
}

void calendar(int year, int month) //3-b13复用
{
	/* 按需添加代码 */
	int xq = zeller(year, month, 1);
	int days = 0, week = 0;
	bool isLeapYear = false;

	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		isLeapYear = true;
	}

	if (month == 1) {
		days = 31;
	}
	else if (month == 2) {
		if (isLeapYear) {
			days = 29;
		}
		else {
			days = 28;
		}
	}
	else if (month == 3) {
		days = 31;
	}
	else if (month == 4) {
		days = 30;
	}
	else if (month == 5) {
		days = 31;
	}
	else if (month == 6) {
		days = 30;
	}
	else if (month == 7) {
		days = 31;
	}
	else if (month == 8) {
		days = 31;
	}
	else if (month == 9) {
		days = 30;
	}
	else if (month == 10) {
		days = 31;
	}
	else if (month == 11) {
		days = 30;
	}
	else if (month == 12) {
		days = 31;
	}

	if (days - 28 - xq + 7 > 0) {
		week = 6;
	}
	else
		week = 5;
	cout << endl;
	cout << year << "年" << month << "月" << endl;

	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */
	for (int i = 0; i < xq; i++) { //3-b13复用
		cout << "        ";
	}

	int day = 1, j;
	for (int i = 1; i <= week; i++) {
		for (j = xq; j <= 6; j++) {
			cout << setw(4) << day << "    ";
			day++;
			xq = 0;
			if (day > days)
				break;
		}
		cout << endl;
		if (day > days) {
			break;
		}
	}

	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}

int main()
{
	int year, month, week = 0;
	int days = 0;
	int xq = 0;

	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;
		if (cin.good() == 0) {
			cin.clear();
			cin.ignore(65536, '\n'); 
			cout << "输入错误，请重新输入" << endl;
		}
		else {
			if (year < 1900 || year>2100) {
				cout << "年份不正确，请重新输入" << endl;
			}
			else {
				if (month > 12 || month < 1) {
					cout << "月份不正确，请重新输入" << endl;
				}
				else {
					break;
				}

			}
		}
	}
	calendar(year, month); //工作函数

	return 0;
}
