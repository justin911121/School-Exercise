#include<stdio.h>
#include<stdlib.h>

int Binary2Decimal(int n,int power2){
	if(n/10==0) return (n%10)*power2;
	return Binary2Decimal(n/10,power2*2)+(n%10)*power2;
}

int main()
{
	int n;
	printf("Enter an number:");
	scanf("%d",&n);
	printf("%d(binary) = %d(decimal)\n",n,Binary2Decimal(n,1));
} 
