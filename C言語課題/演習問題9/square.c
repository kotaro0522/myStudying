#include <stdio.h>

void square(int n);

int main(){
	int hen;
	int flag=1;
	
	while(flag){
		printf("3以上の整数を入力してください。\n");
		if(scanf("%d",&hen) != 1) scanf("%*s");//数字以外を入れたら空読みさせる。
		if(hen>3) flag=0;//3以上の整数ならオッケー。
	}
	
	square(hen);
	
	return 0;
}

void square(int n){
	int i,j;
	
	for(i=0;i<n;i++) printf("■");
	printf("\n");
	
	for(i=0;i<n-2;i++){
		printf("■");
		for(j=0;j<n-2;j++) printf("□");
		printf("■");
		printf("\n");
	}
	
	for(i=0;i<n;i++) printf("■");
	printf("\n");
}