#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <ctime>
#define WIDTH 80
#define HEIGHT 26



using namespace std;

void HideCursor();
void gotoxy(int x, int y);
void gotoxy(int x, int y){
    HANDLE hConsoleOutput;
    COORD Cursor_Pos = {x, y};
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}
void HideCursor(){
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void GameInformation(){
	int startline = 1;
	gotoxy(WIDTH+2,startline);
	cout<<"���C�����ͦs�C��,���d��"<<endl;
	gotoxy(WIDTH+2,startline+1);
	cout<<"�@����,�C��60��"<<endl;
	gotoxy(WIDTH+2,startline+2);
	cout<<"�@�����a�Q�Ǫ��l�W,�C������"<<endl;
	gotoxy(WIDTH+2,startline+3);
	cout<<"���a�N�z�LWASD�ΤW�U���k��ӱ����V"<<endl;
	gotoxy(WIDTH+2,startline+4);
	cout<<"�C�j10��,�H���b���ͤU�C�|��BUFF,���a�i�H�Y"<<endl;
	gotoxy(WIDTH+2,startline+5);
	cout<<"F: ���a���ʳt���ܧ�2��"<<endl;	
	gotoxy(WIDTH+2,startline+6);
	cout<<"S: monster���ʳt�״�b"<<endl;	
	gotoxy(WIDTH+2,startline+7);
	cout<<"B: �Ҧ� monsters �ߨ覺�`"<<endl;	
	gotoxy(WIDTH+2,startline+8);
	cout<<"T: �ഫ�W�h,monster�n�k�����a,���a�i�H�Y�� monster"<<endl;
	gotoxy(WIDTH+2,startline+9);
	cout<<"�Ҧ����~�� buff �� 5 ��A���F B"<<endl;
	gotoxy(WIDTH+2,startline+10);
	cout<<"�q�L�@�� +20��"<<endl;	
	gotoxy(WIDTH+2,startline+11);
	cout<<"�Y��Buff +5��"<<endl;
	gotoxy(WIDTH+2,startline+12);
	cout<<"Monster ����+10��"<<endl;						
}
