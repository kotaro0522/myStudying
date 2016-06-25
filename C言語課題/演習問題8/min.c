#include <stdio.h>

double min5(double a,double b,double c,double d,double e);

int main(){
	double x1,x2,x3,x4,x5;
	double min;
	
	printf("スペース区切りで5個数字をいれてください。\n");
	scanf("%lf%lf%lf%lf%lf",&x1,&x2,&x3,&x4,&x5);
	min=min5(x1,x2,x3,x4,x5);
	printf("最小値:%f\n",min);
	
}

double min5(double a,double b,double c,double d,double e){
	double min;
	if(a-b>0){
		if(b-c>0){
			if(c-d>0){
				if(d-e>0) min=e;
				else min=d;
			}
			else{
				if(c-e>0) min=e;
				else min=c;
			}
		}
		else if(b-d>0){
			if(d-e>0) min=e;
			else min=d;
		}
		else{
			if(b-e>0) min=e;
			else min=b;
		}
	}
	else if(a-c>0){
		if(c-d>0){
			if(d-e>0) min=e;
			else min=d;
		}
		else{
			if(c-e>0) min=e;
			else min=c;
		}
	}
	else if(a-d>0){
		if(d-e>0) min=e;
		else min=d;
	}
	else{
		if(a-e>0) min=e;
		else min=a;
	}
	return min;
}