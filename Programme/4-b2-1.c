/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

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
	int valid_input = 0; 

	while (!valid_input) {
		printf("请输入年[1900-2100]、月、日：\n");
		scanf("%d %d %d", &year, &month, &day);

		if (year < 1900 || year > 2100) {
			printf("年份不正确，请重新输入\n");
			continue;
		}
		if (month < 1 || month > 12) {
			printf("月份不正确，请重新输入\n");
			continue;
		}

		int days_in_month = 31; 

		if (month == 4 || month == 6 || month == 9 || month == 11)
			days_in_month = 30;
		else if (month == 2) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
				days_in_month = 29;
			else
				days_in_month = 28;
		}

		if (day < 1 || day > days_in_month) {
			printf("日不正确，请重新输入\n");
			continue;
		}
		valid_input = 1;
	}

	week = zeller(year, month, day);

	printf("星期");
	if (week == 0)
		printf("日");
	else if (week == 1)
		printf("一");
	else if (week == 2)
		printf("二");
	else if (week == 3)
		printf("三");
	else if (week == 4)
		printf("四");
	else if (week == 5)
		printf("五");
	else if (week == 6)
		printf("六");
	printf("\n");

	return 0;
}
