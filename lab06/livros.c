# include <stdlib.h>
# include <stdio.h>
# include "library.h"

int main(){
    char command[11] ;
    int set, final=0, addition=0, first=0 ;
    p_library library ;
    library = setting_library() ;

    do{
        set = read_command(command) ;

        if (set!= 6){
            // if it's not the end of file.

            if (set == 1){
                if (addition == 0){
                    add_book_last(library, final) ;
                    final = 1 ;                    
                } else if (addition == 1){
                    if (first==0){
                        library->book_list = add_book_front(library) ;
                        first += 1 ;                        
                    } else{
                        add_book_last(library, final) ;
                    }
                }
            } else if (set == 2){
                remove_book(library) ;
            } else if (set == 3){
                addition = 0 ;
                final = 0 ;
            } else if (set == 4){
                addition = 1 ;
                first = 0 ;
            } else if (set == 5){
                print_library(library) ;
            }
        }
        
    } while( set != 6 ) ;

    free_library(library) ;

    return  0 ;
}