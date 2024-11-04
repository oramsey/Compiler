/*
Owen Ramsey
Lab9
5/3/24
*/

/*
this is CMINUS code

emit.c is used to write MIPS code to a .asm file
traverses the syntax tree using EMIT_AST
it uses multiple functions that represent different ASTnode types
like A_EXPR and A_VAR

*/

#include "ast.h"
#include "emit.h"
#include <string.h>
#include <stdlib.h>

/*emit is a void function that writes a always writes a command
 but may also write a label and comment it outputs this tis
 string into our .asm file to write the machine code*/
//PRE: takes string for, label, command, and comment and valid pointer to file
//POST: MIPS code line is outputted into the .asm file
void emit(FILE *fp, char *label, char *command, char *comment)
{
    if(strcmp("", comment) == 0) // don't print comment if no comment
    {
        if(strcmp("", label)==0) // don't print label either
        {
            fprintf(fp, "\t%s\t\t\n", command);
        } // end of if

        else // print label and command
        {
            fprintf(fp, "%s:\t%s\t\t\n", label, command);
        } // end of else

    } // end of if

    else // else print comment
    {
        if(strcmp("", label)==0) // print command and comment
        {
             fprintf(fp, "\t%s\t\t# %s\n", command, comment);
        } // end of if
        else // print label command and comment
        {
            fprintf(fp, "%s:\t%s\t\t# %s\n", label, command, comment);
        } // end of else
    } // end of else
} //end of emit

/*prints out the start of the the MIPS code 
then calls EMIT_STRINGS and EMIT_AST*/
//PRE: valid pointers to ASTnode and FILE
//POST: prints out the the mips code for the AST
void EMIT(ASTnode* p, FILE *fp)
{
    if(p == NULL) // if ast NULL return nothing
    {
        return;
    } // end of if

    if(fp == NULL) // if file NULL return nothing
    {
        return;
    } // end of if

    fprintf(fp, "# MIPS CODE GENERATED BY CS370\n\n");
    fprintf(fp, ".data\n\n");
    EMIT_STRINGS(p, fp);
    fprintf(fp, ".align 2\n");
    EMIT_GLOBALS(p, fp);
    fprintf(fp, ".text\n\n\n") ;
    fprintf(fp, ".globl main\n\n");
    EMIT_AST(p,fp);
} // end of EMIT

/*void function that outputs the global varibles
 into the .data section of our mips code*/
//PRE:valid pointers to ASTnode and FILE
//POST:writes mips code of global varibles into FILE
void EMIT_GLOBALS(ASTnode *p, FILE *fp)
{
    if(p != NULL) // run the the code if P is not NULL
    {
        if(p->type == A_VARDEC && p->symbol->level == 0) // if the code is global varible fprintf to file
        {
        fprintf(fp,"%s: .space %d # global variable \n", p->symbol->name, p->symbol->mysize * WSIZE);
        }
        EMIT_GLOBALS(p->next, fp);
        EMIT_GLOBALS(p->s1, fp);
    } // end of if
} // end of EMIT_GLOBALS

/*prints out the machine code labels into the .data section of the code*/
//PRE:valid pointer to ASTnode and FILE
//POST: writes labels in the beginning of the machine code
void EMIT_STRINGS(ASTnode *p, FILE *fp)
{
    if(p!= NULL) // run code if p is not NULL
    {
        if(p->type == A_WRITE && p->name != NULL) // if the type is a write and it's printing out a string create label
        {
            p->label = CreateLabel();
            fprintf(fp, "%s: .asciiz \t \"%s\"  # string\n", p->label, p->name);
        }
       
        
        EMIT_STRINGS(p->next, fp);
        EMIT_STRINGS(p->s1, fp);
        EMIT_STRINGS(p->s2, fp);
    } // end of if
} // end of EMIT_STRINGS

/*places value into $a0 then jump returns to the function call
 if return is in main break so we dint get error*/
