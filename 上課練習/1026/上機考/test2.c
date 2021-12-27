#include<stdio.h>
#include<stdlib.h>

int main()
{
    int celsius, fahrenheit;
    printf("Celsius = ");
    scanf("%d",&celsius);
    fahrenheit = (float)celsius *9/5+0.5;
    printf("Fahrenheit = %d",fahrenheit+32);
    return 0;
}
