# include "square.h"
# include <stdio.h>
# include <stdlib.h>

p_square create_square(int length){
    p_square square ;
    square = malloc(sizeof( struct square)) ;
    square->matrix = malloc(length*sizeof(int*)) ;
    for(int i=0; i<length;i++){
        square->matrix[i] = malloc(length*sizeof(int)) ;
        for(int j=0; j<length; j++){
            scanf("%d ", &square->matrix[i][j]) ;
        }
    }
    square->length = length ;
    return square ;
}

void add_square_values(int* p_sum, int line, int collum, int l_length, int c_length, p_square square){
    for(; line<l_length; line++)
        for(; collum<c_length; collum++){
            p_sum += square->matrix[line][collum] ;
        }
    // return sum ;
}

int compare_quater(p_square square){
    int sum=0, bigger, quarter=0, bigger_quarter;
    int* p_sum = &sum ;
    for(int i=0; i<2; i++)
        for(int j=0; j<2;j++){
            add_square_values(p_sum, i, j, square->length-1+i, square->length-1+j, square) ;
            if(i==0 && j==0){
                bigger = sum ;
            }
            quarter += 1 ;
            if (sum > bigger){
                bigger = sum  ;
                bigger_quarter = quarter ;
            }
        }
        sum = 0 ;
    return bigger_quarter ;
}

int** remove_square(p_square square, int line, int collum){
    int** matrix = malloc(square->length*sizeof(int*)) ;
    for(int i=0; i<square->length;i++){
        matrix[i] =  malloc(square->length*sizeof(int)) ;
        for(int j=0; j<square->length; j++){
            matrix[i][j] = square->matrix[line + i][collum + j] ;
        }
    }
    return matrix ;
}

void cut_square(p_square square){
    if (compare_quater(square) == 1){
        square->length -= 1 ;
        square->matrix = remove_square(square, 0, 0) ;
    } else if (compare_quater(square) == 2){
        square->length -= 1 ;
        square->matrix = remove_square(square, 0, 1) ;
    } else if (compare_quater(square) == 3){
        square->length -= 1 ;
        square->matrix = remove_square(square, 1, 0) ;
    } else if (compare_quater(square) == 4){
        square->length -= 1 ;
        square->matrix = remove_square(square, 1, 1) ;
    }
}

void change_element(int line, int collum, int new_element, p_square square){
    square->matrix[line][collum] = new_element ;
}

void print_first(p_square square){
    printf("Quadras:\n") ;
    for (int i = 0; i < square->length; i++){
        for (int j = 0; j < square->length; j++){
            printf("%d\t", square->matrix[i][j]);
        }
        printf("\n") ;        
    }
    printf("\n") ;
}

void print_processing(p_square square){
    printf("Conjuntos que precisam de atenção:\n") ;
    for (int i = 0; i < square->length; i++){
        for (int j = 0; j < square->length; j++){
            printf("%d\t", square->matrix[i][j]);
        }
        printf("\n") ;        
    }
    printf("\n") ;
}

void free_square(p_square square){
    for(int i=0; i<square->length; i++){
        free(square->matrix[i]) ;
    }
    free(square->matrix) ;
}