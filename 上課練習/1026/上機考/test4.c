#include<stdio.h>
#include<stdlib.h>

int main()

{
    int income,taxes=0;
    printf("收入:");
    scanf("%d",&income);
    if(income>0 && income<=500000){
        taxes += income*0.05;
    }
    else if(income>500000 && income<=1130000){
        taxes += 500000*0.05;
        taxes += (income-500000)*0.12+0.5;
    }
    else if(income>1130000 && income<=2260000){
        taxes += 500000*0.05;
        taxes += (1130000-500000)*0.12+0.5;
        taxes += (income-1130000)*0.2;
    }
    else if(income>2260000){
        taxes += 500000*0.05;
        taxes += (1130000-500000)*0.12+0.5;
        taxes += (2260000-1130000)*0.2;
        taxes += (income-2260000)*0.3;
    }
    printf("稅金總計:%d",taxes);
}
