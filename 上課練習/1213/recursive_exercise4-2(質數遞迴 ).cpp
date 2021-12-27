//½è¼Æ»¼°j 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int PrimeNumber(int n,int m){
	//printf("m=%d n=%d => %d\n",m,n,m%n);
	if(m==2||m==3) return 1;
	else if(m%n==0) return 0;
	else if(n==2) return 1;
	return PrimeNumber(n-1,m);
}

int PrimePrint(int t,int n){
	//printf("\nt=%d\n",t);
	if(t==n) return 0;
	else if(PrimeNumber(sqrt(t),t)==1)
		printf("%d ",t);
	return PrimePrint(t+1,n);
}

int main()
{
	int n;
	printf("Please enter an integer: ");
	scanf("%d",&n);
	printf("prime numbers 2-%d : ",n);
	PrimePrint(2,n);
	return 0;		
} 
