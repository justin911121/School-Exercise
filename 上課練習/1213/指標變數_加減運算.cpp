#include<stdio.h> 
#include<stdlib.h>

int main(){
	int a;
	int *p;
	p=&a;
	printf("a變數的記憶體位址:%p\n",&a);
	printf("指標p的內容記憶體位址:%p\n",p);
	p+=1;
	printf("p+1後的內容記憶體位址:%p\n",p);
	return 0;

}
