#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#define power_test 100
#define space_test 2592
using namespace std;

void gotoxy(int x, int y){
	COORD pos = {x,y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// 獲取標準輸出裝置控制代碼
	SetConsoleCursorPosition(hOut, pos);//兩個引數分別是指定哪個窗體，具體位置
}
void HideCursor(){
	CONSOLE_CURSOR_INFO cursor_info = {1, 0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

class Robot{
	private:
		int x;
		int y;
		int chargingX;
		int chargingY;
		int power;
		int maxPower;
		int targetX;
		int targetY;
	public:
		Robot(){
			x = 0;
			y = 0;
			chargingX = 0;
			chargingY = 0;
			power = power_test;
			maxPower = power_test;
			targetX = 30;
			targetY = 10;
		}
		Robot(int a,int b){
			x = a;
			y = b;
		}
		int Xval(){
			return x;
		}
		int Yval(){
			return y;
		}		
		int CXval(){
			return chargingX;
		}
		int CYval(){
			return chargingY;
		}
		int Powerval(){
			return power;
		}
		int MaxPowerval(){
			return maxPower;
		} 
		int TXval(){
			return targetX;
		}
		int TYval(){
			return targetY;
		}
		
		void SetLocation(int a,int b){
			x = a;
			y = b;			
		}
		void SetChargingLocation(int a,int b){
			chargingX = a;
			chargingY = b;
		}
		void SetPower(int a){
			power = a;
		}
		void SetTargetLocation(int a,int b){
			targetX = a;
			targetY = b;
		}
		void SetMaxPower(int a){
			maxPower = a;
		}
		void Status(){
			gotoxy(0,16);
			printf("Location = (%d,%d) \n",x,y);
			printf("Charging Location = (%d,%d) \n",chargingX,chargingY);
			printf("Power = %.2f% \n", ((float)power/maxPower)*100);
			printf("Target Location = (%d,%d) \n",targetX,targetY);
		}
		int MoveToTargetXY(){
			if((x!=targetX)||(y!=targetY)){
				gotoxy(x,y);
				cout<<" ";
				if(x<targetX){
					x++;
					power-=5;
				}
				else{
					if(x>targetX){
						x--;
						power-=5;
					}
				}				
				if(y<targetY){
					y++;
					power-=5;
				}
				else{
					if(y>targetY){
						y--;
						power-=5;
					}
				}
			} 
			gotoxy(x,y);
			cout<<"R";
			gotoxy(targetX,targetY);
			cout<<"*";	
			gotoxy(chargingX,chargingY);
			cout<<"S";					
		}
		int MoveToChargingXY(){
			if((x!=chargingX)||(y!=chargingY)){
				gotoxy(x,y);
				cout<<" ";
				if(x<chargingX){
					x++;
				}
				else{
					if(x>chargingX){
						x--;
					}
				}				
				if(y<chargingY){
					y++;
				}
				else{
					if(y>chargingY){
						y--;
					}
				}
			} 
			gotoxy(x,y);
			cout<<"R";
			gotoxy(chargingX,chargingY);
			cout<<"S";
		}		
		void powerCharge(){
			power = power_test;
		}		
};	


class SweeperRobot:public Robot{
	private:
		int capacity;
		int maxCapacity;
	public:
		SweeperRobot(){
			capacity = 0;
			maxCapacity = 100;
		}
		SweeperRobot(int a,int b,int ca,int cb,int n){
			SetLocation(a,b);
			SetChargingLocation(ca,cb);
			maxCapacity = n;
		}
		void SetCapacity(int a){
			capacity = a;
		}
		void SetTargetLocation(int a,int b){
			Robot::SetTargetLocation(a,b);
		}		
		void Status(){
			gotoxy(0,20);
			Robot::Status(); 					
			printf("Capacity = %.2f% \n", ((1-(float)capacity/maxCapacity))*100);
		}
			
		void TrashIncrease(){
			capacity+=5; 
		}
		void print(){
			gotoxy(0,25);
			cout<<"capacity = "<<capacity;
		}
		
		void MoveToXY(){
			if(((1-(float)capacity/maxCapacity)*100)<5.0||((float)Powerval()/MaxPowerval()*100<10.0)){
				MoveToChargingXY();
			}
			else{
				Robot::MoveToTargetXY();
			}
		}
		void MakeTrash(){
			SetTargetLocation(rand()%80,rand()%15);
		}
		void Check(){
			if(Xval()==TXval()&&Yval()==TYval()){
				TrashIncrease();			
				MakeTrash();		
			}	
			if(Xval()==CXval()&&Yval()==CYval()){
				if(((1-(float)capacity/maxCapacity)*100)<5.0){
						capacity = 0;
					}
				if(((float)Powerval()/MaxPowerval()*100<10.0)){
						powerCharge();
				}
				MakeTrash();
			}										
		}
	
};
		
class Trash{
	private:
		int locationX;
		int locationY;
		int trashX[space_test]={};
		int trashY[space_test]={};
		int i=0;
		clock_t start;
		clock_t end;
	public:
		
		void MakingTrash(SweeperRobot *R){
			locationX = rand()%80;
			locationY = rand()%15;
			if(locationX == R->CXval() && locationY == R->CYval()){
				locationX = rand()%80;
				locationY = rand()%15;				
			}
			gotoxy(locationX,locationY);
			cout<<"*";
			while(trashX[i]==0&&trashY[i]==0){
					trashX[i] = locationX;
					trashY[i] = locationY;
					i++;
					break;
			}
		}
		void Coundown(SweeperRobot *R){
			double duration;
			end = clock();			
			duration = (double)(end-start)/CLOCKS_PER_SEC;		
			if(duration >= 1){
				start = clock();
				MakingTrash(R);
			}
		}
		void startClock(){
			start = clock();
		}	
		void trashCheck(SweeperRobot *R){
			for(int j=0;j<space_test;j++){				
				if(R->Xval()==trashX[j] && R->Yval()==trashY[j] ){
					R->TrashIncrease();
				}
			}			
		} 					
};

int main()
{
//	Robot robot1;
//	robot1.SetTargetLocation(20,20);
//	robot1.SetChargingLocation(10,10);
//	robot1.SetPower(150);
//	robot1.SetMaxPower(150);
//	robot1.Status();
//	
//	Robot robot2;
//	robot2.SetLocation(50,30);
//	robot2.SetTargetLocation(15,15);
//	robot2.SetChargingLocation(10,10);
//	robot2.SetPower(20);
//	robot2.SetMaxPower(100);	
//	robot2.Status();
	
	srand(time(NULL)); 
	SweeperRobot *SR = new SweeperRobot(0,14,0,14,100);
	Trash *trash = new Trash;	
	trash->startClock();
	SR->SetCapacity(0);
	SR->Status();
	SR->MakeTrash();
		

	while(1){	
//		robot1.MoveToTargetXY();
//		robot2.MoveToTargetXY();		
		SR->Check();	
		SR->MoveToXY();	 	
		SR->Status();
		trash->Coundown(SR);		
		trash->trashCheck(SR);		
		_sleep(150);
	}	
	return 0;
}
