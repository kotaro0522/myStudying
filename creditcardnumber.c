#include <stdio.h>
int main(void){
    int n,num[100],X[200],even,odd;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        even=0;
        odd=0;
        for(int j=0;j<15;j++){
            scanf("%1d", &num[j]);
        }
        getchar();
        for(int j=0;j<15;j+=2){
            if(num[j]*2>9){
                even=even+1+num[j]*2-10;
            }else{
                even=even+num[j]*2;
            }
            odd=odd+num[j+1];
        }
        for(int j=0;j<10;j++){
            if((even+odd+j)%10==0){
                X[i]=j;
            }
        }

    }
    for(int i=0;i<n;i++){
        printf("%d\n", X[i]);
    }
    return 0;
}
