#ifndef delete
#define delete
#include "create.h"

void delete_Fkt(char *delName) {

    if(front == NULL) {
        printf("Liste ist Leer!\n");
        return;
    }
    if(strcmp(front->Name, delName) == 0) {
        tmp = front->next;
        free(front);
        front = tmp;
    }
    else {
        // Bestimmt Person löschen
        tmp2 = front;
        while(tmp2->next != NULL) { 
            tmp = tmp2->next;   // tmp ist das aktuelle Element
            if(strcmp(tmp->Name, delName) == 0) {   // überprüfen, ob die eingegebenen Daten übereinstimmen
                tmp2->next = tmp->next; // wenn ja ist "tmp2->next" nicht einfach "tmp" sondern "tmp->next" also das nächste Element
                free(tmp);
                break;
            }
            tmp2 = tmp; // wenn die eingegebenen Daten nicht gleich sind wird das nächste Element geprüft
        }                   // aufgrund der while Schleife

    }
}

#endif