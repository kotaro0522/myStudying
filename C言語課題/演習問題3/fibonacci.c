#include <stdio.h>

int main(){
	
	int n = 3;
	int a = 1;
	int b = 1;
	int sum;
	
	sum = a + b;
	
	printf("%d+%d=%d\n",a,b,sum);
	
	while(1){
		
		n++;
		
		a = sum;
		printf("%d+%d=",b,sum);
		sum = sum + b;
		printf("%d\n",sum);
		b = a;
		
		if(n==30) goto end;
		
	}
	
  end:
	return 0;
	
}