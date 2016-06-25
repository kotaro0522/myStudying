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

printf("ŠJŽnŽž‚Í%d[ms]\n",start_time);
printf("I—¹Žž‚Í%d[ms]\n",end_time);
printf("Š|‚©‚Á‚½ŽžŠÔ‚Í%d[ms]\n",period);

return 0;

}