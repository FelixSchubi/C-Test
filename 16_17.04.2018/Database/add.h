#ifndef add
#define add
#define MAX 20
#include <stdio.h>
#include <stdlib.h>



void addFunc() {

struct Node {
        char Na[MAX];
        char Vo[MAX];
        double Ma;
        struct Node *ptr;
    }*front,*rear,*tmp,*frontTMP,*tmp1,*tmp2;


    char name[MAX];
char vname[MAX];
double matr;
                    printf("Name: \n");
                    scanf("%s", name);
                    getchar();
                    printf("Vorname: \n");
                    scanf("%s", vname);
                    getchar();
                    printf("Matrikelnummer: \n");
                    scanf("%lf", &matr);
                    getchar();


    if (rear == NULL) {
        rear = malloc(sizeof(struct Node));
        strcpy(rear->Na,name);
        strcpy(rear->Vo,vname);
        rear->Ma = matr;
        rear->ptr = NULL;
        front = rear;
    }
    else {
        
        tmp = malloc(sizeof(struct Node));
        rear->ptr = tmp;
        strcpy(tmp->Na,name);
        strcpy(tmp->Vo,vname);
        tmp->Ma = matr;
        tmp->ptr = NULL;
        rear = tmp; 
        }
    }

#endif