#ifndef enableNode
#define enableNode


 struct Node {
        char Na[MAX];
        char Vo[MAX];
        double Ma;
        struct Node *ptr;
    }*front,*rear,*tmp,*frontTMP,*tmp1,*tmp2;

struct Node *initNode(){

        if (front == NULL) {
        rear = malloc(sizeof(struct Node));
    }
    else {
        tmp = malloc(sizeof(struct Node));
        }

        printf("initNode\n");
   return front;
}
#endif