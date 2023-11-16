#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "compiler.h"

/* This p_symbols function creates the struct in which the root of the tree structure is saved.
It returns said struct named symbols.
ARG:
    None
RETURN:
    (p_symbol) symbols
*/
p_symbols creating_symbols(){
    p_symbols symbols = malloc(sizeof(struct symbols));
    symbols->root = NULL ;
    return symbols ;
}

/* This p_variable function creates the struct in which the data of a variable is saved.
It returns the new variable.
ARG:
    (int) key
    (char) name[]
RETURN:
    (p_variable) new_variable
*/
p_variable creating_variable(int key, char name[]){
    p_variable new_variable = malloc(sizeof(struct variable)) ;
    new_variable->left = new_variable->right = NULL ;
    new_variable->type = key ;
    new_variable->colour = RED ;
    strcpy(new_variable->name, name) ;
    return new_variable ;
}

/* This p_variable function searches for a variable at the tree structure. It does so by comparing the name searched with each variable name.
It returns the variable with the matching name.
ARG:
    (p_variable) root
    (char) name[]
RETURN:
    (p_variable) root
*/
p_variable searching_variable(p_variable root, char name[]){

    if (root == NULL || strcmp(name, root->name) == 0){
        return root ;        
    } if (strcmp(name, root->name) < 0){
        return searching_variable(root->left, name) ; 
    } else{
        return searching_variable(root->right, name) ;
    }
}

/* This p_variable function fixes the tree structure by rotating it to the correct direction based on the colour of the variables.
It returns the root.
ARG:
    (p_variable) root
RETURN:
    (p_variable) root
*/
p_variable fixing_tree_structure(p_variable root){
    if (isRED(root->right) && isBLACK(root->left))
        root = left_leaning(root) ;
    if (isRED(root->left) && isRED(root->left->left))
        root = right_leaning(root) ;
    if (isRED(root->left) && isRED(root->right))
        up_red(root) ;
    return root ;   
}

/* This p_variable function coordinates in which position the new variable must be pushed, based on the comparison of names using "strcmp". It then fixes the trees structure.
It returns the root.
ARG:
    (p_variable) root
    (int) key
    (char) name[]
RETURN:
    (p_variable) root
*/
p_variable inserting_variable(p_variable root, int key, char name[]){

    if (root == NULL){
        p_variable new_variable = creating_variable(key, name) ;
        return new_variable ;
    } if (strcmp(name, root->name) < 0){
        // name has an ascii value smaller than the one being compared, thus must go left at the tree.
        root->left = inserting_variable(root->left, key, name) ;
    } else{
        root->right = inserting_variable(root->right, key, name) ;
    }

    return root = fixing_tree_structure(root) ;
}

/* This p_variable function inserts a new variable at the tree structure, designating its root colour as Black.
It returns said root.
ARG:
    (p_variable) root
RETURN:
    (p_variable) root
*/
p_variable inserting(p_variable root, int key, char name[]){
    root = inserting_variable(root, key, name) ;
    root->colour = BLACK ;
    return root ;
}

/* This p_variable function corrrects the tree structure by rotating it to the left. It corrects its colouring in the process.
It returns the rotated variable.
ARG:
    (p_variable) root
RETURN:
    (p_variable) temp
*/
p_variable left_leaning(p_variable root){
    p_variable temp = root->right ;
    root->right = temp->left ;
    temp->left = root ;
    temp->colour = root->colour ;
    root->colour = RED ;
    return temp ;
}

/* This p_variable function corrrects the tree structure by rotating it to the right. It corrects its colouring in the process.
It returns the rotated variable.
ARG:
    (p_variable) root
RETURN:
    (p_variable) temp
*/
p_variable right_leaning(p_variable root){
    p_variable temp = root->left ;
    root->left = temp->right ;
    temp->right = root ;
    temp->colour = root->colour ;
    root->colour = RED ;
    return temp ;
}

