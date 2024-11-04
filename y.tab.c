/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "lab9.y" /* yacc.c:339  */

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



#line 128 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_STRING = 258,
    T_NUM = 259,
    T_ID = 260,
    T_WRITE = 261,
    T_RETURN = 262,
    T_WHILE = 263,
    T_IF = 264,
    T_ELSE = 265,
    T_INT = 266,
    T_VOID = 267,
    T_READ = 268,
    T_GT = 269,
    T_LT = 270,
    T_GE = 271,
    T_LE = 272,
    T_EQ = 273,
    T_NE = 274
  };
#endif
/* Tokens.  */
#define T_STRING 258
#define T_NUM 259
#define T_ID 260
#define T_WRITE 261
#define T_RETURN 262
#define T_WHILE 263
#define T_IF 264
#define T_ELSE 265
#define T_INT 266
#define T_VOID 267
#define T_READ 268
#define T_GT 269
#define T_LT 270
#define T_GE 271
#define T_LE 272
#define T_EQ 273
#define T_NE 274

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 66 "lab9.y" /* yacc.c:355  */

      int value;
      char * string;
      ASTnode *node;	
       enum AST_OPERATORS operator;
      enum AST_MY_DATA_TYPE d_type;

#line 214 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 231 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  127

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   274

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    33,     2,     2,
      24,    25,    31,    29,    23,    30,     2,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    20,
       2,    28,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,    22,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,   100,   101,   107,   108,   112,   138,   141,
     144,   148,   154,   155,   158,   170,   158,   185,   186,   189,
     190,   195,   207,   221,   221,   236,   237,   243,   244,   250,
     251,   252,   253,   254,   255,   256,   257,   260,   266,   273,
     278,   286,   292,   294,   299,   305,   309,   315,   328,   347,
     371,   375,   376,   387,   388,   389,   390,   391,   392,   395,
     396,   411,   412,   415,   416,   429,   430,   431,   434,   435,
     439,   440,   441,   452,   476,   480,   483,   490
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_STRING", "T_NUM", "T_ID", "T_WRITE",
  "T_RETURN", "T_WHILE", "T_IF", "T_ELSE", "T_INT", "T_VOID", "T_READ",
  "T_GT", "T_LT", "T_GE", "T_LE", "T_EQ", "T_NE", "';'", "'['", "']'",
  "','", "'('", "')'", "'{'", "'}'", "'='", "'+'", "'-'", "'*'", "'/'",
  "'%'", "$accept", "Program", "Declaration_List", "Declaration",
  "Var_Declaration", "Var_List", "Type_Specifier", "Fun_Declaration",
  "$@1", "$@2", "Params", "Param_List", "Param", "Compound_Stmt", "$@3",
  "Local_Declarations", "Statement_List", "Statement", "Expression_Stmt",
  "Selection_Stmt", "Iteration_Stmt", "Return_Stmt", "Read_Stmt",
  "Write_Stmt", "Assignment_Stmt", "Var", "Expression",
  "Simple_Expression", "Relop", "Additive_Expression", "Addop", "Term",
  "Multop", "Factor", "Call", "Args", "Arg_List", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      59,    91,    93,    44,    40,    41,   123,   125,    61,    43,
      45,    42,    47,    37
};
# endif

#define YYPACT_NINF -111

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-111)))

