	
/*
 *           CUnit : A Unit testing framework for C.
 *           http://cunit.sourceforge.net/
 */


#include <stdio.h>
#include <string.h>
#include "CUnit/Basic.h"

/* Pointer to the file used by the tests. */
static FILE* temp_file = NULL;

/* The suite initialization function.
 * Opens the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int init_suite1(void)
{
   if (NULL == (temp_file = fopen("temp.txt", "w+"))) {
      return -1;
   }
   else {
      return 0;
   }
}

/* The suite cleanup function.
 * Closes the temporary file used by the tests.
 * Returns zero on success, non-zero otherwise.
 */
int clean_suite1(void)
{
   if (0 != fclose(temp_file)) {
      return -1;
   }
   else {
      temp_file = NULL;
      return 0;
   }
}

/* Simple test of fprintf().
 * Writes test data to the temporary file and checks
 * whether the expected number of bytes were written.
 */
void testFPRINTF(void)
{
   int i1 = 1;

   if (NULL != temp_file) {
      CU_ASSERT(0 == fprintf(temp_file, ""));
      CU_ASSERT(11 == fprintf(temp_file, "HelloWorld\n"));
      CU_ASSERT(8 == fprintf(temp_file, "Test: %d\n", i1));
      CU_ASSERT(41 == fprintf(temp_file, "https://github.com/FelixSchubi/C-Test.git"));

   }
}



//add myOwnTest
void myOwnTest (void) {
    int i = 5;
// int i;
// printf("Geben Sie eine Zahl ein\n");
// scanf("%d", &i);

    // wenn hier (i == 3) steht dann gibt es einen Fehler
    if (i == 5) {
      
        CU_PASS("CU_PASS");
    } else {
        CU_FAIL("CU_FALSE: Deine Zahl war leider nicht 5");
    }
}

void myPac(void){

    printf("ABLAUFSTEUERUNG");

    	int dimy = 10;
	int dimx = 10;
	int lvx =0;
	int lvy = 0;
	for(lvx = 0; lvx < dimx; lvx++){
		printf("%d\n", lvx);

		for(lvy = 0; lvy < dimy-lvx; lvy++){
			printf("-%d-", lvy);
			if(lvy % 3 == 0)
				printf("*\t");
			else if(lvy % 3 == 1)
				printf("-\t");
			else
				printf("~\t");
		}
		printf("\n");
	}
	printf("\n");
	for(lvx=0;lvx<10;lvx++)
		printf("-\t");
	printf("\n");
	for(lvx = 0; lvx < dimx; lvx++){
		for(lvy = 0; lvy < lvx; lvy++){
			if(lvx % 3 == 0)
				printf("*\t");
			else if(lvx % 3 == 1)
				printf("-\t");
			else if(lvx % 3 == 2)
				printf("[]\t");
			else
				printf("~\t");
		}
		printf("\n");

    }};


void testFREAD(void)
{
   unsigned char buffer[20];

   if (NULL != temp_file) {
      rewind(temp_file);

   }
}


int main()
{
   CU_pSuite pSuite = NULL;

   /* initialize the CUnit test registry */
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   /* add a suite to the registry */
   pSuite = CU_add_suite("Suite_1", init_suite1, clean_suite1);
   if (NULL == pSuite) {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* add the tests to the suite */
   /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
   if ((NULL == CU_add_test(pSuite, "test of fprintf()", testFPRINTF)) ||
       (NULL == CU_add_test(pSuite, "test of fread()", testFREAD)) ||
       (NULL == CU_add_test(pSuite, "test myPac()", myPac)) ||
       (NULL == CU_add_test(pSuite, "my own test()", myOwnTest)))
   {
      CU_cleanup_registry();
      return CU_get_error();
   }

   /* Run all tests using the CUnit Basic interface */
   CU_basic_set_mode(CU_BRM_VERBOSE);
   CU_basic_run_tests();
   CU_cleanup_registry();
   return CU_get_error();
}

