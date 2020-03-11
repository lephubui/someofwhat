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
/*
   TreeNode * tree, parent;
   tree = node;
   if (par == NULL) {
       parent = tree;
   } else {
      parent = par;
   }
   while (tree != NULL) {
     TreeNode * temp;            // Temporary TreeNode
     int sibling_count = 0;      // Keeps track of siblings
     int line = tree->lineno;    // Node's line number
     std::string tree_svalue = svalResolve(tree);

     if(tree->nodekind == DeclK){
        switch (tree->kind) {
	  case VarK:
             if(!symtable->insert(tree_svalues, tree)){
		printf("Can't insert DeclK:Vark %s \n", tree_svalue);
	     }
             break;
          
           case ParamK:
             if ( !symtable->insert(tree_svalue, tree) )
             {
                // if(testing)
                //     std::cout << "Failed to insert DeclK:ParamK:" << tree_svalue << std::endl;
             }                 
             break;
           case FuncK:
             if ( !symtable->insert(tree_svalue, tree) )
             {
                 // if(testing)
                  //    std::cout << "Failed to insert DeclK:FunK:" << tree_svalue << std::endl;
             }
             symtable->enter("Function " + tree_svalue);
              break;
           case IdK:
             if ( testing )
               {
               //         std::cout << "Hit DeclK:IdK:" << tree_svalue << std::endl;
                }
             temp = (TreeNode *) symtable->lookup(tree_svalue);
             if ( temp != NULL )
             {
                 tree->nodetype = temp->nodetype;
                 if ( temp->isArray && temp->child[0] == NULL )
                 {
                    tree->isArray = true;
                 }
                 if(temp->isIndex)
                 {
                     tree->isIndex = true;
                 }
                 if ( temp->isStatic )
                 {
                    tree->isStatic = true;
                 }

           } else {
                 tree->nodetype = Undef;
            }
            break;
          }
          break;
        }
 
     }*/
  }


// void treeParse ( TreeNode * par, TreeNode * node, SymbolTable * symtable )
// {
//     TreeNode * tree, parent;
//     tree = node;
//     (par == NULL) ? parent = tree : parent = par;

//     while (tree != NULL)
//     {
//         TreeNode * tmp;             // Temporary TreeNode
//         int sibling_count = 0;      // Keeps track of siblings
//         int line = tree->lineno;    // Node's line number

//         Type lhs = Undef; // Left hand side  (child[0])'s type
//         Type rhs = Undef; // Right hand side (child[1])'s type

//         std::string child0_sval;
//         std::string child1_sval;
//         std::string tree_svalue = svalResolve(tree);
//         std::string op = opToStr(tree->token);

//         if ( tree->child[0] != NULL )
//         {
//             lhs = tree->child[0]->nodetype;
//             child0_sval = svalResolve(tree->child[0]);
//         }
//         if ( tree->child[1] != NULL )
//         {
//             rhs = tree->child[1]->nodetype;
//             child1_sval = svalResolve(tree->child[1]);
//         }

//         const char * lhs_str;
//         const char * rhs_str;
//         const char * tree_type_str;
//         tree_type_str = typeToStr(tree->nodetype);
//         lhs_str = typeToStr(lhs);
//         rhs_str = typeToStr(rhs);

