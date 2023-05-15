#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define DIM 1000        // massime righe del file
#define lun 30          // lunghezza massima delle stringhe
#define ncom 6          // opzioni massime del menù (i comandi)

// Funzione che legge il file e salva i valore negli appositi array
void lettura_file(FILE *fp, char tratta[DIM][lun], char part[DIM][lun], char arrivo[DIM][lun], char data[DIM][lun], char ora_p[DIM][lun], char ora_a[DIM][lun], int ritardo[DIM]){
    int x = 0;
    while(!feof(fp)){
        if(!feof(fp)){
            fscanf(fp, "%s %s %s %s %s %s %d", tratta[x], part[x], arrivo[x], data[x], ora_p[x], ora_a[x], &ritardo[x]);
            x += 1;
        }
    }
}


// Funzioni che dividono le date inserite dall'utente e le date del file in giorni e mesi per poi poter fare il confronto
void divisione_date_utente(int x, int passo, int cambio, char dati[][lun], char giorni[][3], char mesi[][3]){
    for(int i = 0; i < strlen(dati[x]);i++){
        if(dati[x][i] == '-' || dati[x][i] == '/'){
            cambio += 1;
            passo = 0;
        }
        else if(cambio == 0){
            giorni[x-1][passo] = dati[x][i];
            passo ++;
        }
        else if (cambio == 1){
            mesi[x-1][passo] = dati[x][i];
            passo ++;
        }
    }
}
void divisione_date_file(int x, int passo, int cambio, char data[][lun], char giorni[][3], char mesi[][3], int i){
    for(int j = 0; j < strlen(data[i]);j++){
        if(data[i][j] == '-' || data[i][j] == '/'){
            cambio += 1;
            passo = 0;
        }
        else if(cambio == 2){
            giorni[x-1][passo] = data[i][j];
            passo ++;
        }
        else if (cambio == 1){
            mesi[x-1][passo] = data[i][j];
            passo ++;
        }
    }
}

// Ad ogni funzione corrisponde un comando
void date_corse(char data[][lun], char codice_tratta[][lun], int righe, char dati[][lun]){
    printf("Le corse partite nell'intervallo selezionato sono: ");

    char giorni[4][3], mesi[4][3];            // dai dati inseriti 0: inizio 1:fine 2:data elenco
    for(int x = 1; x <= 3; x++){
        int passo = 0;
        int cambio = 0;
        if(x <= 2){
            divisione_date_utente(x, passo, cambio, dati, giorni, mesi);
        }
        else{
            for(int i = 0; i < righe;i++){
                cambio = 0;
                passo = 0;
                divisione_date_file(x, passo, cambio, data, giorni, mesi, i);
                if(atoi(mesi[0]) == atoi(mesi[2]) && atoi(giorni[0]) <= atoi(giorni[2])){
                    printf("%s ", codice_tratta[i]);
                }
                else if(atoi(mesi[1]) == atoi(mesi[2]) && atoi(giorni[1]) >= atoi(giorni[2])){
                    printf("%s ", codice_tratta[i]);
                }
                else if(atoi(mesi[0]) < atoi(mesi[2]) && atoi(mesi[1]) > atoi(mesi[2])){
                    printf("%s ", codice_tratta[i]);
                }
            }
        }
    }
}
void partenza(char codice_tratta[][lun], char partenze[][lun], int righe, char dati[][lun]){
    char stampati[righe][lun];
    bool find = false;

    printf("Le tratte in partenza da '%s' sono: ", dati[1]);
   for(int i = 0;i < righe;i++){
       if(strcmp(partenze[i], dati[1]) == 0){
           for(int q = 0;q < righe;q++){
               if(strcmp(stampati[q],codice_tratta[q]) == 0){
                   find = true;
               }
           }
           if(find == false){
               printf("%s ", codice_tratta[i]);
               strcpy(stampati[i],codice_tratta[i]);
           }
           find = true;
       }
   }
}
void destinazione(char codice_tratta[][lun], char capolinea[][lun], int righe, char dati[][lun]){
    char stampati[righe][lun];
    bool find = false;

    printf("Le tratte con destinazione '%s' sono: ", dati[1]);
    for(int i = 0;i < righe;i++){
        if(strcmp(capolinea[i], dati[1]) == 0){
            for(int q = 0;q < righe;q++){
                if(strcmp(stampati[q], codice_tratta[q]) == 0){
                    find = true;
                }
            }
            if(find == false){
                printf("%s ", codice_tratta[i]);
                strcpy(stampati[i],codice_tratta[i]);
            }
            find = true;
        }
    }
}
void ritardo_tratta(char codice_tratta[][lun], char data[][lun], int righe, char dati[][lun], int ritardo[righe]){
    printf("Le corse arrivate a destinazione in ritardo, nell'arco di tempo selezionato, sono: ");

    char giorni[4][3], mesi[4][3];            // dai dati inseriti 0: inizio 1:fine 2:data elenco
    int somma = 0;
    for(int x = 1; x <= 3; x++){
        int passo = 0;
        int cambio = 0;
        if(x <= 2){
            divisione_date_utente(x, passo, cambio, dati, giorni, mesi);
        }
        else{
            for(int i = 0; i < righe;i++){
                cambio = 0;
                passo = 0;
                divisione_date_file(x, passo, cambio, data, giorni, mesi, i);
                if(atoi(mesi[0]) == atoi(mesi[2]) && atoi(giorni[0]) <= atoi(giorni[2]) && ritardo[i] != 0){
                    printf("%s ", codice_tratta[i]);
                }
                else if(atoi(mesi[1]) == atoi(mesi[2]) && atoi(giorni[1]) >= atoi(giorni[2]) && ritardo[i] != 0){
                    printf("%s ", codice_tratta[i]);
                }
                else if(atoi(mesi[0]) < atoi(mesi[2]) && atoi(mesi[1]) > atoi(mesi[2]) && ritardo[i] != 0){
                    printf("%s ", codice_tratta[i]);
                }
            }
        }
    }
}
void ritardotot(char codice_tratta[][lun], int ritardo[DIM], int righe, char dati[][lun]){
    int somma = 0;
    for(int i = 0; i < righe;i++){
        if(strcmp(codice_tratta[i],dati[1]) == 0){
            somma += ritardo[i];
        }
    }
    printf("Il ritardo totale della corsa %s e' %d", dati[1], somma);
}

