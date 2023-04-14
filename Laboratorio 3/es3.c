#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define filein "../numeri.txt"

bool verifica(int number, int x1, int x2){
    bool exist = false;
    if(x1+x2 == number || abs(x2-x1) == abs(number) ||  x2*x1 == number || (float) x2/x1 == (float) number || (float) x1/x2 == (float) number){
        exist = true;
    }
    return exist;
}

int main(){
    FILE *fin = fopen(filein,"r");
    int storico[100];
    int number = 0, max = 0, min = 0, scarti = 0, letti = 0, x1 = 0, x2 = 0;

    while(!feof(fin)){
        fscanf(fin, "%d",&number);
        if(letti >= 2){
            x1 = storico[letti-1];
            x2 = storico[letti-2];
            if(!verifica(number, x1, x2)){
                scarti ++;
            }
            else {
                storico[letti] = number;
                letti ++;
                max = (number > max) ? number : max;
                min = (number < min) ? number : min;
            }
        }
        else{
            storico[letti] = number;
            letti ++;
            max = (number > max) ? number : max;
            min = (number < min) ? number : min;
        }

    }
    printf("Numero massimo: %d\nNumero minimo: %d\nNumeri scartati: %d", max,min,scarti);
    return 0;
}