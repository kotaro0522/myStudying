#include <stdio.h>
#include <time.h>

int main(){
	
	int check;
	int i=0;
	int n[2];
	int card[2];
	srand(time(NULL));
	
	n[1]=-1;
	
	while(1){
	
	n[0]=rand()%13;//カードの絵柄は13通り
	
	if(0<=n[0]&&n[0]<=7){//2~9は2を足して処理
		card[0]='0'+n[0]+2;
	}
	
	else{//柄+A+10は一個ずつ処理
		switch(n[0]){
		  case 8:
			card[0]='X';
			break;
		  case 9:
			card[0]='J';
			break;
		  case 10:
			card[0]='Q';
			break;
		  case 11:
			card[0]='K';
			break;
		  case 12:
			card[0]='A';
			break;
		  default:
			printf("エラー！\n");
		}
	}
		
		if(card[0]==88){//めんどいけど10だけ別個で処理
			printf("めくられたカードは10です。\n");
			goto hantei1;
		}
		printf("場のカードは%cです。\n",card[0]);
			
	  hantei1:
		if(check==1){
		if(n[1]>0){//2回目以降判定
			if(n[0]>n[1]){
				printf("あなたの勝ちです。\n");
				i++;
			}
			else if(n[0]==n[1]) printf("引き分けです。\n");
			else{
				printf("あなたの負けです。\n");
				goto end;
			}
			}
		}
		if(check==2){
			if(n[0]<n[1]){
				printf("あなたの勝ちです。\n");
				i++;
			}
			else if(n[0]==n[1]) printf("引き分けです。\n");
			else{
				printf("あなたの負けです。\n");
				goto end;
			}
		}
			
	  more1:
	printf("Highなら1をLowなら2を入力してエンターを押してください。\n");
		
		scanf("%d", &check);//入力を取る。
		if(check != 1 && check != 2) goto more1;
			
			//以下2回目(内容は全く一緒)
			
	n[1]=rand()%13;//カードの絵柄は13通り
	
	if(0<=n[1]&&n[1]<=7){//2~9は2を足して処理
		card[1]='0'+n[1]+2;
	}
	
	else{//柄+A+10は一個ずつ処理
			switch(n[1]){
		  case 8:
			card[1]='X';
			break;
		  case 9:
			card[1]='J';
			break;
		  case 10:
			card[1]='Q';
			break;
		  case 11:
			card[1]='K';
			break;
		  case 12:
			card[1]='A';
			break;
		  default:
			printf("エラー！\n");
		}
	}
		
		if(card[1]==88){//めんどいけど10だけ別個で処理
			printf("めくられたカードは10です。\n");
				goto hantei2;
			}
		printf("めくられたカードは%cです。\n",card[1]);
			
	  hantei2:
		if(check==1){
		if(n[1]>n[0]){
			printf("あなたの勝ちです。\n");
			i++;
		}
		else if(n[1]==n[0]) printf("引き分けです。\n");
			else{
				printf("あなたの負けです。\n");
				goto end;
			}
		}
		if(check==2){
			if(n[1]<n[0]){
			printf("あなたの勝ちです。\n");
			i++;
		}
		else if(n[1]==n[0]) printf("引き分けです。\n");
			else{
				printf("あなたの負けです。\n");
				goto end;
			}
		}
			
		
	  more2:
	printf("Highなら1をLowなら2を入力してエンターを押してください。\n");
	
		scanf("%d", &check);
		if(check != 1 && check != 2) goto more2;
		
	}
	
  end:
	if(i>0) printf("あなたは%d回勝ちました。\n",i);
	else printf("一度も勝てませんでしたね。ドンマイです。\n");
	printf("お疲れさまでした。\n");
	return 0;
}
	