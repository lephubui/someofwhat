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
#line 1 "parser.y" /* yacc.c:339  */
 
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "treeNode.h"
#include "scanType.h"
#include "ourgetopt.h"
#include "util.h"

#ifdef CPLUSPLUS

extern int yylex();
extern FILE* yyin;
static TreeNode * savedTree; /* stores syntax tree for later return */

#endif

void yyerror(const char *msg)
{
      printf("ERROR(PARSER): %s\n",msg);
}

// the syntax tree goes here
TreeNode *syntaxTree;

static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
bool flagCheck = false;
// variable storage
double vars[26];

#line 98 "parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRINGCONST = 258,
    BOOL = 259,
    INT = 260,
    CHAR = 261,
    EQUAL = 262,
    ASPC = 263,
    RETURN = 264,
    NUMCONST = 265,
    ID = 266,
    LOOP = 267,
    FOREVER = 268,
    STATIC = 269,
    IF = 270,
    ELSE = 271,
    OR = 272,
    AND = 273,
    RANGE = 274,
    THEN = 275,
    DO = 276,
    NOT = 277,
    NONE = 278,
    TRUE = 279,
    ELSEIF = 280,
    FALSE = 281,
    DIVASS = 282,
    LESSEQ = 283,
    GRTEQ = 284,
    DEC = 285,
    ADDASS = 286,
    SUBASS = 287,
    MULASS = 288,
    NOTEQ = 289,
    WHILE = 290,
    BREAK = 291,
    CHARCONST = 292,
    INC = 293,
    PLUS = 294,
    MINUS = 295,
    MULTIPLY = 296,
    DIVIDE = 297,
    MODULUS = 298,
    QUESTION = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "parser.y" /* yacc.c:355  */

    ExpType expType;
    TokenData *tokenData; 
    TreeNode *tree;


#line 190 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 207 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   355

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  54
/* YYNRULES -- Number of rules.  */
#define YYNRULES  130
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  203

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    53,
      43,    54,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    44,    45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    80,    92,    95,    96,   100,   106,   112,
     116,   122,   123,   129,   132,   142,   143,   146,   147,   148,
     151,   158,   167,   168,   171,   175,   180,   185,   189,   193,
     198,   206,   207,   208,   209,   210,   211,   212,   215,   216,
     220,   229,   234,   237,   242,   245,   246,   247,   248,   255,
     256,   257,   260,   261,   264,   275,   282,   285,   291,   296,
     304,   309,   316,   321,   326,   334,   343,   348,   352,   361,
     366,   370,   381,   388,   392,   401,   405,   411,   416,   424,
     432,   440,   448,   456,   463,   470,   473,   480,   483,   490,
     493,   500,   503,   508,   511,   514,   517,   520,   523,   526,
     531,   536,   539,   542,   547,   550,   553,   556,   559,   565,
     567,   570,   573,   576,   581,   582,   585,   589,   597,   598,
     599,   602,   607,   608,   611,   615,   618,   623,   630,   637,
     643
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRINGCONST", "BOOL", "INT", "CHAR",
  "EQUAL", "ASPC", "RETURN", "NUMCONST", "ID", "LOOP", "FOREVER", "STATIC",
  "IF", "ELSE", "OR", "AND", "RANGE", "THEN", "DO", "NOT", "NONE", "TRUE",
  "ELSEIF", "FALSE", "DIVASS", "LESSEQ", "GRTEQ", "DEC", "ADDASS",
  "SUBASS", "MULASS", "NOTEQ", "WHILE", "BREAK", "CHARCONST", "INC", "'('",
  "')'", "','", "'>'", "'<'", "PLUS", "MINUS", "MULTIPLY", "DIVIDE",
  "MODULUS", "QUESTION", "':'", "'{'", "'}'", "';'", "'='", "'['", "']'",
  "$accept", "program", "declarationList", "declaration", "varDeclaration",
  "scopedVarDeclaration", "varDeclList", "varDeclInitialize", "varDeclId",
  "scopedTypeSpecifier", "typeSpecifier", "funDeclaration", "params",
  "paramList", "paramTypeList", "paramIdList", "paramId", "statement",
  "expressionStmt", "compoundStmt", "localDeclarations", "statementList",
  "optionalStmt", "matched", "unmatched", "matchedIf", "matchedElse",
  "unmatchedIf", "unmatchedElse", "iterationRange", "matchedWhile",
  "unmatchedWhile", "iterationStmt", "returnStmt", "breakStmt",
  "expression", "simpleExpression", "andExpression", "unaryRelExpression",
  "relExpression", "relop", "sumExpression", "sumop", "mulExpression",
  "mulop", "unaryExpression", "unaryop", "factor", "mutable", "immutable",
  "call", "args", "argList", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,    40,
      41,    44,    62,    60,   294,   295,   296,   297,   298,   299,
      58,   123,   125,    59,    61,    91,    93
};
# endif

