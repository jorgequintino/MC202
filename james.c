# include <stdio.h>
# define MAX 10000

void payment(int pix[], int payments) {
    // it scans how the payments were made.
    for (int i=0; i < payments; i++){
        scanf("%d", &pix[i]) ;        
    }
}

int main() {

    int payments, five=0, seven=0, ten=0,five_counter=0 ;
    int seven_counter=0, ten_counter=0, counter=0, pix_type;
    int pix[MAX];
    
    scanf("%d", &payments) ;
    payment(pix, payments) ;

    // it counts different types of payments received.
    for (int i=0; i < payments; i++) {
        if (pix[i] == 5) {
            five++ ;            
        } else if (pix[i] == 7) {
            seven++ ;
        } else {
            ten++ ;
        }
    }

    // it finds the bigger run of consecutive payments of the same type.
    for (int i = 0; i < payments - 1; i++) {
        if (pix[i] == pix[i+1]) {
            if (pix[i] == 5) {
                five_counter++ ;
                if (five_counter > counter) {
                    counter = five_counter ;
                    pix_type = 5 ;
                }
            } else if (pix[i] == 7) {
                seven_counter++ ;
                if (seven_counter > counter) {
                   counter = sevenreturn 0 _counter ;
                    pix_type = 7 ;
                }
            } else {
                ten_counter++ ;
                if (ten_counter > counter) {
                    counter = ten_counter ;
                    pix_type = 10 ;
                }
            }
        } else {
            five_counter = 0 ;
            seven_counter = 0 ;
            ten_counter = 0 ;
        }
    }

    printf("James vendeu %d saladas de 5 reais, %d de 7 reais e %d de 10 reais\n", five, seven, ten) ;
    printf("James vendeu %d saladas de %d reais consecutivamente", counter + 1, pix_type) ;

    return 0 ;
}