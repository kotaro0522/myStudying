#include <stdio.h>

int main(){
	
	int time[4];
	
	printf("日と時間と分と秒をスペース区切りで代入してください。\n");
	scanf("%d%d%d%d",&time[0],&time[1],&time[2],&time[3]);
	
	while(1){
		if(time[1]>=24){
			time[0]=time[0]+1;
			time[1]=time[1]-24;
		}
		if(time[2]>=60){
			time[1]=time[1]+1;
			time[2]=time[2]-60;
		}
		if(time[3]>=60){
			time[2]=time[2]+1;
			time[3]=time[3]-60;
		}
		if(24>time[1]&&60>time[2]&&60>time[3]) goto end;
		
	}
	
  end:
	printf("%d日%d時間%d分%d秒ですね。\n",time[0],time[1],time[2],time[3]);
	
	return 0;
	
}