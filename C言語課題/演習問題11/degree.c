#include <stdio.h>
#include <math.h>

double degree(double a[],double b[]);

int main(){
	int flag=1;
	double a[100];
	double b[100];
	
	printf("ベクトルxのx成分、y成分をスペース区切りで入力してください。\n");
	
	while(flag){
		if(scanf("%lf%lf",&a[0],&a[1]) != 2) scanf("%*s");
		else flag=0;
	}
	
	flag=1;
	printf("ベクトルyのx成分、y成分をスペース区切りで入力してください。\n");
	
	while(flag){
		if(scanf("%lf %lf",&b[0],&b[1]) != 2) scanf("%*s");
		else flag=0;
	}
	
	printf("ベクトルx(%f,%f)とベクトルy(%f,%f)のなす角は%f度\n",a[0],a[1],b[0],b[1],degree(a,b));
	
	return 0;
}

double degree(double a[],double b[]){
	double bunshi,bunbo,rad,deg;
	
	bunshi=a[0]*b[0]+a[1]*b[1];
	bunbo=sqrt(a[0]*a[0]+a[1]*a[1])*sqrt(b[0]*b[0]+b[1]*b[1]);
	
	rad=acos(bunshi/bunbo);
	
	deg=rad/M_PI*180.0;
	
	return deg;
}