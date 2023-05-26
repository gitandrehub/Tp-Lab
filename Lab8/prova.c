#include <stdio.h>
#include <stdbool.h>

#define file "../mappa.txt"
#define max 50

void leggi_matrice(int *row, int *col, int matrice[][max], FILE *fp);                         // funzione che legge il contenuto della matrice
void trovo_regioni(int matrice[][max], int row, int col);                                   // funzione che va a trovare le regioni
bool riconosciRegione(int riga, int col, int notin[][2], int elemento);                                          // funzione che controlla che l'elemento selezionato possa essere estremo di una nuova regione
void stampa(int basi[max], int altezze[max], int aree[max], int estremi[][2], int indice);  // funzione che stampa i risultati ottenuti

int main(){
    FILE *fp = fopen(file, "r");
    int row = 0, col = 0;
    int matrice[max][max];

    for(int i = 0;i<max;i++){
        for(int j = 0;j<max;j++){
            matrice[i][j] = 0;
        }
    }

    if(fp != NULL){
        leggi_matrice(&row, &col, matrice, fp);
        fclose(fp);
        printf("Numero di righe: %d\nNumero di colonne: %d\n", row, col);
        trovo_regioni(matrice, row, col);
    }
    else{
        printf("errore nell'apertura del file");
    }
    return 0;
}

void leggi_matrice(int *row, int *col, int matrice[][max], FILE *fp) {
    int elemento;
    for(int i = 0;i<2;i++){
        if(i == 0){
            fscanf(fp, "%d", &elemento);
            *row = elemento;
        }
        else{
            fscanf(fp, "%d", &elemento);
            *col = elemento;
        }
    }
    for (int i = 0; i < *row; i++){
        for (int j = 0; j < *col; j++) {
            fscanf(fp, "%d", &matrice[i][j]);
        }
    }
}
void trovo_regioni(int matrice[][max], int row, int col){
    int estremi[max][2], aree[max], basi[max], altezze[max], notin[max][2],avanti = 0, passo = 0, indice = 0;
    bool x = false, y = false;

    for(int i = 0;i<max;i++){
        for(int j = 0;j<2;j++){
            estremi[i][j] = 0;
            notin[i][j] = col+1;
        }
        aree[i] = 0;
        basi[i] = 0;
        altezze[i] = 0;
    }

    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            x = false;                                           // uso
            y = false;
            passo = 0;
            avanti = 0;
            int elemento = matrice[i][j];
            if(riconosciRegione(i,j,notin,elemento)){
                printf("  > Regione trovata in (%d, %d)\n", i, j);
                estremi[indice][0] = i;
                estremi[indice][1] = j;
                basi[indice] += 1;
                altezze[indice] += 1;
                for(int q = j+1;q<col;q++){             // verso dx
                    if(matrice[i][q] == 1){
                        x = true;
                        avanti++;
                        basi[indice] += 1;
                    }
                    else{
                        break;
                    }
                }
                for(int q = i+1;q<row;q++){             // verso giù
                    if(matrice[q][j] == 1){
                        altezze[indice] += 1;
                        notin[passo][0] = q;
                        notin[passo][1] = j;
                        passo ++;
                        y = true;
                    }
                    else{
                        break;
                    }
                }
                if(x == true && y == true){
                    notin[passo][0] = basi[indice]+i-1;
                    notin[passo][1] = altezze[indice]+j-1;
                    passo++;
                }
                aree[indice] = basi[indice]*altezze[indice];
                indice ++;
                j += avanti;
            }
            //in = true;
        }
    }
    stampa(basi, altezze, aree, estremi, indice);
}
bool riconosciRegione(int riga, int col, int notin[][2], int elemento){
    bool in = true;
    for(int i = 0;i < max;i++){
        if(riga == notin[i][0] && col == notin[i][1]){
            in = false;
        }
    }
    if(in == true && elemento == 1){
        return true;
    }
    else{
        return false;
    }
}
void stampa(int basi[max], int altezze[max], int aree[max], int estremi[][2], int indice) {
    int max_base = 0, max_h = 0, max_area = 0;

    for (int i = 0; i < indice; i++) {
        max_base = basi[i] > basi[max_base] ? i : max_base;
        max_h = altezze[i] > altezze[max_h] ? i : max_h;
        max_area = aree[i] > aree[max_area] ? i : max_area;
    }
    printf("Max Base: estr. sup. SX = <%d, %d> , b = %d, h = %d, area = %d\n", estremi[max_base][0],
           estremi[max_base][1], basi[max_base], altezze[max_base], aree[max_base]);
    printf("Max Altezza: estr. sup. SX = <%d, %d> , b = %d, h = %d, area = %d\n", estremi[max_h][0], estremi[max_h][1],
           basi[max_h], altezze[max_h], aree[max_h]);
    printf("Max Area: estr. sup. SX = <%d, %d> , b = %d, h = %d, area = %d\n", estremi[max_area][0],
           estremi[max_area][1], basi[max_area], altezze[max_area], aree[max_area]);
}