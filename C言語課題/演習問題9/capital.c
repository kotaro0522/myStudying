#include <stdio.h>
#include <string.h>

char capital(char c);

int main(){
	int i=0;
	char moji,c[100];
	
	while(1){
		int flag=1;
		memset(c,0,sizeof(c));
		if(i>0) scanf("%*c");//改行を空読み。
		
		printf("アルファベットを一文字入力してください。\n");
		scanf("%[^\n]",c);
		if(c[1] != 0) flag=0;
		
		if(flag) if(c[0]>64 && c[0]<91 || c[0]>96 && c[0]<123) break;
		i++;
	}
	
	moji=capital(c[0]);
	
	printf("%c\n",moji);
	
	return 0;
}

char capital(char c){
	char after;
	
	if(c>96 && c<123) after=c-32;
	else after=c;
	
	return after;
}