/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
    double oldNum;
    int sy, y, qw, bw, sw, w, q, b, s, g, j, f;
    printf("请输入[0-100亿)之间的数字:\n");
    scanf("%lf", &oldNum);

    double num = (floor(oldNum));
    double partialNum = round((oldNum - num) * 100);

    sy = (int)(num / 1e9);
    num -= sy * 1e9;
    y = (int)(num / 1e8);
    num -= y * 1e8;
    qw = (int)(num / 1e7);
    num -= qw * 1e7;
    bw = (int)(num / 1e6);
    num -= bw * 1e6;
    sw = (int)(num / 1e5);
    num -= sw * 1e5;
    w = (int)(num / 1e4);
    num -= w * 1e4;
    q = (int)(num / 1e3);
    num -= q * 1e3;
    b = (int)(num / 100);
    num -= b * 100;
    s = (int)(num / 10);
    num -= s * 10;
    g = (int)(num);
    j = (int)(partialNum / 10);
    f = (int)(partialNum - j * 10);

    printf("%-6s : %d\n", "十亿位", sy);
    printf("%-6s : %d\n", "亿位", y);
    printf("%-6s : %d\n", "千万位", qw);
    printf("%-6s : %d\n", "百万位", bw);
    printf("%-6s : %d\n", "十万位", sw);
    printf("%-6s : %d\n", "万位", w);
    printf("%-6s : %d\n", "千位", q);
    printf("%-6s : %d\n", "百位", b);
    printf("%-6s : %d\n", "十位", s);
    printf("%-6s : %d\n", "圆", g);
    printf("%-6s : %d\n", "角", j);
    printf("%-6s : %d\n", "分", f);

    return 0;
}