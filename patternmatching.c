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

    for(int Ny=0;Ny<N-M+1;Ny++){
    next:
        for(int Nx=0;Nx<(N-M+1)*2;Nx+=2){
            for(int My=0;My<M;My++){
                for(int Mx=0;Mx<M*2;Mx+=2){
                    if(Nmap[Ny][Nx] != Mmap[My][Mx]){
                        goto next;
                    }
                    if(M==My+1&&M==Mx/2+1){
                        printf("%d %d", );
                    }
                    Nx++;
                }
                Ny++;
            }
            
        }
    }

    return 0;
}
