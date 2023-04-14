#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write;       // metto le variabili che userò per i file
    char file_char, choice;         // variabili che userò per i caratteri

    // Apertura dei due file di lettura e scrittura
    if((fp_read = fopen("C:/Users/andre/Desktop/Poli/Tecniche di programmazione/C/Laboratori/Laboratorio 1/ex2/Guide.txt","r")) == NULL){
        printf("Errore di apertura del file\n");
        return 1;
    }
    if((fp_write = fopen("C:/Users/andre/Desktop/Poli/Tecniche di programmazione/C/Laboratori/Laboratorio 1/ex2/Output.txt","w"))==NULL){
        printf("Errore di apertura del file\n");
        return 2;
    }

    // Richiesta all'utente di dove stampare il contenuto letto
    printf("Stampare su console (C) o su file (F):");
    choice = 'F';

    // Lettura del contenuto e stampa su dove si è scelto
    while(!feof(fp_read)){              // fino a quando il file non è finito
        file_char= fgetc(fp_read);      // prende solo un carattere dal file e va avanti da solo
        if(!feof(fp_read)){             // da mettere per non fargli leggere l'ultimo carattere inesistente
            switch (choice) {
                case 'C':
                    printf("\nChar printed on the console: %c",file_char);
                    break;
                case 'F':
                    fputc(file_char,fp_write);      // scrive sul file il carattere preso
                    break;
                default:
                    printf("Scelta errata\n");
                    return 3;
            }
        }
    }
    fclose(fp_read);
    fclose(fp_write);

    return 0;
}
