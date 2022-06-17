#include<iostream>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#define WIDTH 80
#define HEIGHT 26
#define OBSTACLE_MAX_X 67
#define OBSTACLE_MAX_Y 18
#define OBSTACLE_LENGTH 5
#define OBSTACLE_MAX_HEIGHT 3
#define OBSTACLE_MAX_WIDTH 9
#define TRUE 1
#define FALSE 0
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define Distance_Steps 5
#define fast_code 0
#define slow_code 1
#define b_code 2
#define transfer_code 3
#define F_NUMBER 3
#define S_NUMBER 4
#define B_NUMBER 5
#define T_NUMBER 6
#define BUFF_X 0
#define BUFF_Y 1
#define player_move 0.25
#define monster_move 1

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

class Map{
	protected:
		static int MAP_2DARRAY_X_Y[WIDTH][HEIGHT];
	private:
		int min_x;
		int min_y;
		int max_x;
		int max_y;
		int level;
		static int IsThereAMap;
		char ObstacleIcon;
	public:
		Map(){
			min_x = 0;
			min_y = 0;
			max_x = WIDTH;
			max_y = HEIGHT;
			level = 1;
			ObstacleIcon = '*';
			if(IsThereAMap == FALSE){
				CreateMap();
				IsThereAMap = TRUE;
			}
		}
		void CheckObstacleXY(int x[OBSTACLE_LENGTH],int y[OBSTACLE_LENGTH],int ObstacleWidth[OBSTACLE_LENGTH],int ObstacleHeight[OBSTACLE_LENGTH]){
			for(int i=1;i<OBSTACLE_LENGTH;i++){
				if((x[i] == x[i-1]) && (y[i] == y[i-1])){
					x[i] = rand()%OBSTACLE_MAX_X+1;
					y[i] = rand()%OBSTACLE_MAX_Y+1;
					CheckObstacleXY(x,y,ObstacleWidth,ObstacleHeight);
				}
			}
		}
		void CreateMap(){
			//Set Obstacle data
			int x[OBSTACLE_LENGTH];
			int y[OBSTACLE_LENGTH];
			int ObstacleHeight[OBSTACLE_LENGTH];
			int ObstacleWidth[OBSTACLE_LENGTH];
			SetObstacleData(x,y,ObstacleWidth,ObstacleHeight);
			CheckObstacleXY(x,y,ObstacleWidth,ObstacleHeight);
			//create area
			for(int temp_x=min_x+1;temp_x<max_x;temp_x++){
				gotoxy(temp_x,min_y);
				cout<<"-";
				gotoxy(temp_x,max_y-1);
				cout<<"-";
			}
			for(int temp_y=min_y+1;temp_y<max_y;temp_y++){
				gotoxy(min_x,temp_y);
				cout<<"|";
				gotoxy(max_x-1,temp_y);
				cout<<"|";
			}
			gotoxy(min_x,min_y);
			cout<<"/";
			gotoxy(min_x,max_y-1);
			cout<<"\\";
			gotoxy(max_x-1,min_y);
			cout<<"\\";
			gotoxy(max_x-1,max_y-1);
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
			//Prunt Game Information
			GameInformation();
			ReservedRoad();
			SetMAP_2DARRAY_X_Y(x,y,ObstacleWidth,ObstacleHeight);
		}
		void ReservedRoad(){
			for(int temp_x=min_x+1;temp_x<max_x-1;temp_x++){
				gotoxy(temp_x,min_y+1);
				cout<<" ";
				gotoxy(temp_x,min_y+2);
				cout<<" ";
				gotoxy(temp_x,max_y-2);
				cout<<" ";
				gotoxy(temp_x,max_y-3);
				cout<<" ";
			}
			for(int temp_y=min_y+1;temp_y<max_y-1;temp_y++){
				gotoxy(min_x+1,temp_y);
				cout<<" ";
				gotoxy(min_x+2,temp_y);
				cout<<" ";
				gotoxy(max_x-2,temp_y);
				cout<<" ";
				gotoxy(max_x-3,temp_y);
				cout<<" ";
			}
		}
		void SetMAP_2DARRAY_X_Y(int x[OBSTACLE_LENGTH],int y[OBSTACLE_LENGTH],int ObstacleWidth[OBSTACLE_LENGTH],int ObstacleHeight[OBSTACLE_LENGTH]){
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
			for(int temp_x=min_x+1;temp_x<max_x;temp_x++){
				MAP_2DARRAY_X_Y[temp_x][min_y+1] = 1;
				MAP_2DARRAY_X_Y[temp_x][min_y+2] = 1;
				MAP_2DARRAY_X_Y[temp_x][max_y-3] = 1;
				MAP_2DARRAY_X_Y[temp_x][max_y-2] = 1;
			}
			for(int temp_y=min_y+1;temp_y<max_y;temp_y++){
				MAP_2DARRAY_X_Y[min_x+1][temp_y] = 1;
				MAP_2DARRAY_X_Y[min_x+2][temp_y] = 1;
				MAP_2DARRAY_X_Y[max_x-3][temp_y] = 1;
				MAP_2DARRAY_X_Y[max_x-2][temp_y] = 1;
			}
			for(int temp_x=min_x+1;temp_x<max_x;temp_x++){
				MAP_2DARRAY_X_Y[temp_x][min_y] = 0;
				MAP_2DARRAY_X_Y[temp_x][max_y-1] = 0;
			}
			for(int temp_y=min_y+1;temp_y<max_y;temp_y++){
				MAP_2DARRAY_X_Y[min_x][temp_y] = 0;
				MAP_2DARRAY_X_Y[max_x-1][temp_y] = 0;
			}
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
		    gotoxy(WIDTH+2,startline+5);
		    cout<<"每隔10秒,隨機在產生下列四種BUFF,"<<endl;
		    gotoxy(WIDTH+2,startline+6);
			cout<<"玩家可以吃"<<endl;
		    gotoxy(WIDTH+2,startline+8);
		    cout<<"F: 玩家移動速度變快2倍"<<endl;
		    gotoxy(WIDTH+2,startline+9);
		    cout<<"S: monster移動速度減半"<<endl;
		    gotoxy(WIDTH+2,startline+10);
		    cout<<"B: 所有 monsters 立刻死亡"<<endl;
		    gotoxy(WIDTH+2,startline+11);
		    cout<<"T: 轉換規則,monster要逃離玩家,"<<endl;
			gotoxy(WIDTH+2,startline+12);
			cout<<"玩家可以吃掉 monster"<<endl;
		    gotoxy(WIDTH+2,startline+14);
		    cout<<"所有物品的buff持續時間為5秒，除了B"<<endl;
		    gotoxy(WIDTH+2,startline+15);
		    cout<<"通過一關 +20分"<<endl;
		    gotoxy(WIDTH+2,startline+16);
		    cout<<"吃到Buff +5分"<<endl;
		    gotoxy(WIDTH+2,startline+17);
		    cout<<"Monster 死掉+10分"<<endl;
		    gotoxy(WIDTH+2,startline+19);
		    cout<<"第"<<level<<"關"<<endl;
			gotoxy(WIDTH+2,startline+20);
			cout<<"時間 : 0"<<endl;
			gotoxy(WIDTH+2,startline+21);
			cout<<"分數 : 0"<<endl;
		}
		void SetObstacleData(int x[OBSTACLE_LENGTH],int y[OBSTACLE_LENGTH],int ObstacleWidth[OBSTACLE_LENGTH],int ObstacleHeight[OBSTACLE_LENGTH]){
			for(int i=0;i<OBSTACLE_LENGTH;i++){
				x[i] = rand()%OBSTACLE_MAX_X+1;
				y[i] = rand()%OBSTACLE_MAX_Y+1;
				ObstacleHeight[i] = rand()%OBSTACLE_MAX_HEIGHT+5;
				ObstacleWidth[i] = rand()%OBSTACLE_MAX_WIDTH+4;
			}
		}
		void ResetMap(){
			system("cls");
			level++;
			CreateMap();
		}
		int MAP_2DARRAY_X_YVal(int x,int y){
			return MAP_2DARRAY_X_Y[x][y];
		}
		void ShowMAP_2DARRAY_X_Y(){
			//system("cls");
			for(int i=0;i<WIDTH;i++){
				for(int j=0,m=30;j<HEIGHT;j++,m++){
					gotoxy(i,m);
					cout<<MAP_2DARRAY_X_Y[i][j];
				}
			}
		}
		void RecoveryMAP_2DARRAY_X_YVal(int x,int y){
			MAP_2DARRAY_X_Y[x][y] = 1;
		}
		void ChangeMAP_2DARRAY_X_YVal(int x,int y){
			MAP_2DARRAY_X_Y[x][y] = 2;
		}
		void ChangeMAP_2DARRAY_X_YVal(int x,int y,int BuffNumber){
			MAP_2DARRAY_X_Y[x][y] = BuffNumber;
		}
		int LevelVal(){
			return level;
		}
};
int Map::MAP_2DARRAY_X_Y[WIDTH][HEIGHT];
int Map::IsThereAMap = FALSE;