int main(){
    FILE *fp = fopen("../corse.txt", "r");

    // array in cui salvo i valori presenti nel file
    char codice_tratta[DIM][lun], partenze[DIM][lun], capolinea[DIM][lun], data[DIM][lun], ora_p[DIM][lun], ora_a[DIM][lun];
    int ritardo[DIM];

    // comandi da poter utilizzare in input
    char sample_comandi[ncom][lun] = {"date", "partenza", "capolinea", "ritardo", "ritardo_tot", "fine"};

    // variabili che salvano l'input
    char comando[lun], dati[DIM][lun];

    // menù da stampare a schermo per la selezione del programma + informazioni su come inserire la data e uscire dal programma
    char menu[ncom][150] = {"1. elencare tutte le corse partite in un certo intervallo di date\n",
                            "2. elencare tutti le corse partite da una certa fermata (partenza)\n",
                            "3. elencare tutti le corse aventi una data destinazione (capolinea)\n",
                            "4. elencare tutte le corse che hanno raggiunto la destinazione in ritardo, in un certo intervallo di date\n",
                            "5. elencare il ritardo complessivo accumulato dalle corse identificate da un certo codice di tratta\n",
                            "?? usare la data in formato DD/MM/YYYY e il comando 'fine' per terminare il programma ??"};

    // variabili che uso nella prima parte per:
    int comando_e = 0, x = 0, y = 0;        // salvare gli input nell'array 'dati'
    int righe = 0;                          // salvare la prima riga del file
    bool find = false;                      // sapere se l'utente ha selezionato un comando presente o meno

    for(int i = 0;i<DIM;i++){
        for(int j = 0;j<lun;j++){
            codice_tratta[i][j] = ' ';
            partenze[i][j] = ' ';
            capolinea[i][j] = ' ';
            data[i][j] = ' ';
            ora_p[i][j] = ' ';
            ora_a[i][j] = ' ';
        }
        ritardo[i] = 0;
    }

    if(fp != NULL){
        fscanf(fp,"%d", &righe);
        lettura_file(fp, codice_tratta, partenze, capolinea, data, ora_p, ora_a, ritardo);
        for(int i = 0; i < ncom;i++){
            printf("%s", menu[i]);
        }

        // l'utente inserisce la stringa e la divido
        printf("\n >> Inserire il comando:");
        gets(comando);
        for(int i = 0;i < strlen(comando);i++){
            if(comando[i] == ' '){
                x++;
                y = 0;
            }
            else{
                dati[x][y] = comando[i];
                y++;
            }
        }

        // cerco il comando corrispondente
        for(int i = 0; i < ncom && find == false;i++){
            if(strcmp(sample_comandi[i], dati[0]) == 0){
                comando_e = i;
                find = true;
            }
        }
        if(find != false){
            switch (comando_e) {
                case 0:
                    date_corse(data, codice_tratta, righe, dati);
                    break;
                case 1:
                    partenza(codice_tratta, partenze, righe, dati);
                    break;
                case 2:
                    destinazione(codice_tratta, capolinea, righe, dati);
                    break;
                case 3:
                    ritardo_tratta(codice_tratta, data, righe, dati, ritardo);
                    break;
                case 4:
                    ritardotot(codice_tratta, ritardo, righe, dati);
                    return 0;
                case 5:
                    printf("Uscita dal programma");
                    return 0;
                default:
                    printf("Errore");
                    break;
            }
        }
        else{
            printf("Errore d'inserimento del comando");
        }
    }
    else{
        printf("\nErrore nell'apertura del file");
        return 0;
    }
    fclose(fp);
    return 0;
}