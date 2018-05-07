/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   newmain.c
 * Author: felix
 *
 * Created on 7. Mai 2018, 14:17
 */

#include <stdio.h>
#include <stdlib.h>

long factorial(int arg) {
    long result = 1;
    int i;
    for (i = 2; i <= arg; ++i) {
        result *= i;
     }
    return result;
}

int plus(int h, int i) {
    int tmp = h+i;
    return tmp;
}

int main(int argc, char** argv) {
    printf("Type an integer and press Enter to calculate the integer's factorial: \n");
    int arg;
    fflush(stdout);
    scanf("%d", &arg);
    
    printf("factorial(%d) = %ld\n", arg, factorial(arg));
    
    printf("Das ist ein Test \n");
    int x = 2;
    int y = 10;
    int Ergebnis = plus(x,y);
    printf("Ergebnis ist: \t %d", Ergebnis);

    return (EXIT_SUCCESS);
}
 