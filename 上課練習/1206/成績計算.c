#include<stdio.h>
#include<stdlib.h>
int sum(int);
int score(int);

int main()
{
    int n,ans;
    float avg;
    printf("�п�J�A�Q�p�⪺��ؼ�\n");
    scanf("%d",&n);
    ans=sum(n);
    printf("�A���`����: %d\n",ans);
    avg=(float)ans/n;
    printf("�A��������: %f\n",avg);
    score(avg);
    return 0;
}

int sum(int x){
    int total=0,a=0;
    for(int i=1;i<=x;i++){
        printf("�п�J��%d�즨�Z: ",i);
        scanf("%d",&a);
        total+=a;
    }
    return total;
}

int score(int x){
    switch(x){
        case 90 ... 100:
            printf("���y: �ӴΤF");
            break;
        case 70 ... 89:
            printf("���y: �g");
            break;
        default:
            printf("���y: �[�o");
            break;
    }
}
