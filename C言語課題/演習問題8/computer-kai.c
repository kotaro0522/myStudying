#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]){
	int i;
	char *s[100];
	char a[100];
	
	s[1]="Hello";
	s[2]="Whats your name?";//アポストロフィーを使うと上手く行かない・・・。
	s[3]="Whats your favorite food?";//同上
	
	strcat(a,argv[1]);
	
	for(i=2;i<argc;i++){//aにコマンドライン引数を連結、格納。
		strcat(a," ");
		strcat(a,argv[i]);
	}
	
	if(strcmp(s[1],a)==0) printf("Hello!\n");
	if(strcmp(s[2],a)==0) printf("I'm John.\n");
	if(strcmp(s[3],a)==0) printf("I love cucumber.\n");
	
	return 0;
}