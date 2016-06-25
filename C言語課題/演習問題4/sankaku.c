#include <stdio.h>
#include <math.h>

int main(){
	
	double a,b,c;
	double area;
	double s;
	double nakami;
	double check;
	
	printf("三角形の三辺の長さをスペース区切りで入力してください。\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	
	s=(a+b+c)/2;
	nakami=s*(s-a)*(s-b)*(s-c);
	area=sqrt(nakami);
			
			if(a>b) if(a+b>c&&a-b<c){
				printf("三角形の面積は%lf\n",area);
		goto end;
	}
	
	if(b>a) if(b+a>c&&b-a<c){
		printf("三角形の面積は%lf\n",area);
		goto end;
	}
	
	if(a==b) if((c<sqrt(2)*a+0.00001&&c>sqrt(2)*a-0.00001)||(c<sqrt(2)*b+0.00001&&c>sqrt(2)*b-0.00001)){ //double型の精度の悪さを考慮して、ある程度余裕(幅)を持たせてある。
		printf("三角形の面積は%lf\n",area);
		goto end;
	}
	
	printf("その三辺をもつ三角形は存在しません。\n");
	
  end:
	
	return 0;
}