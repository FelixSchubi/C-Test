#include <stdio.h>
#include <stdlib.h>

struct Node {
    int test;
    struct Node *next;
}*front,*rear,*tmp,*tmp2;



void add(int x) {
    if (front == NULL) {
        tmp = malloc(sizeof(struct Node));
        tmp->next = NULL;
        tmp->test = x;
        front = tmp;
      //  free(tmp);
    }
    else {
        rear = front;
        while(rear->next != NULL) {
            rear = rear->next;
        }
        tmp = malloc(sizeof(struct Node));
        tmp->next = NULL;
        tmp->test = x;
        rear->next = tmp;
    }
  //  printf("add\n");
}

void deleteFirst(){
    tmp = front->next;
    free(front);
    front = tmp;
}

void deleteAll(){
    tmp = front->next;
    while (tmp != NULL) {
        tmp2 = front->next->next;
        front->next = tmp2;
        free(tmp);
        tmp = tmp2;
    }
    free(front->next);
    free(front);
    front = NULL;
    printf("Fertig gelöscht :)\n");
}



void deleteLast(){
    tmp = front;
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    tmp2 = tmp->next;
    tmp->next = NULL;
    free (tmp2);
}

void show(){
    if(front == NULL) {printf("Liste ist leer\n");return;}
    
    tmp = front;
    while (tmp->next != NULL) {
        printf("Wert: \t %d \n", tmp->test);
        tmp = tmp->next;
    }
    if (tmp->next == NULL) {
                printf("Wert: \t %d \n", tmp->test);
    }
}

 

int main(){
    
  //  create();
    add(5);
    add(3);
    add(8);
    add(123);
    add(9);
    show();
    deleteFirst();
    printf("After delFirst:\n");
    show();
    deleteLast();
    printf("After delLast:\n");
    show();
    deleteAll();
    show();
}