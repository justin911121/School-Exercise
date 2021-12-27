#include<stdio.h>
#include<math.h>

int main()
{
    int a[100];
    int sum_avg=0,sum_var=0;
    for(int i=0;i<100;i++){
        scanf("%d",&a[i]);
        sum_avg+=a[i];
        sum_var+=a[i]*a[i];
    }

    float avg=0,var=0;
    printf("%d\n%d\n",sum_avg,sum_var);
    avg=sum_avg/100.0;
    var=sum_var/100.0-avg*avg;
    printf("%.3f\n%.3f",avg,var);
}
