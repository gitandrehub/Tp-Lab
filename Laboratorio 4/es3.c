#include <stdio.h>
#include <string.h>
#include <math.h>

#define file "../testoes3"

void funzione(int dim, int nc, int nr, int matrice[][nc]);

int main(){
    int nr, nc, rg = 0, val;
    //char entername[20], file[24] = "../";
    FILE *fp;
    /*
    printf("Nome file:");
    scanf("%s",entername);
    strcat(file,entername);
     */
    fp = fopen(file,"r");
    if(fp == NULL){
        printf("Errore nel file di input");
        return 0;
    }
    else {
        int x = 0, y = 0, matrice[20][20], ind = 0, dim = 1;
        for(int q = 0;q<20;q++){
            for(int w = 0;w<20;w++){
                matrice[q][w] = 0;
            }
        }
        while (!feof(fp)) {                                     // riempimento matrice
            fscanf(fp, "%d", &val);
            if (rg == 0) {
                if(val <= 20){
                    nr = val;
                }
                else{
                    printf("Valore di riga troppo grande");
                    return 0;
                }
                rg ++;
            }
            else if (rg == 1) {
                if(val <= 20){
                    nc = val;
                }
                else{
                    printf("Valore di colonna troppo grande");
                    return 0;
                }
                rg ++;
            }
            else {
                if(ind == nc){
                    y = 0;
                    ind = 0;
                    x++;
                }
                matrice[x][y] = val;
                y ++;
                ind++;
            }
        }
        while (dim <= fmin(nc, nr) && dim >= 1){
            printf("Dimensione della sottomatrice?");
            scanf("%d",&dim);
            funzione(dim, nc, nr, matrice);
        }
    }
    printf("%d %d", nr, nc);
    return 0;
}

void funzione(int dim, int nc, int nr, int matrice[][nc]) {
    int sottom[(nr * nc) / dim][nc], somma[(nr * nc) / dim];
    int passo = 0, elemento = 0;

    int x = 0, y = 0;
    int i, j;

    for(int q = 0; q < (nr * nc) / dim;q++){
        somma[q] = 0;
    }
    while(passo != (nr*nc)/dim) {
        for (i = x; i < x+dim; i++) {
            for (j = y; j < y+dim; j++) {
                sottom[passo][elemento] = matrice[i][j];
                somma[passo] += matrice[i][j];
                elemento++;
            }
        }
        y = j-1;
        if(j-1 == 3){
            x++;
            y = 0;
        }
        passo ++;
        elemento = 0;
    }
}