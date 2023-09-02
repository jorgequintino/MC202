/* Struct to design the content of the square in wich we wish to set.
*/ 
typedef struct square *p_square ;

struct square{
    int** matrix ;
    int length ;
} ;

p_square create_square(int length) ;

void add_square_values(int* p_sum, int line, int collum, int l_length, int c_length, p_square square) ;

int compare_quater(p_square square) ;

int** remove_square(p_square square, int line, int collum) ;

void cut_square(p_square square) ;

void change_element(int line, int collum, int new_element, p_square square) ;

void print_first(p_square square) ;

void print_processing(p_square square) ;

void free_square(p_square square) ;