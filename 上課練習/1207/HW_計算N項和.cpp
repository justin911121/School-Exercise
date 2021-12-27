#include<stdio.h>
#include<stdlib.h>

#define cal(x)\
	int sum=0;\
	for(int i=1;i<=n;i++){\
		sum+=i*(i+1);\
	}\
	printf("總合為%d",sum);

int main()
{
	int n=0;
	printf("請輸入數字: ");
	scanf("%d",&n);
	cal(n);
}
