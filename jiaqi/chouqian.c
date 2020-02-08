/*
抽签程序
接收用户输入，输入任意内容，抽一张签（大吉、中吉、小吉、吉、末吉、凶、大凶），输入0退出

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


// 给定范围 计算随机数
int randomNum(int a, int b) {
    if (a > b) {
        int temp = 0;
        temp = a;
        a = b;
        b = temp;
    }
    int x = 0;
    srand(time(NULL));
    x = a + rand() % (b - a + 1);
    return x;
}
// 随机数
int xrand = 0;



int main() {
    while (1) {
        char a[100] ;
        char b[] = "0";
        xrand = randomNum(0, 1000);
        printf("请输入任意内容,按0退出:");		scanf("%s", a);
        //printf("      %d",strcmp);
        if (strcmp(a,b) == 0){
            exit(0);
        }
        if (xrand > 0 && xrand <= 50)
            printf("您抽中了大吉\n");
        if (xrand > 50 && xrand <= 150)
            printf("您抽中了中吉\n");
        if (xrand > 150 && xrand <= 300)
            printf("您抽中了小吉\n");
        if (xrand > 300 && xrand <= 600)
            printf("您抽中了吉\n");
        if (xrand > 600 && xrand <= 800)
            printf("您抽中了末吉\n");
        if (xrand > 800 && xrand <= 950)
            printf("您抽中了凶\n");
        if (xrand > 950 && xrand <= 1000)
            printf("您抽中了大凶\n");

    }

    return 0;
}