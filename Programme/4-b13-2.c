/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int steps;
/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        steps++;
        printf("%5d:%3d# %c-->%c\n", steps, n, src, dst);
        return;
    }

    hanoi(n - 1, src, dst, tmp);
    steps++;
    printf("%5d:%3d# %c-->%c\n", steps, n, src, dst);
    hanoi(n - 1, tmp, src, dst);
    return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n, ret;
    char from, tmp, to;
    while (1) {
        printf("请输入汉诺塔的层数(1-16)\n");
        ret = scanf("%d", &n);
        if (ret != 1 || n > 16 || n < 1) {
            while (getchar() != '\n')
                ;
            continue;
        }
        else {
            while (getchar() != '\n')
                ;
            break;
        }
    }

    while (1) {
        printf("请输入起始柱(A-C)\n");
        ret = scanf("%c", &from);
        if (ret != 1 || from - 'c' > 0 || from - 'A' < 0 || from - 'a' < 0 && from - 'C' > 0) {
            while (getchar() != '\n')
                ;
            continue;
        }
        else {
            if (from - 'a' >= 0)
                from -= 32;
            while (getchar() != '\n')
                ;
            break;
        }
    }

    while (1) {
        printf("请输入目标柱(A-C)\n");
        ret = scanf("%c", &to);
        if (ret != 1 || to - 'c' > 0 || to - 'A' < 0 || to - 'a' < 0 && to - 'C' > 0) {
            while (getchar() != '\n')
                ;
            continue;
        }
        else {
            if (to - 'a' >= 0)
                to -= 32;
            if (from == to) {
                printf("目标柱(%c)不能与起始柱(%c)相同\n", from, to);
                while (getchar() != '\n')
                    ;
                continue;
            }
            while (getchar() != '\n')
                ;
            break;
        }
    }

    tmp = 'A' + 'B' + 'C' - to - from;

    printf("移动步骤为:\n");
    hanoi(n, from, tmp, to);

    return 0;
}