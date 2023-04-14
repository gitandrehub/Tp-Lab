#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write_odd, *fp_write_even;
    char file_string[100], name[20];
    int counter = 0;

    if((fp_read = fopen("C:/Users/andre/Desktop/Poli/Tecniche di programmazione/C/Laboratori/Laboratorio 1/ex3/Bronte.txt","r"))==NULL){
        printf("Errore di apertura del file1\n");
        return 1;
    }
    if((fp_read = fopen("/prova.txt","w"))==NULL){
        printf("Errore di apertura del file2\n");
        return 2;
    }
    if((fp_read = fopen("C:/Users/andre/Desktop/Poli/Tecniche di programmazione/C/Laboratori/Laboratorio 1/ex3/Output_even.txt","w"))==NULL){
        printf("Errore di apertura del file3\n");
        return 3;
    }

    printf("Qual'e' il tuo nome?");
    gets(name);

    while(!feof(fp_read)){
        counter++;
        if(counter %2== 0){
            fscanf(fp_read,"%s", file_string);
            if(!feof(fp_read)){
                printf("%s\nI am reading:\n%s\n\n",name,file_string);
                fprintf(fp_write_even,"%s", file_string);
            }
        }
        else{
            fgets(file_string,100, fp_read);
            if(!feof(fp_read)){
                puts(name);
                puts("I am reading:");
                puts(file_string);
                fputs(file_string,fp_write_odd);
            }
        }
    }
    fclose(fp_read);
    fclose(fp_write_odd);
    fclose(fp_write_even);

    return 0;
}
