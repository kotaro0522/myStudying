#include <stdio.h>
void printsum(int n);

int main(){
	int n;
	
	printf("整数を足したい回数を入力してください。\n");
	scanf("%d",&n);
	
	printsum(n);
	
	return 0;
}

void printsum(int n){
	int i,tmp;
	int total=0;
	
	for(i=0;i<n;i++){
		printf("整数を入力してください。\n");
		scanf("%d",&tmp);
		
		total=total+tmp;
	}
	
	printf("入力した整数の和:%d\n",total);
}