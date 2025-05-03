/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main()
{
	int year, month, week = 0;
	int days = 0;
	int xq;

	bool valid = false;

	while (!valid) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		if (cin >> year >> month) {
			if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12) {
				valid = true;
			}
			else {
				int nextYear, nextMonth;
				cout << "输入非法，请重新输入\n";
				cout << "请输入年份(2000-2030)和月份(1-12) : ";
				while (cin >> nextYear >> nextMonth) {
					if (nextYear >= 2000 && nextYear <= 2030 && nextMonth >= 1 && nextMonth <= 12) {
						year = nextYear;
						month = nextMonth;
						valid = true;
						break;
					}
					cout << "输入非法，请重新输入\n";
					cout << "请输入年份(2000-2030)和月份(1-12) : ";
				}
				if (!valid) {
					cin.clear(); 
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "输入非法，请重新输入\n";
				}
			}
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入\n";
		}
	}

	valid = false;

	while (!valid) {
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
		if (cin >> xq) {
			if (xq >= 0 && xq <= 6) {
				valid = true;
			}
			else {
				int nextxq;
				cout << "输入非法，请重新输入\n";
				cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
				while (cin >> nextxq) {
					if (nextxq >= 0 && nextxq <= 6) {
						xq = nextxq;
						valid = true;
						break;
					}
					cout << "输入非法，请重新输入\n";
					cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : ";
				}
				if (!valid) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "输入非法，请重新输入\n";
				}
			}
		}
		else {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入非法，请重新输入\n";
		}
	}

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
	cout << year << "年" << month << "月的月历为:\n";
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六\n";
	for (int i = 0; i < xq; i++) {
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
			if (j == 6) {
				cout << endl;
			}
			break;
		}
	}

	return 0;
}
