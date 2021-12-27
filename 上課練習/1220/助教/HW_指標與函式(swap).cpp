#include<stdio.h>
int swap(int*,int*);

int main()
{
	int a=34,b=21;
	printf("交換以前a= %d, b= %d\n",a,b);
	swap(&a,&b);
	printf("交換以後a= %d, b= %d",a,b);
	
	
	return 0;
}

int swap(int *x,int *y){
	int tmp=0;
	tmp=*x;
	*x=*y;
	*y=tmp;
}
