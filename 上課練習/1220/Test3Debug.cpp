#include <stdio.h> 
void Uppercase(char[]); 

int main(){     
	char str[80];         
	// Save the entered strin, 儲存輸入的字串    
	printf("Enter a string: ");     
	// Complete (1), enter a string and save it to str     
	// 完成(1)，輸入字串，儲存到str     
	scanf("%s",str);     
	// Complete (2), pass the string str to Uppercase() and convert it to uppercase letters   
	// 完成(2)，將字串str傳給Uppercase()，轉換為大寫字母    
	Uppercase(str);     
	// Complete (3), output the converted string str     
	// 完成(3)，輸出轉換後的字串str   
	printf("%s",str);     
	return 0; 
} 

void Uppercase(char msg[]){   
	int i;   
	// Complete (4), the loop termination condition is      
	// the end of string symbol     
	// 完成(4)，迴圈中止條件為字串結束符號  
	for(i=0; msg[i]!='\0'; i++){         
	// Complete (5), if msg[i] is a lowercase letter     
	// 完成(5)，如果msg[i]為小寫字母    
		if(msg[i]>=97 && msg[i]<=122){       
		// Complete (6), convert msg[i] to uppercase letters             
		// 完成(6)，將msg[i]轉為大寫字母            
			msg[i] -= 32;         
		}  
	}
}