//         if(testing)
//         {
//             printf("Tree\n");
//             fflush(stdout);
//             printTreeNode(tree);
//         }
//         // Switch on NodeKind (Declaration, Statement, Expression), then Kind
//         switch (tree->nodekind)
//           {
//             case DeclK: // *** Node is part of a declaration ***
//               switch (tree->kind)
//                 {
//                   case VarK:
//                     if ( !symtable->insert(tree_svalue, tree) )
//                     {
//                         tmp = (TreeNode *) symtable->lookup(tree_svalue);
//                         printf("ERROR(%d): Symbol '%s' is already defined at line %d.\n", line, tree_svalue.c_str(), tmp->lineno);
//                         errors++;
//                     }
//                     else if ( tree->numChildren == 1 && tree->child[0] != NULL )
//                     {
//                         if ( tree->isArray )
//                         {
//                             if ( tree->nodetype != Character )
//                             {
//                                 printf("ERROR(%d): Array '%s' must be of type char to be initialized, but is of type %s.\n",
//                                        line, tree_svalue.c_str(), tree_type_str);
//                                 errors++;
//                             }
//                             else if ( lhs != Character )
//                             {
//                                 printf("ERROR(%d): Initializer for array variable '%s' must be a string, but is of nonarray type %s.\n",
//                                        line, tree_svalue.c_str(), lhs_str);
//                                 errors++;
//                             }
//                         } else if ( tree->child[0]->isIndex )
//                         {
//                             printf("ERROR(%d): Cannot index nonarray '%s'.\n", line, tree_svalue.c_str());
//                             errors++;
//                         } else if ( tree->child[0]->isArray && tree->child[0]->child[0] == NULL )
//                         {
//                             printf("ERROR(%d): Initializer for nonarray variable '%s' of type %s cannot be initialized with an array.\n",
//                                    line, tree_svalue.c_str(), tree_type_str);
//                             errors++;
//                         } else if ( tree->child[0]->isConstant != true )
//                         {
//                             printf("ERROR(%d): Initializer for variable '%s' is not a constant expression.\n",
//                                    line, tree_svalue.c_str());
//                             errors++;
//                         } else if ( lhs != tree->nodetype )
//                         {
//                             printf("ERROR(%d): Variable '%s' is of type %s but is being initialized with an expression of type %s.\n",
//                                    line, tree_svalue.c_str(), tree_type_str, lhs_str);
//                             errors++;
//                         }
//                     }
//                     break;

//                   case ParamK:
//                     if ( !symtable->insert(tree_svalue, tree) )
//                     {
//                         tmp = (TreeNode *) symtable->lookup(tree_svalue);
//                         printf("ERROR(%d): Symbol '%s' is already defined at line %d.\n", line, tree_svalue.c_str(), tmp->lineno);
//                         errors++;
//                     }
//                     break;

//                   case FunK:
//                     if ( !symtable->insert(tree_svalue, tree) )
//                     {
//                         tmp = (TreeNode *) symtable->lookup(tree_svalue);
//                         printf("ERROR(%d): Symbol '%s' is already defined at line %d.\n", line, tree_svalue.c_str(), tmp->lineno);
//                         errors++;
//                     }
//                     symtable->enter("Function " + tree_svalue);
//                     func = tree;
//                     break;

//                   default:
//                     if ( testing )
//                         std::cout << "Hit default case in DeclK switch" << std::endl;
//                     break;

//                 } // end DeclK kind switch
//               break;


//               // *** Node is part of a statement ***
//             case StmtK:
//               switch (tree->kind)
//                 {
//                   case IfK:
//                     if ( tree->numChildren > 0 && tree->child[0] != NULL )
//                     {
//                         if ( tree->child[0]->isArray && tree->child[0]->child[0] == NULL )
//                         {
//                             printf("ERROR(%d): Cannot use array as test condition in if statement.\n", line);
//                             errors++;
//                         } else if ( isBoolean(lhs) == false )
//                         {
//                             printf("ERROR(%d): Expecting Boolean test condition in if statement but got type %s.\n", line, lhs_str);
//                             errors++;
//                         }
//                     }
//                     else
//                     {
//                         if(testing)
//                         {
//                             std::cout << "Less than 2 children in a IfK..." << std::endl;
//                             printTreeNode(tree);
//                         }
//                     }
//                     break;

//                   case CompoundK:
//                     if(tree->isFuncCompound == false)
//                         symtable->enter("Compound" + line);
//                     break;