#define YYTABLE_NINF -18

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      35,  -111,  -111,    53,  -111,    35,  -111,    13,  -111,  -111,
    -111,    44,    24,    54,    61,    56,  -111,    59,    31,  -111,
      58,    60,    57,    80,    62,  -111,    63,    61,    67,  -111,
      35,  -111,    68,    65,  -111,  -111,  -111,  -111,    35,    35,
      61,    15,  -111,  -111,    19,     1,    12,    69,    70,    84,
    -111,    25,    25,  -111,    71,    15,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,    64,    75,  -111,    45,   -20,  -111,  -111,
      25,    25,    76,  -111,    77,  -111,    79,    25,    25,    81,
      83,    82,  -111,  -111,  -111,    25,  -111,  -111,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,    25,    25,  -111,  -111,  -111,
      25,    78,    85,    86,  -111,  -111,  -111,  -111,    87,    88,
    -111,  -111,    89,    42,   -20,  -111,  -111,    25,  -111,    15,
      15,  -111,  -111,  -111,    91,    15,  -111
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    12,    13,     0,     2,     3,     5,     0,     6,     1,
       4,     8,     0,     0,     0,     0,     7,     0,     8,    10,
       0,     9,    13,     0,     0,    18,    19,     0,    21,    15,
       0,    11,     0,     0,    20,    22,    23,    16,    25,    25,
       0,    27,    26,    69,    48,     0,     0,     0,     0,     0,
      38,     0,     0,    30,     0,    27,    29,    31,    32,    34,
      35,    36,    33,    70,     0,    50,    51,    59,    63,    71,
       0,    75,     0,    70,     0,    42,     0,     0,     0,    48,
       0,     0,    72,    24,    28,     0,    37,    55,    54,    56,
      53,    57,    58,    61,    62,     0,     0,    65,    66,    67,
       0,     0,    76,     0,    74,    46,    45,    43,     0,     0,
      44,    68,     0,    52,    60,    64,    49,     0,    73,     0,
       0,    47,    77,    41,    39,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -111,  -111,    99,  -111,    38,    23,    18,  -111,  -111,  -111,
    -111,    90,  -111,    72,  -111,    92,    51,  -110,  -111,  -111,
    -111,  -111,  -111,  -111,  -111,   -41,   -44,    29,  -111,    20,
    -111,    14,  -111,   -49,  -111,  -111,    -1
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    12,     7,     8,    15,    33,
      24,    25,    26,    53,    38,    41,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    73,    64,    65,    95,    66,
      96,    67,   100,    68,    69,   103,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      63,    74,    76,    82,    72,    43,    44,    81,    80,   123,
     124,    97,    98,    99,    63,   126,    43,    44,    11,    43,
      44,    45,    46,    47,    48,    51,   101,   102,    49,    43,
      44,    52,    75,   108,   109,    50,    51,    19,    23,    51,
      70,    36,    52,    71,    16,    52,     1,     2,    23,    51,
      31,   115,    13,     9,    14,    52,    40,    40,    17,    87,
      88,    89,    90,    91,    92,    13,    18,    14,   -14,     1,
      22,    93,    94,   102,    93,    94,    39,    39,    63,    63,
      20,    21,   -17,    27,    63,    28,    30,    29,    32,    79,
      35,    36,    85,    77,    78,    86,   105,   106,    83,   107,
     116,   125,    70,   110,    10,    37,    84,   111,   117,   121,
     114,   118,   119,   120,   112,   113,   122,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    42
};

static const yytype_int8 yycheck[] =
{
      41,    45,    46,    52,     3,     4,     5,    51,    49,   119,
     120,    31,    32,    33,    55,   125,     4,     5,     5,     4,
       5,     6,     7,     8,     9,    24,    70,    71,    13,     4,
       5,    30,    20,    77,    78,    20,    24,    14,    20,    24,
      21,    26,    30,    24,    20,    30,    11,    12,    30,    24,
      27,   100,    21,     0,    23,    30,    38,    39,     4,    14,
      15,    16,    17,    18,    19,    21,     5,    23,    24,    11,
      12,    29,    30,   117,    29,    30,    38,    39,   119,   120,
      24,    22,    25,    23,   125,     5,    23,    25,    21,     5,
      22,    26,    28,    24,    24,    20,    20,    20,    27,    20,
      22,    10,    21,    20,     5,    33,    55,    25,    23,    20,
      96,    25,    25,    25,    85,    95,   117,    -1,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    35,    36,    37,    38,    40,    41,     0,
      36,     5,    39,    21,    23,    42,    20,     4,     5,    39,
      24,    22,    12,    40,    44,    45,    46,    23,     5,    25,
      23,    39,    21,    43,    45,    22,    26,    47,    48,    38,
      40,    49,    49,     4,     5,     6,     7,     8,     9,    13,
      20,    24,    30,    47,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    63,    65,    67,    68,
      21,    24,     3,    59,    60,    20,    60,    24,    24,     5,
      59,    60,    67,    27,    50,    28,    20,    14,    15,    16,
      17,    18,    19,    29,    30,    62,    64,    31,    32,    33,
      66,    60,    60,    69,    70,    20,    20,    20,    60,    60,
      20,    25,    61,    63,    65,    67,    22,    23,    25,    25,
      25,    20,    70,    51,    51,    10,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    37,    38,    39,    39,
      39,    39,    40,    40,    42,    43,    41,    44,    44,    45,
      45,    46,    46,    48,    47,    49,    49,    50,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    55,    55,    56,    57,    57,    58,    59,    59,
      60,    61,    61,    62,    62,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    67,    67,
      67,    67,    67,    68,    69,    69,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     4,
       3,     6,     1,     1,     0,     0,     8,     1,     1,     1,
       3,     2,     4,     0,     5,     0,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     5,
       7,     5,     2,     3,     3,     3,     3,     4,     1,     4,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     2,     4,     1,     0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 97 "lab9.y" /* yacc.c:1646  */
    {PROGRAM = (yyvsp[0].node);}
#line 1400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 100 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1406 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 102 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);
            (yyval.node) -> next = (yyvsp[0].node);
            }
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 107 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 108 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=(yyvsp[0].node);
        		   }
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 113 "lab9.y" /* yacc.c:1646  */
    {
		 ASTnode *p=(yyvsp[-1].node);
		 while(p!=NULL)
		        {
		 	p->my_data_type = (yyvsp[-2].d_type);
		 	
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
		 (yyval.node) = (yyvsp[-1].node);
		 }
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 138 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=ASTCreateNode(A_VARDEC);
		(yyval.node)->name = (yyvsp[0].string);
		}
