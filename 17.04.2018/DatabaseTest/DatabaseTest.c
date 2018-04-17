
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "delete.h"
#include "show.h"
#include "printStudent.h"
#include "askForAdd.h"
#include "add.h"
#include "CUnit/Basic.h"
#include "create.h"

#define MAX 20

int i = 0;
int init_suite(void)
{return 0;}

int clean_suite(void)
{return 0;}

void testCreate(){
    // Create Funktion muss erst mit Node verknüpft werden
    start();
}

void testDazu(){
    struct Node * tmp = dazu();
   // es wird geprüft ob der Pointer noch NULL ist
    CU_ASSERT_PTR_NOT_NULL(front);
    // haben die Pointer front und rear die gleichen Werte?
    CU_ASSERT_STRING_EQUAL(front->Na, rear->Na);
   printf("\nHier ist der Name: %s\n",front->Na);
}

/*
void testAsFoAdd(){
    asFoAd();
        // Ab hier dürfen die Strings nicht mehr gleich sein!!
            CU_ASSERT_STRING_NOT_EQUAL(front->Na, rear->Na);
                  printf("\nHier ist der Name: %s\n",rear->Na); 

}
*/

void testShow(){
    sh();
}

int main()
{
   CU_pSuite pSuite = NULL;

   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   pSuite = CU_add_suite("Database_Test_Suite", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }


if ((NULL == CU_add_test(pSuite, "create", testCreate))
    ||
    (NULL == CU_add_test(pSuite, "add", testDazu))
  //  ||
  //  (NULL == CU_add_test(pSuite, "askForAdd", testAsFoAdd)
    ||
    (NULL == CU_add_test(pSuite, "show", testShow) ))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();         
   // CU_automated_run_tests();  entweder -> Oder!!
   CU_cleanup_registry();
   return CU_get_error();
}

