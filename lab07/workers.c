# include <stdio.h>
# include <stdlib.h>
# include "workers.h"

/* This p_packer function creates the packer for simulation.
It returns said packer.
Arg:
    None
Return:
    packer (p_packer)
*/
p_packer create_packer(){
    p_packer packer ;
    packer = malloc(sizeof(struct packer)) ;
    packer->doing = NULL ;
    packer->packed = 0 ;
    return packer ;
}

/* This p_classer function creates the classifier for simulation.
It returns said classifier.
Arg:
    None
Return:
    classer (p_classer)
*/
p_classer create_classer(){
    p_classer classer ;
    classer = malloc(sizeof(struct classer)) ;
    classer->doing = NULL ;
    classer->classed = 0 ;
    return classer ;
}

/* This void function guides how the packer works.
Arg:
   packer (p_packer)
   pile (p_pile)
Return:
    None
*/
void packer_working(p_packer packer, p_pile pile){
    if (packer->doing == NULL){

        if (pile->using > 0){

            packer->doing = remove_lathe_pile(pile);
            packer->doing->package_time -= 1;

        }
    } else{

        if (packer->doing->package_time == 0){

            pile->out = 1 ;
            packer->packed += 1;

            free_lathe(packer->doing);

            if (pile->using > 0){

                packer->doing = remove_lathe_pile(pile);
                packer->doing->package_time -= 1;

            }else{
                packer->doing = NULL ;
            }
        } else{
            packer->doing->package_time -= 1;
        }
    }
}

/* This void function guides how the classer works.
Arg:
   classer (p_classer)
   queue (p_queue)
   pile (p_pile)
Return:
    None
*/
void classer_working(p_classer classer, p_queue queue, p_pile pile){
    if (classer->doing == NULL){

        if (queue->using > 0){

            classer->doing = remove_lathe_queue(queue);
            classer->doing->class_time -= 1;

        }
    } else{

        if (classer->doing->class_time == 0){

            if(checking__pile_fullness(pile) > -1){

                pile->stack = add_lathe_pile(pile, classer->doing);
                queue->out = 1 ;
                classer->classed += 1;

                if (queue->using > 0){

                    classer->doing = remove_lathe_queue(queue);

                    classer->doing->class_time -= 1;

                }else{
                    classer->doing = NULL ;                            
                }                 
            }

        } else{
            classer->doing->class_time -= 1;
        }
    }
}

/* This void function prints if a lathe has either entered or left classification
and packing every minute of the simulaion.
Arg:
   queue (p_queue)
   pile (p_pile)
   time (int)
Return:
    None
*/
void print_simulation(p_queue queue, p_pile pile, int time){
    printf("Min. %d: Classificação (+%d,-%d) | Embalagem (+%d,-%d).\n", time, queue->in, queue->out, pile->in, pile->out) ;
}

/* This void function prints the delay of the simulation created.
Arg:
   delay (int)
Return:
    None
*/
void print_delay(int delay){
    printf("Tempo atraso: %d.\n", delay) ;
}

/* This void function frees the space alocated in the making of the workers.
Arg:
    classer (p_classer) 
    packer (p_packer)
Return:
    None
*/ 
void free_workers(p_classer classer, p_packer packer){
    free(classer) ;
    free(packer) ;
}