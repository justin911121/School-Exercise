#include<stdio.h>
#include<stdlib.h>
int choose(void);
int weight(void);
int height(void);

int main()
{
    choose();
}

int choose(void){
    int n=0;
    printf("1.重量\n2.長度\n");
    scanf("%d",&n);
    switch(n){
        case 1:
            weight();
            break;
        case 2:
            height();
            break;
    }
}

int weight(void){
    int n=0,num=0;
    printf("1.公斤轉英磅\n2.英磅轉公斤\n");
    scanf("%d",&n);
    printf("請輸入數字: ");
    scanf("%d",&num);
    switch(n){
        case 1:
            printf("等於 %f 磅",(num/0.454));
            break;
        case 2:
            printf("等於 %f 公斤",(num*0.454));
            break;

    }
}
int height(void){
    int n=0,num=0;
    printf("1.公尺轉英呎\n2.英呎轉公尺\n");
    scanf("%d",&n);
    printf("請輸入數字: ");
    scanf("%d",&num);
    switch(n){
        case 1:
            printf("等於 %f 英呎",(num*0.3048));
            break;
        case 2:
            printf("等於 %f 公尺",(num/0.3048));
            break;

    }
}
