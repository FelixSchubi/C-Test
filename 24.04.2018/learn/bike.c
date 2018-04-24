// Schreiben Sie eine Datenstruktur "Fahrrad", welche Rahmennummer, 
// Ganganzahl, Herstellername und Modell ablegen kann.
// Weisen Sie einer Struktur "Fahrrad" Speicherplatz zu.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct Fahrrad {
    double Rahmennummer;
    char Name[MAX];
    struct Fahrrad *next;
}*front,*rear,*tmp,*tmp2,*newBike;

void create(){
    front = rear = NULL;
}

void add(char *bikeName, double bikeNumber) {
    if(front == NULL) {
        rear = malloc(sizeof(struct Fahrrad));
        rear->Rahmennummer = bikeNumber;
        strcpy(rear->Name, bikeName);
        rear->next = NULL;
        front = rear;
    } 
    else {
        tmp = front;
        while(tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp2 = malloc(sizeof(struct Fahrrad));
        tmp2->Rahmennummer = bikeNumber;
        strcpy(tmp2->Name, bikeName);
        tmp2->next = NULL;
        tmp->next = tmp2;
   }
}

void show(){
    tmp = front;
    if(tmp == NULL) {
        printf("Liste leer!!\n");
    }
    else {
    while(tmp->next != NULL) {
        printf("Name: \t%s\n", tmp->Name);
        printf("Nummer: \t%.0lf\n", tmp->Rahmennummer);
        tmp = tmp->next;
    }
    if(tmp->next == NULL) {
          printf("Name: \t%s\n", tmp->Name);
        printf("Nummer: \t%.0lf\n", tmp->Rahmennummer);
    }
    }
}


void delete(char *delName) {

    if(front == NULL) {
        printf("Liste ist Leer!\n");
        return;
    }
    if(strcmp(front->Name, delName) == 0) {
        tmp = front->next;
        free(front);
        front = tmp;
    }
    else {
        // Bestimmt Person löschen
        tmp2 = front;
        while(tmp2->next != NULL) { 
            tmp = tmp2->next;   // tmp ist das aktuelle Element
            if(strcmp(tmp->Name, delName) == 0) {   // überprüfen, ob die eingegebenen Daten übereinstimmen
                tmp2->next = tmp->next; // wenn ja ist "tmp2->next" nicht einfach "tmp" sondern "tmp->next" also das nächste Element
                free(tmp);
                break;
            }
            tmp2 = tmp; // wenn die eingegebenen Daten nicht gleich sind wird das nächste Element geprüft
        }                   // aufgrund der while Schleife

    }
}

void addAfter_Before(char *addNameFkt) {
   char addName[MAX];
    double addNummer;
    tmp2 = front;

    while (tmp2->next != NULL) {
        tmp = tmp2->next;
        if(strcmp(tmp->Name, addNameFkt) == 0) {
     //           struct Fahrrad newBike = NULL;
           
                    printf("Name: ?\n");
                    scanf("%s", addName);
                    getchar();
                    printf("Nummer: ?\n");
                    scanf("%lf", &addNummer);
     newBike = malloc(sizeof(struct Fahrrad));
            newBike->Rahmennummer = addNummer;
            strcpy(newBike->Name, addName);
       //     tmp2->next = newBike; //   newBike->next = tmp; // davor einfügen
       newBike->next = tmp->next;  tmp->next = newBike; // danach einfügen
        break;
        }
        tmp2 = tmp;
    }
}

  



int main(){
    int sw;
    char fName[MAX];
    double fNummer;
    printf("1.add\n");
    printf("2.delete\n");
    printf("3.show\n");
    printf("0.end\n");
    create();
    while(1) {
        printf("Was machen?\n");
        scanf("%d",&sw);
        getchar();
        switch(sw){
            case 1: printf("Name: ?\n");
                    scanf("%s", fName);
                    getchar();
                    printf("Nummer: ?\n");
                    scanf("%lf", &fNummer);
                    add(fName, fNummer);
                    break;
            case 2: printf("Wen _> delete()\n");
                    scanf("%s", fName);
                    getchar();
                    delete(fName);
                    break;
            case 3: show();
                    break;
            case 4: printf("Nach/Vor Wem? _> delete()\n");
                    scanf("%s", fName);
                    getchar();
                    addAfter_Before(fName);
                    break;
            case 0: return 0;
                    break;
        }
    }
}