#ifndef delete
#define delete
#include <stdio.h>
#include <stdlib.h>
#include "askForAdd.h"



void deleteFunc(){

struct Node {
        char Na[MAX];
        char Vo[MAX];
        double Ma;
        struct Node *ptr;
    }*front,*rear,*tmp,*frontTMP,*tmp1,*tmp2;


char n[MAX];

        if(front == NULL){
        askForAddFunc();
        return;
    }
    if (front != NULL){
    printf("Namen der zu löschenden Person eingeben:\n");
    scanf("%s",n);
    
        if(strcmp(front->Na,n) == 0) {
            rear=front->ptr;
            free(front);
            front = rear;
            }
         else {
         tmp2=front;
         while(tmp2->ptr != NULL) {
            tmp1=tmp2->ptr;
            if(strcmp(tmp1->Na,n) == 0) {
              tmp2->ptr=tmp1->ptr;
               free(tmp1);
               break;
            }
            tmp2=tmp1;
         } 
      }   
   }      
}

#endif