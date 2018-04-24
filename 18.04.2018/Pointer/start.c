#include <stdio.h>

int main()
{
    // Taken from here: http://denniskubes.com/2012/08/19/pointers-and-arrays-in-c/

    // initialize an array of ints
    int numbers[5] = {1,2,3,4,5};

    // standard array notation
    int *ptr1 = numbers;
    int val1 = numbers[0];

    // address of array notation
    int *ptr2 = &numbers[0];
    int val2 = *(&numbers[0]);

    // pointer + increment notation
    int *ptr3 = numbers + 0;
    int val3 = *(numbers + 0);

    printf("\n\nprint out the address stored in the pointers\n");
    printf("(void *)ptr1 = %p\n", (void*) ptr1);
    printf("(void *)ptr2 = %p\n", (void *)ptr2);
    printf("(void *)ptr3 = %p\n", (void *)ptr3);

    printf("\n\nprint out the value at the pointer addresses\n");
    printf("val1 = %d\n", val1);
    printf("val2 = %d\n", val1);
    printf("val3 = %d\n", val1);


    printf("\n\nchar arrays and char pointers:\n");
    char *cptr = "Hello there!";
    char carr[] = "Hello there Second!";

    printf("cptr = %s\n", cptr);
    printf("carr = %s\n", carr);

    printf("cptr[1] = %c (with %%c)\n", cptr[1]);
    printf("carr[1] = %c (with %%c)\n", carr[1]);

    printf("*cptr = %c (with %%c)\n", *cptr);
    printf("*(cptr + 1) = %c (with %%c)\n", *(cptr + 1));

    printf("*cptr = %d (with %%d)\n", *cptr);
    printf("*(cptr + 1) = %d (with %%d)\n", *(cptr + 1));

    printf("\n\nComparing the integer values of characters:\n");
    printf("*cptr == carr[0]: %d\n", *cptr == carr[0]);             // True (1)
    printf("*cptr == carr[1]: %d\n", *cptr == carr[1]);             // False (0)
    printf("*(cptr + 1) == carr[1]: %d\n", *(cptr + 1) == carr[1]); // True (1)

    // Setting a new pointer to the memory address of `cptr`
    printf("\n\nLooping through a pointer until hitting 0 character:\n");

    char *np = cptr;
    while(*np != 0) {
        printf("*np: %c\n", *np++);
    }
    printf("After loop - np: %s\n", np);
    printf("After loop - cptr: %s\n", cptr);


    // Taken from here: http://denniskubes.com/2012/08/16/the-5-minute-guide-to-c-pointers/
    printf("\n\nStructs and pointers:\n");
    struct person {
        int age;
        char *name;
    };

    struct person per;
    per.age = 21;
    per.name = "Thorsten Ball";

    printf("per.age=%d, per.name=%s\n", per.age, per.name);

    struct person *pptr = &per;

    printf("(*pptr).age=%d, (*pptr).name=%s\n", (*pptr).age, (*pptr).name);
    printf("pptr->age=%d, pptr->name=%s\n", pptr->age, pptr->name);
}