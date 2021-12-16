#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#define C 523
#define D 587
#define E 659
#define F 698
#define G 784
#define A 880
#define B 988
int main()
{
    int x;
    while(1){
        x = getch();
        if(x=='1')
            Beep(C,500);
        else if(x=='2')
                Beep(D,500);
        else if(x=='3')
                Beep(E,500);
        else if(x=='4')
                Beep(F,500);
        else if(x=='5')
                Beep(G,500);
        else if(x=='6')
                Beep(A,500);
        else if(x=='7')
                Beep(B,500);
    }

    return 0;
}
