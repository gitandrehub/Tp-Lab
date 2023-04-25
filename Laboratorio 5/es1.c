#include <stdio.h>
#include <stdbool.h>

#define file "../mat"

int capolista(int col, int squadra[col], int c){
    int max = 0;
    for(int i = 0;i <= c;i++){
        if(i == 0){
            max = i;
        }
        else{
            max = squadra[i] > squadra[max] ? i:max;
        }
    }
    return max;
}
void matrice(int righe, int col, FILE *fp){
    int squadra[col], val = 0, c = 0, giornata = 1, testa = 0;

    for(int i = 0; i < col;i++){
        squadra[i] = 0;
    }
    while(!feof(fp)){
        fscanf(fp, "%d", &val);
        squadra[c] += val;
        c++;
        
        if(c == 4){
            int testa = capolista(col, squadra, c);
            printf("Alla giornata %d la squadra %d e' in testa con %d punti\n", giornata, testa, squadra[testa]);
            giornata ++;
            c = 0;
        }
    }
}


int main(){
    FILE *fp = fopen(file,"r");
    int righe, col, valore;
    bool primi = false;

    if(fp == NULL){
        printf("Errore nell'apertura del file!");
    }
    else {
        while (!feof(fp)) {
            fscanf(fp, "%d", &valore);
            if (primi == false) {
                righe = valore;
                primi = true;
            } else {
                col = valore;
                matrice(righe, col, fp);
                return 0;
            }
        }
    }
}