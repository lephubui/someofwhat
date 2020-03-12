/* C++ Libraries */
#include <iostream>
#include <string>
#include <cstdlib>

/* C libraries */
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdbool.h>

/* Local headers */
#include "treeNode.h"
#include "scanType.h"
#include "printtree.h"
// #include "util.h"
#include "c-.tab.h"


int errors = 0;
int warnings = 0;

void printTokenForErrWarn( TokenType token, const char* tokenString ){ 
  switch (token)
  { 
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


// Returns number of siblings the node has
int countSiblings( TreeNode * start ) {
    int sib_count = 0;
    
    if( start != NULL) {
        TreeNode * temp = start->sibling;
        while(temp != NULL) {
            sib_count++;
            temp = temp->sibling;
        }
    }
    return sib_count;
}

void printError( int line, std::string err ) {
    std::cout << "ERROR(" << line << "): " << err << "." << std::endl;
    std::cout.flush();
    err.clear();
    errors++;
}

void printWarning( int line, std::string warn ) {
    std::cout << "WARNING(" << line << "): " << warn << "." << std::endl;
    std::cout.flush();
    warn.clear();
    warnings++;
}

// Returns the text string version of Type t
const char * typeToStr(ExpType t ) {
    switch (t) {
        case Void:
            return ("void");
            break;
        case Int:
            return ("int");
            break;
        case Bool:
            return ("bool");
            break;
        case Char:
            return ("char");
            break;
        case UndefinedType:
            return ("undefined type");
            break;
    }
    return "";
}

std::string applyIndents( std::string s, int indent ) {
    std::string temp;
    for (int i = 0; i < indent; i++) {
        temp.append("!   ");
    }
    temp.append(s);
    return temp;
}

const char * nodekindToStr( NodeKind nk ) {
    switch(nk) {
        case DeclK:
            return ("DeclK");
            break;
        case StmtK:
            return ("StmtK");
            break;
        case ExpK:
            return ("ExpK");
            break;
    }
    return "";
}

std::string svalResolve( TreeNode * tree ) {

    std::string temp;
    
    if (tree != NULL) {
        if (tree->svalue != NULL) {
            temp.assign(tree->svalue);
        } else if (tree->dataType != NULL) {
            temp = opToStr(tree->dataType);
        }
    }
    return temp;
}

std::string opToStr( TokenData * tok ) {

    std::string temp;

    if (tok != NULL) {
        if (tok->tokenstr != NULL) {
            temp.assign(tok->tokenstr);
        } else if (tok->cvalue != 0) {
            temp.push_back(tok->cvalue);
        } else {
            temp += tok->idValue;
        }
    }

    return temp;
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

// Print error and warning from the tree
void printErrorWarningTree ( TreeNode * og)
{
    TreeNode * tree = og;
    int i, sibling = -1, count = 0;
    INDENT;
    if (tree == NULL) {
      printf("Tree is empty\n");
    }

    // Prints all nodes of the tree
    while (tree != NULL)
    {
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
          printTokenForErrWarn(tree->attr.op, "\0");
          printf(" [line: %d]\n",tree->lineno); 
          break;
        case ConstantK:
          printf("Const: %d",tree->attr.value);
          if(tree->expType == Int){
              printf(" [type int]");
          }
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
         printTokenForErrWarn(tree->attr.op, "\0");
         if(tree->expType != Int) {
	       printf(" [undefined type]");
         } else {
           printf("WRONG!!!!");
         }
         printf(" [line: %d]\n",tree->lineno);
	     break;
        case InitK:
         printf("Init : ");
         printTokenForErrWarn(tree->attr.op, "\0");
         printf(" [line: %d]\n",tree->lineno);
         break;
        case CallK:
         printf("Call: ");
         printTokenForErrWarn(tree->attr.op, "\0");
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
            printTokenForErrWarn(tree->attr.op, "\0");
          } else{
            printf("Var %s of type ", tree->attr.string);
            printTokenForErrWarn(tree->attr.op, "\0");
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
              printTokenForErrWarn(tree->attr.op, "\0");
	  }else {
              printf("Param %s of type ",tree->attr.name);
	      printTokenForErrWarn(tree->attr.op, "\0");
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
          printErrorWarningTree(tree->child[i]);
       }
    }
    tree = tree->sibling;
    ++sibling;
} // end while
  UNINDENT;
}
