#include <stdio.h>

void complexMultiply2(double a,double b,double c,double d,double *e,double *f);

int main(){
	double a,b,c,d,e,f;
	double aa,bb;
	double bunbo;
	
	printf("(a+bi)/(c+di)を行います。\n");
	printf("a,b,c,dをスペース区切りで入力してください。\n");
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	
	complexMultiply2(a,b,c,d,&aa,&bb);
	bunbo=c*c+d*d;
	
	e=aa/bunbo;
	f=bb/bunbo;
	
	printf("(%f+%fi)/(%f+%fi)=%f+(%fi)\n",a,b,c,d,e,f);
	
	return 0;
}

void complexMultiply2(double a,double b,double c,double d,double *e,double *f){
	*e=a*c+b*d;
	*f=b*c-a*d;
}