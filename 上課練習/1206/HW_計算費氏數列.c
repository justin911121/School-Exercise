#include<stdio.h>
#include<stdlib.h>
int fibo(int);
int count=0;

int main()
{
    int n;
    printf("�п�J�A�n�M��O��ƦC���ĴX��: ");
    scanf("%d",&n);
    printf("�ƦC�� %d ����: %d\n",n,fibo(n-1));
    printf("�I�s�禡%d��",count);
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
