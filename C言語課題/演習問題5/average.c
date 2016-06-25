#include <stdio.h>

int main(){
	int i;
	int sum=0;
	int ave;
	int x[]={168,150,149,180,177,151,186,163,164,170};
	
	printf("配列xの要素:");
	
	for(i=0;i<sizeof(x)/sizeof(x[0]);i++){
		sum=sum+x[i];
		printf("%d, ",x[i]);
	}
	
	ave=sum/(sizeof(x)/sizeof(x[0]));
	
	
	printf("\n配列xの要素の平均値:%d\n",ave);
	
	return 0;
}