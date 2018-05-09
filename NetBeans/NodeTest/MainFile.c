
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "weg.h"
//#include "show.h"
//#include "add_a_b.h"
//#include "add.h"
//#include "create.h"



#define MAX 20

int i = 0; 
char fName[MAX];
double fNummer;


int main()
{
    int sw;
 //   create_Fkt();
    printf("1. Add\n");
    printf("2. Add_After\n");
    printf("3. Delete\n");
    printf("4. Show\n");
    printf("0. End\n");
while(1) {
    printf("Todo?\n");
    scanf("%d", &sw);
    switch(sw) {
        case 1: printf("Name?\n");
                scanf("%s", fName);
                getchar();
                printf("Nummer?\n");
                scanf("%lf", &fNummer);
        //        add_Fkt(fName, fNummer);
                break;
        case 2: printf("Nach Wem?\n");
                scanf("%s", fName);
                getchar();
        //        addAfter_Before_Fkt(fName);
                break;
        case 3: printf("Wen Löschen?\n");
                scanf("%s", fName);
                getchar();
          //      delete_Fkt(fName);
                break;
        case 4:// show_Fkt();
                break;
        case 0: return 0;
                break;
    }
}

}
