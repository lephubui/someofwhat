#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.h"
#include "treeNode.h"
#include "util.h"
#include "semantic.h"

#define MAXCHILDREN 3

SymbolTable mSymbolTable;
SymbolTable * mTypeTable;

void typeCheckDecleration ( TreeNode * par, TreeNode * node, SymbolTable * symtable );

void printSemanticTree(TreeNode *tree) {
   mSymbolTable.insert("String", NULL);
   mSymbolTable.print(pointerPrintStr); 
   printf("Get the table\n");
}

void semanticAnalysis(TreeNode * og) {
    TreeNode * tree = og;
    
    typeCheckDecleration(NULL, tree, mTypeTable);

}    
// std::string svalResolve( TreeNode * tree ) {

//     // std::string temp;
   
//     // if (tree != NULL) {
//     //     if (tree->svalue != NULL) {
//     //         temp.assign(tree->svalue);
//     //     } else if (tree->token != NULL) {
//     //         temp = opToStr(tree->token);
//     //     }
//     // }
//     // return temp;
// }

bool testing = false;

void typeCheckDecleration ( TreeNode * par, TreeNode * node, SymbolTable * symtable ){

}

// Function Tree Parser to check different errors
void treeParse ( TreeNode * par, TreeNode * node, SymbolTable * symtable ) {

  
}


// Function Semantic analysis, Generating ERROR(LINKER)
void semanticAnalysisTree(TreeNode * mTree) {
    int errors = 0;
    SymbolTable * mSymbolTable = new SymbolTable();
    SymbolTable * typetable = new SymbolTable();
    TreeNode * tree = mTree;


    // *** Semantic Analysis *** //
    //treeParse(NULL, tree, mSymbolTable);

    if ( mSymbolTable->lookup("main") == NULL )
    {
        printf("ERROR(LINKER): Procedure main is not defined.\n");
        errors++;
    } else {
      printf("NOTHING\n");
    }

}



/* Procedure traverse is a generic recursive 
 *  syntax tree traversal routine:
 *  it applies preProc in preorder and postProc 
 *  in postorder to tree pointed to by t
 */
static void traverse( TreeNode * t,
               void (* preProc) (TreeNode *),
               void (* postProc) (TreeNode *) )
{ if (t != NULL)
   printf("In the tree\n");
  { preProc(t);
    { int i;
      for (i=0; i < MAXCHILDREN; i++)
        traverse(t->child[i],preProc,postProc);
    }
    postProc(t);
    traverse(t->sibling,preProc,postProc);
  }
}

/*
*  Function to check type of errors
*
*/
static void typeError(TreeNode * t, char * message)
{ printf("Type error at line %d: %s\n",t->lineno,message);
  //Error = TRUE;
}

static int indentno = 0;

// /* macros to increase/decrease indentation */
 #define INDENT indentno+=1
 #define UNINDENT indentno-=1

/* printSpaces indents by printing spaces */
void printSpaces()
{ int i;
  for (i=0;i<indentno;i++)
     printf("!   ");
}
/* Procedure checkNode performs
 * type checking at a single tree node
 */
void checkNode(TreeNode * tree)
{

  int i, sibling = -1, count = 0;
  INDENT;
  if (tree == NULL) {
     printf("Tree is empty\n");
  }
  while (tree != NULL) {
    // printSpaces();
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
          printf("Compoundiddddddddddddddddd [line: %d]\n", tree->lineno);
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
          printf("YOU ARE HEREEEEE\n");
          if(tree->expType != Int){
              printf("Undefined Type \n");
          } else {
              printf("Something defined\n");
          }
          printf(" [line: %d]\n",tree->lineno);
          break;
        case AssignK:
         printf("Assignissssssss: ");
         printToken(tree->attr.op, "\0");
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
