#include <stdio.h>

int main(){
	
	double kinji=1;
	double answer;
	unsigned long i=2;
	unsigned long j=3;
	
	printf("(1");
	
	while(1){
		
		if(i%2>0){
			answer=kinji;
			kinji=kinji+(double)1/(double)j;
			printf("+1/%lu",j);
			j=j+2;
		}
		
		else{
			answer=kinji;
			kinji=kinji-(double)1/(double)j;
			printf("-1/%lu",j);
			j=j+2;
		}
		
		i++;
		
		if(j>=0&&j<5) goto end;//オーバーフローしたら終了
	}
	
  end:
	answer=answer*(double)4;
	printf(")*4\n=pi\n=%.15f\n",answer);//小数点以下を15桁で表示する
	
	return 0;
	
}
