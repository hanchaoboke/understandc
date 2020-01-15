/*
编写一段程序，读取两个整数的值，然后计算出它们之间所有整数的和。
*/

#include<stdio.h>

int main() {

    int a, b, sum = 0;

    printf("请输入第一个整数:");
    scanf("%d", &a);

    printf("请输入第二个整数:");
    scanf("%d", &b);

    //如果a>b则调换
    if (a > b) {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

    for (int i = a + 1; i < b; i++) {
        sum = sum + i;

    }

    printf("两者之间所有整数的和是:%d\n", sum);

    return 0;
}

