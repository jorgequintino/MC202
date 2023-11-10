// listas ligadas
# ifndef PILE_H
# define PILE_H

# include "lathe.h"

typedef struct pile *p_pile ;

struct pile{
    p_lathe stack ;
    int length ;
    int using ;
    int in ;
    int out ;
} ;

p_pile create_pile(int length_p) ;

p_lathe add_lathe_pile(p_pile pile, p_lathe lathe) ;

p_lathe remove_lathe_pile(p_pile pile) ;

int checking__pile_fullness(p_pile pile) ;

void reset_pile(p_pile pile) ;

void free_pile(p_pile pile) ;

# endif