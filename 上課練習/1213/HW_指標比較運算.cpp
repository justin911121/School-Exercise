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

	printf("a����}��%p\n",&a);
	printf("p�����e��}��%p\n",p);
	printf("q�����e��}��%p\n",q);	
	printf("r�����e��}��%p\n",r);
	printf("s�����e��}��%p\n",s);		
	printf("%c ���O�����}����");
	
}
