/*
编写一段程序，输入一个整数值，显示该整数个'*'。每显示5个就进行换行。
*/

#include<stdio.h>

int main() {

    int a, b, c;

    printf("请输入一个值:");
    scanf("%d", &a);

    b = a % 5;
    c = a / 5;

    if (c) {
        for (int i = 1; i <= c; i++) {
            printf("*****\n");
        }
    }
    for (int i = 1; i <= b; i++) {
        printf("*");
    }
    printf("\n");
    return 0;
}