#include <stdio.h>
#include <time.h>

int main(){

int start_time, end_time;
int period;
int i;
int repeat=1000000;

start_time=clock();

for(i=1;i<=repeat;i++){
	printf("Hello!\n");
}

end_time=clock();

period=end_time-start_time;

printf("開始時刻は%d[ms]\n",start_time);
printf("終了時刻は%d[ms]\n",end_time);
printf("掛かった時間は%d[ms]\n",period);

return 0;

}