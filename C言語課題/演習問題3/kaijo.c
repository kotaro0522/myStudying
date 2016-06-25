#include <stdio.h>

int main(){
	
	int i=1;
	int kaijo1=1;
	int kaijo2=1;
	
	while(1){
		kaijo2=kaijo1*i;
				printf("%d!=%d\n",i,kaijo2);
		
		if(kaijo2/i!=kaijo1) goto end;
		
		kaijo1=kaijo2;
		
		i++;
		
	}
	
  end:
	printf("int型で表現できる最大の階乗は%d!\n",i);
	
	return 0;
	
}