#include <stdio.h>
#include <stdlib.h>
#include "math.h"

/* This function checks if the char used is a letter.
ARG
    (char) base
RETURN
    (int)
*/ 
int is_letter(char base){
    return base > 96 && base < 123;
}

/* This function checks if the char used is a number.
ARG
    (char) base
RETURN
    (int)
*/ 
int is_number(char base){
    return base > 47 && base < 58;
}

/* This function checks if the char used is a logic one.
ARG
    (char) base
RETURN
    (int)
*/ 
int is_logic(char base) {
    return base == 'F' || base == 'T';
}

/* This function creates the struct in which the expression is saved.
It returns said expression.
ARG
    (char) base
RETURN
    (p_expression) expression
*/ 
p_expression create_expression(char base){
    p_expression expression = malloc(sizeof(struct expression)) ;
    expression->left = NULL ;
    expression->right = NULL ;
    expression->next = NULL ;
    expression->data = base ;
    return expression ;
}

/* This function creates the struct for the root of the tree 
in which the expressions are saved. It returns said tree.
ARG
    NONE
RETURN
    (p_mathlib) mathlib
*/
p_mathlib create_mathlib(){
    p_mathlib mathlib = malloc(sizeof(struct mathlib)) ;
    mathlib->root = NULL ;
    return mathlib ;
}

/* This function creates the tree in which the expression are saved.
It does so by stacking an expression if it's a letter or number, in
the case of it being an operator, it pops the last two ones pushed
creating a leaf of the tree structure used and pushes its root. It
returns the root of said structure.
ARG
    (char) base
RETURN
    (p_expression) stack
*/
p_expression create_tree_structure(char base){
    p_expression stack = NULL ;
    
    while(base != '\n'){
        p_expression expression = create_expression(base) ;
        if (is_letter(base) || is_number(base)){
            stack = push_expression(expression, stack) ; 
            
        } else{
            // it's a operator.
            stack = pop_expression(stack, expression) ;
            stack = push_expression(expression, stack) ;
            
        }
        scanf("%c", &base) ;
    }

    return stack ;
}

/* This function pushes the expression in the stack. It does so
by returning the new expression top of the stack.
ARG
    (p_expression) expression
    (p_expression) stack
RETURN
    (p_expression) expression
*/
p_expression push_expression(p_expression expression, p_expression stack){
    expression->next = stack ;
    return expression ;
}

/* This function pops out of the expression in the stack. It does so
by returning the new stack root top of the stack.
ARG
    (p_expression) stack
    (p_expression) expression
RETURN
    (p_expression) stack->next->next
*/
p_expression pop_expression(p_expression stack, p_expression expression){
    expression->right = stack ;
    expression->left = stack->next ;
    return stack->next->next ;
}

/* This function coordinates the processing of the full mathematic expression.
It returns none.
ARG
    (p_expression) expression
RETURN
    NONE
*/
void process_mathlib(p_expression expression){

    if (expression != NULL){
        process_mathlib(expression->left) ;
        process_mathlib(expression->right) ;
        process_expression(expression) ;
    }
}

/* This function calls specific process function based on the
operator symbol being used.
ARG
    (p_expression) expression
RETURN
    NONE
*/
void process_expression(p_expression expression){
    if(expression->data == 61 || expression->data == 33){
        // if it's equal or different symbols.
        process_equals_different(expression, expression->data) ;

    } else if(expression->data == 62 || expression->data == 125 || expression->data == 60 || expression->data == 123){
        // if it's bigger or smaller symbols.
        process_bigger_smaller_equals(expression, expression->data) ;

    } else if(expression->data == 38 || expression->data == 124){
        // if it's or, and symbols. 
        process_or_and(expression, expression->data) ;
    }
}

/* This function process "|" and "&" operator. It does so by checking if
the data is a logic.
ARG
    (p_expression) expression
    (int) number
RETURN
    NONE
*/
void process_or_and(p_expression expression, int number){
    if (number == 38){
        // &&
        if (expression->left->data == 'F' || expression->right->data == 'F'){
            // at least one side it's "F".
            expression->data = 'F' ;
            cleaning(expression);
        } else if (expression->left->data == 'T' && expression->right->data == 'T'){
            //  none it's "F".
            expression->data = 'T' ;
            cleaning(expression); 
        }        
    } else{
        // ||
        if (expression->left->data == 'T' || expression->right->data == 'T'){
            // at least one side it's "T".
            expression->data = 'T' ;
            cleaning(expression);               
        } else if (expression->left->data == 'F' && expression->right->data == 'F'){
            //  none it's "T".
            expression->data = 'F' ;
            cleaning(expression);
        }        
    }
}

