/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   create.h
 * Author: felix
 *
 * Created on 7. Mai 2018, 15:51
 */

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
