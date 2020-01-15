#include<stdio.h>

int main() {

    int n = 1289;
    while (n > 0) {
        printf("%d\n", n % 10);
        printf("n   %d\n",n);
        n = n / 10;
        printf("n2      %d\n",n );
    }

    return 0;
}