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
    printf("1.���q\n2.����\n");
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
    printf("1.������^�S\n2.�^�S�ऽ��\n");
    scanf("%d",&n);
    printf("�п�J�Ʀr: ");
    scanf("%d",&num);
    switch(n){
        case 1:
            printf("���� %f �S",(num/0.454));
            break;
        case 2:
            printf("���� %f ����",(num*0.454));
            break;

    }
}
int height(void){
    int n=0,num=0;
    printf("1.������^�`\n2.�^�`�ऽ��\n");
    scanf("%d",&n);
    printf("�п�J�Ʀr: ");
    scanf("%d",&num);
    switch(n){
        case 1:
            printf("���� %f �^�`",(num*0.3048));
            break;
        case 2:
            printf("���� %f ����",(num/0.3048));
            break;

    }
}
