#include <stdio.h>

int main(){
	double vector1[3];
	double vector2[3];
	double naiseki;
	
	printf("1個目の3次元ベクトル(x,y,z)をスペース区切りで入力してください:");
	scanf("%lf%lf%lf",&vector1[0],&vector1[1],&vector1[2]);
	
	printf("2個目の3次元ベクトル(x,y,z)をスペース区切りで入力してください:");
	scanf("%lf%lf%lf",&vector2[0],&vector2[1],&vector2[2]);
	
	
	naiseki=vector1[0]*vector2[0]+vector1[1]*vector2[1]+vector1[2]*vector2[2];
	
	printf("内積は%lfです。\n",naiseki);
	
	return 0;
}