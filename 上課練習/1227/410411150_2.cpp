//410411150 林彥辰 1A 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void fun1(char str[],int n){
	char str2[80]={};
	int count=0;
	for(int i=0;i<n;i++){
		str2[i]=str[n-i-1];
	}
	for(int j=0;j<n;j++){
		if(str[j]!=str2[j]){
			count=1;
			break;			
		}
	}
	if(count==0) printf("相同");
	else printf("不相同");
}
//int len(char str[]){
//	int i=0;
//	while(1){
//		if(str[i]==32) break;
//		i++;
//	}
//	return i;
//}

int main()
{
	char str[80]={};
	scanf("%s",&str);
	//printf("%s\n",str);
	fun1(str,strlen(str));
	
	return 0;
}
