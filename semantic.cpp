#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.h"
#include "treeNode.h"
#include "util.h"
#include "semantic.h"
#include "printtree.h"
#define MAXCHILDREN 3

SymbolTable mSymbolTable;
SymbolTable * mTypeTable;

void typeCheckDecleration ( TreeNode * par, TreeNode * node, SymbolTable * symtable );

void printSemanticTree(TreeNode *tree) {
   mSymbolTable.insert("String", NULL);
   mSymbolTable.print(pointerPrintStr); 
   printf("Get the table\n");
}


bool testing = false;

void typeCheckDecleration ( TreeNode * parentNode, TreeNode * node, SymbolTable * symtable ){
    


}

// Function Tree Parser to check different errors
void treeParseProcess ( TreeNode * parentNode, TreeNode * node, SymbolTable * symtable ) {

    TreeNode * tree, parent;
    tree = node;
    int errors = 0;
    int warnings = 0;
    // (par == NULL) ? parent = tree : parent = par;

    while(tree != NULL) {
        TreeNode * tmp;             // Temporary TreeNode
        int sibling_count = 0;      // Keeps track of siblings
        int line = tree->lineno;    // Node's line number

        ExpType lhs = UndefinedType;
        ExpType rhs = UndefinedType;

        std::string child0_sval;
        std::string child1_sval;
        std::string tree_svalue = svalResolve(tree);
        std::string op = opToStr(tree->dataType);


        if ( tree->child[0] != NULL )
        {
            lhs = tree->child[0]->expType;
            child0_sval = svalResolve(tree->child[0]);
        }
        if ( tree->child[1] != NULL )
        {
            rhs = tree->child[1]->expType;
            child1_sval = svalResolve(tree->child[1]);
        }

        const char * lhs_str;
        const char * rhs_str;
        const char * tree_type_str;
        tree_type_str = typeToStr(tree->expType); // Convert token to string
        lhs_str = typeToStr(lhs); // Convert to String
        rhs_str = typeToStr(rhs); // Convert to String


        if (tree->nodekind==StmtK) {

        } else if (tree->nodekind==ExpK) {
            switch (tree->kind.exp) {
                case OpK:
                  
                  break;
                case ConstantK:
                  
                  break;
                case IdK:
                 
                  break;
                case AssignK:
                    switch(tree->attr.op) {
                        case T_ASSIGN: 
                            if ( lhs != UndefinedType && rhs != UndefinedType && lhs != rhs )
                            {
                                printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is %s.\n",
                                        line, op.c_str(), lhs_str, rhs_str);
                                errors++;
                            }
                            if ( lhs != UndefinedType && rhs != UndefinedType && (tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
                                  != (tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
                            {
                                printf("ERROR(%d): '%s' requires that if one operand is an array so must the other operand.\n",
                                        line, op.c_str());
                                errors++;
                            }
                            break;

                    }
                break;
                case InitK:
               
                break;
                case CallK:
               
                break;
                default:
                  printf("Unknown ExpNode kind in Expression\n");
                  break;
            }
        } else if (tree->nodekind==DeclK){
            switch (tree->kind.decl) {
              case VarK:
                if (!symtable->insert(tree_svalue, tree)) {
                        tmp = (TreeNode *) symtable->lookup(tree_svalue);
                        printf("ERROR(%d): Symbol '%s' is already declared at line %d.\n", line, tree_svalue.c_str(), tmp->lineno);
                        errors++;
                }
                else if ( tree->child[0] != NULL )
                    {
                        if ( tree->isArray )
                        {
                            if ( tree->expType != Char )
                            {
                                printf("ERROR(%d): Array '%s' must be of type char to be initialized, but is of type %s.\n",
                                       line, tree_svalue.c_str(), tree_type_str);
                                errors++;
                            }
                            else if ( lhs != Char )
                            {
                                printf("ERROR(%d): Initializer for array variable '%s' must be a string, but is of nonarray type %s.\n",
                                       line, tree_svalue.c_str(), lhs_str);
                                errors++;
                            }
                        } else if ( tree->child[0]->isArray && tree->child[0]->child[0] == NULL )
                        {
                            printf("ERROR(%d): Initializer for nonarray variable '%s' of type %s cannot be initialized with an array.\n",
                                   line, tree_svalue.c_str(), tree_type_str);
                            errors++;
                        } else if ( lhs != tree->expType )
                        {
                            printf("ERROR(%d): Variable '%s' is of type %s but is being initialized with an expression of type %s.\n",
                                   line, tree_svalue.c_str(), tree_type_str, lhs_str);
                            errors++;
                        }
                    }
                break;
              case FuncK:
                printf("Func %s return type ",tree->attr.name);
                
                break;
              case ParamK:
                  
                    break;
              default:
                  printf("Unknown DeclNode kind in Decleration\n");
                  break;
            }
        } else {
          printf("Node is empty\n");
        }

      tree = tree->sibling;
    } // End while loop
  
}


// Function Semantic analysis, Generating ERROR(LINKER)
void semanticAnalysisTree(TreeNode * mTree) {
    int errors = 0;
    SymbolTable * mSymbolTable = new SymbolTable();
    SymbolTable * typetable = new SymbolTable();
    TreeNode * tree = mTree;


    // Semantic Analysis 
    treeParseProcess(NULL, tree, mSymbolTable);

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
          if(tree->expType != Int){
              printf("Undefined Type \n");
          } else {
              printf("Something defined\n");
          }
          printf(" [line: %d]\n",tree->lineno);
          break;
        case AssignK:
         printf("Assign: ");
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
