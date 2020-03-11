#ifndef _TREENODE_H_
#define _TREENODE_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "scanType.h"

#define MAXCHILDREN 3

extern int yylineno;
/**************************************************/
/***********   Syntax tree for parsing ************/
/**************************************************/

typedef enum {
    T_IF, T_THEN, T_ELSE, T_ELSIF, T_BREAK, T_WHILE, T_DO, T_LOOP, T_FOREVER, T_AND, T_BOOL, T_STATIC, T_INT, T_OR, T_CHAR, T_NOT, T_RETURN, T_TRUE, T_FALSE,
   /* multicharacter tokens /
   T_ID, T_NUM,
   / special symbols */
   T_ASSIGN, T_EQ, T_GT, T_LT, T_PLUS, T_MINUS, T_TIMES, T_LPAREN, T_RPAREN, T_SCOL, T_COL, T_LCURL, T_RCURL, T_RAND, T_MOD, T_DIV,
   T_NOTEQ, T_LESSEQ, T_GRTEQ, T_ADDASS, T_SUBASS, T_MULASS, T_DIVASS, T_DEC, T_INC, T_RANGE, T_RBRAC, T_LBRAC
} TokenType;
// Kinds of Operators
// these are the token numbers for the operators same as in flex
typedef int OpKind;  

// Kinds of Statements
typedef enum {DeclK, StmtK, ExpK} NodeKind;

// Subkinds of Declarations
typedef enum {VarK, FuncK, ParamK} DeclKind;

// Subkinds of Statements
typedef enum {NullK, ElsifK, IfK, WhileK, LoopK, LoopForeverK, CompoundK, RangeK, ReturnK, BreakK} StmtKind;

// Subkinds of Expressions
typedef enum {OpK, ConstantK, IdK, AssignK, InitK, CallK} ExpKind;

// ExpType is used for type checking (Void means no type or value, UndefinedType means undefined)
typedef enum {Void, Int, Bool, Char, CharInt, Equal, UndefinedType} ExpType;

// What kind of scoping is used?  (decided during typing)
typedef enum {None, Local, Global, Parameter, LocalStatic} VarKind;


typedef struct treeNode
    {
    // connectivity in the tree
        struct treeNode *child[MAXCHILDREN];   // children of the node
        struct treeNode *sibling;              // siblings for the node

        // what kind of node

        int lineno;                           // linenum relevant to this node
        char * svalue;
        TokenData *dataType;
        NodeKind nodekind;                     // type of node
        union                                  // subtype of type
        {
                DeclKind decl;                     // used when DeclK
                StmtKind stmt;                     // used when StmtK
                ExpKind exp;                       // used when ExpK
        } kind;
        
        // extra properties about the node depending on type of the node
        union                                  // relevant data to type -> attr
        {
                //OpKind op;                         // type of token (same as in bison)
                TokenType op;
                int value;                         // used when an integer constant or boolean
                unsigned char cvalue;               // used when a character
                char *string;                      // used when a string constant
                char *name;                        // used when IdK
        } attr;                                 
        ExpType expType;		           // used when ExpK for type checking
        bool isArray;                          // is this an array
        bool isStatic;                         // is staticly allocated?

        // even more semantic stuff will go here in later assignments.
} TreeNode;     // TreeNode structMOd

#endif
