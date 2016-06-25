#include <stdio.h>
#include <string.h>

void kyohaku(void);

int main(){
	
	kyohaku();
	
	return 0;
}

void kyohaku(void){
	char s[100];
	char yes[]="yes";
	int flag=1;
	
	while(flag){
		printf("プログラミングできますか？\n");
		printf("できるならyesとお答えください。\n");
		scanf("%s",s);
		
		if(strcmp(s,yes)==0) flag=0;
	}
	
	printf("それは良かったです。\n");
}