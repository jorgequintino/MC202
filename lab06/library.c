# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "library.h"

/* This p_library function creates the library, and sets up its
configurations, and returns it.
ARG:
    none
RETURN:
    (p_library) library
*/ 
p_library setting_library(){
    p_library library ;
    library = malloc(sizeof(struct library)) ;
    library->first = 1 ;
    library->last = 1 ;
    library->book_removed = create_book();
    library->book_removed->name[0] = '\0' ;
    library->book_removed->next = NULL ;
    library->book_added = NULL ;
    library->book_list = NULL ;
    library->support = NULL ;
    return library ;
}

/* This p_book function adds the book in the first position of the pile.
It then returns the new pile.
ARG:
    (p_library) library
RETURN:
    (p_book) new_book
*/ 
p_book add_book_front(p_library library){

    p_book new_book;
    new_book = create_book();
    fgets(new_book->name, 55, stdin);
    new_book->name[strlen(new_book->name)-1]='\0';

    new_book->next = library->book_list ;
    library->book_added = new_book ;

    return new_book;
}

/* This void function adds the book in the pile. It reads its name, and checks if there
is at least one book in the pile. If so, it will add the new book according the the previous.
If not, it will add the first book. It returns nothing.
ARG:
    (p_library) library
    (int) final
RETURN:
    none
*/ 
void add_book_last(p_library library, int final){

    p_book new_book ;
    new_book = create_book() ;
    fgets(new_book->name, 55, stdin);
    new_book->name[strlen(new_book->name)-1]='\0';


    if (library->book_added != NULL){
        // if at least one book was added.

        if(compare_book_name(library->book_removed->name, library->book_added->name) != 0){
            // if the last book removed was not the last added.

            if (final == 0){
                // if the book it's added after the command 'final'

                new_book->next = NULL ;
                for(p_book book = library->book_list ; book != NULL ; book = book->next){
                    if (book->next == NULL){
                        book->next = new_book ;
                        break ;        
                    }
                }

            } else{

                new_book->next = library->book_added->next ;        
                library->book_added->next = new_book ;                     
            }
                  
        } else{
            // if the last book removed was the last added.

            if (library->first == 1){
                // if the last book removed was on the top of the pile.
                free_book(library->book_added) ;
                new_book->next = library->book_list ;
                library->book_list = new_book ;

            } else if (library->last == 1){
                // if the last book removed was on the end of the pile.
                new_book->next = NULL ;
                for(p_book book = library->book_list ; book != NULL ; book = book->next){
                    if (book->next == NULL){
                        book->next = new_book ;
                        break ;        
                    }
                }
                free_book(library->support) ;

            } else{
                // if the last book removed was in the middle of the pile.
                new_book->next = library->book_removed->next->next ; // previous_book->next
                library->book_removed->next->next = new_book;                
            }
        }
    } else{
        // adding the first book.
        library->book_list = new_book ;
        new_book->next = NULL ;
    }
    
    library->book_added = new_book ;

}

/* This void function removes the book in the pile. It reads its name, and searches
for it in the pile and the removes it according to the position it's holding in the
library pile. It returns nothing.
ARG:
    (p_library) library
RETURN:
    none
*/ 
void remove_book(p_library library){
    int count = 0 ;

    p_book book, before;
    fgets(library->book_removed->name, 55, stdin);
    library->book_removed->name[strlen(library->book_removed->name)-1]='\0';
    for(book = library->book_list ; book != NULL ; book = book->next){

        count++ ;

        if (compare_book_name(book->name, library->book_removed->name) == 0){
            if (count == 1){
                // if it's the first book on the pile.
                library->book_list = book->next ;
                library->first = 1 ;
                library->last = 0 ;
                break ; 

            } else{
                // if it's in the middle of the pile.
                before->next = book->next ;
                library->book_removed->next = before ; // holds the address of the previous for later use.
                library->first = 0 ;
                library->last = 0 ;

                if(book->next == NULL){
                    library->last = 1 ;
                    library->support = book ;
                    // if the removed book are the last one, the support holds its address for a while.
                } else{
                    free_book(book) ;                       
                }

                break ;
            }
        } else{
            before = book ;
            // it holds the address of the previous book for possible use.
        }
    }

}

/* This int function compares two strings to know if they're the same.
If they have the same length, it'll return 1 for different strings or 0
for the same. If they haven't, it'll return the difference in their lengths.
ARG:
    (char) possible_book
    (char) book
RETURN:
    (int) size
*/ 
int compare_book_name(char possible_book[], char book[]){
    for(int i=0; book[i] != '\0'; i++){
        if (possible_book[i] != book[i]){
            return 1 ;         
        }
    }    
    int size = (strlen(possible_book)) - (strlen(book)) ;
    return size ;
}

/* This void function prints the books in the library in order.
It returns nothing.
ARG:
    (p_library) library
RETURN:
    none
*/ 
void print_library(p_library library){

    for(p_book book = library->book_list; book!= NULL; book= book->next){
        if(book->next != NULL){
            printf("%s, ", book->name) ;           
        } else{
            printf("%s", book->name) ;            
        }        
    }

    printf("\n") ;
}

/* This int function reads the command and return the integer according
to the action required next.
ARG:
    (char) command
RETURN:
    (int) set
*/ 
int read_command(char command[]){
    int length = scanf("%s ", command) ;
    command[length+1] = '\0' ;
    int set = compare_command(command) ;
    return set ;
}

/* This void function frees the spaces allocated during the program.
It returns nothing.
ARG:
    (p_library) library
RETURN:
    none
*/ 
void free_library(p_library library){
    p_book book = library->book_list;

    while (book != NULL) {
        p_book next_book = book->next;
        free_book(book) ;
        book = next_book ;
    }

    free_book(library->book_removed) ;
    free(library) ;
}

/* This int function compares the command to the initials of possible orders
to get the correct one working.
ARG:
    (char) command
RETURN:
    (int)
*/ 
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
    // '6' means the "EOF" .
    return 6 ;
}