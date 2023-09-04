# include "square.h"
# include <stdio.h>
# include <stdlib.h>

int main(){
    int length, change=0, line, collum, new_element ;
    scanf("%d ", &length) ;
    p_square square ;
    square = create_square(length) ;
    print_processing(length, square) ;
    compare_quater(square) ;
    cut_square(square) ;
    print_processing(length, square) ;
    
    if (square->length > 1){
        scanf("%d ", &change) ;        
    }

    while (change == 1) {
        scanf("%d %d %d ", &line, &collum, &new_element) ;
        change_element(line, collum, new_element, square) ;
        compare_quater(square) ;
        cut_square(square) ;
        print_processing(length, square) ;
        if (square->length > 1){
            scanf("%d ", &change) ;
            if (change==0){
                break ;
            }
        } else{
            break ;
        }
    }

    free_square(square) ;
    
    return 0 ;
}