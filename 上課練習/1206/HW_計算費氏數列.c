#include<stdio.h>
#include<stdlib.h>
int fibo(int);
int count=0;

int main()
{
    int n;
    printf("請輸入你要尋找費氏數列的第幾項: ");
    scanf("%d",&n);
    printf("數列第 %d 項為: %d\n",n,fibo(n-1));
    printf("呼叫函式%d次",count);
    return 0;
}

int fibo(int x){
    count++;
    if(x==0)
        return 0;
    else if(x==1||x==2)
        return 1;
    else
        return fibo(x-1)+fibo(x-2);
}

//1 1 2 3 5 8 13 19
