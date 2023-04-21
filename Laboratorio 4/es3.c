#include <stdio.h>
#include <string.h>
#include <math.h>

void funzione(int dim, int nc, int nr, int matrice[nr][nc]){
    int xsm = 0, ysm = 0, n = 0, sottom[(nr*nc)/dim][nc], somma[(nr*nc)/dim];
    int prova = 0;
    for(int i = 0; i < nr;i++){             // controllo riga
        for (int j = 0; j < nc;j++){        // colonna
            sottom[i][j] = matrice[i][j];
            if((j+1)%dim == 0){
                for(int is = i+1; is < dim;is++){             // controllo sottomatrice riga
                    for (int js = j-1; js < dim;js++){        // colonna
                        //sottom[i][js] = matrice[is][js];
                        prova = matrice[is][js];
                        printf("Bene");
                    }
                }
            }
        }
    }
}

int main(){
    int nr, nc, rg = 0, val;
    char entername[20], file[24] = "../";
    FILE *fp;

    printf("Nome file:");
    scanf("%s",entername);
    strcat(file,entername);
    fp = fopen(file,"r");
    if(fp == NULL){
        printf("Errore nel file di input");
        return 0;
    }
    else {
        int x = 0, y = 0, matrice[20][20], ind = 0, dim = 1;
        while (!feof(fp)) {
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
        }               // riempimento matrice
        while (dim <= fmin(nc, nr) && dim >= 1){
            printf("Dimensione della sottomatrice?");
            scanf("%d",&dim);
            funzione(dim,nc,nr,matrice);
        }
    }
    printf("%d %d", nr, nc);
    return 0;
}