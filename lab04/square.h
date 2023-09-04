/* Struct to design the content of the square in wich we wish to set.
*/ 
typedef struct square *p_square ;

struct square{
    int** matrix ;
    int length ;
    int line ;
    int collum ;
} ;

p_square create_square(int length) ;

int add_square_values(int i, int j, p_square square) ;

void compare_quater(p_square square) ;

void change_square(p_square square) ;

void cut_square(p_square square) ;

void change_element(int line, int collum, int new_element, p_square square) ;

void print_processing(int length, p_square square) ;

void free_square(p_square square) ;