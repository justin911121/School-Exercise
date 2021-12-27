#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x,y,sum=0;
    scanf("%d %d",&x,&y);
    while(x<=y){
        sum+=x;
        x++;
    }
    printf("sum = %d",sum);
}
