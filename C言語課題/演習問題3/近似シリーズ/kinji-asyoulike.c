#include <stdio.h>

int main(){
	
	int check;
	double kinji=1;
	double answer;
	unsigned long i=2;//1800京以上扱えるためほぼオーバーフローすることはないと思う
	unsigned long j=3;//ちなみに453億分の…まで計算するのにかかった時間は5時間以上(MacbookAir使用)
	
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
		
		if(i%1000000==0) {			//1000000項ごとに確認を入れる
			printf("\nまだやります…？ 止めるならxを入力後エンターキーを押してください。ちなみに入力した文字数が多ければ多い程チェックのタイミングが後になります。\n");
			check=getchar();
			if(check=='x') goto end;
		}
			
		if(j>=0&&j<5) goto end;//オーバーフローしたら終了
	}
	
  end:
	answer=answer*(double)4;
	printf("=pi/4\n\n(pi/4)*4\n=pi\n=%.15f\n",answer);//小数点以下を15桁で表示する
	printf("お疲れさまでした\n");
	
	return 0;
	
}