//PRE:valid pointer to ASTnode and FILE
//POST: places value into $a0 in mips code
void emit_return(ASTnode *p, FILE *fp)
{
    char s [100];
    emit(fp,"", "li $a0, 0", "return has no expression");
    if(p->s1 != NULL)
    {
        emit_expression(p->s1, fp);
    } // end of if
        emit(fp, "", "lw $ra ($sp)", "Restore old ebviorment RA");
        sprintf(s, "lw $sp %d($sp)", WSIZE);
        emit(fp, "", s, "return from function store SP");
        p->label = CreateLabel();
        sprintf(s, "beq $ra, $0, %s", p->label);
        emit(fp, "", s, "Break if return is in main");
        emit(fp, "", "jr $ra", "return to call");
        emit(fp, p->label, "", "EXIT main");
        fprintf(fp, "\n");

} // end of emit_return

/*stores the value of the RHS then loads it into $a1 the stores it into the variable*/
//PRE:valid pointer to ASTnode and FILE
//POST: writes mips code to store RHS variable into LHS variable
void emit_assign(ASTnode *p, FILE *fp)
{
    char s[100];
    emit_expression(p->s2, fp);
    sprintf(s, "sw $a0, %d($sp)", p->symbol->offset * WSIZE);
    emit(fp, "", s, "Store assignment in RHS");
    emit_var(p->s1, fp);
    sprintf(s, "lw $a1, %d($sp)",  p->symbol->offset * WSIZE);
    emit(fp, "", s, "get assignment in RHS");
    emit(fp, "", "sw $a1, ($a0)", "Assign expression to var");
    fprintf(fp, "\n");
} // end of emit_assign

/*open $v0 with li 5 and syscall the store it into memory*/
//PRE:valid pointer to ASTnode and FILE
//POST: writes mips code to stores user input into vaiable 
void emit_read(ASTnode *p, FILE *fp)
{
    emit_var(p->s1, fp);
    emit(fp, "", "li $v0, 5", "About to read in value");
    emit(fp, "", "syscall", "read in value $v0 now has readin value");
    emit(fp, "", "sw $v0, ($a0)", "store read in value to memory");
    fprintf(fp, "\n");
} // end of emit_read

/*writes mips code to access declared variable*/
//PRE:valid pointer to ASTnode and FILE
//POST: writes mips code to return var
void emit_var(ASTnode *p, FILE *fp)
{
    char s[100];
    
    if(p->s1 != NULL) // if the var is an array emit_expression for the array and shift logical left to get the offset
    {
        emit_expression(p->s1, fp);
        sprintf(s, "sll $a1 $a0, %d", LOGWSIZE);
        emit(fp, "", s, "get offset for element in array");
       
    } // end of if
    if(p->symbol->level == 0) // check if the var is a global variable and print it with Emit var global variable
    {
        sprintf(s, "la $a0 %s", p->name);
        emit(fp, "", s, "EMIT var global varible");
    } // end of if
    else // not a global variable get address for it
    {
        emit(fp, "", "move $a0, $sp", "Store a copy of SP");
        sprintf(s, "add $a0, $a0, %d", p->symbol->offset*WSIZE);
        emit(fp, "", s, "add SP and offset for variable address");
    } // end of else
    if(p->s1 != NULL) // add additonal offset for array
    {
        emit(fp, "", "add $a0, $a0, $a1", "add the additonal offset");
    } // end of if  
}// end of var

/*writes mips code to  for the mips code for function definitions
 and checks if the function is main or not and exits if it is main*/
//PRE:valid pointer to ASTnode and FILE
//POST: writes mips code for function definition
void emit_function(ASTnode *p, FILE *fp)
{
    char s[100];
    emit(fp,p->name, "", "function definition");
    emit(fp, "", "move $a1, $sp", "Activation Record carve out copy of function");
    sprintf(s, "subi $a1, $a1, %d", p->symbol->offset * WSIZE);
    emit(fp, "", s, "Activation Record carve out copy of function");
    emit(fp, "", "sw $ra, ($a1)", "Store return address");
    sprintf(s, "sw $sp %d($a1)",  WSIZE);
    emit(fp, "", s, "store the old stack pointer");
    emit(fp, "", "move $sp, $a1", "make SP the currenr activaton record");
    fprintf(fp, "\n");

    emit_param(p->s1, fp, 0);

    emit(fp,"", "li $a0, 0", "Return is set to 0");

    EMIT_AST(p->s2, fp);
    
    emit(fp, "", "lw $ra ($sp)", "Restore old ebviorment RA");
    sprintf(s, "lw $sp %d($sp)", WSIZE);
    emit(fp, "", s, "return from function store SP");
    fprintf(fp, "\n");

    if(strcmp(p->name, "main") == 0) // if function name is main go through it and once over exit program
    {
        emit(fp, "", "li $v0, 10", "Exit from main, we are done");
        emit(fp, "", "syscall", "exit everything");
       
    } // end of if
    else // return to where function call was
    {
        emit(fp, "", "jr $ra", "Return to caller");
    } // end of else
    
} // end of function

