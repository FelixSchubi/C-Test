#ifndef add
#define add


void add (char *na,char *vo, double Matr){

    if (rear == NULL) {
        rear = malloc(sizeof(struct Node));
        strcpy(rear->Na,na);
        strcpy(rear->Vo,vo);
        rear->Ma = Matr;
        rear->ptr = NULL;
        front = rear;
        // Strings von Pointern vergleichen
      //  CU_ASSERT_STRING_EQUAL_FATAL(front->Na, na);
       // CU_ASSERT_STRING_EQUAL_FATAL(rear->Vo, front->Vo);
    }
    else {
        
        tmp = malloc(sizeof(struct Node));
        rear->ptr = tmp;
        strcpy(tmp->Na,na);
        strcpy(tmp->Vo,vo);
        tmp->Ma = Matr;
        tmp->ptr = NULL;
        rear = tmp; 
        }
        count++;
}

#endif