//                     // TODO: change all if statements to use error checking methods
//                   case ForeachK:
//                       loopDepth.push(true);
//                     if ( tree->numChildren > 1 && tree->child[0] != NULL && tree->child[1] != NULL )
//                     {
//                         if ( tree->child[0]->isArray && tree->child[0]->child[0] == NULL )
//                         {
//                             printf("ERROR(%d): In foreach statement the variable to the left of 'in' must not be an array.\n", line);
//                             errors++;
//                         }
//                         if ( tree->child[1]->isArray == false || 
//                                 ( tree->child[1]->isArray && tree->child[1]->child[0] != NULL ) )
//                         {
//                             if ( !isInteger(lhs) )
//                             {
//                                 printf("ERROR(%d): If not an array, foreach requires lhs of 'in' be of type int but it is type %s.\n",
//                                        line, lhs_str);
//                                 errors++;
//                             }
//                             if ( !isInteger(rhs) )
//                             {
//                                 printf("ERROR(%d): If not an array, foreach requires rhs of 'in' be of type int but it is type %s.\n",
//                                        line, rhs_str);
//                                 errors++;
//                             }
//                         } else if ( !typeCompare(lhs, rhs) )
//                         {
//                             printf("ERROR(%d): Foreach requires operands of 'in' be the same type but lhs is type %s and rhs array is type %s.\n",
//                                    line, lhs_str, rhs_str);
//                             errors++;
//                         }
//                     }
//                     else if (testing)
//                     {
//                         std::cout << "Foreach didn't have 2 children!" << std::endl;
//                         printTreeNode(tree);
//                     }
                        
//                     break;

//                   case WhileK:
//                       loopDepth.push(true);
//                     if ( tree->numChildren > 0 && tree->child[0] != NULL )
//                     {
//                         if ( lhs != Undef &&  tree->child[0]->isArray && tree->child[0]->child[0] == NULL )
//                         {
//                             printf("ERROR(%d): Cannot use array as test condition in while statement.\n", line);
//                             errors++;
//                         } else if ( lhs != Undef && lhs != Boolean )
//                         {
//                             printf("ERROR(%d): Expecting Boolean test condition in while statement but got type %s.\n", line, lhs_str);
//                             errors++;
//                         }
//                     }
//                     else if (testing)
//                     {
//                         std::cout << "While didn't have 2 children!" << std::endl;
//                         printTreeNode(tree);
//                     }
//                     break;

//                   case ReturnK:
//                     return_found = true;
//                     if ( tree->numChildren == 1 && tree->child[0] != NULL )
//                     {
//                         if ( lhs != Undef && tree->child[0]->isArray && tree->child[0]->child[0] == NULL )
//                         {
//                             printf("ERROR(%d): Cannot return an array.\n", line);
//                             errors++;
//                         }
//                         tree->nodetype = tree->child[0]->nodetype;
//                     }
//                     if ( func != NULL )
//                     {
//                         if ( func->nodetype == Void && tree->nodetype != Void && tree->nodetype != Undef )
//                         {
//                             printf("ERROR(%d): Function '%s' at line %d is expecting no return value, but return has return value.\n",
//                                    line, svalResolve(func).c_str(), func->lineno);
//                             errors++;
//                         } else if ( func->nodetype != Void && tree->nodetype == Void && tree->nodetype != Undef )
//                         {
//                             printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but return has no return value.\n",
//                                    line, svalResolve(func).c_str(), func->lineno, typeToStr(func->nodetype));
//                             errors++;
//                         } else if ( func->nodetype != Void && func->nodetype != Undef && tree->nodetype != Undef && func->nodetype != tree->nodetype )
//                         {
//                             printf("ERROR(%d): Function '%s' at line %d is expecting to return type %s but got %s.\n",
//                                    line, svalResolve(func).c_str(), func->lineno, typeToStr(func->nodetype), typeToStr(tree->nodetype));
//                             errors++;
//                         }
//                     }
//                     break;

//                   case BreakK:
//                     if(loopDepth.top() == false)
//                     {
//                         printf("ERROR(%d): Cannot have a break statement outside of loop.\n", line);
//                         errors++;
//                     }
//                     break;

//                   default:
//                     if ( testing )
//                     {
//                         std::cout << "Hit default case in StmtK switch" << std::endl;
//                     }
//                     break;
//                 } // end StmtK kind switch
//               break;


//               // *** Node is part of an expression ***
//             case ExpK:
//               switch (tree->kind)
//                 {
//                   case AssignK:
//                     if ( tree->token != NULL )
//                     {
//                         switch (tree->token->bval)
//                           {
//                             case ASSIGN:
//                               if ( lhs != Undef && rhs != Undef && lhs != rhs )
//                               {
//                                   printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is %s.\n",
//                                          line, op.c_str(), lhs_str, rhs_str);
//                                   errors++;
//                               }
//                               if ( lhs != Undef && rhs != Undef && (tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
//                                    != (tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
//                               {
//                                   printf("ERROR(%d): '%s' requires that if one operand is an array so must the other operand.\n",
//                                          line, op.c_str());
//                                   errors++;
//                               }
//                               break;

