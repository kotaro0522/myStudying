#include <stdio.h>
#include <math.h>

double tanzaku(void);
double f(double x);

int main(){
	double ans;
	double x0=100;
	
	ans=tanzaku();
	printf("∮[0→a]1/{1+sin(x/2)}dx-2=0を満たすaは:%f\n",ans);
	return 0;
}

double tanzaku(void){
	int flag=1;
	double ans;
	double i=1.0;
	double h=0.0001;
	double sum=0;
	
	while(flag){
		sum=sum+f(h*i)*h;
		if(sum>2.0) flag=0;
		i=i+1.0;
	}
	ans=h*(i-1.0);
	return ans;
}

double f(double x){
	double ans;
	
	ans=1/(1+sin(x/2));
	
	return ans;
}