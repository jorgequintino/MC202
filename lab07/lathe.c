# include <stdio.h>
# include <stdlib.h>
# include "lathe.h"

/* This p_lathe function creates a lathe for simulation.
It returns said lathe.
Arg:
    None
Return:
    lathe (p_lathe)
*/
p_lathe create_lathe(){
    p_lathe lathe;
    lathe = malloc(sizeof(struct lathe)) ;
    scanf("%s %d ", lathe->size, &lathe->type) ;
    setting_time(lathe) ;
    return lathe ;
}

/* This void function sets the arguments in the previously created lathe.
Arg:
    lathe(p_lathe)
Return:
    None
*/
void setting_time(p_lathe lathe){
    lathe->next = NULL ;
    for(int i=1; i<4; i++){
        if (lathe->size[0] == 'p'){
            lathe->class_time = 1 ;
            lathe->package_time = lathe->type ;
        } else if(lathe->size[0] == 'm'){
            lathe->class_time = 2 ;
            lathe->package_time = lathe->type + 1;
        } else{
            lathe->class_time = 3 ;
            lathe->package_time = lathe->type + 1 ;
        }
    }
}

/* This void function frees the space alocated in the making of the lathe.
Arg:
    lathe (p_lathe)
Return:
    None
*/ 
void free_lathe(p_lathe lathe){
    free(lathe) ;
}