#include<stdio.h>
int swap(int*,int*);

int main()
{
	int a=34,b=21;
	printf("�洫�H�ea= %d, b= %d\n",a,b);
	swap(&a,&b);
	printf("�洫�H��a= %d, b= %d",a,b);
	
	
	return 0;
}

int swap(int *x,int *y){
	int tmp=0;
	tmp=*x;
	*x=*y;
	*y=tmp;
}
