#include<stdio.h>
#include<stdlib.h>
int BinarySearch(int[], int, int);
void BubbleSort(int[], int);

int main()
{
	int a[9]={1,5,3,7,8,6,2,9,4};
	int index;
	int key=9;
	
	index=BinarySearch(a,9,key);
	if(index == -1)
		printf("%d is not in array.\n", key);
	else 
		printf("%d is in a[%d]\n", key, index);
	
	return 0;
}

int BinarySearch(int a[], int n, int key){
	int low=0, high=n-1, mid;
	
	BubbleSort(a, n);
	while(1){
		if(key==a[high]) return high;
		else if(key==a[low]) return low;
		else if(a[high]<a[low] || key>a[high] || key<a[low]) return -1;
		mid=(low+high)/2;
		if(key==a[mid]) return mid;
		else{
			if(key>a[mid]) low = mid;
			else if(key<a[mid]) high = mid;
		} 
	}
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
