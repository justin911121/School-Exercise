#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    int n,counter=0;
    printf("Enter: ");
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        for(int j=1;j<=sqrt(n);i++){
            if(i%j==0)
                counter=1;
        }

    }
}
