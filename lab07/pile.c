# include <stdio.h>
# include <stdlib.h>
# include "pile.h"

/* This p_pile function creates the pile for simulation.
It returns said pile.
Arg:
    length_p (int)
Return:
    pile (p_pile)
*/
p_pile create_pile(int length_p){
    p_pile pile ;
    pile = malloc(sizeof(struct pile)) ;

    pile->length = length_p ;
    pile->stack = NULL ;
    pile->using = 0 ;
    pile->in = 0 ;
    pile->out = 0 ;

    return pile ;
}

/* This function adds a new lathe on top of the pile.
It returns the new pile.
Arg:
    pile (p_pile)
    lathe (p_lathe)
Return:
    lathe (p_lathe)
*/
p_lathe add_lathe_pile(p_pile pile, p_lathe lathe){
    lathe->next = pile->stack ;
    pile->in = 1 ;
    pile->using += 1;
    return lathe ;
}

/* This function removes a lathe from top of the pile.
It returns the lathe removed to be sent to packer.
Arg:
    pile (p_pile)
Return:
    temp_pile (p_lathe)
*/
p_lathe remove_lathe_pile(p_pile pile){
    p_lathe temp_stack = pile->stack ;
    pile->stack = pile->stack->next ;
    pile->using -= 1;
    return temp_stack ;
}

/* This function checks if pile is full. It returns the first position
in which a new lathe can be added. If it's full, it returns -1.
Arg:
    pile (p_pile)
Return:
    position (int)
*/ 
int checking__pile_fullness(p_pile pile){
    return (pile->length - pile->using - 1) ;
}

/* This void function resets the variables that say when a lathe is in or out of the pile.
Arg:
    pile (p_pile)
Return:
    None
*/ 
void reset_pile(p_pile pile){
    pile->in = 0 ;
    pile->out = 0 ;    
}

/* This void function frees the space alocated in the making of the pile.
Arg:
    pile (p_pile)
Return:
    None
*/ 
void free_pile(p_pile pile){
    free(pile) ;
}