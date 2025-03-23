/* 2452098 ¼ÆËã»ú ÕÔ³çÖÎ */
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double oldNum;
    int sy, y, qw, bw, sw, w, q, b, s, g, j, f;
    cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:\n";
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

    cout << "´óĞ´½á¹ûÊÇ:" << endl;

    bool hasYi = false;
    bool hasWan = false;
    bool hasThousandBelow = (b > 0 || s > 0 || g > 0);
    bool hasWanToYi = (qw > 0 || bw > 0 || sw > 0 || w > 0);

    if (sy > 0) {
        if (sy == 1)
            cout << "Ò¼";
        else if (sy == 2)
            cout << "·¡";
        else if (sy == 3)
            cout << "Èş";
        else if (sy == 4)
            cout << "ËÁ";
        else if (sy == 5)
            cout << "Îé";
        else if (sy == 6)
            cout << "Â½";
        else if (sy == 7)
            cout << "Æâ";
        else if (sy == 8)
            cout << "°Æ";
        else if (sy == 9)
            cout << "¾Á";
        cout << "Ê°";
    }

    if (y > 0) {
        if (y == 1)
            cout << "Ò¼";
        else if (y == 2)
            cout << "·¡";
        else if (y == 3)
            cout << "Èş";
        else if (y == 4)
            cout << "ËÁ";
        else if (y == 5)
            cout << "Îé";
        else if (y == 6)
            cout << "Â½";
        else if (y == 7)
            cout << "Æâ";
        else if (y == 8)
            cout << "°Æ";
        else if (y == 9)
            cout << "¾Á";
        cout << "ÒÚ";
        hasYi = true;
    }
    else if (sy > 0) {
        cout << "ÒÚ";
        hasYi = true;
    }

    if (hasYi) {
        if (!hasWanToYi && hasThousandBelow && q == 0) {
            cout << "Áã";
        }
    }

    if (qw > 0) {
        if (qw == 1)
            cout << "Ò¼";
        else if (qw == 2)
            cout << "·¡";
        else if (qw == 3)
            cout << "Èş";
        else if (qw == 4)
            cout << "ËÁ";
        else if (qw == 5)
            cout << "Îé";
        else if (qw == 6)
            cout << "Â½";
        else if (qw == 7)
            cout << "Æâ";
        else if (qw == 8)
            cout << "°Æ";
        else if (qw == 9)
            cout << "¾Á";
        cout << "Çª";
    }
    else if ((sy > 0 || y > 0) && (bw > 0 || sw > 0 || w > 0)) {
        cout << "Áã";
    }

    if (bw > 0) {
        if (bw == 1)
            cout << "Ò¼";
        else if (bw == 2)
            cout << "·¡";
        else if (bw == 3)
            cout << "Èş";
        else if (bw == 4)
            cout << "ËÁ";
        else if (bw == 5)
            cout << "Îé";
        else if (bw == 6)
            cout << "Â½";
        else if (bw == 7)
            cout << "Æâ";
        else if (bw == 8)
            cout << "°Æ";
        else if (bw == 9)
            cout << "¾Á";
        cout << "°Û";
    }
    else if (qw > 0 && (sw > 0 || w > 0)) {
        cout << "Áã";
    }

    if (sw > 0) {
        if (sw == 1)
            cout << "Ò¼";
        else if (sw == 2)
            cout << "·¡";
        else if (sw == 3)
            cout << "Èş";
        else if (sw == 4)
            cout << "ËÁ";
        else if (sw == 5)
            cout << "Îé";
        else if (sw == 6)
            cout << "Â½";
        else if (sw == 7)
            cout << "Æâ";
        else if (sw == 8)
            cout << "°Æ";
        else if (sw == 9)
            cout << "¾Á";
        cout << "Ê°";
    }
    else if (bw > 0 && w > 0) {
        cout << "Áã";
    }

    if (w > 0) {
        if (w == 1)
            cout << "Ò¼";
        else if (w == 2)
            cout << "·¡";
        else if (w == 3)
            cout << "Èş";
        else if (w == 4)
            cout << "ËÁ";
        else if (w == 5)
            cout << "Îé";
        else if (w == 6)
            cout << "Â½";
        else if (w == 7)
            cout << "Æâ";
        else if (w == 8)
            cout << "°Æ";
        else if (w == 9)
            cout << "¾Á";
        cout << "Íò";
        hasWan = true;
    }
    else if ((qw > 0 || bw > 0 || sw > 0) && !hasWan) {
        cout << "Íò";
        hasWan = true;
    }

    if (hasWan && !hasThousandBelow) {
    }
    else if (hasWan && hasThousandBelow && q == 0) {
        cout << "Áã";
    }

    if (q > 0) {
        if (q == 1)
            cout << "Ò¼";
        else if (q == 2)
            cout << "·¡";
        else if (q == 3)
            cout << "Èş";
        else if (q == 4)
            cout << "ËÁ";
        else if (q == 5)
            cout << "Îé";
        else if (q == 6)
            cout << "Â½";
        else if (q == 7)
            cout << "Æâ";
        else if (q == 8)
            cout << "°Æ";
        else if (q == 9)
            cout << "¾Á";
        cout << "Çª";
    }

    if (b > 0) {
        if (b == 1)
            cout << "Ò¼";
        else if (b == 2)
            cout << "·¡";
        else if (b == 3)
            cout << "Èş";
        else if (b == 4)
            cout << "ËÁ";
        else if (b == 5)
            cout << "Îé";
        else if (b == 6)
            cout << "Â½";
        else if (b == 7)
            cout << "Æâ";
        else if (b == 8)
            cout << "°Æ";
        else if (b == 9)
            cout << "¾Á";
        cout << "°Û";
    }
    else if (q > 0 && (s > 0 || g > 0)) {
        cout << "Áã";
    }

    if (s > 0) {
        if (s == 1)
            cout << "Ò¼";
        else if (s == 2)
            cout << "·¡";
        else if (s == 3)
            cout << "Èş";
        else if (s == 4)
            cout << "ËÁ";
        else if (s == 5)
            cout << "Îé";
        else if (s == 6)
            cout << "Â½";
        else if (s == 7)
            cout << "Æâ";
        else if (s == 8)
            cout << "°Æ";
        else if (s == 9)
            cout << "¾Á";
        cout << "Ê°";
    }
    else if (b > 0 && g > 0) {
        cout << "Áã";
    }

    if (g > 0) {
        if (g == 1)
            cout << "Ò¼";
        else if (g == 2)
            cout << "·¡";
        else if (g == 3)
            cout << "Èş";
        else if (g == 4)
            cout << "ËÁ";
        else if (g == 5)
            cout << "Îé";
        else if (g == 6)
            cout << "Â½";
        else if (g == 7)
            cout << "Æâ";
        else if (g == 8)
            cout << "°Æ";
        else if (g == 9)
            cout << "¾Á";
    }

    if (sy > 0 || y > 0 || qw > 0 || bw > 0 || sw > 0 || w > 0 || q > 0 || b > 0 || s > 0 || g > 0) {
        cout << "Ô²";
    }

    if (sy == 0 && y == 0 && qw == 0 && bw == 0 && sw == 0 && w == 0 && q == 0 && b == 0 && s == 0 && g == 0) {
        if (j == 0 && f == 0) {
            cout << "ÁãÔ²Õû";
        }
        else if (j > 0 && f == 0) {
            if (j == 1)
                cout << "Ò¼";
            else if (j == 2)
                cout << "·¡";
            else if (j == 3)
                cout << "Èş";
            else if (j == 4)
                cout << "ËÁ";
            else if (j == 5)
                cout << "Îé";
            else if (j == 6)
                cout << "Â½";
            else if (j == 7)
                cout << "Æâ";
            else if (j == 8)
                cout << "°Æ";
            else if (j == 9)
                cout << "¾Á";
            cout << "½ÇÕû";
        }
        else if (j > 0 && f > 0) {
            if (j == 1)
                cout << "Ò¼";
            else if (j == 2)
                cout << "·¡";
            else if (j == 3)
                cout << "Èş";
            else if (j == 4)
                cout << "ËÁ";
            else if (j == 5)
                cout << "Îé";
            else if (j == 6)
                cout << "Â½";
            else if (j == 7)
                cout << "Æâ";
            else if (j == 8)
                cout << "°Æ";
            else if (j == 9)
                cout << "¾Á";
            cout << "½Ç";

            if (f == 1)
                cout << "Ò¼";
            else if (f == 2)
                cout << "·¡";
            else if (f == 3)
                cout << "Èş";
            else if (f == 4)
                cout << "ËÁ";
            else if (f == 5)
                cout << "Îé";
            else if (f == 6)
                cout << "Â½";
            else if (f == 7)
                cout << "Æâ";
            else if (f == 8)
                cout << "°Æ";
            else if (f == 9)
                cout << "¾Á";
            cout << "·Ö";
        }
        else if (j == 0 && f > 0) {
            if (f == 1)
                cout << "Ò¼";
            else if (f == 2)
                cout << "·¡";
            else if (f == 3)
                cout << "Èş";
            else if (f == 4)
                cout << "ËÁ";
            else if (f == 5)
                cout << "Îé";
            else if (f == 6)
                cout << "Â½";
            else if (f == 7)
                cout << "Æâ";
            else if (f == 8)
                cout << "°Æ";
            else if (f == 9)
                cout << "¾Á";
            cout << "·Ö";
        }
    }
    else {
        if (j == 0 && f == 0) {
            cout << "Õû";
        }
        else if (j > 0) {
            if (j == 1)
                cout << "Ò¼";
            else if (j == 2)
                cout << "·¡";
            else if (j == 3)
                cout << "Èş";
            else if (j == 4)
                cout << "ËÁ";
            else if (j == 5)
                cout << "Îé";
            else if (j == 6)
                cout << "Â½";
            else if (j == 7)
                cout << "Æâ";
            else if (j == 8)
                cout << "°Æ";
            else if (j == 9)
                cout << "¾Á";
            cout << "½Ç";
            if (f == 0)
                cout << "Õû";
            if (f > 0) {
                if (f == 1)
                    cout << "Ò¼";
                else if (f == 2)
                    cout << "·¡";
                else if (f == 3)
                    cout << "Èş";
                else if (f == 4)
                    cout << "ËÁ";
                else if (f == 5)
                    cout << "Îé";
                else if (f == 6)
                    cout << "Â½";
                else if (f == 7)
                    cout << "Æâ";
                else if (f == 8)
                    cout << "°Æ";
                else if (f == 9)
                    cout << "¾Á";
                cout << "·Ö";
            }
        }
        else if (j == 0 && f > 0) {
            cout << "Áã";
            if (f == 1)
                cout << "Ò¼";
            else if (f == 2)
                cout << "·¡";
            else if (f == 3)
                cout << "Èş";
            else if (f == 4)
                cout << "ËÁ";
            else if (f == 5)
                cout << "Îé";
            else if (f == 6)
                cout << "Â½";
            else if (f == 7)
                cout << "Æâ";
            else if (f == 8)
                cout << "°Æ";
            else if (f == 9)
                cout << "¾Á";
            cout << "·Ö";
        }
    }

    cout << endl;

    return 0;
}