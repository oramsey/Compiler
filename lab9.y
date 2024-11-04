%{
/*
    Owen Ramsey
    lab 9
    spring 370
    5/3/2024
*/  



/*
        lab9:
        This is C minus code implementing a compiler using yacc in this file
        this file is yacc grammar added Syntax Directed Semantic action 
        because we're using an abstract syntax tree added type node, operator, and dtype
        and added those to union as well
        introduced a symbol table by including symtable.h
        we made global varibles level an offset
        Used function CreateTemp to hold intermiadte values in operations and assignmemt statement
        used other aspects of the symbTable object for type checking thing like int or void and things like scalar and array
        and we use Insert, Search, and Delete Functions from symtable
        we added more fuctionallity to debug in main
        and we're accessing our .asm file in main as well.
    
*/




#include "ast.h"
#include "emit.h"
#include <stdlib.h>
    /* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "symtable.h"
#include <string.h>


ASTnode *PROGRAM;

/* added int yylex() to resolve warning */
int yylex();
//#include "lex.yy.c"
/* added extern int mydebug to add the mydebug from the lex file to the yacc file */
extern int mydebug;
extern int lineCount;
// global vars
int LEVEL= 0;
int OFFSET = 0;
int GOFFSET = 0;
int MAXOFFSET = 0;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("YACC BARFFF %s line number %d\n", s, lineCount);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start Program

%union {
      int value;
      char * string;
      ASTnode *node;	
       enum AST_OPERATORS operator;
      enum AST_MY_DATA_TYPE d_type;
}
//token declarations
%token <string> T_STRING
%token <value>T_NUM
%token  <string>T_ID  
%token T_WRITE
%token T_RETURN
%token T_WHILE
%token T_IF
%token T_ELSE
%token T_INT
%token T_VOID
%token T_READ
%token T_GT      
%token T_LT
%token T_GE
%token T_LE
%token T_EQ
%token T_NE

%type <node> Declaration_List Declaration Var_Declaration Var_List Fun_Declaration Compound_Stmt Params Local_Declarations Statement_List Statement Write_Stmt Expression Simple_Expression Additive_Expression Term Factor Var Call Param_List Param  Expression_Stmt Selection_Stmt Iteration_Stmt Assignment_Stmt Return_Stmt Read_Stmt Args Arg_List
%type <d_type> Type_Specifier
%type <operator> Relop Addop Multop
%%  /* end specs, begin rules */

Program: Declaration_List  {PROGRAM = $1;}
    ; // Program starts with a Declaration_List
    
Declaration_List: Declaration {$$ = $1;}
         | Declaration Declaration_List
           {$$ = $1;
            $$ -> next = $2;
            }// Declaration_List may contain one or more Declarations
         ;
         
Declaration: Var_Declaration {$$ = $1;} // Declaration can be a Variable Declaration
        | Fun_Declaration {$$=$1;
        		   } // or a Function Declaration
        ;

Var_Declaration: Type_Specifier Var_List ';'
		 {
		 ASTnode *p=$2;
		 while(p!=NULL)
		        {
		 	p->my_data_type = $1;
		 	
		 	if (Search(p->name, LEVEL, 0) != NULL){
                                yyerror(p->name);
                                yyerror("Symbol table already defined.");
                                exit(1);
                        }
                        if(p->value == 0 ){
                                p->symbol = Insert(p->name, p->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET );
                                OFFSET++;
                        }
                        else{
                               p->symbol = Insert(p->name, p->my_data_type, SYM_ARRAY, LEVEL, p->value, OFFSET );
                                OFFSET += p->value;
                        }
                        p = p->s1;
		 	}
		 $$ = $2;
		 }// Variable Declaration includes Type specifier, Var_List, and ';'
        ;
        
Var_List: T_ID {$$=ASTCreateNode(A_VARDEC);
		$$->name = $1;
		} // Var_List can be a single ID
        | T_ID '[' T_NUM ']' {$$=ASTCreateNode(A_VARDEC);
        		      $$->name = $1;
        		      $$->value = $3;} // or an ID with array size
        | T_ID ',' Var_List 
        	{$$=ASTCreateNode(A_VARDEC);
        	 $$->name = $1;
        	 $$->s1 = $3;} 
        | T_ID '[' T_NUM ']' ',' Var_List {$$=ASTCreateNode(A_VARDEC);
        		      		   $$->name = $1;
        		      		   $$->value = $3;
        		      		   $$->s1 = $6;} // or an array followed by comma separated list of IDs
        ;
        
Type_Specifier: T_INT {$$ = A_INTTYPE;}// Type Specifier can be INT
        	| T_VOID{$$ = A_VOIDTYPE;} // or VOID
        	;
        
Fun_Declaration : Type_Specifier T_ID  {if (Search($2, LEVEL, 0) != NULL){
                                        yyerror($2);
                                        yyerror("ALREADY USED FUN NAME DIEEE");
                                        exit(1);
                                }
                                        
                                        Insert($2,$1,SYM_FUN,LEVEL,0,0);
                                        
                                        GOFFSET = OFFSET;
                                        OFFSET = 2;
                                        MAXOFFSET = OFFSET;
                                        } 
                                        '(' Params ')' {Search($2,LEVEL,0)->fparms = $5;} Compound_Stmt  
				{	
					$$ = ASTCreateNode(A_FUNCTIONDEC);
					$$->name = $2;	
					$$->my_data_type = $1;
					$$->s1 = $5;
					$$->s2 = $8;
                                        $$->symbol = Search($2, LEVEL, 0);
                                        $$->symbol->offset = MAXOFFSET;
                                        OFFSET -= Delete(1);
                                        LEVEL = 0;
                                        OFFSET = GOFFSET;
                                        
				} // Function Declaration includes Type specifier, ID, Params, and Compound_Stmt
        ;
Params: T_VOID {$$ = NULL;} // Params can be VOID
        | Param_List {$$ = $1;} // or a list of Parameters
        ;
        
Param_List: Param {$$ = $1;}
        | Param ',' Param_List {$$ = $1;
        			$$->next = $3;
        			} // Parameters can be a single Param or a comma separated list of Params
        ;
        
Param: Type_Specifier T_ID  { if(Search($2,LEVEL+1, 0) != NULL){
                                yyerror($2);
                                yyerror("PARAM ALREADY USED DIEEE");
                                exit(1);
                                }

                             $$ = ASTCreateNode(A_PARAM);
			     $$->name = $2;
		             $$->my_data_type = $1;
                             $$->symbol = Insert($$->name, $$->my_data_type, SYM_SCALAR, LEVEL+1, 1, OFFSET);
                             OFFSET++;
		             } // Param includes Type specifier and ID
        | Type_Specifier T_ID '[' ']'  {if(Search($2,LEVEL+1, 0) != NULL){
                                        yyerror($2);
                                        yyerror("PARAM ALREADY USED DIEEE");
                                        exit(1);
                                }
                                        $$ = ASTCreateNode(A_PARAM);
			     		$$->name = $2;
		             		$$->my_data_type = $1;
		             		$$->value = 1;
                                        $$->symbol = Insert($$->name, $$->my_data_type, SYM_ARRAY, LEVEL+1, 1, OFFSET);
                                        OFFSET++;
		             		} // or Type specifier, ID, and empty square brackets
        ; 
        
Compound_Stmt    : '{' {LEVEL++;} Local_Declarations Statement_List '}'
		 {$$ = ASTCreateNode(A_COMPOUND);
		 $$->s1 = $3;
		 $$->s2 = $4;
                 if(mydebug == 1)
                 {
                        Display();
                 }
                 if(OFFSET > MAXOFFSET) MAXOFFSET = OFFSET ;
                 OFFSET -= Delete(LEVEL);
                 
                 LEVEL--;}// Compound Statement includes local declarations and statement list
                 
        ;
        
Local_Declarations : /*empty*/ {$$ = NULL;}
           | Var_Declaration Local_Declarations
           	{$$ = $1;
           	$$->next = $2;
           	}  // Local Declarations can be empty or a series of Var_Declarations   
           ;

Statement_List    : /*empty*/ {$$ = NULL;}
        | Statement Statement_List
        	{$$ = $1;
           	$$->next = $2;
           	} // Statement_List can be empty or a series of Statements
        ;
        
Statement    : Expression_Stmt {$$ = $1;}
        | Compound_Stmt {$$ = $1;}
        | Selection_Stmt {$$ = $1;}
        | Iteration_Stmt {$$ = $1;}
        | Assignment_Stmt {$$ = $1;}
        | Return_Stmt {$$ = $1;}
        | Read_Stmt {$$ = $1;}
        | Write_Stmt {$$ = $1;}
        ; // Statement can be any one of these types of statements
        
Expression_Stmt    : Expression ';'  // Expression statement ends with a semicolon
                                    {
                                     $$ = ASTCreateNode(A_EXPRSTMT);
                                     $$->s1 = $1;
                                    }
                                       
        | ';'
                                    {
                                     $$ = ASTCreateNode(A_EXPRSTMT);
                                    }
                                      
        ; // It can be an expression followed by a semicolon or just a semicolon
        
Selection_Stmt  : T_IF '(' Expression ')' Statement  // Selection statement starts with 'if' followed by expression and statement
                {$$ = ASTCreateNode(A_SLCT);
                 $$->s1 = $3;
                 $$->s2 = ASTCreateNode(A_SLCTBODY);
                 $$->s2->s1 = $5;}
        | T_IF '(' Expression ')' Statement T_ELSE Statement // or 'if' expression statement 'else' statement
                {$$ = ASTCreateNode(A_SLCT);
                 $$->s1 = $3;
                 $$->s2 = ASTCreateNode(A_SLCTBODY);
                 $$->s2->s1 = $5;
                 $$->s2->s2 = $7;}
        ;
        
Iteration_Stmt    : T_WHILE '(' Expression ')' Statement // Iteration statement starts with 'while' followed by expression and statement
                        {$$ = ASTCreateNode(A_WHILE);
                         $$->s1 = $3;
                         $$->s2 = $5;}
        ;
        
Return_Stmt    : T_RETURN ';' // Return statement ends with a semicolon
                {$$ = ASTCreateNode(A_RETURN);}
        | T_RETURN Expression ';' // or 'return' followed by expression and semicolon
                {$$ = ASTCreateNode(A_RETURN);
                 $$->s1 = $2;}
        ;
        
Read_Stmt    : T_READ Var ';' // Read statement starts with 'read' followed by variable and semicolon
                {$$ = ASTCreateNode(A_READ);
                 $$->s1 = $2;}
                        
        ;
        
Write_Stmt    : T_WRITE Expression';' 
        	{$$ = ASTCreateNode(A_WRITE);
		$$->s1 = $2;
		}
        	|  T_WRITE T_STRING  ';' {
			$$ = ASTCreateNode(A_WRITE);
			$$->name = $2;
			} 
        	;
         
Assignment_Stmt    : Var '=' Simple_Expression ';' // Assignment statement includes variable, '=', simple expression, and semicolon
                { if($1->my_data_type != $3->my_data_type){
                        yyerror("TYPE MISMATCH DIEEEE");
                        exit(1);
                }
                $$ = ASTCreateNode(A_ASSIGN);
                $$->s1 = $1;
                $$->s2 = $3;
                $$->name = CreateTemp();
                $$->symbol = Insert($$->name, $1->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                OFFSET++;}
        ; 

Var        : T_ID   // Var can be a single ID
                {struct SymbTab *p;
                p = Search($1, LEVEL, 1);
                if(p == NULL){
                        yyerror($1);
                        yyerror("NOT DEFINED VAR DIEEEEE");
                        exit(1);
                }
                if(p->SubType != SYM_SCALAR){
                        yyerror($1);
                        yyerror("NOT SCALAR DIEEEEE");
                        exit(1);
                }
                 $$ = ASTCreateNode(A_VAR);
                 $$->name = $1;
                 $$->symbol = p;
                 $$->my_data_type = p->Declared_Type;
                 }

        | T_ID '[' Expression ']'   // or an ID with an expression inside square brackets
                 {struct SymbTab *p;
                p = Search($1, LEVEL, 1);
                if(p == NULL){
                        yyerror($1);
                        yyerror("NOT DEFINED ARRAY DIEEEEE");
                        exit(1);
                }
                if(p->SubType != SYM_ARRAY){
                        yyerror($1);
                        yyerror("NOT SYM_ARRAY DIEEEEE ");
                        exit(1);
                }
                        
                 $$ = ASTCreateNode(A_VAR);
                 $$->name = $1;
                 $$->s1 = $3;
                 $$->symbol = p;
                 $$->my_data_type = p->Declared_Type;
                 
                  }
                 
        ;

Expression    : Simple_Expression {$$ = $1;
                } // Expression can be a simple expression
        ;
        
Simple_Expression : Additive_Expression {$$ = $1;} // Simple Expression can be an Additive Expression
          | Additive_Expression Relop Additive_Expression  // or Additive Expression followed by Relop and another Additive Expression
                {$$ = ASTCreateNode(A_EXPR);
                 $$->s1 = $1;
                 $$->operator = $2;
                 $$->s2 = $3;
                 $$->name = CreateTemp();
                 $$->symbol = Insert($$->name, $1->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;
                 }
          ;
          
Relop   : T_LE {$$ = A_LE;}
        | T_LT {$$ = A_LT;}
        | T_GT {$$ = A_GT;}
        | T_GE {$$ = A_GE;}
        | T_EQ {$$ = A_EQ;}
        | T_NE {$$ = A_NE;}
        ; // Relational operators
        
Additive_Expression : Term {$$ = $1;}// Additive Expression can be a Term
            | Additive_Expression Addop Term  // or Additive Expression followed by Addop and another Term

                {if($1->my_data_type != $3->my_data_type){
                        yyerror("TYPE MISMATCH DIEEEEE");
                        exit(1);
                }
                 $$ = ASTCreateNode(A_EXPR);
                 $$->s1 = $1;
                 $$->operator = $2;
                 $$->name = CreateTemp();
                 $$->symbol = Insert($$->name, $1->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;
                 $$->s2 = $3;}
            ;
            
Addop: '+' {$$ = A_PLUS;} // Addition operator
        | '-'{$$ = A_MINUS;} // Subtraction operator
        ;
        
Term: Factor {$$ = $1;}// Term can be a Factor
        | Term Multop Factor  // or Term followed by Multop and Factor
                {$$ = ASTCreateNode(A_EXPR);
                 $$->s1 = $1;
                 $$->operator = $2;
                 $$->s2 = $3;
                 $$->my_data_type = $1->my_data_type;
                 $$->name = CreateTemp();
                 $$->symbol = Insert($$->name, $1->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;
                 
                }
        ;
        
Multop: '*' {$$ = A_TIMES;} // Multiplication operator
        | '/' {$$ = A_DIVIDE;} // Division operator
        | '%' {$$ = A_MODULUS;}
        ;
        
Factor: '(' Expression ')' {$$ = $2;} // Factor can be an expression inside parentheses
        | T_NUM { $$ =ASTCreateNode(A_NUM);
        	$$ -> value = $1;
                $$->my_data_type = A_INTTYPE;
        	} // or a number
        | Var {$$ = $1;} // or a variable
        | Call {$$ = $1;} // or a function call
        | '-' Factor  // or negation of a Factor
                {$$ = ASTCreateNode(A_EXPR);
		$$->s1 = $2;
		$$->operator = A_UNARYMINUS;
                $$->my_data_type = $2->my_data_type;
                 $$->name = CreateTemp();
                 $$->symbol = Insert($$->name, $2->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;
                }
        ;
        
Call: T_ID '(' Args ')'   // Function Call includes function name, arguments, and parentheses
                {
                struct SymbTab *p;
                p = Search($1, 0, 0);
                if( p == NULL){
                        yyerror($1);
                        yyerror("FUN NAME NOT DEFINED DIEEEE");
                        exit(1);
                }

                if(checkParams($3, p->fparms) == 0){
                        yyerror($1);
                        yyerror("ACTUAL DONT MATCH FORMAL DIEEEEE");
                        exit(1);
                }
		$$ = ASTCreateNode(A_CALL);
		$$->name = $1;
		$$->s1 = $3;
                $$->symbol = p;
                
                
		}
        ;

Args: Arg_List // Arguments can be a list of expressions
                {
                $$ = $1;
                }
        | /*empty*/ {$$ = NULL;} // or empty
        ;
    
Arg_List: Expression // Argument list includes an expression
                {$$ = ASTCreateNode(A_ARG);
                $$->s1 = $1;
                $$->my_data_type = $1->my_data_type;
                $$->name = CreateTemp();
                 $$->symbol = Insert($$->name, $1->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;}
        | Expression ',' Arg_List // or expression followed by comma and another argument list
                {$$ = ASTCreateNode(A_ARG);
                $$->s1 = $1;
                $$->next = $3;
                $$->my_data_type = $1->my_data_type;
                 $$->name = CreateTemp();
                 $$->symbol = Insert($$->name, $1->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;}
        ;
%%  /* end of rules, start of program */
/* added return type int to resolve warning */
/* main calls yyparse */
int main(int argc, char *argv[])
{ 
        FILE *fp;
        char s[100];
        for(int i = 0; i< argc; i++ )// it loops for all the arguments in the command
        {
                if(strcmp(argv[i],"-d") == 0) // if we have -d we turn on debug
                {
                        mydebug = 1;
                }

                if(strcmp(argv[i], "-o") == 0) // if we have -o write to the asm file
                {
                        strcpy(s, argv[i+1]);
                        strcat(s, ".asm");
                        
                }

                       
        }
        fp = fopen(s, "w");
        if(fp == NULL) // error no file given
        {
                printf("Cannot open file %s \n", s);
                exit(1);
        }
        yyparse();
        if(mydebug == 1) // if debug on print this our
        {
                printf("\nFinished Parsing\n\n\n");
        }
        if(mydebug == 1)// run display function if debug on
        {
                Display();
        }

        if(mydebug == 1)// print this if debug on
        {
                printf("\nAST PRINT\n\n\n");
                
        }
         if(mydebug == 1) // run AST function if debug equals true
        {
                ASTprint(0,PROGRAM);
        }
        EMIT(PROGRAM, fp);
        fclose(fp);
    
} 


