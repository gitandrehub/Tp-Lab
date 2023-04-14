#include <stdio.h>

int calcoloMCD(int A,int B,int MCD){
    for (;;){
        MCD = A % B;
        if (MCD == 0){
            printf("\nMCD = %d\n",B);
            break;
        }
        else{
            A = B;
            B = MCD;
        }
    }
    return 1;
}

int main(){
    int A,B,MCD;

    printf("Inserire il primo numero A:");
    scanf("%d",&A);
    printf("Inserire il secondo numero B:");
    scanf("%d",&B);

    if (A > 0 && B > 0){
        calcoloMCD(A,B,MCD);
    }
    else{
        MCD = (A==0) ? B : A;
        printf("\nMCD = %d\n",MCD);
        return 1;
    }
    return 0;
}