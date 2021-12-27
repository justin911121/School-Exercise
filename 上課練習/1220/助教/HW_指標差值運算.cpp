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
	printf("亂數1:%d\n",a);
	printf("亂數2:%d\n",b);
	printf("亂數3:%d\n",c);
	printf("亂數4:%d\n",d);		
	printf("產生出來的陣列元素1 x[%d][%d]\n",a,b);	
	printf("產生出來的陣列元素2 x[%d][%d]\n",c,d);		
	int x1[a][b],x2[c][d];
	printf("ptr1=%d\n",&x1[a][b]);
	printf("ptr2=%d\n",&x2[c][d]);	
	printf("x[%d][%d] ~ x[%d][%d]的元素個數: %d\n",a,b,c,d,abs(&x1[a][b]-&x2[c][d]));
	printf("x[%d][%d] ~ x[%d][%d]的記憶體區塊大小:  %d\n",a,b,c,d,4*abs(&x1[a][b]-&x2[c][d]));	
	
}
