#ifndef STACK_H
#define STACK_H
typedef struct nodestack *nodestackpointer  ;

struct nodestack{
    int data ;
    nodestackpointer next ;
} ;

typedef struct stack *stackpointer ;

struct stack{
    nodestackpointer top ;
} ;

stackpointer makestack() ;

void stackit(stackpointer stack, int data) ;

int unstack(stackpointer stack) ;

void freeliststack(nodestackpointer nodestack) ;

void freestack(stackpointer stack) ;

int emptystack(stackpointer stack) ;

#endif