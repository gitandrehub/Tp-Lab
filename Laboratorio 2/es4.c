#include <stdio.h>
#include <stdbool.h>

int main(){
    FILE *fp = fopen("../filecodifica.txt","r");
    char carattere, precedente = '\n', somma;
    char h, fisso_i, fisso_f, fisso_ai, fisso_af;

    if(fp == NULL){
        printf("Errore!");
        return 1;
    }

    while(!feof(fp)){
        carattere = fgetc(fp);
        if(!feof(fp)) {
            if (carattere <= 90 && carattere >= 65){
                fisso_ai = 'A';
                fisso_af = 'Z';
            }
            else if (carattere <= 122 && carattere >= 97){
                fisso_ai = 'a';
                fisso_af = 'z';
            }
            if (precedente == '\n' && carattere != ' ') {
                printf("%c", carattere);
                precedente = carattere;
            }
            else if(precedente != '\n' && carattere != ' ') {
                h = precedente - fisso_i;
                somma = carattere + h;
                while (somma > fisso_af){
                    somma = somma - fisso_af + fisso_ai - 1;
                }
                printf("%c", somma);
                precedente = somma;
            }
            else{
                precedente = '\n';
                printf(" ");
            }
            if (carattere <= 90 && carattere >= 65){
                fisso_i = 'A';
                fisso_f = 'Z';
            }
            else if (carattere <= 122 && carattere >= 97){
                fisso_i = 'a';
                fisso_f = 'z';
            }
        }
    }

}