#define YYPACT_NINF -162

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-162)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,  -162,  -162,  -162,   -17,    30,    84,  -162,  -162,    26,
    -162,   111,  -162,  -162,   -30,   -29,  -162,     0,    46,    25,
      20,  -162,   111,    64,    80,  -162,   288,    39,    43,  -162,
     192,   111,    62,    50,    57,  -162,  -162,  -162,    74,   288,
    -162,  -162,  -162,   288,  -162,  -162,  -162,   116,   119,  -162,
    -162,   146,    73,  -162,   306,  -162,    83,  -162,  -162,  -162,
      79,    46,   255,    92,   288,   288,    86,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,    89,   116,   179,
    -162,   192,  -162,   288,  -162,   106,   288,   288,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,   306,   306,  -162,  -162,
    -162,   306,  -162,   288,  -162,  -162,  -162,    99,    91,   192,
      -6,    35,  -162,    15,  -162,   288,  -162,   288,   288,   288,
    -162,   288,  -162,  -162,   120,   122,  -162,   119,  -162,    54,
      73,  -162,   108,  -162,   288,   140,  -162,   237,   192,   111,
    -162,    80,  -162,   147,  -162,  -162,  -162,  -162,  -162,  -162,
     288,  -162,   105,   192,   117,   288,  -162,  -162,  -162,    29,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,    -5,
    -162,  -162,  -162,   288,  -162,    91,   237,    38,   237,   288,
    -162,  -162,  -162,    -7,   145,  -162,  -162,   237,  -162,  -162,
      52,   288,   237,  -162,  -162,   237,   116,  -162,  -162,    29,
    -162,  -162,  -162
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    17,    19,     0,     0,     2,     4,     5,     0,
       6,    23,     1,     3,    13,     0,    10,    11,     0,     0,
      22,    25,    23,     0,     0,     7,     0,    29,    26,    28,
       0,     0,     0,     0,    13,     9,   128,   126,   116,     0,
     129,   130,   127,     0,   111,   112,   113,    12,    87,    89,
      91,    93,   101,   105,     0,   110,   115,   114,   119,   120,
       0,     0,     0,     0,     0,     0,     0,    42,    39,    21,
      31,    32,    33,    34,    35,    36,    37,     0,    85,   115,
      24,     0,    14,   123,    90,     0,     0,     0,    98,    94,
      97,    99,    96,    95,   102,   103,     0,     0,   106,   107,
     108,     0,   109,     0,    30,    27,    75,     0,     0,     0,
       0,     0,    77,    44,    38,     0,    84,     0,     0,     0,
      83,     0,    20,   125,     0,   122,   118,    86,    88,    92,
     100,   104,     0,    76,     0,     0,    73,     0,     0,     0,
      41,     0,    16,     0,    82,    79,    80,    81,    78,   121,
       0,   117,     0,     0,     0,     0,    45,    46,    51,    57,
      58,    49,    52,    50,    53,    47,    48,    72,    15,     0,
      40,    43,   124,     0,    74,     0,     0,     0,     0,     0,
      54,    59,     8,    64,     0,    67,    70,     0,    56,    63,
       0,     0,     0,    66,    69,     0,    65,    68,    71,    60,
      62,    55,    61
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,   162,  -162,  -162,    31,   152,  -162,  -162,
       1,  -162,   148,  -162,   150,  -162,   118,   -76,  -129,   -95,
    -162,  -162,  -162,  -161,  -160,   -91,   -22,   -69,   -21,    10,
    -162,  -162,  -162,   -51,   -44,   -39,   -24,   101,   -36,  -162,
    -162,    98,  -162,   100,  -162,   -48,  -162,  -162,   -26,  -162,
    -162,  -162,  -162,  -162
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,   140,    15,    16,    17,   141,
      18,    10,    19,    20,    21,    28,    29,    69,    70,    71,
     113,   143,   158,   159,   160,    72,   180,    73,   181,   135,
     163,   164,    74,    75,    76,    77,    78,    48,    49,    50,
      96,    51,    97,    52,   101,    53,    54,    55,    79,    57,
      58,   124,   125,    59
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      56,     9,    47,    84,    85,   122,   102,     9,   156,    22,
      86,    86,    24,    56,   137,   185,   186,   188,   189,     1,
       2,     3,    11,   107,    25,    23,   193,   194,    56,   139,
      12,   197,   198,   136,   199,   200,    24,    14,    56,    56,
     110,   111,   157,   191,   123,   178,   161,   156,   182,   156,
      26,   128,    86,   131,   179,    86,   138,    27,   156,   187,
      56,    56,   167,   156,   132,    30,   156,   171,   162,    86,
      56,    56,   195,    31,    33,    56,   144,   174,   145,   146,
     147,   157,   148,   157,    61,   161,   165,   161,     1,     2,
       3,    34,   157,   166,    60,     4,   161,   157,    94,    95,
     157,   161,    81,   108,   161,   109,    82,   162,    56,   162,
     152,   172,    23,    83,   142,     1,     2,     3,   162,    98,
      99,   100,    86,   162,   173,   165,   162,   165,   175,    56,
     176,   177,   166,    86,   166,   104,   165,    87,   103,   112,
     168,   165,   114,   166,   165,   134,   126,    56,   166,   183,
      36,   166,   133,    56,    88,   190,    62,    37,    38,    63,
     149,   153,    64,   150,   151,    56,   192,   196,    13,    39,
      32,    40,   169,    41,    89,    90,    35,   201,   202,   105,
      91,    80,    65,    66,    42,   184,    43,   127,    92,    93,
      94,    95,    44,    45,   129,    36,    46,   130,    67,   170,
      68,    62,    37,    38,    63,     0,   115,    64,     0,   116,
     117,   118,   119,     0,    39,     0,    40,   120,    41,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,    42,
       0,    43,     0,   121,   103,     0,     0,    44,    45,     0,
      36,    46,     0,    67,     0,    68,    62,    37,    38,   154,
       0,     0,    64,     0,     0,     0,     0,     0,    36,    39,
       0,    40,     0,    41,     0,    37,    38,     0,     0,     0,
       0,     0,   155,    66,    42,     0,    43,    39,     0,    40,
       0,    41,    44,    45,     0,     0,    46,     0,    67,     0,
      68,    36,    42,     0,    43,     0,     0,     0,    37,    38,
      44,    45,     0,     0,    46,     0,     0,     0,   106,    36,
      39,     0,    40,     0,    41,     0,    37,    38,     0,     0,
       0,     0,     0,     0,     0,    42,     0,    43,     0,     0,
      40,     0,    41,    44,    45,     0,     0,    46,     0,     0,
       0,     0,     0,    42,     0,    43,     0,     0,     0,     0,
       0,    44,    45,     0,     0,    46
};

