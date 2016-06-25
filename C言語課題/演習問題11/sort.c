#include <stdio.h>

void sortKojun(int a[]);

int main(){
	int a[100],i;
	
	printf("何個数字を入力しますか？\n");
	scanf("%d",&a[99]);
	
	for(i=0;i<a[99];i++){
		printf("%d個目の数字を入力してください。(整数で)\n",i+1);
		scanf("%d",&a[i]);
	}
	
	sortKojun(a);
	
	return 0;
}

void sortKojun(int a[]){
	int sum,tmp;
	int i=0;
	int flag=1;
	
	while(flag){
		for(i=0;i<a[99];i++){//数字を並び替え。
			if(a[i]<a[i+1]){
				tmp=a[i];
				a[i]=a[i+1];
				a[i+1]=tmp;
			}
		}
		for(i=0;i<a[99];i++){//並び替えができてるかチェック。
			if(a[i]<a[i+1]) break;//できてなかったらブレイク。
			else if(i+2 == a[99]) flag=0;//最後まで大丈夫だったらループ終わり。
		}
	}
	
	for(i=0;i<a[99];i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	
}