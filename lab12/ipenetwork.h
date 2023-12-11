#ifndef IPENETWORK_H
#define IPENETWORK_H
typedef struct edge *edgepointer ;

struct edge {
    int data ;
    edgepointer next ;
} ;

typedef struct grafo *grafopointer;

struct grafo {
    edgepointer *adj;
    int total;
} ;

grafopointer makegrafo(int total);

int isthereedge(grafopointer grafo, int line, int collumn);

int* dfs(grafopointer grafo, int value) ;

int* bfs(grafopointer grafo, int value) ;

void changetotal(grafopointer grafo, int newtotal) ;

void freelistedges(edgepointer edge) ;

void freegrafo(grafopointer grafo);

edgepointer pushlist(edgepointer list, int data) ;

void pushedge(grafopointer grafo, int line, int collumn);

edgepointer poplist(edgepointer list, int data) ;

void popedge(grafopointer grafo, int line, int collumn);

void printifroute(grafopointer grafo, int line, int collumn) ;

void printconnection(grafopointer grafo) ;

void printclosest(grafopointer grafo, int line, int collumn) ;

#endif