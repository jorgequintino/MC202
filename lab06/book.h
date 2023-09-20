# define MAX 55

typedef struct book *p_book ;
struct book{
    char name[MAX] ;
    p_book next ;
} ;

p_book create_book() ;

void free_book(p_book book) ;