/* 2452098 计算机 赵崇治 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    float money;
    int wsyuan = 0;
    int esyuan = 0;
    int syuan = 0;
    int wyuan = 0;
    int yyuan = 0;
    int wjiao = 0;
    int yjiao = 0;
    int wfen = 0;
    int lfen = 0;
    int yfen = 0;
    int zhang = 0;

    printf("请输入找零值：\n");
    scanf("%f", &money);

    if (money >= 50) {
        money -= 50;
        zhang++;
        wsyuan++;
    }
    if (money >= 20) {
        money -= 20;
        zhang++;
        esyuan++;
    }
    if (money >= 20) {
        money -= 20;
        zhang++;
        esyuan++;
    }
    if (money >= 10) {
        money -= 10;
        zhang++;
        syuan++;
    }
    if (money >= 5) {
        money -= 5;
        zhang++;
        wyuan++;
    }
    if (money >= 1) {
        money -= 1;
        zhang++;
        yyuan++;
    }
    if (money >= 1) {
        money -= 1;
        zhang++;
        yyuan++;
    }
    if (money >= 1) {
        money -= 1;
        zhang++;
        yyuan++;
    }
    if (money >= 1) {
        money -= 1;
        zhang++;
        yyuan++;
    }
    if (0.5f - money <= 1e-5) {
        money -= 0.5f;
        zhang++;
        wjiao++;
    }
    if (0.1f - money <= 1e-5) {
        money -= 0.1f;
        zhang++;
        yjiao++;
    }
    if (0.1f - money <= 1e-5) {
        money -= 0.1f;
        zhang++;
        yjiao++;
    }
    if (0.1f - money <= 1e-5) {
        money -= 0.1f;
        zhang++;
        yjiao++;
    }
    if (0.1f - money <= 1e-5) {
        money -= 0.1f;
        zhang++;
        yjiao++;
    }
    if (0.05f - money <= 1e-5) {
        money -= 0.05f;
        zhang++;
        wfen++;
    }
    if (0.02f - money <= 1e-5) {
        money -= 0.02f;
        zhang++;
        lfen++;
    }
    if (0.02f - money <= 1e-5) {
        money -= 0.02f;
        zhang++;
        lfen++;
    }
    if (0.01f - money <= 1e-5) {
        money -= 0.01f;
        zhang++;
        yfen++;
    }

    printf("共%d张找零，具体如下：\n", zhang);
    if (wsyuan)
        printf("50元 : %d张\n", wsyuan);
    if (esyuan)
        printf("20元 : %d张\n", esyuan);
    if (syuan)
        printf("10元 : %d张\n", syuan);
    if (wyuan)
        printf("5元  : %d张\n", wyuan);
    if (yyuan)
        printf("1元  : %d张\n", yyuan);
    if (wjiao)
        printf("5角  : %d张\n", wjiao);
    if (yjiao)
        printf("1角  : %d张\n", yjiao);
    if (wfen)
        printf("5分  : %d张\n", wfen);
    if (lfen)
        printf("2分  : %d张\n", lfen);
    if (yfen)
        printf("1分  : %d张\n", yfen);

    return 0;
}