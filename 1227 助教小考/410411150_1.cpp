//410411150 ªL«Û¨° 1A 
#include<stdio.h>
#include<stdlib.h>
int fun1(int* x,int* y){
	if(*x>*y){
		*x=*x**x;
		*y*=2;
	}
	else if(*x<*y){
		*x*=2;
		*y=*y**y;
	}
}

int main()
{
	int x,y;
	scanf("%d %d",&x,&y);
	fun1(&x,&y);
	printf("%d %d",x,y);
	
	return 0;
}
