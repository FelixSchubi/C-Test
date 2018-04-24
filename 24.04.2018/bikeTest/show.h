#ifndef show
#define show
#include "create.h"

void show_Fkt(){
    tmp = front;
    if(tmp == NULL) {
        printf("Liste leer!!\n");
    }
    else {
    while(tmp->next != NULL) {
        printf("Name: \t%s\n", tmp->Name);
        printf("Nummer: \t%.0lf\n", tmp->Rahmennummer);
        tmp = tmp->next;
    }
    if(tmp->next == NULL) {
          printf("Name: \t%s\n", tmp->Name);
        printf("Nummer: \t%.0lf\n", tmp->Rahmennummer);
    }
    }
}

#endif