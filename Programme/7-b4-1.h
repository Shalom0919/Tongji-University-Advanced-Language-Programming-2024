/* 2452098 计算机 赵崇治 */
#pragma once
#include<iostream>
#include<cmath>

using namespace std;
/* 允许加入需要的头文件、命令空间 */

/* point类的定义及实现，已给出部分内容，按要求补充完成 */
class point {
private:
	int x;
	int y;
	//除上面的两个private数据成员外，不再允许添加任何类型的数据成员
public:
	int getx() const //函数声明后加const，表示不允许在本函数中修改数据成员的值 
	{
		return x;
	}
	int gety() const //函数声明后加const，表示不允许在本函数中修改数据成员的值
	{
		return y;
	}
	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */
	void set(int px, int py)
	{
		x = px;
		y = py;
	}
};

/* triangle类的定义及实现，已给出部分内容，按要求补充完成 */
class triangle {
private:
	point p1;
	point p2;
	point p3;
	//除上面的三个private数据成员外，不再允许添加任何类型的数据成员
public:
	/* 根据需要补充相应的语句后完成area函数(形参为空，不准改)，要求：如果三点能构成三角形，则返回面积，否则返回 -1 */
	double area()
	{
		const double a = calc(p1, p2);
		const double b = calc(p1, p3);
		const double c = calc(p2, p3);
		if ((a + b - c) < 1e-5) // 浮点数，养成好习惯
			return -1;
		if ((a + c - b) < 1e-5)
			return -1;
		if ((b + c - a) < 1e-5)
			return -1;

		double p = calc_p(p1, p2, p3); // 海伦公式
		return sqrt(p*(p-a)*(p-b)*(p-c));
	}

	/* 构造函数（已实现，不准动） */
	triangle(int p1_x, int p1_y, int p2_x, int p2_y, int p3_x, int p3_y)
	{
		/* 给p1/p2/p3三个点分别赋x,y坐标值 */
		p1.set(p1_x, p1_y);
		p2.set(p2_x, p2_y);
		p3.set(p3_x, p3_y);
	}

	/* 可以定义需要的成员函数，数量不限，并以体内方式实现，不允许添加数据成员 */
	double get_length(int x1, int y1, int x2, int y2)
	{
		return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	}

	double calc(point p1, point p2)
	{
		return get_length(p1.getx(), p1.gety(), p2.getx(), p2.gety());
	}

	double calc_p(point p1, point p2, point p3)
	{
		return (calc(p1, p2) + calc(p1, p3) + calc(p2, p3)) / 2;
	}
};