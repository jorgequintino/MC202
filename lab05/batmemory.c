# include <stdio.h>
# include <stdlib.h>
# include "batcomputer.h"
# define WORD 10

int main(){
    int instructions, bat, direction, begin, amount;

    char command[WORD] ;
    scanf("%d", &instructions) ;

    p_bat bat_memory ;
    bat_memory = create_memory(instructions) ;

    for(int i=0 ; i<instructions; i++){
        scanf("%s", command) ;
        bat = compare_command(command) ;
        if (bat == 0){
            scanf("%d", &amount) ;
            set_bat_alloc(bat_memory, amount, instructions) ;
        } else if (bat == 1){
            scanf("%d", &begin) ;
            bat_print(begin, bat_memory) ;
        } else if (bat == 2){
            scanf("%d", &direction) ;
            bat_free(direction, bat_memory, instructions) ;
        } else if (bat == 3){
            bat_use(bat_memory) ;
        }
    }

    free_bat_computer(bat_memory) ;
    
    return 0 ;
}