#line 1463 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 141 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=ASTCreateNode(A_VARDEC);
        		      (yyval.node)->name = (yyvsp[-3].string);
        		      (yyval.node)->value = (yyvsp[-1].value);}
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 145 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=ASTCreateNode(A_VARDEC);
        	 (yyval.node)->name = (yyvsp[-2].string);
        	 (yyval.node)->s1 = (yyvsp[0].node);}
#line 1479 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "lab9.y" /* yacc.c:1646  */
    {(yyval.node)=ASTCreateNode(A_VARDEC);
        		      		   (yyval.node)->name = (yyvsp[-5].string);
        		      		   (yyval.node)->value = (yyvsp[-3].value);
        		      		   (yyval.node)->s1 = (yyvsp[0].node);}
#line 1488 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 154 "lab9.y" /* yacc.c:1646  */
    {(yyval.d_type) = A_INTTYPE;}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 155 "lab9.y" /* yacc.c:1646  */
    {(yyval.d_type) = A_VOIDTYPE;}
#line 1500 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 158 "lab9.y" /* yacc.c:1646  */
    {if (Search((yyvsp[0].string), LEVEL, 0) != NULL){
                                        yyerror((yyvsp[0].string));
                                        yyerror("ALREADY USED FUN NAME DIEEE");
                                        exit(1);
                                }
                                        
                                        Insert((yyvsp[0].string),(yyvsp[-1].d_type),SYM_FUN,LEVEL,0,0);
                                        
                                        GOFFSET = OFFSET;
                                        OFFSET = 2;
                                        MAXOFFSET = OFFSET;
                                        }
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 170 "lab9.y" /* yacc.c:1646  */
    {Search((yyvsp[-4].string),LEVEL,0)->fparms = (yyvsp[-1].node);}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 171 "lab9.y" /* yacc.c:1646  */
    {	
					(yyval.node) = ASTCreateNode(A_FUNCTIONDEC);
					(yyval.node)->name = (yyvsp[-6].string);	
					(yyval.node)->my_data_type = (yyvsp[-7].d_type);
					(yyval.node)->s1 = (yyvsp[-3].node);
					(yyval.node)->s2 = (yyvsp[0].node);
                                        (yyval.node)->symbol = Search((yyvsp[-6].string), LEVEL, 0);
                                        (yyval.node)->symbol->offset = MAXOFFSET;
                                        OFFSET -= Delete(1);
                                        LEVEL = 0;
                                        OFFSET = GOFFSET;
                                        
				}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 185 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 186 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 189 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 190 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node);
        			(yyval.node)->next = (yyvsp[0].node);
        			}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 195 "lab9.y" /* yacc.c:1646  */
    { if(Search((yyvsp[0].string),LEVEL+1, 0) != NULL){
                                yyerror((yyvsp[0].string));
                                yyerror("PARAM ALREADY USED DIEEE");
                                exit(1);
                                }

                             (yyval.node) = ASTCreateNode(A_PARAM);
			     (yyval.node)->name = (yyvsp[0].string);
		             (yyval.node)->my_data_type = (yyvsp[-1].d_type);
                             (yyval.node)->symbol = Insert((yyval.node)->name, (yyval.node)->my_data_type, SYM_SCALAR, LEVEL+1, 1, OFFSET);
                             OFFSET++;
		             }
