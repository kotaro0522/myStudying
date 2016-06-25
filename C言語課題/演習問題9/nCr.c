#include <stdio.h>

int combination(int n,int r);

int main(){
	int flag=1;
	int n,r;
	int ans;
	
	while(flag){
		printf("nCrのnとrをスペース区切りで入力してください。\n");
		if(scanf("%d%d",&n,&r) != 2) scanf("%*s");
		
		if(n>0 && r>=0) flag=0;
	}
	
	ans=combination(n,r);
	
	printf("%dC%d=%d\n",n,r,ans);
	
	return 0;
}

int combination(int n,int r){
	int ans;
	
	if(n==r) ans=1;
	else if(r==0) ans=1;
	else ans=combination(n-1,r-1)+combination(n-1,r);
	
	return ans;
}