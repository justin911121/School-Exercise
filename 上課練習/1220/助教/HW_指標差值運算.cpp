#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<math.h>


int main()
{	
	int a,b,c,d;
	srand(time(NULL));
	a=rand()%5;
	b=rand()%8;
	c=rand()%5;
	d=rand()%8;
	printf("�ü�1:%d\n",a);
	printf("�ü�2:%d\n",b);
	printf("�ü�3:%d\n",c);
	printf("�ü�4:%d\n",d);		
	printf("���ͥX�Ӫ��}�C����1 x[%d][%d]\n",a,b);	
	printf("���ͥX�Ӫ��}�C����2 x[%d][%d]\n",c,d);		
	int x1[a][b],x2[c][d];
	printf("ptr1=%d\n",&x1[a][b]);
	printf("ptr2=%d\n",&x2[c][d]);	
	printf("x[%d][%d] ~ x[%d][%d]�������Ӽ�: %d\n",a,b,c,d,abs(&x1[a][b]-&x2[c][d]));
	printf("x[%d][%d] ~ x[%d][%d]���O����϶��j�p:  %d\n",a,b,c,d,4*abs(&x1[a][b]-&x2[c][d]));	
	
}
