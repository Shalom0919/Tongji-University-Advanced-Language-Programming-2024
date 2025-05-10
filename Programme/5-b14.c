/* 2452098 计算机 赵崇治 */
/* */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    char board[11][27] = { 0 };
    char line[100] = { 0 };
    int i, j;
    int star_count = 0;
    int error_found = 0;

    /* 读取输入数据 */
    for (i = 1; i <= 10; i++) {
        if (fgets(line, 100, stdin) == NULL) { //当一个字符都没有读到时，fgets函数返回NULL
            break;
        }

        /* 过滤掉每个符号/数字间的空格 */
        int pos = 0;
        for (j = 1; j <= 26; j++) {
            /* 跳过空格 */
            while (line[pos] == ' ')
                pos++;

            board[i][j] = line[pos];
            pos++;
        }
    }

    /* 检查星号的个数是否为50个 */
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 26; j++) {
            if (board[i][j] == '*')
                star_count++;
        }
    }

    if (star_count != 50) {
        printf("错误1\n");
        return 0;
    }

    /* 在*个数正确的前提下，重新计算周围的雷数，再和读入的内容进行比较 */
    for (i = 1; i <= 10; i++) {
        for (j = 1; j <= 26; j++) {
            if (board[i][j] != '*') {
                int count = 0;
                int k, l;

                /* 计算周围的雷数 */
                for (k = -1; k <= 1; k++) {
                    for (l = -1; l <= 1; l++) {
                        if (i + k >= 1 && i + k <= 10 && j + l >= 1 && j + l <= 26) {
                            if (board[i + k][j + l] == '*')
                                count++;
                        }
                    }
                }

                /* 检查计算的雷数是否与读入的数字一致 */
                if (board[i][j] - '0' != count) {
                    error_found = 1;
                    break;
                }
            }
        }
        if (error_found)
            break;
    }

    /* 输出检查结果 */
    if (error_found) {
        printf("错误2\n");
    }
    else {
        printf("正确\n");
    }

    return 0;
}