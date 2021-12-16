#include<stdio.h>

int main()
{
    FILE *inp;
    int input_status ,int_temp,int_hot=0,int_pleasant=0,int_cold=0;
    int int_count=0,int_sum=0,int_avg = 0;
    inp = fopen("data1.txt","r");

    input_status = fscanf(inp,"%d",&int_temp);
    while(input_status != EOF){
        printf("%d  ",int_temp);
        int_sum+=int_temp;
        int_count++;
        if(int_temp>=85)
            int_hot++;
        else if(int_temp<60)
            int_cold++;
        else
            int_pleasant++;
        input_status = fscanf(inp,"%d",&int_temp);
    }
    printf("\nhot days: %d\n",int_hot);
    printf("pleasant days: %d\n",int_pleasant);
    printf("cold days: %d\n",int_cold);
    printf("the  average  temperature: %.2f\n",(float)(int_sum/int_count));
    fclose(inp);
    return 0;
}
