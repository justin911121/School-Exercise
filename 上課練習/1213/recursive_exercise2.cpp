#include<stdio.h>
#include<stdlib.h>

int digitals(int n){
	if(n/10==0) return 1;
	
	return 1+digitals(n/10);
}

int main(){
	int n;
	printf("Please enter an integer: ");
	scanf("%d",&n);
	printf("%d digitals",digitals(n));
	return 0;
}
