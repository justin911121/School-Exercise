#include<stdio.h>

int main()
{
    while(1){
        char x;
        scanf("%c",&x);
        if(x>=65 && x<=90)
            x+=32;
        else if(x>=97 && x<=122)
            x-=32;
        printf("%c",x);
    }
}
