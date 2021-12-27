#include<stdio.h>
#include<stdlib.h>

#define mul(x,y) \
	for(int i=x;i<=y;i++){\
		for(int j=x;j<=y;j++){\
			printf("%d*%d=%d  ",i,j,i*j);\
		}\
		printf("\n");\
	} 

int main()
{
	int a,b,c=0;
	printf("請輸入兩個數字: ");
	scanf("%d %d",&a,&b);
	if(a>b){
		c=a;
		a=b;
		b=c;
	}
	mul(a,b);
	
	return 0;
}
