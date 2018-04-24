#ifndef add_a_b
#define add_a_b
#include "create.h"


void addAfter_Before_Fkt(char *addNameFkt) {
   char addName[MAX];
    double addNummer;
    tmp2 = front;

    while (tmp2->next != NULL) {
        tmp = tmp2->next;
        if(strcmp(tmp->Name, addNameFkt) == 0) {
     //           struct Fahrrad newBike = NULL;
           
                    printf("Name: ?\n");
                    scanf("%s", addName);
                    getchar();
                    printf("Nummer: ?\n");
                    scanf("%lf", &addNummer);
     newBike = malloc(sizeof(struct Fahrrad));
            newBike->Rahmennummer = addNummer;
            strcpy(newBike->Name, addName);
       //     tmp2->next = newBike; //   newBike->next = tmp; // davor einfügen
       newBike->next = tmp->next;  tmp->next = newBike; // danach einfügen
        break;
        }
        tmp2 = tmp;
    }
}

#endif