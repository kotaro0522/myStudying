#include <stdio.h>

int main(){
	char letter;
	int type=0;
	
	printf("文字を1文字入力してください:");
	scanf("%c",&letter);
	
	if('A'<=letter && letter<='Z') type=1; //大文字判定
	else if('a'<=letter && letter<='z') type=2; //小文字判定
	else type=3; //その他
	
	switch(type){
				case 1:
				letter=letter+32; //小文字に変換
		printf("変換:%c\n",letter); 
		break;
		
	  case 2:
		letter=letter-32; //大文字に変換
		printf("変換:%c\n",letter);
		break;
		
	  case 3:
		printf("アルファベットを入力してください。\n");
		break;
		
	  default:
		printf("エラー！\n");
	}
	
	return 0;
}