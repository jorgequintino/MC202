#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"

int main(){
    int errors = 0, line_number = 1 ;
    p_symbols symbols = creating_symbols() ;

    // reading every line of D code.    
    while(line_number > 0){
        char line[MAXLINE], first[MAXLINE], second[MAXLINE], third[MAXLINE], fourth[MAXLINE], fifth[MAXLINE] ; // variables to be read.
        
        fgets(line, MAXLINE, stdin);
        if(is_valid_line(line) == 1){
            // this line cannot be descarted.

            sscanf(line, "%s", first);
            int key = istype(first) ;
            if (key > 0){

                // if line being read is a declaration.
                sscanf(line, "%s %[^;]s", first, second);
                symbols->root = inserting(symbols->root, key, second) ;
                // variable saved at tree structure.

            } else{

                sscanf(line, "%s %s %s %s %[^;]s", first, second, third, fourth, fifth) ;
                if(strcmp(second, "=") == 0){ 
                    // if line being read is a operation.
                errors = errors | checking_errors(symbols->root,first, third, fifth, fourth, line_number) ;
                // one a error has ocurred and the fuction returned "1", it will continue being that.

                }
            }         
        }

        if (feof(stdin)) {
            if (errors == 0){
                printf("Não há erros de tipo.\n") ;
            }
            print_variables(symbols->root) ;
            break;
        } else{
            line_number++ ;
        }
    }

    free_symbol(symbols) ;

    return 0 ;
}