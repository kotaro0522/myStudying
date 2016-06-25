#include <stdio.h>

int main(){

int i;
int sigma;

for(i=1;i<=30;i++){

sigma=sigma+i*i*i*i*i;

}

printf("ƒ°[k=1..30]k^5=%d\n",sigma);

return 0;

}