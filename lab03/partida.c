# include <stdio.h>
# include <stdlib.h>
# include "partida.h"

match read_match(int numb){
    match game;
    scanf("%d %d %d ", &game.players, &game.circuits, &game.equipaments) ;
    game.price = 10*(game.circuits) + 17.5*(game.equipaments) ;
    game.id = numb ;
    game.circuit_data = malloc(game.circuits*sizeof(tour)) ;
    for(int i=0; i<game.circuits; i++){
        game.circuit_data[i] = read_tour(game.players) ;
    }
    return game ;
}

int hardest_circuit(match game){
    int hardest=0 ;
    int id ;
    for(int i=0;i<game.circuits;i++){
        if (game.circuit_data[i].total>hardest){
            hardest = game.circuit_data[i].total ;
            id = game.circuit_data[i].id ;
        }
    }
    return id ;
}

int* gamers_plays(match game){
    int* data = malloc((game.players)*sizeof(int)) ;
    for(int j=0; j<game.players; j++){
        int plays=0 ;
        for(int i=0; i<game.circuits; i++){
            plays += game.circuit_data[i].playing[j] ;
        data[j] = plays ;
        }
    }
    return data ;
}


void print_match(match game, int* data, int hardest_tour){
    printf("Partida %d\n", game.id) ;
    printf("Num. de Jogadores: %d - Num. de Circuitos: %d - Num. de Equipamentos: %d\n", game.players, game.circuits, game.equipaments) ;
    printf("Valor do Aluguel: R$ %.2f\n", game.price) ;
    for(int i=0; i<game.players; i++){
        printf("Jogador %d: %d\n", i+1, data[i]) ;       
    }
    printf("Circuito mais dificil: %d\n", hardest_tour) ;
    printf("##########\n") ;
}

void free_match(match game){

    for(int i=0; i<game.circuits;i++){
        free_tour(game.circuit_data[i]) ;        
    }
    free(game.circuit_data) ;
}