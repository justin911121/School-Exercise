//½è¼Æ»¼°j 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int PrimeNumber(int n,int m){
	printf("m=%d n=%d => %d\n",m,n,m%n);
	if(m==2||m==3) return 1;
	else if(m%n==0) return 0;
	else if(n==2) return 1;
	return PrimeNumber(n-1,m);
}

int main()
{
	int n;
	printf("Please enter an integer: ");
	scanf("%d",&n);
	//printf("%d\n",PrimeNumber(sqrt(n),n));
	
	if(PrimeNumber(sqrt(n),n)==1)
		printf("%d is a prime number",n);
	else
		printf("%d isn't a prime number",n);
		
} 
