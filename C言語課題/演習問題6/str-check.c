#include <stdio.h>
#include <string.h>

int main(){
	
	char str1[100],str2[100];
	int length1,length2,i;
	int flag=1;
	
	printf("一つ目の文字列を入力してください。:");
	scanf("%s",str1);
	length1=strlen(str1);
	
	printf("二つ目の文字列を入力してください。:");
	scanf("%s",str2);
	length2=strlen(str2);
	
	if(length1==length2){
		for(i=0;i<length1;i++){
			if(str1[i]!=str2[i]){
				if(str1[i]>64&&str1[i]<91&&str2[i]>96&&str2[i]<123){//大文字小文字の区別をなくしてチェック
					if(str1[i]+32!=str2[i]){
						flag=0;
						break;
					}
				}
				else if(str2[i]>64&&str2[i]<91&&str1[i]>96&&str1[i]<123){//同上
					if(str2[i]+32!=str1[i]){
						flag=0;
						break;
					}
				}
				else{
					flag=0;
					break;
				}
			}
		}
		if(flag) printf("入力した文字列は一致しています。\n");
		else printf("入力した文字列は一致していません。\n");
	}
	else printf("入力した文字列は一致していません。\n");
	
	return 0;
}
	