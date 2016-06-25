#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

int i;
int hit=0;


double zahyo();

int main(){
	double area;
	
	FILE *f=fopen("darts.txt","w");
	FILE *g=fopen("darts_out.txt","w");
	
	srand(time(NULL));
	
	for(i=1;i<=100000;i++){
		//もともとこの中身は関数にしてたけど上手く行かなかったので変更。
		double x;
		double y;
	
	x=zahyo();
	y=zahyo();
	
	printf("ダーツ[%d](%lf,%lf)\n",i,x,y);
	
	double check;
	check=sqrt(x*x+y*y);
	
	if(check<=1){
		hit++;
		fprintf(f,"%lf,%lf\n",x,y);
	}
	else{
		fprintf(g,"%lf,%lf\n",x,y);
		}
		//ここまでもともと関数。
	}
	
	area=4.0*hit/100000;
	
	printf("モンテカルロ法によると、半径１の円の面積は%fです。\n",area);
	
		fclose(f);
		fclose(g);
	
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