//                             case ADDASS:
//                             case SUBASS:
//                             case MULASS:
//                             case DIVASS:
//                               if ( ( tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
//                                 || ( tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
//                               {
//                                   printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
//                                          line, op.c_str());
//                                   errors++;
//                               }                                
//                               if (  lhs != Void && lhs != Undef && lhs != Integer )
//                               {
//                                   printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n",
//                                          line, op.c_str(), typeToStr(Integer), lhs_str);
//                                   errors++;
//                               }
//                               if ( rhs != Void && rhs != Undef && rhs != Integer )
//                               {
//                                   printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n",
//                                          line, op.c_str(), typeToStr(Integer), rhs_str);
//                                   errors++;
//                               }
//                               break;
//                               // TODO: lhs != rhs checking?

//                             case INC:
//                             case DEC:
//                               if ( lhs != Undef && lhs != Integer )
//                               {
//                                   printf("ERROR(%d): Unary '%s' requires operands of type %s but lhs is of type %s.\n",
//                                          line, op.c_str(), typeToStr(Integer), lhs_str);
//                                   errors++;
//                               }
//                               break;
//                           } // end assign switch
//                     } else
//                     {
//                         if ( testing )
//                         {
//                             std::cout << "Tried to access NULL token in ExpK: AssignK" << std::endl;
//                         }
//                     }
//                     break;

//                   case CallK:
//                     if ( tree_svalue != "" )
//                     {
//                         tmp = (TreeNode *) symtable->lookup(tree_svalue);
//                         if ( tmp == NULL )
//                         {
//                             printf("ERROR(%d): Symbol '%s' is not defined.\n", line, tree_svalue.c_str());
//                             errors++;
//                             tree->nodetype = Undef;
//                         } else
//                         {
//                             if ( tmp->kind != FunK )
//                             {
//                                 printf("ERROR(%d): '%s' is a simple variable and cannot be called.\n",
//                                        line, svalResolve(tmp).c_str());
//                                 errors++;
//                             } else
//                             {
//                                 int treesibs = countSiblings(tree->child[0]);
//                                 int tempsibs = countSiblings(tmp->child[0]);

//                                 if ( treesibs < tempsibs )
//                                 {
//                                     printf("ERROR(%d): Too few parameters passed for function '%s' defined on line %d.\n",
//                                            line, svalResolve(tmp).c_str(), tmp->lineno);
//                                     errors++;
//                                 } else if ( treesibs > tempsibs )
//                                 {
//                                     printf("ERROR(%d): Too many parameters passed for function '%s' defined on line %d.\n",
//                                            line, svalResolve(tmp).c_str(), tmp->lineno);
//                                     errors++;
//                                 }
//                                 checkArgTypes(tree, tmp);
//                             }
    
//                         }
//                     }
//                     break;

//                   case FunK:
//                     printf("ERROR(%d): Cannot use function '%s' as a simple variable.\n", line, tree_svalue.c_str());
//                     errors++;
//                     break;

//                   case OpK:
//                     if ( tree->numChildren == 2 )
//                     {
//                         if ( tree->token != NULL )
//                         {
//                             switch (tree->token->bval)
//                               {
//                                 case NOT:
//                                 case QUESTION:
//                                   if ( testing )
//                                   {
//                                       std::cout << "Shouldn't reach Unary in a OpK" << std::endl;
//                                   }
//                                   break;

//                                 case EQ:
//                                 case NOTEQ:
//                                   if ( (tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
//                                     != (tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
//                                   {
//                                       printf("ERROR(%d): '%s' requires that if one operand is an array so must the other operand.\n", line, op.c_str());
//                                       errors++;
//                                   }                                  
//                                   if( !typeCompare(lhs, rhs) )
//                                   {
//                                       printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is %s.\n",
//                                              line, op.c_str(), lhs_str, rhs_str);
//                                       errors++;
//                                   }                                   
//                                   break;                                  