class Buff{
	private:
		Map m;
		int buff_X_Y[2][6];
		char buff_icon[6];
		int num;
	public:
		Buff(){
			num = 0;
		}
		void Produce(){
			switch(rand()%4){
				case 0:
					CreateBuff(F_NUMBER,'F');
					break;
				case 1:
					CreateBuff(S_NUMBER,'S');
					break;
				case 2:
					CreateBuff(B_NUMBER,'B');
					break;
				case 3:
					CreateBuff(T_NUMBER,'T');
					break;
			}
		}
		void CreateBuff(int number,char icon_key){
			int x,y;
			x = rand()%WIDTH;
			y = rand()%HEIGHT;
			if(m.MAP_2DARRAY_X_YVal(x,y)==1){
				buff_X_Y[BUFF_X][num] = x;
				buff_X_Y[BUFF_Y][num] = y;
				buff_icon[num] = icon_key;
				gotoxy(x,y);
				cout<<buff_icon[num];
				num++;
				m.ChangeMAP_2DARRAY_X_YVal(x,y,number);
			}
			else{
				CreateBuff(number,icon_key);
			}
		}
		void Print_Buff(){
			for(int i=0;i<num;i++){
				gotoxy(buff_X_Y[BUFF_X][i],buff_X_Y[BUFF_Y][i]);
				cout<<buff_icon[i];
			}
		}
		void Delete_Buff(int x,int y){
			gotoxy(x,y);
			cout<<" ";
			m.RecoveryMAP_2DARRAY_X_YVal(x,y);
			for(int i=0;i<num;i++){
				if((buff_X_Y[BUFF_X][i] == x) && (buff_X_Y[BUFF_Y][i] == y)){
					buff_X_Y[BUFF_X][i] = WIDTH+1;
					buff_X_Y[BUFF_Y][i] = HEIGHT+1;
					buff_icon[i] = ' ';
					break;
				}
			}
			return;
		}
		void Delete_All_Buff(){
			for(int i=0;i<num;i++){
				gotoxy(buff_X_Y[BUFF_X][i],buff_X_Y[BUFF_Y][i]);
				cout<<" ";
				m.RecoveryMAP_2DARRAY_X_YVal(buff_X_Y[BUFF_X][i],buff_X_Y[BUFF_Y][i]);
				buff_X_Y[BUFF_X][i] = WIDTH+1;
				buff_X_Y[BUFF_Y][i] = HEIGHT+1;
				buff_icon[i] = ' ';
			}
			num = 0;
			return;
		}
};

