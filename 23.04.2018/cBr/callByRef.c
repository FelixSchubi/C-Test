#include <stdio.h>
#include <stdlib.h>


void callByReference(int *first, int *sec) {
        int *tmp = malloc(sizeof(int));

        *tmp = *first;
        *first = *sec;
        *sec = *tmp;
}

void main(){

int x = 10;
int y = 15;

    printf("Zwei Werte: \n");
    printf("Erster: \t %d \n", x);
    printf("Zweiter: \t %d \n", y);
    
 callByReference(&x,&y);

printf("in main: \n");
    printf("Erster: \t %d \n", x);
    printf("Zweiter: \t %d \n", y);

}