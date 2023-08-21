# include <stdio.h>
# define MAX 301
# define LENGTH 21

void puzzle(int line, int collum, char matrix[][MAX]){
    for(int i=0; i<line; i++)
        for(int j=0; j<collum; j++)
            scanf("%c ", &matrix[i][j]) ;
}

int search_left(char matrix[][MAX], char word[], int i, int j, int k){
    if (matrix[i][j-1] == word[k]){
        return 1 ;        
    }
    return 0 ;
}

int search_right(char matrix[][MAX], char word[], int i, int j, int k){
    if (matrix[i][j+1] == word[k]){
        return 1 ;       
    }
    return 0 ;
}

int search_up(char matrix[][MAX], char word[], int i, int j, int k){
    if (matrix[i-1][j] == word[k]){
        return 1 ;        
    }
    return 0 ;
}

int search_down(char matrix[][MAX], char word[], int i, int j, int k){
    if (matrix[i+1][j] == word[k]){
        return 1 ;        
    }
    return 0 ;
}
        
int compare_left(int i, int j, char matrix[][MAX], int collum, char word[]){
    int w=-1 ;
    for(; word[w] != '\0'; j--){
        if (j>=0){
            if (j<collum){
                w++ ;
                if (matrix[i][j] != word[w]){
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

int compare_right(int i, int j, char matrix[][MAX], int collum, char word[]){
    int w=-1 ;
    for(; word[w] != '\0'; j++){
        if (j>=0){
            if (j<collum){
                w++ ;
                if (matrix[i][j] != word[w]){
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

int compare_up(int i, int j, char matrix[][MAX], int line, char word[]){
    int w=-1 ;
    for(; word[w] != '\0'; i--){
        if (i>=0){
            if (i<line){
                w++ ;
                if (matrix[i][j] != word[w]){
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

int compare_down(int i, int j, char matrix[][MAX], int line, char word[]){
    int w=-1 ;
    for(; word[w] != '\0'; i++){
        if (i>=0){
            if (i<line){
                w++ ;
                if (matrix[i][j] != word[w]){
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

int second(char matrix[][MAX], char word[], int i, int j, int k, int line, int collum){

    if (search_left(matrix, word, i, j, k)==1){
        if (compare_left(i, j, matrix, collum, word)==1){
            return 1 ;
        }

    } if (search_up(matrix, word, i, j, k)==1){
        if (compare_up(i, j, matrix, line, word)==1){
            return 1 ;
        }

    } if (search_right(matrix, word, i, j, k)==1){
        if (compare_right(i, j, matrix, collum, word)==1){
            return 1 ;
        }
    } if (search_down(matrix, word, i, j, k)==1){
        if (compare_down(i, j, matrix, line, word)==1){
            return 1 ;
        }
    }
    return 0 ;
}

int search_word(int k, int line, int collum, char word[], char matrix[][MAX]){
    for(int i=0; i<line;i++){
        for(int j=0; j<collum; j++){
            if (matrix[i][j] == word[k]){ //
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

void clean_word(char word[]){
    for(int i=0; i<LENGTH; i++){
        word[i] = 'a' ;
    }
}

int main(){
    int line, collum, amount_words ;
    scanf("%d %d %d ", &line, &collum, &amount_words) ;
    char matrix[MAX][MAX] ;
    puzzle(line, collum, matrix) ;
    printf("\n") ;
    char word[LENGTH] ;

    for(int text=1 ;text <= amount_words; text++){
        int k = 0 ;
        scanf("%s", word) ;
        if (search_word(k, line, collum, word, matrix) == 1){
            printf("A palavra %s está no texto!", word) ;
        } else if (search_word(k, line, collum, word, matrix) == 0){
            printf("A palavra %s não está no texto!", word) ;            
        }
        clean_word(word) ;
    }

    return 0 ;
}