#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    int n=0;
    do{
        n++;
        printf("\n�����%d���j��\n",n);
        printf("�O�_�~�����(y/n)\n");
    }while(getche()=='y');
    printf("\n�j���`�@����F%d��",n);
}
