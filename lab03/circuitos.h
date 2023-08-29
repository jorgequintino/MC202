typedef struct {
    int id;
    int players;
    int* playing;
    int total ;
} tour ;

/* It collects data to create an struct type circuit.
It takes as argument the int numb, as the number of said match.
It returns the srtuct with its arguments stablished.
Arg: 
    players (int)
Return:
    set (struct-tour)
*/ 
tour read_tour(int players) ;

/* It frees the space used in the code.
Arg: 
    game (struct-match)
Return:
    none
*/ 
void free_tour(tour set) ;