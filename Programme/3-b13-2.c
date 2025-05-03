/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int year, month, week = 0;
    int days = 0;
    int xq;
    bool valid = false;

    while (!valid) {
        printf("请输入年份(2000-2030)和月份(1-12) : ");
        if (scanf("%d %d", &year, &month) == 2) {
            if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12) {
                valid = true;
            }
            else {
                int nextYear, nextMonth;
                printf("输入非法，请重新输入\n");
                printf("请输入年份(2000-2030)和月份(1-12) : ");
                while (scanf("%d %d", &nextYear, &nextMonth) == 2) {
                    if (nextYear >= 2000 && nextYear <= 2030 && nextMonth >= 1 && nextMonth <= 12) {
                        year = nextYear;
                        month = nextMonth;
                        valid = true;
                        break;
                    }
                    printf("输入非法，请重新输入\n");
                    printf("请输入年份(2000-2030)和月份(1-12) : ");
                }
                if (!valid) {
                    while (getchar() != '\n'); 
                    printf("输入非法，请重新输入\n");
                }
            }
        }
        else {
            while (getchar() != '\n'); 
            printf("输入非法，请重新输入\n");
        }
    }

    valid = false;
    while (!valid) {
        printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
        if (scanf("%d", &xq) == 1) {
            if (xq >= 0 && xq <= 6) {
                valid = true;
            }
            else {
                int nextxq;
                printf("输入非法，请重新输入\n");
                printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
                while (scanf("%d", &nextxq) == 1) {
                    if (nextxq >= 0 && nextxq <= 6) {
                        xq = nextxq;
                        valid = true;
                        break;
                    }
                    printf("输入非法，请重新输入\n");
                    printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
                }
                if (!valid) {
                    while (getchar() != '\n'); 
                    printf("输入非法，请重新输入\n");
                }
            }
        }
        else {
            while (getchar() != '\n');  
            printf("输入非法，请重新输入\n");
        }
    }

    int isLeapYear = 0; 

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        isLeapYear = 1;
    }

    switch (month) {
        case 1: 
        case 3: 
        case 5: 
        case 7: 
        case 8: 
        case 10: 
        case 12:
            days = 31;
            break;
        case 4: 
        case 6: 
        case 9: 
        case 11:
            days = 30;
            break;
        case 2:
            days = isLeapYear ? 29 : 28;
            break;
    }

    if (days - 28 - xq + 7 > 0) {
        week = 6;
    }
    else {
        week = 5;
    }

    printf("\n%d年%d月的月历为:\n", year, month);
    printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");

    int i, j;
    for (i = 0; i < xq; i++) {
        printf("        ");
    }

    int day = 1;
    for (i = 1; i <= week; i++) {
        for (j = xq; j <= 6; j++) {
            printf("%4d    ", day);
            day++;
            xq = 0;
            if (day > days)
                break;
        }
        printf("\n");
        if (day > days) {
            if (j == 6) {
                printf("\n");
            }
            break;
        }
    }

    return 0;
}