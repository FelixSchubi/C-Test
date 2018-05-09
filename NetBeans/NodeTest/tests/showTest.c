/*
 * File:   showTest.c
 * Author: felix
 *
 * Created on 09.05.2018, 09:02:44
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../show.h"
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

void testShow_Fkt() {
    add_Fkt("TestShowFunktion", 1234455678);
    printf("\n");
    show_Fkt();
    if (front != NULL) {
        CU_ASSERT(1);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("showTest", init_suite, clean_suite);
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
     printf("\n\n**********************************************************");
    printf("\n**********************Nächste Suite***********************");
    printf("\n**********************************************************\n \n");
    return CU_get_error();
}
