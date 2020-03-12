/****************************************************/
/* File: util.c                                     */
/* Utility function implementation                  */
/* for the TINY compiler                            */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "treeNode.h"
#include "scanType.h"
#include "util.h"
#include "c-.tab.h"

#define MAXCHILDREN 3

void printToken( TokenType token, const char* tokenString ){ 
  switch (token)
  { 
   printf("IN TOKEN\n");
    //case IF: printf("IF"); break;
   // case EQUAL: printf("="); break;
   // case RETURN: printf("("); break;
   // case BREAK: printf(")"); break;
    case ';': printf(";\n"); break;
    
    case T_PLUS: printf("+"); break;
    case T_MINUS: printf("-"); break;
    case T_TIMES: printf("*"); break;
    case T_ASSIGN: printf("="); break;
    case T_DIV: printf("/"); break;
    case T_GT: printf(">"); break;
    case T_LT: printf("<"); break;
    case T_MOD: printf("%"); break;
    case T_NOTEQ: printf("!="); break;
    case T_LESSEQ: printf("<="); break;
    case T_GRTEQ: printf(">="); break;
    case T_ADDASS: printf("+="); break;
    case T_DIVASS: printf("/="); break;
    case T_SUBASS: printf("-="); break;
    case T_MULASS: printf("*="); break;
    case T_DEC: printf("--"); break;
    case T_INC: printf("++"); break;
    case T_EQ: printf("=="); break;   
    case NUMCONST:
      printf("NUM, val= %s\n",tokenString);
      break;
    case ID:
      printf("ID, name= %s\n",tokenString);
      break;
    // case ERROR:
    //  printf("ERROR: %s\n",tokenString);
    //  break;
    case QUESTION:
     printf("?");
     break;
    case '=':
       printf("=");
       break;
    case Int:
      printf("int ");
      break;
    case Void:
      printf("void ");
      break;
    case Bool:
      printf("bool ");
      break;
    case Char:
      printf("char ");
      break;
    default: /* should never happen */
      printf("Unknown token: %d",token);
      break;
  }
}
/* Function newStmtNode creates a new statement
 * node for syntax tree construction
 */
TreeNode * newStmtNode(StmtKind kind, int lineNum) { 
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    printf("Out of memory error at line %d\n",lineNum);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = StmtK;
    t->kind.stmt = kind;
    t->lineno = lineNum;
  }
  return t;
}

/* Function newStmtNode creates a new declaration
 * node for syntax tree construction
 */
TreeNode * newDeclNode(DeclKind kind, int lineNum) { 
  TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    printf("Out of memory error at line %d\n",lineNum);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = DeclK;
    t->kind.decl = kind;
    t->lineno = lineNum;
   
  }
  return t;
}


/* Function newExpNode creates a new expression 
 * node for syntax tree construction
 */
TreeNode * newExpNode(ExpKind kind, int lineNum)
{ TreeNode * t = (TreeNode *) malloc(sizeof(TreeNode));
  int i;
  if (t==NULL)
    printf("Out of memory error at line %d\n",lineNum);
  else {
    for (i=0;i<MAXCHILDREN;i++) t->child[i] = NULL;
    t->sibling = NULL;
    t->nodekind = ExpK;
    t->kind.exp = kind;
    t->lineno = lineNum;
    t->expType = Void;
  }
  return t;
}

/* Function copyString allocates and makes a new
 * copy of an existing string
 */
char * copyString(char * s, int line)
{ int n;
  char * t;
  if (s==NULL) return NULL;
  n = strlen(s)+1;
  t = (char*)malloc(n);
  if (t==NULL)
    printf("Out of memory error at line %d\n", line);
  else strcpy(t,s);
  return t;
}

void childExpType(TreeNode *mTree, ExpType mType) {
  TreeNode *t = mTree;
  while(t != NULL) {
    t->expType = mType;
    t = t->sibling;
  }
}
// Links siblings to each other, starting with the first
TreeNode * linkChild( TreeNode * child1, TreeNode * child2 ) {

    if (child1 == NULL) {
        return child2;
    }
    if (child2 == NULL) {
        return child1;
    }
 
    if(child1 != NULL && child2 != NULL)
    {
        TreeNode * temp = (TreeNode*) malloc(sizeof(TreeNode));
        temp = child1;

        while ((temp != NULL) && (temp->sibling != NULL)) {
            temp = temp->sibling;
        }
        temp->sibling = child2;
    }

    return child1;
}
// /* Variable indentno is used by printTree to
//  * store current number of spaces to indent
//  */
static int indentno = 0;

// /* macros to increase/decrease indentation */
 #define INDENT indentno+=1
 #define UNINDENT indentno-=1

