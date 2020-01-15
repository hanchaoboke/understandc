/*
编写一段程序，输入两个整数值，如果后者是前者的约数，则显示“B是A的约数”，如果不是，则显示“B不是A的约数”。
*/

#include<stdio.h>

int main() {

    puts("请输入两个整数");
    int a, b;

    printf("整数A:");
    scanf("%d", &a);

    printf("整数B:");
    scanf("%d", &b);

    if (a % b == 0) {
        printf("%d是%d的约数\n", b, a);
    } else {
        printf("%d不是%d的约数\n", b, a);
    }

    return 0;
}

