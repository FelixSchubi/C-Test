
#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"


int init_suite(void)
{return 0;}

int clean_suite(void)
{return 0;}

void printINT(void) {
    int i = 0;
    printf("This ist the Function:  %d\n", i);
    if (i == 0) {
      
        CU_PASS("Here ist the Assert_> CU_PASS");
    } else {
        CU_FAIL("CU_FALSE");
    }
}

void someText(void) {
    CU_FAIL("Das ist die Nachricht für CU_FAIL");
}

int main()
{
   CU_pSuite pSuite = NULL;

   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   pSuite = CU_add_suite("Suite_1", init_suite, clean_suite);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   if ((NULL == CU_add_test(pSuite, "printINT", printINT) ||
   ( NULL == CU_add_test(pSuite, "some Text", someText))))
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

