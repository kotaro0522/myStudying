#include <stdio.h>
#include <string.h>

int checkKyudai(char s[]);

int main(){
	char s[100];
	
	printf("文字列を入力してください。\n");
	scanf("%s",s);
	
	printf("%d\n",checkKyudai(s));
	
	return 0;
}

int checkKyudai(char s[]){
	int length,i;
	int ans=0;
	
	length=strlen(s);
	
	for(i=0;i<length;i++){
		if(s[i]=='K'){
			if(s[i+1]=='y'){
				if(s[i+2]=='u'){
					if(s[i+3]=='d'){
						if(s[i+4]=='a'){
							if(s[i+5]=='i'){
								ans=1;
								break;
							}
						}
					}
				}
			}
		}
	}
	
	return ans;
}