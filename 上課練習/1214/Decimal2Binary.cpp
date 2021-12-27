#include <stdio.h>

// 13(decimal) = 1101
// 13/2 = 6...1   
// 6/2 = 3...0
// 3/2 = 1...1
// 1/2 = 0...1, if(商==0) terminated
// 1101 --> 1*10^3 + 1*10^2 + 0*10^1 + 1*10^0
// ---------------------------------------------------------
// 13/2 = 6...1 -->  (1*10^3 + 1*10^2 + 0*10^1) + 1*10^0 --> recursion + 自己餘數＊１０的次方
// 6/2 = 3...0 --> (1*10^3 + 1*10^2) + 0*10^1
// 3/2 = 1...1 --> (1*10^3) + 1*10^2
// 1/2 = 0...1 --> 1*10^3
// ---------------------------------------------------------
// 13/2 = 10^0 = 1
// 6/2 = 10^1 = 10
// 3/2 = 10^2 = 100
// 1/2 = 10^3 = 1000
int Decimal2Binary(int, int);
int Decimal2Binary(int n, int power10){
	if((n/2)==0) return (n%2)*power10;
	return Decimal2Binary(n/2,power10*10)+(n%2)*power10;
} 

int Binary2Decimal(???); 

int main(){
	int n;
	printf("Enter a decimal :");
	scanf("%d",&n);
	printf("%d(decimal) = %d(binary)\n",n,Decimal2Binary(n,1));
	
	return 0;
}
