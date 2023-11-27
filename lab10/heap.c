#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"

/*
This p_Priority function sets the struct Priority in which is the heap. It returns said Priority pointer.
ARG:
    Length (int)
RETURN:
    Priority (p_Priority)
*/ 
p_Priority create_Priority(int Length){
    p_Priority Priority = malloc(sizeof(struct Priority)) ;
    Priority->heap =  malloc((Length)*sizeof(p_Meal)) ;
    Priority->Used = 0 ;
    Priority->Length = Length ;
    return Priority ;
}

/*
This p_Meal function extracts the Meal with the bigger priority from the heap. It returns said Meal.
ARG:
    Priority (p_Priority)
RETURN:
    Meal (p_Meal)
*/ 
p_Meal extract_biggest_priority(p_Priority Priority){
    p_Meal Meal = Priority->heap[0] ;
    swap(&Priority->heap[0], &Priority->heap[Priority->Used-1]) ;
    Priority->Used-- ;
    down(Priority, 0) ;    
    return Meal ;
}

/*
This int function searches in which position a Meal is in the heap. It returns said position.
ARG:
    ID (int)
    Priority (p_Priority)
RETURN:
    position (int)
*/ 
int search_Dish(int ID, p_Priority Priority){
    for(int i=0; i<Priority->Used; i++){
        if (Priority->heap[i]->ID == ID){
            return i ;
        }
    }
    return -1 ;
}

/*
This int function checks if the heap is empty. It returns a True or False integer.
ARG:
    Priority (p_Priority)
RETURN:
    position (int)
*/ 
int empty(p_Priority Priority){
    return !Priority->Used ;
}

/*
This void function swaps two Meals position in the heap.
ARG:
    Meal1 (p_Meal*)
    Meal2 (p_Meal*)
RETURN:
    NONE
*/ 
void swap(p_Meal* Meal1, p_Meal* Meal2){
    p_Meal temp = *Meal1 ;
    *Meal1 = *Meal2 ;
    *Meal2 = temp ;

}

/*
This void function pushes a Meal in the heap and sets to place it according to its priority. It also adds 1 to the counter of space used.
ARG:
    Priority (p_Priority)
    Meal (p_Meal)
RETURN:
    NONE
*/ 
void push(p_Priority Priority, p_Meal Meal){
    Priority->heap[Priority->Used] = Meal ;
    Priority->Used++ ;
    up(Priority, Priority->Used-1) ;
}

/*
This void function sets a Meal up in the heap by comparing its priority to the one above it.
It continues said process until it's not possible to change anymore.
ARG:
ARG:
    Priority (p_Priority)
    Position (int)
RETURN:
    NONE
*/ 
void up(p_Priority Priority, int  position){
    if(position>0 && Priority->heap[ABOVE(position)]->Key < Priority->heap[position]->Key){
        swap(&Priority->heap[position], &Priority->heap[ABOVE(position)]) ;
        up(Priority, ABOVE(position)) ;
    }
}

/*
This void function sets a Meal down in the heap by first checking if it's possible to get down. If so, it checks what direction to go, left or right,
whichever is the biggest. Then, it compares the priority of the Meal in question to the one on the possible position. If the Meal priority is smaller,
it changes places. It continues said process until it's not possible to change anymore.
ARG:
    Priority (p_Priority)
    Position (int)
RETURN:
    NONE
*/ 
void down(p_Priority Priority, int  position){
    int bigger_below ;
    if(LEFT(position) < Priority->Used){
        bigger_below = LEFT(position) ;
        if(RIGHT(position) < Priority->Used && Priority->heap[LEFT(position)]->Key < Priority->heap[RIGHT(position)]->Key){
            bigger_below = RIGHT(position) ;
        } if (Priority->heap[position]->Key < Priority->heap[bigger_below]->Key){
            swap(&Priority->heap[bigger_below], &Priority->heap[position]) ;
            down(Priority, bigger_below) ;
        }
    }
}

/*
This void function change the priority of a Meal in the heap and places it in the heap according to its new priority.
ARG:
    Priority (p_Priority)
    Position (int)
    Value (int)
RETURN:
    NONE
*/ 
void change_priority(p_Priority Priority, int  position, int value){
    if(Priority->heap[position]->Key < Priority->heap[position]->Key + value){
        Priority->heap[position]->Key = Priority->heap[position]->Key + value ;
        up(Priority, position) ;
    } else{
        Priority->heap[position]->Key = Priority->heap[position]->Key + value ;
        down(Priority, position) ;
    }
}

/*
This void function prints the round in question based on the amount of pans available at the Kitchen.
ARG:
    Round (int)
    KitchenPans (int)
    Priority (p_Priority)
RETURN:
    NONE
*/ 
void print_Round(int Round, int KitchenPans, p_Priority Priority){
    printf("---- rodada %d ----\n", Round) ;
    for(int i=0; i<KitchenPans && !empty(Priority); i++){
        p_Meal Done = extract_biggest_priority(Priority) ;
        print_Meal(Done) ; 
        free_Meal(Done) ;
    } 
}

/*
This void function first frees the space alocated for the heap and then for the struct which contained it.
ARG:
    Priority (p_Priority)    
RETURN:
    NONE
*/ 
void free_heap(p_Priority Priority){

    free(Priority->heap) ;
    free(Priority) ;
}
