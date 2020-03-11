/* C++ Libraries */
#include <iostream>
#include <string>
#include <cstdlib>

/* C libraries */
#include <stdio.h>
#include <string.h>
#include <getopt.h>

/* Local headers */
#include "treeNode.h"
#include "scanType.h"
#include "printtree.h"
#include "util.h"


int errors = 0;
int warnings = 0;
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


void printAnnotatedTree ( TreeNode * og, int indent_count )
{

    TreeNode * tree = og;
    int sibling_count = 0; // Keeps track of siblings
    std::string outstr; // Output buffer

    // Prints all nodes of the tree
    while (tree != NULL)
    {

        if ( sibling_count > 0 )
        {
            outstr.append("|Sibling: ");
            // outstr.append(std::to_string(sibling_count));
            outstr.append("  ");
            std::cout << applyIndents(outstr, indent_count);
            std::cout.flush();
            outstr.clear();
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


        std::cout << outstr << " [line: " << tree->lineno << "]" << std::endl;
        std::cout.flush();
        outstr.clear();

        // Check if there are children
       // if ( tree->numChildren > 0 )
       // {
            for (int i = 0; i < 3; i++)
            {
                if ( tree->child[i] != NULL )
                {
                    outstr.append("!   Child: ");
                    // outstr.append(std::to_string(i));
                    outstr.append("  ");
                    std::cout << applyIndents(outstr, indent_count);
                    std::cout.flush();
                    outstr.clear();
                    printAnnotatedTree(tree->child[i], indent_count + 1);
                }
            }
       // }

        tree = tree->sibling; // Jump to the next sibling
        sibling_count++;
    } // end while

}
