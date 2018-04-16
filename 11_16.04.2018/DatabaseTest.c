
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void insertValues(){
    char name[MAX];
char vname[MAX];
double matr;
                    printf("Name: \n");
                    scanf("%s", name);
                    getchar();
                    printf("Vorname: \n");
                    scanf("%s", vname);
                    getchar();
                    printf("Matrikelnummer: \n");
                    scanf("%lf", &matr);
                    getchar();
    CU_ASSERT_STRING_NOT_EQUAL("", name );
    CU_ASSERT_STRING_NOT_EQUAL("", vname );
    CU_ASSERT_NOT_EQUAL(0, matr);


        add(name,vname,matr);
}

void add (char *na,char *vo, double Matr){

    if (rear == NULL) {
        rear = malloc(sizeof(struct Node));
        strcpy(rear->Na,na);
        strcpy(rear->Vo,vo);
        rear->Ma = Matr;
        rear->ptr = NULL;
        front = rear;
    }
    else {
        
        tmp = malloc(sizeof(struct Node));
        rear->ptr = tmp;
        strcpy(tmp->Na,na);
        strcpy(tmp->Vo,vo);
        tmp->Ma = Matr;
        tmp->ptr = NULL;
        rear = tmp; 
        }
        count++;
}

void askForAdd(){
    int tmp = 0;
     printf("Die Liste ist Leer\n Student hinzufügen?\n");
         TEST:
         if (tmp>0){
             printf("Auf Rechtschreibung achten!\n");
         }
         tmp++;
        printf("Eingeben:\n Ja \t Nein\n");
        char ans[MAX];
        scanf("%s", ans);
        getchar();
        if(strcmp("Ja",ans)==0) {
            insertValues();
        }
        else if(strcmp("Nein", ans)==0) {
            return ;
        }
        else {
            printf("Vertippt?\n");
            goto TEST;
        }
}

void printStudent(int x){
    CU_ASSERT_PTR_NOT_NULL(frontTMP->Na);
    if (frontTMP->Na == NULL){
        return;
    }
    else {
    printf("----------------------------------------\n");
        printf("Student Nummer: %d\n",x);
        printf("Name: %s \n", frontTMP->Na);
        printf("Vorname: %s \n", frontTMP->Vo);
        printf("Matrikelnummer: %.0lf\n", frontTMP->Ma);
        printf("----------------------------------------\n");
}
}

void show(){
    frontTMP = front;
    if( frontTMP == NULL) {
      askForAdd();
    }
    else{
        printf("Hier Sind die Studenten:\n");
    int tmp = 1;
    while (frontTMP != NULL)
    { 
        printStudent(tmp);
        tmp++;
        frontTMP = frontTMP->ptr;
    }
    if (frontTMP == rear)
         printStudent(tmp);
     }
}

void delete(){
char n[MAX];

        if(front == NULL){
        askForAdd();
        return;
    }
    if (front != NULL){
    printf("Namen der zu löschenden Person eingeben:\n");
    scanf("%s",n);
    
        if(strcmp(front->Na,n) == 0) {
            rear=front->ptr;
            free(front);
            front = rear;
            }
         else {
         tmp2=front;
         while(tmp2->ptr != NULL) {
            tmp1=tmp2->ptr;
            if(strcmp(tmp1->Na,n) == 0) {
              tmp2->ptr=tmp1->ptr;
               free(tmp1);
               break;
            }
            tmp2=tmp1;
         } 
      }   
   }      
   count--;
}



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