class Object{
	protected:
		Map m;
		int x;
		int y;
		int targetX;
		int targetY;
		double runTime;
		int sec_move;
		static int playerNext_temp;
		clock_t start_time,finish_time;
		Object *next;
	private:
		char icon;
	public:
		Object(double time,char icon_key){
			x = rand() % 80;
			y = rand() % 26;
			runTime = time;
			icon = icon_key;
			playerNext_temp = 0;
		}
		~Object(){
			gotoxy(x,y);
			cout<<" ";
		}
		int Count(){
	    	double duration;
			finish_time = clock();
			duration = (double)(finish_time-start_time)/CLOCKS_PER_SEC;
			if(duration>=runTime){
				start_time = clock();
				return 1;
			}
			return 0;
		}
		int Check(int x,int y){
	        if(m.MAP_2DARRAY_X_YVal(x,y)== 0){
	            return 0;
	        }
	        else{
	            return 1;
	        }
    	}
		template <class T>
		T get_next(T){
			return next;
		}
		void tandem(Object *nextObject){
			next = nextObject;
		}
		void targetXY(int a,int b){
			targetX = a;
			targetY = b;
		}
		void Show(){
			gotoxy(x,y);
			cout<<icon;
		}
		int ReturnX(){
			return x;
		}
		int ReturnY(){
			return y;
		}
		char get_icon(){
			return icon;
		}
		void Timer(double movetime){
			runTime = movetime;
		}
		double RunTimeVal(){
			return runTime;
		}
		void SetSec_move(int n){
			sec_move = n;
		}
		void ResetXY(){
			do{
				x = rand() % 80;
				y = rand() % 26;
			}while(m.MAP_2DARRAY_X_YVal(x,y) == 0);
		}
        void TransferAction(){
		    if(Count()){
                switch(playerNext_temp){
                    case 1:
                        if((abs(y-targetY)-abs(y-1-targetY))<0){
                            gotoxy(x,y);
                            cout<<" ";
                            if(Check(x,y-1)!=0) y = y-1;
                            Show();
                        }
                        break;
                    case 2:
                        if((abs(y-targetY)-abs(y+1-targetY))<0){
                            gotoxy(x,y);
                            cout<<" ";
                            if(Check(x,y+1)!=0) y = y+1;
                            Show();
                        }
                        break;
                    case 3:
                        if((abs(x-targetX)-abs(x-1-targetX))<0){
                            gotoxy(x,y);
                            cout<<" ";
                            if(Check(x-1,y)!=0) x = x-1;
                            Show();
                        }
                        break;
                    case 4:
                        if((abs(x-targetX)-abs(x+1-targetX))<0){
                            gotoxy(x,y);
                            cout<<" ";
                            if(Check(x+1,y)!=0) x = x+1;
                            Show();
                        }
                        break;
                    case 0:
                        break;

                }
		    }

		}
		int CheckTransferEat(){
            if((x==targetX)&&(y==targetY)) return 1;
            else return 0;
		}
		void virtual Action() = 0;
};
int Object::playerNext_temp = 0;

