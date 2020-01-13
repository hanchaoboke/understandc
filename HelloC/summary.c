/*
   求长方形的面积
*/


#include<stdio.h>

int main(){
	int width;
	int height;

	puts("求长方形面积。");

	printf("长：");
	scanf("%d",&width);

	printf("宽：");
	scanf("%d",&height);

	printf("面积是 %d 。\a\n",width * height);

	return 0;
}
