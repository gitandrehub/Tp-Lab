#include <stdio.h>
#include <stdlib.h>

int main(){
    char giorni[2][3] = {"23", "24"};
    if(atoi(giorni[0]) < atoi(giorni[1])){
        printf("yes");
    }
}