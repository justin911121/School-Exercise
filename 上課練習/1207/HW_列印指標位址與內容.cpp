#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a=100;
	int *p,*q;
	printf("==================宣告變數時=======================\n");
	printf("&a=%p     a=%d\n",&a,a);
	printf("&p=%p     \n",&p);
	printf("&q=%p     \n",&q);		
	printf("==================設定p=&a後=======================\n");	
	p=&a;
	printf("p=%p     *p=%d\n",p,*p);	 
	printf("==================設定q=p後=======================\n");	
	q=p;	
	printf("q=%p     *q=%d\n",q,*q);	
	printf("==================設定q=p後=======================\n");
	*q=50;	
	printf("p=%p     *p=%d\n",p,*p);	 
	printf("q=%p     *q=%d\n",q,*q);
	printf("a=%d",a);
		
	return 0;
}
