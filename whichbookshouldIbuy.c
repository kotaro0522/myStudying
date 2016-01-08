#include <stdio.h>
int main(void){
    int N,M1,M2;
    int flg=0;
    int x[2016],y[2016];
    scanf("%d",&N);
    scanf("%d",&M1);
    for(int i=0;i<M1;i++){
        scanf("%d",&x[i]);
    }
    scanf("%d",&M2);
    for(int i=0;i<M2;i++){
        scanf("%d",&y[i]);
        for(int j=0;j<M1;j++){
            if(y[i]==x[j]){
                y[i]=0;
                break;
            }else if(y[i]<x[j]){
                break;
            }
        }
    }
    for(int i=0;i<M2;i++){
        if(y[i]!=0){
            flg=1;
            if(i>0){
                printf(" ");
            }
            printf("%d",y[i]);
        }
    }
    if(flg==0){
        printf("None");
    }
    return 0;
}
