#include<stdio.h>
#include<stdlib.h>

#define f(n)\
	int sum=1;\
	for(int j=n;j>0;j--){\
		sum*=j;\
	}\
	printf("%d階為%d",n,sum);
	
int main()
{
	int n=0,i;
	printf("請輸入一數字: ");
	scanf("%d",&n);
	f(n);
	
	return 0;
}
