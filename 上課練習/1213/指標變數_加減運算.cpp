#include<stdio.h> 
#include<stdlib.h>

int main(){
	int a;
	int *p;
	p=&a;
	printf("a�ܼƪ��O�����}:%p\n",&a);
	printf("����p�����e�O�����}:%p\n",p);
	p+=1;
	printf("p+1�᪺���e�O�����}:%p\n",p);
	return 0;

}
