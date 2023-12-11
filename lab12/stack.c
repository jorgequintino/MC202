#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/* This stackpointer function makes a stack and sets its arguments. It returns a pointer to it.
ARG
    NONE
RETURN
    stack (stackpointer)
*/ 
stackpointer makestack(){
    stackpointer stack = malloc(sizeof(struct stack)) ;
    stack->top = NULL ;
    return stack ;
}

/* This void function pushes a element to the stack and sets it. It returns NONE.
ARG
    stack (stackpointer)
    data (int)
RETURN
    NONE
*/ 
void stackit(stackpointer stack, int data){
    nodestackpointer nodestack = malloc(sizeof(struct nodestack)) ;
    nodestack->data = data ;
    nodestack->next = stack->top ;
    stack->top = nodestack ;
}

/* This int function pops a element from the stack. It returns its data after freeing the spaced alocated.
ARG
    stack (stackpointer)
RETURN
    NONE
*/ 
int unstack(stackpointer stack){
    nodestackpointer topnodestack = stack->top ;
    int topnodestackdata = topnodestack->data ;
    stack->top = stack->top->next ;
    free(topnodestack) ;
    return topnodestackdata ;
}

/* This void function frees the elements from the stack. It returns NONE.
ARG
    nodestack (nodestackpointer)
RETURN
    NONE
*/ 
void freeliststack(nodestackpointer nodestack){
    if(nodestack != NULL){
        if (nodestack->next != NULL){
            freeliststack(nodestack->next) ;    
        } free(nodestack) ;
    }
}

/* This void function frees the stack, it does so by freeing its elements first. It returns NONE.
ARG
    stack (stackpointer)
RETURN
    NONE
*/ 
void freestack(stackpointer stack){
    freeliststack(stack->top) ;
    free(stack) ;
}

/* This int function checks if the stack is empty. It returns TRUE or FALSE.
ARG
    stack (stackpointer)
RETURN
    number (int)
*/ 
int emptystack(stackpointer stack){
    if(stack->top == NULL){
        return 1 ;
    } else{
        return 0 ;
    }
}