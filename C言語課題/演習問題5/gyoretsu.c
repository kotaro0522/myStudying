#include <stdio.h>

int main(){
	double gyoretsu[3][3];
	double shiki;
	
	printf("1行目の３つの要素をスペース区切りで入力してください:");
	scanf("%lf%lf%lf",&gyoretsu[0][0],&gyoretsu[0][1],&gyoretsu[0][2]);
	
	printf("2行目の３つの要素をスペース区切りで入力してください:");
	scanf("%lf%lf%lf",&gyoretsu[1][0],&gyoretsu[1][1],&gyoretsu[1][2]);
	
	printf("3行目の３つの要素をスペース区切りで入力してください:");
	scanf("%lf%lf%lf",&gyoretsu[2][0],&gyoretsu[2][1],&gyoretsu[2][2]);
	
	shiki=(gyoretsu[0][0]*gyoretsu[1][1]*gyoretsu[2][2]+gyoretsu[1][0]*gyoretsu[1][2]*gyoretsu[2][0]+gyoretsu[0][2]*gyoretsu[1][0]*gyoretsu[2][1])
			-(gyoretsu[0][0]*gyoretsu[1][2]*gyoretsu[2][1]+gyoretsu[0][1]*gyoretsu[1][0]*gyoretsu[2][2]+gyoretsu[0][2]*gyoretsu[1][1]*gyoretsu[2][0]);
	
	printf("行列式は%lfです。\n",shiki);
	
	return 0;
}