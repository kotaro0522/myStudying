#include <stdio.h>

unsigned long Hanoi(unsigned long n);

int main(){
	unsigned long n,ans;//unsined long でも63枚までしか無理。
	int flag=1;
	
	while(flag){
		printf("ハノイの塔！\n");
		printf("動かす円盤の枚数を自然数で入力してください。\n");
		if(scanf("%lu",&n) != 1) scanf("%*s");
		
		if(n>0) flag=0;
	}
	
	ans=Hanoi(n);
	
	printf("%lu枚の円盤を動かすのにかかる回数は%lu\n",n,ans);
	
	return 0;
}

unsigned long Hanoi(unsigned long n){
	unsigned long ans;
	
	if(n==1) ans=1;
	else ans=2*Hanoi(n-1)+1;
	
	return ans;
}