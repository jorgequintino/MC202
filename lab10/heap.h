#ifndef HEAP_H
#define HEAP_H

#include "meal.h"
#include "winona9000.h" 

#define ABOVE(i) ((i-1)/2) 

#define LEFT(i) (2*i+1) 

#define RIGHT(i) (2*i+2) 

typedef struct Priority *p_Priority ;

struct Priority{
    p_Meal* heap ;
    int Used, Length;
} ;

p_Priority create_Priority(int size) ;

p_Meal extract_biggest_priority(p_Priority Priority) ;

int search_Dish(int ID, p_Priority Priority) ;

int empty(p_Priority Priority) ;

void swap(p_Meal* Meal1, p_Meal* Meal2) ;

void push(p_Priority Priority, p_Meal Meal) ;

void up(p_Priority Priority, int  position) ;

void down(p_Priority Priority, int  position) ;

void change_priority(p_Priority Priority, int  position, int value) ;

void print_Round(int Round, int KitchenPans, p_Priority Priority) ;

void free_heap(p_Priority Priority) ;

#endif