// vetores
# ifndef QUEUE_H
# define QUEUE_H

# include "lathe.h"

typedef struct queue *p_queue ;

struct queue{
    p_lathe* treadmill ;
    int length ;
    int using ;
    int in ;
    int out ;
} ;

p_queue create_queue(int length_q) ;

void free_queue(p_queue queue) ;

int checking_queue_fullness(p_queue queue) ;

void add_lathe_queue(p_queue queue, p_lathe lathe, int queue_space) ;

p_lathe remove_lathe_queue(p_queue queue) ;

void move_queue(p_queue queue) ;

void reset_queue(p_queue queue) ;

# endif