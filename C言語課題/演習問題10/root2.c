#include <stdio.h>

double bisection(double a,double b);
double f(double x);

int main(){
	
	double a=0;
	double b=100;
	
	printf("二分法による√2の近似値は:%f\n",bisection(a,b));
	
	return 0;
}

double bisection(double a,double b){
	double c;
	int flag=1;
	double e=0.0001;
	
	while(flag){
		c=(a+b)/2;
		if(f(a)*f(c)<0) b=c;
		else a=c;
		if(b-a<e) flag=0;
	}
	
	return a;
}

double f(double x){
	double ans;
	
	ans=x*x-2;
	
	return ans;
}