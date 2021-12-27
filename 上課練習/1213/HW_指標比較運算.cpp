#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a;
	double *q;
	double *p;
	double *r;
	double *s;
	
	p=(double*)&a;
	q=(double*)&a;
	r=(double*)&a;
	s=(double*)&a;

	printf("a的位址為%p\n",&a);
	printf("p的內容位址為%p\n",p);
	printf("q的內容位址為%p\n",q);	
	printf("r的內容位址為%p\n",r);
	printf("s的內容位址為%p\n",s);		
	printf("%c 的記憶體位址較高");
	
}
