#include <stdio.h>

int main(){
	
	int kinji=0;
	double answer=1;
	int i1=2;
	int i2=2;
	int j1=3;
	int j2=3;
	unsigned long k=3;
	unsigned long check;
	int flag=0;
	
	printf("(1");
	
	while(1){
		
		if(i1%2>0){
			printf("+1/%d",j1);
			j1=j1+2;
		}
		
		else{
			printf("-1/%d",j1);
			j1=j1+2;
		}
		
		i1++;
		
		if(flag) goto calculate;//計算パートへ
		
		k=k*j1;
		check=18446744073709551615UL/k;//unsigned long型の最大値を超えないようにチェック
		if(check<=j1+2) flag=1;//最大値超える一歩手前でフラグを立てる
		
	}
	
  calculate:
	while(1){
		
		if(i2%2>0){
			kinji=kinji+(k/j2);
			j2=j2+2;
		}
		
		else{
			kinji=kinji-(k/j2);
			j2=j2+2;
		}
		
		i2++;
		
		if(i1==i2){
			answer=answer+(double)kinji/(double)k;
			goto end;
		}
		
	}
	
	
  end:
	answer=answer*(double)4;
	printf(")*4\n=pi\n=%.15f\n",answer);//小数点以下を15桁で表示する
	
	return 0;
	
}
