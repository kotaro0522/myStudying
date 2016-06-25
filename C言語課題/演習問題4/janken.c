#include <stdio.h>
#include <time.h>

int main(){
	
	int janken[2];
	
	srand(time(NULL));
	
	printf("あなたの手を入力してください(1:パー、2:グー、3:チョキ)：");
	scanf("%d",&janken[0]);
	
	if(janken[0]<1||janken[0]>3){
		printf("エラー！\n");
		goto end;
	}
	
	if(janken[0]==1) printf("あなたの手:パー\n");
	if(janken[0]==2) printf("あなたの手:グー\n");
	if(janken[0]==3) printf("あなたの手:チョキ\n");
	
	janken[1]=rand()%3;
	
	if(janken[1]==0) printf("わたしの手:パー\n");
	if(janken[1]==1) printf("わたしの手:グー\n");
	if(janken[1]==2) printf("わたしの手:チョキ\n");
	
	janken[1]=janken[1]+1;
	
	if(janken[0]==janken[1]) printf("あいこです。\n");
	if(janken[0]==1&&janken[1]==2) printf("あなたが勝ちました。\n");
	if(janken[0]==1&&janken[1]==3) printf("私の勝ちです！\n");
	if(janken[0]==2&&janken[1]==1) printf("私の勝ちです！\n");
	if(janken[0]==2&&janken[1]==3) printf("あなたが勝ちました。\n");
	if(janken[0]==3&&janken[1]==1) printf("あなたが勝ちました。\n");
	if(janken[0]==3&&janken[1]==2) printf("私の勝ちです！\n");
	
  end:
	return 0;
}