//                                 case LESSEQ:
//                                 case LTHAN:
//                                 case GRTEQ:
//                                 case GTHAN:
//                                   if ( (!isInteger(lhs) && !isCharacter(lhs))
//                                     || (!isInteger(rhs) && !isCharacter(rhs)) )
//                                   {
//                                       if ( !isInteger(lhs) && !isCharacter(lhs) )
//                                       {
//                                           printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n",
//                                                  line, op.c_str(), "char or int", lhs_str);
//                                           errors++;
//                                       }
//                                       if ( !isInteger(rhs) && !isCharacter(rhs) )
//                                       {
//                                           printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n",
//                                                  line, op.c_str(), "char or int", rhs_str);
//                                           errors++;
//                                       }
//                                   }
//                                   if ( !typeCompare(lhs, rhs) )
//                                   {
//                                       printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is %s.\n",
//                                              line, op.c_str(), lhs_str, rhs_str);
//                                       errors++;
//                                   }
//                                   if ( (tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
//                                        || (tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
//                                   {
//                                       printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
//                                              line, op.c_str());
//                                       errors++;
//                                   }
//                                   break;

//                                 case MULTIPLY:
//                                 case PLUS:
//                                 case MINUS:
//                                 case DIVIDE:
//                                 case MODULUS:
//                                   if ( !isInteger(lhs) || !isInteger(rhs) )
//                                   {
//                                       if ( !isInteger(lhs) )
//                                       {
//                                           printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n",
//                                                  line, op.c_str(), typeToStr(Integer), lhs_str);
//                                           errors++;
//                                       }
//                                       if ( !isInteger(rhs) )
//                                       {
//                                           printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n",
//                                                  line, op.c_str(), typeToStr(Integer), rhs_str);
//                                           errors++;
//                                       }
//                                   } else if ( !typeCompare(lhs, rhs) )
//                                   {
//                                       printf("ERROR(%d): '%s' requires operands of the same type but lhs is type %s and rhs is %s.\n",
//                                              line, op.c_str(), lhs_str, rhs_str);
//                                       errors++;
//                                   }
//                                   if ( (tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
//                                        || (tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
//                                   {
//                                       printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
//                                              line, op.c_str());
//                                       errors++;
//                                   }                                  
//                                   break;
                                  
//                                 case AND:
//                                 case OR:
//                                   if ( !isBoolean(lhs) )
//                                   {
//                                       printf("ERROR(%d): '%s' requires operands of type %s but lhs is of type %s.\n",
//                                              line, op.c_str(), typeToStr(Integer), lhs_str);
//                                       errors++;
//                                   }
//                                   if ( !isBoolean(rhs) )
//                                   {
//                                       printf("ERROR(%d): '%s' requires operands of type %s but rhs is of type %s.\n",
//                                              line, op.c_str(), typeToStr(Integer), rhs_str);
//                                       errors++;
//                                   }
//                                   if ( (tree->child[0]->isArray && tree->child[0]->child[0] == NULL)
//                                        || (tree->child[1]->isArray && tree->child[1]->child[0] == NULL) )
//                                   {
//                                       printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
//                                              line, op.c_str());
//                                       errors++;
//                                   }                                      
//                                     break;
//                               }
                           
//                         } else
//                         {
//                             if ( testing )
//                             {
//                                 std::cout << "Tried to access NULL token in ExpK: OpK, or something like that" << std::endl;
//                             }
//                         }
//                     }
//                     break;

//                   case UnaryK:
//                     if ( tree->numChildren == 1 && tree->child[0] != NULL )
//                     {
//                         switch (tree->token->bval)
//                           {
//                             case MULTIPLY:
//                               if ( tree->child[0]->isArray == false || 
//                                  ( tree->child[0]->isArray && tree->child[0]->child[0] != NULL ) )
//                               {
//                                   printf("ERROR(%d): The operation '%s' only works with arrays.\n",
//                                          line, tree_svalue.c_str());
//                                   errors++;
//                               }
//                               break;

