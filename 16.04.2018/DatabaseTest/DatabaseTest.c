
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <delete.h>
#include <show.h>
#include <printStudent.h>
#include <askForAdd.h>
#include <add.h>
#include <insertValues>
#include "CUnit/Basic.h"
#define MAX 20

int i = 0;
int init_suite(void)
{return 0;}

int clean_suite(void)
{return 0;}


int count;
int test;
int secTest = 0;

    struct Node {
        char Na[MAX];
        char Vo[MAX];
        double Ma;
        struct Node *ptr;
    }*front,*rear,*tmp,*frontTMP,*tmp1,*tmp2;
// Compilerzwecke
void add (char *na,char *vo, double Matr);

void create (){
    front = rear = NULL;
    test = 1;
}

void insertValues();
void add (char *na,char *vo, double Matr);
void askForAdd();
void printStudent(x);
void show();
void delete();
void amount(){
    printf("Anzahl der Studenten:\t%d\n", count);
}



void mainFunc(){
    CU_PASS("mainFunc() gestartet");
    int x,y,sw;
char n[MAX];

    printf("1. Add\n");
    printf("2. Show\n");
    printf("3. Delete\n");
    printf("4. Amount\n");
    printf("0. Stop\n");
   // buildNode();1
   
    create();

    if (test = 1){
        CU_ASSERT_PTR_NULL(front);
        CU_PASS("create()function");
    }
    else {
        CU_FAIL("create() fail");
    }
    while(1) {
    CU_ASSERT_EQUAL_FATAL(secTest, 0) ;
        printf("Todo?\n");
        scanf("%d", &sw);
        switch(sw) {
            case 0: secTest = 1;
                    return ;
                    break;
            case 1: insertValues();
                    //front darf nicht mehr NULL sein
                    CU_ASSERT_PTR_NOT_NULL(front);
                    // count darf nicht mehr 0 sein
                    CU_ASSERT_TRUE(count);
                    break;
            case 2: show();
                    break;
            case 3: delete();
                    break;
            case 4: amount();
                    break;
        }
    }
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



if ((NULL == CU_add_test(pSuite, "Database", mainFunc)))
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

