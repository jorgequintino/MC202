# ifndef WORKERS_H
# define WORKERS_H

# include "queue.h"
# include "pile.h"

typedef struct packer *p_packer ;

struct packer{
    p_lathe doing ;
    int packed ;
} ;

typedef struct classer *p_classer ;

struct classer{
    p_lathe doing ;
    int classed ;
} ;

p_packer create_packer() ;

p_classer create_classer() ;

void packer_working(p_packer packer, p_pile pile) ;

void classer_working(p_classer classer, p_queue queue, p_pile pile) ;

void print_simulation(p_queue queue, p_pile pile, int time) ;

void print_delay(int delay) ;

void free_workers(p_classer classer, p_packer packer) ;

# endif