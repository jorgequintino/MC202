# include <stdlib.h>
# include <stdio.h>
# include "library.h"

p_library setting_library(){
    p_library library ;
    library = malloc(sizeof(struct library)) ;
    library->books_total = 0 ;
    library->book_removed = NULL;
    library->book_added = NULL ;
    library->book_list = NULL ;
    return library ;
}



/* no começo
*/
p_book add_book_front(p_library library){
    p_book new_book;
    new_book = malloc(sizeof(struct book));
    scanf("%s ", new_book->name) ;
    new_book->next = library->book_list ;
    library->books_total += 1 ;
    return new_book;
}

// p_book add_book_back(p_library library){
//     p_book new_book, book ;
//     new_book = malloc(sizeof(struct book));
//     scanf("%f ", new_book->name) ;
//     new_book->next = NULL ;
//     for(book = library->book_list ; book != NULL ; book = book->next){
//         if (book->next == NULL){
//             book->next = new_book ;
//         }
//     }
//     library->book_added = new_book ;
//     library->books_total += 1 ;
//     return book ;
// }

void add_book_last(p_library library){
    p_book new_book ;
    new_book = malloc(sizeof(struct book));
    scanf("%s ", new_book->name) ;
    new_book->next = library->book_added->next ;
    library->book_added->next = new_book ;
    library->books_total += 1 ;
}

// void change_addition_place(int place){
//     if (place == 3){
//         // adicionar final
//     } else if (place == 4){
//         // começo
//     }
// }

void remove_book(p_library library){
    p_book book, temp_book;
    scanf("%s ", library->book_removed->name) ;
    for(book = library->book_list ; book != NULL ; book = book->next){
        if (compare_book_name(book->next->name, library->book_removed->name) == 0){
            temp_book = book->next->next ;
            book->next = temp_book ;
            free(temp_book->next) ;
            free(temp_book) ;
            break ;
        }
    }
    library->books_total -= 1 ;
}

int compare_book_name(char possible_book[], char book[]){
    for(int i=0; book[i] != '\0'; i++){
        if (possible_book[i] != '\0'){
            if (possible_book[i] != book[i]){
                return 1 ;
            }            
        } else{
            return 1 ;
        }
    }
    return 0 ;
}

void print_library(p_book book){
    // p_book book = library->book_list ;
    if (book != NULL){
        printf("%s, ", book->name) ;
        print_library(book->next) ;
    }


    // p_book book ;
    // for(book = library->book_list ; book != NULL ; book = book->next){
    //     printf("%f, ", book->name) ;
    // }

}

int read_command(char command[]){
    scanf("%s ", command) ;
    int set = compare_command(command) ;
    return set ;
}

void free_library(p_library){

}

int compare_command(char command[]){
    if (command[0] == 'a'){
        return 1 ;
    } else if (command[0] == 'r'){
        return 2 ;
    } else if (command[0] == 'f'){
        return 3 ;
    } else if (command[0] == 'i'){
        if (command[1] == 'n'){
            return 4 ;
        } else{
            return 5 ;
        }
    }
    return 6 ;
}