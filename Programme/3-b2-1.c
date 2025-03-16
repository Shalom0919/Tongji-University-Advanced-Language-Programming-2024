/* 2452098 计算机 赵崇治*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
    int num, w, q, b, s, g;
    printf("请输入一个[1..30000]间的整数:\n");
    scanf("%d", &num);

    g = num % 10;
    num /= 10;
    s = num % 10;
    num /= 10;
    b = num % 10;
    num /= 10;
    q = num % 10;
    num /= 10;
    w = num;

    printf("%-3s : %d\n", "万位", w);
    printf("%-3s : %d\n", "千位", q);
    printf("%-3s : %d\n", "百位", b);
    printf("%-3s : %d\n", "十位", s);
    printf("%-3s : %d\n", "个位", g);

    return 0;
}
