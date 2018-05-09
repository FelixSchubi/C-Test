/*
 * File:   createTest.c
 * Author: felix
 *
 * Created on 09.05.2018, 09:02:27
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../create.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testCreate_Fkt() {
    printf("\n Ist nach dem Funktionsaufruf der front Pointer wieder auf NULL?\n");
    create_Fkt();
  //   Der front Pointer muss nach der createFunktion NULL sein!
    CU_ASSERT_PTR_NULL(front);
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("createTest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCreate_Fkt", testCreate_Fkt))) {
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
