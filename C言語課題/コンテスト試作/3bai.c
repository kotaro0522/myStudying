//数字を文字列をして処理すると得する事があるよという一例。

#include <stdio.h>

int main(){
	char s[1000];
	int t[1000];
	int i;
	int sum=0;
	int check;
	
	printf("任意の自然数を入力してください:");
	scanf("%s",s);
	for(i=0;i<100;i++){
		t[i]=s[i];
		if(t[i]==0) break;
		sum=sum+t[i]-'0';
	}
	printf("各位の数の合計:%d\n",sum);
	check=sum%3;
	if(check==0) printf("%sは3で割り切れます。\n",s);
	else printf("%sは3で割り切れません。\n",s);
	
	return 0;
}