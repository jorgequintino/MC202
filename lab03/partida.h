# include "circuitos.h"
# include <stdlib.h>

typedef struct {
    float price;
    int id;
    int players;
    int circuits;
    int equipaments;
    tour* circuit_data ;
} match ;

/* It collects data to create an struct type match.
It takes as argument the int numb, as the number of said match.
It returns the srtuct with its arguments stablished.
Arg: 
    numb(int)
Return:
    game (struct-match)
*/ 
match read_match(int numb) ;

/* It compares the argument total of the circuit to point the hardest,
the one with more points.
It retuns the id of said circuit.
Arg: 
    game (struct-match)
Return:
    id (int)
*/ 
int hardest_circuit(match game) ;

/* It compares the circuits in the argument of the game.
During the process, it creates a vector in which, the position
contains the plays a players does in a circuit.
It retuns the id of said circuit.
Arg: 
    game (struct-match)
Return:
    data (int*)
*/ 
int* gamers_plays(match game) ;

/* It prints the informations of each match.
Arg: 
    game (struct-match)
    data (int*)
    hardest_tour (int)
Return:
    none
*/ 
void print_match(match game, int* data, int hardest_tour) ;

/* It frees the space used in the code.
Arg: 
    game (struct-match)
Return:
    none
*/ 
void free_match(match game) ;