static const yytype_int16 yycheck[] =
{
      26,     0,    26,    39,    43,    81,    54,     6,   137,    39,
      17,    17,    41,    39,    20,   176,   176,   178,   178,     4,
       5,     6,    39,    62,    53,    55,   187,   187,    54,    14,
       0,   192,   192,   109,   195,   195,    41,    11,    64,    65,
      64,    65,   137,    50,    83,    16,   137,   176,    53,   178,
      50,    87,    17,   101,    25,    17,    21,    11,   187,    21,
      86,    87,   138,   192,   103,    40,   195,   143,   137,    17,
      96,    97,    20,    53,    10,   101,   115,   153,   117,   118,
     119,   176,   121,   178,    41,   176,   137,   178,     4,     5,
       6,    11,   187,   137,    55,    11,   187,   192,    44,    45,
     195,   192,    40,    11,   195,    13,    56,   176,   134,   178,
     134,   150,    55,    39,   113,     4,     5,     6,   187,    46,
      47,    48,    17,   192,    19,   176,   195,   178,    11,   155,
      13,   155,   176,    17,   178,    56,   187,    18,    55,    53,
     139,   192,    53,   187,   195,    54,    40,   173,   192,   173,
       3,   195,    53,   179,     8,   179,     9,    10,    11,    12,
      40,    21,    15,    41,    56,   191,    21,   191,     6,    22,
      22,    24,   141,    26,    28,    29,    24,   199,   199,    61,
      34,    31,    35,    36,    37,   175,    39,    86,    42,    43,
      44,    45,    45,    46,    96,     3,    49,    97,    51,    52,
      53,     9,    10,    11,    12,    -1,    27,    15,    -1,    30,
      31,    32,    33,    -1,    22,    -1,    24,    38,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      -1,    39,    -1,    54,    55,    -1,    -1,    45,    46,    -1,
       3,    49,    -1,    51,    -1,    53,     9,    10,    11,    12,
      -1,    -1,    15,    -1,    -1,    -1,    -1,    -1,     3,    22,
      -1,    24,    -1,    26,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    35,    36,    37,    -1,    39,    22,    -1,    24,
      -1,    26,    45,    46,    -1,    -1,    49,    -1,    51,    -1,
      53,     3,    37,    -1,    39,    -1,    -1,    -1,    10,    11,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    53,     3,
      22,    -1,    24,    -1,    26,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,    -1,
      24,    -1,    26,    45,    46,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    49
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     6,    11,    58,    59,    60,    61,    67,
      68,    39,     0,    60,    11,    63,    64,    65,    67,    69,
      70,    71,    39,    55,    41,    53,    50,    11,    72,    73,
      40,    53,    69,    10,    11,    64,     3,    10,    11,    22,
      24,    26,    37,    39,    45,    46,    49,    93,    94,    95,
      96,    98,   100,   102,   103,   104,   105,   106,   107,   110,
      55,    41,     9,    12,    15,    35,    36,    51,    53,    74,
      75,    76,    82,    84,    89,    90,    91,    92,    93,   105,
      71,    40,    56,    39,    95,    92,    17,    18,     8,    28,
      29,    34,    42,    43,    44,    45,    97,    99,    46,    47,
      48,   101,   102,    55,    56,    73,    53,    92,    11,    13,
      93,    93,    53,    77,    53,    27,    30,    31,    32,    33,
      38,    54,    74,    92,   108,   109,    40,    94,    95,    98,
     100,   102,    92,    53,    54,    86,    74,    20,    21,    14,
      62,    66,    67,    78,    92,    92,    92,    92,    92,    40,
      41,    56,    93,    21,    12,    35,    75,    76,    79,    80,
      81,    82,    84,    87,    88,    90,    91,    74,    67,    63,
      52,    74,    92,    19,    74,    11,    13,    93,    16,    25,
      83,    85,    53,    93,    86,    80,    81,    21,    80,    81,
      93,    50,    21,    80,    81,    20,    93,    80,    81,    80,
      81,    83,    85
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    70,    70,    71,    72,    72,    73,
      73,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      76,    77,    77,    78,    78,    79,    79,    79,    79,    80,
      80,    80,    81,    81,    82,    83,    83,    84,    84,    84,
      85,    85,    85,    85,    86,    86,    87,    87,    87,    88,
      88,    88,    89,    89,    89,    90,    90,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   101,   102,
     102,   103,   103,   103,   104,   104,   105,   105,   106,   106,
     106,   107,   108,   108,   109,   109,   110,   110,   110,   110,
     110
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     3,     3,
       1,     1,     3,     1,     4,     2,     1,     1,     1,     1,
       6,     5,     1,     0,     3,     1,     2,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       4,     2,     0,     2,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     2,     4,     4,     5,
       4,     5,     4,     2,     4,     6,     4,     3,     5,     4,
       3,     5,     4,     3,     5,     2,     3,     2,     3,     3,
       3,     3,     3,     2,     2,     1,     3,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     1,
       1,     4,     1,     0,     3,     1,     1,     1,     1,     1,
       1
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
#line 73 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = (yyvsp[0].tree); 
            syntaxTree = (yyval.tree); 
            if(flagCheck) {printf("program\n");};
        }
#line 1481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 80 "parser.y" /* yacc.c:1646  */
    {
		              // TreeNode *t = $1;
                  //             if(t != NULL){
                  //               while(t->sibling != NULL){
                  //                 t = t->sibling;
                  //               }
                  //               t->sibling = $2;
                  //             } else {
                  //               t = $2;
                  //             }
                  (yyval.tree) = linkChild((yyvsp[-1].tree), (yyvsp[0].tree));
                  ; if(flagCheck) {printf("declarationList declaration\n");};}
