/*
  Owen Ramsey
  lab9
  5/3/24
*/

/*
  lab9:
    this is CMINUS code
     that is used to define an Abstract Syntax Tree nodes
    we used global varible GLABEL in the function createLabel which creates labels
    for emit.c we have a check params function to make sure actuals and formals match
    we use level and offset we have cases for each node type and we can print the level and 
    offset of each node type that is in test code we are using with ast.c
*/



/*
  lab7:
    this is cminus code
    added check params to make sure actuals and formals matched
    updated some print statements to include the the level and offset value
    updated print statements are in A_VARDEC A_FUNDEC A_PARAM A_VAR

*/


#include<stdio.h>
#include<malloc.h>
#include "ast.h" 
#include <string.h>
// global variable to count labels
int GLABEL;
// pre: valid pointers to actuals and formals
// post: confirmation if actuals and formals match
int checkParams(ASTnode *actuals, ASTnode *formals){
  // if they're both NULL they match
 if(actuals == NULL && formals == NULL)return 1;
 // if only one is NULL they don't match
 if(actuals == NULL || formals == NULL) return 0;
 // if types don't match they don't match
 if(actuals->my_data_type != formals->my_data_type)return 0;
 return  checkParams(actuals->next, formals->next);


 
}

/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
//  PRE:  Ast Node Type
//  POST:   PTR To heap memory and ASTnode set and all other pointers set to NULL
ASTnode *ASTCreateNode(enum ASTtype mytype)

{
    ASTnode *p;
    // if debug is on throw this error
    if (mydebug) fprintf(stderr,"Creating AST Node \n");
    p=(ASTnode *)malloc(sizeof(ASTnode));
    p->type=mytype;
    p->s1=NULL;
    p->s2=NULL;
    p->next=NULL;
    p->value=0;
    return(p);
}

/*  Helper function to print tabbing */
//PRE:  Number of spaces desired
//POST:  Number of spaces printed on standard output

void PT(int howmany)
{
   // make "howmany" number of spaces
	 while (howmany > 0) {
		printf(" ");
		howmany--;
	}
}

//  PRE:  A declaration type
//  POST:  A character string that is the name of the type
//          Typically used in formatted printing
char * ASTtypeToString(enum AST_MY_DATA_TYPE mytype)
{
  // return int or void depending on the case
switch(mytype)
{
  case A_INTTYPE:
    return("INT");
  case A_VOIDTYPE:
    return("VOID");
  default:
    printf("BARGGG ERROR ERROR ERROR");
}
}


/*creates a label for the machine code that you can use for branches and jumps.*/
// PRE: GLABEL is properly intialized 
// POST: creates a label in mips code
char * CreateLabel()
{    char hold[100];
     char *s;
     sprintf(hold,"_l%d",GLABEL++);
     s=strdup(hold);
     return (s);

}
/*  Print out the abstract syntax tree */
// PRE:   PRT to an ASTtree
// POST:  indented output using AST order printing with indentation