//                             case MINUS:
//                               if ( !isInteger(lhs) )
//                               {
//                                   printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given %s.\n",
//                                          line, tree_svalue.c_str(), typeToStr(Integer), lhs_str);
//                                   errors++;
//                               }
//                               break;
//                             case QUESTION:
//                               if ( !isInteger(lhs) )
//                               {
//                                   printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given %s.\n",
//                                          line, tree_svalue.c_str(), typeToStr(Integer), lhs_str);
//                                   errors++;
//                               }
//                               if ( tree->child[0]->isArray && tree->child[0]->child[0] == NULL )
//                               {
//                                   printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
//                                          line, op.c_str());
//                                   errors++;
//                               }
//                               break;

//                             case NOT:
//                               if ( lhs != Undef && lhs != Boolean )
//                               {
//                                   printf("ERROR(%d): Unary '%s' requires an operand of type %s but was given %s.\n",
//                                          line, tree_svalue.c_str(), typeToStr(Boolean), lhs_str);
//                                   errors++;
//                               }
//                               if ( tree->child[0]->isArray && tree->child[0]->child[0] == NULL )
//                               {
//                                   printf("ERROR(%d): The operation '%s' does not work with arrays.\n",
//                                          line, op.c_str());
//                                   errors++;
//                               }                              
//                               break;
//                           }
//                     }
//                     break;

//                   case ParamK:
//                       if (testing)
//                       {
//                           std::cout << "ExpK:ParamK...wat?" << std::endl;
//                           printTreeNode(tree);
//                       }
//                     break;

//                   case IdK:
//                     tmp = (TreeNode *) symtable->lookup(tree_svalue);
//                     if ( tmp != NULL )
//                     {
//                         if ( tree->child[0] != NULL && tree->child[0]->isIndex )
//                         {
//                             tree->isArray = false; // can we have arr[] be a thing?
//                             if ( tmp->isArray ) // TODO: possible subtle error, if add "child[0] == null" check we have...issues. do everything05.c-
//                             {
//                                 if ( child0_sval == tree_svalue && tree->child[0]->child[0] == NULL)
//                                 {
//                                     printf("ERROR(%d): Array index is the unindexed array '%s'.\n", line, tree_svalue.c_str());
//                                     errors++;
//                                 } else if ( lhs != Integer )
//                                 {
//                                     printf("ERROR(%d): Array '%s' should be indexed by type int but got %s.\n",
//                                            line, tree_svalue.c_str(), lhs_str);
//                                     errors++;
//                                 }
//                             } else
//                             {
//                                 printf("ERROR(%d): Cannot index nonarray '%s'.\n",
//                                        line, tree_svalue.c_str());
//                                 errors++;
//                             }
//                         }
//                     } else
//                     {
//                         printf("ERROR(%d): Symbol '%s' is not defined.\n", line, tree_svalue.c_str());
//                         errors++;
//                         tree->nodetype = Undef;
//                     }
//                     break;

//                   default:
//                     break;
//                 } // end ExpK kind switch
//               break;

//             default:
//               if ( testing )
//               {
//                   std::cout << "Hit default case in ExpK switch" << std::endl;
//                   printTreeNode(tree);
//               }
//               break;
//           } // end nodekind switch


//         // Check if there are children
//         if ( tree->numChildren > 0 )
//         {
//             for (int i = 0; i < tree->numChildren; i++)
//             {
//                 if ( tree->child[i] != NULL )
//                 {
//                     treeParse(tree, tree->child[i], symtable );
//                 }
//             }
//         }
        
//         if ( (tree->kind == CompoundK && (tree->isFuncCompound == false)) || tree->kind == FunK )
//         {
//             symtable->leave();
//         }
//         else if(tree->kind == WhileK || tree->kind == ForeachK)
//         {
//             //iloop = false;
//             loopDepth.pop();
//         }
        
//         if ( tree->kind == FunK && tree->lineno > -1 )
//         {
//             if ( tree->nodetype != Void && return_found == false )
//             {
//                 printf("WARNING(%d): Expecting to return type %s but function '%s' has no return statement.\n",
//                        line, tree_type_str, tree_svalue.c_str());
//                 warnings++;
//             }
//             return_found = false;
//             func = NULL;
//         } 

//         tree = tree->sibling; // Jump to the next sibling
//         sibling_count++;

//     } // end while
// }


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
