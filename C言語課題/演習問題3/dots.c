#include <stdio.h>

int main(){
	
	int i;
	
	
	for(i = 1;i <= 20;i++){
		
		int j=1;
		
		for(;;){
			printf("*");
			
			if(j==i) goto end;
			
			j++;
			
		}
	  end:
		printf("\n");
	}
	
	return 0;
	
}