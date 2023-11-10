# include <stdio.h>
# include <stdlib.h>
# include "queue.h"

/* This p_queue function creates the queue for simulation.
It returns said queue.
Arg:
    length_q (int)
Return:
    queue (p_queue)
*/
p_queue create_queue(int length_q){
    p_queue queue ;
    queue = malloc(sizeof(struct queue)) ;
    
    queue->length = length_q ;
    queue->treadmill = malloc((queue->length)*(sizeof(p_lathe))) ;
    for(int i=0; i<(queue->length); i++){
        queue->treadmill[i] = NULL ;
    }

    queue->using = 0 ;
    queue->in = 0 ;
    queue->out = 0 ;

    return queue ;
}

/* This function checks if queue is full. It returns the first position
in which a new lathe can be added. If it's full, it returns -1.
Arg:
    queue (p_queue)
Return:
    position (int)
*/ 
int checking_queue_fullness(p_queue queue){
    return (queue->length - queue->using - 1) ;
}

/* This function add a new lathe on the last position free. 
This way, the first lathe added in queue is closer to the worker.
Arg:
    queue (p_queue)
    lathe (p_lathe)
    queue_space (int)
Return:
    None
*/
void add_lathe_queue(p_queue queue, p_lathe lathe, int queue_space){
    queue->treadmill[queue_space] = lathe ;
    queue->using += 1 ;
    queue->in = 1 ;
}

/* This function removes a lathe from the last position of the queue.
It returns the lathe removed to be sent to pile.
Arg:
    queue (p_queue)
Return:
    temp_lathe (p_lathe)
*/
p_lathe remove_lathe_queue(p_queue queue){
    p_lathe temp_lathe = queue->treadmill[queue->length - 1] ;
    queue->treadmill[queue->length - 1] = NULL ;
    move_queue(queue) ;
    queue->using -= 1;
    return temp_lathe ;
}

/* This void function moves the queue after the lathe in the last position
of it is removed. It does so to keep the first lathe added in queue closer
to the worker, in order to make the first in, first out.
Arg:
    queue (p_queue)
Return:
    None
*/
void move_queue(p_queue queue){
    int position = (queue->length) - 1 ;

    for(int i=position; i>0 ;i--){  
        queue->treadmill[i] = queue->treadmill[i-1] ;
    }
    queue->treadmill[0] = NULL ;
}

/* This void function resets the variables that say when a lathe is in or out of the queue.
Arg:
    queue (p_queue)
Return:
    None
*/ 
void reset_queue(p_queue queue){
    queue->in = 0 ;
    queue->out = 0;    
}

/* This void function frees the space alocated in the making of the queue.
Arg:
    queue (p_queue)
Return:
    None
*/ 
void free_queue(p_queue queue){
    free(queue->treadmill) ;
    free(queue) ;
}