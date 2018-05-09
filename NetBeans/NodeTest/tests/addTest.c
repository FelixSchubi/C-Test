/*
 * File:   addTest.c
 * Author: felix
 *
 * Created on 09.05.2018, 08:59:18
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../add.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testAdd_Fkt() {
   
    add_Fkt("TestSuiteOne", 1234455678);
 //Adresse darf nach dem Funktionsaufruf nicht mehr NULL sein!   
    if(front == NULL) {
        CU_ASSERT(0); // Fehler
    } else {
        CU_ASSERT(1); // Erfolg
      }
 //wird das neue Element an die erste Stelle gestellt?
    printf("\nWird das Element an die erste Stelle gestellt?\n");
    if(strcmp(front->Name, "TestSuiteOne") == 0){
        CU_ASSERT(1);
    } else {
        CU_ASSERT(0);
    }
    
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("addTest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testAdd_Fkt", testAdd_Fkt))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    printf("\n\n**********************************************************");
    printf("\n**********************Nächste Suite***********************");
    printf("\n**********************************************************\n \n");
    return CU_get_error();
    
}
