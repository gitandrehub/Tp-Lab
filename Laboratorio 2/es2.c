#include <stdio.h>

int main(){
    int N, precedente1, precedente2, X;

    printf("Inserire quanti numeri della serie visualizzare:");
    scanf("%d",&N);

    for(int i = 0;N != i; i++){
        if (i == 0){
            printf("0 ");
        }
        else if (i == 1){
            printf("1 ");
            precedente1 = 1;
            precedente2 = 0;
        }
        else {
            X = precedente1 + precedente2;
            printf("%d ",X);
            precedente2 = precedente1;
            precedente1 = X;
        }
    }
}