#ifndef askForAdd
#define askForAdd

#import <insertValues.h>

void askForAdd(){
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
            insertValues();
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