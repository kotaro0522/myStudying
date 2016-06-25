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
		
		check1=kinji*100000000;//int型の制限上チェックの桁数は8ケタ
		check2=answer1*100000000;//同上
		
		if(j>=2147483646) goto end;//int型の制限を超えたら終了
		if(check1==check2) goto more;
	}
	
	while(1){
		
	  more:
		
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
		
		check1=(kinji-0.785398)*1000000000;//チェックの桁数は9桁
		check2=(answer1-0.785398)*1000000000;//同上
		
		if(j>=2147483646) goto end;//int型の制限を超えたら終了
		if(check1==check2) goto end;
		
	}
	
  end:
	answer1=answer1*(double)4;
	answer2=answer1*(double)100000000;//切り捨ての処理
	answer1=(double)answer2/(double)100000000;//同上
	printf(")*4\n=pi\n=%.8f\n",answer1);//小数点以下を8桁で表示する
	
	return 0;
	
}
