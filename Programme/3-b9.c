/* 2452098 ¼ÆËã»ú ÕÔ³çÖÎ */
#include <stdio.h>

int main()
{
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            int prod = i * j;
            printf("%dx%d=%-3d ", j, i, prod);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}