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
            outstr.append(std::to_string(sibling_count));
            outstr.append("  ");
            std::cout << applyIndents(outstr, indent_count);
            std::cout.flush();
            outstr.clear();
        }

        switch (tree->kind)
          {
            case OpK:
              outstr += "Op: ";
              outstr += opToStr(tree->token);
              outstr += (" Type: ");
              outstr += typeToStr(tree->nodetype);
              break;

            // case UnaryK:
            //   outstr.append("Op: ");
            //   outstr.append(svalResolve(tree));
            //   outstr += (" Type: ");
            //   outstr += typeToStr(tree->nodetype);
            //   break;

            case ConstantK:
              outstr.append("Const: ");
              if ( tree->nodetype == Boolean )
              {
                  outstr.append(iboolToString(tree->token->ivalue));
              } else if ( tree->nodetype == Integer )
              {
                  outstr.append(std::to_string(tree->token->ivalue));
              } else if ( tree->nodetype == Character )
              {
                  if ( tree->token->svalue != NULL )
                  {
                      outstr += '"';
                      outstr += tree->token->svalue;
                      outstr += '"';
                  } else
                  {
                      outstr += '\'';
                      outstr += tree->token->cvalue;
                      outstr += '\'';
                  }
              }

              outstr.append(" Type: ");
              if ( tree->isArray )
              {
                  outstr.append("is array of ");
              }
              outstr.append(typeToStr(tree->nodetype));
              break;

            case IdK:
              outstr.append("Id: ");
              outstr.append(svalResolve(tree));
              outstr += (" Type: ");
              if ( tree->isArray )
              {
                  outstr.append("is array of ");
              }
              outstr += typeToStr(tree->nodetype);
              break;

            case AssignK:
              outstr.append("Assign: ");
              outstr += opToStr(tree->token);
              outstr += (" Type: ");
              if ( tree->isArray )
              {
                  outstr.append("is array of ");
              }
              outstr += typeToStr(tree->nodetype);
              break;

            case IfK:
              outstr.append("If");
              break;

            case CompoundK:
              outstr.append("Compound");
              outstr += " with size ";
              outstr += std::to_string(tree->size);
              outstr += " at end of it's declarations";                     
              break;

            // case ForeachK:
            //   outstr.append("Foreach");
            //   break;

            case WhileK:
              outstr.append("While");
              break;

            case ReturnK:
              outstr.append("Return");
              break;

            case BreakK:
              outstr.append("Break");
              break;

            case VarK:
              outstr.append("Var ");
              outstr.append(svalResolve(tree));
              if ( tree->isArray )
              {
                  outstr.append(" is array of");
              }
              outstr += " ";
              outstr.append(typeToStr(tree->nodetype));
              outstr += " allocated as ";
            //   if( tree->offsetReg == global )
            //       outstr += "Global";
            //   else
            //       outstr += "Local";
              if(tree->isStatic)
                  outstr += "Static";
              outstr += " of size ";
              outstr += std::to_string(tree->size);
              outstr += " and data location ";
              outstr += std::to_string(tree->location);
              break;

            case ParamK:
              outstr.append("Param ");
              outstr.append(svalResolve(tree));
              if ( tree->isArray )
              {
                  outstr.append(" is array of");
              }
              outstr += " ";
              outstr.append(typeToStr(tree->nodetype));
              outstr += " allocated as ";
              outstr += "Parameter";
              outstr += " of size ";
              outstr += std::to_string(tree->size);
              outstr += " and data location ";
              outstr += std::to_string(tree->location);
              break;

            case FuncK:
              outstr.append("Func ");
              outstr.append(svalResolve(tree));
              outstr.append(" returns type ");
              outstr.append(typeToStr(tree->nodetype));
              outstr += " allocated as ";
            //   if( tree->offsetReg == global )
            //       outstr += "Global";
            //   else
            //       outstr += "Local";
              outstr += " of size -";
              outstr += std::to_string(tree->size);
              outstr += " and exec location ";
              outstr += std::to_string(tree->location);              
              break;

            case CallK:
              outstr.append("Call: ");
              outstr.append(svalResolve(tree));
              outstr += (" Type: ");
              outstr += typeToStr(tree->nodetype);
              break;

            default:
              outstr.append("\nWe shouldn't get here\n");
              break;

          } // end switch

        std::cout << outstr << " [line: " << tree->lineno << "]" << std::endl;
        std::cout.flush();
        outstr.clear();

        // Check if there are children
        if ( tree->numChildren > 0 )
        {
            for (int i = 0; i < tree->numChildren; i++)
            {
                if ( tree->child[i] != NULL )
                {
                    outstr.append("!   Child: ");
                    outstr.append(std::to_string(i));
                    outstr.append("  ");
                    std::cout << applyIndents(outstr, indent_count);
                    std::cout.flush();
                    outstr.clear();
                    printAnnotatedTree(tree->child[i], indent_count + 1);
                }
            }
        }

        tree = tree->sibling; // Jump to the next sibling
        sibling_count++;
    } // end while

}
