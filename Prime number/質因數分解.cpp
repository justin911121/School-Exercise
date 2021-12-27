//410411150 ªL«Û¨° 1A 
#include<stdio.h>
#include<stdlib.h>

void fun(int x,int test){
	if(x==0||x==1) return;
	if(x%test==0){
		printf("%d",test);
		x/=test;
		if(x!=0&&x!=1){
			printf("*");
		}
		fun(x,test);
	}
	else fun(x,test+1);
}


int main()
{
	int x;
	scanf("%d",&x);
	fun(x,2);
	
	return 0;
}
