#include <stdio.h>

int main(){
	int a;
	int i;
	int flag=1;//基本は素数。
	
	printf("自然数を入力:");
	scanf("%d",&a);
	
	for(i=2;i<a;i++){//a=1ならループはスルーされる。
			if(a%i==0) flag=0;//割り切れたら素数じゃない。
		}
	
	if(flag) printf("%dは素数です。\n",a);
	
	else printf("%dは素数ではありません。\n",a);
	
	return 0;
}