#include <stdio.h>
#include <math.h>

double tanzaku(void);
double f(double x);

int main(){
	double ans;
	double x0=100;
	
	ans=tanzaku()*4;
	printf("単位円の面積の近似値は:%f\n",ans);
	return 0;
}

double tanzaku(void){
	double a=0;
	double b=1;
	double h=0.0001;
	double x;
	
	int num=(b-a)/h;
	double sum=0;
	int i;
	
	for(i=1;i<=num;i++){
		x=a+h*i;
		sum=sum+f(x)*h;
	}
	
	return sum;
}

double f(double x){
	double ans;
	
	ans=sqrt(1.0-x*x);
	
	return ans;
}