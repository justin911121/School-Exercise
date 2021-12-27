#include<stdio.h>
#include<math.h>
int Decimal2Binary(int);

int main(){
    int x;
    printf("Enter a number:");
    scanf("%d",&x);
    printf("%d",Decimal2Binary(x));

    return 0;
}

int Decimal2Binary(int a){
    int ans[10]={},sum=0,i=0,j;
    while(a/2!=0){
        //printf("a=%d\n",a);
        ans[i]=a%2;
        //printf("ans[%d]=%d\n",i,ans[i]);
        a/=2;
        i++;
    }
    ans[i]=a%2;
    //printf("ans[%d]=%d\n",i,ans[i]);
    j=i;

	while(j >= 0){
		sum+=ans[j]*pow(10,j);
		j--;
	}
    return sum;
}
