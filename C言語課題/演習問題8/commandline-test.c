#include <stdio.h>
#include <string.h>

int main(int argc,char *argv[]){
	char *s1="Hello";//ポインタ変数には文字列をぶちこめる。
	//char s2="Hello";//これは通らない。
	char a='H';
	char s[100];
	//char x[100][];//この書き方はアウト。
	char *t[100];//コマンドライン引数と同じ書き方。結局これを使うのが一番スマートか。
	
	
	//s[1]="Dame!\n";//この書き方はダメ。
	//printf("%s\n",s[1]);//同上
	printf("%s\n",argv[1]);//一見、上と同じような書き方なのにこっちはOK.なぜならargvは二次元配列もとい配列の要素それぞれがポインタ扱いだから。
	t[1]="OK";//これはオッケー。
	printf("%s\n",t[1]);//同上
	
	if(strcmp(t[1],argv[1])==0) printf("Great!\n");//forとかでループさせやすい。すっきり書ける。
	
	
	/*
	printf("%s\n",argv[1]);//出力される文字列は同じ
	printf("%s\n",s1);//同上
	
	printf("%c\n",*argv[1]);//出力される文字はみんな同じ
	printf("%c\n",*s1);//同上
	printf("%c\n",a);//同上
	
	printf("%p\n",argv[1]);//アドレスはバラバラ
	printf("%p\n",s1);//同上
	printf("%p\n",&a);//同上
	*/
	
	/*
	if(*s1==*argv[1]) printf("good!\n");//通常変数モードだから最初の一文字しか比較されてない
	if(s1==argv[1]) printf("NO!");//両者のアドレスは異なるものだからダメ。
	if(strcmp(s1,argv[1])==0) printf("OK!\n");//文字列として比較しているからOK.
	*/
	
	return 0;
}