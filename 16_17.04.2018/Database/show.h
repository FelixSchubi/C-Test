#ifndef show
#define show
#include "askForAdd.h"
#include "printStudent.h"
#include <stdio.h>
#include <stdlib.h>


void showFunc(){

struct Node {
        char Na[MAX];
        char Vo[MAX];
        double Ma;
        struct Node *ptr;
    }*front,*rear,*tmp,*frontTMP,*tmp1,*tmp2;

    frontTMP = front;
    if( frontTMP == NULL) {
 // CU_ASSERT_PTR_NULL_FATAL(front);

      askForAddFunc();
    }
    else{
        printf("Hier Sind die Studenten:\n");

    while (frontTMP != NULL)
    { 
       printStudentFunc();
     
        frontTMP = frontTMP->ptr;
    }
    if (frontTMP == rear)
    // CU_ASSERT_PTR_NULL_FATAL()
         printStudentFunc();
     }
}

#endif