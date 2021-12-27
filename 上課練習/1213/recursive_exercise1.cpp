#include<stdio.h>
#include<stdlib.h>

int SumRecursive(){
	int n,sum;
	printf("Please enter an integer: ");
	scanf("%d",&n);
	if(n==(-99)) return 0;
	
	return n+SumRecursive();
}

int main(){
	printf("Sum=%d",SumRecursive());
	return 0;
}
