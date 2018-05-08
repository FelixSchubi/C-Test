/*
 * File:   newcunittest.c
 * Author: felix
 *
 * Created on 08.05.2018, 08:36:49
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../weg.h"
#include "../show.h"
#include "../add_a_b.h"
#include "../add.h"
#include "../create.h"

#include "CUnit/Basic.h"
#include "CUnit/Console.h"
#include "CUnit/Automated.h"

#define MAX 20


double fNummer;

int init_suite(void)
{return 0;}

int clean_suite(void)
{return 0;}



void testCreate(){
       
    create_Fkt();
    CU_ASSERT_PTR_NOT_NULL_FATAL(front);
}

void testAdd_a_b(){
printf("Nach Wem: ?\n");
char nachWem[20] = "testDazu1";
    addAfter_Before_Fkt(nachWem);
}

void testDazu(){
  
                
                    float fNummer = 1;
                  char fName [20]= "dazu";
    add_Fkt(fName, fNummer);
}

void testFelix(){
  
                
                    float fNummer = 2;
                  char fName [20]= "Felix";
    add_Fkt(fName, fNummer);
}


void testMeier(){
  
                
                    float fNummer = 3;
                  char fName [20]= "Meier";
    add_Fkt(fName, fNummer);
}



void testDel(){

    printf("\nMeier wird gelöscht:!\n");
    
    char arr[20] = "Meier";

    delete_Fkt(arr);
}



void testShow(){
    printf("\nBeim Anzeigen darf front nicht mehr NULL sein!:\n");
    CU_ASSERT_PTR_NOT_NULL_FATAL(front);
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
    (NULL == CU_add_test(pSuite, "add", testFelix))
      ||
    (NULL == CU_add_test(pSuite, "add", testMeier))
 //   ||
  //  (NULL == CU_add_test(pSuite, "addAfter", testAdd_a_b))
  //  ||
  //  (NULL == CU_add_test(pSuite, "askForAdd", testAsFoAdd)
    ||
    (NULL == CU_add_test(pSuite, "show", testShow)
    ||  // Testen, ob das löschen funktionert!
    (NULL == CU_add_test(pSuite, "testDel", testDel)
    ||  // Nochmal anzeigen lassen um löschen zu überprüfen
    (NULL == CU_add_test(pSuite, "show", testShow) ))))
 
   
   
     CU_basic_set_mode(CU_BRM_VERBOSE);
 CU_basic_run_tests();         
  //  CU_automated_run_tests(); // entweder -> Oder!!
//    CU_cleanup_registry();
//    return CU_get_error();

 /* Run all tests using the basic interface */
  // CU_basic_set_mode(CU_BRM_VERBOSE);
//    CU_basic_run_tests();
//    printf("\n");
//    CU_basic_show_failures(CU_get_failure_list());

   /* Run all tests using the automated interface */
 //  CU_automated_run_tests();
 //  CU_list_tests_to_file();

   /* Run all tests using the console interface */
 //  CU_console_run_tests();



   /* Clean up registry and return */
   CU_cleanup_registry();
  return CU_get_error();
}
