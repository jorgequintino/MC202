#ifndef FAMILY_H
#define FAMILY_H

#define NAMES 11

typedef struct family* familypointer ;

struct family{
    int removed ;
    int key ;
    int candy ;
    char name[NAMES] ;
} ;

familypointer makeafamily(char name[], int candies) ;

void freefamily(familypointer family) ;

#endif