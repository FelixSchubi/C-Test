/*
 * File:   wegTest.c
 * Author: felix
 *
 * Created on 09.05.2018, 09:03:05
 */

#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../weg.h"
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

void testDelete_Fkt() {
    char* delName;
    int am;
   
    add_Fkt("Meier", 893465934);
    add_Fkt("Test", 0143567534);
    am = count(0);
    printf("Anzahl vor dem löschen: \t %d\n", am);
    delete_Fkt("Test");
    int ai;
    ai = count(0);
    printf("Anzahl nach dem löschen: \t %d\n", ai);
}

int count(int x){
    int amount = 0;
    tmp = front;
    while(tmp != NULL) {
        amount++;
        tmp = tmp->next;
    }
    return amount;
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("wegTest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testDelete_Fkt", testDelete_Fkt))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    printf("\n\n**********************************************************");
    printf("\n********************** ENDE ***********************");
    printf("\n**********************************************************\n \n");
    return CU_get_error();
}
