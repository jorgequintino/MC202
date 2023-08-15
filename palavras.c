# include <stdio.h>
# define MAX 300
# define LENGTH 21

// void sets(int line, int collum, int amount_words){
//     for (int i=0; i<3; i++){
//         if (i = 0){
//             scanf("%d ", &line) ;            
//         } else if (i=1) {
//             scanf("%d ", &collum) ;
//         } else {
//             scanf("%d ", &amount_words) ;
//         }
//     }
// }

void puzzle(int line, int collum, char matrix[][collum]){
    for(int i=0; i<line; i++)
        for(int j=0; j<collum; j++)
            scanf("%c ", &matrix[i][j]) ;
}

// void words_searched(int amount_words, char words[]){
//     for(int i=0; i<amount_words; i++){
//         scanf("%s ", &words) ; // como salavar as palavras que serão procuradas ?
//     }
// }

// void search(int line, int collum, char matrix[][], char word[]){
//     for(int i=0; i<line;i++){
//         for(int j=0; j<collum; j++){
//             if (matrix[i][j]) == word[i]{
//                 search() ;
//             }
//         }

//     }
// }

int search_left(char matrix[][], char words[], int i, int j, int k){
    if (matrix[i-1][j] == words[k])
        return i-1 ;
}

int search_right(char matrix[][], char words[], int i, int j, int k){
    if (matrix[i+1][j] == words[k])
        return i+1 ;
}

int search_up(char matrix[][], char words[], int i, int j, int k){
    if (matrix[i][j-1] == words[k])
        return j-1 ;
}

int search_down(char matrix[][collum], char words[], int i, int j, int k){
    if (matrix[i][j+1] == words[k])
        return j+1 ;
}

void compare(char matrix[][], char words[], int possible_word[], int i, int j, int k){
    char word[LENGTH] ;
    int position ;
    // ADICIONAR PRIMEIRO CARACTERE
    // posso ter que usar o ponto comercial

        if (search_left(matrix[][collum], words[], i, j, k)==words[k]){
            possible_word[0] = i-1 ;
            possible_word[1] = j ;
            possible_word[2] = 1 ;
            
        } else if (search_up()==0){
            possible_word[0] = i ;
            possible_word[1] = j-1 ;
            possible_word[2] = 1 ; 
        }else if (search_right()==0){
            possible_word[0] = i+1 ;
            possible_word[1] = j ;
            possible_word[2] = 1 ; 
        } else if (search_down()==0){
            possible_word[0] = i ;
            possible_word[1] = j+1 ;
            possible_word[2] = 1 ; 
        }
}

// void compare(char matrix[][], char words[], int i, int j, int k){
//     char word[LENGTH] ;
//     int position ;
//     // ADICIONAR PRIMEIRO CARACTERE
//     for(int k=1; k < LENGTH; k++){
//         if (search_left(matrix[][], words[], i, j, k)==words[k]){
//             for(int k=2; k<LENGTH; k++){
//                 word[k] = search_left()
//             }




//             position = search_left() ;
//             if (position == words[k])
//                 word[k] = position
//         } else if (search_up()==0){
//             j = search_up() ;
//         }else if (search_right()==0){
//             i = search_right() ;
//         } else if (search_down()==0){
//             j = search_down() ;

void print(){

}

int main(){
    int line, collum, amount_words ;
    scanf("%d %d %d", &line, &collum, &amount_words) ;
    // sets(line, collum, amount_words) ;
    char matrix[line][collum] ;
    puzzle(line, collum, matrix) ;
    char words[LENGTH] ;
    int possible_word[100] ; // [x, y, direção, 1º, ... ,20º ]

    int i =0, k=0 ;
    do {
        scanf("%s ", &words) ;
        for(int n=0; n<10; n++){
            possible_word[n] = 0 ;
        }
        for(int i=0; i<line;i++){
            for(int j=0; j<collum; j++){
                if (matrix[i][j] == words[k]){
                    k++ ;
                    campare() ;
                    for(int m=2; m<10; m++){
                        if (possible_word[m] == 1){
                            // mandar sim ou não, se sim entra na
                            // recorrencia até acabar a palavra procurada
                            // ou o limite do vetor da matriz
                            // loop para olhar o resto da palavra
                            // coletar a palavra
                            // compara com a palavra inputada
                            
                            
                        }
                    }
                    
                    }
                }
            }
        }
    } while (i < amount_words) ;







    // words_searched(amount_words, words) ; // criar vetores para as diferentes palavras

    return 0 ;
}