#include <stdio.h> 
void Uppercase(char[]); 

int main(){     
	char str[80];         
	// Save the entered strin, �x�s��J���r��    
	printf("Enter a string: ");     
	// Complete (1), enter a string and save it to str     
	// ����(1)�A��J�r��A�x�s��str     
	scanf("%s",str);     
	// Complete (2), pass the string str to Uppercase() and convert it to uppercase letters   
	// ����(2)�A�N�r��str�ǵ�Uppercase()�A�ഫ���j�g�r��    
	Uppercase(str);     
	// Complete (3), output the converted string str     
	// ����(3)�A��X�ഫ�᪺�r��str   
	printf("%s",str);     
	return 0; 
} 

void Uppercase(char msg[]){   
	int i;   
	// Complete (4), the loop termination condition is      
	// the end of string symbol     
	// ����(4)�A�j�餤����󬰦r�굲���Ÿ�  
	for(i=0; msg[i]!='\0'; i++){         
	// Complete (5), if msg[i] is a lowercase letter     
	// ����(5)�A�p�Gmsg[i]���p�g�r��    
		if(msg[i]>=97 && msg[i]<=122){       
		// Complete (6), convert msg[i] to uppercase letters             
		// ����(6)�A�Nmsg[i]�ର�j�g�r��            
			msg[i] -= 32;         
		}  
	}
}