#line 1584 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 207 "lab9.y" /* yacc.c:1646  */
    {if(Search((yyvsp[-2].string),LEVEL+1, 0) != NULL){
                                        yyerror((yyvsp[-2].string));
                                        yyerror("PARAM ALREADY USED DIEEE");
                                        exit(1);
                                }
                                        (yyval.node) = ASTCreateNode(A_PARAM);
			     		(yyval.node)->name = (yyvsp[-2].string);
		             		(yyval.node)->my_data_type = (yyvsp[-3].d_type);
		             		(yyval.node)->value = 1;
                                        (yyval.node)->symbol = Insert((yyval.node)->name, (yyval.node)->my_data_type, SYM_ARRAY, LEVEL+1, 1, OFFSET);
                                        OFFSET++;
		             		}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 221 "lab9.y" /* yacc.c:1646  */
    {LEVEL++;}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 222 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_COMPOUND);
		 (yyval.node)->s1 = (yyvsp[-2].node);
		 (yyval.node)->s2 = (yyvsp[-1].node);
                 if(mydebug == 1)
                 {
                        Display();
                 }
                 if(OFFSET > MAXOFFSET) MAXOFFSET = OFFSET ;
                 OFFSET -= Delete(LEVEL);
                 
                 LEVEL--;}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 236 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 238 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);
           	(yyval.node)->next = (yyvsp[0].node);
           	}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 243 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 245 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);
           	(yyval.node)->next = (yyvsp[0].node);
           	}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 250 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 251 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1663 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 252 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 253 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 254 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 255 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 256 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 257 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 261 "lab9.y" /* yacc.c:1646  */
    {
                                     (yyval.node) = ASTCreateNode(A_EXPRSTMT);
                                     (yyval.node)->s1 = (yyvsp[-1].node);
                                    }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 267 "lab9.y" /* yacc.c:1646  */
    {
                                     (yyval.node) = ASTCreateNode(A_EXPRSTMT);
                                    }
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 274 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_SLCT);
                 (yyval.node)->s1 = (yyvsp[-2].node);
                 (yyval.node)->s2 = ASTCreateNode(A_SLCTBODY);
                 (yyval.node)->s2->s1 = (yyvsp[0].node);}
#line 1725 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 279 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_SLCT);
                 (yyval.node)->s1 = (yyvsp[-4].node);
                 (yyval.node)->s2 = ASTCreateNode(A_SLCTBODY);
                 (yyval.node)->s2->s1 = (yyvsp[-2].node);
                 (yyval.node)->s2->s2 = (yyvsp[0].node);}
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 287 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_WHILE);
                         (yyval.node)->s1 = (yyvsp[-2].node);
                         (yyval.node)->s2 = (yyvsp[0].node);}
