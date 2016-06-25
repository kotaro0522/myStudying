#include <stdio.h>
#include <string.h>

int goukei(char name[],int length){
	int i;
	int total=0;
	
	for(i=0;i<length;i++) total=total+name[i];
	
	return total;
}

int main(){
	FILE *f=fopen("aisho.txt","a");//ファイル出力するようにした。
	
	char name[2][100];
	int length;
	double a,b,aisho;
	
	printf("一人目の名前:");
	fprintf(f,"一人目の名前:");//出力
	scanf("%s",name[0]);
	fprintf(f,"%s\n",name[0]);//出力
	
	length=strlen(name[0]);
	
	a=goukei(name[0],length);
	
	printf("二人目の名前:");
	fprintf(f,"二人目の名前:");//出力
	scanf("%s",name[1]);
	fprintf(f,"%s\n",name[1]);//出力
	
	length=strlen(name[1]);
	
	b=goukei(name[1],length);
	
	if(a>b) aisho=1.0-(a-b)/a;
	else aisho=1.0-(b-a)/b;
	
	printf("二人の相性度は%.9f\n",aisho);
	fprintf(f,"二人の相性度は:%.9f\n",aisho);//出力
	
	fprintf(f,"\n");//出力
	
	fclose(f);
	
	return 0;
}