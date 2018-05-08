/*
 * File:   showFunctionTest.c
 * Author: felix
 *
 * Created on 08.05.2018, 15:36:24
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../show.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
  //  printf("******************************************************************\n");
  //  printf("******************************************************************\n");
  //  printf("init third Suite\n");
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testShow_Fkt() {
    show_Fkt();
    if (1 /*check result*/) {
        CU_ASSERT(1);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("showFunctionTest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testShow_Fkt", testShow_Fkt))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
