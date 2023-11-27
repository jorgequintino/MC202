#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "winona9000.h"
#include "heap.h"
#include "meal.h"

int main(){
    
    int KitchenPans, Survivors, OrdersOnRound=-1, Round = 1;
    scanf("%d %d ", &KitchenPans, &Survivors) ;
    p_Surviver* SurviversData = saving_Survivers(Survivors) ;
    p_Priority Priority = create_Priority(Survivors) ;

    for(int i = 0; i < Survivors; i++){
        char Name[MAX], Surname[MAX] ;
        int DaysSurvived ; //priority to each surviver
        scanf("%s %s %d ", Name, Surname, &DaysSurvived) ;
        SurviversData[i] = create_Surviver(Name, Surname, DaysSurvived, i) ;
        // save it in a data base heap structure for people/clients/surviver
    }

    scanf("%d ", &OrdersOnRound) ; 
    while(!empty(Priority) || (OrdersOnRound != 0)){

        // changed priority or added new dishes.
        if (OrdersOnRound!=0){
            for(int i=0; i<OrdersOnRound; i++){
                char Dish[26], Command[MAX] ;
                int ID, Value;
                scanf("%s %d ", Command, &ID) ;
                if(strcmp(Command, "novo") == 0){
                    fgets(Dish, 26, stdin) ;
                    push(Priority, create_Meal(Dish, SurviversData[ID])) ;
                    // saves a new dish.

                } if(strcmp(Command, "altera") == 0){
                    scanf("%d ", &Value) ;
                    change_priority(Priority, search_Dish(ID, Priority), Value) ;                    
                }
            } 
            scanf("%d ", &OrdersOnRound) ; 
        }
        
        print_Round(Round, KitchenPans, Priority) ;
        Round++ ;
    }

    free_SurviverData(SurviversData, Priority->Length) ;
    free_heap(Priority) ;

    return 0 ;
}