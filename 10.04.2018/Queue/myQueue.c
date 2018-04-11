#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Basic.h"


int init_suite(void)
{return 0;}

int clean_suite(void)
{return 0;}

struct node {
    int data;
    struct node *ptr;
}*front, *rear, *tmp, *front1;

void create (){
    front = rear = NULL;
}

void enque (int v){
    if(rear == NULL) {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->data = v;
        rear->ptr = NULL;
        front = rear;
    }
    else {
        tmp = (struct node *)malloc(sizeof(struct node));
        rear-> ptr = tmp;
        tmp->data = v;
        tmp->ptr = NULL;
        rear = tmp;
    }
   CU_ASSERT_PTR_NOT_EQUAL(rear->ptr, rear);
}

void display()
{
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        CU_ASSERT_PTR_EQUAL(front1, rear);
        printf("Leer\n");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->data);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d\n", front1->data);
}

void show(){


int wert_global[5];

   static int wert_static[5];
   int wert_auto[5];
   int i;

   for(i = 0; i < 3; i++)
      printf("%d:\t%10d\t%10d\t%10d\n",
         i, wert_global[i], wert_static[i], wert_auto[i] );
 

}


void deque()
{
    front1 = front;
 
    if (front1 == NULL)
    {
        CU_ASSERT_PTR_NULL(front1);
        printf("\n Leer \n");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n Dequed value : %d\n", front->data);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n Dequed value : %d\n", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
}

void doWhile() {
   int y,x,c;

    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Display");
    printf("\n 0 - Exit");
    create();
    //check if create worked

   CU_ASSERT_PTR_NULL(front);
   CU_ASSERT_PTR_NULL(rear);
        

    for(int i = 0; i < 1;)
    {
        printf("Was tun?\n");
        scanf("%d", &c);
        switch(c) {
            
            case 0: i++;
                    break;
            case 1:
                    printf("Data to add?\n");
                    scanf("%d", &x);
                    getchar();
                    enque(x);
                    // es wird geprüft das der Pointer nicht NULL ist
                    CU_ASSERT_PTR_NOT_NULL_FATAL(rear);
                    break;
            case 2: deque();
                    break;
            CU_ASSERT_PTR_NULL(front);
            case 3: display();
                    break;
            case 4: show();
                    break;
        }
        
    }
return;

}





int main()
{
   CU_pSuite pSuite = NULL;

   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   pSuite = CU_add_suite("Suite1", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "doWhile", doWhile) ||
        (NULL == CU_add_test(pSuite, "addValueTest", enque))))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_automated_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

