/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isLeapYear(int year){
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    }
    return 0;
}

int calday(int year, int month, int day) {
    int days = 0;
    int dayPerMonth[13] = { 0, 31,28,31,30, 31,30,31,31, 30,31,30,31 };
    if (isLeapYear(year)) {
        dayPerMonth[2] = 29;
    }
    for (int i = 1; i < month; i++) {
        days += dayPerMonth[i];
    }

    return days + day;
}

int main()
{
    int year, month, day;
    int days = 0;

    printf("请输入年，月，日\n");
    scanf("%d %d %d", &year, &month, &day);

    int isMonthValid = 1;
    int isDayValid = 1;

    if (month < 1 || month > 12) {
        isMonthValid = 0;
    }

    if (isMonthValid) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day < 1 || day > 31) {
                isDayValid = 0;
            }
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day < 1 || day > 30) {
                isDayValid = 0;
            }
        }
        else if (month == 2) {
            if (isLeapYear(year)) {
                if (day < 1 || day > 29) {
                    isDayValid = 0;
                }
            }
            else {
                if (day < 1 || day > 28) {
                    isDayValid = 0;
                }
            }
        }
    }

    if (!isMonthValid) {
        printf("输入错误-月份不正确\n");
    }
    else if (!isDayValid) {
        printf("输入错误-日与月的关系非法\n");
    }
    else {
        days = calday(year, month, day);
        printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
    }

    return 0;
}