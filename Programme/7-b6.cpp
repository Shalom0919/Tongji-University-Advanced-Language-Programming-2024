/* 2452098 计算机 赵崇治 */
#include <iostream>
#include "7-b6.h" // 包含题目要求的头文件
using namespace std;

// 判断是否为闰年
bool is_leap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取指定年月的天数
int get_days_in_month(int year, int month) {
	if (month < 1 || month > 12) {
		return 0; // 非法月份返回0
	}
	if (month == 2) {
		return is_leap(year) ? 29 : 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11) {
		return 30;
	}
	else {
		return 31;
	}
}

/* 给出 Date 类的所有成员函数的体外实现 */
Date::Date() {
	year = 2000;
	month = 1;
	day = 1;
}

// 带年月日参数的构造函数：包含合法性检查
Date::Date(int y, int m, int d) {
	// 1. 验证年份，非法则设为 2000
	if (y >= 1900 && y <= 2099) {
		year = y;
	}
	else {
		year = 2000;
	}

	// 2. 验证月份，非法则设为 1
	if (m >= 1 && m <= 12) {
		month = m;
	}
	else {
		month = 1;
	}

	// 3. 验证日期（使用已确定的年月），非法则设为 1
	if (d >= 1 && d <= get_days_in_month(year, month)) {
		day = d;
	}
	else {
		day = 1;
	}
}

// 带总天数参数的构造函数
Date::Date(int total_days) {
	// 如果总天数小于1或过大导致年份超出范围，则设为默认日期 2000.1.1
	if (total_days < 1) {
		year = 1900;
		month = 1;
		day = 1;
		return;
	}

	int temp_year = 1900;
	// 逐年减去当年的天数，以确定年份
	while (total_days > (is_leap(temp_year) ? 366 : 365)) {
		total_days -= (is_leap(temp_year) ? 366 : 365);
		temp_year++;
		// 防止计算结果超出合法范围
		if (temp_year >= 2100) {
			year = 2099;
			month = 12;
			day = 31;
			return;
		}
	}
	year = temp_year;

	int temp_month = 1;
	// 逐月减去当月的天数，以确定月份
	while (total_days > get_days_in_month(year, temp_month)) {
		total_days -= get_days_in_month(year, temp_month);
		temp_month++;
	}
	month = temp_month;

	day = total_days; // 剩余的天数即为日期
}

// 设置日期函数：包含合法性检查，0表示不修改
void Date::set(int y, int m, int d) {
	// 按 年->月->日 的顺序处理
	// 1. 设置年份
	if (y != 0) {
		if (y >= 1900 && y <= 2099) {
			year = y;
		}
		else {
			year = 2000; // 非法年份，设为默认值
		}
	}

	// 2. 设置月份
	if (m != 0) {
		if (m >= 1 && m <= 12) {
			month = m;
		}
		else {
			month = 1; // 非法月份，设为默认值
		}
	}

	// 3. 设置日期（基于当前对象的年月进行验证）
	if (d != 0) {
		if (d >= 1 && d <= get_days_in_month(year, month)) {
			day = d;
		}
		else {
			day = 1; // 非法日期，设为默认值
		}
	}
}

// 获取日期
void Date::get(int& y, int& m, int& d) {
	y = year;
	m = month;
	d = day;
}

// 显示日期
void Date::show() {
	cout << year << "." << month << "." << day << ".\n";
}