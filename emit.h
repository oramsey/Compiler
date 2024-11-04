/*
  Owen Ramsey
  lab9
  5/3/24
*/

/*
defines WSIZE and LOGWSIZE for use in emit.c
defines all the functions used in emit.c
*/


#ifndef EMIT_H
#define EMIT_H
#include "ast.h"

#define WSIZE 4
#define LOGWSIZE 2

    void EMIT (ASTnode *p, FILE *fp);
    void EMIT_GLOBALS(ASTnode *p, FILE *fp);
    void EMIT_STRINGS(ASTnode *p, FILE *fp);
    void EMIT_AST(ASTnode *p, FILE *fp);
    void emit_function(ASTnode *p, FILE *fp);
    void emit_write(ASTnode *p, FILE *fp);
    void emit_expression(ASTnode *p, FILE *fp);
    void emit_read(ASTnode *p, FILE *fp);
    void emit_var(ASTnode *p, FILE *fp);
    void emit_assign(ASTnode *p, FILE *fp);
    void emit_while(ASTnode *p, FILE *fp);
    void emit_slct(ASTnode *p, FILE *fp);
    void emit_param(ASTnode *p, FILE *fp, int count);
    void emit_args(ASTnode *p, FILE *fp, int count);
    void emit_call(ASTnode *p, FILE *fp);
    


#endif