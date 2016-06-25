#include <stdio.h>

int main(){
	
	double kinji=1;
	double answer;
	int i=2;
	int j=3;
	
	printf("(1");
	
	while(1){
		
		if(i%2>0){
			answer=kinji;
			kinji=kinji+(double)1/(double)j;
			printf("+1/%d",j);
			j=j+2;
		}
		
		else{
			answer=kinji;
			kinji=kinji-(double)1/(double)j;
			printf("-1/%d",j);
			j=j+2;
		}
		
		i++;
		
		if(j>=2147483646) goto end;//int型の制限を超えたら終了
	}
	
  end:
	answer=answer*(double)4;
	printf(")*4\n=pi\n=%.9f\n",answer);//小数点以下を9桁で表示する
	
	return 0;
	
}
