#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Basic.h"

#define MAX 30

int i = 0;
int init_suite(void)
{return 0;}

int clean_suite(void)
{return 0;}

void printINT(void) {
    printf("This ist the Function:  %d\n", i);
    if (i == 0) {
        CU_PASS("Here ist the Assert_> CU_PASS");
    } else {
        CU_FAIL("CU_FALSE");
    }
}

void rechner(void) {
    printf("Zahl 1:\n");
    int x;
    scanf("%d", &x);
    getchar();
    printf("Zahl 2:\n");
    int y;
    scanf("%d", &y);
    getchar();
    printf("Rechenoperator?\n");
    char operator;
    scanf("%c", &operator);
    printf("%c", operator);
    switch (operator){
        case '+': 
           CU_ASSERT(plus(x,y) == x+y);
                break;
        case '-':
           CU_ASSERT(minus(x,y) == x-y);
    }
}

int plus(int a, int s){
    // Hier ist ein Fehler eingebaut
   int tmp = a- s;
   printf("\nDas Ergbnis aus %d + %d = %d\n", a, s, tmp);
   return tmp;
}

int minus(int a, int s){
   int tmp = a - s;
   printf("\nDas Ergbnis aus %d - %d = %d\n", a, s, tmp);
   return tmp;
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

   if ((NULL == CU_add_test(pSuite, "printINT", printINT)) ||
   (NULL == CU_add_test(pSuite, "Taschenrechner", rechner)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

