#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ipenetwork.h"

int main(){
    int command ;
    grafopointer grafo = makegrafo(21) ;
    scanf("%d ", &command) ;
    while (command<7 && command >0){
        if (command == 1){
            // sets the length of the graph.
            int edge ;
            scanf("%d ", &edge) ;
            changetotal(grafo, edge) ;

        } else if (command == 2){
            // sets the conections between points.
            int line, collumn ;
            scanf("%d %d ", &line, &collumn) ;
            pushedge(grafo, line, collumn) ;

        } else if (command == 3){
            // unsets the connections between two points.
            int line, collumn ;
            scanf("%d %d ", &line, &collumn) ;
            popedge(grafo, line, collumn) ;

        } else if (command == 4){
            // checks if there is direct or indirect conection between two points.
            int line, collumn ;
            scanf("%d %d ", &line, &collumn) ;
            printifroute(grafo, line, collumn) ;

        } else if (command == 5){
            // searches for the closest connection found between two points.
            int line, collumn ;
            scanf("%d %d ", &line, &collumn) ;
            printclosest(grafo, line, collumn) ;

        } else if (command == 6){
            // checks about possible direct and indirect connections between two points.
            printconnection(grafo) ;

        }
        scanf("%d ", &command) ;
    } 
    freegrafo(grafo) ;

    return 0 ;
}