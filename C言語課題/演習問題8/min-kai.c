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
	double ave,min;
	int i=0;
	int flag1=0;
	int flag2=0;
	int flag3=0;
	int flag4=0;
	int flag5=0;
	
	ave=(a+b+c+d+e)/5;//平均を出す。
	
	while(1){
		if(ave>a) flag1=1;
		if(ave>b) flag2=1;
		if(ave>c) flag3=1;
		if(ave>d) flag4=1;
		if(ave>e) flag5=1;
		
		ave=0;
		i=flag1+flag2+flag3+flag4+flag5;
		
		if(i==1) break;//1個まで絞れたら終了。
		
		if(flag1) ave=ave+a;
		if(flag2) ave=ave+b;
		if(flag3) ave=ave+c;
		if(flag4) ave=ave+d;
		if(flag5) ave=ave+e;
		
		ave=ave/i;
		
		//以下フラグの初期化。
		flag1=0;
		flag2=0;
		flag3=0;
		flag4=0;
		flag5=0;
	}
	
	if(flag1) min=a;
	if(flag2) min=b;
	if(flag3) min=c;
	if(flag4) min=d;
	if(flag5) min=e;
	
	return min;
}