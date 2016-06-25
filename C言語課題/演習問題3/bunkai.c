#include <stdio.h>

int main(){
	
	int i=1;
	int bunkai=415120814;
	printf("%d=",bunkai);
	
	while(1){
		
		i=i+1;//iから1ずつ足していく
		
		if(bunkai%i==0){ //割り切れたら計算、表示
			
			printf("%d",i);
			
			bunkai=bunkai/i;
			
			if(bunkai<2) goto end;//割れなくなったら*付けられる前に終了
			printf("*");
			
		}
		
	}
	
  end:
	printf("\n");
	return 0;
	
}