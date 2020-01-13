/*
对读取的整数值进行符号取反操作，并输出结果
*/


#include<stdio.h>

int main(){

	int num;

	printf("请输入一个数：");
	scanf("%d",&num);

	printf("符号取反之后的值是%d。\n", -num);

	return 0;
}
