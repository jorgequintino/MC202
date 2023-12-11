#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashnopolis.h"

int main(){

    int end = 0 ;
    hashpointer hash = makehash() ;
    
    while (end!=1){
        
        char command[13] ;
        scanf("%s ", command) ;

        if(strcmp(command, "ENTRAR") == 0){
            char name[NAMES];
            int candies ;
            scanf("%s %d ", name, &candies) ;
            push(hash, name, makeafamily(name, candies)) ;
            
        } else if(strcmp(command, "SAIR") == 0){
            char name[NAMES];
            scanf("%s ", name) ;
            pop(hash, name) ;

        } else if(strcmp(command, "COMPRAR") == 0){
            char name[NAMES];
            int candies ;
            scanf("%s %d ", name, &candies) ;
            morecandy(hash, name, candies) ;
            
        } else if(strcmp(command, "TRICKORTREAT") == 0){
            char name[NAMES], surname[NAMES], familyname[NAMES], score[NAMES];
            int houses, candies=0 ;
            scanf("%s %s %d ", name, surname, &houses) ;
            for(int i=0; i<houses; i++){
                scanf("%s %s ", familyname, score) ;
                candies += givecandy(hash, familyname, score) ;
            }
            printtrickortreat(name, surname, candies) ;

        } else{ // leave, command == "FINALIZAR"
            end = 1 ;
        }        
    }

    free_hash(hash) ;

    return 0 ;
}