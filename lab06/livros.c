# include <stdlib.h>
# include <stdio.h>
# include "library.h"

int main(){
    printf("começou\n") ;
    char command[MAX] ;
    int set, addition=0 ;
    p_library library ;
    library = setting_library() ;
    printf("fiz a library\n") ;
    do{
        printf("in\n") ;
        set = read_command(command) ;
        printf("this is set %d\n", set) ;
        if (set == 1){
            printf("passou aqui\n") ;
            if (addition == 0){
                printf("e aqui\n") ;
                add_book_last(library) ;
            } else if (addition == 1){
                addition = 0 ;
                library->book_list = add_book_front(library) ;
            }
        } else if (set == 2){
            remove_book(library) ;
        } else if (set == 3){
            addition = 0 ;
        } else if (set == 4){
            addition = 1 ;
        } else if (set == 5){
            print_library(library->book_list) ;
        }
    } while( set != 6 ) ;

    return  0 ;
}