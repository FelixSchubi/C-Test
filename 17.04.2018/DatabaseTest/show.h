#ifndef show
#define show
#include "askForAdd.h"
#include "printStudent.h"
#include "add.h"


void sh(){

 // struct Node * tmp = dazu();


    frontTMP = front;
    if( frontTMP == NULL) {

      asFoAd();
    }
    else{
        printf("Hier Sind die Studenten:\n");

    //  while (frontTMP != NULL)
    // { 
    //    priStu();
      
    //     frontTMP = frontTMP->ptr;
    // }
    if (frontTMP != NULL)
         priStu();
     }
}

#endif