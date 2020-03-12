#include <stdio.h>
#include <stdlib.h>
#include "symbolTable.h"
#include "treeNode.h"
#include "util.h"
#include "semantic.h"
#include "printtree.h"
#include "scanType.h"
#define MAXCHILDREN 3

SymbolTable mSymbolTable;
SymbolTable * mTypeTable;

TreeNode * func = NULL;

void typeCheckDecleration ( TreeNode * par, TreeNode * node, SymbolTable * symtable );

void printSemanticTree(TreeNode *tree) {
   mSymbolTable.insert("String", NULL);
   mSymbolTable.print(pointerPrintStr); 
   printf("Get the table\n");
}


bool testing = false;

void typeCheckDecleration ( TreeNode * parentNode, TreeNode * node, SymbolTable * symtable ){
    


}


void checkArgTypes( TreeNode * call, TreeNode * func)
{
  int errors = 0;
    if(call == NULL || func == NULL )
    {
        if(testing)
        {
            //std::cout << "NULL passed to checkArgTypes" << std::endl;
        }
        return;
    }
    
    TreeNode * temp_call = call->child[0];
    TreeNode * temp_func = func->child[0];
    int sibling_count = 1;
    
    while( temp_call != NULL && temp_func != NULL)
    {
       
        if ( temp_func->expType != temp_call->expType )
        {
            printf("ERROR(%d): Expecting type %s in parameter %i of call to '%s' defined on line %d but got %s.\n",
                   call->lineno, typeToStr(temp_func->expType), sibling_count, svalResolve(func).c_str(), func->lineno, typeToStr(temp_call->expType));
            errors++;
        }
        if ( temp_func->isArray && (!temp_call->isArray || (temp_call->isArray && temp_call->child[0] != NULL)) )
        {
            printf("ERROR(%d): Expecting array in parameter %i of call to '%s' defined on line %d.\n",
                   call->lineno, sibling_count, svalResolve(func).c_str(), func->lineno);
            errors++;
        }
        if ( !temp_func->isArray && (temp_call->isArray && temp_call->child[0] == NULL) )
        {
            printf("ERROR(%d): Not expecting array in parameter %i of call to '%s' defined on line %d.\n",
                   call->lineno, sibling_count, svalResolve(func).c_str(), func->lineno);
            errors++;
        }
        
        sibling_count++;
        temp_call = temp_call->sibling;
        temp_func = temp_func->sibling;
    }
    
    
}


