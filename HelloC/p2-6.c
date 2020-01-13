/*
编写一段程序，读取表示身高的整数，显示出标准体重的实数值。标准体重根据公式(身高-100)X0.9进行计算，所得结果保留一位小数。
*/

#include<stdio.h>

int main(){

	int highth;
	double weight;

	printf("请输入您的身高：");
	scanf("%d",&highth);

	weight = ( (double)highth - 100 ) * 0.9;

	printf("您法人标准体重是%.0f\n",weight);

	return 0;
}
