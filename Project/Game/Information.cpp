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
	cout<<"此遊戲為生存遊戲,關卡制"<<endl;
	gotoxy(WIDTH+2,startline+1);
	cout<<"共五關,每關60秒"<<endl;
	gotoxy(WIDTH+2,startline+2);
	cout<<"一旦玩家被怪物追上,遊戲結束"<<endl;
	gotoxy(WIDTH+2,startline+3);
	cout<<"玩家將透過WASD或上下左右鍵來控制方向"<<endl;
	gotoxy(WIDTH+2,startline+4);
	cout<<"每隔10秒,隨機在產生下列四種BUFF,玩家可以吃"<<endl;
	gotoxy(WIDTH+2,startline+5);
	cout<<"F: 玩家移動速度變快2倍"<<endl;	
	gotoxy(WIDTH+2,startline+6);
	cout<<"S: monster移動速度減半"<<endl;	
	gotoxy(WIDTH+2,startline+7);
	cout<<"B: 所有 monsters 立刻死亡"<<endl;	
	gotoxy(WIDTH+2,startline+8);
	cout<<"T: 轉換規則,monster要逃離玩家,玩家可以吃掉 monster"<<endl;
	gotoxy(WIDTH+2,startline+9);
	cout<<"所有物品的 buff 為 5 秒，除了 B"<<endl;
	gotoxy(WIDTH+2,startline+10);
	cout<<"通過一關 +20分"<<endl;	
	gotoxy(WIDTH+2,startline+11);
	cout<<"吃到Buff +5分"<<endl;
	gotoxy(WIDTH+2,startline+12);
	cout<<"Monster 死掉+10分"<<endl;						
}