class Player:public Object{
	public:
		Player():Object(player_move,'P'){
			start_time = clock();
		}
		char PressedKey(){
	        if(kbhit()){
	            return getch();
	    	}
	        else return NULL;
	    }
		void Action(){
			if(Count()){
				switch(PressedKey()){
	            	case UP:
	            	case 'W':
	            	case 'w':
	            	    if(Check(x,y-1)!=0){
	             		   	gotoxy(x,y);
	        				cout<<" ";
	                    	y = y-1;
	                    	Show();
	                    	playerNext_temp = 1;
	                	}
	                	break;
	            	case DOWN:
	            	case 'S':
	            	case 's':
		                if(Check(x,y+1)!=0){
		                	gotoxy(x,y);
		        			cout<<" ";
		                    y = y+1;
		                    Show();
		                    playerNext_temp = 2;
		                }
		                break;
		            case LEFT:
		            case 'A':
		            case 'a':
		                if(Check(x-1,y)!=0){
		                	gotoxy(x,y);
		        			cout<<" ";
		                    x = x-1;
		                    Show();
		                    playerNext_temp = 3;
		                }
		                break;
		            case RIGHT:
		            case 'D':
		            case 'd':
		                if(Check(x+1,y)!=0){
		                	gotoxy(x,y);
		        			cout<<" ";
		                    x = x+1;
		                    Show();
		                    playerNext_temp = 4;
		                }
		                break;
		            default:
		                break;
				}
				if(m.MAP_2DARRAY_X_YVal(x,y) == 2){
					m.RecoveryMAP_2DARRAY_X_YVal(x,y);
				}
			}
		}
};