#line 1498 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 92 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[0].tree) ;if(flagCheck) {printf("declaration\n");};}
#line 1504 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck) {printf("varDeclaration\n");};}
#line 1510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree) ;if(flagCheck) {printf("funDeclaration\n");};}
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[-1].tree) ;  
                childExpType((yyval.tree), (yyvsp[-2].expType));
                if(flagCheck) {printf("typeSpecifier varDeclList\n");};}
#line 1524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 106 "parser.y" /* yacc.c:1646  */
    {
                              (yyval.tree) = (yyvsp[-1].tree);
                              childExpType((yyval.tree), (yyvsp[-2].expType));
                              if(flagCheck) {printf("scopedTypeSpecifier varDeclList\n");};}
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 112 "parser.y" /* yacc.c:1646  */
    {
                              // Add silding
                             (yyval.tree) = linkChild((yyvsp[-2].tree), (yyvsp[0].tree));
                    if(flagCheck) {printf("varDeclList ',' varDeclInitialize\n");};}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 116 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = (yyvsp[0].tree); 
                    if(flagCheck) {printf("varDeclInitialize\n");};}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 122 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[0].tree); if(flagCheck) {printf("varDeclInitialize\n");};}
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 123 "parser.y" /* yacc.c:1646  */
    {
                    (yyval.tree) = (yyvsp[-2].tree);
                    (yyval.tree)->child[0] = (yyvsp[0].tree);
                    if(flagCheck) {printf("varDeclId\n");};}
#line 1565 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 129 "parser.y" /* yacc.c:1646  */
    { if(flagCheck) {printf("varDeclId\n");};
                  (yyval.tree) = newDeclNode(VarK, (yyvsp[0].tokenData)->linenum);
                  (yyval.tree)->attr.string = strdup((yyvsp[0].tokenData)->tokenstr);}
#line 1573 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 132 "parser.y" /* yacc.c:1646  */
    {
                  (yyval.tree) = newDeclNode(VarK, (yyvsp[-3].tokenData)->linenum);
                  (yyval.tree)->attr.value = (yyvsp[-1].tokenData)->numValue;
                  (yyval.tree)->dataType = (yyvsp[-3].tokenData);
	                (yyval.tree)->attr.op = (yyvsp[-2].tokenData)->tokenclass;
                  (yyval.tree)->isArray = true;
                  if(flagCheck) {printf("ID NUMCONST Token: \n");};}
#line 1585 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "parser.y" /* yacc.c:1646  */
    { (yyval.expType) = (yyvsp[0].expType); if(flagCheck){printf("STATIC typeSpecifier %d Token: \n", (yyvsp[-1].tokenData)->linenum);}; }
#line 1591 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.expType) = (yyvsp[0].expType); if(flagCheck){printf("Type Specifier: \n");};}
#line 1597 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 146 "parser.y" /* yacc.c:1646  */
    {(yyval.expType) = Int; if(flagCheck){printf("INT TYPE\n");};}
#line 1603 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval.expType) = Bool; if(flagCheck){printf("BOOL TYPE\n");};}
#line 1609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.expType) = Char; if(flagCheck){ printf("CHAR TYPE\n");};}
#line 1615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 151 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData)->linenum);
                (yyval.tree)->attr.string = strdup((yyvsp[-4].tokenData)->tokenstr);
                (yyval.tree)->expType = (yyvsp[-5].expType);
                (yyval.tree)->child[0] = (yyvsp[-2].tree);
                (yyval.tree)->child[1] = (yyvsp[0].tree); 
		            if(flagCheck) {printf("typeSpecifier ID params statement\n");};}
#line 1627 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 158 "parser.y" /* yacc.c:1646  */
    {
                 (yyval.tree) = newDeclNode(FuncK, (yyvsp[-4].tokenData)->linenum);
           		   (yyval.tree)->attr.name = strdup((yyvsp[-4].tokenData)->tokenstr);
		            (yyval.tree)->expType = Void;
                 (yyval.tree)->child[0] = (yyvsp[-2].tree);
                 (yyval.tree)->child[1]  = (yyvsp[0].tree);
                 if(flagCheck) {printf("ID params statement\n");};}
#line 1639 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("paramList\n"); };}
#line 1645 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 168 "parser.y" /* yacc.c:1646  */
    { /*empty*/  (yyval.tree) = NULL; }
#line 1651 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 171 "parser.y" /* yacc.c:1646  */
    { 
            // Add silbilin
            (yyval.tree) = linkChild((yyvsp[-2].tree), (yyvsp[0].tree));
            if(flagCheck){ printf("paramList ; paramTypeList\n");};}
#line 1660 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 175 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = (yyvsp[0].tree);
            if(flagCheck) {printf("paramList\n");};}
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[0].tree); 
                childExpType((yyval.tree), (yyvsp[-1].expType));
              if(flagCheck){printf("typeSpecifier paramIdList\n");};}
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 185 "parser.y" /* yacc.c:1646  */
    { 
              //Adding sibling;
              (yyval.tree) = linkChild((yyvsp[-2].tree), (yyvsp[0].tree));
              if(flagCheck){ printf("paramIdList ',' paramId\n");};}
#line 1685 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 189 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[0].tree) ;if(flagCheck){ printf("paramId\n");};}
#line 1691 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 193 "parser.y" /* yacc.c:1646  */
    {
              (yyval.tree) = newDeclNode(ParamK, (yyvsp[0].tokenData)->linenum);
              (yyval.tree)->attr.name = strdup((yyvsp[0].tokenData)->tokenstr);
              //$$->expType = Void;
              if(flagCheck){printf("ID\n");};}
