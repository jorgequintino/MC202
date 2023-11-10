# ifndef LATHE_H
# define LATHE_H

# define MAXSIZE 7

typedef struct lathe *p_lathe ;

struct lathe{
    p_lathe next ;
    char size[MAXSIZE] ;
    int type ;
    int class_time ;
    int package_time ;
} ;

p_lathe create_lathe() ;

void setting_time(p_lathe lathe) ;

void free_lathe(p_lathe lathe) ;

# endif