void ASTprint(int level,ASTnode *p)
{
   int i;
   // if ASTnode is null return nothing
   if (p == NULL ) return;
   else
     { 
       switch (p->type) {
        case A_VARDEC : 
          PT(level); 
          
          // if value is not 0 it's an array
          if(p->value != 0){
            printf("Variable %s %s level %d offset %d [%d] \n", ASTtypeToString(p->my_data_type), p->name, p->symbol->level,p->symbol->offset, p->value);
          }
          // not an array
          else{
           printf("Variable %s %s level %d offset %d \n", ASTtypeToString(p->my_data_type), p->name, p->symbol->level,p->symbol->offset);
          }
         
          
          ASTprint(level, p->s1);
          ASTprint(level, p->next);
          break;

        case A_FUNCTIONDEC :  
          PT(level); printf("Function %s %s level %d offset %d \n", ASTtypeToString(p->my_data_type), p->name, p->symbol->level,p->symbol->offset);
          ASTprint(level + 1 , p->s1); // params
          ASTprint(level + 1, p->s2); // statement list
          ASTprint(level, p->next);
          break;
                     
        case A_COMPOUND :
        	PT(level); printf("Compound Statement \n");
        	ASTprint(level + 1 , p->s1); // local decs
          ASTprint(level + 1, p->s2); // statement list
          ASTprint(level, p->next);
        	break;
        	
        case A_WRITE :
        	PT(level);
          // Write is writing a string
        	if(p->name != NULL)
          {
        	  printf("Write String %s\n", p->name);
        	}
        	else // it is an expression
        	{
        	  printf("Write Expression\n");
        	  ASTprint(level + 1, p->s1);
        	}
        	ASTprint(level, p->next);
        	break;
        	 
        case A_NUM :
        	PT(level);
        	printf("NUMBER value %d \n", p->value);
        	break;
        	 
        case A_PARAM :
        	PT(level);
         
          // the param is an array so the output will have brackets
        	if(p->value != 0){
        	  printf("Parameter %s %s[] level %d offset %d \n", ASTtypeToString(p->my_data_type), p->name, p->symbol->level,p->symbol->offset);
        	}
          // output is not an array
        	else{
        	  printf("Parameter %s %s level %d offset %d \n", ASTtypeToString(p->my_data_type), p->name, p->symbol->level,p->symbol->offset);
        	}
        	ASTprint(level, p->next);
        	break;

        case A_EXPR :
          PT(level);
          printf("EXPRESSION operator ");
			    // choose operator
          switch (p->operator) {
            case A_PLUS :printf("PLUS\n");break;
            case A_MINUS : printf("MINUS\n");break;
            case A_TIMES : printf("TIMES\n");break;
            case A_DIVIDE : printf("/\n");break;
            case A_MODULUS :printf("%\n");break;
            case A_LT :printf("<\n");break;
            case A_LE :printf("<=\n");break;
            case A_GT :printf(">\n");break;
            case A_GE :printf(">=\n");break;
            case A_EQ :printf("==\n");break;
            case A_NE :printf("!=\n");break;
            case A_UNARYMINUS :printf("-\n");break; 
            default: printf("AHHHH DON'T KNOW OPERATOR \n");
          }
          ASTprint(level+1, p->s1);
          ASTprint(level+1, p->s2);
          ASTprint(level, p->next);
          break;

        case A_SLCT:
          PT(level);
          printf("IF STATEMENT\n");
          PT(level+1);
          printf("IF expression\n");
          ASTprint(level+2, p->s1);   
          PT(level+1);
          printf("IF body\n");
          ASTprint(level+2, p->s2->s1);   
          //if there is an else print out "else body" and the actual else body 
          if (p->s2->s2 != NULL) {
            PT(level+1);
            printf("ELSE body\n");
            ASTprint(level+2, p->s2->s2);   
          }
          ASTprint(level, p->next);
          break;

        case A_WHILE:
          PT(level);
          printf("WHILE STATEMENT\n");
          PT(level+1);
          printf("WHILE expression\n");
          ASTprint(level+2, p->s1);  
          PT(level+1);
          printf("WHILE body\n");
          ASTprint(level+2, p->s2);   
          ASTprint(level, p->next);
          break;

        case A_ASSIGN:
          PT(level);
          printf("ASSIGNMENT STATEMENT\n");
          ASTprint(level+1, p->s1);   // variable
          PT(level);
          printf("is assigned\n");
          ASTprint(level+1, p->s2);   // expression
          ASTprint(level, p->next);
          break;

          case A_VAR :
            PT(level);
            printf("Variable %s level %d offset %d \n",  p->name, p->symbol->level,p->symbol->offset);
            // if expression does not equal NULL outut brackets with num or expression
            if (p->s1 != NULL) {
              PT(level+1);
              printf("[\n");
              ASTprint(level+2, p->s1);   
              PT(level+1);
              printf("]\n");			        
              }
              break;

          case A_RETURN :
            PT(level);
            printf("RETURN STATEMENT\n");
            ASTprint(level+1, p->s1);
            ASTprint(level, p->next);
            break;

          case A_READ :
            PT(level);
            printf("READ STATEMENT\n");
            ASTprint(level+1, p->s1);  
            ASTprint(level, p->next);   
            break;

          case A_CALL :
            PT(level);
            printf("CALL STATEMENT function %s\n", p->name);
            PT(level+1);
            printf("(\n");
            ASTprint(level+2, p->s1);   
            PT(level+1);
            printf(")\n");
            break;

          case A_ARG:
            PT(level);
            printf("CALL argument\n");
            ASTprint(level+1, p->s1);   // print arg (A_EXPR)
            ASTprint(level, p->next);   // idk
            break;

          case A_EXPRSTMT:
            PT(level);
            printf("expression statement\n");
            if(p->s1 != NULL)
            {
              ASTprint(level + 1, p->s1);
            }
            ASTprint(level, p->next);
            break;



        default: printf("unknown AST Node type %d in ASTprint\n", p->type);


       }
     }

}



/* dummy main program so I can compile for syntax error independently   
main()
{
}
/* */
