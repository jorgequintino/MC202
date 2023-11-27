#ifndef WINONA9000_H
#define WINONA9000_H

#define MAX 16

typedef struct Surviver *p_Surviver ;

struct Surviver{
    char Name[MAX];
    char Surname[MAX];
    char Dish[MAX];
    int Key ;
    int ID ;
    int Priority ;
} ;

p_Surviver create_Surviver(char Name[], char Surname[], int Key, int ID) ;

p_Surviver* saving_Survivers(int Survivors) ;

void free_Surviver(p_Surviver Surviver) ;

void free_SurviverData(p_Surviver* SurviverData, int Length) ;

#endif