#line 1701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 198 "parser.y" /* yacc.c:1646  */
    { 
              (yyval.tree) = newDeclNode(ParamK, (yyvsp[-2].tokenData)->linenum);
              (yyval.tree)->attr.name = strdup((yyvsp[-2].tokenData)->tokenstr);
              //$$->expType = Void;
              (yyval.tree)->isArray = true;
          if(flagCheck){printf("ID with [ \n");};}
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("expressionStmt\n");};}
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("compoundStmt\n");};}
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 208 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("selectionStmt\n");};}
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 209 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("selectionStmt\n");};}
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("iterationStmt\n");};}
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("returnStmt\n");};}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 212 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("breakStmt\n");};}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree); if(flagCheck){printf("expression\n");};}
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 216 "parser.y" /* yacc.c:1646  */
    { if(flagCheck){printf("simmicolon\n");};}
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 220 "parser.y" /* yacc.c:1646  */
    {
             (yyval.tree) = newStmtNode(CompoundK, (yyvsp[-3].tokenData)->linenum);
             (yyval.tree)->attr.op = (yyvsp[-3].tokenData)->tokenclass;

             (yyval.tree)->child[0] = (yyvsp[-2].tree);
             (yyval.tree)->child[1] = (yyvsp[-1].tree); 
             if(flagCheck){printf("localDeclarations\n");};}
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 229 "parser.y" /* yacc.c:1646  */
    {
                  //Add sibling $1 and $2
                  (yyval.tree) = linkChild((yyvsp[-1].tree), (yyvsp[0].tree));
                  //$$ = $1; 
                  if(flagCheck){printf("localDeclarations scopedVarDeclaration\n");};}
#line 1788 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 234 "parser.y" /* yacc.c:1646  */
    { /*empty*/}
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 237 "parser.y" /* yacc.c:1646  */
    {
              // Adding sibling
              (yyval.tree) = linkChild((yyvsp[-1].tree), (yyvsp[0].tree));
              //$$ = $1;
              if(flagCheck){ printf("statementList statement\n");};}
#line 1804 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 242 "parser.y" /* yacc.c:1646  */
    {/*empty*/}
#line 1810 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("expressionStmt\n");};}
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("compoundStmt\n");};}
#line 1822 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("returnStmt\n");};}
#line 1828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 248 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("breakStmt\n");};}
#line 1834 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 265 "parser.y" /* yacc.c:1646  */
    {
            // New statement
            (yyval.tree) = newStmtNode(IfK, (yyvsp[-4].tokenData)->linenum);
            (yyval.tree)->expType = Void;
            (yyval.tree)->child[0] = (yyvsp[-3].tree);
            (yyval.tree)->child[1] = (yyvsp[-1].tree);
            (yyval.tree)->child[2] = (yyvsp[0].tree);
          }
#line 1847 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 276 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = newStmtNode(ElsifK, (yyvsp[-4].tokenData)->linenum);
            (yyval.tree)->child[0] = (yyvsp[-3].tree);
            (yyval.tree)->child[1] = (yyvsp[-1].tree);
            (yyval.tree)->child[2] = (yyvsp[0].tree);
          }
#line 1858 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 282 "parser.y" /* yacc.c:1646  */
    { (yyval.tree) = (yyvsp[0].tree);}
#line 1864 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 286 "parser.y" /* yacc.c:1646  */
    {
              (yyval.tree) = newStmtNode(IfK, (yyvsp[-3].tokenData)->linenum);
                (yyval.tree)->child[0] = (yyvsp[-2].tree);
                (yyval.tree)->child[1] = (yyvsp[0].tree);
            }
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 291 "parser.y" /* yacc.c:1646  */
    {
               (yyval.tree) = newStmtNode(IfK, (yyvsp[-3].tokenData)->linenum);
                (yyval.tree)->child[0] = (yyvsp[-2].tree);
                (yyval.tree)->child[1] = (yyvsp[0].tree);
            }
#line 1884 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 296 "parser.y" /* yacc.c:1646  */
    {
              (yyval.tree) = newStmtNode(ElsifK, (yyvsp[-4].tokenData)->linenum);
                (yyval.tree)->child[0] = (yyvsp[-3].tree);
                (yyval.tree)->child[1] = (yyvsp[-1].tree);
                (yyval.tree)->child[2] = (yyvsp[0].tree);

            }
#line 1896 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 304 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = newStmtNode(ElsifK, (yyvsp[-3].tokenData)->linenum);
                (yyval.tree)->child[0] = (yyvsp[-2].tree);
                (yyval.tree)->child[1] = (yyvsp[0].tree);
          }
#line 1906 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 310 "parser.y" /* yacc.c:1646  */
    {
              (yyval.tree) = newStmtNode(ElsifK, (yyvsp[-4].tokenData)->linenum);
              (yyval.tree)->child[0] = (yyvsp[-3].tree);
              (yyval.tree)->child[1] = (yyvsp[-1].tree);
              (yyval.tree)->child[2] = (yyvsp[0].tree);
          }
#line 1917 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 316 "parser.y" /* yacc.c:1646  */
    {
             (yyval.tree) = newStmtNode(ElsifK, (yyvsp[-3].tokenData)->linenum);
              (yyval.tree)->child[0] = (yyvsp[-2].tree);
              (yyval.tree)->child[1] = (yyvsp[0].tree);
          }
#line 1927 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 321 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = (yyvsp[0].tree);
          }
#line 1935 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 326 "parser.y" /* yacc.c:1646  */
    {
                // new statment node attr.name = $1
                (yyval.tree) = newStmtNode(RangeK, (yyvsp[-3].tokenData)->linenum);
                (yyval.tree)->child[0] = (yyvsp[-2].tree);
                (yyval.tree)->child[1] = (yyvsp[0].tree);
                (yyval.tree)->child[2] = newExpNode(ConstantK, (yyvsp[-3].tokenData)->linenum);
                (yyval.tree)->attr.value = 1;
                if(flagCheck){printf("simpleExpression RANGE simpleExpression\n");};}
#line 1948 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 334 "parser.y" /* yacc.c:1646  */
    {
                 // add child
                 (yyval.tree) = newStmtNode(RangeK, (yyvsp[-5].tokenData)->linenum);
                (yyval.tree)->child[0] = (yyvsp[-4].tree);
                (yyval.tree)->child[1] = (yyvsp[-2].tree);     
                (yyval.tree)->child[2] = (yyvsp[0].tree);
                 if(flagCheck){printf("simpleExpression RANGE simpleExpression simpleExpression\n");};}
