#include<stdio.h> 

void Top3Number(int a,int *x,int *y,int *z){
	if(a > *x){
		*z = *y;
		*y = *x;
		*x = a;				
	}
	else if(a <*x && a>*y){
		*z = *y;
		*y = a;
	}
	else if(a > *y&& a<*z){
		*z=a;
	}
}

int main()
{
	int number[]={1,3,26,2,48,11,23,8};
	//testdata
	//int number[]={13,41,1,4,81,16,22,15}; 
	int first=0,second=0,third=0;
	for(int i=0;i<=8;i++)
		Top3Number(number[i],&first,&second,&third);
	//Top3Number(??,??,??)
	printf("First: %d\nSecond: %d\nThird: %d",first,second,third);
	return 0;
}
