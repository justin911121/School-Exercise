#include<stdio.h>

#define PI 3.1415
#define rSqare  r*r

int main()
{
	int r;
	printf("請輸入半徑: ");
	scanf("%d",&r);
	printf("圓面積為%f\n",rSqare*PI);
	printf("球體積為%f",4/3*PI*r*rSqare);
	
	return 0;
}
