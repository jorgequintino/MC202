# include "square.h"
# include <stdio.h>
# include <stdlib.h>

/* This function sets a pointer to a struct named square which conteins the data
required to analyse the square(matrix). These infos are the matrix, its length,
line and collum that starts it.
It returns the pointer with the struct set and it recieves in the main.
Arg:
    length (int)
Return:
    square (p_square)
*/ 
p_square create_square(int length){
    p_square square ;
    square = malloc(sizeof(struct square)) ;
    square->matrix = malloc(length*sizeof(int*)) ;
    for(int i=0; i<length;i++){
        square->matrix[i] = malloc(length*sizeof(int)) ;
        for(int j=0; j<length; j++){
            scanf("%d ", &square->matrix[i][j]) ;
        }
    }
    square->length = length ;
    square->line = 0 ;
    square->collum = 0 ;
    return square ;
}

/* This function adds the values of the quarter which we want to analyze.
Arg:
    i (int)
    j (int)
    square (p_square)
Return:
    sum (int)
*/ 
int add_square_values(int i, int j, p_square square){
    int sum = 0 ;
    for(int line=i; line < ((square->length) - 1 + i); line++)
        for(int collum=j; collum < ((square->length) - 1 + j); collum++){
            sum += square->matrix[line][collum] ;
        }
    return sum ;
}

/* This function compares the sum of the quarters analyzed. It updates
the struct the line and collum in which the matrix must be cut, once it
has found the right quarter to be analyzed.
Arg:
    square (p_square)
Return:
    none
*/ 
void compare_quater(p_square square){
    int sum=0, bigger=0, quarter=0 ;
    for(int i=0; i<2; i++)
        for(int j=0; j<2; j++){
            sum = add_square_values(i, j, square) ;
            if(quarter==0){
                bigger = sum ;
            }
            quarter++ ;
            if (sum > bigger){
                bigger = sum  ;
                square->line = i ;
                square->collum = j ;
            }
        }
}

/* This function cchanges the matrix. It does so by saving the addres of the
previous square in a temporary pointer and the it passes the data to the new
sqaure. By the end of it, it frees the space alocated before. 
Arg:
    square (p_square)
Return:
    none
*/ 
void change_square(p_square square){
    int** temp_matrix = square->matrix ;
    square->matrix = malloc((square->length)*sizeof(int*)) ;
    for(int i=0; i<square->length;i++){
        square->matrix[i] = malloc((square->length)*sizeof(int)) ;
        for(int j=0; j<square->length; j++){
            square->matrix[i][j] = temp_matrix[square->line + i][square->collum + j] ;
        }
    }
    
    for(int i=0; i<square->length+1; i++){
        free(temp_matrix[i]) ;
    }
    free(temp_matrix) ;
}

/* This function sets the new square to be cutted and calls
the function responsible to do it according the line and
collum which it will do it.
Arg:
    square (p_square)
Return:
    none
*/ 
void cut_square(p_square square){
    if (square->line == 0){
        if (square->collum == 0){
            square->length -= 1 ;
            change_square(square) ;            
        } else if (square->collum == 1){
            square->length -= 1 ;
            change_square(square) ;
        }
    } else if (square->line == 1){
        if (square->collum == 0){
            square->length -= 1 ;
            change_square(square) ;            
        } else if (square->collum == 1){
            square->length -= 1 ;
            change_square(square) ;
        }
    }
}

/* This function changes the element in the position required.
Arg:
    line (int)
    collum (int)
    new_element (int)
    square (p_square)
Return:
    none
*/ 
void change_element(int line, int collum, int new_element, p_square square){
    square->matrix[line][collum] = new_element ;
}

/* This function prints the squares. If the matrix length is the
same as the length iserted, it prints the originbal squares. On the
contrary, it prints the squares that require attention.
Arg:
    length (int)
    square (p_square)
Return:
    none
*/ 
void print_processing(int length, p_square square){
    if(square->length == length){
        printf("Quadras:\n") ;
        for (int i = 0; i < square->length; i++){
            for (int j = 0; j < square->length; j++){
                printf("%d\t", square->matrix[i][j]);
        }
        printf("\n") ;        
    }
    printf("\n") ;
    } else{
    printf("Conjuntos que precisam de atenção:\n") ;
    for (int i = 0; i < square->length; i++){
        for (int j = 0; j < square->length; j++){
            printf("%d\t", square->matrix[i][j]);
        }
        printf("\n") ;        
    }        
    printf("\n") ;
    }


}

/* This function frees the space required by the mallocs for the
matrix and then it destroys the struct with all the data.
Arg:
    square (p_square)
Return:
    none
*/ 
void free_square(p_square square){
    for(int i=0; i<square->length; i++){
        free(square->matrix[i]) ;
    }
    free(square->matrix) ;
    free(square) ;
}