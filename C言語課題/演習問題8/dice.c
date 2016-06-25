#include <stdio.h>
#include <time.h>

int dice(int n);

int main(){
	int n;
	int saikoro;
	
	printf("サイコロの面数を入力してください。\n");
	scanf("%d",&n);
	
	saikoro=dice(n);
	
	printf("サイコロの目は%dです。\n",saikoro);
	
	return 0;
}

int dice(int n){
	int i;
	
	srand(time(NULL));
	
	i=rand()%n;
	
	return i+1;
}