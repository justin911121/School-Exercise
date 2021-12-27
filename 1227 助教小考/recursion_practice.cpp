//410411150 ªL«Û¨° 1A 
#include<stdio.h>
#include<stdlib.h>
int fun1(int x){
	if(x==1) return 1;
	else if(x%2==0) return fun1(x/2);
	else return fun1(x-1)+fun1(x+1); 
}

int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",fun1(x));
	
	return 0;
}
