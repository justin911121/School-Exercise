#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    int poker[52];
    int i;
    int roll;
    int timesRoll=0;
    int temp;
    int end=51;

    srand(time(NULL));

    for(i=0;i<52;i++){
        poker[i]=i;
    }
    for(i=0;i<52;i++){
        roll=rand()%(52-i);
        temp=poker[end];
        poker[end]=poker[roll];
        poker[roll]=temp;
        end--;
        timesRoll++;
    }
 /*
        do{
            roll=rand()%52;
            timesRoll++;
        }while(poker[roll]);
        poker[roll]=1;
 */
    for(int i=0;i<52;i++){
//        printf("%d ",poker[i]);
        switch(poker[i]/13){
            case 0:
                printf("S:");
                break;
            case 1:
                printf("H:");
                break;
            case 2:
                printf("D:");
                break;
            case 3:
                printf("C:");
                break;
            default:
                printf("error....\n");
                exit(1);
        }
        switch(poker[i]%13+1){
            case 1 ... 10:
                printf("%d\n",poker[i]%13+1);
                break;
            case 11:
                printf("J\n");
                break;
            case 12:
                printf("Q\n");
                break;
            case 13:
                printf("K\n");
                break;
            default:
                printf("error....\n");
                exit(1);
        }
    }
    printf("\nroll %d times\n",timesRoll);

    return 0;
}
