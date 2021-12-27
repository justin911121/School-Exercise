#include<stdio.h>
int year_cal(int x);

int main()
{
    int y,m,d,total=0;
    scanf("%d %d %d",&y,&m,&d);
    for(int i=1;i<m;i++){
        if(i<=7){
            if(i==2&&year_cal(y)==0)
                total+=28;
            else if(i==2&&year_cal(y)==1)
                total+=29;
            else if(i%2==0)
                total+=30;
            else
                total+=31;
        }
        else{
            if(i%2==0)
                total+=31;
            else
                total+=30;
        }
    }
    total+=d;
    printf("%d",total);

}

int year_cal(int ans)
{
    int x;
    if(ans%1000==0)
        x=1;
    else{
        if(ans%4==0){
            if(ans%100==0){
                if(ans%400==0){
                    x=1;
                }
                else
                    x=0;
            }
            else
                x=1;
        }
        else
            x=0;
    }
    return x;
}
