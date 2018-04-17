#ifndef askForAdd
#define askForAdd
#include <stdio.h>
#include <stdlib.h>
#include "add.h"



void askForAddFunc(){

#include "process_node.c"


    int tmpSc = 0;
     printf("Die Liste ist Leer\n Student hinzufügen?\n");
         TEST:
         if (tmpSc>0){
             printf("Auf Rechtschreibung achten!\n");
         }
         tmpSc++;
        printf("Eingeben:\n Ja \t Nein\n");
        char ans[MAX];
        scanf("%s", ans);
        getchar();
        if(strcmp("Ja",ans)==0) {
            addFunc();
        }
        else if(strcmp("Nein", ans)==0) {
            return ;
        }
        else {
            printf("Vertippt?\n");
       //     CU_ASSERT_FALSE("Weder Ja noch Nein eingegeben");
            goto TEST;
        }
}

#endif