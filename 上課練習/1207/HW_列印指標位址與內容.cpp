#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=100;
	int *p,*q;
	printf("==================�ŧi�ܼƮ�=======================\n");
	printf("&a=%p     a=%d\n",&a,a);
	printf("&p=%p     \n",&p);
	printf("&q=%p     \n",&q);		
	printf("==================�]�wp=&a��=======================\n");	
	p=&a;
	printf("p=%p     *p=%d\n",p,*p);	 
	printf("==================�]�wq=p��=======================\n");	
	q=p;	
	printf("q=%p     *q=%d\n",q,*q);	
	printf("==================�]�wq=p��=======================\n");
	*q=50;	
	printf("p=%p     *p=%d\n",p,*p);	 
	printf("q=%p     *q=%d\n",q,*q);
	printf("a=%d",a);
		
	return 0;
}
