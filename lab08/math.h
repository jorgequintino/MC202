
typedef struct mathlib *p_mathlib ;

typedef struct expression *p_expression ;

struct expression {
    char data ;
    p_expression left, right, next;
} ;

struct mathlib {
    p_expression root ;
} ;

p_mathlib create_mathlib() ;

p_expression create_expression(char base) ;

p_expression create_tree_structure(char base) ;

p_expression push_expression(p_expression expression, p_expression stack) ;

p_expression pop_expression(p_expression stack, p_expression expression) ;

int is_letter(char base) ;

int is_number(char base) ;

int is_logic(char base) ;

void process_mathlib(p_expression expression) ;

void process_expression(p_expression expression) ;

void process_or_and(p_expression expression, int number) ;

void process_bigger_smaller_equals(p_expression expression, int number) ;

void process_equals_different(p_expression expression, int number) ;

void cleaning(p_expression expression) ;

void print_input(p_expression expression) ;

void free_mathlib(p_mathlib mathlib) ;

void free_expression(p_expression expresion) ;