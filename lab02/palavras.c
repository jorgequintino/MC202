# include <stdio.h>
# define MAX 301
# define LENGTH 21

// This function sets the puzzle, letter by letter. It is vois. It returns none.
void puzzle(int line, int collum, char matrix[][MAX]){
    for(int i=0; i<line; i++)
        for(int j=0; j<collum; j++)
            scanf("%c ", &matrix[i][j]) ;
    printf("\n") ;
}

// This function searches if the next letter is at the left side of the first letter inside the matrix(puzzle).
// If so, it returns 1. On the contrary, it returns 0.
int search_left(char matrix[][MAX], char word[], int i, int j, int k, int line, int collum){

    if (i < line && i>=0){
        if (j < collum && j>0){
            if (matrix[i][j-1] == word[k]){
                return 1 ;
            }
        }
    }
    return 0 ;
}

// This function searches if the next letter is at the right side of the first letter inside the matrix(puzzle).
// If so, it returns 1. On the contrary, it returns 0.
int search_right(char matrix[][MAX], char word[], int i, int j, int k, int line, int collum){

    if (i < line && i>=0){
        if (j < collum-1 && j>=0){
            if (matrix[i][j+1] == word[k]){
                return 1 ;
            }
        }
    }
    return 0 ;
} 

// This function searches if the next letter is at above the first letter inside the matrix(puzzle).
// If so, it returns 1. On the contrary, it returns 0.
int search_up(char matrix[][MAX], char word[], int i, int j, int k, int line, int collum){

    if (i < line && i>0){
        if (j < collum && j>=0){
            if (matrix[i-1][j] == word[k]){
                return 1 ;
            }
        }
    }
    return 0 ;
} 

// This function searches if the next letter is below the first letter inside the matrix(puzzle).
// If so, it returns 1. On the contrary, it returns 0.
int search_down(char matrix[][MAX], char word[], int i, int j, int k, int line, int collum){

    if (i < line-1 && i>=0){
        if (j < collum && j>=0){
            if (matrix[i+1][j] == word[k]){
                return 1 ;
            }
        }
    }
    return 0 ;
} 

// Once the code has a possible direction the word is, it searches letter by letter to check if they're compatible with the word.
// If any letter doesn't match between puzzle and word or the searching index is out of reach, the function returns 0. On the contrary, it returns 1.
int compare_left(int i, int j, char matrix[][MAX], int collum, char word[]){

    int w=0 ;
    for(; word[w] != '\0'; j--){
        if (j>=0){
            if (j<collum){
                w++ ;
                if (matrix[i][j] != word[w-1]){
                    return 0 ;
                }
            } else{
                return 0 ;
            } 
        } else{
            return 0 ;
        }
    }
    return 1 ;
}

// Once the code has a possible direction the word is, it searches letter by letter to check if they're compatible with the word.
// If any letter doesn't match between puzzle and word or the searching index is out of reach, the function returns 0. On the contrary, it returns 1.
int compare_right(int i, int j, char matrix[][MAX], int collum, char word[]){

    int w=0 ;
    for(; word[w] != '\0'; j++){
        if (j>=0){
            if (j<collum){
                w++ ;
                if (matrix[i][j] != word[w-1]){
                    return 0 ;
                }
            } else{
                return 0 ;
            } 
        } else{
            return 0 ;
        }
    }
    return 1 ;
}

// Once the code has a possible direction the word is, it searches letter by letter to check if they're compatible with the word.
// If any letter doesn't match between puzzle and word or the searching index is out of reach, the function returns 0. On the contrary, it returns 1.
int compare_up(int i, int j, char matrix[][MAX], int line, char word[]){

    int w=0 ;
    for(; word[w] != '\0'; i--){
        if (i>=0){
            if (i<line){
                w++ ;
                if (matrix[i][j] != word[w-1]){
                    return 0 ;
                }
            } else{
                return 0 ;
            } 
        } else{
            return 0 ;
        }
    }        
    return 1 ;
}

// Once the code has a possible direction the word is, it searches letter by letter to check if they're compatible with the word.
// If any letter doesn't match between puzzle and word or the searching index is out of reach, the function returns 0. On the contrary, it returns 1.
int compare_down(int i, int j, char matrix[][MAX], int line, char word[]){

    int w=0 ;
    for(; word[w] != '\0'; i++){
        if (i>=0){
            if (i<line){
                w++ ;
                if (matrix[i][j] != word[w-1]){
                    return 0 ;
                }
            } else{
                return 0 ;
            }
        } else{
            return 0 ;
        }
    }
    return 1 ;
}

// This function sets the possible directions the word might be and pulls the correct function for each one of them.
// If the functions 'search' and 'compare' in those coordanates finds the word, it returns 1, otherwise it returns 0.
int second(char matrix[][MAX], char word[], int i, int j, int k, int line, int collum){


    if (search_left(matrix, word, i, j, k, line, collum)==1){
        if (compare_left(i, j, matrix, collum, word)==1){
            return 1 ;
        }

    } if (search_up(matrix, word, i, j, k, line, collum)==1){
        if (compare_up(i, j, matrix, line, word)==1){
            return 1 ;
        }

    } if (search_right(matrix, word, i, j, k, line, collum)==1){
        if (compare_right(i, j, matrix, collum, word)==1){
            return 1 ;
        }
    } if (search_down(matrix, word, i, j, k, line, collum)==1){
        if (compare_down(i, j, matrix, line, word)==1){
            return 1 ;
        }
    }
    return 0 ;
}

// Fist function pulled by main. It starts the process of searching the word inserted.
// It does so by checking the first letter of said word and comparing it to the puzzle.
// It the functions it pulls finds the word, it returns 1, otherwise it returns 0.
int search_word(int line, int collum, char word[], char matrix[][MAX]){

    int k=0 ;
    for(int i=0; i<line;i++){
        for(int j=0; j<collum; j++){
            if (matrix[i][j] == word[k]){
                k++ ;
                if (second(matrix, word, i, j, k, line, collum) == 1){
                    return 1 ;
                } else if (second(matrix, word, i, j, k, line, collum) == 0){
                    k-- ;
                }
            }
        }
    }
    return 0 ;
}

int main(){
    int line, collum, amount_words ;
    scanf("%d %d %d ", &line, &collum, &amount_words) ;
    char matrix[MAX][MAX] ;
    puzzle(line, collum, matrix) ;
    char word[LENGTH] ;

    for(int text=1 ;text <= amount_words; text++){
        scanf("%s", word) ;
        if (search_word(line, collum, word, matrix) == 1){
            printf("A palavra %s está no texto!\n", word) ;
        } else if (search_word(line, collum, word, matrix) == 0){
            printf("A palavra %s não está no texto!\n", word) ;            
        }
    }

    return 0 ;
}