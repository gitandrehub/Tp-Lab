#include <stdio.h>

#define maxN 30

void ruota(int N,int vettore[N],int P, int dir){
    int nuovov[N], ind = 0, spdx = P;
    if(dir == -1) {                      // nel caso di spostamento a destra cambio lo spostamento
        spdx = N - P;
    }
    for (int i = spdx; i < N; i++) {
        nuovov[ind] = vettore[i];
        ind++;
    }
    for (int i = 0; i < spdx; i++) {
        nuovov[ind] = vettore[i];
        ind++;
    }
    printf("vettore: [");           // stampa vettore risultante
    for(int i = 0;i<N;i++){
        printf(" %d ",nuovov[i]);
    }
    printf("]\n");
}

int main(){
    int N = 0, val = 0, ind = 0, dir, pos;
    printf("Inserimento parametri:\n");

    printf("a) quanti numeri?");
    scanf("%d",&N);
    int vettore[N];
    if(N<maxN) {
        while (ind != N && val != -1) {
            printf("   inserire il numero:");
            scanf("%d", &val);
            vettore[ind] = val;
            ind++;
        }
        while(pos != 0) {
            printf("\nb) direzione e rotazione di posizioni:");
            scanf("%d %d", &dir, &pos);
            if((dir == 1 || dir == -1) && pos != 0 && pos <= N){
                ruota(N,vettore,pos,dir);
            }
            else if((dir != 1 && dir != -1 && dir != 0) || pos > N){
                printf("\nErrore d'inserimento!");
                return 0;
            }
        }
        printf("\nFine programma");
        return 0;
    }
    else{
        printf("\nErrore d'inserimento del parametro 'N'");
        return 0;
    }
}