#line 1960 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 343 "parser.y" /* yacc.c:1646  */
    {
              (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData)->linenum);
              (yyval.tree)->child[0] = (yyvsp[-2].tree);
              (yyval.tree)->child[1] = (yyvsp[0].tree);
              if(flagCheck){ printf("WHILE simpleExpression DO statement\n");};}
#line 1970 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 348 "parser.y" /* yacc.c:1646  */
    { 
                (yyval.tree) = newStmtNode(LoopForeverK, (yyvsp[-2].tokenData)->linenum);
                (yyval.tree)->child[0] = (yyvsp[0].tree);
                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
#line 1979 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 352 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = newStmtNode(LoopK, (yyvsp[-4].tokenData)->linenum);
                (yyval.tree)->child[0] = newExpNode(IdK, (yyvsp[-3].tokenData)->linenum);
                (yyval.tree)->child[0]->attr.name = strdup((yyvsp[-3].tokenData)->tokenstr);;
                (yyval.tree)->child[1] = (yyvsp[-2].tree);
                (yyval.tree)->child[2] = (yyvsp[0].tree);
                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
#line 1991 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 361 "parser.y" /* yacc.c:1646  */
    {
              (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData)->linenum);
              (yyval.tree)->child[0] = (yyvsp[-2].tree);
              (yyval.tree)->child[1] = (yyvsp[0].tree);
              if(flagCheck){ printf("WHILE simpleExpression DO statement\n");};}
#line 2001 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 366 "parser.y" /* yacc.c:1646  */
    { 
                 (yyval.tree) = newStmtNode(LoopForeverK, (yyvsp[-2].tokenData)->linenum);
                (yyval.tree)->child[0] = (yyvsp[0].tree);
                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
#line 2010 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 370 "parser.y" /* yacc.c:1646  */
    {
                 (yyval.tree) = newStmtNode(LoopK, (yyvsp[-4].tokenData)->linenum);
                (yyval.tree)->child[0] = newExpNode(IdK, (yyvsp[-3].tokenData)->linenum);
                (yyval.tree)->child[0]->attr.name = strdup((yyvsp[-3].tokenData)->tokenstr);;
                (yyval.tree)->child[1] = (yyvsp[-2].tree);
                (yyval.tree)->child[2] = (yyvsp[0].tree);
                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
#line 2022 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 381 "parser.y" /* yacc.c:1646  */
    {
              (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData)->linenum);
              //Add child $2 and $4
              (yyval.tree) = newStmtNode(WhileK, (yyvsp[-3].tokenData)->linenum);
              (yyval.tree)->child[0] = (yyvsp[-2].tree);
              (yyval.tree)->child[1] = (yyvsp[0].tree);
              ;if(flagCheck){ printf("WHILE simpleExpression DO statement\n");};}
#line 2034 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 388 "parser.y" /* yacc.c:1646  */
    { 

                (yyval.tree) = newStmtNode(LoopForeverK, (yyvsp[-2].tokenData)->linenum);
                (yyval.tree)->child[0] = (yyvsp[0].tree);                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 392 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = newStmtNode(LoopK, (yyvsp[-4].tokenData)->linenum);
                (yyval.tree)->child[0] = newExpNode(IdK, (yyvsp[-3].tokenData)->linenum);
                (yyval.tree)->child[0]->attr.name = strdup((yyvsp[-3].tokenData)->tokenstr);;
                (yyval.tree)->child[1] = (yyvsp[-2].tree);
                (yyval.tree)->child[2] = (yyvsp[0].tree);
                if(flagCheck){ printf("LOOP FOREVER statement\n");};}
#line 2055 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 401 "parser.y" /* yacc.c:1646  */
    {
              (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-1].tokenData)->linenum);
              //$$->op = $-> type of token
              ;if(flagCheck){printf("RETURN\n");};}
#line 2064 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 405 "parser.y" /* yacc.c:1646  */
    {
		        (yyval.tree) = newStmtNode(ReturnK, (yyvsp[-2].tokenData)->linenum);
              (yyval.tree)->child[1] = (yyvsp[-1].tree);
	      if(flagCheck){ printf("RETURN expression\n");};}
#line 2073 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 411 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = newStmtNode(BreakK, (yyvsp[-1].tokenData)->linenum);
            ;if(flagCheck){ printf("BREAK\n");};}
#line 2081 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 416 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = newExpNode(AssignK, (yyvsp[-2].tree)->lineno);
            // $$->attr.op = $2 -> token data
            (yyval.tree)->child[0] = (yyvsp[-2].tree);
            (yyval.tree)->child[1] = (yyvsp[0].tree);
            (yyval.tree)->expType = Void; // othercase is integer
            (yyval.tree)->attr.op = '=';
            if(flagCheck){ printf(" mutable = expression\n");};}
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 424 "parser.y" /* yacc.c:1646  */
    {
              (yyval.tree) = newExpNode(AssignK, (yyvsp[-2].tree)->lineno);
            // $$->attr.op = $2 -> token data
            (yyval.tree)->child[0] = (yyvsp[-2].tree);
            (yyval.tree)->child[1] = (yyvsp[0].tree);
            (yyval.tree)->expType = Int; // othercase is integer
            (yyval.tree)->attr.op = (yyvsp[-1].tokenData)->tokenclass;
             ; if(flagCheck){printf(" mutable ADDASS expression\n");};}
