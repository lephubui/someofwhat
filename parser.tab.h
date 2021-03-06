/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 33 "parser.y" /* yacc.c:1909  */

    ExpType expType;
    TokenData *tokenData; 
    TreeNode *tree;


#line 106 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
