#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define sorgente "../sorgente.txt"
#define dizionario "../dizionario.txt"
#define ricodificato "../ricodificato.txt"
#define S 30
#define l 10

void lettura_dizionario(FILE *fdiz, char vett_s[][l], char vett_o[][l], FILE *fout){
    bool val = false;
    char valore[l];
    int passo = 0;

    while (!feof(fdiz)) {
        fscanf(fdiz, "%s", valore);
        if(val == false){
            strcpy(vett_s[passo],valore);
            val = true;
        }else {
            strcpy(vett_o[passo], valore);
            val = false;
            passo++;
        }
    }
}
void stampa_controllo(char parola[15], char vett_o[][l], char vett_s[][l], FILE *fout, int ricodifiche){
    int punt = 0, prec = 0;

    for (int i = 0; i < strlen(parola); i++) {                           // carattere per carattere della parola
        bool find = false;
        while (find != true) {
            for (int j = 0; j < ricodifiche; j++) {                         // prendo la ricodifica
                find = false;
                prec = i;
                bool cont = true;
                punt = strlen(vett_o[j]);
                for (int x = 0; x < strlen(vett_o[j]); x++) {           // carattere per carattere della ricodifica attuale
                    if (parola[prec] == vett_o[j][x] && cont == true) {     // se i caratteri coincidono allora vado avanti
                        punt--;
                        prec++;
                    } else if (parola[prec] != vett_o[j][x]) {              // se anche solo un carattere non coincide allora non potrà essere la ricodifica corretta
                        cont = false;
                    }
                }
                if (punt == 0) {                                            // se la ricodifica attuale è quella corretta
                    i = prec;
                    fprintf(fout,"%s", vett_s[j]);
                    find = true;
                }
            }
            if (find == false) {                                            // se non corrisponde ad alcuna ricodifica
                fprintf(fout,"%c", parola[i]);
                find = true;
            }
        }
    }
    fprintf(fout," ");
}

int main() {
    FILE *fsorg = fopen(sorgente,"r"),
            *fdiz = fopen(dizionario,"r"),
            *fout = fopen(ricodificato, "w");
    int ricodifiche = 0;
    char vett_s[S][l], vett_o[S][l], parola[15];                // vettore con caratteri di sostituizone e con caratteri originali

    if(fdiz == NULL || fsorg == NULL){
        printf("Errore in apertura file");
        return 0;
    }

    fscanf(fdiz,"%d",&ricodifiche);
    lettura_dizionario(fdiz, vett_s, vett_o, fout);                 // riempi i vettori 'vett_s' e 'vett_o'

    while(!feof(fsorg)) {                                       // leggo parola per parola dal file e la controllo carattere per carattere nella funzione
        fscanf(fsorg, "%s", parola);
        stampa_controllo(parola, vett_o, vett_s, fout, ricodifiche);
    }

    fclose(fdiz);
    fclose(fsorg);
    fclose(fout);
    return 0;
}