#line 2107 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 432 "parser.y" /* yacc.c:1646  */
    {
               (yyval.tree) = newExpNode(AssignK, (yyvsp[-2].tree)->lineno);
            // $$->attr.op = $2 -> token data
            (yyval.tree)->child[0] = (yyvsp[-2].tree);
            (yyval.tree)->child[1] = (yyvsp[0].tree);
            (yyval.tree)->expType = Void; // othercase is integer
            (yyval.tree)->attr.op = (yyvsp[-1].tokenData)->tokenclass;
           if(flagCheck){printf(" mutable SUBASS expression\n");};}
#line 2120 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 440 "parser.y" /* yacc.c:1646  */
    {
               (yyval.tree) = newExpNode(AssignK, (yyvsp[-2].tree)->lineno);
            // $$->attr.op = $2 -> token data
            (yyval.tree)->child[0] = (yyvsp[-2].tree);
            (yyval.tree)->child[1] = (yyvsp[0].tree);
            (yyval.tree)->expType = Int; // othercase is integer
            (yyval.tree)->attr.op = (yyvsp[-1].tokenData)->tokenclass;
             if(flagCheck){ printf(" mutable MULASS expression\n");};}
#line 2133 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 448 "parser.y" /* yacc.c:1646  */
    {
               (yyval.tree) = newExpNode(AssignK, (yyvsp[-2].tree)->lineno);
            // $$->attr.op = $2 -> token data
            (yyval.tree)->child[0] = (yyvsp[-2].tree);
            (yyval.tree)->child[1] = (yyvsp[0].tree);
            (yyval.tree)->expType = Int; // othercase is integer
            (yyval.tree)->attr.op = (yyvsp[-1].tokenData)->tokenclass;
              if(flagCheck){ printf(" mutable DIVASS expression\n");};}
