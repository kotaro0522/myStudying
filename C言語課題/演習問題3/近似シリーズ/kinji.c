#include <stdio.h>

int main(){
	
	double kinji=1;
	double answer1;
	int answer2;
	int i=2;
	int j=3;
	int check1;
	int check2;
	
	printf("(1");
	
	while(1){
		
		if(i%2>0){
			answer1=kinji;
			kinji=kinji+(double)1/(double)j;
			printf("+1/%d",j);
			j=j+2;
		}
		
		else{
			answer1=kinji;
			kinji=kinji-(double)1/(double)j;
			printf("-1/%d",j);
			j=j+2;
		}
		
		i++;
		
		check1=kinji*(double)100000000;//int型の制限上チェックの桁数は8ケタ
		check2=answer1*(double)100000000;//同上
		
		if(j>=2147483646) goto end;//int型の制限を超えたら終了
		if(check1==check2) goto end;
	}
	
  end:
	answer1=answer1*(double)4;
	answer2=answer1*(double)10000000;//切り捨ての処理
	answer1=(double)answer2/(double)10000000;//同上
	printf(")*4\n=pi\n=%.7f\n",answer1);//小数点以下を7桁で表示する
	
	return 0;
	
}