class Monster:public Object{
	protected:
		int time_count;
		int stopX;
		int stopY;
		int key = 0;
		int sec_move;
		double duration_move;
	public:
		Monster(int a,int b,char icon_key):Object(monster_move,icon_key){
			targetX = a;
			targetY = b;
			time_count = 0;
			sec_move = 1;
			duration_move = 1;
			start_time = clock();
		}
		void Action(){
			if(Count()){
				Show();
				time_count++;
				start_time = clock();
				Move();
				//m.ShowMAP_2DARRAY_X_Y();
			}
		}
		int Count(){
			double duration;
			finish_time = clock();
			duration = (double)(finish_time - start_time)/CLOCKS_PER_SEC;
			if(duration>=duration_move)return TRUE;
			else return FALSE;
		}
		void TakeADetour(){
			switch(CheckKey()){
				case 1:
					if(Check(x+1,y)==2){
						x--;
					}
					else{
						y++;
					}
					key = 0;
					break;
				case 2:
					if(Check(x,y+1)==2){
						y--;
					}
					else{
						x--;
					}
					key = 0;
					break;
				case 3:
					if(Check(x,y+1)==2){
						y--;
					}
					else{
						x++;
					}
					key = 0;
					break;
				case 4:
					if(Check(x-1,y)==2){
						x++;
					}
					else{
						y++;
					}
					key = 0;
					break;
				case 5:
					y--;
					key = 0;
					break;
				case 6:
					y++;
					key = 0;
					break;
				case 7:
					x--;
					key = 0;
					break;
				case 8:
					x++;
					key = 0;
					break;
			}
		}
		int CheckKey(){
			return key;
		}
		int Check(int x,int y){
	        if(m.MAP_2DARRAY_X_YVal(x,y) == 0){
	            return 0;
	        }
	        if(m.MAP_2DARRAY_X_YVal(x,y) == 2){
	            return 2;
	        }
	        else{
	            return 1;
	        }
	    }
		void Move(){
			if(((x==targetX) && (y==targetY))){
				return;
			}
			if(time_count % sec_move == 0){
				stopX = x;
				stopY = y;
				gotoxy(x,y);
				cout<<" ";
				if(key == 0){
					if(x<targetX){
						if(Check(x+1,y)!=1){
						}else x++;
					}
					else
						if(x>targetX){
							if(Check(x-1,y)!=1){
							}else x--;
						}
					if(y<targetY){
						if(Check(x,y+1)!=1){
						}else y++;
					}
					else
						if(y>targetY){
							if(Check(x,y-1)!=1){
							}else y--;
						}
					if(stopX == x && stopY == y){
						if(Check(x+1,y)!=1)
							switch(rand()%2){
								case 0:
									key = 5;
									break;
								case 1:
									key = 6;
									break;
							}
						if(Check(x,y+1)!=1)
							switch(rand()%2){
								case 0:
									key = 7;
									break;
								case 1:
									key = 8;
									break;
							}
						if(Check(x-1,y)!=1)
							switch(rand()%2){
								case 0:
									key = 5;
									break;
								case 1:
									key = 6;
									break;
							}
						if(Check(x,y-1)!=1)
							switch(rand()%2){
								case 0:
									key = 7;
									break;
								case 1:
									key = 8;
									break;
							}
						if(Check(x,y-1)!=1 && Check(x+1,y)!=1) key = 1;
						if(Check(x,y+1)!=1 && Check(x+1,y)!=1) key = 2;
						if(Check(x,y+1)!=1 && Check(x-1,y)!=1) key = 3;
						if(Check(x,y-1)!=1 && Check(x-1,y)!=1) key = 4;
						if(Check(x-1,y)!=1 && Check(x+1,y)!=1 && Check(x,y+1)!=1) key = 5;
						if(Check(x-1,y)!=1 && Check(x+1,y)!=1 && Check(x,y-1)!=1) key = 6;
						if(Check(x,y-1)!=1 && Check(x+1,y)!=1 && Check(x,y+1)!=1) key = 7;
						if(Check(x,y-1)!=1 && Check(x-1,y)!=1 && Check(x,y+1)!=1) key = 8;
					}
				}
				if(key != 0){
					m.ChangeMAP_2DARRAY_X_YVal(x,y);
					TakeADetour();
				}
				Show();
			}
		}
};

