#include <stdio.h>
#include <string.h>
#define MAX 20


int strComp(char *str1, char *str2) {
char newStr[MAX];
strcpy(newStr, str1);

printf("newString:\t%s\n", newStr);
    if(strcmp(str1, str2)== 0) {
        return 1;
    }
    else {
        return 0;
    }
}


void main(){
    char Name[] = "12345678901234567890/234";
    char zwName[] = "Test";

    printf("Name:\t%s\n", Name);
    printf("zwName:\t%s\n", zwName);
    int Ergebnis =  strComp(Name, zwName);
    printf("Ergebnis: \t %d \n", Ergebnis);
}