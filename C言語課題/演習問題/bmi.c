#include <stdio.h>
int main(){

	double a;
	double b;
	double bmi;

	a=1.68;
	b=60;
	bmi=b/(a*a);

	printf("身長168cm、体重60kgの人のBMIは%fです。\n", bmi);

	return 0;
}