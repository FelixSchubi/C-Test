#ifndef show
#define show
#include "askForAdd.h"
#include "printStudent.h"

void sh(){

    struct Node {
        char Na[MAX];
        char Vo[MAX];
        double Ma;
        struct Node *ptr;
    }*front,*rear,*tmp,*frontTMP,*tmp1,*tmp2;

    frontTMP = front;
    if( frontTMP == NULL) {

      asFoAd();
    }
    else{
        printf("Hier Sind die Studenten:\n");
    int tmp = 1;
    while (frontTMP != NULL)
    { 
       priStu();
        tmp++;
        frontTMP = frontTMP->ptr;
    }
    if (frontTMP == rear)
         priStu();
     }
}

#endif