/* 2452098 ¼ÆËã»ú ÕÔ³çÖÎ */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
    double oldNum;
    int sy, y, qw, bw, sw, w, q, b, s, g, j, f;
    printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
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

    printf("´óÐ´½á¹ûÊÇ:\n");

    if (sy > 0) {
        if (sy == 1)
            printf("Ò¼");
        else if (sy == 2)
            printf("·¡");
        else if (sy == 3)
            printf("Èþ");
        else if (sy == 4)
            printf("ËÁ");
        else if (sy == 5)
            printf("Îé");
        else if (sy == 6)
            printf("Â½");
        else if (sy == 7)
            printf("Æâ");
        else if (sy == 8)
            printf("°Æ");
        else if (sy == 9)
            printf("¾Á");
        printf("Ê°");
    }

    if (y > 0) {
        if (y == 1)
            printf("Ò¼");
        else if (y == 2)
            printf("·¡");
        else if (y == 3)
            printf("Èþ");
        else if (y == 4)
            printf("ËÁ");
        else if (y == 5)
            printf("Îé");
        else if (y == 6)
            printf("Â½");
        else if (y == 7)
            printf("Æâ");
        else if (y == 8)
            printf("°Æ");
        else if (y == 9)
            printf("¾Á");
        printf("ÒÚ");
        hasYi = 1;
    }
    else if (sy > 0) {
        printf("ÒÚ");
        hasYi = 1;
    }

    if (hasYi) {
        if (!hasWanToYi && hasThousandBelow && q == 0) {
            printf("Áã");
        }
    }

    if (qw > 0) {
        if (qw == 1)
            printf("Ò¼");
        else if (qw == 2)
            printf("·¡");
        else if (qw == 3)
            printf("Èþ");
        else if (qw == 4)
            printf("ËÁ");
        else if (qw == 5)
            printf("Îé");
        else if (qw == 6)
            printf("Â½");
        else if (qw == 7)
            printf("Æâ");
        else if (qw == 8)
            printf("°Æ");
        else if (qw == 9)
            printf("¾Á");
        printf("Çª");
    }
    else if ((sy > 0 || y > 0) && (bw > 0 || sw > 0 || w > 0)) {
        printf("Áã");
    }

    if (bw > 0) {
        if (bw == 1)
            printf("Ò¼");
        else if (bw == 2)
            printf("·¡");
        else if (bw == 3)
            printf("Èþ");
        else if (bw == 4)
            printf("ËÁ");
        else if (bw == 5)
            printf("Îé");
        else if (bw == 6)
            printf("Â½");
        else if (bw == 7)
            printf("Æâ");
        else if (bw == 8)
            printf("°Æ");
        else if (bw == 9)
            printf("¾Á");
        printf("°Û");
    }
    else if (qw > 0 && (sw > 0 || w > 0)) {
        printf("Áã");
    }

    if (sw > 0) {
        if (sw == 1)
            printf("Ò¼");
        else if (sw == 2)
            printf("·¡");
        else if (sw == 3)
            printf("Èþ");
        else if (sw == 4)
            printf("ËÁ");
        else if (sw == 5)
            printf("Îé");
        else if (sw == 6)
            printf("Â½");
        else if (sw == 7)
            printf("Æâ");
        else if (sw == 8)
            printf("°Æ");
        else if (sw == 9)
            printf("¾Á");
        printf("Ê°");
    }
    else if (bw > 0 && w > 0) {
        printf("Áã");
    }

    if (w > 0) {
        if (w == 1)
            printf("Ò¼");
        else if (w == 2)
            printf("·¡");
        else if (w == 3)
            printf("Èþ");
        else if (w == 4)
            printf("ËÁ");
        else if (w == 5)
            printf("Îé");
        else if (w == 6)
            printf("Â½");
        else if (w == 7)
            printf("Æâ");
        else if (w == 8)
            printf("°Æ");
        else if (w == 9)
            printf("¾Á");
        printf("Íò");
        hasWan = 1;
    }
    else if ((qw > 0 || bw > 0 || sw > 0) && !hasWan) {
        printf("Íò");
        hasWan = 1;
    }

    if (hasWan && !hasThousandBelow) {
    }
    else if (hasWan && hasThousandBelow && q == 0) {
        printf("Áã");
    }

    if (q > 0) {
        if (q == 1)
            printf("Ò¼");
        else if (q == 2)
            printf("·¡");
        else if (q == 3)
            printf("Èþ");
        else if (q == 4)
            printf("ËÁ");
        else if (q == 5)
            printf("Îé");
        else if (q == 6)
            printf("Â½");
        else if (q == 7)
            printf("Æâ");
        else if (q == 8)
            printf("°Æ");
        else if (q == 9)
            printf("¾Á");
        printf("Çª");
    }

    if (b > 0) {
        if (b == 1)
            printf("Ò¼");
        else if (b == 2)
            printf("·¡");
        else if (b == 3)
            printf("Èþ");
        else if (b == 4)
            printf("ËÁ");
        else if (b == 5)
            printf("Îé");
        else if (b == 6)
            printf("Â½");
        else if (b == 7)
            printf("Æâ");
        else if (b == 8)
            printf("°Æ");
        else if (b == 9)
            printf("¾Á");
        printf("°Û");
    }
    else if (q > 0 && (s > 0 || g > 0)) {
        printf("Áã");
    }

    if (s > 0) {
        if (s == 1)
            printf("Ò¼");
        else if (s == 2)
            printf("·¡");
        else if (s == 3)
            printf("Èþ");
        else if (s == 4)
            printf("ËÁ");
        else if (s == 5)
            printf("Îé");
        else if (s == 6)
            printf("Â½");
        else if (s == 7)
            printf("Æâ");
        else if (s == 8)
            printf("°Æ");
        else if (s == 9)
            printf("¾Á");
        printf("Ê°");
    }
    else if (b > 0 && g > 0) {
        printf("Áã");
    }

    if (g > 0) {
        if (g == 1)
            printf("Ò¼");
        else if (g == 2)
            printf("·¡");
        else if (g == 3)
            printf("Èþ");
        else if (g == 4)
            printf("ËÁ");
        else if (g == 5)
            printf("Îé");
        else if (g == 6)
            printf("Â½");
        else if (g == 7)
            printf("Æâ");
        else if (g == 8)
            printf("°Æ");
        else if (g == 9)
            printf("¾Á");
    }

    if (sy > 0 || y > 0 || qw > 0 || bw > 0 || sw > 0 || w > 0 || q > 0 || b > 0 || s > 0 || g > 0) {
        printf("Ô²");
    }

    if (sy == 0 && y == 0 && qw == 0 && bw == 0 && sw == 0 && w == 0 && q == 0 && b == 0 && s == 0 && g == 0) {
        if (j == 0 && f == 0) {
            printf("ÁãÔ²Õû");
        }
        else if (j > 0 && f == 0) {
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("½ÇÕû");
        }
        else if (j > 0 && f > 0) {
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("½Ç");

            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("·Ö");
        }
        else if (j == 0 && f > 0) {
            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("·Ö");
        }
    }
    else {
        if (j == 0 && f == 0) {
            printf("Õû");
        }
        else if (j > 0) {
            if (j == 1)
                printf("Ò¼");
            else if (j == 2)
                printf("·¡");
            else if (j == 3)
                printf("Èþ");
            else if (j == 4)
                printf("ËÁ");
            else if (j == 5)
                printf("Îé");
            else if (j == 6)
                printf("Â½");
            else if (j == 7)
                printf("Æâ");
            else if (j == 8)
                printf("°Æ");
            else if (j == 9)
                printf("¾Á");
            printf("½Ç");
            if (f == 0)
                printf("Õû");
            if (f > 0) {
                if (f == 1)
                    printf("Ò¼");
                else if (f == 2)
                    printf("·¡");
                else if (f == 3)
                    printf("Èþ");
                else if (f == 4)
                    printf("ËÁ");
                else if (f == 5)
                    printf("Îé");
                else if (f == 6)
                    printf("Â½");
                else if (f == 7)
                    printf("Æâ");
                else if (f == 8)
                    printf("°Æ");
                else if (f == 9)
                    printf("¾Á");
                printf("·Ö");
            }
        }
        else if (j == 0 && f > 0) {
            printf("Áã");
            if (f == 1)
                printf("Ò¼");
            else if (f == 2)
                printf("·¡");
            else if (f == 3)
                printf("Èþ");
            else if (f == 4)
                printf("ËÁ");
            else if (f == 5)
                printf("Îé");
            else if (f == 6)
                printf("Â½");
            else if (f == 7)
                printf("Æâ");
            else if (f == 8)
                printf("°Æ");
            else if (f == 9)
                printf("¾Á");
            printf("·Ö");
        }
    }

    printf("\n");

    return 0;
}