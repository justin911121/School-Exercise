#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n,s=0,a;
	cin>>n;
	a=sqrt(n);
	for(int i=1;i<=a;i++){
		if(n%i==0)
			s+=i;
	}
	if(s==1&&n!=1&&n!=0)
		cout<<"YES";
	else 
		cout<<"NO";
}
