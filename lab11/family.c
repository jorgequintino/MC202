#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "family.h"

/* This familypointer function sets a struct for a family containing all its data. It returns a pointer to it.
ARG
    name[] (char)
    candies (int)
RETURN
    family (familypointer)
*/ 
familypointer makeafamily(char name[], int candies){
    familypointer family = malloc(sizeof(struct family)) ;
    strcpy(family->name, name)  ;
    family->candy = candies ;
    family->removed = 0 ;
    return family ;
}

/* This void function free the space in memory alocated for a family data. It returns NONE.
ARG
    family (familypointer)]
RETURN
    NONE
*/ 
void freefamily(familypointer family){
    free(family) ;
}