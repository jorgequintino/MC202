# include <stdlib.h>
# include <stdio.h>
# include "book.h"

p_book create_book(){
    p_book new_book;
    new_book = malloc(sizeof(struct book));
    return new_book ;
}

void free_book(p_book book){
    free(book) ;
}