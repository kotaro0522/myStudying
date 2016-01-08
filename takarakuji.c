#include <stdio.h>
#include <string.h>
int main(void){
    int b,n,a;
    char kekka[200][10];
    scanf("%d",&b);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a);
        strcpy(kekka[i],"blank");
        if(b%1000==a%1000){
            strcpy(kekka[i],"third");
            if(b%10000==a%10000){
                strcpy(kekka[i],"second");
                if(b==a){
                    strcpy(kekka[i],"first");
                }
            }
        }
        if(b-1==a||b+1==a){
            strcpy(kekka[i],"adjacent");
        }

    }
    for(int i=0;i<n;i++){
        printf("%s\n",kekka[i]);
    }
    return 0;
}
