#include <stdio.h>
int main(void){
    int N,M1,M2;
    int flg=0;
    int tmp,x[2016],y[2016];
    scanf("%d",&N);
    scanf("%d",&M1);
    for(int i=0;i<M1;i++){
        scanf("%d",&tmp);
        x[tmp]=1;
    }
    scanf("%d",&M2);
    for(int i=0;i<M2;i++){
        scanf("%d",&tmp);
        if(x[tmp]!=1){
            y[tmp]=1;
        }
    }
    for(int i=1;i<=1000;i++){
        if(y[i]==1){
            if(flg==1){
                printf(" ");
            }
            printf("%d",i);
            flg=1;
        }
    }
    if(flg==0){
        printf("None");
    }
    return 0;
}
