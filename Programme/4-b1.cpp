/* 2452098 计算机 赵崇治 */
#include <iostream>
#include <cmath>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
	case 0:
		if (flag_of_zero)	//此标记什么意思请自行思考
			cout << "零";
		break;
	case 1:
		cout << "壹";
		break;
	case 2:
		cout << "贰";
		break;
	case 3:
		cout << "叁";
		break;
	case 4:
		cout << "肆";
		break;
	case 5:
		cout << "伍";
		break;
	case 6:
		cout << "陆";
		break;
	case 7:
		cout << "柒";
		break;
	case 8:
		cout << "捌";
		break;
	case 9:
		cout << "玖";
		break;
	default:
		cout << "error";
		break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double oldNum;
	int sy, y, qw, bw, sw, w, q, b, s, g, j, f;
	cout << "请输入[0-100亿)之间的数字:\n";
	cin >> oldNum;
	
	double num = (floor(oldNum));
	double partialNum = round((oldNum - num) * 100);
	
	sy = int(num / 1e9);
	num -= sy * 1e9;
	y = int(num / 1e8);
	num -= y * 1e8;
	qw = int(num / 1e7);
	num -= qw * 1e7;
	bw = int(num / 1e6);
	num -= bw * 1e6;
	sw = int(num / 1e5);
	num -= sw * 1e5;
	w = int(num / 1e4);
	num -= w * 1e4;
	q = int(num / 1e3);
	num -= q * 1e3;
	b = int(num / 100);
	num -= b * 100;
	s = int(num / 10);
	num -= s * 10;
	g = int(num);
	j = int(partialNum / 10);
	f = int(partialNum - j * 10);
	
	cout << "大写结果是:" << endl;
	
	bool hasYi = false;
	bool hasWan = false;
	bool hasThousandBelow = (b > 0 || s > 0 || g > 0);
	bool hasWanToYi = (qw > 0 || bw > 0 || sw > 0 || w > 0);
	
	// 处理十亿位和亿位
	if (sy > 0) {
		daxie(sy, 1);
		cout << "拾";
		hasYi = true;
	}
	if (y > 0) {
		daxie(y, 1);
		cout << "亿";
		hasYi = true;
	} else if (sy > 0) {
		cout << "亿";
		hasYi = true;
	}
	
	// 处理千万到万位
	if (qw > 0) {
		daxie(qw, 1);
		cout << "仟";
		hasWan = true;
	} else if (hasYi && (bw > 0 || sw > 0 || w > 0)) {
		daxie(0, 1);
		hasWan = true;
	}
	
	if (bw > 0) {
		daxie(bw, 1);
		cout << "佰";
		hasWan = true;
	} else if ((qw > 0) && (sw > 0 || w > 0)) {
		daxie(0, 1);
		hasWan = true;
	}
	
	if (sw > 0) {
		daxie(sw, 1);
		cout << "拾";
		hasWan = true;
	} else if ((qw > 0 || bw > 0) && w > 0) {
		daxie(0, 1);
		hasWan = true;
	}
	
	if (w > 0) {
		daxie(w, 1);
		cout << "万";
		hasWan = true;
	} else if (hasWanToYi) {
		cout << "万";
		hasWan = true;
	}
	
	// 处理千到个位
	if (q > 0) {
		daxie(q, 1);
		cout << "仟";
	} else if ((hasYi || hasWan) && (b > 0 || s > 0 || g > 0)) {
		daxie(0, 1);
	}
	
	if (b > 0) {
		daxie(b, 1);
		cout << "佰";
	} else if (q > 0 && (s > 0 || g > 0)) {
		daxie(0, 1);
	}
	
	if (s > 0) {
		daxie(s, 1);
		cout << "拾";
	} else if ((q > 0 || b > 0) && g > 0) {
		daxie(0, 1);
	}
	
	if (g > 0) {
		daxie(g, 1);
	}
	
	// 处理整数部分的"圆"
	if (sy > 0 || y > 0 || qw > 0 || bw > 0 || sw > 0 || w > 0 || q > 0 || b > 0 || s > 0 || g > 0) {
		cout << "圆";
	} else {
		daxie(0, 1);
		cout << "圆";
	}
	
	// 处理小数部分
	if (j > 0) {
		daxie(j, 1);
		cout << "角";
	}
	
	if (f > 0) {
		daxie(f, 1);
		cout << "分";
	} else {
		cout << "整";
	}
	cout << endl;

	return 0;
}
