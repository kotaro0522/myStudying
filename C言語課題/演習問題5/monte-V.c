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
	double volume;
	
	srand(time(NULL));
	
	for(i=1;i<=100000;i++) darts();//十万回ダーツを投げる。ここの数を増やしていけば、精度は上がっていく。（ただし時間はかかる。）
	
	volume=8.0*hit/100000;
	
	printf("モンテカルロ法によると、半径１の球の体積は%fです。\n",volume);
	
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
	double z;
	
	x=zahyo();
	y=zahyo();
	z=zahyo();
	
	printf("ダーツ??[%d](%lf,%lf,%lf)\n",i,x,y,z);
	
	double check;
	double xy;
	
	xy=sqrt(x*x+y*y);
	check=sqrt(xy*xy+z*z);
	
	if(check<=1) hit++;
	
}