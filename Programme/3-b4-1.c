/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdio.h>

int main()
{
	int a, b, angle;
	float s;
	const double pi = 3.14159;
	printf("请输入三角形的两边及其夹角(角度)\n");
	scanf("%d %d %d", &a, &b, &angle);

	s = (float)(1.0f / 2 * a * b * sin(angle * pi / 180.0));

	printf("三角形面积为 : %-.3f\n", s);
	return 0;
}