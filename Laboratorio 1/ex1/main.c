#include <stdio.h>

int main() {
    int x,y;
    float z;

    printf("Inserisci un numero intero:");
    scanf("%d",&x);
    y = 3;
    z = (float)(x)/y;

    printf("%d/%d=%.3f\n",x,y,z);
    return 0;
}
