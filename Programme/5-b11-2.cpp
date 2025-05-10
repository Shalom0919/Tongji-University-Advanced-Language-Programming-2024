/* 2452098 计算机 赵崇治 */
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

void daxie(int num)
{
    result += string(chnstr + num * 2, chnstr + num * 2 + 2);
}

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

    if (sy > 0) {
        daxie(sy);
        result+= "拾";
    }

    if (y > 0) {
        daxie(y);
        result+= "亿";
        hasYi = true;
    }
    else if (sy > 0) {
        result+= "亿";
        hasYi = true;
    }

    if (hasYi) {
        if (!hasWanToYi && hasThousandBelow && q == 0) {
            daxie(0);
        }
    }

    if (qw > 0) {
        daxie(qw);
        result+= "仟";
    }
    else if ((sy > 0 || y > 0) && (bw > 0 || sw > 0 || w > 0)) {
        daxie(0);
    }

    if (bw > 0) {
        daxie(bw);
        result+= "佰";
    }
    else if (qw > 0 && (sw > 0 || w > 0)) {
        daxie(0);
    }

    if (sw > 0) {
        daxie(sw);
        result+= "拾";
    }
    else if (bw > 0 && w > 0) {
        daxie(0);
    }

    if (w > 0) {
        daxie(w);
        result+= "万";
        hasWan = true;
    }
    else if ((qw > 0 || bw > 0 || sw > 0) && !hasWan) {
        result+= "万";
        hasWan = true;
    }

    if (hasWan && !hasThousandBelow) {
    }
    else if (hasWan && hasThousandBelow && q == 0) {
        daxie(0);
    }

    if (q > 0) {
        daxie(q);
        result+= "仟";
    }

    if (b > 0) {
        daxie(b);
        result+= "佰";
    }
    else if (q > 0 && (s > 0 || g > 0)) {
        daxie(0);
    }

    if (s > 0) {
        daxie(s);
        result+= "拾";
    }
    else if (b > 0 && g > 0) {
        daxie(0);
    }

    if (g > 0) {
        daxie(g);
    }

    if (sy > 0 || y > 0 || qw > 0 || bw > 0 || sw > 0 || w > 0 || q > 0 || b > 0 || s > 0 || g > 0) {
        result+= "圆";
    }

    if (sy == 0 && y == 0 && qw == 0 && bw == 0 && sw == 0 && w == 0 && q == 0 && b == 0 && s == 0 && g == 0) {
        if (j == 0 && f == 0) {
            daxie(0);
            result+= "圆整";
        }
        else if (j > 0 && f == 0) {
            daxie(j);
            result+= "角整";
        }
        else if (j > 0 && f > 0) {
            daxie(j);
            result+= "角";

            daxie(f);
            result+= "分";
        }
        else if (j == 0 && f > 0) {
            daxie(f);
            result+= "分";
        }
    }
    else {
        if (j == 0 && f == 0) {
            result+= "整";
        }
        else if (j > 0) {
            daxie(j);
            result+= "角";
            if (f == 0)
                result+= "整";
            if (f > 0) {
                daxie(f);
                result+= "分";
            }
        }
        else if (j == 0 && f > 0) {
            daxie(0);
            daxie(f);
            result+= "分";
        }
    }
	cout << result << endl;

    return 0;
}