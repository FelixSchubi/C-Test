#ifndef insertValues
#define insertValues
#include <add.h>

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
  //  CU_ASSERT_STRING_NOT_EQUAL("", name );
  //  CU_ASSERT_STRING_NOT_EQUAL("", vname );
   // CU_ASSERT_NOT_EQUAL(0, matr);


        add(name,vname,matr);
}

#endif
