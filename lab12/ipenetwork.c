#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ipenetwork.h"
#include "stack.h"
#include "queue.h"

/* This grafopointer function creates a struct for the graph and sets its arguments. It returns its pointer.
ARG
    total (int)
RETURN
    grafo (grafopointer)
*/ 
grafopointer makegrafo(int total) {
    grafopointer grafo = malloc(sizeof(struct grafo));
    grafo->total = 0 ;
    grafo->adj = malloc((total)*sizeof(edgepointer)) ;
    for(int i =  0; i < total; i++){
        grafo->adj[i] = NULL ;
    } return grafo ;
}

/* This int function checks if there's a edge between these points. It returns TRUE or FALSE.
ARG
    grafo (grafopointer)
    line (int)
    collumnn (int)
RETURN
    number (int)
*/ 
int isthereedge(grafopointer grafo, int line, int collumn){
    edgepointer tempedge ;
    for(tempedge = grafo->adj[line]; tempedge != NULL; tempedge = tempedge->next){
        if (tempedge->data == collumn){
            return 1 ;
        }
    }
    return 0 ; ;
}

/* This int* function does a deep-first search, it does so using a stack struct. It returns a vector
in which contains wich points there's a connection.
ARG
    grafo (grafopointer)
    value (int)
RETURN
    been (int*)
*/ 
int* dfs(grafopointer grafo, int value){
    int i, j ;
    int* data = malloc((grafo->total+1)*sizeof(int)) ;
    int* been = malloc((grafo->total+1)*sizeof(int)) ;
    stackpointer stack = makestack() ;
    for(i = 0; i<= grafo->total; i++){
        data[i] = -1 ;
        been[i] = 0 ;
    } stackit(stack, value) ;
    data[value] = value ;
    while(!emptystack(stack)){
        i = unstack(stack) ;
        if (been[i]){
            continue ;
        } been[i] = 1 ;
        for(j = 1; j <= grafo->total; j++){
            if(isthereedge(grafo, i, j) && !been[j]){
                data[j] = i ;
                stackit(stack, j) ;            
            }
        }
    } freestack(stack) ;
    free(data) ;
    return been ;
}

/* This int* function does a breadth-first search, it does so using a queue struct. It returns a vector in
which contains the data its the "father" of a o=point, related by its index number.
    grafo (grafopointer)
    value (int)
RETURN
    been (int*)
*/
int* bfs(grafopointer grafo, int value) {
    int i, j ;
    int* data = malloc((grafo->total+1)*sizeof(int)) ;
    int* been = malloc((grafo->total+1)*sizeof(int)) ;
    queuepointer queue = makequeue() ;
    for(i = 0 ; i<= grafo->total; i++){
        data[i] = -1 ;
        been[i] = 0 ;
    } 
    queueit(queue, value) ;
    data[value] = value;
    been[value] = 1 ;
    while(!emptyqueue(queue)){
        i = unqueue(queue) ;
        for(j = 1; j <= grafo->total; j++){
            if (isthereedge(grafo, i, j) && !been[j]){
                been[j] = 1 ;
                data[j] = i ;
                queueit(queue, j) ;
            }
        }
    } 
    freequeue(queue) ;
    free(been) ;
    return data ;
}

/* This void function changes the length of the graph analyzed. It returns NONE.
ARG
    grafo (grafopointer)
    newtotal (int)
RETURN
    NONE
*/ 
void changetotal(grafopointer grafo, int newtotal){
    grafo->total = newtotal ;
}

/* This void function frees the edges of the graph analyzed. It returns NONE.
ARG
    edge (edgepointer)
RETURN
    NONE
*/ 
void freelistedges(edgepointer edge){
    if (edge != NULL){
        freelistedges(edge->next) ;
        free(edge) ;
    }
}

