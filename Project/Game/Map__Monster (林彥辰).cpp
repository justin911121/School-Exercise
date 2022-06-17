// Map + Monster
#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define WIDTH 80
#define HEIGHT 26
#define OBSTACLE_MAX_X 68
#define OBSTACLE_MAX_Y 19 
#define OBSTACLE_LENGTH 5
#define Y_LENGTH 5
#define X_LENGTH 5
#define OBSTACLE_HEIGHT_LENGTH 5
#define OBSTACLE_WIDTH_LENGTH 5
#define OBSTACLE_MAX_HEIGHT 3
#define OBSTACLE_MAX_WIDTH 9

#define PEOPLE_X 30
#define PEOPLE_Y 30 

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
void Delay(int   time)//time*1000¬°¬í¼Æ 
{ 
	clock_t now=clock(); 
	while(clock()-now<time); 
} 

class Map{
	protected:
		int x[X_LENGTH];
		int y[Y_LENGTH];
		int ObstacleHeight[OBSTACLE_HEIGHT_LENGTH];
		int ObstacleWidth[OBSTACLE_WIDTH_LENGTH];
		int MAP_2DARRAY_X_Y[WIDTH][HEIGHT];
	private:
		int min_x;
		int min_y;
		int max_x;
		int max_y;
		char ObstacleIcon;
	public:
		Map(){
			min_x = 0;
			min_y = 0;
			max_x = WIDTH;
			max_y = HEIGHT;
			ObstacleIcon = '*';
			for(int i=0;i<OBSTACLE_LENGTH;i++){
				x[i] = rand()%OBSTACLE_MAX_X+1;
				y[i] = rand()%OBSTACLE_MAX_Y+1;
				ObstacleHeight[i] = rand()%OBSTACLE_MAX_HEIGHT+5;	//5~7
				ObstacleWidth[i] = rand()%OBSTACLE_MAX_WIDTH+4;		//4~12
			}
			CheckObstacleXY();
			CreateMap();
			SetMAP_2DARRAY_X_Y();
		}
		void CheckObstacleXY(){
			for(int i=1;i<OBSTACLE_LENGTH;i++){
				if((x[i] == x[i-1]) && (y[i] == y[i-1])){
					x[i] = rand()%OBSTACLE_MAX_X+1;
					y[i] = rand()%OBSTACLE_MAX_Y+1;
					CheckObstacleXY();
				}
			}
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
			for(int i=0;i<OBSTACLE_LENGTH;i++){
				for(int temp_x = x[i];temp_x<x[i]+ObstacleWidth[i];temp_x++){
					for(int temp_y = y[i];temp_y<y[i]+ObstacleHeight[i];temp_y++){
						gotoxy(temp_x,temp_y);
						cout<<ObstacleIcon;
					}
				}
			}
		}
		void SetMAP_2DARRAY_X_Y(){
			for(int i=0;i<WIDTH;i++){
				for(int j=0;j<HEIGHT;j++){
					MAP_2DARRAY_X_Y[i][j] = 1;
				}
			}
			for(int temp_x=min_x+1;temp_x<max_x;temp_x++){
				MAP_2DARRAY_X_Y[temp_x][min_y] = 0;
				MAP_2DARRAY_X_Y[temp_x][max_y-1] = 0;
			}
			for(int temp_y=min_y+1;temp_y<max_y;temp_y++){
				MAP_2DARRAY_X_Y[min_x][temp_y] = 0;
				MAP_2DARRAY_X_Y[max_x-1][temp_y] = 0;
			}
			MAP_2DARRAY_X_Y[min_x][min_y] = 0;
			MAP_2DARRAY_X_Y[min_x][max_y-1] = 0;
			MAP_2DARRAY_X_Y[max_x-1][min_y] = 0;
			MAP_2DARRAY_X_Y[max_x-1][max_y-1] = 0;
			for(int k=0;k<OBSTACLE_LENGTH;k++){
				for(int temp_x = x[k];temp_x<x[k]+ObstacleWidth[k];temp_x++){
					for(int temp_y = y[k];temp_y<y[k]+ObstacleHeight[k];temp_y++){
						MAP_2DARRAY_X_Y[temp_x][temp_y] = 0;
					}
				}
			}
		}
};

class Monster: public Map{
	private:
		int x;
		int y;
		int targetX;
		int targetY;
		int time_count;
		clock_t start_time,finish_time;
		Map map;
	public:
		Monster(){
			x = y = 1;
			time_count = 0;
			targetX = 30;
			targetY = 1;
			start_time = clock();
			show();
			while(1){
				Count();
			}
		}
		void Count(){
			double duration;
			finish_time = clock();
			duration = (double)(finish_time-start_time)/CLOCKS_PER_SEC;
			if(duration>=1){
				time_count++;
				//gotoxy(0,0);
				//cout<<time_count;
				start_time = clock();
				Action();
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
		void Check(){
			if(MAP_2DARRAY_X_Y[max_x-1][max_y-1] == 0){
				return ;
			}
		}				
		void Action(){
			if((x == targetX) && (y == targetY)){
				return;
			}
			if((targetX-x)+(targetY-y)>=20){
				for(int i = 0;i<3;i++){
					gotoxy(x,y);
					cout<<'M';
					BuffMove();	
				}
				time_count = 0;
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
			show();
			Delay(1000);
			
		}

		void show(){
			gotoxy(x,y);
			cout<<"m";
		}
};

int main(){
	HideCursor();
	srand(time(NULL));

	Monster monster;
	
	return 0;
}
