/* 2452098 计算机 赵崇治 */
#include<iostream>
using namespace std;

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

    cout << "请输入找零值：\n";
    cin >> money;

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


    cout << "共" << zhang << "张找零，具体如下：\n";
    if (wsyuan)
        cout << "50元 : " << wsyuan << "张\n";
    if (esyuan)
        cout << "20元 : " << esyuan << "张\n";
    if (syuan)
        cout << "10元 : " << syuan << "张\n";
    if (wyuan)
        cout << "5元  : " << wyuan << "张\n";
    if (yyuan)
        cout << "1元  : " << yyuan << "张\n";
    if (wjiao)
        cout << "5角  : " << wjiao << "张\n";
    if (yjiao)
        cout << "1角  : " << yjiao << "张\n";
    if (wfen)
        cout << "5分  : " << wfen << "张\n";
    if (lfen)
        cout << "2分  : " << lfen << "张\n";
    if (yfen)
        cout << "1分  : " << yfen << "张\n";

    return 0;
}
