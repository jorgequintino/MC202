# include <stdio.h>
# include <stdlib.h>
# include "circuitos.h"

tour read_tour(int players){
    tour set;
    set.total = 0 ;
    set.players = players ;
    set.playing = malloc(set.players*sizeof(int)) ;

    scanf("%d ", &set.id) ;
    for(int j=0; j<set.players; j++){
        scanf("%d ", &set.playing[j]) ;
        set.total += set.playing[j] ;
    }

    return set ;
}

void free_tour(tour set){
    free(set.playing) ;
}