/* This int function checks the errors done at D code and prints them. It does so by first searching the variables in the equation analyzed. If any of them hasn't been defined, it prints so. Then, if the second and third variable doesn't have the same type, it prints so. And at last, if the result is of a different type from the one designated, it prints so.
It returns "0" for not having an error or "1" for having one.
ARG:
    (p_variable) root
    (char) namefirst[]
    (char) namesecond[]
    (char) namethird[]
    (char) operator[]
    (int) line_number
RETURN:
    (int) number
*/
int checking_errors(p_variable root, char namefirst[], char namesecond[], char namethird[], char operator[], int line_number) {

    p_variable first, second, third ;
    first = searching_variable(root, namefirst) ;
    second = searching_variable(root, namesecond) ;
    third = searching_variable(root, namethird) ;

    if(first == NULL){
        printf("Linha %d: o símbolo %s não foi definido.\n", line_number, namefirst) ;
        return 1 ;

    } if(second == NULL){
        printf("Linha %d: o símbolo %s não foi definido.\n", line_number, namesecond) ;
        return 1 ;

    } if (third == NULL){
        printf("Linha %d: o símbolo %s não foi definido.\n", line_number, namethird) ;
        return 1 ;

    } if(second->type != third->type){
        printf("Linha %d: tipos incompatíveis: %s (", line_number, second->name) ;
        print_type(second->type) ;
        printf(") %s %s (", operator, third->name) ;
        print_type(third->type) ;
        printf(").\n") ;
        return 1 ;

    } if (first->type != second->type){
        printf("Linha %d: tipos incompatíveis: o símbolo %s espera ", line_number, first->name) ;
        print_type(first->type) ;
        printf(", obteve ") ;
        print_type(second->type) ;
        printf(".\n") ;
        return 1 ;

    }
    return 0 ;
}

/* This int function checks if the line at input is valid based on the criteria of:
I) Not being empty
II) Not having a parentesis in it
III) The first character of the first word being a letter
It returns "1" for being a valid line and "0" in case of being unvalid.
ARG:
    (char) line[]
RETURN:
    (int) number
*/
int is_valid_line(char line[]){

    if(strlen(line) <= 2){
        return 0 ;
    }

    char firstword[MAXLINE] ;
    char* parenthesis = strchr(line, '(') ;
    if (parenthesis != NULL){
        return 0 ; //unvalid line
    } else{
        sscanf(line, "%s", firstword);
        if(!is_letter(firstword[0])){
            return 0 ; // unvalid line
        }
    } 
    return 1 ;
}

/* This int function checks if the first character of a word is a letter.
It returns its conclusion.
ARG:
    (char) firstletter
RETURN:
    (bool)
*/
int is_letter(char firstletter){
    return (firstletter >= 'a' && firstletter <= 'z') || (firstletter >= 'A' && firstletter <= 'Z');
}

/* This int function checks if the word is a type designated word, meaning there's a variable being declared.
It returns "0" in case of not being a type, but if it is, it returns a number marking which one.
ARG:
    (char) line[]
RETURN:
    (int) number
*/
int istype(char line[]){
    if (strcmp(line, "int") == 0){
        return 1 ;
    } else if (strcmp(line, "char") == 0){
        return 2 ;
    } else if (strcmp(line, "double") == 0){
        return 3 ;
    }
    return 0 ;
}

/* This int function checks if the variable being analyzed is Black.
It returns the correction.
ARG:
    (p_variable) variable
RETURN:
    (enum) colour Black
*/
int isBLACK(p_variable variable){
    if(variable == NULL){
        return 1 ;
    }
    return variable->colour == BLACK ;
}

/* This int function checks if the variable being analyzed is Red.
It returns the correction.
ARG:
    (p_variable) variable
RETURN:
    (enum) colour Red
*/
int isRED(p_variable variable){
    if(variable == NULL){
        return 0 ;
    }
    return variable->colour == RED ;
}


/* This void function takes the colouring of Red up on the tree structure.
It returns none.
ARG:
    (p_variable) variable
RETURN:
    NONE
*/
void up_red(p_variable root){
    root->colour = RED ;
    root->left->colour = BLACK ;
    root->right->colour = BLACK ;
}

/* This void function prints the variables created in the code and its declared type. It does so by going trough the tree structure.
It returns none.
ARG:
    (p_variable) root
RETURN:
    NONE
*/
void print_variables(p_variable root){
    if(root!= NULL){
        print_variables(root->left) ;
        printf("%s ", root->name) ;
        print_type(root->type) ;
        printf("\n") ;
        print_variables(root->right) ;
    }
}

/* This void function prints the type marked for a variable based on the number designated to it.
It returns none.
ARG:
    (int) number
RETURN:
    NONE
*/
void print_type(int number){
    if(number == 1){
        printf("int");
    } else if(number == 2){
        printf("char") ;
    } else{
        printf("double") ;
    }
}

/* This void function frees the space alocated for the variables by going through the structure created.
It returns none.
ARG:
    (p_variable) root
RETURN:
    NONE
*/
void free_variable(p_variable root){
    if (root != NULL){
        free_variable(root->left) ;
        free_variable(root->right) ;
        free(root) ; 
    }
}

/* This void function frees the space alocated on the tree structure. It does so by freeing first the variables going through the spaces alocated and then it frees its root.
It returns none.
ARG:
    (p_symbol) symbols
RETURN:
    NONE
*/
void free_symbol(p_symbols symbols) {
    free_variable(symbols->root) ;
    free(symbols) ;
}