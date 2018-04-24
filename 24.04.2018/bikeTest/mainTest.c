
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "delete.h"
#include "show.h"
#include "add_a_b.h"
#include "add.h"
#include "create.h"

#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#define MAX 20

int i = 0; 
char fName[MAX];
double fNummer;

int init_suite(void)
{return 0;}

int clean_suite(void)
{return 0;}



void testCreate(){
    create_Fkt();
}

void testDazu(){
   
    printf("Name: ?\n");
                    scanf("%s", fName);
                    getchar();
                    printf("Nummer: ?\n");
                    scanf("%lf", &fNummer);
    add_Fkt(fName, fNummer);
}

void testDel(){
scanf("%s", fName);
        getchar();

    delete_Fkt(fName);
}



void testShow(){
   // CU_ASSERT_PTR_NOT_NULL_FATAL(front);
        show_Fkt();
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
     ||
    (NULL == CU_add_test(pSuite, "add", testDazu))
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
//    CU_basic_run_tests();
//    printf("\n");
//    CU_basic_show_failures(CU_get_failure_list());
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