#line 1743 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 293 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_RETURN);}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 295 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_RETURN);
                 (yyval.node)->s1 = (yyvsp[-1].node);}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 300 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_READ);
                 (yyval.node)->s1 = (yyvsp[-1].node);}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 306 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_WRITE);
		(yyval.node)->s1 = (yyvsp[-1].node);
		}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 309 "lab9.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_WRITE);
			(yyval.node)->name = (yyvsp[-1].string);
			}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 316 "lab9.y" /* yacc.c:1646  */
    { if((yyvsp[-3].node)->my_data_type != (yyvsp[-1].node)->my_data_type){
                        yyerror("TYPE MISMATCH DIEEEE");
                        exit(1);
                }
                (yyval.node) = ASTCreateNode(A_ASSIGN);
                (yyval.node)->s1 = (yyvsp[-3].node);
                (yyval.node)->s2 = (yyvsp[-1].node);
                (yyval.node)->name = CreateTemp();
                (yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[-3].node)->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                OFFSET++;}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 329 "lab9.y" /* yacc.c:1646  */
    {struct SymbTab *p;
                p = Search((yyvsp[0].string), LEVEL, 1);
                if(p == NULL){
                        yyerror((yyvsp[0].string));
                        yyerror("NOT DEFINED VAR DIEEEEE");
                        exit(1);
                }
                if(p->SubType != SYM_SCALAR){
                        yyerror((yyvsp[0].string));
                        yyerror("NOT SCALAR DIEEEEE");
                        exit(1);
                }
                 (yyval.node) = ASTCreateNode(A_VAR);
                 (yyval.node)->name = (yyvsp[0].string);
                 (yyval.node)->symbol = p;
                 (yyval.node)->my_data_type = p->Declared_Type;
                 }
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 348 "lab9.y" /* yacc.c:1646  */
    {struct SymbTab *p;
                p = Search((yyvsp[-3].string), LEVEL, 1);
                if(p == NULL){
                        yyerror((yyvsp[-3].string));
                        yyerror("NOT DEFINED ARRAY DIEEEEE");
                        exit(1);
                }
                if(p->SubType != SYM_ARRAY){
                        yyerror((yyvsp[-3].string));
                        yyerror("NOT SYM_ARRAY DIEEEEE ");
                        exit(1);
                }
                        
                 (yyval.node) = ASTCreateNode(A_VAR);
                 (yyval.node)->name = (yyvsp[-3].string);
                 (yyval.node)->s1 = (yyvsp[-1].node);
                 (yyval.node)->symbol = p;
                 (yyval.node)->my_data_type = p->Declared_Type;
                 
                  }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 371 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);
                }
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 375 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1855 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 377 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_EXPR);
                 (yyval.node)->s1 = (yyvsp[-2].node);
                 (yyval.node)->operator = (yyvsp[-1].operator);
                 (yyval.node)->s2 = (yyvsp[0].node);
                 (yyval.node)->name = CreateTemp();
                 (yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[-2].node)->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;
                 }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 387 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_LE;}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 388 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_LT;}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 389 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_GT;}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 390 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_GE;}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 391 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_EQ;}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 392 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_NE;}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 395 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 398 "lab9.y" /* yacc.c:1646  */
    {if((yyvsp[-2].node)->my_data_type != (yyvsp[0].node)->my_data_type){
                        yyerror("TYPE MISMATCH DIEEEEE");
                        exit(1);
                }
                 (yyval.node) = ASTCreateNode(A_EXPR);
                 (yyval.node)->s1 = (yyvsp[-2].node);
                 (yyval.node)->operator = (yyvsp[-1].operator);
                 (yyval.node)->name = CreateTemp();
                 (yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[-2].node)->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;
                 (yyval.node)->s2 = (yyvsp[0].node);}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 411 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_PLUS;}
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 412 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_MINUS;}
#line 1938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 415 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 417 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_EXPR);
                 (yyval.node)->s1 = (yyvsp[-2].node);
                 (yyval.node)->operator = (yyvsp[-1].operator);
                 (yyval.node)->s2 = (yyvsp[0].node);
                 (yyval.node)->my_data_type = (yyvsp[-2].node)->my_data_type;
                 (yyval.node)->name = CreateTemp();
                 (yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[-2].node)->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;
                 
                }
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 429 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_TIMES;}
#line 1965 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 430 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_DIVIDE;}
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 431 "lab9.y" /* yacc.c:1646  */
    {(yyval.operator) = A_MODULUS;}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 434 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 435 "lab9.y" /* yacc.c:1646  */
    { (yyval.node) =ASTCreateNode(A_NUM);
        	(yyval.node) -> value = (yyvsp[0].value);
                (yyval.node)->my_data_type = A_INTTYPE;
        	}
#line 1992 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 439 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1998 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 440 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 442 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_EXPR);
		(yyval.node)->s1 = (yyvsp[0].node);
		(yyval.node)->operator = A_UNARYMINUS;
                (yyval.node)->my_data_type = (yyvsp[0].node)->my_data_type;
                 (yyval.node)->name = CreateTemp();
                 (yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[0].node)->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;
                }
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 453 "lab9.y" /* yacc.c:1646  */
    {
                struct SymbTab *p;
                p = Search((yyvsp[-3].string), 0, 0);
                if( p == NULL){
                        yyerror((yyvsp[-3].string));
                        yyerror("FUN NAME NOT DEFINED DIEEEE");
                        exit(1);
                }

                if(checkParams((yyvsp[-1].node), p->fparms) == 0){
                        yyerror((yyvsp[-3].string));
                        yyerror("ACTUAL DONT MATCH FORMAL DIEEEEE");
                        exit(1);
                }
		(yyval.node) = ASTCreateNode(A_CALL);
		(yyval.node)->name = (yyvsp[-3].string);
		(yyval.node)->s1 = (yyvsp[-1].node);
                (yyval.node)->symbol = p;
                
                
		}
#line 2043 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 477 "lab9.y" /* yacc.c:1646  */
    {
                (yyval.node) = (yyvsp[0].node);
                }
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 480 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 484 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_ARG);
                (yyval.node)->s1 = (yyvsp[0].node);
                (yyval.node)->my_data_type = (yyvsp[0].node)->my_data_type;
                (yyval.node)->name = CreateTemp();
                 (yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[0].node)->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 491 "lab9.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(A_ARG);
                (yyval.node)->s1 = (yyvsp[-2].node);
                (yyval.node)->next = (yyvsp[0].node);
                (yyval.node)->my_data_type = (yyvsp[-2].node)->my_data_type;
                 (yyval.node)->name = CreateTemp();
                 (yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[-2].node)->my_data_type,SYM_SCALAR,LEVEL,1,OFFSET);
                 OFFSET++;}
#line 2080 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2084 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 499 "lab9.y" /* yacc.c:1906  */
  /* end of rules, start of program */
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


