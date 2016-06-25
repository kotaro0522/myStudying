#include <stdio.h>

int gcd(int a,int b);

int main(){
	int a,b;
	int flag=1;
	int maxkoyaku;
	
	while(flag){
		printf("自然数a,bをスペース区切りで入力してください。(ただしa>bとする)\n");
		if(scanf("%d%d",&a,&b) != 2) scanf("%*s");
		
		if(b>0) if(a>b) flag=0;
	}
	
	maxkoyaku=gcd(a,b);
	
	printf("a,bの最大公約数は%d\n",maxkoyaku);
	
	return 0;
}

int gcd(int a,int b){
	int ans;
	
	if(a%b==0) ans=b;
	else ans=gcd(b,a%b);
	
	return ans;
}