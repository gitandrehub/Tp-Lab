#include <stdio.h>

#define file "../sort1.txt"
#define max 100

int lettura_matrice(FILE *fp, int matrice[][max], int lunghezza);
void selection_sort(int matrice[][max], int lunghezza, int col);
void insertion_sort(int matrice[][max], int lunghezza, int col);
void shell_sort(int matrice[][max], int lunghezza, int col);

int main(){
    FILE *fp = fopen(file, "r");
    int algoritmi = 3, lunghezza = 0, col = 0;
    int matrice[max][max];

    for(int i = 0;i<max;i++){
        for(int j = 0;j<max;j++){
            matrice[i][j] = 0;
        }
    }

    if(fp != NULL){
        fscanf(fp, "%d", &lunghezza);
        col = lettura_matrice(fp, matrice, lunghezza);
        fclose(fp);
        for(int i = 0;i<algoritmi;i++){
            switch (i) {
                case 0:
                    insertion_sort(matrice, lunghezza, col);
                    break;
                case 1:
                    selection_sort(matrice, lunghezza, col);
                    break;
                case 2:
                    shell_sort(matrice, lunghezza, col);
                    break;
                default:
                    printf("fine");
                    break;
            }
        }
    }
    else{
        printf("Errore nell'apertura del file");
    }
    return 0;
}

int lettura_matrice(FILE *fp, int matrice[][max], int lunghezza){
    int col = 0;
    for(int i = 0;i<lunghezza;i++){
        fscanf(fp, "%d", &col);
        for(int j = 0;j<col;j++){
            fscanf(fp, "%d", &matrice[i][j]);
        }
    }
    return col;
}
void selection_sort(int matrice[][max], int lunghezza, int col){
    int copia_m[lunghezza][col], scambi = 0, iterazioni_est = 0, iterazioni_in = 0, iterazioni_tot = 0, passo = 0;
    int min = 100000, indice_min = 0;
    for(int i = 0;i<lunghezza;i++){
        for(int j = 0;j<col;j++){
            copia_m[i][j] = matrice[i][j];
        }
    }

    printf("\n> Selection sort:\n");
    for(int i = 0;i<lunghezza;i++){
        for(int j = 0;j<col;j++){
            for(int q = j;q < col;q++){           // itero sulla parte dx del vettore
                if(copia_m[i][q] < min){
                    min = copia_m[i][q];
                    indice_min = q;
                    iterazioni_in ++;
                }
            }
            for(int q = j;q >= 0;q--){            // itero sulla parte sx
                if(copia_m[i][q] > min && copia_m[i][q-1] < min && q != 0){
                    int cop = copia_m[i][j];
                    copia_m[i][q] = min;
                    copia_m[i][indice_min] = cop;
                    scambi++;
                    iterazioni_in ++;
                    break;
                }
                else if (q == 0 && copia_m[i][q] > min){
                    int cop = copia_m[i][j];
                    copia_m[i][q] = min;
                    copia_m[i][indice_min] = cop;
                    iterazioni_in ++;
                    scambi++;
                    break;
                }
            }
            min = 100000;
        }
        printf("  alla riga %d sono state fatte %d iterazioni interne\n", i, iterazioni_in);
        iterazioni_est ++;
        iterazioni_tot += iterazioni_in;
        iterazioni_in = 0;
    }
    iterazioni_tot += iterazioni_est;
    printf("  - numero di scambi totali: %d\n  - numero di iterazioni del ciclo esterno: %d\n  - il numero totale di iterazioni: %d\n", scambi, iterazioni_est, iterazioni_tot);
}
void insertion_sort(int matrice[][max], int lunghezza, int col){
    int copia_m[lunghezza][col], scambi = 0, iterazioni_est = 0, iterazioni_in = 0, iterazioni_tot = 0, passo = 0;

    for(int i = 0;i<lunghezza;i++){
        for(int j = 0;j<col;j++){
            copia_m[i][j] = matrice[i][j];
        }
    }

    printf("> Insertion sort:\n");
    for(int i = 0;i<lunghezza;i++){
        for(int j = 0;j<col;j++){
            while (copia_m[i][j-passo] < copia_m[i][j-passo-1] && j-passo > 0){
                int cop = copia_m[i][j-passo];
                copia_m[i][j-passo] = copia_m[i][j-1-passo];
                copia_m[i][j-1-passo] = cop;
                passo++;
                iterazioni_in ++;
                scambi++;
            }
            iterazioni_in ++;
            iterazioni_est ++;
            passo = 0;
        }
        printf("  alla riga %d sono stati fatte %d iterazioni interne\n", i, iterazioni_in);
        iterazioni_tot += iterazioni_in;
        iterazioni_in = 0;
    }
    iterazioni_tot += iterazioni_est;
    printf("  - numero di scambi totali: %d\n  - numero di iterazioni del ciclo esterno: %d\n  - il numero totale di iterazioni: %d\n", scambi, iterazioni_est, iterazioni_tot);
}
void shell_sort(int matrice[][max], int lunghezza, int col){
    int copia_m[col], scambi = 0, iterazioni_est = 0, iterazioni_in = 0, iterazioni_tot = 0, passo = 0;
    printf("\n> Shell sort:\n");

    for(int q = 0;q<lunghezza;q++){
        for(int w = 0;w<col;w++){
            copia_m[w] = matrice[q][w];
        }
        int i, j, x, l=0, r=col-1, h=1;
        while (h <= col/3) {
            h = 3 * h + 1;
        }
        while (h >= 1) {
            for (i = l + h; i <= r; i++) {
                j = i;
                x = copia_m[i];
                while (j >= l + h && x < copia_m[j-h]) {
                    copia_m[j] = copia_m[j-h];
                    j -= h;
                    scambi++;
                    iterazioni_in ++;
                }
                copia_m[j] = x;
            }
            h = h/3;
        }
        printf("  alla riga %d sono stati fatte %d iterazioni interne\n", i, iterazioni_in);
    }
    printf("  - numero di scambi totali: %d\n  - il numero totale di iterazioni interne: %d\n", scambi, iterazioni_in);
}