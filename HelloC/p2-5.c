/*
编写一段程序，读取两个整数的值，计算出前者是后者的百分之几，并用实数输出结果。
*/


#include<stdio.h>

int main(){

	int a;
	int b;
	double result;
	
	printf("请输入两个整数:");
	scanf("%d%d",&a,&b);
	
	result = ( (double)a / (double)b ) * 100 ;

	printf("结果为：%.0f%%\n",result);

	return 0;
}
