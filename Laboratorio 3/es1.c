#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define filein "../input.txt"
#define fileout "../testo.txt"

int textprocessing(FILE *fin, FILE *fout){
    char carattere;                         // carattere letto
    int ochar = 0, totchar = 0;             // original char dal file e carattere totali scritti
    // condizione di continuazione del ciclo, verifica dello spazio, aggiunta maiuscola, aggiunta spazio
    bool ciclo = true, vspazio = false, vmaiuscola = false, addspace = false;

    while(!feof(fin)) {
        while (ciclo) {
            carattere = fgetc(fin);
            if (!feof(fin)) {
                if (carattere >= '0' && carattere <= '9' && vspazio == false) {
                    fprintf(fout, "*");
                }
                else if (vspazio == false && (carattere == '.' || carattere == '!' || carattere == '?' || carattere == ','
                        || carattere == ':' || carattere == ';' || carattere == 39 || carattere == '(' || carattere == ')')) {
                    if (carattere == '.' || carattere == '!' || carattere == '?') {
                        vmaiuscola = true;
                    }
                    vspazio = true;
                    fprintf(fout, "%c",carattere);
                }
                else if (vspazio == true || vmaiuscola == true) {
                    if (vmaiuscola == false && carattere == ' ') {
                        fprintf(fout, "%c",carattere);
                    }
                    else if (vmaiuscola == false && carattere == '\n'){
                        ciclo = false;
                    }
                    else if (vmaiuscola == false && carattere != ' ' && carattere != '\n') {
                        fprintf(fout, " %c",carattere);
                        totchar ++;
                    }
                    else if (vmaiuscola == true && carattere == ' ') {
                        fprintf(fout, "%c",carattere);
                        addspace = true;
                    }
                    else if (vmaiuscola == true && carattere == '\n') {
                        ciclo = false;
                        addspace = true;
                    }
                    else if (vmaiuscola == true && carattere != ' ' && carattere != '\n' && addspace == false) {
                        fprintf(fout, " %c", toupper(carattere));
                        totchar ++;
                        vmaiuscola = false;
                        addspace = false;
                    }
                    else if (vmaiuscola == true && carattere != ' ' && carattere != '\n' && addspace == true) {
                        fprintf(fout, "%c", toupper(carattere));
                        vmaiuscola = false;
                        addspace = false;
                    }
                    vspazio = false;
                }
                else if (carattere == '\n') {
                    ciclo = false;
                }
                else
                    fprintf(fout, "%c",carattere);
            ochar ++; totchar ++;
            }
            else {
                ciclo = false;
                totchar ++;
            }
            if (totchar == 25) {
                ciclo = false;
            }
        }
        if (totchar == 25) {
            fprintf(fout, "| c:%d\n", ochar);
        }
        else {
            for (int i = totchar; i <= 25; i++) {
                fprintf(fout, " ");
            }
            fprintf(fout, "| c:%d\n", ochar);
        }
        ochar = 0; totchar = 0; ciclo = true;
    }
    fclose(fin); fclose(fout);
}

int main(){
    FILE *fin = fopen(filein,"r"), *fout = fopen(fileout,"w");

    if (fin == NULL){
        printf("Errore nell'apertura del file di input!");
        return 0;
    }
    if (fout == NULL){
        printf("Errore nell'apertura del file di output!");
        return 0;
    }
    textprocessing(fin, fout);

    return 0;
}