#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void lettura_matrice(FILE *fp, int matrice[20][20], int row, int col, int valore){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col;j++){
            fscanf(fp,"%d", &matrice[i][j]);
        }
    }
}
void rotazione_riga(int matrice[20][20], char selettore[8], int indice, char direzione[9], int posizioni, int row, int col){
    int nuovo[col];
    int ind = 0;

    if(posizioni > col){
        posizioni = posizioni-col;
    }
    int spdx = strcmp(direzione,"destra") == 0? col-posizioni : posizioni;           // nel caso di spostamento a destra cambio direzione e posizione

    for (int i = spdx; i < col; i++) {
        nuovo[ind] = matrice[indice-1][i];
        ind++;
    }
    for (int i = 0; i < spdx; i++) {
        nuovo[ind] = matrice[indice-1][i];
        ind++;
    }

    for(int i = 0;i< col;i++){
        matrice[indice-1][i] = nuovo[i];
    }
}
void rotazione_colonna(int matrice[20][20], char selettore[8], int indice, char direzione[9], int posizioni, int row, int col){
    int nuovo[col];
    int ind = 0;

    int spsu = strcmp(direzione, "giu") == 0 ? row - posizioni : posizioni;           // nel caso di spostamento a destra cambio direzione e posizione

    for (int i = spsu; i < row; i++) {
        nuovo[ind] = matrice[i][indice-1];
        ind++;
    }
    for (int i = 0; i < spsu; i++) {
        nuovo[ind] = matrice[i][indice-1];
        ind++;
    }

    for(int i = 0;i< row;i++){
        matrice[i][indice-1] = nuovo[i];
    }
}

int main(){
    char enter[20], file[23] = "../";
    FILE *fp;
    int row, col, primo = 0, valore, matrice[20][20];
    char selettore[8], direzione[9];
    int indice, posizioni;

    printf("Inserire il nome del file:");                   // scelta del file
    scanf("%s",enter);
    strcat(file,enter);

    fp = fopen(file,"r");
    if(fp == NULL){
        printf("Errore nell'apertura del file!");
    } else{
        while(!feof(fp)){
            fscanf(fp,"%d", &valore);               // lettura della matrice
            row = primo == 0 ? valore:row;
            col = primo == 1 ? valore:col;
            primo ++;
            if(primo == 2){
                lettura_matrice(fp, matrice, row, col, valore);
                for(int i = 0;i < row;i++){                     // stampa della matrice
                    for(int j = 0;j< col;j++){
                        printf("%d ", matrice[i][j]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }
        do {
            printf("<selettore> <indice> <direzione> <posizioni>:");                // scelta dell'operazione
            scanf("%s %d %s %d", selettore, &indice, direzione, &posizioni);

            if(strcmp(selettore,"riga") == 0 && (strcmp(direzione,"destra") == 0 || strcmp(direzione, "sinistra") == 0)){
                rotazione_riga(matrice, selettore, indice, direzione, posizioni, row, col);
            } else if(strcmp(selettore,"colonna") == 0 && (strcmp(direzione, "giu") == 0 || strcmp(direzione, "su") == 0)){
                rotazione_colonna(matrice, selettore, indice, direzione, posizioni, row, col);
            } else if(strcmp(selettore, "fine") == 0){
                printf("Fine del programma\n");
            } else {
                printf("Inserimento errato dei parametri!\n");
            }

            for(int i = 0;i < row;i++){                         // stampa lo stato della matrice
                for(int j = 0;j< col;j++){
                    printf("%d ", matrice[i][j]);
                }
                printf("\n");
            }
            printf("\n");
        } while (strcmp(selettore, "fine") != 0);
    }
}