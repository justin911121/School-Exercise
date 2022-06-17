// Map + Monster
#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <ctime>
#define WIDTH 80
#define HEIGHT 26
#define MAP_WIDTH 78
#define MAP_HEIGHT 24
#define WALL_AMOUNT 6
#define MAX_WIDTH 15
#define MAX_HEIGHT 9

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
    private:
        char map[WIDTH][HEIGHT];
    public:
        Map(){
            for(int i=0;i<80;i++){
                for(int j=0;j<26;j++){
                    map[i][j] = ' ';
                }
            }
            map[0][0] = '/';
            map[79][0] = '\\';
            map[0][25] = '\\';
            map[79][25] = '/';
            for(int i=1;i<79;i++){
                map[i][0] = '-';
                map[i][25] = '-';
            }
            for(int i=1;i<25;i++){
                map[0][i] = '|';
                map[79][i] = '|';
            }
            for(int i=0;i<WALL_AMOUNT;i++)
                CreateWall();
            PrintMap();
        }
        void PrintMap(){
            for(int i=0;i<80;i++){
                for(int j=0;j<26;j++){
                    gotoxy(i,j);
                    cout<<map[i][j];
                }
            }
        }
        void CreateWall(){
            int width = rand()%MAX_WIDTH + 1;
            int height = rand()%MAX_HEIGHT + 1;
            int left_x = rand()%(MAP_WIDTH-width) + 1;
            int up_y = rand()%(MAP_HEIGHT-height) + 1;
            for(int a=0,i=left_x;a<width;a++,i++){
                for(int b=0,j=up_y;b<height;b++,j++){
                    map[i][j] = '*';
                }
            }
        }
        void Plus(int x,int y,char c){
            map[x][y] = c;
        }
};


class Monster{
	private:
		int x;
		int y;
		int targetX;
		int targetY;
		int time_count;
		char icon;
		clock_t start_time,finish_time;
		Map map;
	public:
		Monster(){
			x = y = 1;
			time_count = 0;
			targetX = 30;
			targetY = 1;
			icon = 'M';
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
    srand(time(NULL));
    Map m;
    Monster monster;
    
    return 0;
}


