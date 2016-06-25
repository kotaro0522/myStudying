#include <stdio.h>

int main(){
	
	int n = 1;
	
	while(1){
		
		if(n%3==1){
			if(n%5==2){
				if(n%7==3){
					printf("3で割ると余りが1で、\n");
					printf("5で割ると余りが2で、\n");
					printf("7で割ると余りが3の自然数の内、最小の数は%d\n",n);
					
					goto end;
				}
			}
		}
		
		n++;
			}
	
  end:
	return 0;
	
}