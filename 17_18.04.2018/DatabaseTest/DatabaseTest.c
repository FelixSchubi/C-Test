
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "delete.h"
#include "show.h"
#include "printStudent.h"
#include "askForAdd.h"
#include "add.h"
#include "create.h"

#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

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
    
   // es wird geprüft ob der Pointer noch NULL ist
    CU_ASSERT_PTR_NOT_NULL(front);
    // haben die Pointer front und rear die gleichen Werte?
    CU_ASSERT_STRING_EQUAL(front->Na, rear->Na);
   printf("\nHier ist der Name: %s\n",front->Na);
   int i = 0;
   printf("Wie viele Einheiten sollen eingegeben werden?\n");
   scanf("%d", &i);
   for(int x = 0; x < i; x++){
    printf("%d.ter Student: \n", x+2);   
   dazu();
   CU_ASSERT_STRING_NOT_EQUAL(front->Na, rear->Na);
   }
}

void testDel(){
int tmp = count;
    del();
    CU_ASSERT_EQUAL_FATAL((tmp-1),count);
    printf("tmp: \t%d \n count:\t %d\n", tmp,count);
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
    CU_ASSERT_PTR_NOT_NULL_FATAL(front);
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

 struct Node * tmp = dazu();

if ((NULL == CU_add_test(pSuite, "create", testCreate))
    ||
    (NULL == CU_add_test(pSuite, "add", testDazu))
  //  ||
  //  (NULL == CU_add_test(pSuite, "askForAdd", testAsFoAdd)
    ||
    (NULL == CU_add_test(pSuite, "show", testShow)
    ||  // Testen, ob das löschen funktionert!
    (NULL == CU_add_test(pSuite, "testDel", testDel)
    ||  // Nochmal anzeigen lassen um löschen zu überprüfen
    (NULL == CU_add_test(pSuite, "show", testShow) ))))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

//     CU_basic_set_mode(CU_BRM_VERBOSE);
//     // CU_basic_run_tests();         
//     CU_automated_run_tests(); // entweder -> Oder!!
//    CU_cleanup_registry();
//    return CU_get_error();

 /* Run all tests using the basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   printf("\n");
   CU_basic_show_failures(CU_get_failure_list());
   printf("\n\n");

   /* Run all tests using the automated interface */
   CU_automated_run_tests();
   CU_list_tests_to_file();

   /* Run all tests using the console interface */
   CU_console_run_tests();



   /* Clean up registry and return */
   CU_cleanup_registry();
   return CU_get_error();
}

