#include<stdio.h>
#include<stdlib.h>
int sum(int);
int score(int);

int main()
{
    int n,ans;
    float avg;
    printf("請輸入你想計算的科目數\n");
    scanf("%d",&n);
    ans=sum(n);
    printf("你的總分為: %d\n",ans);
    avg=(float)ans/n;
    printf("你的平均為: %f\n",avg);
    score(avg);
    return 0;
}

int sum(int x){
    int total=0,a=0;
    for(int i=1;i<=x;i++){
        printf("請輸入第%d科成績: ",i);
        scanf("%d",&a);
        total+=a;
    }
    return total;
}

int score(int x){
    switch(x){
        case 90 ... 100:
            printf("評語: 太棒了");
            break;
        case 70 ... 89:
            printf("評語: 讚");
            break;
        default:
            printf("評語: 加油");
            break;
    }
}
