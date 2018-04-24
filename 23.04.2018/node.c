#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

struct Node {
    char Name[MAX];
    int Alter;
    struct Node *next;
    struct Node *prev;
}*front,*rear,*tmp,*bev;

void create(){
    front = rear = NULL;
}

void add(){

char nam[MAX];
printf("Name: \n");
scanf("%s", nam);
getchar();
int alt;
printf("Alter: \n");
scanf("%d", &alt);
getchar();

    if(front == NULL) {
        rear = malloc(sizeof(struct Node));
        rear->Alter = alt;
        strcpy(rear->Name, nam);
        rear->next = NULL;
        rear->prev = NULL;
        front = rear;
    }
    else {
    while(rear->next != NULL) {
        rear = rear->next;
    }
        rear->next = malloc(sizeof(struct Node));
        rear = rear->next;
         rear->Alter = alt;
        strcpy(rear->Name, nam);
        rear->next = NULL;
        rear->prev = NULL;
    }
}

void show(){
    tmp = front;
    while(tmp != NULL){
        printf("Name :\t %s\n Alter : \t %d \n",tmp->Name, tmp->Alter);
        tmp = tmp->next;
    }
}

void delFirst() {
    if(front == NULL) {return;}
    tmp = front->next;
    free(front);
    front = tmp;
}

void delAfter(){
    char after[MAX];
    printf("Nach wem?\n");
    scanf("%s", after);
    getchar();
tmp = front;
while(strcmp(tmp->Name, after) != 0) {
    tmp->prev = tmp;
    tmp = tmp->next;
}
printf("Name //AFTER//: \t %s\n", tmp->Name);
printf("Name //Prev//: \t %s\n", tmp->prev->Name);
}


void main(){
    int sw;
    create();
    printf("1. Add\n");
    printf("3. Show\n");
    printf("4. delFirst\n");
    printf("5. delAfter\n");
    printf("0. End\n");

while(1) {
        printf("Was machen?\n");
        scanf("%d", &sw);
        switch(sw){
            case 0: // end();
                    break;
            case 1: add();
                    break;
            case 3: show();
                    break;
            case 4: delFirst();
                    break;
            case 5: delAfter();
                    break;
        }
    }
    
}