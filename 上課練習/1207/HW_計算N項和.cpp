#include<stdio.h>
#include<stdlib.h>

#define cal(x)\
	int sum=0;\
	for(int i=1;i<=n;i++){\
		sum+=i*(i+1);\
	}\
	printf("�`�X��%d",sum);

int main()
{
	int n=0;
	printf("�п�J�Ʀr: ");
	scanf("%d",&n);
	cal(n);
}