class Y_Monster:public Monster{
	public:
		Y_Monster(int a,int b):Monster(a,b,'Y'){
		}
		void Action(){
			if(Count()){
				if(abs(targetX-x)+abs(targetY-y)>=20){
					ViolentMove();
				}
				else{
					duration_move = 1;
					Monster::Action();
				}
			}

		}
		void ViolentMove(){
			duration_move = 0.33;
			Monster::Action();
		}
};

class LinkedList{
	private:
		int time_count;
		int num;
		int score;
		int buff_temp;
		int T_check;
		Map m;
		Buff *B = new Buff;
		Object *first,*q;
		clock_t LinkedList_start_time,LinkedList_finish_time;
		clock_t J_start_time,J_finish_time;
		clock_t fast_finish_time,fast_start_time;
		clock_t slow_finish_time,slow_start_time;
		clock_t transfer_finish_time,transfer_start_time;
	public:
		LinkedList(){
			first = NULL;
			time_count = 0;
			score = 0;
			buff_temp = 0;
			T_check = 0;
			LinkedList_start_time = clock();
		}
		int Count(){
			double duration;
			LinkedList_finish_time = clock();
			duration = (double)(LinkedList_finish_time-LinkedList_start_time)/CLOCKS_PER_SEC;
			if(duration>=1){
				LinkedList_start_time = clock();
				time_count++;
				return 1;
			}
			return 0;
		}
		void Control(){
			if(Count()){
				gotoxy(WIDTH+2,21);
				cout<<"時間 : "<<time_count<<endl;
				if((time_count % 10 == 0) && (time_count != 0)){
					B->Produce();
					gotoxy(30,28);
					cout<<"Add Buff";
				}
				if((time_count % 20 == 0) && (time_count % 60 != 0)){
					GenerateMonster();
				}
				if((time_count % 60 == 0) && (time_count != 0)){
					Reset();
				}
			}
		}
		void Insert(Object *newObject){
			if(first==NULL){
				first = newObject;
				first->tandem(first);
				q = first;
			}
			else{
				newObject->tandem(first);
				q->tandem(newObject);
				q = newObject;
			}
		}
		void Insert_player(){
			Player *P;
			while(1){
				P = new Player;
				if(m.MAP_2DARRAY_X_YVal(P->ReturnX(),P->ReturnY())==1)break;
			}
			Insert(P);
		}
		void Insert_monster(){
			Monster *M;
			while(1){
				M = new Monster(first->ReturnX(),first->ReturnY(),'M');
				if(m.MAP_2DARRAY_X_YVal(M->ReturnX(),M->ReturnY())==1)break;
			}
			Insert(M);
		}
		void Insert_Y_monster(){
			Y_Monster *Y;
			while(1){
				Y = new Y_Monster(first->ReturnX(),first->ReturnY());
				if(m.MAP_2DARRAY_X_YVal(Y->ReturnX(),Y->ReturnY())==1)break;
			}
			Insert(Y);
		}
		void GenerateMonster(){
            Insert_Y_monster();
            gotoxy(30,27);
            cout<<"generate Y_monster"<<endl;
            return;
		}
		void AddScore(int a){
			score = score + a;
			gotoxy(WIDTH+2,22);
			cout<<"分數 : "<<score<<endl;
			return;
		}
		int Monsternumber(){
            Object *p = first;
            int number = 0;
            do{
                if(p->get_icon()!='P'){
                    number++;
                }
                p = p->get_next(p);
            }while(p!=first);
            return number;
        }
		void Check_buffEat(Object *object){
			if(object->get_icon() == 'P'){
				switch(m.MAP_2DARRAY_X_YVal(first->ReturnX(),first->ReturnY())){
					case F_NUMBER:
						fast_start_time = clock();
						AddScore(5);
						first->Timer(player_move/2);
						gotoxy(0,26);
						cout<<"玩家移動速度變快2倍!!";
						buff_temp = F_NUMBER;
						B->Delete_Buff(object->ReturnX(),object->ReturnY());
						break;
					case S_NUMBER:
						slow_start_time = clock();
						AddScore(5);
						SlowMonster();
						gotoxy(0,27);
						cout<<"monster移動速度減半!!";
						buff_temp = S_NUMBER;
						B->Delete_Buff(object->ReturnX(),object->ReturnY());
						break;
					case B_NUMBER:
						AddScore(5);
						num = Monsternumber();
						AddScore(10*num);
						All_Monster_Die();
						gotoxy(0,28);
						cout<<"所有 monsters 立刻死亡!!";
						B->Delete_Buff(object->ReturnX(),object->ReturnY());
						break;
					case T_NUMBER:
						transfer_start_time = clock();
						AddScore(5);
						T_check = 1;
						buff_temp = T_NUMBER;
						gotoxy(0,29);
						cout<<"轉換規則!!";
						B->Delete_Buff(object->ReturnX(),object->ReturnY());
						break;
					default:
						break;
				}
			}
			if(object->get_icon() == 'D'){
				if((m.MAP_2DARRAY_X_YVal(object->ReturnX(),object->ReturnY()) >= 3) && (m.MAP_2DARRAY_X_YVal(object->ReturnX(),object->ReturnY()) <= 6)){
					B->Delete_Buff(object->ReturnX(),object->ReturnY());
				}
			}
			else{
				return;
			}
		}
		void Reset_F_Buff(){
			fast_finish_time = clock();
			double duration = (fast_finish_time - fast_start_time)/CLOCKS_PER_SEC;
			if(duration>=5)	{
				first->Timer(player_move);
				gotoxy(0,26);
				cout<<"                      ";
				buff_temp = 0;
			}
		}
		void Reset_S_Buff(){
			slow_finish_time = clock();
			double duration = (slow_finish_time - slow_start_time)/CLOCKS_PER_SEC;
			if(duration>=5){
				Object *p = first;
				do{
					if(p->get_icon() != 'P'){
						p->SetSec_move(1);
						gotoxy(0,27);
						cout<<"                      ";
						buff_temp = 0;
					}
					p = p->get_next(p);
				}while(p!=first);
			}
		}
		void Reset_T_Buff(){
			transfer_finish_time = clock();
			double duration = (transfer_finish_time - transfer_start_time)/CLOCKS_PER_SEC;
            if(duration>=5){
				buff_temp = 0;
				gotoxy(0,29);
				cout<<"                        ";
				buff_temp = 0;
				T_check = 0;
            }
		}
		void SlowMonster(){
			Object *p = first;
			do{
				if(p->get_icon() != 'P'){
					p->SetSec_move(2);
				}
				p = p->get_next(p);
			}while(p!=first);
		}
		void T_Buff_Monster_Die(){
   			Object *p = first;
 			do{
				if((first->ReturnX()==p->ReturnX()) && (first->ReturnY()==p->ReturnY()) && (p->get_icon() != 'P')){
					Delete_Object(p);
					break;
				}
				p = p->get_next(p);
			}while(p!=first);
		}
		void All_Monster_Die(){
  			Object *p = first;
  			do{
    			if(p->get_icon() != 'P'){
					Delete_Object(p);
				}
				p = p->get_next(p);
			}while(p!=first);
			return;
		}
		void Delete_Object(Object *delete_Object){
  			Object *p = first,*a = first;
			do{
    			if(p->get_next(p)==delete_Object)break;
    			p = p->get_next(p);
			}while(p!=first);
  			p->tandem(delete_Object->get_next(delete_Object));
  			do{
                if(a->get_next(a)==first)break;
                a = a->get_next(a);
            }while(a!=first);
            q = a;
			delete delete_Object;
		}
		void AroundList(){
			Object *p = first;
			do{
				p->Show();
				if(T_check&&p!=first){
					p->TransferAction();
					if(p->CheckTransferEat()){
                        AddScore(10);
                        T_Buff_Monster_Die();
					}
				}
				else {
                    p->Action();
				}
				Check_buffEat(p);
				B->Print_Buff();
				p->targetXY(first->ReturnX(),first->ReturnY());
				if(buff_temp == F_NUMBER){
					Reset_F_Buff();
				}
				if(buff_temp == S_NUMBER){
					Reset_S_Buff();
				}
				if(buff_temp == T_NUMBER){
					Reset_T_Buff();
				}
				if(T_check == 0) Player_Die();
				p = p->get_next(p);
			}while(p!=first);
		}
		void GodModeAroundList(){
            Object *p = first;
            do{
				p->Show();
				if(T_check&&p!=first){
					p->TransferAction();
					if(p->CheckTransferEat()){
                        AddScore(10);
                        T_Buff_Monster_Die();
					}
				}
				else {
                    p->Action();
				}
				Check_buffEat(p);
				B->Print_Buff();
				p->targetXY(first->ReturnX(),first->ReturnY());
				if(buff_temp == F_NUMBER){
					Reset_F_Buff();
				}
				if(buff_temp == S_NUMBER){
					Reset_S_Buff();
				}
				if(buff_temp == T_NUMBER){
					Reset_T_Buff();
				}
				p = p->get_next(p);
            }while(p!=first);
        }
		void Player_Die(){
		    Object *p = first->get_next(first);
		    do{
		        if((first->ReturnX()==p->ReturnX()) && (first->ReturnY()==p->ReturnY()) && (p->get_icon() != 'P')){
		        	All_Monster_Die();
					Delete_Object(first);
		        	system("cls");
					gotoxy(25,12);
		        	cout<<"87! 會不會玩啊";
		        	gotoxy(25,14);
		        	cout<<"your score = "<<score;
		        	break;
		        }
		        p = p->get_next(p);
		    }while(p!=first);
		}
		void GameOver(){
			Object *p = first;
			All_Monster_Die();
			first == NULL;
			delete p;
			system("cls");
			gotoxy(45,12);
		    cout<<"Success!!";
		    gotoxy(25,14);
		    cout<<"your score = "<<score;
		}
		void Reset(){
			All_Monster_Die();
			B->Delete_All_Buff();
			m.ResetMap();
			if(m.MAP_2DARRAY_X_YVal(first->ReturnX(),first->ReturnY()) == 0){
				first->ResetXY();
			}
			AddScore(20);
			time_count = 0;
			GenerateMonster();
			if(m.LevelVal() > 5){
				GameOver();
			}
		}
};

int main(){
    HideCursor();
    srand(time(NULL));
    gotoxy(42,10);
    cout<<"press \"R\" to enter God Mode"<<endl;
    gotoxy(35,13);
    cout<<"press another key to enter Normal Mode"<<endl;
	char a;
    a = getch();
    system("cls");
    LinkedList *l =new LinkedList;
    l->Insert_player();
    l->Insert_monster();
    switch(a){
        case 'R':
        case 'r':
            gotoxy(0,26);
            cout<<"God Mode";
            while(TRUE){
                l->Control();
                l->GodModeAroundList();
            }
            break;
        default:
            gotoxy(0,26);
            cout<<"Normal Mode";
            while(TRUE){
                l->Control();
                l->AroundList();
            }
            break;
    }
}