/* This void function frees the graph analyzed, it does so by freeing its edges first. It returns NONE.
ARG
    grafo (grafopointer)
RETURN
    NONE
*/ 
void freegrafo(grafopointer grafo){
    for(int i = 0; i<=20; i++){
        freelistedges(grafo->adj[i]) ;
    }
    free(grafo->adj) ;
    free(grafo) ;
}

/* This edgepointer function pushes a new edge onto the list of the graph analyzed. It returns said edge.
ARG
    list (edgepointer)
    data (int)
RETURN
    newedge (edgepointer)
*/ 
edgepointer pushlist(edgepointer list, int data){
    edgepointer newedge = malloc(sizeof(struct edge)) ;
    newedge->data = data ;
    newedge->next = list ;
    return newedge ;
}

/* This void function pushes a new edge onto the graph analyzed. It returns NONE.
ARG
    grafo (edgepointer)
    line (int)
    collumn (int)
RETURN
    NONE
*/ 
void pushedge(grafopointer grafo, int line, int collumn){
    grafo->adj[line] = pushlist(grafo->adj[line], collumn) ;
    grafo->adj[collumn] = pushlist(grafo->adj[collumn], line) ;
}

/* This edgepointer function pops a new edge onto the list of the graph analyzed. It returns said edge.
ARG
    list (edgepointer)
    data (int)
RETURN
    list (edgepointer)
*/ 
edgepointer poplist(edgepointer list, int data){
    edgepointer next ;
    if(list == NULL){
        return NULL ;
    } else if (list->data == data){
        next = list->next ;
        free(list) ;
        return next ;
    } else{
        list->next = poplist(list->next, data) ;
        return list ;
    }
}

/* This void function pops a new edge onto the list of the graph analyzed. It returns NONE.
ARG
    grafo (edgepointer)
    line (int)
    collumnn (int)
RETURN
    NONE
*/ 
void popedge(grafopointer grafo, int line, int collumn){
    grafo->adj[line] = poplist(grafo->adj[line], collumn) ;
    grafo->adj[collumn] = poplist(grafo->adj[collumn], line) ;
}


/* This void function prints if there's a route between two vertexes after checking it using dfs. It returns NONE.
ARG
    grafo (grafopointer)
    line (int)
    collumnn (int)
RETURN
    NONE
*/ 
void printifroute(grafopointer grafo, int line, int collumn){
    int* been = dfs(grafo, line) ;
    if(been[collumn] == 1){
        printf("Existe conexão entre os nós.\n") ;        
    } else{
        printf("Não existe conexão entre os nós.\n") ;
    }
    free(been) ;
}

/* This void function prints which points are connected directly or indirectly after doing dfs. It returns NONE.
ARG
    grafo (grafopointer)
RETURN
    NONE
*/ 
void printconnection(grafopointer grafo){
    for(int i = 1; i<=grafo->total; i++){
        int* been = dfs(grafo, i) ;
        printf("Ponto %d (Pontos diretamente ou indiretamente conectados):", i) ;
        for(int j = 1; j<=grafo->total; j++){
            if(been[j] == 1){
                printf(" %d", j) ;
            }
        } printf("\n") ;
        free(been) ;
    }
}

/* This void function prints which way are the closest between two points. It returns NONE.
ARG
    grafo (grafopointer)
    p (int)
    value (int)
RETURN
    NONE
*/ 
void printclosest(grafopointer grafo, int line, int collumn){
    int* data = bfs(grafo, collumn) ;
    queuepointer queue = makequeue() ;
    queueit(queue, line) ;
    while(data[line] != collumn && data[line] != -1){
        queueit(queue, data[line]) ;
        line = data[line] ;
    }
    if (data[line] == -1){
        printf("Não existe conexão entre os nós.\n") ;
    } else {
        printf("%d ", unqueue(queue)) ;
        while(!emptyqueue(queue)){
            printf("-> %d ", unqueue(queue)) ;
        } 
        printf("-> %d\n", collumn) ;
    }
    freequeue(queue) ;
    free(data) ;
}