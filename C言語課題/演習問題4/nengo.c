#include <stdio.h>

int main(){
	
	int seireki;
	int nengo;
	
	printf("西暦何年生まれですか？\n");
	scanf("%d",&seireki);
	
	if(seireki==1989) printf("昭和64年、平成1年生まれですね。\n");
	
	if(seireki<=2013&&seireki>1989){
		nengo=seireki-1988;
		printf("平成%d年生まれですね。\n",nengo);
	}
	if(seireki>=1926&&seireki<1989){
		nengo=seireki-1925;
		printf("昭和%d年生まれですね。\n",nengo);
	}
	if(seireki>2013) printf("ジョン・タイターさんですか？\n");
	
	if(seireki<1926) printf("長生きしてください。\n");
	
	return 0;
	
}