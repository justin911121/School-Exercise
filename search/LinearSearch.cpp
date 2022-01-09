#include<stdio.h>
#include<stdlib.h>
int LinearSearch(int[], int, int);

int main()
{
	int a[9]={1,5,3,7,8,6,2,9,4};
	int index;
	int key=9;
	
	index=LinearSearch(a,9,key);
	if(index == -1)
		printf("%d is not in array.\n", key);
	else 
		printf("%d is in a[%d]\n", key, index);
	
	return 0;
}

int LinearSearch(int a[],int n,int key){
	for(int i=0;i<n;i++){
		if(a[i]==key) return i; 
	}
	return -1;
}
