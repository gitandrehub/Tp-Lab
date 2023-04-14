#include <stdio.h>

int main(){
    int precedente1, precedente2, X;
    int N;

    printf("Inserire quanti numeri della serie visualizzare:");
    scanf("%d",&N);

    for(int i = 0;N != i; i++){
        if (i == 0){
            printf("1 ");
        }
        else if (i == 1){
            printf("2 ");
            precedente1 = 2;
            precedente2 = 1;
        }
        else {
            X = precedente1 * precedente2;
            printf("%f ",X);
            precedente2 = precedente1;
            precedente1 = X;
        }
    }
}
