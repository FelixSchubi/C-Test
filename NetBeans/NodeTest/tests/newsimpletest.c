/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newsimpletest.c
 * Author: felix
 *
 * Created on 8. Mai 2018, 11:44
 */

#include <stdio.h>
#include <stdlib.h>
#include "add.h"

/*
 * Simple C Test Suite
 */

void testAdd_Fkt() {
    char* bikeName;
    double bikeNumber;
    add_Fkt(bikeName, bikeNumber);
    if (1 /*check result*/) {
        printf("%%TEST_FAILED%% time=0 testname=testAdd_Fkt (newsimpletest) message=error message sample\n");
    }
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% newsimpletest\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%%  testAdd_Fkt (newsimpletest)\n");
    testAdd_Fkt();
    printf("%%TEST_FINISHED%% time=0 testAdd_Fkt (newsimpletest)\n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