/*writes the mips code to execute a write statement
  either a string or an expression*/
//PRE:valid pointer to ASTnode and FILE
//POST:writes the mips code to execute a write statement
void  emit_write(ASTnode *p, FILE *fp)
{
    char s[100];
    if(p->name != NULL) // going to print out string from the write
    {
        sprintf(s, "la $a0, %s", p->label);
        emit(fp, "", s, "the string address");
        emit(fp, "", "li $v0, 4", "About to print a string");
        emit(fp, "", "syscall",  "Call write string");
        fprintf(fp, "\n");
    }
    else //going to print out an expression from the write
    {
        emit_expression(p->s1, fp);
        emit(fp, "", "li $v0, 1", "About to print a number");
        emit(fp, "", "syscall", "Call write a number");
        fprintf(fp, "\n");
    }
} // end of write

/*uses jumps and labels in mips code to recreate a normal while loop*/
//PRE:valid pointer to ASTnode and FILE
//POST:writes th mips code to create a while loop
void emit_while(ASTnode *p, FILE *fp)
{
    char s [100];
    char t [100];
    p->label = CreateLabel();
    emit(fp, p->label, "", "while loop label");
    emit_expression(p->s1, fp);
    sprintf(t, "%s", CreateLabel());
    sprintf(s, "beq $0, $a0 %s", t);
    emit(fp, "", s, "Branch out if false");
    fprintf(fp,"\n");
    EMIT_AST(p->s2, fp);
    sprintf(s, "j %s", p->label);
    emit(fp, "", s, "LOOP");
    emit(fp, t, "", "NO LOOP");
    fprintf(fp,"\n");
}//end of emit_while

/*writes mips code to execute expression with operators and comparison operators
  or the expression is a var or a number or a call*/
