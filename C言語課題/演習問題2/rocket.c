#include <stdio.h>

int main(){

int i;
double rocket=0.999999;

for(i=1;i<1000000;i++){
	rocket=rocket*0.999999;
}

double rocket2=rocket*100;

printf("とあるロケットは100万個の部品からなる。\n");
printf("各部品は99.9999％の確率で正しく動作する。\n");
printf("このロケットが一つの部品の故障もない確率は%f％である。\n",rocket2);

return 0;

}
