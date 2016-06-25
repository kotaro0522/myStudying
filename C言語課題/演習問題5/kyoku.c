#include <stdio.h>
#include <math.h>

int main(){
	double r;
	double theta;
	double x;
	double y;
	
	printf("rを入力してください:");
	scanf("%lf",&r);
	
	printf("θを入力してください:");
	scanf("%lf",&theta);
	
	x=r*cos(theta*M_PI/180);
	y=r*sin(theta*M_PI/180);
	
	printf("(x,y)=(%lf,%lf)\n",x,y);
	
	return 0;
}