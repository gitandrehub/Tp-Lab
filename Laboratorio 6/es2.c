#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define file_testo "../testo.txt"
#define file_sequenze "../sequenze.txt"
#define MaxLRiga 200
#define MaxLPar 25
#define MaxLSeq 5

int scomponi_riga(char riga[MaxLRiga], char parole[][MaxLPar], int num_par);
int ricerca_sequenza(int num_seq, char sequenza[MaxLSeq], char parole[][MaxLPar], int num_par);

int main(){
    FILE *f1 = fopen(file_testo, "r"), *f2 = fopen(file_sequenze, "r");
    char riga[MaxLRiga], parole[MaxLRiga][MaxLPar], sequenza[MaxLSeq];
    int num_par = 0, num_seq = 0;

    for(int i = 0; i < MaxLRiga; i++){
        for(int j = 0; j< MaxLPar;j++){
            parole[i][j] = ' ';
        }
        riga[i] = ' ';
    }

    if(f1 != NULL && f2 != NULL) {
        while (!feof(f1)) {
            fgets(riga, MaxLRiga, f1);
            num_par = scomponi_riga(riga, parole, num_par);
        }
        fscanf(f2, "%d", &num_seq);
        while(num_seq != 0){
            fscanf(f2, "%s", sequenza);
            num_seq = ricerca_sequenza(num_seq, sequenza, parole, num_par);
            printf("\n\n");
        }
    }
    else{
        printf("Errore nell'apertura del file");
        return 0;
    }
    fclose(f1);
    fclose(f2);

    return 0;
}

int scomponi_riga(char riga[MaxLRiga], char parole[][MaxLPar], int num_par){
    int x = 0;
    char elemento[MaxLPar];

    for(int j = 0;j<MaxLPar;j++){
        elemento[j] = ' ';
    }

    for(int i = 0;i < strlen(riga);i++){
        if(isspace(riga[i]) != 0 || ispunct(riga[i]) != 0){
            elemento[x] = '\0';
            strcpy(parole[num_par], elemento);
            x = 0;
            num_par ++;
            for(int j = 0;j<MaxLPar;j++){
                elemento[j] = ' ';
            }
        }
        else{
            elemento[x] = riga[i];
            x++;
        }
    }
    return num_par;
}
int ricerca_sequenza(int num_seq, char sequenza[MaxLSeq], char parole[][MaxLPar], int num_par){
    int passo_s = 0;

    for(int i = 0;i< strlen(sequenza);i++){
        if(islower(sequenza[i]) == 0){
            sequenza[i] += 32;
        }
    }
    printf("La sequenza '%s' e' contenuta in: ", sequenza);
    for(int i = 0;i<num_par;i++){                                                        // itero sull'array
        passo_s = 0;
        for(int j = 0; j < strlen(parole[i]);j++){                                   // itero sui caratteri della parola
            if(isspace(parole[i][j]) != 0){
                break;
            } else if(islower(parole[i][j]) == 0 && isalpha(parole[i][j]) != 0){
                parole[i][j] += 32;
            }

            if (sequenza[passo_s] != parole[i][j]){
                passo_s = 0;
            } else{
                passo_s ++;
            }

            if(passo_s == strlen(sequenza)){
                printf("%s (alla posizione %d) ", parole[i], i);
                passo_s = 0;
            }
        }
    }

    num_seq --;
    return num_seq;
}