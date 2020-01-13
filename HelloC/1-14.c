/*
显示出读取到的两个整数的和
*/


#include<stdio.h>

int main(){
	int n1,n2;
	int wa;

	puts("请输入两个整数。");
	printf("整数1："); scanf("%d",&n1);
	printf("整数2："); scanf("%d",&n2);

	wa = n1 + n2;

	printf("它们的和是%d\n", wa);

	return 0;
}