#line 2146 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 456 "parser.y" /* yacc.c:1646  */
    {
               (yyval.tree) = newExpNode(AssignK, (yyvsp[-1].tree)->lineno);
            // $$->attr.op = $2 -> token data
            (yyval.tree)->child[0] = (yyvsp[-1].tree);
            (yyval.tree)->expType = Int; // othercase is integer
            (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
              if(flagCheck){printf(" mutable INC\n");};}
#line 2158 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 463 "parser.y" /* yacc.c:1646  */
    {
               (yyval.tree) = newExpNode(AssignK, (yyvsp[-1].tree)->lineno);
            // $$->attr.op = $2 -> token data
            (yyval.tree)->child[0] = (yyvsp[-1].tree);
            (yyval.tree)->expType = Int; // othercase is integer
            (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
              if(flagCheck){ printf(" mutable DEC\n");};}
#line 2170 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 470 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);if(flagCheck){ printf(" simpleExpression\n");};}
#line 2176 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 473 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData)->linenum);
                (yyval.tree)->attr.op = (yyvsp[-1].tokenData)->tokenclass;
                (yyval.tree)->expType = Bool;
                (yyval.tree)->child[0] = (yyvsp[-2].tree);
                (yyval.tree)->child[1] = (yyvsp[0].tree)
              ; if(flagCheck){ printf("simpleExpression OR andExpression\n");};}
#line 2188 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 480 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){ printf("andExpression\n");};}
#line 2194 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 483 "parser.y" /* yacc.c:1646  */
    {
              (yyval.tree) = newExpNode(OpK, (yyvsp[-1].tokenData)->linenum);
                (yyval.tree)->attr.op = (yyvsp[-1].tokenData)->tokenclass;
                (yyval.tree)->expType = Bool;
                (yyval.tree)->child[0] = (yyvsp[-2].tree);
                (yyval.tree)->child[1] = (yyvsp[0].tree)
              ; if(flagCheck){ printf("andExpression AND unaryRelExpression\n");};}
#line 2206 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 490 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("unaryRelExpression\n");};}
#line 2212 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 493 "parser.y" /* yacc.c:1646  */
    {
                (yyval.tree) = newExpNode(OpK, (yyvsp[0].tree)->lineno);
                (yyval.tree)->attr.op = (yyvsp[-1].tokenData)->tokenclass;
                (yyval.tree)->expType = Bool;
                (yyval.tree)->child[0] = (yyvsp[0].tree);
               // $$->child[1] = $2;
	        if(flagCheck){ printf("NOTTTT unaryRelExpression\n");};}
#line 2224 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 500 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);  if(flagCheck){printf("relExpression\n");};}
#line 2230 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 503 "parser.y" /* yacc.c:1646  */
    {
            (yyval.tree) = (yyvsp[-1].tree);
            (yyval.tree)->child[0] = (yyvsp[-2].tree);
            (yyval.tree)->child[0] = (yyvsp[0].tree)
            ; if(flagCheck){ printf("sumExpression relop sumExpression\n");};}
#line 2240 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 508 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("sumExpression\n");};}
#line 2246 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 511 "parser.y" /* yacc.c:1646  */
    {  (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
                (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
                (yyval.tree)->expType = Bool;}
#line 2254 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 514 "parser.y" /* yacc.c:1646  */
    {  (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
                (yyval.tree)->attr.op = '<';
                (yyval.tree)->expType = Bool;}
#line 2262 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 517 "parser.y" /* yacc.c:1646  */
    {  (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
                (yyval.tree)->attr.op = '>';
                (yyval.tree)->expType = Bool;}
#line 2270 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 520 "parser.y" /* yacc.c:1646  */
    {  (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
                (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
                (yyval.tree)->expType = Bool;}
#line 2278 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 523 "parser.y" /* yacc.c:1646  */
    {  (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
                (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
                (yyval.tree)->expType = Bool;}
#line 2286 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 526 "parser.y" /* yacc.c:1646  */
    {  (yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
                (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
                (yyval.tree)->expType = Bool;}
#line 2294 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 531 "parser.y" /* yacc.c:1646  */
    {
	        (yyval.tree) = (yyvsp[-1].tree);
                (yyval.tree)->child[0] = (yyvsp[-2].tree);
                (yyval.tree)->child[1] = (yyvsp[0].tree);
                if(flagCheck){printf("sumExpression sumop mulExpression\n");};}
#line 2304 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 536 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("mulExpression\n");};}
#line 2310 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 539 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
              (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
              (yyval.tree)->expType = Int;}
#line 2318 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 542 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
              (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
              (yyval.tree)->expType = Int;}
#line 2326 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 547 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-2].tree);
                (yyval.tree)->child[0] = (yyvsp[-2].tree);
                (yyval.tree)->child[1] = (yyvsp[0].tree); if(flagCheck){printf("mulExpression mulop unaryExpression\n");};}
#line 2334 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 550 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("unaryExpression\n");};}
#line 2340 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 553 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
              (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
              (yyval.tree)->expType = Int;}
#line 2348 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 556 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
              (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
              (yyval.tree)->expType = Int;}
#line 2356 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 559 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
              (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
              (yyval.tree)->expType = Int;}
#line 2364 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 565 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree); (yyval.tree)->child[0] = (yyvsp[0].tree);
	       		if(flagCheck){printf("unaryop unaryExpression\n");};}
#line 2371 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 567 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("factor\n");};}
#line 2377 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 570 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
              (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
              (yyval.tree)->expType = Int;}
#line 2385 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 573 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
              (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
              (yyval.tree)->expType = Int;}
#line 2393 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 576 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(OpK, (yyvsp[0].tokenData)->linenum);
              (yyval.tree)->attr.op = (yyvsp[0].tokenData)->tokenclass;
              (yyval.tree)->expType = Int;}
#line 2401 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 581 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("immutable\n");};}
#line 2407 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 582 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree); if(flagCheck){printf("mutable\n");};}
#line 2413 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 585 "parser.y" /* yacc.c:1646  */
    {
          (yyval.tree) = newExpNode(IdK, (yyvsp[0].tokenData)->linenum);
          (yyval.tree)->attr.name = strdup((yyvsp[0].tokenData)->tokenstr);
          ;if(flagCheck){printf("ID\n");};}
#line 2422 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 589 "parser.y" /* yacc.c:1646  */
    {
          (yyval.tree) = newExpNode(OpK, (yyvsp[-3].tree)->lineno);
          (yyval.tree)->child[0] = (yyvsp[-3].tree);
          (yyval.tree)->child[1] = (yyvsp[-1].tree); 
          if(flagCheck){printf("mutable\n");};}
#line 2432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 597 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[-1].tree);}
#line 2438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 598 "parser.y" /* yacc.c:1646  */
    {}
#line 2444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 599 "parser.y" /* yacc.c:1646  */
    {}
#line 2450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 602 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(CallK, (yyvsp[-3].tokenData)->linenum);
                        (yyval.tree)->expType = (yyvsp[-1].tree)->expType;
                        (yyval.tree)->child[0] = (yyvsp[-1].tree);}
#line 2458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 607 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) =(yyvsp[0].tree);}
#line 2464 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 608 "parser.y" /* yacc.c:1646  */
    {(yyval.tree)= NULL; /*empty*/}
#line 2470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 611 "parser.y" /* yacc.c:1646  */
    {
          // Add silbling
          (yyval.tree) = linkChild((yyvsp[-2].tree), (yyvsp[0].tree));
	}
#line 2479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 615 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = (yyvsp[0].tree);}
#line 2485 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 618 "parser.y" /* yacc.c:1646  */
    {(yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData)->linenum);
          (yyval.tree)->attr.value = (yyvsp[0].tokenData)->numValue;
          (yyval.tree)->expType=Int;
          if(flagCheck){
          printf("NUMCONST\n");};}
#line 2495 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 623 "parser.y" /* yacc.c:1646  */
    { 
           (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData)->linenum);
          (yyval.tree)->attr.value = (yyvsp[0].tokenData)->numValue;
          (yyval.tree)->attr.string = strdup((yyvsp[0].tokenData)->tokencharVal);
          (yyval.tree)->expType=Char;
          if(flagCheck){printf("CHARCONST\n");};}
#line 2506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 630 "parser.y" /* yacc.c:1646  */
    {
           (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData)->linenum);
          (yyval.tree)->attr.value = (yyvsp[0].tokenData)->numValue;
          (yyval.tree)->attr.string = strdup((yyvsp[0].tokenData)->tokenstrVal);
          (yyval.tree)->expType=Char;
          if(flagCheck){printf("STRINGCONST\n");};}
#line 2517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 637 "parser.y" /* yacc.c:1646  */
    {
           (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData)->linenum);
          (yyval.tree)->attr.value = (yyvsp[0].tokenData)->numValue;
          (yyval.tree)->expType=Bool;
          if(flagCheck){printf("TRUE\n");};}
#line 2527 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 643 "parser.y" /* yacc.c:1646  */
    {
           (yyval.tree) = newExpNode(ConstantK, (yyvsp[0].tokenData)->linenum);
          (yyval.tree)->attr.value = 1;
           (yyval.tree)->expType=Bool;
          (yyval.tree)->expType=Int;
          if(flagCheck){printf("FALSE\n");};}
#line 2538 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2542 "parser.tab.c" /* yacc.c:1646  */
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
#line 650 "parser.y" /* yacc.c:1906  */



int main(int argc, char *argv[]) 
{
    int c;
    int counter = 1;
    extern char *optarg;
    int flagTree = 0;

    // hunt for a string of options
    while ((c = getopt(argc, argv,"pd")) != -1) {
        switch (c) {
        case 'd': 
            yydebug=1;
            break;
        case 'p': 
            flagTree = 1;
            break;
        default: 
            exit(1);
        }
        counter++;
    }

    if(argc > 1){

      if(yyin = fopen(argv[argc - 1], "r")){
        yyparse();
        if(flagTree){
          printTree(syntaxTree);
        } else{
          exit(1);
        }
            
     }
   }
        return 0;
}
