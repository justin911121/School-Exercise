#include <stdio.h> 

int main(){    
 // F is Fahrenheit, C is Centigrade
	int F;
	int C;     
	printf("Enter Fahrenheit temperature: ");     
	scanf("%d", &F);     
	C = (float)(F-32)*5/9+0.5;     
	printf("Centigrade temperature = %d",C);     
	return 0 ;
}
