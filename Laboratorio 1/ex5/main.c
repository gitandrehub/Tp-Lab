#include <stdio.h>

int main() {
    char operator;
    float op1, op2, result;

    // Entering parameters
    printf("Enter operator:");
    operator = getchar();
    printf("Enter numbers:");
    scanf("%f%f",&op1,&op2);

    // Calculation of operations
    switch (operator){
        case '+':
            result = op1+op2;
            break;
        case '-':
            result = op1-op2;
            break;
        case '*':
            result = op1*op2;
            break;
        case '/':
            result = op1/op2;
            break;
        default:
            printf("Error in data entry\n");
            return 0;
    }
    printf("%c %.2f", operator,result);
}

/*
 Approfondimento: Cosa succede quando op2 è uguale a 0?

 Quando op2 è pari a 0:
 - se somma o differenza allora l'operazione è pari a op1
 - se prodotto allora l'operazione è pari a 0
 - se rapporto allora l'operazione vale infinito:
        . + infinito nel caso in cui op1 > 0
        . - infinito nel caso in cui op1 < 0
 */
