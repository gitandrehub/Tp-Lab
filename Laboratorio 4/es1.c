#include <stdio.h>
#include <string.h>
#include <math.h>

#define max 30

int sottoSequenze(int N, int V[N]){
    int riga = 0, col = 0, lriga[N], maxl;
    int sottoV[N][N];

    for(int i = 0; i <= N; i++){
        lriga[i] = 0;
    }
    for(int i = 0; i < N; i++){             // creazione dei sottovettori
        if(V[i] == 0){
            riga ++;
            col = 0;
        }
        else{
            sottoV[riga][col] = V[i];
            lriga[riga] += 1;
            col++;
        }
    }
    for(int i = 0; i <= riga; i++){         // ricerca della dimensione massima dei sottovettori
        if(i == 0){
            maxl = lriga[i];
        }
        else {
            maxl = lriga[i] > maxl ? lriga[i]:maxl;
        }
    }
    for(int i = 0; i <= riga; i++){         // stampa degli elementi con dimensione massima
        if(maxl == lriga[i]){
            printf("[");
            for(int j = 0;j < lriga[i];j++){
                printf(" %d ", sottoV[i][j]);
            }
            printf("]\n");
        }
    }
}

int main(){
    int vettore[max], chiamata, val=1, ind = 0;
    char nfile[100];

    for(int i = 0; i < max; i++){
        vettore[i] = 0;
    }

    printf("Scegliere il metodo di inserimento (0 tastiera e 1 file):");
    scanf("%d",&chiamata);

    if(chiamata == 1){
        char file[100] = "../";
        FILE *fp;
        printf("Inserire il nome del file:");
        scanf("%s",nfile);
        strcat(file,nfile);
        fp = fopen(file, "r");
        if(fp == NULL){
            printf("There is a problem on file!");
            return 0;
        }
        else {
            while(!feof(fp)){
                fscanf(fp,"%d", &val);
                vettore[ind] = val;
                ind++;
            }
            if(ind <= max){
                sottoSequenze(ind, vettore);
            }
            return 0;
        }
    }
    else if(chiamata == 0){
        while(val != -1){
            printf("Inserire numero:");
            scanf("%d",&val);
            if(val != -1){
                vettore[ind] = val;
                ind ++;
            }
        }
        if(ind <= max){
            sottoSequenze(ind, vettore);
        }
        return 0;
    }
    else{
        printf("Errore d'inserimento");
        return 0;
    }
}