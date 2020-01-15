/*
编写一段程序，根据输入的整数，循环显示1234567890，显示的位数和输入的整数值相同。
*/

#include<stdio.h>

int main() {

    int Num[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int n;

    printf("请输入一个正整数:");
    scanf("%d", &n);

    int a , b = 0;

    a = n % 10;
    b = n / 10;

    if (b) {
        for (int i = 0; i < b; i++) {
            for (int i = 0; i < 10; i++) {

                printf("%d", Num[i]);

            }
        }
    }

    for (int i = 0; i < a; i++) {
        printf("%d", Num[i]);
    }

    printf("\n");

    return 0;
}