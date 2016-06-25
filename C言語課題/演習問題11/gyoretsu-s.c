#include <stdio.h>

void matrixProduct(double a[][3],double b[][3],double c[][3]);

int main(){
	int i,j;
	double a[100][3];
	double b[100][3];
	double c[100][3];
	
	matrixProduct(a,b,c);
	
	printf("行列cは\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%f ",c[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}

void matrixProduct(double a[][3],double b[][3],double c[][3]){
	int i,j;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("行列aの%d*%d成分を入力してください。\n",i+1,j+1);
			scanf("%lf",&a[i][j]);
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("行列bの%d*%d成分を入力してください。\n",i+1,j+1);
			scanf("%lf",&b[i][j]);
		}
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			c[j][i]=a[j][0]*b[0][i]+a[j][1]*b[1][i]+a[j][2]*b[2][i];
		}
	}
	
}