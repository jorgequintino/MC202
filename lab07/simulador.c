#include <stdio.h>
#include <stdlib.h>
#include "workers.h"

int main(){
    int entries, length_q, length_p, queue_space, time = 0, delay = 0, lathe_created = 0;

    scanf("%d %d ", &length_q, &length_p);
    scanf("%d ", &entries);

    p_queue queue = create_queue(length_q);
    p_classer classer = create_classer();

    p_pile pile = create_pile(length_p);
    p_packer packer = create_packer();

    printf("##### Simulação\n") ;

    while (packer->packed != entries){

        time++;

        if (lathe_created > 0){

            packer_working(packer, pile) ;

            if(classer->classed < entries){
                classer_working(classer, queue, pile) ;
            }

        }

        if (lathe_created < entries){

            queue_space = checking_queue_fullness(queue);

            if (queue_space != -1){
                p_lathe lathe = create_lathe();
                lathe_created += 1;
                add_lathe_queue(queue, lathe, queue_space);
            } else{
                delay += 1;
            }
        }
        
        print_simulation(queue, pile, time);
        if (packer->packed == entries){
            print_delay(delay);
        }

        reset_queue(queue) ;
        reset_pile(pile) ;

    }

    free_queue(queue);
    free_pile(pile);
    free_workers(classer, packer) ;

    return 0 ;

}