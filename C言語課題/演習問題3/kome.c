#include <stdio.h>

int main(){
	
	int i;
	double kome =  0.00000002;
	double total = 0;
	
	for(i=1;i <= 30;i++){
		
		total = total + kome;
		kome = kome * 2;
		
	}
	
	printf("米一粒の重さを20mgとすると、\n");
	printf("初日は米一粒、翌日は二粒、次の日は四粒・・・と繰り返していくと、\n");
	printf("30日間で獲得する米粒の重さは%fトンである。\n",total);
	
	return 0;
}