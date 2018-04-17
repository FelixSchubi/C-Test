#ifndef show
#define show
#include "askForAdd.h"
#include "printStudent.h"
#include <stdio.h>
#include <stdlib.h>
#include "process_node.c"

void showFunc(){



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