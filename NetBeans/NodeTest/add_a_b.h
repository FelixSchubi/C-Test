/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   add_a_b.h
 * Author: felix
 *
 * Created on 7. Mai 2018, 15:57
 */

#ifndef add_a_b
#define add_a_b
#include "create.h"


void addAfter_Before_Fkt(char *addNameFkt) {
   char addName[MAX];
    double addNummer;
    tmp2 = front;

    while (tmp2->next != NULL) {
        tmp = tmp2->next;

if (strcmp(tmp2->Name, addNameFkt) == 0) {
                    printf("Name: ?\n");
                    scanf("%s", addName);
                    getchar();
                    printf("Nummer: ?\n");
                    scanf("%lf", &addNummer);
     newBike = malloc(sizeof(struct Fahrrad));
            newBike->Rahmennummer = addNummer;
            strcpy(newBike->Name, addName);
       //     tmp2->next = newBike; //   newBike->next = tmp; // davor einfügen
       newBike->next = tmp2->next;  tmp2->next = newBike; // danach einfügen
        break;
        }
        if (strcmp(tmp->Name, addNameFkt) == 0) {
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

