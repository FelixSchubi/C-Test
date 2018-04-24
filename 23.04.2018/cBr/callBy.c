#include <stdio.h>


void callByReference(int x, int y) {
    printf("x :%d\n", x);
    printf("y :%d\n", y);
    int tmp = x;
    x = y;
    y = tmp;
printf("Danach:\n");
    printf("x :%d\n", x);
    printf("y :%d\n", y);
}

int main(){

int x = 10;
int y = 15;

    printf("Zwei Werte: \n");
    printf("Erster: \t %d \n", x);
    printf("Zweiter: \t %d \n", y);
    callByReference(x,y);
        // printf("2. Runde\n");
        // callByReference(y,x);
printf("in main: \n");
    printf("Erster: \t %d \n", x);
    printf("Zweiter: \t %d \n", y);
}