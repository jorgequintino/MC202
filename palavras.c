# include <stdio.h>
# define MAX 300
# define LENGTH 21

void puzzle(int line, int collum, char matrix[][collum]){
    for(int i=0; i<line; i++)
        for(int j=0; j<collum; j++)
            scanf("%c ", &matrix[i][j]) ;
}

int search_left(char matrix[][], char words[], int i, int j, int k){
    if (matrix[i-1][j] == words[k])
        return 1 ;
}

int search_right(char matrix[][], char words[], int i, int j, int k){
    if (matrix[i+1][j] == words[k])
        return 1 ;
}

int search_up(char matrix[][], char words[], int i, int j, int k){
    if (matrix[i][j-1] == words[k])
        return 1 ;
}

int search_down(char matrix[][collum], char words[], int i, int j, int k){
    if (matrix[i][j+1] == words[k])
        return 1 ;
}

int second(char matrix[][], char words[], int possible_word[], int i, int j, int k){

        if (search_left(matrix[][collum], words[], i, j, k)==1){
            if (compare() == 1){
                print() ;
                return 1 ;
            }
            
        } if (search_up()==1){
        
        } if (search_right()==1){
            possible_word[0] = i+1 ;
            possible_word[1] = j ;
            possible_word[2] = 1 ; 
        } if (search_down()==1){
            possible_word[0] = i ;
            possible_word[1] = j+1 ;
            possible_word[2] = 1 ; 
        }
    return 0 ;
}

int extent(char words[][collum], int line, int collum){
    for(int i=0; i<LENGTH; i++){
        if (words[i] == "\0"){
            return i ;
        }
    }
}


int compare(int i, int j, char matrix[][]){
    int size = extent() ;

    // comparar os caracteres da matriz direto com a words[]

    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if (matrix[i][j] != word[j]){
                return 0 ;
            }
        }

        //  pegar os caracteres e armazenar em possible_words
        // comparar possible word com words
        // if igual, print()
    


    }
    
    return 1 ;
}

void print(){

}

int main(){
    int line, collum, amount_words ;
    scanf("%d %d %d", &line, &collum, &amount_words) ;
    // sets(line, collum, amount_words) ;
    char matrix[line][collum] ;
    puzzle(line, collum, matrix) ;
    char words[LENGTH] ;

    int a =0 ;
    do {
        int k = 0 ;
        scanf("%s ", &words) ;
        for(int i=0; i<line;i++){
            for(int j=0; j<collum; j++){
                if (matrix[i][j] == words[k]){
                    k++ ;
                    if (second() == 0){
                        print() ;
                    }



                    // for(int m=2; m<10; m++){
                        // if (possible_word[m] == 1){

                            // mandar sim ou não, se sim entra na
                            // recorrencia até acabar a palavra procurada
                            // ou o limite do vetor da matriz
                            // loop para olhar o resto da palavra
                            // coletar a palavra
                            // compara com a palavra inputada
                }
            }
        }
    } while (a < amount_words) ;







    // words_searched(amount_words, words) ; // criar vetores para as diferentes palavras

    return 0 ;
}