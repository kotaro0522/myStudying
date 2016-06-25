#include <stdio.h>

double tanzaku(void);
double f(double x);

int main(){
	
	double x0=100;
	
	printf("家を出てt分後のひろし君の歩く速さが60-t^2[m]のとき、\n家を出てから6分間の間にひろし君が歩く道のりは%f[m]である。\n",tanzaku());
	return 0;
}

double tanzaku(void){
	double a=0;
	double b=6;
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
	
	ans=60-x*x;
	
	return ans;
}