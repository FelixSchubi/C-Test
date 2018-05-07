#ifndef add
#define add
#define MAX 20
#include <stdio.h>

 struct Node {
        char Na[MAX];
        char Vo[MAX];
        double Ma;
        struct Node *ptr;
    }*front,*rear,*tmp,*frontTMP,*tmp1,*tmp2;

int count = 0;

struct Node *dazu(){

       

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
    int p = sizeof(struct Node);
    printf("SUPRISE: \t %d", p);

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
        count++;
   return front;
}

#endif