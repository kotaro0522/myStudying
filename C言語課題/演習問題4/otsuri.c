#include <stdio.h>

int main(){
	
	int n;
	int otsuri;
	int hyaku;
	int ju;
	int ichi;
	
	printf("何円の物を買いますか？\n");
	scanf("%d",&n);
	
	if(n<0||1000<n) {
		printf("金額がおかしいです\n");
		goto end;
	}
	
	printf("%d円の買い物をして1000円札を出した時のおつりは",n);
	
	otsuri=1000-n;
	
	printf("%d円です\n",otsuri);
	//以下硬貨の種類を表示
	//1がついてる硬貨の処理がめんどい。もっとスマートな方法があるかも。
	while(1){
	if(otsuri>=500){
		printf("500円玉が1枚\n");
		otsuri=otsuri-500;
	}
	else if(otsuri>=100){
	  back1:
		hyaku++;
		otsuri=otsuri-100;
		if(otsuri>=100) goto back1;
		printf("100円玉が%d枚\n",hyaku);
	}
	else if(otsuri>=50){
		printf("50円玉が1枚\n");
		otsuri=otsuri-50;
	}
	else if(otsuri>=10){
	  back2:
		ju++;
		otsuri=otsuri-10;
		if(otsuri>=10) goto back2;
		printf("10円玉が%d枚\n",ju);
	}
	else if(otsuri>=5){
		printf("5円玉が1枚\n");
		otsuri=otsuri-5;
	}
	else if(otsuri>=1){
	  back3:
		ichi++;
		otsuri=otsuri-1;
		if(otsuri>=1) goto back3;
		printf("1円玉が%d枚\n",ichi);
		}
		else break;
	}
	  end:
		
		return 0;
	}