//PRE:valid pointer to ASTnode and FILE
//POST: writes mips code to store the result of an expression to $a0
void emit_expression(ASTnode *p, FILE *fp)
{
    char s[100];
    switch(p->type) // start of switch
    {
        case A_NUM:
        sprintf(s, "li $a0, %d", p->value);
        emit(fp, "", s, "expression is constant");
        return;
        break;

        case A_EXPR:
        if(p->s2 != NULL) // there is a right side store it temporairly
        {
            emit_expression(p->s2, fp);
            sprintf(s, "sw $a0, %d($sp)", p->symbol->offset * WSIZE);
            emit(fp, "", s, "Store expr's RHS temporairly");
            emit_expression(p->s1, fp); 
            sprintf(s, "lw $a1, %d($sp)", p->symbol->offset * WSIZE);
            emit(fp, "", s, "Store expr's RHS temporairly");
        } // end of if

        else // unary minus
        {
            emit_expression(p->s1, fp);
        } // end of else

        switch(p->operator) // start of switch for operators
        {
            case A_PLUS: // addition
            emit(fp, "", "add $a0, $a0, $a1", "Plus operator");
            break;

            case A_MINUS: //subtraction
            emit(fp, "", "subu $a0, $a0, $a1", "Minus operator");
            break;

            case A_TIMES: //multiplication
            emit(fp, "", "mul $a0, $a0, $a1", "Times operator");
            emit(fp, "", "mflo $a0", "low operator");
            break;

            case A_DIVIDE: //division
            emit(fp, "", "divu $a0, $a0, $a1", "divide operator");
            emit(fp, "", "mflo $a0", "low operator");
            break;

            case A_MODULUS: // remainder
            emit(fp, "", "divu $a0, $a0, $a1", "divide operator");
            emit(fp, "", "mfhi $a0", "get remainder");
            break;

            case A_UNARYMINUS: //negative number
            emit(fp, "", "subu $a0, $a0, $a1", "unary-minus operator");
            break;

            case A_LT: //less than
            emit(fp, "", "slt $a0, $a0, $a1", "less than operator");
            break;

            case A_GT: // greater than
            emit(fp, "", "slt $a0, $a1, $a0", "greater than operator");
            break;

            case A_LE: // less than or equal to
            emit(fp, "", "addi $a1, $a1, 1", "offset RHS by 1");
            emit(fp, "", "slt $a0, $a0, $a1", "less than or equal operator");
            break;

            case A_GE: // greater than or equal to
            emit(fp, "", "addi $a0, $a0, 1", "offset LHS by 1");
            emit(fp, "", "slt $a0, $a1, $a0", "greater than or equal operator");
            break;

            case A_EQ: // equal to
            emit(fp, "", "seq $a0, $a0, $a1", "equals operator");
            break;

            case A_NE: // not equal to
            emit(fp, "", "seq $a0, $a0, $a1", "equals operator UNLESS");
            emit(fp, "", "xori $a0, $a0, 1", "NOT EQUALS operator");
            break;

            default: // operator not found
            printf("OPERATOR NOT RECOGNIZED DIEEEEE");
            exit(1);
        } //end of operator switch
        fprintf(fp, "\n");
        break;

        case A_VAR: // the expression is a var
        emit_var(p, fp);
        emit(fp, "", "lw $a0, ($a0)", "Expression is a Var");
        return;
        break;

        case A_CALL: // the expression is a call
        emit_call(p,fp);
        break;


        default:
        printf("AHHHH EMIT_EXPRESSIOM NOT WORKING RIGHT AHHHHHHH");
        exit(1);
    } // end of switch
}  // end of emit_expression

/*checks if there is an else body then checks if we can fufill the if expression
 if not go to OUT label or else*/
//PRE: valid pointer to ASTnode and FILE
//POST: writes mips code to make if or else statement 
void emit_slct(ASTnode *p, FILE *fp)
{
    char s [100];
    p->label = CreateLabel();
    emit_expression(p->s1, fp);
    if(p->s2->s2 == NULL)// no else so go to OUT label or to if body
    {
        sprintf(s, "beq $0, $a0 %s", p->label);
        emit(fp, "", s, "if false go out");
        fprintf(fp,"\n");
        EMIT_AST(p->s2->s1, fp);
        emit(fp,p->label, "", "Out label");
    } // end of if
    else // there is an else go to if body or else body or OUT label
    {
        char t [100];
        sprintf(t, "%s", CreateLabel());
        sprintf(s, "beq $0, $a0 %s", t);
        emit(fp, "", s, "if false go to else");
        fprintf(fp,"\n");
        EMIT_AST(p->s2->s1, fp);
        sprintf(s, "j %s", p->label);
        emit(fp, "", s, "jump to out after IF");
        fprintf(fp,"\n");
        emit(fp, t, "", "else");
        EMIT_AST(p->s2->s2, fp);
        emit(fp,p->label, "", "Out label");

    } // end of else
        

} 

/*writes mips code to create formals for function definitions */
//PRE: valid pointer to ASTnode and FILE and an int that should alwasy be 0
//POST: makes space in the SP for param
void emit_param(ASTnode *p, FILE *fp, int count)
{
    char s [100];
    if(p == NULL) // nothing
    {
        return;
    }// end of if
    if(count > 7 ) // there are more than 8 params there shouldn't be
    {
        printf("only 8 params");
        exit(1);
        return;
    } //end of
    
    sprintf(s, "sw $t%d, %d($sp)", count, p->symbol->offset * WSIZE);
    emit(fp, "", s, "loads formal");
    emit_param(p->next, fp, count+1);

} // end of emit_param 

