/*
编写一段程序，计算出15减去37的结果，并以“15减去37的结果是-22。”的格式进行显示。
*/




#include<stdio.h>

int main(){

	int a = 15;	
	int b = 37;
	int result;

	result = a - b ;

	printf("%d减去%d的结果是%d\n",a,b,result);	

	return 0;
}
