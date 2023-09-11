typedef struct bat *p_bat ;

struct bat{
    int* memory ;
    int* data ; // [place, length]
    int alocated ;
    int space ;
} ;

p_bat create_memory(int instructions) ;

void set_bat_alloc(p_bat bat_memory, int amount, int instructions) ;

void bat_alloc(int amount, p_bat bat_memory, int place, int instructions) ;

void bat_free(int place, p_bat bat_memory, int instructions) ;

void bat_print(int begin, p_bat bat_memory) ;

void bat_use(p_bat bat_memory) ;

int check_memory(p_bat bat_memory, int amount, int place) ;

int check_quarter(p_bat bat_memory) ;

void expand(p_bat bat_memory) ;

void cut(p_bat bat_memory) ;

void free_bat_computer(p_bat bat_memory) ;

int compare_command(char command[]) ;