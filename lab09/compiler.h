#define MAXLINE 201

enum colour {RED, BLACK} ;

typedef struct variable *p_variable ;

typedef struct symbols *p_symbols ;

struct variable{
    char name[MAXLINE];
    int type;
    enum colour colour ;
    p_variable left, right;
} ;

struct symbols{
    p_variable root ;
} ;

p_symbols creating_symbols() ;

p_variable creating_variable(int key, char name[]) ;

p_variable searching_variable(p_variable root, char name[]) ;

p_variable fixing_tree_structure(p_variable root) ;

p_variable inserting_variable(p_variable root, int key, char name[]) ;

p_variable inserting(p_variable root, int key, char name[]) ;

p_variable left_leaning(p_variable root) ;

p_variable right_leaning(p_variable root) ;

int checking_errors(p_variable root, char namefirst[], char namesecond[], char namethird[], char operator[], int line_number) ;

int is_valid_line(char line[]) ;

int is_letter(char firstletter) ;

int istype(char line[]) ;

int isBLACK(p_variable variable) ;

int isRED(p_variable variable) ;

void up_red(p_variable root) ;

void print_variables(p_variable root) ;

void print_type(int number) ;

void free_variable(p_variable root) ;

void free_symbol(p_symbols symbols) ;