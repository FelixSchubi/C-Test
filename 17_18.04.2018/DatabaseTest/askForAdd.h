#ifndef askForAdd
#define askForAdd
#define MAX 20
#include "add.h"
#include <string.h>

void asFoAd(){




    int tmp = 0;
     printf("Die Liste ist Leer\n Student hinzufügen?\n");
         TEST:
         if (tmp>0){
             printf("Auf Rechtschreibung achten!\n");
         }
         tmp++;
        printf("Eingeben:\n Ja \t Nein\n");
        char ans[MAX];
        scanf("%s", ans);
        getchar();
        if(strcmp("Ja",ans)==0) {
            dazu();
        }
        else if(strcmp("Nein", ans)==0) {
            return ;
        }
        else {
            printf("Vertippt?\n");
            goto TEST;
        }
}

#endif