#include<stdio.h>

int main()
{
	float temp1[12],sum=0;
	float *temp2[12];
	for(int k=0;k<12;k++){
		temp2[k]=&temp1[k];
	}
	for(int i=1;i<=12;i++){
		printf("%d�몺�����ū�:�@",i);
		scanf("%f",&temp1[i]);
	}
	for(int j=0;j<12;j++){
		sum+=temp1[j];
	}
	printf("\n�~�����ū׬�: %f",sum/12);
}