/* printSpaces indents by printing spaces */
static void printSpaces()
{ int i;
  for (i=0;i<indentno;i++)
     printf("!   ");
}

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */
void printTree( TreeNode * tree ){
  int i, sibling = -1, count = 0;
  INDENT;
  if (tree == NULL) {
     printf("Tree is empty\n");
  }

  while (tree != NULL) {
     //printSpaces();
    if(sibling >= 0) {
        UNINDENT;
        printSpaces();
        printf("Sibling: %d ", sibling);
        INDENT;
    }
    if (tree->nodekind==StmtK){
      switch (tree->kind.stmt) {
        case IfK:
          printf("If [line: %d]\n", tree->lineno);
          break;
        case ElsifK:
          printf("Elsif [line: %d]\n", tree->lineno);
          break;
        case WhileK:
          printf("While [line: %d]\n", tree->lineno);   
          break; 
        case CompoundK:
          printf("Compound [line: %d]\n", tree->lineno);
          break;
        case LoopForeverK:
	  printf("Loop Forever [line: %d]\n", tree->lineno);
          break;
        case LoopK:
          printf("Loop [line: %d]\n",tree->lineno);
          break;
        case ReturnK:
          printf("Return [line: %d]\n", tree->lineno);
          break;
        case RangeK:
          printf("Range [line: %d]\n",tree->lineno);
          break;
        case BreakK:
          printf("Break [line: %d]\n", tree->lineno);
          break;
        default:
          printf("Unknown StmtNode kind in Statement\n");
          break;
      }
    }else if (tree->nodekind==ExpK) {
      switch (tree->kind.exp) {
        case OpK:
          printf("Op: "); 
          printToken(tree->attr.op, "\0");
          printf(" [line: %d]\n",tree->lineno); 
          break;
        case ConstantK:
          printf("Const: %d",tree->attr.value);
          printf(" [line: %d]\n",tree->lineno);
          break;
        case IdK:
          printf("Id: %s",tree->attr.name);
          if (tree->expType != Int) {
            printf(" [undefined type]");
          }
          printf(" [line: %d]\n",tree->lineno);
          break;
        case AssignK:
         printf("Assign: ");
         printToken(tree->attr.op, "\0");
         if(tree->expType != Int) {
	      printf(" [undefined type]");
         } else {
           printf("WRONG!!!!");
         }
         printf(" [line: %d]\n",tree->lineno);
	      break;
        case InitK:
         printf("Init : ");
         printToken(tree->attr.op, "\0");
         printf(" [line: %d]\n",tree->lineno);
         break;
        case CallK:
         printf("Call: ");
         printToken(tree->attr.op, "\0");
         printf(" [line: %d]\n",tree->lineno);
         break;
        default:
          printf("Unknown ExpNode kind in Expression\n");
          break;
      }
    } else if (tree->nodekind==DeclK){ 
      switch (tree->kind.decl) {
        case VarK:
          if(tree->isArray){
            printf("Var %s is array of type ", tree->dataType->tokenstr);
            printToken(tree->attr.op, "\0");
          } else{
            printf("Var %s of type ", tree->attr.string);
            printToken(tree->attr.op, "\0");
	  }
          printf("[line: %d]\n", tree->lineno);
          break;
        case FuncK:
           printf("Func %s return type ",tree->attr.name);
           switch (tree->expType) {
	      case Void:
                printf("void ");
                break;
             case Char:
                printf("char ");
                break;
             case Int:
                printf("int ");
                break;
           }
           printf(" [line: %d]\n",tree->lineno);
           break;
         case ParamK:
          if(tree->isArray) {
	      printf("Param %s is array of type ", tree->attr.name);
              printToken(tree->attr.op, "\0");
	  }else {
              printf("Param %s of type ",tree->attr.name);
	      printToken(tree->attr.op, "\0");
          }
	  printf("[line: %d]\n", tree->lineno);
          break;
        default:
          printf("Unknown DeclNode kind in Decleration\n");
          break;
      }
    } else {
      printf("Unknown node kind in the last\n");
    }

    for (i=0;i<MAXCHILDREN;i++) {
       if(tree->child[i] == NULL) {
          // printf("Counter: %d\n", i);
           continue;
       } else {
          //printf("Counter CHILD NOT EMPTY: %d\n", i);
          printSpaces();
          printf("Child: %d ", i);
          printTree(tree->child[i]);
       }
    }
    tree = tree->sibling;
    ++sibling;
  }
  UNINDENT;
}


bool isBoolean( ExpType t )
{
    return typeCompare( t, Bool );
}

bool isInteger( ExpType t )
{
    return typeCompare( t, Int );    
}

bool isCharacter( ExpType t )
{
    return typeCompare( t, Char );    
}

bool isVoid( ExpType t )
{
    return t == Void ? true : false;
}

bool isUndef( ExpType t )
{
    return t == UndefinedType ? true : false;
}

bool typeCompare( ExpType a, ExpType b )
{
    if( a != UndefinedType && b != UndefinedType  )
        return a == b;
    else
        return true;
}

bool hasType( ExpType t )
{
    if( t != UndefinedType  )
        return true;
    else
        return false;
}