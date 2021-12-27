#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a;
	int *q;
	short *p;
	double *r;
	float *s;
	
	p=(short*)&a;
	q=&a;
	r=(double*)&a;
	s=(float*)&a;
	printf("a的位址為%p\n",&a);
	printf("p的內容位址為%p\n",p);
	printf("q的內容位址為%p\n",q);	
	printf("r的內容位址為%p\n",r);
	printf("s的內容位址為%p\n",s);		
	printf("=============");
	p-=2;
	q-=2;
	r-=2;
	s-=2;
	printf("a的位址為%p\n",&a);
	printf("p的內容位址為%p\n",p);
	printf("q的內容位址為%p\n",q);	
	printf("r的內容位址為%p\n",r);
	printf("s的內容位址為%p\n",s);		
}
