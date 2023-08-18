# include <stdio.h>
# define MAX 301
# define LENGTH 21

void puzzle(int line, int collum, char matrix[][MAX]){
    for(int i=0; i<line; i++)
        for(int j=0; j<collum; j++)
            scanf("%c ", &matrix[i][j]) ;
}

int search_left(char matrix[][MAX], char word[], int i, int j, int k){
    if (matrix[i-1][j] == word[k]){
        return 1 ;        
    }
    return 0 ;
}

int search_right(char matrix[][MAX], char word[], int i, int j, int k){
    if (matrix[i+1][j] == word[k])
        return 1 ;
    return 0 ;
}

int search_up(char matrix[][MAX], char word[], int i, int j, int k){
    if (matrix[i][j-1] == word[k])
        return 1 ;
    return 0 ;
}

int search_down(char matrix[][MAX], char word[], int i, int j, int k){
    if (matrix[i][j+1] == word[k])
        return 1 ;
    return 0 ;
}
        
int compare_left(int i, int j, char matrix[][MAX], int collum, char word[]){
    for(; word[j] != '\0'; j--){
        if (j>=0){
            if (j<collum){
                if (matrix[i][j] != word[j]){
                    return 0 ;
                }
            }
        }
    }
    return 1 ;
}

int compare_right(int i, int j, char matrix[][MAX], int collum, char word[]){
    for(; word[j] != '\0'; j++){
        if (j>=0){
            if (j<collum){
                if (matrix[i][j] != word[j]){
                    return 0 ;
                }
            }
        }
    }
    return 1 ;
}

int compare_up(int i, int j, char matrix[][MAX], int line, char word[]){
    for(; word[i] != '\0'; j--){
        if (i>=0){
            if (i<line){
                if (matrix[i][j] != word[i]){
                    return 0 ;
                }
            }
        }
    }
    return 1 ;
}

int compare_down(int i, int j, char matrix[][MAX], int line, char word[]){
    for(; word[i] != '\0'; j++){
        if (i>=0){
            if (i<line){
                if (matrix[i][j] != word[i]){
                    return 0 ;
                }
            }
        }
    }
    return 1 ;
}

int second(char matrix[][MAX], char word[], int i, int j, int k, int line, int collum){

    if (search_left(matrix, word, i, j, k)==1){
        if (compare_left(i, j, matrix, collum, word)==1){
            printf("A palavra %s está no texto!", word) ;
            return 1 ;
        }

    } if (search_up(matrix, word, i, j, k)==1){
        if (compare_up(i, j, matrix, line, word)==1){
            printf("A palavra %s está no texto!", word) ;
            return 1 ;
        }

    } if (search_right(matrix, word, i, j, k)==1){
        if (compare_right(i, j, matrix, collum, word)==1){
            printf("A palavra %s está no texto!", word) ;
            return 1 ;
        }

    } if (search_down(matrix, word, i, j, k)==1){
        if (compare_down(i, j, matrix, line, word)==1){
            printf("A palavra %s está no texto!", word) ;
            return 1 ;
        }
    }

    return 0 ;
}

//  pegar os caracteres e armazenar em possible_words
// comparar possible word com words
// if igual, print()

int main(){
    int line, collum, amount_words ;
    scanf("%d %d %d", &line, &collum, &amount_words) ;
    char matrix[MAX][MAX] ;
    puzzle(line, collum, matrix) ;
    char word[LENGTH] ;

    int text=1 ;
    do {
        int k = 0 ;
        scanf("%s ", &word[LENGTH]) ;
        for(int i=0; i<line;i++){
            for(int j=0; j<collum; j++){
                if (matrix[i][j] == word[k]){
                    k++ ;
                    if (second(matrix, word, i, j, k, line, collum) == 0){
                        printf("A palavra %s não está no texto!", word) ;
                    }
                }
            }
        }
    } while (text <= amount_words) ;

    return 0 ;
}

// int extent(char words[][collum], int line, int collum){
//     for(int i=0; i<LENGTH; i++){
//         if (words[i] == "\0"){
//             return i ;
//         }
//     }
// }LENGTH