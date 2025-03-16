/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    double r, h, c, sCircle, sSphere, vSphere;
	double vColumn;
    const double pi = 3.14159;
    printf("请输入半径和高度\n");
    scanf("%lf %lf", &r, &h);

    c = 2 * pi * r;
    sCircle = pi * r * r;
    sSphere = 4 * pi * r * r;
    vSphere = pi * r * r * r * 4 / 3;
    vColumn = pi * r * r * h;

    printf("%-10s : %.2f\n", "圆周长", c);
    printf("%-10s : %.2f\n", "圆面积", sCircle);
    printf("%-10s : %.2f\n", "圆球表面积", sSphere);
    printf("%-10s : %.2f\n", "圆球体积", vSphere);
    printf("%-10s : %.2f\n", "圆柱体积", vColumn);

    return 0;
}
