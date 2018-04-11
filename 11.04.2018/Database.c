

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20

int count;

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
    printf("----------------------------------------\n");
        printf("Student Nummer: %d\n",x);
        printf("Name: %s \n", frontTMP->Na);
        printf("Vorname: %s \n", frontTMP->Vo);
        printf("Matrikelnummer: %.0lf\n", frontTMP->Ma);
        printf("----------------------------------------\n");
}

void show(){
    frontTMP = front;
    if( frontTMP == NULL) {
      askForAdd();
    }
    else{
        printf("Hier Sind die Studenten:\n");
    int tmp = 1;
    while (frontTMP != rear)
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

int main(){

int x,y,sw;
char n[MAX];

    printf("1. Add\n");
    printf("2. Show\n");
    printf("3. Delete\n");
    printf("4. Amount\n");
    printf("0. Stop\n");
   // buildNode();
    create();
    while(1) {
        printf("Todo?\n");
        scanf("%d", &sw);
        switch(sw) {
            case 0: exit(0);
                    break;
            case 1: insertValues();
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