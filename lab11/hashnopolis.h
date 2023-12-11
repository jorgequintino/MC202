#ifndef HASHNOPOLIS_H
#define HASHNOPOLIS_H

#define MAX 1783

#include "family.h" 

typedef struct hash* hashpointer ;

struct hash{
    familypointer* vector ;
} ;

hashpointer makehash() ;

familypointer search(hashpointer hash, char key[]) ;

int buildkey(char key[]) ;

int givecandy(hashpointer hash, char familyname[], char score[]) ;

void morecandy(hashpointer hash, char name[], int candies) ;

void push(hashpointer hash, char key[], familypointer family) ;

void pop(hashpointer hash, char hey[]) ;

void printtrickortreat(char child[], char surname[], int candies) ;

void printstatus(familypointer family) ;

void printmorecandy(familypointer family) ;

void printleft(familypointer family) ;

void free_hash(hashpointer hash) ;

#endif