#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* This queuepointer function makes a queue and sets its arguments. It returns a pointer to it.
ARG
    NONE
RETURN
    queue (queuepointer)
*/ 
queuepointer makequeue(){
    queuepointer queue = malloc(sizeof(struct queue)) ;
    queue->first = queue->last = NULL ;
    return queue ;
}

/* This void function pushes a element to the queue and sets it. It returns NONE.
ARG
    queue (queuepointer)
    value (int)
RETURN
    NONE
*/ 
void queueit(queuepointer queue, int value){
    queuenodepointer queuenode = malloc(sizeof(struct queuenode)) ;
    queuenode->data = value ;
    queuenode->next = NULL ;
    if (queue->first == NULL){
        queue->first = queuenode ;
    } else {
        queue->last->next = queuenode ;
    }
    queue->last = queuenode ;
}

/* This int function pops a element from the queue. It returns its data after freeing its space alocated.
ARG
    queue (queuepointer)
RETURN
    firstdata (int)
*/ 
int unqueue(queuepointer queue){
    queuenodepointer first = queue->first ;
    int firstdata = first->data ;
    queue->first = queue->first->next ;
    if (queue->first == NULL){
        queue->last = NULL ;
    } 
    free(first) ;
    return firstdata ;
}

/* This void function frees the elements from the queue. It returns NONE.
ARG
    queuenode (queuenodepointer)
RETURN
    NONE
*/ 
void freelistqueue(queuenodepointer queuenode){
    if(queuenode != NULL){
        if (queuenode->next != NULL){
            freelistqueue(queuenode->next) ;    
        } free(queuenode) ;
    }
}

/* This void function frees the queue, it does so freeing its elements first. It returns NONE.
ARG
    queue (queuepointer)
RETURN
    firstdata (int)
*/ 
void freequeue(queuepointer queue){
    freelistqueue(queue->first) ;
    free(queue) ;
}

/* This int function checks if the queue is empty. It returns TRUE or FALSE.
ARG
    queue (queuepointer)
RETURN
    number (int)
*/ 
int emptyqueue(queuepointer queue){
    if(queue->first == NULL){
        return 1 ;
    } else{
        return 0 ;
    }
}