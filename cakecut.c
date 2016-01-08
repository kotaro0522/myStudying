#include <stdio.h>
int main(void){
    int X,Y,Z,N,d,a,count=0,minX=100,minY=100;
    int x[200],y[200];
    scanf("%d",&X);
    scanf("%d",&Y);
    scanf("%d",&Z);
    scanf("%d",&N);
    for(int i=0;i<X;i++){
        x[i]=1;
    }
    for(int i=0;i<Y;i++){
        y[i]=1;
    }
    for(int i=0;i<N;i++){
        scanf("%d",&d);
        scanf("%d",&a);
        if(d==0){
            x[a]=0;
        }else if(d==1){
            y[a]=0;
        }
    }
    for(int i=0;i<=X;i++){
        if(x[i]==1){
            count++;
        }else{
            if(minX>count){
                minX=count;
            }
            count=1;
        }
    }
    count=0;
    for(int i=0;i<=Y;i++){
        if(y[i]==1){
            count++;
        }else{
            if(minY>count){
                minY=count;
            }
            count=1;
        }
    }
    printf("%d",minX*minY*Z);
    return 0;
}
