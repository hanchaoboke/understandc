/*
编写一段程序，输入一个整数值，显示出它的绝对值。
*/

#include<stdio.h>

int main(){

	int a = 0;

	printf("请输入一个整数值:" );
	scanf("%d",&a);

	if(a >= 0){
		printf("它的绝对值是%d\n",a);
	}else{
		printf("它的绝对值是%d\n", -a);
	}

	return 0;
}