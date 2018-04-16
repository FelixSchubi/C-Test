#ifndef show
#define show
#include <askForAdd.h>
#include <printStudent.h>

void show(){
    frontTMP = front;
    if( frontTMP == NULL) {
 // CU_ASSERT_PTR_NULL_FATAL(front);

      askForAdd();
    }
    else{
        printf("Hier Sind die Studenten:\n");
    int tmp = 1;
    while (frontTMP != NULL)
    { 
       printStudent(tmp);
        tmp++;
        frontTMP = frontTMP->ptr;
    }
    if (frontTMP == rear)
    // CU_ASSERT_PTR_NULL_FATAL()
         printStudent(tmp);
     }
}

#endif