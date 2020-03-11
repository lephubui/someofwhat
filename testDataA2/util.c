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
  { case IF: printf("IF TOKEN\n"); break;
    case EQUAL: printf("=\n"); break;
    case RETURN: printf("(\n"); break;
    case BREAK: printf(")\n"); break;
    //case SEMI: printf(";\n"); break;
    case PLUS: printf("+\n"); break;
    case MINUS: printf("-\n"); break;
    case MULTIPLY: printf("*\n"); break;
    case NUMCONST:
      printf("NUM, val= %s\n",tokenString);
      break;
    case ID:
      printf("ID, name= %s\n",tokenString);
      break;
    // case ERROR:
    //  printf("ERROR: %s\n",tokenString);
    //  break;
    case '=':
       printf("=");
       break;
    case Int:
      printf("int ");
      break;
    case Bool:
      printf("bool ");
      break;
    case Char:
      printf("char ");
      break;
    default: /* should never happen */
      printf("Unknown token: %d\n",token);
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
// #define INDENT indentno+=2
// #define UNINDENT indentno-=2

/* printSpaces indents by printing spaces */
static void printSpaces()
{ int i;
  for (i=0;i<indentno;i++)
    if(i%3 == 0) {
       printf("!");
       printf("   ");
    }
}

/* procedure printTree prints a syntax tree to the 
 * listing file using indentation to indicate subtrees
 */
void printTree( TreeNode * tree ){
   int i, countSibling =0, count = 0;
  if (tree == NULL) {
     printf("Tree is empty\n");
  }
  while (tree != NULL) {
    // printSpaces();
    // printf("AAA\n");
    if (tree->nodekind==StmtK){
      // printf("1111\n");
      switch (tree->kind.stmt) {
        case IfK:
          printf("If\n");
          break;
       // case RepeatK:
       //   printf("Repeat\n");
       //   break;
        case CompoundK:
          printf("Compound [line: %d]\n", tree->lineno);
          break;
	      case AssignK:
          printf("Assign to: %s\n",tree->attr.name);
          break;
        case ReturnK:
          printf("If ReturnK\n");
          break;
        //case ReadK:
        //  printf("Read: %s\n",tree->attr.name);
        //  break;
        //case WriteK:
        //  printf("Write\n");
        //  break;
        default:
          printf("Unknown ExpNode kind in Statement\n");
          break;
      }
    }else if (tree->nodekind==ExpK) {
      //printf("3333\n");
      switch (tree->kind.exp) {
        case OpK:
          printf("Op: ");                                                                                                 printToken(tree->attr.op, "\0");
         printf(" [line: %d]\n",tree->lineno); 
         break;
        case ConstantK:
          printf("Const: %d",tree->attr.value);
          printf(" [line: %d]\n",tree->lineno);
          break;
        case IdK:
          printf("Id: %s",tree->attr.name);
          printf(" [line: %d]\n",tree->lineno);
          break;
        case AssignK:
	printf("Assign: ");
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
            printToken(tree->expType, "\0");
          } else{
            printf("Var %s of type ", tree->attr.string);
            printToken(tree->expType, "\0");
	  }
          printf("[line: %d]\n", tree->lineno);
          break;
        case FuncK:
        char * type;
        if(tree->expType == ExpType(Void)){
          type =(char*) "void";
        }
          printf("Func %s return type %s [line: %d]\n",tree->attr.name, type, tree->lineno);
          break;
        case ParamK:
          if(tree->isArray) {
	    printf("Param %s is array of type ", tree->attr.name);
            printToken(tree->expType, "\0");
	  }else {
            printf("Param %s of type ",tree->attr.name);
	      printToken(tree->expType, "\0");
          }
	printf("[line: %d]\n", tree->lineno);
          break;
        default:
          printf("Unknown ExpNode kind in Expression\n");
          break;
      }
    } else {printf("Unknown node kind in the last\n");}
    indentno +=3;
    for (i=0;i<MAXCHILDREN;i++)
       if(tree->child[i] != NULL) {
          //indentno -=3; 
          printSpaces();
          printf("Child: %d ", i);
	  printTree(tree->child[i]);
       }
       indentno -=3;
       //count++;
    if(tree->sibling != NULL) {
       // indentno -=3;
        printSpaces();
	      printf("Sibling: %d ", countSibling);
	      countSibling++;
    }
    tree = tree->sibling;
    
  }
}
