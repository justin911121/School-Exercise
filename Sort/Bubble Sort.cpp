#include<stdio.h>
#include<stdlib.h>
void BubbleSort(int[], int);
void PrintArray(int[], int);

int main()
{
	int a[9]={1,5,3,7,8,6,2,9,4};
	
	BubbleSort(a,9);
	PrintArray(a,9);
	
	return 0;
}

void BubbleSort(int a[], int n) {
	int temp;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}

void PrintArray(int a[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
