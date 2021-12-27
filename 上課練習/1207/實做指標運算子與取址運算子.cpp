#include<stdio.h>
#include<stdlib.h>

int main()
{
	float a,b;
	float *ptr;
	printf("a = ");
	scanf("%f",&a);
	ptr=&a;
	printf("*ptr = %f\n",*ptr);
	b=*ptr;
	printf("b = %f\n",b);
}
