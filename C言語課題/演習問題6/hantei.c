#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	int length,i;
	int flag=1;
	
	printf("文字列を入力してください:");
	scanf("%s",s);
	
	length=strlen(s);
	
	for(i=0;i<length;i++){
		if(s[i]=='g'){
			if(s[i+1]=='e'){
				if(s[i+2]=='i'){
					if(s[i+3]=='j'){
						if(s[i+4]=='o'){
							printf("この文字列はgeijoを含んでいます。\n");
							flag=0;
							break;
						}
					}
				}
			}
		}
	}
	
	if(flag) printf("この文字列はgeijoを含んでいません。\n");
	
	return 0;
}