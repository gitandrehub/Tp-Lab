#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compressione(FILE *fout,FILE *fp){
    char carattere_p, carattere_a;              // inizializzazione delle variabili carattere precedente, carattere attuale
    int passo = 0, tot_caratteri = 0;           // il passo e il numero totale di caratteri

    while(!feof(fp)){
        fscanf(fp,"%c",&carattere_a);
        if(!feof(fp)){
        if(carattere_p == carattere_a && passo < 9){
                passo += 1;
            }
        else if (carattere_p != carattere_a || passo == 9){
            if (passo == 0){
                fprintf(fout, "%c", carattere_a);
                tot_caratteri ++;
            }
            else if(passo > 1 && passo < 10){
                fprintf(fout, "$%d%c", passo, carattere_a);
                tot_caratteri += 3;
                passo = 0;
            }
            else{
                fprintf(fout, "%c%c", carattere_p, carattere_a);
                tot_caratteri += 2;
                passo = 0;
            }
        }
        carattere_p = carattere_a;
        }
        else if (feof(fp) && passo != 0){
            fprintf(fout,"$%d",passo);
            passo = 0;
        }
    }
    return tot_caratteri;
}
int decompressione(FILE *fout,FILE *fp){
    char carattere_p, carattere_a, carattere_s;         // 'carattere_p' il carattere precedente, 'carattere_a' il carattere attuale e 'carattere_c' il carattere da stampare
    int tot_caratteri = 0;                              // il numero totale di caratteri
    bool numero = false;                                // variabile che mi dice se sto leggendo un numero o meno

    while(!feof(fp)){
        fscanf(fp,"%c",&carattere_a);
        if(!feof(fp)){
           if(carattere_a != '$' && numero == false){
               fprintf(fout, "%c", carattere_a);
               tot_caratteri ++;
           }
           else if(carattere_a == '$'){
               carattere_s = carattere_p;
               numero = true;
           }
           else if(numero == true){
               int i;
               for(i = strtol(&carattere_a, NULL, 10); i != 0; i--){
                   fprintf(fout, "%c", carattere_s);
                   tot_caratteri ++;
               }

               numero = false;
           }
        }
        carattere_p = carattere_a;
    }
    return tot_caratteri;
}

// Funzione che controlla i file, prima di eseguire l'operazione scelta
int controllo_file(FILE *fout,FILE *fp){
    if (fp == NULL){
        printf("Errore nell'apertura del file!");
        return false;
    }
    if (fout == NULL){
        printf("Errore nell'apertura del file!");
        return false;
    }
    return true;
}

int main(){
    int scelta;             // variabile in cui verrà salvato il tipo di operazione da fare

    printf("Eseguire compressione (0) o decompressione(1)?");       // scelta dell'utente
    scanf("%d",&scelta);

    // Le due scelte, organizzare come: apertura dei file, controllo che non siano vuoti e svolgo l'operazione scelta
    if(scelta == 0){
        FILE *fp = fopen("../sorgente.txt","r");
        FILE *fout = fopen("../codificato.txt","w");
        controllo_file(fout,fp);
        printf("Caratteri nel file di compressione: %d\n",compressione(fout,fp));
    }
    else if(scelta == 1){
        FILE *fp = fopen("../codificato.txt","r");
        FILE *fout = fopen("../decodificato.txt","w");
        if (controllo_file(fout,fp)){
            printf("Caratteri nel file di decompressione: %d\n",decompressione(fout,fp));
        }
    }
    else{
        printf("Errore nella scelta dei dati!");
    }

    return 0;
}