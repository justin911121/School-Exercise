#include <stdio.h>
int SumOfEven(int n){	
	//printf("n=%d\nsum=%d\n\n",n,sum);
	if(n/10==0) return (n%10)*((n%10)%2==0);
	return (n%10)*((n%10)%2==0)+SumOfEven(n/10);
	//printf("n=%d\nsum=%d\n\n",n,sum);	
}
	
int main(){
     int n;     
	 printf("Enter an integer: ");     
	 scanf("%d",&n);     
	 printf("The sum of even digits of %d = %d\n",n,SumOfEven(n));     
	 return 0; 
}

