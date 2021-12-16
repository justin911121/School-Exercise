#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
void gogoxy(int,int);
void gotoxy(int x,int y){
    COORD pos={x,y};
    HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut,pos);
}
int main()
{
    char horse='H';
    int i,x=0,y=10;

    system("cls");
    gotoxy(x,y);
    printf("%c",horse);

    for(i=0;i<30;i++){
        //goto(x,y)clear the symbol of horse gotoxy(x,y);
        gotoxy(x,y);
        printf(" ");
        //update new location to(x,y)
        x++;
        //goto new location(x,y)draw the symbol of horse
        gotoxy(x,y);
        printf("%c",horse);
        _sleep(100);
    }
    return 0;
}
