#ifndef _PRINTTREE_H_
#define _PRINTTREE_H_

/* C/C++ headers */
#include <stdio.h>
#include <cstdlib>
#include <string>

/* Local headers */
#include "scanType.h"
#include "treeNode.h"
// #include "cminus.h"
// #include "cminus.tab.h"


const char * iboolToString( int ib );	    // Returns "true" for 1, "false" for 0
std::string applyIndents( std::string s, int indent_count );
const char * typeToStr( ExpType t );	        // Returns literal string of type, eg "int" for Integer
const char * nodekindToStr( NodeKind nk );
std::string svalResolve( TreeNode * tree ); // Resolves the svalue of node or token as a C++ string
std::string opToStr( TokenData * tok );

void printError( int line, std::string err );
void printWarning( int line, std::string warn );

void printErrorWarningTree(TreeNode * og);

#endif