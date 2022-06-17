#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <ctime>
#define WIDTH 80
#define HEIGHT 26
#define OBSTACLE_MAX_X 68 
#define OBSTACLE_MAX_Y 19 
#define X_Y_LENGTH 5
#define Y_LENGTH 5
#define X_LENGTH 5
#define OBSTACLE_HEIGHT_LENGTH 5
#define OBSTACLE_WIDTH_LENGTH 5
#define OBSTACLE_MAX_HEIGHT 3
#define OBSTACLE_MAX_WIDTH 9


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
void   Delay(int   time)//time*1000為秒數 
{ 
	clock_t now=clock(); 
	while(clock()-now<time); 
} 
class Map{
	private:
		int x[X_LENGTH];
		int y[Y_LENGTH];
		int ObstacleHeight[OBSTACLE_HEIGHT_LENGTH];
		int ObstacleWidth[OBSTACLE_WIDTH_LENGTH];
		int min_x;
		int min_y;
		int max_x;
		int max_y;
	public:
		Map(){
			min_x = 0;
			min_y = 0;
			max_x = WIDTH;
			max_y = HEIGHT;
			for(int i=0;i<X_Y_LENGTH;i++){
				x[i] = rand()%OBSTACLE_MAX_X+1;
				y[i] = rand()%OBSTACLE_MAX_Y+1;
				ObstacleHeight[i] = rand()%OBSTACLE_MAX_HEIGHT+5;	//5~7
				ObstacleWidth[i] = rand()%OBSTACLE_MAX_WIDTH+4;		//4~12
			}
			CreateMap();
		}
		void CreateMap(){
			//create area
			for(int temp_x=min_x+1;temp_x<max_x;temp_x++){
				gotoxy(temp_x,min_y);
				cout<<"-";
				gotoxy(temp_x,max_y);
				cout<<"-";
			}
			for(int temp_y=min_y+1;temp_y<max_y;temp_y++){
				gotoxy(min_x,temp_y);
				cout<<"|";
				gotoxy(max_x,temp_y);
				cout<<"|";
			}
			gotoxy(min_x,min_y);
			cout<<"/";
			gotoxy(min_x,max_y);
			cout<<"\\";
			gotoxy(max_x,min_y);
			cout<<"\\";
			gotoxy(max_x,max_y);
			cout<<"/";
			//create obstacle
			for(int i=0;i<X_Y_LENGTH;i++){
				for(int temp_x = x[i];temp_x<x[i]+ObstacleWidth[i];temp_x++){
					for(int temp_y = y[i];temp_y<y[i]+ObstacleHeight[i];temp_y++){
						gotoxy(temp_x,temp_y);
						cout<<"*";
					}
				}
			}
			
		}
};
class Monster{
	private:
		int x;//原始座標 x
		int y;//原始座標 y
		int targetX;//目標位置 x
		int targetY;//目標位置 y
		int count;
		clock_t start_time,finish_time; 
		Map map;
	public:
		Monster(){
			x = y = 1;
			count = 0;
			targetX = 30;
			targetY = 1;
			start_time = clock();
			Show();
			while(1){
				Count();
			}
		}
		void Count(){
			double duration;
			finish_time = clock();
			duration = (double)(finish_time - start_time)/CLOCKS_PER_SEC;
			if(duration>=1){
				count++;
				start_time = clock();
				Move();
			}
		}
		void BuffMove(){
			if((x == targetX) && (y == targetY)){
				return;
			}
			gotoxy(x,y);
			cout<<" ";
			if(x<targetX){
				x++;
			}
			else if(x>targetX){
				x--;
			}
			else if(y<targetY){
				y++;
			}
			else if(y>targetY){
				y--;
			}
			gotoxy(x,y);
			cout<<'M';
			Delay(333); 
		}
		void Move(){
			if((x == targetX) && (y == targetY)){
				return;
			}
			 if(count == 5){
				for(int i = 0;i<3;i++){
					gotoxy(x,y);
					cout<<'M';
					BuffMove();	
				}
				count = 0;
			}
			gotoxy(x,y);
			cout<<" ";
			if(x<targetX){
				x++;
			}
			else if(x>targetX){
				x--;
			}
			else if(y<targetY){
				y++;
			}
			else if(y>targetY){
				y--;
			}
			Show();
			Delay(1000);
			
		}
		void Show(){
			gotoxy(x,y);
			cout<<'m';
		}
		
};
int main(){
	HideCursor();
	srand(time(NULL));
	
	Monster monster; 
	(void)getch();
	
	return 0;
}