/* This function process bigger and smaller operators.
It does so by checking which symbol were used, and then followed
by the rules of processing.
ARG
    (p_expression) expression
    (int) number
RETURN
    NONE
*/
void process_bigger_smaller_equals(p_expression expression, int number){
    if(number == 62 || number == 125){
        // bigger or equal.

        if (expression->left->data == expression->right->data && (is_number(expression->left->data) || is_letter(expression->left->data))){
            // if it's equal expression, expect the logic ones.
            if (number == 62){
                // only bigger.
                expression->data = 'F' ;
                cleaning(expression);
            } else{
                // bigger or equals.
                expression->data = 'T' ;
                cleaning(expression);
            }
        } else if (is_number(expression->left->data) && is_number(expression->right->data)){
            // comparing two numbers.
            if (number == 62){
                // analysing which number is bigger.
                expression->data = expression->left->data > expression->right->data ? 'T' : 'F';
                cleaning(expression);
            } else{
                // analysing which number is bigger or equal.
                expression->data = expression->left->data >= expression->right->data ? 'T' : 'F';
                cleaning(expression);
            }
        } else if(((expression->left->data == '0')||(expression->right->data == '9')) && number == 62){
            // border case if it's only bigger.
            expression->data = 'F' ;
            cleaning(expression);             
        } else if(((expression->left->data == '9')||(expression->right->data == '0')) && number == 125){
            // border case if it's bigger or equals.
            expression->data = 'T' ;
            cleaning(expression);
        }

    } else{
        // smaller or equals

        if (expression->left->data == expression->right->data && (is_number(expression->left->data) || is_letter(expression->left->data))){
            // if it's equal expression, expect the logic ones.
            if (number == 60){
                // only smaller.
                expression->data = 'F' ;
                cleaning(expression);
            } else{
                // smaller or equals.
                expression->data = 'T' ;
                cleaning(expression);
            }
        } else if (is_number(expression->left->data) && is_number(expression->right->data)){
            // comparing two numbers.
            if (number == 60){
                // analysing which number is bigger.
                expression->data = expression->left->data < expression->right->data ? 'T' : 'F';
                cleaning(expression);
            } else{
                // analysing which number is bigger or equals.
                expression->data = expression->left->data <= expression->right->data ? 'T' : 'F';
                cleaning(expression);
            }
        } else if(((expression->right->data == '0')||(expression->left->data == '9')) && number == 60){
            // border case if it's only smaller.
            expression->data = 'F' ;
            cleaning(expression);
        } else if(((expression->right->data == '9')||(expression->left->data == '0')) && number == 123){
            // // border case if it's only smaller or equals.
            expression->data = 'T' ;
            cleaning(expression);
        }

    }
}

/* This function process equals or different operators.
ARG
    (p_expression) expression
    (int) number
RETURN
    NONE
*/
void process_equals_different(p_expression expression, int number){
    if(expression->left->data == expression->right->data && (is_number(expression->left->data) || is_letter(expression->left->data) || is_logic(expression->left->data))){
        // equal number , letters or logic symbols.
        if (number == 61){
            //  if it's equal.
            expression->data = 'T' ;
            cleaning(expression);               
        } else{
            // if it's different.
            expression->data = 'F' ;
            cleaning(expression);
        }
    } else{
        if(is_number(expression->left->data) && is_number(expression->right->data)){
            // if both are numbers.
            if (number == 61){
                //  if it's equal.
                expression->data = 'F' ;
                cleaning(expression);
            } else{
                //  if it's different.
                expression->data = 'T' ;
                cleaning(expression);
            }
        }
    }
}

/* This function cleans the data below the expression processed.
ARG
    (p_expression) expression
RETURN
    NONE
*/
void cleaning(p_expression expression){
    free_expression(expression->right) ;
    free_expression(expression->left) ;
    expression->left = NULL ;
    expression->right = NULL ; 
}

/* This function prints the full mathematic expression. It opens a parathesis
when there's a new expression being set and closes it when it's done.
ARG
    (p_expression) expression
    (int) number
RETURN
    NONE
*/
void print_input(p_expression expression){

    if (expression != NULL){

        if ((!is_number(expression->data) && !is_letter(expression->data)) && !is_logic(expression->data)){
            printf("(") ;
        }

        print_input(expression->left) ;

        if ((!is_number(expression->data) && !is_letter(expression->data)) && !is_logic(expression->data)){
            printf(" %c ", expression->data) ;  
        } else{
            printf("%c", expression->data) ;
        }

        print_input(expression->right) ;

        if ((!is_number(expression->data) && !is_letter(expression->data)) && !is_logic(expression->data)){
            printf(")") ;
        }

    }

}

/* This function frees the root of the tree structure. But first it calls
the function responsible for freeing its leaves.
ARG
    (p_expression) expression
RETURN
    NONE
*/
void free_mathlib(p_mathlib mathlib){
    free_expression(mathlib->root) ;
    free(mathlib) ;
}

/* This function frees a expression, by going every expresion above it first.
ARG
    (p_expression) expression
RETURN
    NONE
*/
void free_expression(p_expression expresion){
    if (expresion != NULL){
        free_expression(expresion->left) ;
        free_expression(expresion->right) ;
        free(expresion) ;        
    }
}