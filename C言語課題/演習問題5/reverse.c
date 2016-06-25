#include <stdio.h>

int main(){
	int i;
	int seisu[10],reverse[10];
	
	printf("整数を10個スペース区切りで入力してください:");
	scanf("%d%d%d%d%d%d%d%d%d%d",&seisu[0],&seisu[1],&seisu[2],&seisu[3],&seisu[4],&seisu[5],&seisu[6],&seisu[7],&seisu[8],&seisu[9]);
	printf("逆の順番:");
	
	for(i=0;i<10;i++){
		reverse[i]=seisu[9-i];
		printf("%d ",reverse[i]);
	}
	printf("\n");
	return 0;
}