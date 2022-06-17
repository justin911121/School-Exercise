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
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ����зǿ�X�˸m����N�X
	SetConsoleCursorPosition(hOut, pos);//��Ӥ޼Ƥ��O�O���w���ӵ���A�����m
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
//					PowerDecrease();
				}
				else{
					if(x>targetX){
						x--;
						power-=5;
//						PowerDecrease();
					}
				}				
				if(y<targetY){
					y++;
					power-=5;
//					PowerDecrease();
				}
				else{
					if(y>targetY){
						y--;
						power-=5;
//						PowerDecrease();
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
//					PowerDecrease();
				}
				else{
					if(x>chargingX){
						x--;
//						PowerDecrease();
					}
				}				
				if(y<chargingY){
					y++;
//					PowerDecrease();
				}
				else{
					if(y>chargingY){
						y--;
//						PowerDecrease();
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
//		void PowerDecrease(){
//			power-=5;
//			if(((float)power/maxPower*100.0)<10.0){
//				targetX = chargingX;
//				targetY = chargingY;
//			}
//		}

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
			if(Xval()==TXval()&&Yval()==TYval()&&Xval()!=CXval()&&Yval()!=CYval()){
//				MoveToChargingXY();
				TrashIncrease();
				gotoxy(0,40);
				cout<<"+";
				SetTargetLocation(CXval(),CYval());
			}	
			else if(((1-(float)capacity/maxCapacity)*100)<5.0||((float)Powerval()/MaxPowerval()*100<10.0)){
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
	public:
		void MakingTrash(SweeperRobot *R){
//			gotoxy(0,39);
//			cout<<i<<"/";
			locationX = rand()%80;
			locationY = rand()%15;
			if(locationX == R->CXval() && locationY == R->CYval()){
				locationX = rand()%80;
				locationY = rand()%15;				
			}
			gotoxy(locationX,locationY);
			cout<<"*";
//			gotoxy(0,41);
//			cout<<locationX<<"+";
			while(trashX[i]==0&&trashY[i]==0){
					trashX[i] = locationX;
//					gotoxy(0,44);
//					cout<<trashX[i]<<"@";
					trashY[i] = locationY;
//					gotoxy(0,45);
//					cout<<i<<"=";
					i++;
					break;
			}
//			gotoxy(0,46);
//			for(int j=0;j<100;j++){
//				cout<<trashX[j]<<",";
//			}
//			gotoxy(0,40);
			for(int j=0;j<space_test;j++){				
//				cout<<trashX[j]<<"* "<<endl;
				if(R->Xval()==trashX[j] && R->Yval()==trashY[j] ){
//					gotoxy(0,70);
//					cout<<"Xval() : "<<R->Xval()<<endl;
//					cout<<"[j] : "<<trashX[j];//�d�b�o�� 
					R->TrashIncrease();
				}
			}			
//			gotoxy(0,43);
//			cout<<"?";
//			getch();
			//i++;
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
	SR->SetCapacity(0);
	SR->Status();
	SR->MakeTrash();
	
	Trash *trash = new Trash;
	

	while(1){	
//		robot1.MoveToTargetXY();
//		robot2.MoveToTargetXY();
		SR->Check();
		SR->MoveToXY();	 	
		SR->Status();
//		SR->print();			
		trash->MakingTrash(SR);		
		_sleep(1000);
	}	
	return 0;
}
