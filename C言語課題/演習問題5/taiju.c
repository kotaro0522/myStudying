#include <stdio.h>

int main(){
	int i;
	double sum=0;
	double ave;
	double x[10];
	
	
	
	for(i=0;i<sizeof(x)/sizeof(x[0]);i++){
		printf("体重を入力してください(kg)");
		scanf("%lf",&x[i]);
		sum=sum+x[i];
	}
	
	ave=sum/(sizeof(x)/sizeof(x[0]));
	
	
	printf("\n10人の平均体重:%f(kg)\n",ave);
	
	return 0;
}