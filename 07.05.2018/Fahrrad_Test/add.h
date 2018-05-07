#ifndef add
#define add
#include "create.h"

void add_Fkt(char *bikeName, double bikeNumber) {
    if(front == NULL) {
        rear = malloc(sizeof(struct Fahrrad));
        rear->Rahmennummer = bikeNumber;
        strcpy(rear->Name, bikeName);
        rear->next = NULL;
        front = rear;
    } 
    else {
        tmp = front;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp2 = malloc(sizeof(struct Fahrrad));
        tmp2->Rahmennummer = bikeNumber;
        strcpy(tmp2->Name, bikeName);
        tmp2->next = NULL;
        tmp->next = tmp2;
   }
}

#endif