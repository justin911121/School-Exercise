#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    int n=0;
    do{
        n++;
        printf("\n執行第%d次迴圈\n",n);
        printf("是否繼續執行(y/n)\n");
    }while(getche()=='y');
    printf("\n迴圈總共執行了%d次",n);
}
