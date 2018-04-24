#ifndef create
#define create 
#define MAX 20

struct Fahrrad {
    double Rahmennummer;
    char Name[MAX];
    struct Fahrrad *next;
}*front,*rear,*tmp,*tmp2,*newBike;


void create_Fkt(){
    front = rear = NULL;
}

#endif