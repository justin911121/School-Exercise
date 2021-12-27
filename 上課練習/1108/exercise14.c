#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a[100]={};
    for(int i=0;i<100;i++){
        scanf("%d",&a[i]);
    }
    int where=0,x=a[0];
    for(int i=0;i<100;i++){
        if(x>a[i]){
            where = i;
            x = a[i];
        //    printf("%d\n",x);
        }
    }
    printf("%d",where);
}
