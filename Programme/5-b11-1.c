/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

void daxie(int num)
{
	char temp[3] = { 0 };
	temp[0] = chnstr[num * 2];
	temp[1] = chnstr[num * 2 + 1];
	strcat(result, temp);
}

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

	int hasThousandBelow, hasWanToYi;
	int hasYi = 0;
	int hasWan = 0;
	hasThousandBelow = (b > 0 || s > 0 || g > 0);
	hasWanToYi = (qw > 0 || bw > 0 || sw > 0 || w > 0);

	// 初始化result为空字符串
	result[0] = '\0';

	printf("大写结果是:\n");

	if (sy > 0) {
		daxie(sy);
		strcat(result, "拾");
	}

	if (y > 0) {
		daxie(y);
		strcat(result, "亿");
		hasYi = 1;
	}
	else if (sy > 0) {
		strcat(result, "亿");
		hasYi = 1;
	}

	if (hasYi) {
		if (!hasWanToYi && hasThousandBelow && q == 0) {
			daxie(0);
		}
	}

	if (qw > 0) {
		daxie(qw);
		strcat(result, "仟");
	}
	else if ((sy > 0 || y > 0) && (bw > 0 || sw > 0 || w > 0)) {
		daxie(0);
	}

	if (bw > 0) {
		daxie(bw);
		strcat(result, "佰");
	}
	else if (qw > 0 && (sw > 0 || w > 0)) {
		daxie(0);
	}

	if (sw > 0) {
		daxie(sw);
		strcat(result, "拾");
	}
	else if (bw > 0 && w > 0) {
		daxie(0);
	}

	if (w > 0) {
		daxie(w);
		strcat(result, "万");
		hasWan = 1;
	}
	else if ((qw > 0 || bw > 0 || sw > 0) && !hasWan) {
		strcat(result, "万");
		hasWan = 1;
	}

	if (hasWan && !hasThousandBelow) {
	}
	else if (hasWan && hasThousandBelow && q == 0) {
		daxie(0);
	}

	if (q > 0) {
		daxie(q);
		strcat(result, "仟");
	}

	if (b > 0) {
		daxie(b);
		strcat(result, "佰");
	}
	else if (q > 0 && (s > 0 || g > 0)) {
		daxie(0);
	}

	if (s > 0) {
		daxie(s);
		strcat(result, "拾");
	}
	else if (b > 0 && g > 0) {
		daxie(0);
	}

	if (g > 0) {
		daxie(g);
	}

	if (sy > 0 || y > 0 || qw > 0 || bw > 0 || sw > 0 || w > 0 || q > 0 || b > 0 || s > 0 || g > 0) {
		strcat(result, "圆");
	}

	if (sy == 0 && y == 0 && qw == 0 && bw == 0 && sw == 0 && w == 0 && q == 0 && b == 0 && s == 0 && g == 0) {
		if (j == 0 && f == 0) {
			daxie(0);
			strcat(result, "圆整");
		}
		else if (j > 0 && f == 0) {
			daxie(j);
			strcat(result, "角整");
		}
		else if (j > 0 && f > 0) {
			daxie(j);
			strcat(result, "角");

			daxie(f);
			strcat(result, "分");
		}
		else if (j == 0 && f > 0) {
			daxie(f);
			strcat(result, "分");
		}
	}
	else {
		if (j == 0 && f == 0) {
			strcat(result, "整");
		}
		else if (j > 0) {
			daxie(j);
			strcat(result, "角");
			if (f == 0)
				strcat(result, "整");
			if (f > 0) {
				daxie(f);
				strcat(result, "分");
			}
		}
		else if (j == 0 && f > 0) {
			daxie(0);
			daxie(f);
			strcat(result, "分");
		}
	}

	printf("%s\n", result);
	return 0;
}