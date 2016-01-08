#include <stdio.h>
#include <string.h>
int main(void){
    int a,b,R,N,x,y;
    char check[2016][10];

    scanf("%d %d %d",&a,&b,&R);
    scanf("%d",&N);



    for(int i=1;i<=N;i++){
        scanf("%d %d",&x,&y);
        if(((x-a)*(x-a)+(y-b)*(y-b))>=R*R){
            strcpy(check[i],"silent");
        }else{
            strcpy(check[i],"noisy");
        }
    }

    for(int i=1;i<=N;i++){
        printf("%s\n",check[i]);
    }

    return 0;
}
