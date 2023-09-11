# include <stdio.h>
# include <stdlib.h>
# include "batcomputer.h"

/* This function sets the struct which will contein the bat memory.
ARG:
    instructions (int)
RETURN:
    bat_memory (p_bat)
*/
p_bat create_memory(int instructions){
    p_bat bat_memory ;
    bat_memory = malloc(sizeof(struct bat)) ;
    bat_memory->alocated = 0 ;
    bat_memory->space = 8 ;
    
    bat_memory->memory = malloc(8*sizeof(int)) ;
    for(int i=0; i<(bat_memory->space) ; i++){
        bat_memory->memory[i] = -1 ;
    }

    bat_memory->data = malloc((2*instructions)*sizeof(int)) ;
    for(int j=0; j< (2*instructions); j++){
        bat_memory->data[j] = -1 ;
    } 
    return bat_memory ;
}

/* This function puts the memory in a space, with the first number of its vector
being its length.
ARG:
    batman (p_bat)
RETURN:
    none
*/ 
void bat_alloc(int amount, p_bat bat_memory, int place, int instructions){
    bat_memory->memory[place] = amount ;
    for(int i=0; i<amount; i++){
        scanf("%d", &bat_memory->memory[place + 1 +i]) ;
    }
    bat_memory->alocated += (amount+1) ;
    for(int i=0; i<(2*instructions) ; i=i+2){
        if (bat_memory->data[i] != -1){
            if (bat_memory->data[i+1] != -1){
                bat_memory->data[i] = place ;
                bat_memory->data[i+1] = amount ;
            }
        }
    }
    printf("%d\n", place) ;
}

/* This function checks if there's free space in the vector, and then
calls the 'check_memory' to make sure the vector will fit in that space.
In case it does not find space available, it will expand the memory until
it fits the vector.
ARG:
    batman (p_bat)
    amount (int)
    instructions (int)
RETURN:
    none
*/
void set_bat_alloc(p_bat bat_memory, int amount, int instructions){
    int available=0,free_space;
    for(int i=0; i<(bat_memory->space); i++){
        if (bat_memory->memory[i] == -1){
            free_space = check_memory(bat_memory, amount, i) ;
            if (free_space == 1){
                bat_alloc(amount, bat_memory, i, instructions) ;
                available = 1 ;
                break ;
            }
        }
    }
    while (available == 0){
        expand(bat_memory) ;
        for(int i=0; i<(bat_memory->space); i++){
            if (bat_memory->memory[i] == -1){
                free_space = check_memory(bat_memory, amount, i) ;
                if (free_space == 1){
                    bat_alloc(amount, bat_memory, i, instructions) ;
                    available = 1 ;
                    break ;
                }
            }
        }
    }
}

/* This function checks if there's a place in the memory to add a new sequence
of numbers. If not, it returns 0, on the contrary it returns 1.
ARG:
    batman (p_bat)
    amount (int)
    place (int)
RETURN:
    (int)
*/ 
int check_memory(p_bat bat_memory, int amount, int place){
    for(int j=0; j<amount; j++){
        if ((place+1+j) < (bat_memory->space)){
            if (bat_memory->memory[place+1+j] != -1){
                return 0 ;
            }
        } else{
            return 0 ;
        }
    }
    return 1 ;
}

/* This function checks if the last 3/4 of the memory is free and
therefore if we should cut it.
ARG:
    batman (p_bat)
RETURN:
    (int)
*/ 
int check_quarter(p_bat bat_memory){
    int i = (bat_memory->space) / 4 ;
    for(; i<bat_memory->space; i++){
        if (bat_memory->memory[i] != -1){
            return 0 ;
        }
    }
    return 1 ;
}

/* This function doubles the memory.
ARG:
    batman (p_bat)
RETURN:
    none
*/
void expand(p_bat bat_memory){
    int* temp_memory = bat_memory->memory ;
    bat_memory->memory = malloc(((bat_memory->space)*2)*sizeof(int)) ;
    for(int i=0; i<((bat_memory->space*2)); i++){
        if (i<bat_memory->space){
            bat_memory->memory[i] = temp_memory[i] ;
        } else{
            bat_memory->memory[i] = -1 ;        
        }
    }
    bat_memory->space = (2*(bat_memory->space)) ;
    free(temp_memory) ;
} 

/* This function cuts the memory in half.
ARG:
    batman (p_bat)
RETURN:
    none
*/
void cut(p_bat bat_memory){
    int* temp_memory = bat_memory->memory ;
    bat_memory->memory = malloc(((bat_memory->space) / 2)*sizeof(int)) ;
    for(int i=0; i<((bat_memory->space)/2); i++){
        bat_memory->memory[i] = temp_memory[i] ;
    }
    bat_memory->space = ((bat_memory->space) / 2) ;
    free(temp_memory) ;
}

/* This function frees the memory of a space, according to batman's orders.
ARG:
    place (int)
    batman (p_bat)
    instructions (int)
RETURN:
    none
*/ 
void bat_free(int place, p_bat bat_memory, int instructions){

    for(int i=1; i<=bat_memory->memory[place]; i++){
        bat_memory->memory[place +i] = -1 ;
    }

    bat_memory->alocated -= (bat_memory->memory[place]+1) ;
    bat_memory->memory[place] = -1 ;

    for(int j=0; j< (2*instructions); j+=2){
        if (bat_memory->data[j] == place){
            bat_memory->data[j] = -1 ;
            bat_memory->data[j+1] = -1 ;
            break ;
        }
    }

    int free_space = check_quarter(bat_memory) ;
    if (free_space == 1 ){
        cut(bat_memory) ;
    }

}

/* This function prints a list of integer numbers in order it was added.
ARG:
    batman (p_bat)
RETURN:
    none
*/ 
void bat_print(int begin, p_bat bat_memory){
    for(int i=1; i<= bat_memory->memory[begin]; i++){
            printf("%d ", bat_memory->memory[begin + i]) ;
        }
    printf("\n") ;
}

/* This function prints the amount of memory being used.
ARG:
    batman (p_bat)
RETURN:
    none
*/ 
void bat_use(p_bat bat_memory){
    printf("%d de %d\n", bat_memory->alocated,  (bat_memory->space)) ;
}

/* This function frees the space allocated for the struct.
ARG:
    batman (p_bat)
RETURN:
    none
*/ 
void free_bat_computer(p_bat bat_memory){
    free(bat_memory->memory) ;
    free(bat_memory->data) ;
    free(bat_memory) ;
}

/* This function compares the command given, to set the right fuction.
ARG:
    command (char[])
RETURN:
    none
*/ 
int compare_command(char command[]){
    if (command[4] == 'a'){
        return 0 ;
    } else if (command[4] == 'p'){
        return 1 ;
    } else if (command[4] == 'f'){
        return 2 ;
    } else if (command[4] == 'u'){
        return 3 ;
    }
    return 4 ;
}