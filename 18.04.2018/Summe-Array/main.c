#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20


int main() {

A:
    printf("Wie viele Werte sollen eingelesen werden?\n");
    int tmp;
     scanf("%d", &tmp);
    getchar();
    if(tmp > MAX) {
        printf("weniger als 20!!\n");
    goto A;
    }
     int arr[tmp];
    for ( int i = 0; i < tmp; i++){
        int x;
        printf("Wert Nummer %d eingeben!", i+1);
        scanf("%d", &x);
        getchar();
        if(x%2 == 0) {
            arr[i] = x;
        }
        else {
            printf("Nur gerade Zahlen!\n");
            arr[i] = -1;
        }
    }

    int n = sizeof(arr)/sizeof(arr[0]);
    printf("sizeof(arr)/sizeof(arr[0]): \t %d\n",n);

    int n1 = sizeof(arr);
    printf("sizeof(arr);   ein Int ist 4 bytes lang: \t %d\n",n1);

    int n2 = sizeof(arr) / sizeof(int);
    printf("sizeof(arr) / sizeof(int): \t %d\n",n);

    for( int h = 0; h < sizeof(arr)/sizeof(int); h++){
        if(arr[h]%2 == 0){
        printf("%d.te Stelle hat Wert: \t %d\n", h+1, arr[h]);
    }
    else if (arr[h] == -1) {
        printf("Eingegebener Wert an Stelle %d war ungerade!\n", h+1);
    }
    else {
        printf("\n");
    }
    }

  
}