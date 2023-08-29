# include <stdio.h>
# include <stdlib.h>
# include "partida.h"

int main(){
    int games ;
    scanf("%d ", &games) ;
    
    for(int numb=1; numb<=games;numb++){
        match game = read_match(numb) ;
        int hardest_tour = hardest_circuit(game) ;
        int* data = gamers_plays(game) ;
        print_match(game, data, hardest_tour) ;
        free_match(game) ;
        free(data) ;
    }
}