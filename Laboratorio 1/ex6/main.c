#include <stdio.h>

// Function to calculate operations
float operation(char operator, float op1, float op2){
    float result;
    switch (operator) {
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
    return result;
}

int main() {
    char operator,file_string[50];
    float op1, op2;
    FILE *fp_read, *fp_write;

    // Opening and controlling files
    if((fp_read = fopen("../Operazioni.txt","r")) == NULL){
        printf("Error opening file\n");
        return 1;
    }

    if((fp_write = fopen("../Output.txt","w")) == NULL){
        printf("Error opening file\n");
        return 2;
    }

    // Reading and using strings
    while(!feof(fp_read)){
        fscanf(fp_read,"%c%f%f\n",&operator,&op1,&op2);
        fprintf(fp_write,"%c %.2f\n",operator, operation(operator,op1,op2));
    }
    fclose(fp_read);
    fclose(fp_write);
    return 3;
}