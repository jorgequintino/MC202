#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meal.h"
#include "winona9000.h"

/*
This p_Meal function sets the struct Meal for a DIsh to be pushed in the Heap. It returns said Meal pointer.
ARG:
    Dish[] (char)
    Surviver (p_Surviver)
RETURN:
    Meal (p_Meal)
*/ 
p_Meal create_Meal(char Dish[], p_Surviver Surviver){
    p_Meal Meal = malloc(sizeof(struct Meal)) ;
    length_Dish(Dish) ;
    strcpy(Meal->Dish, Dish)  ;
    strcpy(Meal->Name, Surviver->Name)  ;
    strcpy(Meal->Surname, Surviver->Surname)  ;
    Meal->ID = Surviver->ID ;
    Meal->Key = Surviver->Priority ;
    return Meal ;
}

/*
This void function sets every char from '\n' on as a '\0'.
ARG:
    Dish[] (char)
RETURN:
    NONE
*/ 
void length_Dish(char Dish[]){
    for(int i =0; i<26; i++){
        if(Dish[i] == '\n'){
            for(int j = i; j<26; j++){
                Dish[j] = '\0' ;
            }
            break ;
        }
    }
}

/*
This void function prints the detais of the dish being served.
ARG:
    Meal (p_Meal)
RETURN:
    NONE
*/ 
void print_Meal(p_Meal Meal){
    printf("%s %s %s %d\n", Meal->Name, Meal->Surname, Meal->Dish, Meal->Key) ;
}

/*
This void function frees the struct created for said dish.
ARG:
    Meal (p_Meal)
RETURN:
    NONE
*/ 
void free_Meal(p_Meal Dish){
    free(Dish) ;
}
