

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "delete.h"
#include "show.h"
#include "printStudent.h"
#include "askForAdd.h"
#include "add.h"
#include "begin.h"

#define MAX 20

int count;

 extern struct Node {
        char Na[MAX];
        char Vo[MAX];
        double Ma;
        struct Node *ptr;
    }*front, *rear,*tmp,*frontTMP,*tmp1,*tmp2;



void amount(){
    printf("Anzahl der Studenten:\t%d\n", count);
}

int main(){

int x,y,sw;
char n[MAX];

    printf("1. Add\n");
    printf("2. Show\n");
    printf("3. Delete\n");
    printf("4. Amount\n");
    printf("0. Stop\n");
    start();
    while(1) {
        printf("Todo?\n");
        scanf("%d", &sw);
        switch(sw) {
            case 0: exit(0);
                    break;
            case 1: addFunc();
                    break;
            case 2: showFunc();
                    break;
            case 3: deleteFunc();
                    break;
            case 4: amount();
                    break;
        }
    }

}