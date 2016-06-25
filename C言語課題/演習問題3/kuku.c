#include <stdio.h>

int main(){
	
	int tate;
	int yoko;
	int seki;
	
	for(tate=1;tate<=9;tate++){
		for(yoko=1;yoko<=9;yoko++){
			
			seki=tate*yoko;
			
			printf("%02d ",seki);
			
		}
		printf("\n");
	}
	
	return 0;
	
}