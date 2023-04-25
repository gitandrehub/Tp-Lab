#include <stdio.h>

int main(){
    int val = 0, vettore[30], ind = 0;
    while(val != -1){
        printf("Inserire numero:");
        scanf("%d",&val);
        vettore[ind] = val;
        ind ++;
    }
    for(int i = 0;i < ind;i++){
        printf("%d - ",vettore[ind]);
    }
}