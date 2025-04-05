/* 2452098 计算机 赵崇治 */
#include<iostream>
using namespace std;

int zeller(int year, int month, int day) 
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

int main()
{
	int year, month, day, week;
	bool valid_input = false;
	
	while (!valid_input) {
		cout << "请输入年[1900-2100]、月、日：\n";
		cin >> year >> month >> day;
		
		// 输入验证
		if (year < 1900 || year > 2100) {
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		if (month < 1 || month > 12) {
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		
		// 判断每月的天数，使用条件判断
		int days_in_month = 31; // 默认31天
		
		if (month == 4 || month == 6 || month == 9 || month == 11)
			days_in_month = 30;
		else if (month == 2) {
			// 处理闰年二月
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				days_in_month = 29;
			else
				days_in_month = 28;
		}
		
		if (day < 1 || day > days_in_month) {
			cout << "日不正确，请重新输入" << endl;
			continue;
		}
		
		// 如果所有验证都通过，设置valid_input为true
		valid_input = true;
	}
	
	week = zeller(year, month, day);
	
	// 格式化输出星期，使用if-else结构
	cout << "星期";
	if (week == 0)
		cout << "日";
	else if (week == 1)
		cout << "一";
	else if (week == 2)
		cout << "二";
	else if (week == 3)
		cout << "三";
	else if (week == 4)
		cout << "四";
	else if (week == 5)
		cout << "五";
	else if (week == 6)
		cout << "六";
	cout << endl;

	return 0;
}
