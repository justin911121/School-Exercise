#include <stdio.h> 
int F(int); 

int F(int n){     
	if(n==0 || n==1)  return n+1;     
	return  F(n-1)+F(n/2); 
} 

int main()
{     
	int n;     
	printf("Enter an integer: ");     
	scanf("%d",&n);   
	printf("F(%d) = %d\n",n,F(n));     
	return 0; 
}
