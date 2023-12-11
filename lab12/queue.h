#ifndef QUEUE_H
#define QUEUE_H
typedef struct queuenode *queuenodepointer  ;

struct queuenode{
    int data ;
    queuenodepointer next ;
} ;

typedef struct queue *queuepointer ;
 
struct queue{
    queuenodepointer first, last ;
} ;

queuepointer makequeue() ;

void queueit(queuepointer queue, int value) ;

int unqueue(queuepointer queue) ;

void freelistqueue(queuenodepointer queuenode) ;

void freequeue(queuepointer queue) ;

int emptyqueue(queuepointer queue) ;

#endif