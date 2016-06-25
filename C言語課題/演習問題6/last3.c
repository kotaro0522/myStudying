#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	int length;
	
	printf("3文字以上の文字列を入力してください:");
	scanf("%s",s);
	
	length=strlen(s);
	
	printf("最後尾の3文字:%c%c%c\n",s[length-3],s[length-2],s[length-1]);
	
	return 0;
}