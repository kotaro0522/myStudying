#include <stdio.h>
int main(){

	int year;
	int uruu1;
	int uruu2;
	int uruu3;

	year=1948;
	uruu1=year%400;
	uruu2=year%4;
	uruu3=year%100;

	if(uruu1==0){
	printf("%d年はうるう年です。\n", year);
	}
	else{
		if(uruu2>0){
		printf("%d年はうるう年ではありません。\n", year);
		}
		
		else if(uruu3>0){
		printf("%d年はうるう年です。\n", year);
		}

		else{
		printf("%d年はうるう年ではありません。\n", year);
		}
	
	}

	return 0;

}