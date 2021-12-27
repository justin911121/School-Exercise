#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int Random10Numbers(int[] ,int);

int main(){    
	srand(time(NULL)); 
	int data[10];     
	int i,j;     
	for(i=0;i<4;i++){       
	    Random10Numbers(data,10) ; 
		for(j=0;j<10;j++){            
			printf("%d ",data[j]);         
		}         
		printf("\n");     
	}     
	return 0; 
} 

int Random10Numbers(int num[],int size){
	for(int i=0;i<size;i++){
		num[i]=rand()%10;		
		for(int j=0;j<i;j++){
			if(num[i]==num[j]){
				i--;
				break;
			}	
		}
	}
}
