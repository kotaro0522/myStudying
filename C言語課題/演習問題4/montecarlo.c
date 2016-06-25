#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

int i;
int hit=0;



void darts();
double zahyo();

int main(){
	double area;
	
	srand(time(NULL));
	
	for(i=1;i<=100000;i++) darts();//十万回ダーツを投げる。ここの数を増やしていけば、精度は上がっていく。（ただし時間はかかる。）
	
	area=4.0*hit/100000;
	
	printf("モンテカルロ法によると、半径１の円の面積は%fです。\n",area);
	
	return 0;
}

double zahyo(){
	double n;
	int fugo;
	
	fugo=rand()%2;
	
	if(fugo==0) n=rand()/(RAND_MAX+1.0);
	else n=-(rand()/(RAND_MAX+1.0));
	
	return n;
}

void darts(){
	double x;
	double y;
	
	x=zahyo();
	y=zahyo();
	
	printf("ダーツ[%d](%lf,%lf)\n",i,x,y);
	
	double check;
	check=sqrt(x*x+y*y);
	
	if(check<=1) hit++;
	
}