// Function Tree Parser to check different errors
void treeTraverse ( TreeNode * parentNode, TreeNode * node, SymbolTable * symtable ) {

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
                if ( tree->dataType != NULL )
                {
                    switch (tree->attr.op)
                      {
                        case T_NOTEQ:
                          if ( (tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
                            != (tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
                          {
                              printf("ERROR(%d): '%s' requires that if one operand is an array so must the other operand.\n", line, op.c_str());
                              errors++;
                          }                                  
                          if( !typeCompare(lhs, rhs) )
                          {
                              printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is %s.\n",
                                      line, op.c_str(), lhs_str, rhs_str);
                              errors++;
                          }                                   
                          break;                                  

                        case T_LESSEQ:
                        case T_LT:
                        case T_GRTEQ:
                        case T_GT:
                          if ( (!isInteger(lhs) && !isCharacter(lhs))
                            || (!isInteger(rhs) && !isCharacter(rhs)) )
                          {
                              if ( !isInteger(lhs) && !isCharacter(lhs) )
                              {
                                  printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n",
                                          line, op.c_str(), "char or int", lhs_str);
                                  errors++;
                              }
                              if ( !isInteger(rhs) && !isCharacter(rhs) )
                              {
                                  printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n",
                                          line, op.c_str(), "char or int", rhs_str);
                                  errors++;
                              }
                          }
                          if ( !typeCompare(lhs, rhs) )
                          {
                              printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is %s.\n",
                                      line, op.c_str(), lhs_str, rhs_str);
                              errors++;
                          }
                          if ( (tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
                                || (tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
                          {
                              printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
                                      line, op.c_str());
                              errors++;
                          }
                          break;

                        case T_TIMES:
                        case T_PLUS:
                        case T_MINUS:
                        case T_DIV:
                        case T_MOD:
                          if ( !isInteger(lhs) || !isInteger(rhs) )
                          {
                              if ( !isInteger(lhs) )
                              {
                                  printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n",
                                          line, op.c_str(), typeToStr(Int), lhs_str);
                                  errors++;
                              }
                              if ( !isInteger(rhs) )
                              {
                                  printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n",
                                          line, op.c_str(), typeToStr(Int), rhs_str);
                                  errors++;
                              }
                          } else if ( !typeCompare(lhs, rhs) )
                          {
                              printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is %s.\n",
                                      line, op.c_str(), lhs_str, rhs_str);
                              errors++;
                          }
                          if ( (tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
                                || (tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
                          {
                              printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
                                      line, op.c_str());
                              errors++;
                          }                                  
                          break;
                          
                        case T_AND:
                        case T_OR:
                          if ( !isBoolean(lhs) )
                          {
                              printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n",
                                      line, op.c_str(), typeToStr(Int), lhs_str);
                              errors++;
                          }
                          if ( !isBoolean(rhs) )
                          {
                              printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n",
                                      line, op.c_str(), typeToStr(Int), rhs_str);
                              errors++;
                          }
                          if ( (tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
                                || (tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
                          {
                              printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
                                      line, op.c_str());
                              errors++;
                          }                                      
                            break;
                      }
                    
                } else {
                  printf("Tried to access NULL token in ExpK: OpK, or something like that\n");
                }
                break;
                case ConstantK:
                  
                break;
                case IdK:
                tmp = (TreeNode *) symtable->lookup(tree_svalue);
                if ( tmp != NULL )
                {
                    if ( tree->child[0] != NULL)
                    {
                        tree->isArray = false; 
                        if ( tmp->isArray ) 
                        {
                            if ( child0_sval == tree_svalue && tree->child[0]->child[0] == NULL)
                            {
                                printf("ERROR(%d): Array index is the unindexed array '%s'.\n", line, tree_svalue.c_str());
                                errors++;
                            } else if ( lhs != Int )
                            {
                                printf("ERROR(%d): Array '%s' should be indexed by type int but got %s.\n",
                                        line, tree_svalue.c_str(), lhs_str);
                                errors++;
                            }
                        } else
                        {
                            printf("ERROR(%d): Cannot index nonarray '%s'.\n",
                                    line, tree_svalue.c_str());
                            errors++;
                        }
                    }
                } else
                {
                    printf("ERROR(%d): Symbol '%s' is not defined.\n", line, tree_svalue.c_str());
                    errors++;
                    tree->expType = UndefinedType;
                }
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
                        case T_ADDASS:
                        case T_SUBASS:
                        case T_MULASS:
                        case T_DIVASS:
                          if ( ( tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
                            || ( tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
                          {
                              printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
                                      line, op.c_str());
                              errors++;
                          }                                
                          if (  lhs != Void && lhs != UndefinedType && lhs != Int )
                          {
                              printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n",
                                      line, op.c_str(), typeToStr(Int), lhs_str);
                              errors++;
                          }
                          if ( rhs != Void && rhs != UndefinedType && rhs != Int )
                          {
                              printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n",
                                      line, op.c_str(), typeToStr(Int), rhs_str);
                              errors++;
                          }
                          break;
                          // TODO: lhs != rhs checking?

                        case T_INC:
                        case T_DEC:
                          if ( lhs != UndefinedType && lhs != UndefinedType )
                          {
                              printf("ERROR(%d): Unary '%s' requires operands of type %s but lhs is of type %s.\n",
                                      line, op.c_str(), typeToStr(Int), lhs_str);
                              errors++;
                          }
                        break;
                    } // end switch
                break;
                case InitK:
               
                break;
                case CallK:
                  
                        tmp = (TreeNode *) symtable->lookup(tree_svalue);
                        if ( tmp == NULL )
                        {
                            printf("ERROR(%d): Symbol '%s' is not defined.\n", line, tree_svalue.c_str());
                            errors++;
                            tree->expType = UndefinedType;
                        } else
                        {
                            if ( tmp->kind.decl != FuncK )
                            {
                                printf("ERROR(%d): '%s' is a simple variable and cannot be called.\n",
                                       line, svalResolve(tmp).c_str());
                                errors++;
                            } else
                            {
                                int treesibs = countSiblings(tree->child[0]);
                                int tempsibs = countSiblings(tmp->child[0]);

                                if ( treesibs < tempsibs )
                                {
                                    printf("ERROR(%d): Too few parameters passed for function '%s' defined on line %d.\n",
                                           line, svalResolve(tmp).c_str(), tmp->lineno);
                                    errors++;
                                } else if ( treesibs > tempsibs )
                                {
                                    printf("ERROR(%d): Too many parameters passed for function '%s' defined on line %d.\n",
                                           line, svalResolve(tmp).c_str(), tmp->lineno);
                                    errors++;
                                }
                                checkArgTypes(tree, tmp);
                            }
    
                        }
                    
                    break;
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
                if ( !symtable->insert(tree_svalue, tree) )
                {
                    tmp = (TreeNode *) symtable->lookup(tree_svalue);
                    printf("ERROR(%d): Symbol '%s' is already defined at line %d.\n", line, tree_svalue.c_str(), tmp->lineno);
                    errors++;
                }
                symtable->enter("Function " + tree_svalue);
                func = tree;
                break;
              case ParamK:
                  if ( !symtable->insert(tree_svalue, tree) )
                  {
                      tmp = (TreeNode *) symtable->lookup(tree_svalue);
                      printf("ERROR(%d): Symbol '%s' is already defined at line %d.\n", line, tree_svalue.c_str(), tmp->lineno);
                      errors++;
                  }
                break;
              default:
                  printf("Unknown DeclNode kind in Decleration\n");
                  break;
            }
        } else {
          printf("Node is empty\n");
        }

      for (int i = 0; i < MAXCHILDREN; i++)
      {
          if ( tree->child[i] != NULL )
          {
              treeTraverse(tree, tree->child[i], symtable );
          }
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
    treeTraverse(NULL, tree, mSymbolTable);

    // if ( mSymbolTable->lookup("main") == NULL )
    // {
    //     printf("ERROR(LINKER): Procedure main is not defined.\n");
    //     errors++;
    // }

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
          if(tree->expType == Int){
              printf("type int \n");
          }
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
