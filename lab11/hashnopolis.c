#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashnopolis.h"

/* This hashpointer function sets a struct for the hash in which there's only a vector pointing for every family put at the database.
It returns a pointer to it.
ARG
    NONE
RETURN
    hash (hashpointer)
*/ 
hashpointer makehash(){
    hashpointer hash = malloc(sizeof(struct hash)) ;
    hash->vector = malloc(MAX*sizeof(familypointer)) ;
    for(int i = 0; i < MAX; i++){
        hash->vector[i] = NULL ;
    }
    return hash ;
}

/* This familypointer function searches for a family at hash, it does so after the family's hash number.
It returns said family, if found, or NULL if they aren't at it.
ARG
    hash (hashpointer)
    key[] (char)
RETURN
    family (familypointer)
*/
familypointer search(hashpointer hash, char key[]){
    int searchnumber = buildkey(key) ;
    while(hash->vector[searchnumber] !=  NULL){
        if (strcmp(hash->vector[searchnumber]->name, key) == 0 && hash->vector[searchnumber]->removed == 0 ){
            return hash->vector[searchnumber] ;
        }
        searchnumber = (searchnumber + 1) % MAX ;
    }
    return NULL ;
}

/* This int function sets a hash number for a family, it does so by using the value of each character of the string, key.
It returns said number.
ARG
    key[] (char)
RETURN
    keynumber (int)
*/
int buildkey(char key[]){
    int keynumber = 0 ;
    for(int i = 0; i < strlen(key); i++){
        keynumber = (256*keynumber+key[i])%MAX ;
    } return keynumber ;
}

/* This int function gives candy for a child based on the sccore recieved and the amount of candy the family giving it has.
It returns the amount of candy given.
ARG
    hash (hashpointer)
    familyname[] (char)
    score[] (char)
RETURN
    candies (int)
*/
int givecandy(hashpointer hash, char familyname[], char score[]){
    int candies=0 ;
    familypointer family = search(hash, familyname) ;

    if(strcmp(score, "Boa") == 0){
        if (family != NULL && family->candy>0){
            if(family->candy<3){
                candies += family->candy ;
                family->candy = 0 ;
                printstatus(family) ;
            } else{
                candies += 3 ;
                family->candy -= 3 ;
                printstatus(family) ;
            }
        }

    } else if(strcmp(score, "Media") == 0){
        if (family != NULL && family->candy>0){
            if(family->candy<2){
                candies += family->candy ;
                family->candy = 0 ;
                printstatus(family) ;
            } else{
                candies += 2 ;
                family->candy -= 2 ;
                printstatus(family) ;
            }
        }

    } else {
        if (family != NULL && family->candy>0){
            candies += 1 ;
            family->candy -= 1 ;
            printstatus(family) ;
        }
    }

    return candies ;
}

/* This void function adds candy to a family data. It returns NONE.
ARG
    hash (hashpointer)
    name[] (char)
    candies (int)
RETURN
    NONE
*/
void morecandy(hashpointer hash, char name[], int candies){
    familypointer family = search(hash, name) ;
    if(family!=NULL){
        family->candy += candies ;
        printmorecandy(family) ;
    }
}

/* This void function pushes a family to the hash from its hash number foward in a available position. It returns NONE.
ARG
    hash (hashpointer)
    key[] (char)
    family (familypointer)
RETURN
    NONE
*/
void push(hashpointer hash, char key[], familypointer family){
    int number = buildkey(key) ;
    while(hash->vector[number] != NULL){
        if(hash->vector[number]->removed == 1){
            break ;
        }
        number = (number + 1) % MAX ;
    }
    freefamily(hash->vector[number]) ;
    family->key = number ;
    hash->vector[number] = family;
}

/* This void function removes a family from hash. It returns NONE.
ARG
    hash (hashpointer)
    key[] (char)
RETURN
    NONE
*/
void pop(hashpointer hash, char key[]){
    familypointer family = search(hash, key) ;
    if (family != NULL){
        printleft(family) ;
        family->removed = 1 ;
    }
}

/* This void function prints a family status, if they are out of candies. It returns NONE.
ARG
    family (familypointer)
RETURN
    NONE
*/
void printstatus(familypointer family){
    if(family->candy == 0){
        printf("A familia %s ficou sem doces.\n", family->name) ;
    }
}

/* This void function prints how much candy a child has been given. It returns NONE.
ARG
    child[] (char)
    surname[] (char)
    candies (int)
RETURN
    NONE
*/
void printtrickortreat(char child[], char surname[], int candies){
    if (candies>0){
        printf("%s %s recebeu %d doce(s) das familias.\n", child, surname, candies) ;
    } else{
        printf("%s %s recebeu 10 doces da prefeitura.\n", child, surname) ;
    }
}

/* This void function prints how much a family has of candies, after bying some. It returns NONE.
ARG
    family (familypointer)
RETURN
    NONE
*/
void printmorecandy(familypointer family){
    printf("A familia %s agora possui %d doces.\n", family->name, family->candy) ;
}

/* This void function prints if a family has left the database, hash. It returns NONE.
ARG
    family (familypointer)
RETURN
    NONE
*/
void printleft(familypointer family){
    printf("A familia %s saiu com %d doce(s) sobrando.\n", family->name, family->candy) ;
}

/* This void function frees the space alocated for the hash. It, first, frees the family data still at it. Then, it frees the space
alocated for the vector and last, the hash struct. It returns NONE.
ARG
    hash (hashpointer)
RETURN
    NONE
*/
void free_hash(hashpointer hash){
    for(int i = 0; i < MAX; i++){
        if(hash->vector[i] != NULL){
            freefamily(hash->vector[i]) ;
        }
    }
    free(hash->vector) ;
    free(hash) ;
}