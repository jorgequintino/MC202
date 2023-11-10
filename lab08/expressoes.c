#include <stdio.h>
#include <stdlib.h>
#include "math.h"

int main(){
    int total_exp ;
    scanf("%d ", &total_exp) ;

    for(int i=1; i <= total_exp; i++){

        p_mathlib mathlib = create_mathlib() ;

        char base ;
        // it reads first character of the mathematic expression.
        scanf("%c", &base) ;

        mathlib->root = create_tree_structure(base) ;
        print_input(mathlib->root);
        process_mathlib(mathlib->root) ;

        // printing processed mathematic expression.
        printf("\n") ;
        print_input(mathlib->root) ;
        printf("\n\n") ;       

        free_mathlib(mathlib) ;
    }

    return 0 ;
}
