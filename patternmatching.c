#include <stdio.h>
int main(void){
    int N,M;
    char Nmap[200][200],Mmap[20][20];
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        fgets(Nmap[i], sizeof(Nmap[i]), stdin);
    }
    scanf("%d",&M);
    getchar();
    for(int i=0;i<M;i++){
        fgets(Mmap[i], sizeof(Mmap[i]), stdin);
    }

    for(int i=0;i<M;i++){
        printf("%s", Mmap[i]);
    }

    return 0;
}
