#ifndef MEAL_H
#define MEAL_H

#include "winona9000.h"

typedef struct Meal *p_Meal ;

struct Meal{
    char Name[MAX] ;
    char Surname[MAX] ;
    char Dish[26];
    int Key ;
    int ID ;
} ;

p_Meal create_Meal(char Dish[], p_Surviver Surviver) ; 

void length_Dish(char Dish[]) ;

void print_Meal(p_Meal Meal) ;

void free_Meal(p_Meal Dish) ;

#endif