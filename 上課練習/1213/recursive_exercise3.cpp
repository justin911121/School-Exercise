#include<stdio.h>
#include<stdlib.h>

int PowerRecursive(int n){
	if(n==0) return 1;
	return 2*PowerRecursive(n-1);
}

int main()
{
	int n;
	printf("Please enter an integer: ");
	scanf("%d",&n);
	printf("2^%d = %d",n,PowerRecursive(n));
}
