/*
    Owen Ramsey
    lab 9
    spring 370
    5/3/2024
*/
/*
Description:
This is a Lex specification file for a simple compiler.
It tokenizes input text according to predefined rules, returning
tokens such as keywords, identifiers, numbers, and symbols.
It also handles whitespace, comments, and string literals.
*/



%{
// Initialize line count and debug flag
int lineCount = 1;
int mydebug=0;
#include "ast.h"
#include "y.tab.h"

%}

%%

"write"		{return(T_WRITE);} // Return token for 'write'
"string"	{return(T_STRING);} // Return token for 'string'
"return"	{return(T_RETURN);} // Return token for 'return'
"while"		{return(T_WHILE);} // Return token for 'while'
"if"		{return(T_IF);} // Return token for 'if'
"else"		{return(T_ELSE);} // Return token for 'else'
"void"		{return(T_VOID);} // Return token for 'void'
"int"		{return (T_INT);} // Return token for 'int'
"read"		{return(T_READ);} // Return token for 'read'
">"		{return(T_GT);} // Return token for '>'
"<"		{return(T_LT);} // Return token for '<'
">="		{return(T_GE);} // Return token for '>='
"<="		{return(T_LE);} // Return token for '<='
"=="		{return(T_EQ);} // Return token for '=='
"!="		{return(T_NE);} // Return token for '!='

[a-zA-Z][a-zA-Z0-9]*		{ // Match letter followed by alphanumeric characters
                           if (mydebug) fprintf(stderr,"Letter found\n"); 
                           yylval.string=strdup(yytext);
                           return(T_ID);
                        }

[0-9][0-9]*	{ // Match integer
               if (mydebug) fprintf(stderr,"Digit found\n"); 
               yylval.value=atoi((const char *)yytext); 
               return(T_NUM);
             }
 
\"[^\"]*\"     { // Match string literal
                   if (mydebug) fprintf(stderr,"String literal found\n");
                   yylval.string = strdup(yytext + 1); // Skip the opening quote
                   yylval.string[strlen(yylval.string) - 1] = '\0'; // Replace the closing quote with null termi
                   return T_STRING;
                }
                       
[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");} // Ignore whitespace
[(=;\-+%*/&|),\]\[{}] 	{ // Match various symbols
                           if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
                           return (*yytext);
                         }
[/][/](.)*\n	| // Match comments until end of line
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext); 
                       lineCount++;
                     } // Increment line count for newline

%%

int yywrap(void)
{ 
    return 1; // End of file
}

