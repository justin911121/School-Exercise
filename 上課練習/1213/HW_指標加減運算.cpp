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
	printf("a����}��%p\n",&a);
	printf("p�����e��}��%p\n",p);
	printf("q�����e��}��%p\n",q);	
	printf("r�����e��}��%p\n",r);
	printf("s�����e��}��%p\n",s);		
	printf("=============");
	p-=2;
	q-=2;
	r-=2;
	s-=2;
	printf("a����}��%p\n",&a);
	printf("p�����e��}��%p\n",p);
	printf("q�����e��}��%p\n",q);	
	printf("r�����e��}��%p\n",r);
	printf("s�����e��}��%p\n",s);		
}
