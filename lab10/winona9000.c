#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "winona9000.h"

/*
This p_Surviver function sets the struct Surviver containing detais of whoever is in the island. It returns said Surviver pointer.
ARG:
    Name[] (char)
    Surname[] (char)
    Key (int)
    ID (int)
RETURN:
    Surviver (p_Surviver)
*/ 
p_Surviver create_Surviver(char Name[], char Surname[], int Key, int ID){
    p_Surviver Surviver = malloc(sizeof(struct Surviver)) ;
    strcpy(Surviver->Name, Name) ;
    strcpy(Surviver->Surname, Surname) ;
    Surviver->Key = Surviver->Priority = Key ;
    Surviver->ID = ID ;
    return Surviver ;
}

/*
This p_Surviver* function sets the vector in which each Surviver data will be saved. It returns said vector.
ARG:
    Survivors (int)
RETURN:
    SurviverData (p_Surviver*)
*/ 
p_Surviver* saving_Survivers(int Survivors){
    p_Surviver* SurviverData = malloc((Survivors)*sizeof(p_Surviver)) ;
    return SurviverData ;
}

/*
This void function frees the struct created for said Surviver.
ARG:
    Surviver (p_Surviver)
RETURN:
    NONE
*/ 
void free_Surviver(p_Surviver Surviver){
    free(Surviver) ;
}

/*
This void function frees the vector which contains every Surviver data, it does so after freeing the struct created for every one of them.
ARG:
    Surviver (p_Surviver)
RETURN:
    NONE
*/ 
void free_SurviverData(p_Surviver* SurviverData, int Length){
    for(int i=0; i<Length;i++){
        free_Surviver(SurviverData[i]) ;
    }
    free(SurviverData) ;
}