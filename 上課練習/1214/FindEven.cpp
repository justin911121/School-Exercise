#include<stdio.h>
#include<stdlib.h>

int findEven(int n){
	if(n/10==0) return (n%2)==0;	
	return findEven(n/10)+((n%2)==0);
}

int main()
{
	int n;
	printf("Enter a num:");
	scanf("%d",&n);
	printf("%d -> %d",n,findEven(n));
}
