#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x1,y1,x2,y2;
    int x3=0,y3=0;
    printf("Enter (x1,y1): ");
    scanf("%d,%d",&x1,&y1);
    printf("Enter (x2,y2): ");
    scanf("%d,%d",&x2,&y2);
    if(x2<x1){
        x3=x1;
        x1=x2;
        x2=x3;
        y3=y1;
        y1=y2;
        y2=y3;
    }
    printf("(x1,y1)=(%d,%d)\n",x1,y1);
    printf("(x2,y2)=(%d,%d)",x2,y2);
    return 0;

}
