/*
  Owen Ramsey
  lab9
  5/22/24
*/

/*
   lab9:
   createLabel was added so we can use it in ast.c 
   the h file contains the ASTtypes which are types of statements
   and constants we use in code, the ASToperators that are used in 
   expressions thats accessed through the enum AST_OPERATORS operator,
   theres the MY_DATA_TYPE that can return either a int or void,
   and then the ASTnodetype has the attributes of the AST nodes like the 
   name and value and label they carry unless they're null, then it defines
   the ASTCreateNode and PT functions
*/


#include<stdio.h>
#include<malloc.h>
#include "symtable.h"
#ifndef AST_H
#define AST_H
int mydebug;

/* define the enumerated types for the AST.  THis is used to tell us what 
sort of production rule we came across */


enum ASTtype {
   A_FUNCTIONDEC,
   A_VARDEC,
   A_COMPOUND,
   A_WRITE,
   A_NUM,
   A_PARAM,
   A_EXPR,
   A_SLCT,
   A_SLCTBODY,
   A_WHILE,
   A_ASSIGN,
   A_VAR,
   A_RETURN,
   A_READ,
   A_CALL,
   A_ARG, 
   A_EXPRSTMT
   
};

// Math Operators

enum AST_OPERATORS {
   A_PLUS,
   A_MINUS,
   A_TIMES,
   A_DIVIDE,
   A_MODULUS,
   A_GT,
   A_GE,
   A_LT,
   A_LE,
   A_EQ,
   A_NE,
   A_UNARYMINUS

};

enum AST_MY_DATA_TYPE {
   A_INTTYPE,
   A_VOIDTYPE

};

/* define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code 
*/

typedef struct ASTnodetype
{
     char * label;
     enum ASTtype type;
     enum AST_OPERATORS operator;
     char * name;
     int value;
     enum AST_MY_DATA_TYPE my_data_type;
     struct SymbTab *symbol;
     struct ASTnodetype *s1,*s2, *next ; /* used for holding IF and WHILE components -- not very descriptive */
} ASTnode;


/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
ASTnode *ASTCreateNode(enum ASTtype mytype);

void PT(int howmany);


/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p);
int checkParams(ASTnode *actuals, ASTnode *formals);
char * CreateLabel();

#endif // of AST_H
