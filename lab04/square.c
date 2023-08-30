# include "square.h"
# include <stdio.h>
# include <stdlib.h>

int* read_square(int line){
    int* square[][] = malloc(3*sizeof(int)) ;
    // não tenho certeza de como alocar essa matriz
    for(int i=0; i<line;i++)
        for(int j=0; j<line; j++){
            sacnf("%d ", &square[i][j]) ;
        }
    return square[][] ;
}

void print_processing(){

}

void free_square(){
    free() ;
}