/*stores args into t registers*/
//PRE: valid pointer to ASTnode and FILE and an int that should alwasy be 0
//POST: writes mips code to put arguments into t registers
void emit_args(ASTnode *p, FILE *fp, int count)
{

    char s [100];
    if(p == NULL)
    {
        return;
    }
    if(count > 7 )
    {
        printf("only 8 params");
        exit(1);
        return;
    }
    
    emit_expression(p->s1, fp);
    sprintf(s, "sw $a0, %d($sp)",  p->symbol->offset * WSIZE);
    emit(fp, "", s, "store call args");
    sprintf(s, "lw $t%d %d($sp)", count, p->symbol->offset * WSIZE);
    emit(fp, "", s, "get the stored arg");
    emit_args(p->next, fp, count+1);
}

/*writes mips code to jump to label and puts args into t registers */
//PRE: valid pointer to ASTnode and FILE
//POST: writes mips code to jump to a label
void emit_call(ASTnode *p, FILE *fp)
{
    char s [100];
    if(p->s1 == NULL) // function call has no args
    {
        sprintf(s, "jal %s", p->name);
        emit(fp, "", s, "jump to function label no args");
    } // end of if
    else // has args so call emit_args
    {
        emit_args(p->s1, fp, 0);

        sprintf(s, "jal %s", p->name);
        emit(fp, "", s, "jump to function label args");
    } // end of else
} // end of emit_call

/*Uses a switch statement to call other emit functions to make the correct MIPS code for our program*/
//PRE: valid pointer to ASTnode and FILE
//POST: calls all other emit functions to write their mips code
void EMIT_AST(ASTnode *p, FILE *fp)
{
    if(p==NULL) // return nothing if AST is NULL
    {
        return;
    }
switch(p->type) // Start of switch statement based on AST node type
{
    case A_VARDEC: // If node type is variable declaration
        // Emit AST for next node in sequence
        EMIT_AST(p->next, fp);
        break;

    case A_FUNCTIONDEC: // If node type is function declaration
        // Emit function code
        emit_function(p, fp);
        // Emit AST for next node in sequence
        EMIT_AST(p->next, fp);
        break;

    case A_COMPOUND: // If node type is compound statement
        // Emit AST for statement list
        EMIT_AST(p->s2, fp);
        // Emit AST for next node in sequence
        EMIT_AST(p->next, fp);
        break;

    case A_WRITE: // If node type is write statement
        // Emit code for write statement
        emit_write(p, fp);
        // Emit AST for next node in sequence
        EMIT_AST(p->next, fp);
        break;

    case A_READ: // If node type is read statement
        // Emit code for read statement
        emit_read(p, fp);
        // Emit AST for next node in sequence
        EMIT_AST(p->next, fp);
        break;

    case A_VAR: // If node type is variable
        // Emit code for variable access
        emit_var(p, fp);
        // Emit load word instruction
        emit(fp, "", "lw $a0, ($a0)", "expression is a var");
        break;

    case A_ASSIGN: // If node type is assignment statement
        // Emit code for assignment statement
        emit_assign(p, fp);
        // Emit AST for next node in sequence
        EMIT_AST(p->next, fp);
        break;

    case A_WHILE: // If node type is while loop
        // Emit code for while loop
        emit_while(p, fp);
        // Emit AST for next node in sequence
        EMIT_AST(p->next, fp);
        break;

    case A_SLCT: // If node type is selection statement (if-else)
        // Emit code for selection statement
        emit_slct(p, fp);
        // Emit AST for next node in sequence
        EMIT_AST(p->next, fp);
        break;

    case A_EXPRSTMT: // If node type is expression statement
        // Emit code for expression statement
        emit_expression(p->s1, fp);
        // Emit AST for next node in sequence
        EMIT_AST(p->next, fp);
        break;

    case A_RETURN: // If node type is return statement
        // Emit code for return statement
        emit_return(p, fp);
        break;

    default:
        // Print error message for unimplemented node type
        printf("AHHHH EMIT_AST NOT WORKING RIGHT AHHHHHHH %d not implemented\n", p->type);
        // Exit program with error code
        exit(1);
} // End of switch statement

} //end of EMIT_AST