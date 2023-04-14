#include <stdio.h>

# define pi 3.14

int main() {
    char geometria[2], lato[2];
    float val_lato, area;

    printf("Inserire la forma, il tipo di lato e il valore:");
    scanf("%s%s%f", &geometria, &lato, &val_lato);

    if (geometria[0] == 'C') {
        switch (lato[0]) {
            case 'D':
                area = pi * val_lato * (val_lato/4);
                break;
            case 'R':
                area = pi * val_lato * val_lato;
                break;
            default:
                printf("Errore nell'inserimento dei dati");
                return 1;
        }
    }
    else if (geometria[0] == 'Q') {
        switch (lato[0]) {
            case 'D':
                area = val_lato * (val_lato / 2);
                break;
            case 'L':
                area = val_lato * val_lato;
                break;
            default:
                printf("Errore nell'inserimento dei dati");
                return 2;
        }
    }
    else {
        printf("Errore nell'inserimento dei dati");
        return 3;
    }
    printf("L'area e': %.2f", area);
    return 0;
}