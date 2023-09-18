# define MAX 55

typedef struct book *p_book ;
struct book{
    char name[MAX] ;
    p_book next ;
} ;

typedef struct library *p_library ;
struct library{
    int books_total ;
    p_book book_removed ;
    p_book book_added ;
    p_book book_list ;
} ;

p_library setting_library() ;

p_book add_book_front(p_library library) ;

void add_book_last(p_library library) ;

void remove_book(p_library library) ;

int compare_book_name(char possible_book[], char book[]) ;

void print_library(p_book book) ;

int read_command(char command[]) ;

int compare_command(char command[]) ;